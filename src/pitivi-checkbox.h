/* 
 * PiTiVi
 * Copyright (C) <2004> Edward G. Hervey <hervey_e@epita.fr>
 *                      Guillaume Casanova <casano_g@epita.fr>
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

#ifndef PITIVI_CHECKBOX_H
#define PITIVI_CHECKBOX_H

/*
 * Potentially, include other headers on which this header depends.
 */

#include "pitivi-types.h"

G_BEGIN_DECLS

/*
 * Type macros.
 */

#define PITIVI_CHECKBOX_TYPE (pitivi_checkbox_get_type ())
#define PITIVI_CHECKBOX(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), PITIVI_CHECKBOX_TYPE, PitiviCheckBox))
#define PITIVI_CHECKBOX_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), PITIVI_CHECKBOX_TYPE, PitiviCheckBoxClass))
#define PITIVI_IS_CHECKBOX(obj) (G_TYPE_CHECK_TYPE ((obj), PITIVI_CHECKBOX_TYPE))
#define PITIVI_IS_CHECKBOX_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), PITIVI_CHECKBOX_TYPE))
#define PITIVI_CHECKBOX_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), PITIVI_CHECKBOX_TYPE, PitiviCheckBoxClass))

typedef struct _PitiviCheckBoxPrivate PitiviCheckBoxPrivate;

struct _PitiviCheckBox
{
  GtkCheckButton parent;

  /* instance public members */

  /* private */
  PitiviCheckBoxPrivate *private;
};

struct _PitiviCheckBoxClass
{
  GtkCheckButtonClass parent;
  /* class members */
};

#define INDICATOR_PART_SIZE 13

typedef enum {
  CHECK_AA,
  CHECK_BASE,
  CHECK_BLACK,
  CHECK_DARK,
  CHECK_LIGHT,
  CHECK_MID,
  CHECK_TEXT,
  CHECK_INCONSISTENT_TEXT,
  CHECK_BALL,
  CHECK_X,
  CHECK_ANCHOR
} IndicatorPart;

/*
 * Extracted from check-13.png, width=13, height=13
 */

static const guchar check_black_bits[] = {
  0x00,0x00,0xfe,0x0f,0x02,0x00,0x02,0x00,0x02,0x00,0x02,0x00,0x02,0x00,0x02,
  0x00,0x02,0x00,0x02,0x00,0x02,0x00,0x02,0x00,0x00,0x00,0x00,0x00};

static const guchar check_dark_bits[] = {
  0xff,0x1f,0x01,0x00,0x01,0x00,0x01,0x00,0x01,0x00,0x01,0x00,0x01,0x00,0x01,
  0x00,0x01,0x00,0x01,0x00,0x01,0x00,0x01,0x00,0x01,0x00,0x00,0x00};

static const guchar check_mid_bits[] = {
  0x00,0x00,0x00,0x00,0x00,0x08,0x00,0x08,0x00,0x08,0x00,0x08,0x00,0x08,0x00,
  0x08,0x00,0x08,0x00,0x08,0x00,0x08,0xfc,0x0f,0x00,0x00,0x00,0x00};

static const guchar check_light_bits[] = {
  0x00,0x00,0x00,0x10,0x00,0x10,0x00,0x10,0x00,0x10,0x00,0x10,0x00,0x10,0x00,
  0x10,0x00,0x10,0x00,0x10,0x00,0x10,0x00,0x10,0xfe,0x1f,0x00,0x00};

static const guchar check_text_bits[] = {
  0x00, 0x00, 0x00, 0x00, 0x0c, 0x06, 0x1c, 0x07, 0xb8, 0x03, 0xf0, 0x01,
  0xe0, 0x00, 0xf0, 0x01, 0xb8, 0x03, 0x1c, 0x07, 0x0c, 0x06, 0x00, 0x00,
  0x00, 0x00 };

static const guchar check_aa_bits[] = {
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x04,0x00,0x00,0x00,0x00,0x58,0x00,0xa0,
  0x00,0x10,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00};

static const guchar check_base_bits[] = {
  0x00,0x00,0x00,0x00,0xfc,0x07,0xfc,0x07,0xfc,0x07,0xfc,0x07,0xfc,0x07,0xfc,
  0x07,0xfc,0x07,0xfc,0x07,0xfc,0x07,0x00,0x00,0x00,0x00,0x00,0x00};

static guchar check_ball_bits[] = {
   0x00, 0x00, 0xe0, 0x00, 0xf8, 0x03, 0x9c, 0x07, 0x0c, 0x07, 0xfe, 0x0f,
   0xfe, 0x0f, 0xfe, 0x0f, 0xfc, 0x07, 0xfc, 0x07, 0xf8, 0x03, 0xe0, 0x00,
   0x00, 0x00 };

static guchar check_anchor_bits[] = {
   0x00, 0x00, 0xf0, 0x01, 0x60, 0x01, 0x60, 0x01, 0x60, 0x01, 0xe0, 0x00,
   0x6e, 0x0e, 0x66, 0x0c, 0x66, 0x0c, 0x66, 0x0c, 0x68, 0x02, 0xf0, 0x01,
   0x00, 0x00 };

static guchar check_x_bits[] = {
  0x00, 0x00, 0x00, 0x00, 0x0c, 0x06, 0x1c, 0x07, 0xb8, 0x03, 0xf0, 0x01,
  0xe0, 0x00, 0xf0, 0x01, 0xb8, 0x03, 0x1c, 0x07, 0x0c, 0x06, 0x00, 0x00,
  0x00, 0x00 };

/*
 * Extracted from check-13-inconsistent.png, width=13, height=13
 */
static const guchar check_inconsistent_text_bits[] = {
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xf8,0x03,0xf8,
  0x03,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00};
#if 0
/*
 * check_inconsistent_aa_bits is currently not used, since it is all zeros.
 */
static const guchar check_inconsistent_aa_bits[] = {
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00};
#endif

static struct {
  const guchar      *bits;
  GList	    *bmap_list; /* list of GdkBitmap */
} indicator_parts[] = {
  { check_aa_bits, NULL },
  { check_base_bits, NULL },
  { check_black_bits, NULL },
  { check_dark_bits, NULL },
  { check_light_bits, NULL },
  { check_mid_bits, NULL },
  { check_text_bits, NULL },
  { check_inconsistent_text_bits, NULL },
  { check_ball_bits, NULL },
  { check_x_bits, NULL },
  { check_anchor_bits, NULL },
};

/* used by PITIVI_CHECKBOX_TYPE */
GType pitivi_checkbox_get_type (void);

/*
 * Method definitions.
 */


PitiviCheckBox	*pitivi_checkbox_new (guint type);

G_END_DECLS

#endif
