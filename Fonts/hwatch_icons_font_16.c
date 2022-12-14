/*******************************************************************************
 * Size: 16 px
 * Bpp: 4
 * Opts:
 ******************************************************************************/

#include "lvgl.h"

#ifndef HWATCH_ICONS_FONT_16
#define HWATCH_ICONS_FONT_16 1
#endif

#if HWATCH_ICONS_FONT_16

 /*-----------------
  *    BITMAPS
  *----------------*/

  /*Store the image of the glyphs*/
static LV_ATTRIBUTE_LARGE_CONST const uint8_t glyph_bitmap [] = {
    /* U+F011 "" */
    0x0, 0x0, 0x0, 0xb8, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x4, 0xff, 0x0, 0x0, 0x0, 0x0, 0x15,
    0x4, 0xff, 0x2, 0x50, 0x0, 0x2, 0xdf, 0x74,
    0xff, 0xc, 0xfb, 0x0, 0xc, 0xff, 0x34, 0xff,
    0x7, 0xff, 0x80, 0x6f, 0xf4, 0x4, 0xff, 0x0,
    0x9f, 0xf1, 0xbf, 0xa0, 0x4, 0xff, 0x0, 0xe,
    0xf7, 0xef, 0x60, 0x2, 0xfc, 0x0, 0xa, 0xfa,
    0xff, 0x40, 0x0, 0x10, 0x0, 0x9, 0xfb, 0xdf,
    0x70, 0x0, 0x0, 0x0, 0xc, 0xf9, 0x9f, 0xe0,
    0x0, 0x0, 0x0, 0x2f, 0xf5, 0x2f, 0xfa, 0x0,
    0x0, 0x1, 0xdf, 0xd0, 0x8, 0xff, 0xd5, 0x23,
    0x7f, 0xff, 0x40, 0x0, 0x8f, 0xff, 0xff, 0xff,
    0xf5, 0x0, 0x0, 0x3, 0xbf, 0xff, 0xe9, 0x10,
    0x0, 0x0, 0x0, 0x0, 0x11, 0x0, 0x0, 0x0,

    /* U+F017 "" */
    0x0, 0x0, 0x59, 0xbb, 0x93, 0x0, 0x0, 0x0,
    0x2d, 0xff, 0xff, 0xff, 0xb1, 0x0, 0x3, 0xff,
    0xd7, 0x44, 0x8e, 0xfd, 0x10, 0xd, 0xfa, 0x0,
    0x5, 0x1, 0xcf, 0xa0, 0x6f, 0xc0, 0x0, 0x2f,
    0x0, 0x1f, 0xf2, 0xcf, 0x50, 0x0, 0x2f, 0x0,
    0x8, 0xf8, 0xef, 0x10, 0x0, 0x2f, 0x0, 0x5,
    0xfa, 0xff, 0x0, 0x5f, 0xff, 0x0, 0x4, 0xfb,
    0xdf, 0x30, 0x13, 0x32, 0x0, 0x7, 0xf9, 0x9f,
    0x90, 0x0, 0x0, 0x0, 0xd, 0xf5, 0x2f, 0xf4,
    0x0, 0x0, 0x0, 0x8f, 0xe0, 0x7, 0xff, 0x81,
    0x0, 0x2a, 0xff, 0x30, 0x0, 0x7f, 0xff, 0xef,
    0xff, 0xe4, 0x0, 0x0, 0x3, 0xaf, 0xff, 0xe8,
    0x10, 0x0, 0x0, 0x0, 0x0, 0x10, 0x0, 0x0,
    0x0,

    /* U+F026 "" */
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x9d, 0x0,
    0x0, 0x9f, 0xd0, 0x0, 0x9f, 0xfd, 0xef, 0xff,
    0xff, 0xdf, 0xff, 0xff, 0xfd, 0xff, 0xff, 0xff,
    0xdf, 0xff, 0xff, 0xfd, 0x79, 0x9f, 0xff, 0xd0,
    0x0, 0x3f, 0xfd, 0x0, 0x0, 0x3f, 0xd0, 0x0,
    0x0, 0x38,

    /* U+F028 "" */
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0xe, 0x80, 0x0, 0x0,
    0x0, 0x9, 0xd0, 0x0, 0x2c, 0xc0, 0x0, 0x0,
    0x9, 0xfd, 0x0, 0xd7, 0xb, 0xa0, 0x0, 0x9,
    0xff, 0xd0, 0x3, 0xe7, 0x1f, 0x3e, 0xff, 0xff,
    0xfd, 0xa, 0x64, 0xf0, 0x99, 0xff, 0xff, 0xff,
    0xd0, 0x4f, 0x1e, 0x46, 0xcf, 0xff, 0xff, 0xfd,
    0x0, 0xe3, 0xc5, 0x5d, 0xff, 0xff, 0xff, 0xd0,
    0x9d, 0x1f, 0x37, 0xb7, 0x99, 0xff, 0xfd, 0x4,
    0x18, 0xc0, 0xc7, 0x0, 0x3, 0xff, 0xd0, 0xa,
    0xe2, 0x5f, 0x10, 0x0, 0x3, 0xfd, 0x0, 0x61,
    0x4f, 0x50, 0x0, 0x0, 0x3, 0x80, 0x0, 0x9f,
    0x60, 0x0, 0x0, 0x0, 0x0, 0x0, 0x8, 0x20,
    0x0,

    /* U+F042 "" */
    0x0, 0x0, 0x59, 0xbb, 0x93, 0x0, 0x0, 0x0,
    0x2d, 0xff, 0xff, 0xff, 0xb1, 0x0, 0x3, 0xff,
    0xd7, 0x5f, 0xff, 0xfd, 0x10, 0xd, 0xfa, 0x0,
    0x1f, 0xff, 0xff, 0xa0, 0x6f, 0xc0, 0x0, 0x1f,
    0xff, 0xff, 0xf2, 0xcf, 0x50, 0x0, 0x1f, 0xff,
    0xff, 0xf8, 0xef, 0x10, 0x0, 0x1f, 0xff, 0xff,
    0xfb, 0xff, 0x0, 0x0, 0x1f, 0xff, 0xff, 0xfb,
    0xdf, 0x30, 0x0, 0x1f, 0xff, 0xff, 0xf9, 0x9f,
    0x90, 0x0, 0x1f, 0xff, 0xff, 0xf5, 0x2f, 0xf4,
    0x0, 0x1f, 0xff, 0xff, 0xe0, 0x7, 0xff, 0x81,
    0x1f, 0xff, 0xff, 0x30, 0x0, 0x7f, 0xff, 0xef,
    0xff, 0xf4, 0x0, 0x0, 0x3, 0xaf, 0xff, 0xe9,
    0x10, 0x0, 0x0, 0x0, 0x0, 0x10, 0x0, 0x0,
    0x0,

    /* U+F05A "" */
    0x0, 0x0, 0x14, 0x66, 0x40, 0x0, 0x0, 0x0,
    0x9, 0xff, 0xff, 0xfe, 0x60, 0x0, 0x1, 0xdf,
    0xfb, 0x0, 0xff, 0xf9, 0x0, 0xb, 0xff, 0xfc,
    0x22, 0xff, 0xff, 0x70, 0x5f, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xf1, 0xbf, 0xff, 0x90, 0x0, 0xff,
    0xff, 0xf6, 0xef, 0xff, 0x90, 0x0, 0xff, 0xff,
    0xf9, 0xff, 0xff, 0xfb, 0x0, 0xff, 0xff, 0xfa,
    0xdf, 0xff, 0xfb, 0x0, 0xff, 0xff, 0xf9, 0x9f,
    0xff, 0xf9, 0x0, 0xdf, 0xff, 0xf5, 0x2f, 0xff,
    0x90, 0x0, 0xd, 0xff, 0xe0, 0x8, 0xff, 0xa2,
    0x22, 0x2e, 0xff, 0x30, 0x0, 0x8f, 0xff, 0xff,
    0xff, 0xf4, 0x0, 0x0, 0x3, 0xbf, 0xff, 0xe9,
    0x10, 0x0, 0x0, 0x0, 0x0, 0x10, 0x0, 0x0,
    0x0,

    /* U+F073 "" */
    0x0, 0x4d, 0xd4, 0x0, 0x5, 0xda, 0x0, 0x0,
    0xe, 0x77, 0xe0, 0x0, 0xe7, 0xe5, 0x0, 0x36,
    0xf3, 0x3f, 0x66, 0x6f, 0x3c, 0xa6, 0x2f, 0xff,
    0x33, 0xff, 0xff, 0xf3, 0xcf, 0xfd, 0xff, 0xf9,
    0x9f, 0xff, 0xff, 0x9e, 0xff, 0xef, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xfe, 0xf2, 0x6, 0x60,
    0x9, 0x0, 0x70, 0x3, 0xef, 0x20, 0x66, 0x0,
    0x90, 0x7, 0x0, 0x3e, 0xf9, 0x9b, 0xb9, 0x9d,
    0x99, 0xc9, 0x9a, 0xef, 0x20, 0x66, 0x0, 0x90,
    0x7, 0x0, 0x3e, 0xf2, 0x6, 0x60, 0x9, 0x0,
    0x70, 0x3, 0xef, 0x20, 0x66, 0x0, 0x90, 0x7,
    0x0, 0x3e, 0xfa, 0x9b, 0xb9, 0x9d, 0x99, 0xc9,
    0x9a, 0xef, 0x20, 0x66, 0x0, 0x90, 0x7, 0x0,
    0x3e, 0xf2, 0x6, 0x60, 0x9, 0x0, 0x70, 0x3,
    0xed, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfc,
    0x2, 0x33, 0x33, 0x33, 0x33, 0x33, 0x32, 0x0,

    /* U+F085 "" */
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x60, 0x33,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x7, 0xfa,
    0xed, 0x0, 0x0, 0x0, 0x26, 0x50, 0x0, 0x5,
    0xfa, 0xdb, 0x10, 0x0, 0x40, 0x8f, 0xe0, 0x31,
    0xbf, 0xa0, 0x3f, 0xf2, 0x8, 0xfc, 0xef, 0xfb,
    0xfd, 0x6b, 0xd3, 0x8e, 0x80, 0xb, 0xff, 0xff,
    0xff, 0xff, 0x24, 0xff, 0xfb, 0x0, 0x4, 0xff,
    0x60, 0x3d, 0xfb, 0x4, 0xd1, 0x9a, 0x0, 0xdf,
    0xf9, 0x0, 0x3, 0xff, 0xe5, 0x0, 0x0, 0x0,
    0xff, 0xf7, 0x0, 0x0, 0xff, 0xf6, 0x0, 0x0,
    0x0, 0x6b, 0xfc, 0x0, 0x6, 0xfe, 0x82, 0x40,
    0x21, 0x0, 0x5, 0xff, 0xd7, 0xaf, 0xfc, 0x7,
    0xf8, 0xee, 0x0, 0xd, 0xff, 0xff, 0xff, 0xff,
    0x44, 0xfc, 0xea, 0x0, 0x3, 0xd5, 0xbf, 0xf3,
    0xb8, 0xaf, 0xa0, 0x4f, 0xf1, 0x0, 0x0, 0x6f,
    0xd0, 0x0, 0x6c, 0xc1, 0x7e, 0xa1, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x4, 0xff, 0xfb, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x5, 0xe3, 0xbb, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0,

    /* U+F0AE "" */
    0x45, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x54,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xfe, 0xcc, 0xdf,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xf8, 0x33, 0x4f,
    0xdf, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfd,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0xef, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfe,
    0xff, 0xff, 0xfb, 0x0, 0x0, 0x0, 0x0, 0x2f,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0x23, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x32,
    0x23, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x32,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xf4, 0x22, 0x22, 0x4f,
    0xef, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfe,

    /* U+F0ED "" */
    0x0, 0x0, 0x4, 0x76, 0x20, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x1, 0xcf, 0xff, 0xf9, 0x0, 0x0,
    0x0, 0x0, 0x0, 0xd, 0xff, 0xff, 0xff, 0x90,
    0x31, 0x0, 0x0, 0x0, 0x6f, 0xff, 0xff, 0xff,
    0xfe, 0xff, 0x30, 0x0, 0x0, 0xaf, 0xff, 0xd0,
    0xd, 0xff, 0xff, 0xb0, 0x0, 0x1, 0xdf, 0xff,
    0xd0, 0xd, 0xff, 0xff, 0xc0, 0x0, 0x1e, 0xff,
    0xff, 0xd0, 0xd, 0xff, 0xff, 0xc3, 0x0, 0xaf,
    0xff, 0xc6, 0x50, 0x5, 0x6c, 0xff, 0xff, 0x50,
    0xef, 0xff, 0xf5, 0x0, 0x0, 0x5f, 0xff, 0xff,
    0xe0, 0xff, 0xff, 0xff, 0x50, 0x5, 0xff, 0xff,
    0xff, 0xf1, 0xbf, 0xff, 0xff, 0xf6, 0x6f, 0xff,
    0xff, 0xff, 0xf0, 0x2f, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0x70, 0x2, 0xbf, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xd7, 0x0,

    /* U+F0EE "" */
    0x0, 0x0, 0x2, 0x54, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x1, 0xbf, 0xff, 0xf6, 0x0, 0x0,
    0x0, 0x0, 0x0, 0xc, 0xff, 0xff, 0xff, 0x60,
    0x31, 0x0, 0x0, 0x0, 0x6f, 0xff, 0xff, 0xff,
    0xfe, 0xfe, 0x30, 0x0, 0x0, 0xaf, 0xff, 0xe3,
    0x3f, 0xff, 0xff, 0xa0, 0x0, 0x1, 0xdf, 0xfe,
    0x20, 0x3, 0xef, 0xff, 0xb0, 0x0, 0x1e, 0xff,
    0xd2, 0x0, 0x0, 0x2e, 0xff, 0xc3, 0x0, 0xaf,
    0xff, 0xeb, 0x90, 0xa, 0xbe, 0xff, 0xff, 0x40,
    0xef, 0xff, 0xff, 0xd0, 0xe, 0xff, 0xff, 0xff,
    0xd0, 0xff, 0xff, 0xff, 0xd0, 0xe, 0xff, 0xff,
    0xff, 0xf0, 0xbf, 0xff, 0xff, 0xe4, 0x4f, 0xff,
    0xff, 0xff, 0xe0, 0x2f, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0x60, 0x2, 0xbf, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xd6, 0x0,

    /* U+F0F3 "" */
    0x0, 0x0, 0x0, 0x6, 0xc0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x1, 0x7e, 0xf9, 0x30, 0x0, 0x0,
    0x0, 0x0, 0x3e, 0xff, 0xff, 0xf7, 0x0, 0x0,
    0x0, 0x0, 0xef, 0xff, 0xff, 0xff, 0x40, 0x0,
    0x0, 0x4, 0xff, 0xff, 0xff, 0xff, 0xa0, 0x0,
    0x0, 0x6, 0xff, 0xff, 0xff, 0xff, 0xc0, 0x0,
    0x0, 0x7, 0xff, 0xff, 0xff, 0xff, 0xd0, 0x0,
    0x0, 0x8, 0xff, 0xff, 0xff, 0xff, 0xe0, 0x0,
    0x0, 0xc, 0xff, 0xff, 0xff, 0xff, 0xf1, 0x0,
    0x0, 0x1f, 0xff, 0xff, 0xff, 0xff, 0xf7, 0x0,
    0x0, 0x8f, 0xff, 0xff, 0xff, 0xff, 0xfe, 0x0,
    0x3, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x80,
    0x1e, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf6,
    0xa, 0xcc, 0xcc, 0xef, 0xff, 0xdc, 0xcc, 0xb3,
    0x0, 0x0, 0x0, 0xcc, 0xff, 0x40, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x4b, 0xe9, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,

    /* U+F118 "" */
    0x0, 0x0, 0x2, 0x44, 0x20, 0x0, 0x0, 0x0,
    0x7, 0xef, 0xdd, 0xfc, 0x40, 0x0, 0x0, 0xbd,
    0x50, 0x0, 0x17, 0xf8, 0x0, 0xa, 0xb0, 0x10,
    0x0, 0x0, 0x2e, 0x70, 0x4e, 0x15, 0xf9, 0x0,
    0xcf, 0x24, 0xf1, 0xb8, 0x5, 0xf9, 0x0, 0xdf,
    0x20, 0xc7, 0xe3, 0x0, 0x10, 0x0, 0x1, 0x0,
    0x7a, 0xf2, 0x0, 0x0, 0x0, 0x0, 0x0, 0x6b,
    0xd4, 0x4, 0x80, 0x0, 0xb, 0x0, 0x89, 0x99,
    0x2, 0xf5, 0x0, 0x9d, 0x0, 0xd6, 0x3f, 0x20,
    0x5e, 0xef, 0xd2, 0x6, 0xe0, 0x8, 0xd2, 0x0,
    0x32, 0x0, 0x4f, 0x40, 0x0, 0x8f, 0x83, 0x1,
    0x4a, 0xf5, 0x0, 0x0, 0x3, 0xaf, 0xff, 0xe8,
    0x20, 0x0, 0x0, 0x0, 0x0, 0x10, 0x0, 0x0,
    0x0,

    /* U+F119 "" */
    0x0, 0x0, 0x2, 0x44, 0x20, 0x0, 0x0, 0x0,
    0x7, 0xef, 0xdd, 0xfc, 0x40, 0x0, 0x0, 0xbd,
    0x50, 0x0, 0x17, 0xf8, 0x0, 0xa, 0xb0, 0x10,
    0x0, 0x0, 0x2e, 0x70, 0x4e, 0x15, 0xf9, 0x0,
    0xcf, 0x24, 0xf1, 0xb8, 0x5, 0xf9, 0x0, 0xdf,
    0x20, 0xc7, 0xe3, 0x0, 0x10, 0x0, 0x1, 0x0,
    0x7a, 0xf2, 0x0, 0x0, 0x10, 0x0, 0x0, 0x6b,
    0xd4, 0x0, 0x3d, 0xff, 0xa1, 0x0, 0x89, 0x99,
    0x1, 0xf8, 0x12, 0xbb, 0x0, 0xd6, 0x3f, 0x25,
    0xa0, 0x0, 0x1d, 0x16, 0xe0, 0x8, 0xd2, 0x0,
    0x0, 0x0, 0x4f, 0x40, 0x0, 0x8f, 0x83, 0x1,
    0x4a, 0xf5, 0x0, 0x0, 0x3, 0xaf, 0xff, 0xe8,
    0x20, 0x0, 0x0, 0x0, 0x0, 0x10, 0x0, 0x0,
    0x0,

    /* U+F11A "" */
    0x0, 0x0, 0x2, 0x44, 0x20, 0x0, 0x0, 0x0,
    0x7, 0xef, 0xdd, 0xfc, 0x40, 0x0, 0x0, 0xbd,
    0x50, 0x0, 0x17, 0xf8, 0x0, 0xa, 0xb0, 0x10,
    0x0, 0x0, 0x2e, 0x70, 0x4e, 0x16, 0xf7, 0x0,
    0xdf, 0x14, 0xf1, 0xb8, 0x7, 0xf7, 0x0, 0xdf,
    0x10, 0xc7, 0xe3, 0x0, 0x10, 0x0, 0x0, 0x0,
    0x7a, 0xf2, 0x0, 0x0, 0x0, 0x0, 0x0, 0x6b,
    0xd4, 0x2, 0x55, 0x55, 0x55, 0x0, 0x89, 0x99,
    0x6, 0xcc, 0xcc, 0xcc, 0x10, 0xd6, 0x3f, 0x20,
    0x0, 0x0, 0x0, 0x6, 0xe0, 0x8, 0xd2, 0x0,
    0x0, 0x0, 0x4f, 0x40, 0x0, 0x8f, 0x83, 0x1,
    0x4a, 0xf5, 0x0, 0x0, 0x3, 0xaf, 0xff, 0xe8,
    0x20, 0x0, 0x0, 0x0, 0x0, 0x10, 0x0, 0x0,
    0x0,

    /* U+F11B "" */
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x8e, 0xff, 0xff, 0xff, 0xff, 0xfe,
    0x91, 0x0, 0xc, 0xfe, 0xaf, 0xff, 0xff, 0xff,
    0xff, 0xfd, 0x10, 0x8f, 0xfb, 0xc, 0xff, 0xff,
    0xff, 0xc4, 0xaf, 0xa0, 0xee, 0xa7, 0x8, 0xae,
    0xff, 0xff, 0x60, 0x3f, 0xf0, 0xfb, 0x0, 0x0,
    0x9, 0xff, 0xd9, 0xe9, 0xef, 0xf1, 0xdf, 0xb8,
    0x9, 0xbe, 0xff, 0x30, 0x7f, 0xff, 0xf0, 0x8f,
    0xfb, 0xc, 0xff, 0xff, 0xa5, 0xdf, 0xff, 0xa0,
    0xc, 0xfe, 0xaf, 0xff, 0xff, 0xff, 0xff, 0xfd,
    0x10, 0x0, 0x8d, 0xfe, 0x91, 0x1, 0x8e, 0xfe,
    0x81, 0x0,

    /* U+F17C "" */
    0x0, 0x0, 0x4, 0xa8, 0x10, 0x0, 0x0, 0x0,
    0x0, 0x3f, 0xfd, 0xd0, 0x0, 0x0, 0x0, 0x0,
    0x6d, 0xfa, 0xf4, 0x0, 0x0, 0x0, 0x0, 0x68,
    0x99, 0xc6, 0x0, 0x0, 0x0, 0x0, 0x52, 0x4,
    0xe8, 0x0, 0x0, 0x0, 0x0, 0x59, 0x55, 0xcb,
    0x0, 0x0, 0x0, 0x0, 0x92, 0x50, 0x6f, 0x70,
    0x0, 0x0, 0x7, 0x80, 0x0, 0xe, 0xe3, 0x0,
    0x0, 0x1e, 0x20, 0x0, 0x7, 0xcc, 0x0, 0x0,
    0x6b, 0x0, 0x0, 0x4, 0xcf, 0x20, 0x0, 0xc8,
    0x0, 0x0, 0x2, 0xaf, 0x50, 0x0, 0x76, 0x0,
    0x0, 0x4, 0xff, 0x30, 0x23, 0x5, 0x80, 0x0,
    0x2, 0x85, 0x20, 0x30, 0x0, 0xa4, 0x0, 0x12,
    0x0, 0x22, 0x40, 0x0, 0x17, 0x56, 0xd3, 0x0,
    0x22, 0x34, 0x52, 0x2b, 0x99, 0x97, 0x16, 0x10,
    0x0, 0x3, 0x40, 0x0, 0x3, 0x50, 0x0,

    /* U+F1D6 "" */
    0x0, 0x0, 0x2, 0x8c, 0xdc, 0x81, 0x0, 0x0,
    0x0, 0x0, 0x5f, 0xff, 0xff, 0xff, 0x40, 0x0,
    0x0, 0x2, 0xff, 0xff, 0xff, 0xff, 0xf1, 0x0,
    0x0, 0xa, 0xff, 0xff, 0xff, 0xff, 0xf8, 0x0,
    0x0, 0xf, 0xff, 0xff, 0xff, 0xff, 0xfc, 0x0,
    0x0, 0x3f, 0xff, 0xff, 0xff, 0xff, 0xff, 0x10,
    0x0, 0x8f, 0xff, 0xff, 0xff, 0xff, 0xff, 0x60,
    0x0, 0xcf, 0xff, 0xff, 0xff, 0xff, 0xff, 0x70,
    0xb, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf1,
    0x6f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf7,
    0xbf, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfc,
    0xcb, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xdc,
    0x40, 0xaf, 0xff, 0xff, 0xff, 0xff, 0xfc, 0x25,
    0x0, 0x2e, 0xff, 0xff, 0xff, 0xff, 0xf5, 0x0,
    0x0, 0xdf, 0xff, 0xff, 0xff, 0xff, 0xff, 0x50,
    0x0, 0x9f, 0xff, 0xfb, 0x6a, 0xef, 0xfc, 0x20,
    0x0, 0x0, 0x11, 0x0, 0x0, 0x0, 0x0, 0x0,

    /* U+F1EC "" */
    0xae, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfe, 0x8f,
    0x63, 0x33, 0x33, 0x33, 0x33, 0x33, 0x7e, 0xf2,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x3, 0xef, 0x20,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x3e, 0xf5, 0x22,
    0x22, 0x22, 0x22, 0x22, 0x26, 0xef, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xfe, 0xf6, 0x1e, 0xa0,
    0x7f, 0x41, 0xea, 0x8, 0xef, 0x40, 0xe9, 0x5,
    0xf2, 0xe, 0x80, 0x6e, 0xff, 0xef, 0xfe, 0xff,
    0xff, 0xff, 0xef, 0xef, 0xa6, 0xfd, 0x5b, 0xf9,
    0x6f, 0xd5, 0xbe, 0xf2, 0xc, 0x60, 0x3f, 0x0,
    0xc6, 0x3, 0xef, 0xa6, 0xfd, 0x5b, 0xf9, 0x6f,
    0x60, 0x3e, 0xff, 0xef, 0xfe, 0xff, 0xff, 0xf6,
    0x3, 0xef, 0x40, 0xe9, 0x5, 0xf2, 0xe, 0x60,
    0x3e, 0xf5, 0x1e, 0xa0, 0x6f, 0x31, 0xea, 0x7,
    0xed, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfc,
    0x2, 0x33, 0x33, 0x33, 0x33, 0x33, 0x32, 0x0,

    /* U+F1F6 "" */
    0x0, 0x0, 0x0, 0x0, 0x6c, 0x0, 0x0, 0x0,
    0x6a, 0x0, 0x0, 0x0, 0x1, 0x7d, 0xf9, 0x30,
    0x0, 0x9f, 0xe1, 0x0, 0x0, 0x3, 0xef, 0xff,
    0xff, 0x80, 0xaf, 0xc1, 0x0, 0x0, 0x0, 0xdf,
    0xff, 0xff, 0xff, 0xdf, 0xb0, 0x0, 0x0, 0x0,
    0x4f, 0xff, 0xff, 0xff, 0xff, 0x90, 0x0, 0x0,
    0x0, 0x6, 0xff, 0xff, 0xff, 0xff, 0x70, 0x0,
    0x0, 0x0, 0x0, 0x7f, 0xff, 0xff, 0xff, 0x50,
    0x0, 0x0, 0x0, 0x0, 0x9, 0xff, 0xff, 0xfe,
    0x30, 0x10, 0x0, 0x0, 0x0, 0x0, 0xcf, 0xff,
    0xfd, 0x20, 0x2d, 0x20, 0x0, 0x0, 0x0, 0x1f,
    0xff, 0xfc, 0x10, 0x3e, 0xf7, 0x0, 0x0, 0x0,
    0x8, 0xff, 0xfa, 0x0, 0x5f, 0xff, 0xe0, 0x0,
    0x0, 0x3, 0xff, 0xf8, 0x0, 0x7f, 0xff, 0xff,
    0x90, 0x0, 0x1, 0xef, 0xf6, 0x0, 0x9f, 0xff,
    0xff, 0xff, 0x60, 0x0, 0x6f, 0xf4, 0x0, 0xaf,
    0xff, 0xdc, 0xcc, 0xb3, 0x0, 0x8f, 0xe2, 0x0,
    0xc, 0xcf, 0xf5, 0x0, 0x0, 0x0, 0x5, 0xc1,
    0x0, 0x0, 0x4b, 0xe9, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0,

    /* U+F1F8 "" */
    0x0, 0x0, 0x35, 0x55, 0x10, 0x0, 0x0, 0x0,
    0x5f, 0xcc, 0xde, 0x0, 0x0, 0x44, 0x4d, 0x94,
    0x44, 0xe8, 0x44, 0x2d, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xe7, 0xd, 0xff, 0xff, 0xff, 0xff, 0xf7,
    0x0, 0xdf, 0x77, 0xb2, 0xf0, 0xef, 0x70, 0xd,
    0xf7, 0x6b, 0x2f, 0xd, 0xf7, 0x0, 0xdf, 0x76,
    0xb2, 0xf0, 0xdf, 0x70, 0xd, 0xf7, 0x6b, 0x2f,
    0xd, 0xf7, 0x0, 0xdf, 0x76, 0xb2, 0xf0, 0xdf,
    0x70, 0xd, 0xf7, 0x6b, 0x2f, 0xd, 0xf7, 0x0,
    0xdf, 0x88, 0xc4, 0xf2, 0xef, 0x70, 0xd, 0xff,
    0xff, 0xff, 0xff, 0xf6, 0x0, 0x7f, 0xff, 0xff,
    0xff, 0xfe, 0x10, 0x0, 0x12, 0x22, 0x22, 0x22,
    0x0, 0x0,

    /* U+F204 "" */
    0x0, 0x0, 0x2, 0x33, 0x33, 0x33, 0x31, 0x0,
    0x0, 0x0, 0x3, 0xbf, 0xff, 0xff, 0xff, 0xff,
    0xfd, 0x50, 0x0, 0x5, 0xf8, 0x10, 0x5, 0xda,
    0x0, 0x1, 0x6e, 0x90, 0x2, 0xf5, 0x0, 0x0,
    0x1, 0xd7, 0x0, 0x0, 0x1e, 0x60, 0xaa, 0x0,
    0x0, 0x0, 0x4, 0xf0, 0x0, 0x0, 0x5e, 0xe,
    0x40, 0x0, 0x0, 0x0, 0xe, 0x40, 0x0, 0x0,
    0xf2, 0xf2, 0x0, 0x0, 0x0, 0x0, 0xc5, 0x0,
    0x0, 0xe, 0x4d, 0x40, 0x0, 0x0, 0x0, 0xe,
    0x30, 0x0, 0x0, 0xf2, 0x8b, 0x0, 0x0, 0x0,
    0x5, 0xe0, 0x0, 0x0, 0x6d, 0x1, 0xe7, 0x0,
    0x0, 0x3, 0xf5, 0x0, 0x0, 0x4f, 0x40, 0x3,
    0xec, 0x52, 0x38, 0xf9, 0x22, 0x24, 0x9f, 0x60,
    0x0, 0x1, 0x8d, 0xff, 0xff, 0xff, 0xff, 0xea,
    0x20, 0x0,

    /* U+F205 "" */
    0x0, 0x0, 0x2, 0x33, 0x33, 0x33, 0x31, 0x0,
    0x0, 0x0, 0x3, 0xbf, 0xff, 0xff, 0xff, 0xff,
    0xfd, 0x50, 0x0, 0x5, 0xff, 0xff, 0xff, 0xff,
    0x71, 0x0, 0x6e, 0x90, 0x2, 0xff, 0xff, 0xff,
    0xff, 0x30, 0x0, 0x0, 0x1e, 0x60, 0xaf, 0xff,
    0xff, 0xff, 0x70, 0x0, 0x0, 0x0, 0x5e, 0xe,
    0xff, 0xff, 0xff, 0xf1, 0x0, 0x0, 0x0, 0x0,
    0xf2, 0xff, 0xff, 0xff, 0xff, 0x0, 0x0, 0x0,
    0x0, 0xe, 0x4d, 0xff, 0xff, 0xff, 0xf2, 0x0,
    0x0, 0x0, 0x0, 0xf2, 0x8f, 0xff, 0xff, 0xff,
    0x90, 0x0, 0x0, 0x0, 0x6d, 0x1, 0xef, 0xff,
    0xff, 0xff, 0x50, 0x0, 0x0, 0x4f, 0x40, 0x3,
    0xef, 0xff, 0xff, 0xff, 0xa4, 0x24, 0x9f, 0x60,
    0x0, 0x1, 0x8d, 0xff, 0xff, 0xff, 0xff, 0xea,
    0x20, 0x0,

    /* U+F21E "" */
    0x1, 0x7b, 0xb8, 0x10, 0x1, 0x8b, 0xb7, 0x10,
    0x1e, 0xff, 0xff, 0xe5, 0x5f, 0xff, 0xff, 0xe1,
    0xaf, 0xff, 0xfe, 0xaf, 0xff, 0xff, 0xff, 0xfa,
    0xef, 0xff, 0xf9, 0xf, 0xff, 0xff, 0xff, 0xfe,
    0xff, 0xff, 0xf5, 0xb, 0xff, 0xef, 0xff, 0xff,
    0xcf, 0xff, 0xf1, 0x26, 0xfa, 0x1f, 0xff, 0xfc,
    0x5f, 0xff, 0xd0, 0xa2, 0xf5, 0x8, 0xff, 0xf5,
    0x1, 0x11, 0x3, 0xf0, 0xd1, 0x70, 0x11, 0x10,
    0x0, 0x9c, 0xce, 0xf3, 0x41, 0xfd, 0xc9, 0x0,
    0x0, 0xc, 0xff, 0xf8, 0x5, 0xff, 0xc0, 0x0,
    0x0, 0x0, 0xbf, 0xfc, 0xa, 0xfb, 0x0, 0x0,
    0x0, 0x0, 0xb, 0xff, 0x7f, 0xb0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0xaf, 0xfa, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x9, 0x90, 0x0, 0x0, 0x0,

    /* U+F240 "" */
    0x2, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33,
    0x33, 0x0, 0xb, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xfe, 0x10, 0xf2, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0xe3, 0xf,
    0x2c, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0x1e, 0x70, 0xf2, 0xcf, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xf1, 0xbf, 0x4f, 0x2c, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0x10, 0xc6, 0xf2,
    0xcf, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf1,
    0xc, 0x6f, 0x2c, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0x10, 0xc6, 0xf2, 0xcf, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xf1, 0xef, 0x3f, 0x2a,
    0xdd, 0xdd, 0xdd, 0xdd, 0xdd, 0xdd, 0xdd, 0x1e,
    0x40, 0xf4, 0x22, 0x22, 0x22, 0x22, 0x22, 0x22,
    0x22, 0x22, 0xf3, 0x9, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xfc, 0x0,

    /* U+F241 "" */
    0x2, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33,
    0x33, 0x0, 0xb, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xfe, 0x10, 0xf2, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0xe3, 0xf,
    0x2e, 0xff, 0xff, 0xff, 0xff, 0xff, 0x80, 0x0,
    0xe, 0x70, 0xf2, 0xef, 0xff, 0xff, 0xff, 0xff,
    0xf8, 0x0, 0x0, 0xbf, 0x4f, 0x2e, 0xff, 0xff,
    0xff, 0xff, 0xff, 0x80, 0x0, 0x0, 0xc6, 0xf2,
    0xef, 0xff, 0xff, 0xff, 0xff, 0xf8, 0x0, 0x0,
    0xc, 0x6f, 0x2e, 0xff, 0xff, 0xff, 0xff, 0xff,
    0x80, 0x0, 0x0, 0xc6, 0xf2, 0xef, 0xff, 0xff,
    0xff, 0xff, 0xf8, 0x0, 0x0, 0xef, 0x3f, 0x2b,
    0xdd, 0xdd, 0xdd, 0xdd, 0xdd, 0x60, 0x0, 0xe,
    0x40, 0xf4, 0x22, 0x22, 0x22, 0x22, 0x22, 0x22,
    0x22, 0x22, 0xf3, 0x9, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xfc, 0x0,

    /* U+F242 "" */
    0x2, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33,
    0x33, 0x0, 0xb, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xfe, 0x10, 0xf2, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0xe3, 0xf,
    0x2e, 0xff, 0xff, 0xff, 0xf1, 0x0, 0x0, 0x0,
    0xe, 0x70, 0xf2, 0xef, 0xff, 0xff, 0xff, 0x10,
    0x0, 0x0, 0x0, 0xbf, 0x4f, 0x2e, 0xff, 0xff,
    0xff, 0xf1, 0x0, 0x0, 0x0, 0x0, 0xc6, 0xf2,
    0xef, 0xff, 0xff, 0xff, 0x10, 0x0, 0x0, 0x0,
    0xc, 0x6f, 0x2e, 0xff, 0xff, 0xff, 0xf1, 0x0,
    0x0, 0x0, 0x0, 0xc6, 0xf2, 0xef, 0xff, 0xff,
    0xff, 0x10, 0x0, 0x0, 0x0, 0xef, 0x3f, 0x2b,
    0xdd, 0xdd, 0xdd, 0xd1, 0x0, 0x0, 0x0, 0xe,
    0x40, 0xf4, 0x22, 0x22, 0x22, 0x22, 0x22, 0x22,
    0x22, 0x22, 0xf3, 0x9, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xfc, 0x0,

    /* U+F243 "" */
    0x2, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33,
    0x33, 0x0, 0xb, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xfe, 0x10, 0xf2, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0xe3, 0xf,
    0x2a, 0xff, 0xfe, 0x0, 0x0, 0x0, 0x0, 0x0,
    0xe, 0x70, 0xf2, 0xaf, 0xff, 0xe0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0xbf, 0x4f, 0x2a, 0xff, 0xfe,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0xc6, 0xf2,
    0xaf, 0xff, 0xe0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0xc, 0x6f, 0x2a, 0xff, 0xfe, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0xc6, 0xf2, 0xaf, 0xff, 0xe0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0xef, 0x3f, 0x28,
    0xdd, 0xdb, 0x0, 0x0, 0x0, 0x0, 0x0, 0xe,
    0x40, 0xf4, 0x22, 0x22, 0x22, 0x22, 0x22, 0x22,
    0x22, 0x22, 0xf3, 0x9, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xfc, 0x0,

    /* U+F244 "" */
    0x2, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33,
    0x33, 0x0, 0xb, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xfe, 0x10, 0xf2, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0xe3, 0xf,
    0x20, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0xe, 0x90, 0xf2, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0xbf, 0x5f, 0x20, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0xc6, 0xf2,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0xc, 0x6f, 0x20, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0xc6, 0xf2, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0xef, 0x3f, 0x20,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0xe,
    0x40, 0xf4, 0x22, 0x22, 0x22, 0x22, 0x22, 0x22,
    0x22, 0x22, 0xf3, 0x9, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xfb, 0x0,

    /* U+F252 "" */
    0xef, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfa, 0x2d,
    0x73, 0x33, 0x33, 0x33, 0x3a, 0xa1, 0xb, 0x60,
    0x0, 0x0, 0x0, 0xb, 0x70, 0x9, 0x90, 0x0,
    0x0, 0x0, 0xd, 0x40, 0x4, 0xe0, 0x0, 0x0,
    0x0, 0x3f, 0x0, 0x0, 0xdf, 0xff, 0xff, 0xff,
    0xf9, 0x0, 0x0, 0x4f, 0xff, 0xff, 0xff, 0xe1,
    0x0, 0x0, 0x7, 0xff, 0xff, 0xff, 0x40, 0x0,
    0x0, 0x0, 0xcf, 0xff, 0xf8, 0x0, 0x0, 0x0,
    0xc, 0xc2, 0x0, 0x4e, 0x70, 0x0, 0x0, 0x8c,
    0x0, 0x0, 0x2, 0xf4, 0x0, 0x1, 0xf2, 0x0,
    0x0, 0x0, 0x6c, 0x0, 0x7, 0xfd, 0xdd, 0xdd,
    0xdd, 0xdf, 0x20, 0xb, 0xff, 0xff, 0xff, 0xff,
    0xff, 0x60, 0xc, 0xff, 0xff, 0xff, 0xff, 0xff,
    0x80, 0xef, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfa,
    0x23, 0x33, 0x33, 0x33, 0x33, 0x33, 0x31,

    /* U+F287 "" */
    0x0, 0x0, 0x0, 0x0, 0x0, 0x7, 0x70, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x2, 0x6a,
    0xff, 0x80, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x3, 0xfb, 0xdf, 0xfa, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0xc8, 0x1, 0xbb, 0x20, 0x0,
    0x0, 0x0, 0x6, 0x83, 0x0, 0x4f, 0x0, 0x0,
    0x0, 0x0, 0x3, 0x0, 0x9, 0xff, 0xf3, 0xc,
    0x80, 0x0, 0x0, 0x0, 0x0, 0xdc, 0x30, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0x5c, 0xff, 0xf7, 0x33, 0x3b, 0xc3, 0x33,
    0x33, 0x33, 0xde, 0x60, 0x2c, 0xe9, 0x0, 0x0,
    0x2f, 0x20, 0x0, 0x0, 0x6, 0x10, 0x0, 0x0,
    0x0, 0x0, 0x0, 0xa9, 0x2, 0x66, 0x60, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x2, 0xf6, 0x9f,
    0xff, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x5, 0xde, 0xff, 0xf0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x6f, 0xff, 0x0, 0x0,
    0x0,

    /* U+F2C7 "" */
    0x0, 0x5c, 0xc6, 0x0, 0x0, 0x5, 0xd5, 0x6e,
    0x60, 0x0, 0xc, 0x35, 0x25, 0xd3, 0x61, 0xd,
    0x1c, 0x53, 0xe5, 0xb2, 0xd, 0x1c, 0x53, 0xe1,
    0x20, 0xd, 0x1c, 0x53, 0xe8, 0xf3, 0xd, 0x1c,
    0x53, 0xe0, 0x0, 0xd, 0x1c, 0x53, 0xe7, 0xd2,
    0xd, 0x1c, 0x53, 0xe2, 0x40, 0xe, 0x1c, 0x53,
    0xf1, 0x0, 0x9b, 0xd, 0x70, 0xc9, 0x0, 0xe4,
    0xbf, 0xf4, 0x3f, 0x0, 0xf3, 0xef, 0xf7, 0x2f,
    0x0, 0xc7, 0x5e, 0xc1, 0x6d, 0x0, 0x4f, 0x50,
    0x5, 0xf5, 0x0, 0x5, 0xef, 0xff, 0x60, 0x0,
    0x0, 0x3, 0x30, 0x0, 0x0,

    /* U+F2DB "" */
    0x0, 0x3c, 0xdd, 0xdd, 0xdd, 0xc3, 0x0, 0x0,
    0x8f, 0xff, 0xff, 0xff, 0xf8, 0x0, 0x37, 0x8f,
    0xff, 0xff, 0xff, 0xf8, 0x73, 0x48, 0x8f, 0xff,
    0xff, 0xff, 0xf8, 0x84, 0x3, 0x8f, 0xff, 0xff,
    0xff, 0xf8, 0x30, 0x7d, 0x8f, 0xff, 0xff, 0xff,
    0xf8, 0xd7, 0x0, 0x8f, 0xff, 0xff, 0xff, 0xf8,
    0x0, 0x8e, 0x8f, 0xff, 0xff, 0xff, 0xf8, 0xe8,
    0x2, 0x8f, 0xff, 0xff, 0xff, 0xf8, 0x20, 0x59,
    0x8f, 0xff, 0xff, 0xff, 0xf8, 0x95, 0x36, 0x8f,
    0xff, 0xff, 0xff, 0xf8, 0x63, 0x15, 0x8f, 0xff,
    0xff, 0xff, 0xf8, 0x51, 0x6b, 0x8f, 0xff, 0xff,
    0xff, 0xf8, 0xb6, 0x0, 0x8f, 0xff, 0xff, 0xff,
    0xf8, 0x0, 0x0, 0x5f, 0xff, 0xff, 0xff, 0xf5,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0
};


