/*
This is the c configuration file for the keymap

Copyright 2012 Jun Wako <wakojun@gmail.com>
Copyright 2015 Jack Humbert

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#pragma once


#include "config_common.h"

/* USB Device descriptor parameter */
#define VENDOR_ID 0x0001
#define PRODUCT_ID 0x0001
#define DEVICE_VER 0x0001
#define MANUFACTURER Me
#define PRODUCT TinyPi Board
#define DESCRIPTION small board with a Raspberry Pi4B

/* COL2ROW or ROW2COL */
#define DIODE_DIRECTION COL2ROW

/* key matrix size */
#define MATRIX_ROWS 4
#define MATRIX_COLS 10

/* key matrix pins */
#define MATRIX_ROW_PINS { D1, D0, D4, C6 }
#define MATRIX_COL_PINS { B3, B1, F7, F6, F5, F4, B5, B4, E6, D7 }

/* Set 0 if debouncing isn't needed */
#define DEBOUNCE 5

#define RGB_DI_PIN B6
#ifdef RGB_DI_PIN
#define RGBLIGHT_ANIMATIONS
#define RGBLED_NUM 5
#define RGBLIGHT_HUE_STEP 8
#define RGBLIGHT_SAT_STEP 8
#define RGBLIGHT_VAL_STEP 8
#define RGBLIGHT_LIMIT_VAL 125
#endif

/* place overrides here
#define DEFAULT_LAYER_SONGS { SONG(QWERTY_SOUND), \
                              SONG(COLEMAK_SOUND), \
                              SONG(DVORAK_SOUND) \
                            }


set_single_persistent_default_layer(_DVORAK)
*/


#undef TAPPING_TERM
#define TAPPING_TERM 200 //At 500 some bad logic takes hold
#define IGNORE_MOD_TAP_INTERRUPT
#define PERMISSIVE_HOLD
