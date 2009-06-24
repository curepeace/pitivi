# PiTiVi , Non-linear video editor
#
#       pitivi/timeline/timeline.py
#
# Copyright (c) 2009, Alessandro Decina <alessandro.decina@collabora.co.uk>
#
# This program is free software; you can redistribute it and/or
# modify it under the terms of the GNU Lesser General Public
# License as published by the Free Software Foundation; either
# version 2.1 of the License, or (at your option) any later version.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
# Lesser General Public License for more details.
#
# You should have received a copy of the GNU Lesser General Public
# License along with this program; if not, write to the
# Free Software Foundation, Inc., 59 Temple Place - Suite 330,
# Boston, MA 02111-1307, USA.

from common import TestCase
import gst

from pitivi.timeline.track import Track, SourceTrackObject, TrackError
from pitivi.stream import AudioStream, VideoStream
from common import SignalMonitor, StubFactory

class TrackSignalMonitor(SignalMonitor):
    def __init__(self, track_object):
        SignalMonitor.__init__(self, track_object, 'start-changed',
                'duration-changed', 'in-point-changed', 'out-point-changed',
                'media-duration-changed', 'priority-changed')

class TestTrackObject(TestCase):
    def setUp(self):
        TestCase.setUp(self)
        stream = AudioStream(gst.Caps("audio/x-raw-int"))
        self.factory = StubFactory()
        gst.debug("%r" % self.factory.duration)
        self.factory.addOutputStream(stream)
        self.track_object = SourceTrackObject(self.factory, stream)
        self.monitor = TrackSignalMonitor(self.track_object)

    def tearDown(self):
        self.monitor = None
        self.track_object.release()
        self.track_oject = None
        self.factory = None
        TestCase.tearDown(self)

    def testDefaultProperties(self):
        obj = self.track_object
        self.failUnlessEqual(obj.start, 0)
        self.failUnlessEqual(obj.duration, self.factory.duration)
        self.failUnlessEqual(obj.in_point, 0)
        self.failUnlessEqual(obj.out_point, self.factory.duration)
        self.failUnlessEqual(obj.media_duration, self.factory.duration)
        self.failUnlessEqual(obj.rate, 1)
        self.failUnlessEqual(obj.priority, 0)

        gnl_object = obj.gnl_object
        self.failUnlessEqual(gnl_object.props.start, 0)
        self.failUnlessEqual(gnl_object.props.duration, self.factory.duration)
        self.failUnlessEqual(gnl_object.props.media_start, 0)
        self.failUnlessEqual(gnl_object.props.media_stop,
                self.factory.duration)
        self.failUnlessEqual(gnl_object.props.media_duration,
                self.factory.duration)
        self.failUnlessEqual(gnl_object.props.rate, 1)
        self.failUnlessEqual(obj.priority, 0)

    def testChangePropertiesFromTrackObject(self):
        obj = self.track_object
        gnl_object = obj.gnl_object

        start = 1 * gst.SECOND
        obj.start = start
        self.failUnlessEqual(obj.start, start)
        self.failUnlessEqual(gnl_object.props.start, start)
        self.failUnlessEqual(self.monitor.start_changed_count, 1)

        duration = 10 * gst.SECOND
        obj.duration = duration
        self.failUnlessEqual(obj.duration, duration)
        self.failUnlessEqual(gnl_object.props.duration, duration)
        self.failUnlessEqual(self.monitor.duration_changed_count, 1)

        in_point = 5 * gst.SECOND
        obj.in_point = in_point
        self.failUnlessEqual(obj.in_point, in_point)
        self.failUnlessEqual(gnl_object.props.media_start, in_point)
        self.failUnlessEqual(self.monitor.in_point_changed_count, 1)

        media_duration = 5 * gst.SECOND
        obj.media_duration = media_duration
        self.failUnlessEqual(obj.media_duration, media_duration)
        self.failUnlessEqual(gnl_object.props.media_duration, media_duration)
        self.failUnlessEqual(obj.out_point, in_point + media_duration)
        self.failUnlessEqual(gnl_object.props.media_stop,
                in_point + media_duration)
        self.failUnlessEqual(self.monitor.media_duration_changed_count, 1)
        self.failUnlessEqual(self.monitor.out_point_changed_count, 1)

        priority = 100
        obj.priority = priority
        self.failUnlessEqual(obj.priority, priority)
        self.failUnlessEqual(gnl_object.props.priority, priority)
        self.failUnlessEqual(self.monitor.priority_changed_count, 1)

    def testChangePropertiesFromGnlObject(self):
        obj = self.track_object
        gnl_object = obj.gnl_object

        start = 1 * gst.SECOND
        gnl_object.props.start = start
        self.failUnlessEqual(obj.start, start)
        self.failUnlessEqual(self.monitor.start_changed_count, 1)

        duration = 10 * gst.SECOND
        gnl_object.props.duration = duration
        self.failUnlessEqual(obj.duration, duration)
        self.failUnlessEqual(self.monitor.duration_changed_count, 1)

        in_point = 5 * gst.SECOND
        gnl_object.props.media_start = in_point
        self.failUnlessEqual(obj.in_point, in_point)
        self.failUnlessEqual(self.monitor.in_point_changed_count, 1)

        media_duration = 5 * gst.SECOND
        gnl_object.props.media_duration = media_duration
        self.failUnlessEqual(obj.media_duration, media_duration)
        self.failUnlessEqual(self.monitor.media_duration_changed_count, 1)
        self.failUnlessEqual(obj.out_point, in_point + media_duration)
        self.failUnlessEqual(self.monitor.media_duration_changed_count, 1)
        self.failUnlessEqual(self.monitor.out_point_changed_count, 1)

        priority = 100
        gnl_object.props.priority = priority
        self.failUnlessEqual(obj.priority, priority)
        self.failUnlessEqual(gnl_object.props.priority, priority)
        self.failUnlessEqual(self.monitor.priority_changed_count, 1)

    def testTrimStart(self):
        obj = self.track_object

        # start at 2 seconds with length 10 seconds
        obj.start = 2 * gst.SECOND
        obj.duration = 10 * gst.SECOND

        self.failUnlessEqual(self.monitor.duration_changed_count, 1)

        # trim at lower edge
        monitor = TrackSignalMonitor(obj)
        time = 2 * gst.SECOND
        obj.trimStart(time)
        self.failUnlessEqual(obj.start, time)
        self.failUnlessEqual(obj.in_point, 0)
        self.failUnlessEqual(obj.duration, 10 * gst.SECOND)
        self.failUnlessEqual(obj.rate, 1)
        # we didn't change the start/in-point/duration (it was the same as before)
        self.failUnlessEqual(monitor.start_changed_count, 0)
        self.failUnlessEqual(monitor.in_point_changed_count, 0)
        self.failUnlessEqual(monitor.duration_changed_count, 0)

        # trim at upper edge
        monitor = TrackSignalMonitor(obj)
        time = 12 * gst.SECOND
        obj.trimStart(time)
        self.failUnlessEqual(obj.start, time)
        self.failUnlessEqual(obj.in_point, 10 * gst.SECOND)
        self.failUnlessEqual(obj.duration, 0)
        self.failUnlessEqual(obj.rate, 1)
        self.failUnlessEqual(monitor.start_changed_count, 1)
        self.failUnlessEqual(monitor.in_point_changed_count, 1)
        self.failUnlessEqual(monitor.duration_changed_count, 1)

        # trim before lower edge, should clamp
        monitor = TrackSignalMonitor(obj)
        time = 1 * gst.SECOND
        obj.trimStart(time)
        self.failUnlessEqual(obj.start, 2 * gst.SECOND)
        self.failUnlessEqual(obj.in_point, 0)
        self.failUnlessEqual(obj.duration, 10 * gst.SECOND)
        self.failUnlessEqual(obj.rate, 1)
        self.failUnlessEqual(monitor.start_changed_count, 1)
        self.failUnlessEqual(monitor.in_point_changed_count, 1)
        self.failUnlessEqual(monitor.duration_changed_count, 1)

        # trimp past upper edge, should clamp
        monitor = TrackSignalMonitor(obj)
        time = 13 * gst.SECOND
        obj.trimStart(time)
        self.failUnlessEqual(obj.start, 12 * gst.SECOND)
        self.failUnlessEqual(obj.in_point, 10 * gst.SECOND)
        self.failUnlessEqual(obj.duration, 0)
        self.failUnlessEqual(obj.rate, 1)
        self.failUnlessEqual(monitor.start_changed_count, 1)
        self.failUnlessEqual(monitor.in_point_changed_count, 1)
        self.failUnlessEqual(monitor.duration_changed_count, 1)

        # trim somewhere in the middle
        monitor = TrackSignalMonitor(obj)
        time = 4 * gst.SECOND
        obj.trimStart(time)
        self.failUnlessEqual(obj.start, time)
        self.failUnlessEqual(obj.in_point, 2 * gst.SECOND)
        self.failUnlessEqual(obj.duration, 8 * gst.SECOND)
        self.failUnlessEqual(obj.rate, 1)
        self.failUnlessEqual(monitor.start_changed_count, 1)
        self.failUnlessEqual(monitor.in_point_changed_count, 1)
        self.failUnlessEqual(monitor.duration_changed_count, 1)

    def testSplitObject(self):
        obj = self.track_object

        obj.start = 3 * gst.SECOND
        obj.duration = 10 * gst.SECOND

        monitor = TrackSignalMonitor(obj)

        self.failUnlessRaises(TrackError, obj.splitObject, 2 * gst.SECOND)
        self.failUnlessRaises(TrackError, obj.splitObject, 14 * gst.SECOND)

        # should these be possible (ie create empty objects) ?
        self.failUnlessRaises(TrackError, obj.splitObject, 3 * gst.SECOND)
        self.failUnlessRaises(TrackError, obj.splitObject, 13 * gst.SECOND)

        # splitObject at 4s should result in:
        # obj (start 3, end 4) other1 (start 4, end 13)
        other1 = obj.splitObject(4 * gst.SECOND)

        self.failUnlessEqual(obj.start, 3 * gst.SECOND)
        self.failUnlessEqual(obj.in_point, 0 * gst.SECOND)
        self.failUnlessEqual(obj.duration, 1 * gst.SECOND)
        self.failUnlessEqual(obj.rate, 1)

        self.failUnlessEqual(other1.start, 4 * gst.SECOND)
        self.failUnlessEqual(other1.in_point, 1 * gst.SECOND)
        self.failUnlessEqual(other1.duration, 9 * gst.SECOND)
        self.failUnlessEqual(other1.rate, 1)

        self.failUnlessEqual(monitor.start_changed_count, 0)
        self.failUnlessEqual(monitor.duration_changed_count, 1)

        # move other1 back to start = 1
        other1.start = 1 * gst.SECOND

        # splitObject again other1
        monitor = TrackSignalMonitor(other1)

        other2 = other1.splitObject(6 * gst.SECOND)
        self.failUnlessEqual(other1.start, 1 * gst.SECOND)
        self.failUnlessEqual(other1.in_point, 1 * gst.SECOND)
        self.failUnlessEqual(other1.duration, 5 * gst.SECOND)
        self.failUnlessEqual(other1.rate, 1)

        self.failUnlessEqual(other2.start, 6 * gst.SECOND)
        self.failUnlessEqual(other2.in_point, 6 * gst.SECOND)
        self.failUnlessEqual(other2.duration, 4 * gst.SECOND)
        self.failUnlessEqual(other2.rate, 1)

        self.failUnlessEqual(monitor.start_changed_count, 0)
        self.failUnlessEqual(monitor.duration_changed_count, 1)


