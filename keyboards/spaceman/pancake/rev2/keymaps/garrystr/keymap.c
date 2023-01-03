 /* Copyright Spaceman 2021
  *
  * This program is free software: you can redistribute it and/or modify
  * it under the terms of the GNU General Public License as published by
  * the Free Software Foundation, either version 2 of the License, or
  * (at your option) any later version.
  *
  * This program is distributed in the hope that it will be useful,
  * but WITHOUT ANY WARRANTY; without even the implied warranty of
  * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  * GNU General Public License for more details.
  *
  * You should have received a copy of the GNU General Public License
  * along with this program.  If not, see <http://www.gnu.org/licenses/>.
  */

#include QMK_KEYBOARD_H
enum layers {
  _DEFAULT,
  _RAISE,
  _FN
};

#define RAISE MO(_RAISE)
#define FN MO(_FN)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Default
 * ,-----------------------------------------------------------------------------------.
 * | Esc  |   Q  |   W  |   F  |   P  |   B  |   J  |   L  |   U  |   Y  |   -  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |  Tab |   A  |   R  |   S  |   T  |   G  |   M  |   N  |   E  |   I  |   O  | ENT  |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   D  |   V  |   K  |   H  |   ,  |   .  |   ;  | Shift|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |   /  | Ctrl | Alt  |  GUI  | FN  | Spc  |Raise | Left | Down |  Up  |Right |  '   |
 * `-----------------------------------------------------------------------------------'
 */
[_DEFAULT] = LAYOUT_ortho_4x12(
    KC_ESC,  KC_Q,    KC_W,    KC_F,    KC_P,   KC_B,    KC_J,   KC_L,    KC_U,    KC_Y,    KC_MINS, KC_BSPC,
    KC_TAB,  KC_A,    KC_R,    KC_S,    KC_T,   KC_G,    KC_M,   KC_N,    KC_E,    KC_I,    KC_O,    KC_ENT,
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_D,   KC_V,    KC_K,   KC_H,    KC_COMM, KC_DOT,  KC_SCLN, KC_RSFT,
    KC_SLSH, KC_LCTL, KC_LALT, KC_LGUI, FN,     KC_SPC,  RAISE,  KC_LEFT, KC_DOWN,  KC_UP,  KC_RGHT, KC_QUOT
),

/* Raise
 * ,-----------------------------------------------------------------------------------.
 * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | DEL  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |   -  |  =   |   [  |   ]  |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      | Vol- |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |   \  |      |      |      |      |      |      |      |      |      | Vol+ |      |
 * `-----------------------------------------------------------------------------------'
 */
[_RAISE] = LAYOUT_ortho_4x12(
    KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_DEL,
    _______, _______, _______, _______, _______, _______, _______, KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_VOLU, _______,
    KC_BSLS, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_VOLD, _______
),

 /* FN
 * ,-----------------------------------------------------------------------------------.
 * | F1   |  F2  |  F3  |  F4  |  F5  |  F6  |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      | TRNS |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_FN] = LAYOUT_ortho_4x12(
    KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10, KC_F11,  KC_F12,
    _______, _______, _______, _______, _______, _______, _______, _______, _______,  ______________,,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
),


};
