#include QMK_KEYBOARD_H

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _DVORAK 0
#define _QWERTY 1
#define _COLEMAK 2
#define _NUMS 3
#define _FUNCT 4
#define _ADJUST 16

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  COLEMAK,
  DVORAK,
  ADJUST,
  NUMS,
  FUNCT
};
/*
#define LOWER  MO(_LOWER)
#define RAISE  MO(_RAISE)
*/
#define ADJUST MO(_ADJUST)


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Qwerty
 * ,-----------------------------------------------------------------------------------.
 * |  Tab |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |  Esc |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  | Enter|
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |   /  |   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   -  |Shift |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |SftCap| Ctrl | Alt  | GUI  | DEL  |Space |Adjust | Left|  Up  | Down |Right |   '  |
 * `-----------------------------------------------------------------------------------'
 */
[_QWERTY] = LAYOUT_ortho_4x12(
   KC_TAB ,        KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC, \
   KC_ESC,         KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_ENT, \
   SFT_T(KC_CAPS), KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_MINS, KC_RSFT , \
   KC_SLSH,        KC_LCTL, KC_LALT, KC_LGUI, KC_DEL,  KC_SPC,  ADJUST,  KC_LEFT, KC_DOWN,   KC_UP, KC_RGHT, KC_QUOT \
),

/* Colemak
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |   Q  |   W  |   F  |   P  |   B  |   J  |   L  |   U  |   Y  |   ;  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Esc  |   A  |   R  |   S  |   T  |   G  |   M  |   N  |   E  |   I  |   O  | Enter|
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |   /  |   Z  |   X  |   C  |   D  |   V  |   K  |   H  |   ,  |   .  |   -  |Shift |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |SftCap| Ctrl | Alt  | GUI  | DEL  |Space |Adjust | Left|  Up  | Down |Right |   '  |
 * `-----------------------------------------------------------------------------------'
 */
[_COLEMAK] = LAYOUT_ortho_4x12( \
  KC_TAB,         KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,    KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN, KC_BSPC, \
  KC_ESC,         KC_A,    KC_R,    KC_S,    KC_T,    KC_G,    KC_M,    KC_N,    KC_E,    KC_I,    KC_O,    KC_ENT, \
  SFT_T(KC_CAPS), KC_Z,    KC_X,    KC_C,    KC_D,    KC_V,    KC_K,    KC_H,    KC_COMM, KC_DOT,  KC_MINS, KC_RSFT, \
  KC_SLSH,        KC_LCTL, KC_LALT, KC_LGUI, KC_DEL,  KC_SPC,  ADJUST,  KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_QUOT   \
),

/* Dvorak
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |   ,  |   .  |   P  |   Y  |   F  |   G  |   C  |   R  |   L  |   -  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Esc  |   A  |   O  |   E  |   U  |   I  |   D  |   H  |   T  |   N  |   S  | Enter|
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |   /  |   ;  |   Q  |   J  |   K  |   X  |   B  |   M  |   W  |   V  |   Z  |Shift |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |SftCap| Ctrl | Alt  | GUI  | DEL  |Space |Adjust | Left|  Up  | Down |Right |   '  |
 * `-----------------------------------------------------------------------------------'
 */
[_DVORAK] = LAYOUT_ortho_4x12( \
  KC_TAB,           KC_COMM, KC_DOT,  KC_P,    KC_Y,    KC_F,    KC_G,    KC_C,    KC_R,    KC_L,    KC_MINS, KC_BSPC, \
  KC_ESC,           KC_A,    KC_O,    KC_E,    KC_U,    KC_I,    KC_D,    KC_H,    KC_T,    KC_N,    KC_S,    KC_ENT, \
  SFT_T(KC_CAPS),   KC_Z,    KC_Q,    KC_J,    KC_K,    KC_X,    KC_B,    KC_M,    KC_W,    KC_V,    KC_SCLN,    KC_RSFT, \
  KC_SLSH ,       KC_LCTL,   KC_LALT, KC_LGUI, KC_DEL,  KC_SPC,  ADJUST,  KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_QUOT   \
),

/* Numbers
 * ,-----------------------------------------------------------------------------------.
 * | TAB  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |   `  |      |      |      |      |      |      |   -  |   =  |   [  |   ]  |Enter |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |   ~  |   ;  |  X   |   C  |  V   |      |ISO | |ISO ~ |   ,  |   .  |   \  |  /   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |Shift | Ctrl | Alt  | GUI  | DEL  |Space |Adjust | Left| Down |  Up  |Right |Shift |
 * `-----------------------------------------------------------------------------------'
 */
[_NUMS] = LAYOUT_ortho_4x12( \
  KC_TAB,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC, \
  KC_GRV,  KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_ENT, \
  KC_TILD, KC_SCLN, KC_X,    KC_C,    KC_V,    KC_NO,   KC_NUBS, KC_NUHS, KC_COMM, KC_DOT,  KC_BSLS, KC_SLSH, \
  KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI, KC_DEL,  KC_SPC,  ADJUST,  KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_RSFT  \
),

/* Function
 * ,-----------------------------------------------------------------------------------.
 * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  F7  |  F8  |  F9  | F10  | F11  |  F12 |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Bksp |   1  |   2  |   3  |   4  |   5  |   6  |   7  |  8   |   9  |   0  |  ENT |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |   /  |   Z  |   X  |   C  |   V  |      |   R  |  M   |  D   |      |      |   .  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |Shift | Ctrl | Alt  | GUI  | DEL  |Space |Adjust| Left |  Up  | Down |Right |Shift |
 * `-----------------------------------------------------------------------------------'
 */
[_FUNCT] = LAYOUT_ortho_4x12( \
  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12, \
  KC_BSPC, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_ENT, \
  KC_SLSH, KC_Z,    KC_X,    KC_C,    KC_V,    KC_NO,   KC_R,    KC_M,    KC_D,    KC_NO,   KC_NO,   KC_DOT, \
  KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI, KC_DEL,  KC_SPC,  ADJUST,  KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_RSFT  \
),

/* Adjust
 * ,-----------------------------------------------------------------------------------.
 * |      |Qwerty|      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |Dvorak| Funct|      |      |      |      |      |      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |Colemk|      |      | Nums |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_ADJUST] =  LAYOUT_ortho_4x12( \
  _______,  QWERTY, _______, _______,  _______, _______, _______, _______, _______, _______, _______, _______, \
  _______, _______, _______, DVORAK , FUNCT, _______, _______, _______, _______, _______,  _______, _______, \
  _______, _______, _______, COLEMAK, _______, _______, NUMS,  _______, _______, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______ \
)


};
/*
layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}


layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _ADJUST);
}

* The above change made doesn't work as there needs to be 3 variables
* It might seem obvious after the fact!!
*
*/

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case DVORAK:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_DVORAK);
      }
      return false;
    case QWERTY:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_QWERTY);
      }
      return false;
    case COLEMAK:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_COLEMAK);
      }
      return false;
    case NUMS:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_NUMS);
      }
      return false;
    case FUNCT:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_FUNCT);
      }
      return false;
  }
  return true;
}
