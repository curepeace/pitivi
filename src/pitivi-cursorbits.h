/* 
 * PiTiVi
 * Copyright (C) <2004> Guillaume Casanova <casano_g@epita.fr>
 *                      
 *
 * This software has been written in EPITECH <http://www.epitech.net>
 * EPITECH is a computer science school in Paris - FRANCE -
 * under the direction of Flavien Astraud and Jerome Landrieu.
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * General Public License for more details.
 *
 * You should have received a copy of the GNU General Public
 * License along with this program; if not, write to the
 * Free Software Foundation, Inc., 59 Temple Place - Suite 330,
 * Boston, MA 02111-1307, USA.
 */

#ifndef PITIVI_CURSORBITS_H
#define PITIVI_CURSORBITS_H

/*
 * Cursor's definitions.
 */

static unsigned char zoom_mask_bits[] = {
   0x00, 0x00, 0x00, 0x00, 0xc0, 0x07, 0x00, 0x00, 0xe0, 0x0f, 0x00, 0x00,
   0xf0, 0x1f, 0x00, 0x00, 0x38, 0x38, 0x00, 0x00, 0x1c, 0x70, 0x00, 0x00,
   0x0e, 0xe0, 0x00, 0x00, 0x0e, 0xe0, 0x00, 0x00, 0x0e, 0xe0, 0x00, 0x00,
   0x0e, 0xe0, 0x00, 0x00, 0x0e, 0xe0, 0x00, 0x00, 0x1c, 0x70, 0x00, 0x00,
   0x38, 0x78, 0x00, 0x00, 0xf0, 0xff, 0x00, 0x00, 0xe0, 0xff, 0x01, 0x00,
   0xc0, 0xe7, 0x03, 0x00, 0x00, 0xc0, 0x07, 0x00, 0x00, 0x80, 0x0f, 0x00,
   0x00, 0x00, 0x1f, 0x00, 0x00, 0x00, 0x3e, 0x00, 0x00, 0x00, 0x7c, 0x00,
   0x00, 0x00, 0x38, 0x00, 0x00, 0x00, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 };

static unsigned char zoom_bits[] = {
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc0, 0x07, 0x00, 0x00,
   0x20, 0x08, 0x00, 0x00, 0x10, 0x10, 0x00, 0x00, 0x08, 0x20, 0x00, 0x00,
   0x04, 0x40, 0x00, 0x00, 0x04, 0x40, 0x00, 0x00, 0x04, 0x40, 0x00, 0x00,
   0x04, 0x40, 0x00, 0x00, 0x04, 0x40, 0x00, 0x00, 0x08, 0x20, 0x00, 0x00,
   0x10, 0x30, 0x00, 0x00, 0x20, 0x78, 0x00, 0x00, 0xc0, 0xe7, 0x00, 0x00,
   0x00, 0xc0, 0x01, 0x00, 0x00, 0x80, 0x03, 0x00, 0x00, 0x00, 0x07, 0x00,
   0x00, 0x00, 0x0e, 0x00, 0x00, 0x00, 0x1c, 0x00, 0x00, 0x00, 0x38, 0x00,
   0x00, 0x00, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 };

static unsigned char hand_1_bits[] = {
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x30, 0x00, 0x00,
   0x00, 0xce, 0x01, 0x00, 0x00, 0x49, 0x02, 0x00, 0x00, 0x49, 0x02, 0x00,
   0x00, 0x49, 0x0e, 0x00, 0x00, 0x49, 0x12, 0x00, 0xc0, 0x49, 0x12, 0x00,
   0x20, 0x49, 0x12, 0x00, 0x20, 0x49, 0x12, 0x00, 0x20, 0x49, 0x12, 0x00,
   0x20, 0x49, 0x12, 0x00, 0x20, 0x01, 0x12, 0x00, 0x20, 0x01, 0x12, 0x00,
   0x20, 0x00, 0x10, 0x00, 0x20, 0x00, 0x10, 0x00, 0x20, 0x00, 0x10, 0x00,
   0x60, 0x00, 0x10, 0x00, 0xc0, 0x00, 0x18, 0x00, 0x80, 0x01, 0x0c, 0x00,
   0x00, 0x03, 0x06, 0x00, 0x00, 0x02, 0x02, 0x00, 0x00, 0x02, 0x02, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 };