/*---------------------
 *  GLYPH DESCRIPTION
 *--------------------*/

static const lv_font_fmt_txt_glyph_dsc_t glyph_dsc [] = {
    {.bitmap_index = 0, .adv_w = 0, .box_w = 0, .box_h = 0, .ofs_x = 0, .ofs_y = 0} /* id = 0 reserved */,
    {.bitmap_index = 0, .adv_w = 219, .box_w = 14, .box_h = 16, .ofs_x = 0, .ofs_y = -2},
    {.bitmap_index = 112, .adv_w = 219, .box_w = 14, .box_h = 15, .ofs_x = 0, .ofs_y = -2},
    {.bitmap_index = 217, .adv_w = 110, .box_w = 7, .box_h = 12, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 259, .adv_w = 238, .box_w = 15, .box_h = 14, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 364, .adv_w = 219, .box_w = 14, .box_h = 15, .ofs_x = 0, .ofs_y = -2},
    {.bitmap_index = 469, .adv_w = 219, .box_w = 14, .box_h = 15, .ofs_x = 0, .ofs_y = -2},
    {.bitmap_index = 574, .adv_w = 238, .box_w = 15, .box_h = 17, .ofs_x = 0, .ofs_y = -3},
    {.bitmap_index = 702, .adv_w = 274, .box_w = 18, .box_h = 17, .ofs_x = 0, .ofs_y = -3},
    {.bitmap_index = 855, .adv_w = 256, .box_w = 16, .box_h = 13, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 959, .adv_w = 274, .box_w = 18, .box_h = 13, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1076, .adv_w = 274, .box_w = 18, .box_h = 13, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1193, .adv_w = 256, .box_w = 16, .box_h = 17, .ofs_x = 0, .ofs_y = -3},
    {.bitmap_index = 1329, .adv_w = 219, .box_w = 14, .box_h = 15, .ofs_x = 0, .ofs_y = -2},
    {.bitmap_index = 1434, .adv_w = 219, .box_w = 14, .box_h = 15, .ofs_x = 0, .ofs_y = -2},
    {.bitmap_index = 1539, .adv_w = 219, .box_w = 14, .box_h = 15, .ofs_x = 0, .ofs_y = -2},
    {.bitmap_index = 1644, .adv_w = 274, .box_w = 18, .box_h = 10, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1734, .adv_w = 219, .box_w = 14, .box_h = 17, .ofs_x = 0, .ofs_y = -3},
    {.bitmap_index = 1853, .adv_w = 256, .box_w = 16, .box_h = 17, .ofs_x = 0, .ofs_y = -3},
    {.bitmap_index = 1989, .adv_w = 256, .box_w = 15, .box_h = 17, .ofs_x = 0, .ofs_y = -3},
    {.bitmap_index = 2117, .adv_w = 293, .box_w = 19, .box_h = 17, .ofs_x = 0, .ofs_y = -3},
    {.bitmap_index = 2279, .adv_w = 201, .box_w = 13, .box_h = 15, .ofs_x = 0, .ofs_y = -2},
    {.bitmap_index = 2377, .adv_w = 293, .box_w = 19, .box_h = 12, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 2491, .adv_w = 293, .box_w = 19, .box_h = 12, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 2605, .adv_w = 256, .box_w = 16, .box_h = 14, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 2717, .adv_w = 329, .box_w = 21, .box_h = 12, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 2843, .adv_w = 329, .box_w = 21, .box_h = 12, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 2969, .adv_w = 329, .box_w = 21, .box_h = 12, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 3095, .adv_w = 329, .box_w = 21, .box_h = 12, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 3221, .adv_w = 329, .box_w = 21, .box_h = 12, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 3347, .adv_w = 219, .box_w = 14, .box_h = 17, .ofs_x = 0, .ofs_y = -3},
    {.bitmap_index = 3466, .adv_w = 329, .box_w = 21, .box_h = 13, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 3603, .adv_w = 146, .box_w = 10, .box_h = 17, .ofs_x = 0, .ofs_y = -3},
    {.bitmap_index = 3688, .adv_w = 219, .box_w = 14, .box_h = 16, .ofs_x = 0, .ofs_y = -2}
};