class TestTrack(TestCase):
    def setUp(self):
        TestCase.setUp(self)
        self.factory = StubFactory()
        self.stream = VideoStream(gst.Caps('video/x-raw-rgb'))
        self.factory.addOutputStream(self.stream)
        self.track1 = Track(self.stream)
        self.track2 = Track(self.stream)

    def tearDown(self):
        self.factory = None
        self.stream = None
        self.track1 = None
        self.track2 = None
        TestCase.tearDown(self)

    def testAddRemoveObjects(self):
        factory = self.factory
        stream = self.stream
        track1 = self.track1
        track2 = self.track2

        # add an object
        obj1 = SourceTrackObject(factory, stream)
        self.failUnlessEqual(obj1.track, None)
        track1.addTrackObject(obj1)
        self.failIfEqual(obj1.track, None)

        # can't add twice
        self.failUnlessRaises(TrackError, track1.addTrackObject, obj1)

        # can't add to two different tracks
        self.failUnlessRaises(TrackError, track2.addTrackObject, obj1)

        # add a second object
        obj2 = SourceTrackObject(factory, stream)
        self.failUnlessEqual(obj2.track, None)
        track1.addTrackObject(obj2)
        self.failIfEqual(obj2.track, None)

        # remove
        track1.removeTrackObject(obj1)
        self.failUnlessEqual(obj1.track, None)

        # can't remove twice
        self.failUnlessRaises(TrackError, track1.removeTrackObject, obj1)

        track1.removeTrackObject(obj2)
        self.failUnlessEqual(obj2.track, None)

    def testRemoveAllTrackObjects(self):
        track = self.track1
        factory = self.factory

        # check that can be called on an empty track
        track.removeAllTrackObjects()

        objs = []
        for i in xrange(10):
            obj = SourceTrackObject(factory, self.stream)
            objs.append(obj)
            track.addTrackObject(obj)

        for obj in objs:
            self.failIfEqual(obj.track, None)

        track.removeAllTrackObjects()

        for obj in objs:
            self.failUnlessEqual(obj.track, None)

    def testMaxPriority(self):
        track = self.track1
        factory = self.factory

        obj1 = SourceTrackObject(factory, self.stream)
        obj1.priority = 10

        self.failUnlessEqual(track.max_priority, 0)
        track.addTrackObject(obj1)
        self.failUnlessEqual(track.max_priority, 10)

        obj2 = SourceTrackObject(factory, self.stream)
        obj2.priority = 5
        track.addTrackObject(obj2)
        self.failUnlessEqual(track.max_priority, 10)

        obj3 = SourceTrackObject(factory, self.stream)
        obj3.priority = 14
        track.addTrackObject(obj3)
        self.failUnlessEqual(track.max_priority, 14)

        obj3.priority = 9
        self.failUnlessEqual(track.max_priority, 10)

        obj2.priority = 11
        self.failUnlessEqual(track.max_priority, 11)

        track.removeTrackObject(obj1)
        self.failUnlessEqual(track.max_priority, 11)

        track.removeTrackObject(obj2)
        self.failUnlessEqual(track.max_priority, 9)

        track.removeTrackObject(obj3)
        self.failUnlessEqual(track.max_priority, 0)