static unsigned char hand_1_mask_bits[] = {
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x30, 0x00, 0x00, 0x00, 0xfe, 0x01, 0x00,
   0x00, 0xef, 0x03, 0x00, 0x80, 0x6d, 0x07, 0x00, 0x80, 0x6d, 0x0f, 0x00,
   0x80, 0x6d, 0x1f, 0x00, 0xc0, 0x6d, 0x3b, 0x00, 0xf0, 0x6d, 0x3b, 0x00,
   0xb0, 0x6d, 0x3b, 0x00, 0xb0, 0x6d, 0x3b, 0x00, 0xb0, 0x6d, 0x3b, 0x00,
   0xb0, 0x6d, 0x3b, 0x00, 0xb0, 0x01, 0x3b, 0x00, 0xb0, 0x01, 0x3b, 0x00,
   0x30, 0x00, 0x38, 0x00, 0x30, 0x00, 0x38, 0x00, 0x30, 0x00, 0x38, 0x00,
   0x70, 0x00, 0x38, 0x00, 0xe0, 0x00, 0x38, 0x00, 0xc0, 0x01, 0x1c, 0x00,
   0x80, 0x03, 0x0e, 0x00, 0x00, 0x03, 0x06, 0x00, 0x00, 0x03, 0x06, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 };

static unsigned char cut_bits[] = {
   0x00, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00,
   0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00,
   0x04, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x04, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00,
   0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x04, 0x7c, 0x00, 0x00,
   0x04, 0xef, 0x01, 0x00, 0x04, 0xef, 0x01, 0x00, 0x00, 0xc7, 0x01, 0x00,
   0x04, 0xef, 0x01, 0x00, 0x04, 0xef, 0x01, 0x00, 0x04, 0xef, 0x01, 0x00,
   0x00, 0xef, 0x01, 0x00, 0x00, 0xef, 0x01, 0x00, 0x00, 0xc7, 0x01, 0x00,
   0x00, 0xef, 0x01, 0x00, 0x00, 0xef, 0x01, 0x00, 0x00, 0x7c, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 };

static unsigned char cut_mask_bits[] = {
   0x0e, 0x00, 0x00, 0x00, 0x0e, 0x00, 0x00, 0x00, 0x0e, 0x00, 0x00, 0x00,
   0x0e, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0e, 0x00, 0x00, 0x00,
   0x0e, 0x00, 0x00, 0x00, 0x0e, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x0e, 0x00, 0x00, 0x00, 0x0e, 0x00, 0x00, 0x00, 0x0e, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x0e, 0x00, 0x00, 0x00, 0x0e, 0x00, 0x00, 0x00,
   0x0e, 0x00, 0x00, 0x00, 0x00, 0x7c, 0x00, 0x00, 0x0e, 0xfe, 0x00, 0x00,
   0x8e, 0xff, 0x03, 0x00, 0x8e, 0xff, 0x03, 0x00, 0x80, 0xff, 0x03, 0x00,
   0x8e, 0xff, 0x03, 0x00, 0x8e, 0xff, 0x03, 0x00, 0x8e, 0xff, 0x03, 0x00,
   0x8e, 0xff, 0x03, 0x00, 0x80, 0xff, 0x03, 0x00, 0x80, 0xff, 0x03, 0x00,
   0x80, 0xff, 0x03, 0x00, 0x80, 0xff, 0x03, 0x00, 0x00, 0xfe, 0x00, 0x00,
   0x00, 0x7c, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 };

static unsigned char pointer_bits[] = {
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x18, 0x00, 0x00, 0x00,
   0x38, 0x00, 0x00, 0x00, 0x68, 0x00, 0x00, 0x00, 0xd8, 0x00, 0x00, 0x00,
   0xb8, 0x01, 0x00, 0x00, 0x78, 0x03, 0x00, 0x00, 0xf8, 0x06, 0x00, 0x00,
   0xf8, 0x0d, 0x00, 0x00, 0xf8, 0x1b, 0x00, 0x00, 0xf8, 0x37, 0x00, 0x00,
   0xf8, 0x6f, 0x00, 0x00, 0x08, 0xdc, 0x00, 0x00, 0x58, 0xbf, 0x01, 0x00,
   0x58, 0x7f, 0x03, 0x00, 0x58, 0xff, 0x06, 0x00, 0xf8, 0xff, 0x0d, 0x00,
   0xf8, 0xe1, 0x1b, 0x00, 0x78, 0x00, 0x3e, 0x00, 0x18, 0x00, 0x78, 0x00,
   0x18, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 };