/*---------------------
 *  CHARACTER MAPPING
 *--------------------*/

static const uint16_t unicode_list_0 [] = {
    0x0, 0x6, 0x15, 0x17, 0x31, 0x49, 0x62, 0x74,
    0x9d, 0xdc, 0xdd, 0xe2, 0x107, 0x108, 0x109, 0x10a,
    0x16b, 0x1c5, 0x1db, 0x1e5, 0x1e7, 0x1f3, 0x1f4, 0x20d,
    0x22f, 0x230, 0x231, 0x232, 0x233, 0x241, 0x276, 0x2b6,
    0x2ca
};

/*Collect the unicode lists and glyph_id offsets*/
static const lv_font_fmt_txt_cmap_t cmaps [] =
{
    {
        .range_start = 61457, .range_length = 715, .glyph_id_start = 1,
        .unicode_list = unicode_list_0, .glyph_id_ofs_list = NULL, .list_length = 33, .type = LV_FONT_FMT_TXT_CMAP_SPARSE_TINY
    }
};



/*--------------------
 *  ALL CUSTOM DATA
 *--------------------*/

#if LV_VERSION_CHECK(8, 0, 0)
 /*Store all the custom data of the font*/
static  lv_font_fmt_txt_glyph_cache_t cache;
static const lv_font_fmt_txt_dsc_t font_dsc = {
#else
static lv_font_fmt_txt_dsc_t font_dsc = {
#endif
    .glyph_bitmap = glyph_bitmap,
    .glyph_dsc = glyph_dsc,
    .cmaps = cmaps,
    .kern_dsc = NULL,
    .kern_scale = 0,
    .cmap_num = 1,
    .bpp = 4,
    .kern_classes = 0,
    .bitmap_format = 0,
#if LV_VERSION_CHECK(8, 0, 0)
    .cache = &cache
#endif
};


/*-----------------
 *  PUBLIC FONT
 *----------------*/

 /*Initialize a public general font descriptor*/
 #if LV_VERSION_CHECK(8, 0, 0)
 const lv_font_t hwatch_icons_font_16 = {
 #else
 lv_font_t hwatch_icons_font_16 = {
 #endif
     .get_glyph_dsc = lv_font_get_glyph_dsc_fmt_txt,    /*Function pointer to get glyph's data*/
     .get_glyph_bitmap = lv_font_get_bitmap_fmt_txt,    /*Function pointer to get glyph's bitmap*/
     .line_height = 17,          /*The maximum line height required by the font*/
     .base_line = 3,             /*Baseline measured from the bottom of the line*/
 #if !(LVGL_VERSION_MAJOR == 6 && LVGL_VERSION_MINOR == 0)
     .subpx = LV_FONT_SUBPX_NONE,
 #endif
 #if LV_VERSION_CHECK(7, 4, 0)
     .underline_position = 0,
     .underline_thickness = 0,
 #endif
     .dsc = &font_dsc           /*The custom font data. Will be accessed by `get_glyph_bitmap/dsc` */
 };



 #endif /*#if HWATCH_ICONS_FONT_16*/