static unsigned char pointer_mask_bits[] = {
   0x00, 0x00, 0x00, 0x00, 0x18, 0x00, 0x00, 0x00, 0x3c, 0x00, 0x00, 0x00,
   0x7c, 0x00, 0x00, 0x00, 0xec, 0x00, 0x00, 0x00, 0xdc, 0x01, 0x00, 0x00,
   0xbc, 0x03, 0x00, 0x00, 0x7c, 0x07, 0x00, 0x00, 0xfc, 0x0e, 0x00, 0x00,
   0xfc, 0x1d, 0x00, 0x00, 0xfc, 0x3b, 0x00, 0x00, 0xfc, 0x77, 0x00, 0x00,
   0xfc, 0xef, 0x00, 0x00, 0x0c, 0xdc, 0x01, 0x00, 0x5c, 0xbf, 0x03, 0x00,
   0x5c, 0x7f, 0x07, 0x00, 0x5c, 0xff, 0x0e, 0x00, 0xfc, 0xff, 0x1d, 0x00,
   0xfc, 0xff, 0x3b, 0x00, 0xfc, 0xe3, 0x7f, 0x00, 0x7c, 0x00, 0xfe, 0x00,
   0x3c, 0x00, 0x78, 0x00, 0x18, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 };

static unsigned char resize_bits[] = {
   0x00, 0x0c, 0x03, 0x00, 0x00, 0x98, 0x01, 0x00, 0x00, 0x90, 0x00, 0x00,
   0x00, 0x90, 0x00, 0x00, 0x00, 0x90, 0x00, 0x00, 0x00, 0x90, 0x00, 0x00,
   0x00, 0x90, 0x00, 0x00, 0x00, 0x90, 0x00, 0x00, 0x00, 0x90, 0x00, 0x00,
   0x00, 0x90, 0x00, 0x00, 0x00, 0x90, 0x00, 0x00, 0x00, 0x90, 0x00, 0x00,
   0xe0, 0x90, 0x70, 0x00, 0x70, 0x98, 0xe1, 0x00, 0xf8, 0x0f, 0xff, 0x01,
   0xf8, 0x0f, 0xff, 0x01, 0x70, 0x98, 0xe1, 0x00, 0xe0, 0x90, 0x70, 0x00,
   0x00, 0x90, 0x00, 0x00, 0x00, 0x90, 0x00, 0x00, 0x00, 0x90, 0x00, 0x00,
   0x00, 0x90, 0x00, 0x00, 0x00, 0x90, 0x00, 0x00, 0x00, 0x90, 0x00, 0x00,
   0x00, 0x90, 0x00, 0x00, 0x00, 0x90, 0x00, 0x00, 0x00, 0x90, 0x00, 0x00,
   0x00, 0x90, 0x00, 0x00, 0x00, 0x90, 0x00, 0x00, 0x00, 0x98, 0x01, 0x00,
   0x00, 0x0c, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00 };

static unsigned char resize_mask_bits[] = {
   0x00, 0x8e, 0x03, 0x00, 0x00, 0xdc, 0x01, 0x00, 0x00, 0xd8, 0x00, 0x00,
   0x00, 0xd8, 0x00, 0x00, 0x00, 0xd8, 0x00, 0x00, 0x00, 0xd8, 0x00, 0x00,
   0x00, 0xd8, 0x00, 0x00, 0x00, 0xd8, 0x00, 0x00, 0x00, 0xd8, 0x00, 0x00,
   0x00, 0xd8, 0x00, 0x00, 0x00, 0xd8, 0x00, 0x00, 0x00, 0xd8, 0x00, 0x00,
   0xf0, 0xd8, 0x78, 0x00, 0x78, 0xdc, 0xf1, 0x00, 0xfc, 0x8f, 0xff, 0x01,
   0xfc, 0x8f, 0xff, 0x01, 0x78, 0xdc, 0xf1, 0x00, 0xf0, 0xd8, 0x78, 0x00,
   0x00, 0xd8, 0x00, 0x00, 0x00, 0xd8, 0x00, 0x00, 0x00, 0xd8, 0x00, 0x00,
   0x00, 0xd8, 0x00, 0x00, 0x00, 0xd8, 0x00, 0x00, 0x00, 0xd8, 0x00, 0x00,
   0x00, 0xd8, 0x00, 0x00, 0x00, 0xd8, 0x00, 0x00, 0x00, 0xd8, 0x00, 0x00,
   0x00, 0xd8, 0x00, 0x00, 0x00, 0xd8, 0x00, 0x00, 0x00, 0xdc, 0x01, 0x00,
   0x00, 0x8e, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00 };


#endif
