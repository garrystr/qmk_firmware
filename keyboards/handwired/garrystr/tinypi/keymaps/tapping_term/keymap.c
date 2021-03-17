#include "tinypi.h"

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
#define _MOUSE 8
#define _ADJUST 16


typedef struct {
  bool is_press_action;
  uint8_t state;
} tap;

enum {
  SINGLE_TAP = 1,
  SINGLE_HOLD,
  DOUBLE_TAP
};

enum {
  ENT_LAYER_CAPS,
};

uint8_t cur_dance(qk_tap_dance_state_t *state);

void ql_finished(qk_tap_dance_state_t *state, void *user_data);
void ql_reset(qk_tap_dance_state_t *state, void *user_data);

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  COLEMAK,
  DVORAK,
  ADJUST,
  NUMS,
  FUNCT,
  MOUSE
};  

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  
  /* Qwerty
  * ,---------------------------------------------------------------------.
  * |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  |
  * |------+------+------+------+------+-------------+------+------+------|
  * |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   '  |
  * |------+------+------+------+------+------|------+------+------+------|
  * |   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   -  |
  * |------+------+------+------+------+------+------+------+------+------|
  * |                    | Bkspc|    Space    | Enter|                    |
  * `---------------------------------------------------------------------'
  */
  
  [_QWERTY] = LAYOUT(
    KC_Q,    KC_W,           KC_E,           KC_R,           KC_T,    KC_Y,    KC_U,           KC_I,             KC_O,            KC_P,
    KC_A,    CTL_T(KC_S),    ALT_T(KC_D),    GUI_T(KC_F),    KC_G,    KC_H,    GUI_T(KC_J),    ALT_T(KC_K),    RCTL_T(KC_L),    KC_QUOT,
    KC_Z,    KC_X,           KC_C,           KC_V,           KC_B,    KC_N,    KC_M,           KC_COMM,          KC_DOT,          KC_MINS,
                                             KC_BSPC,        SFT_T(KC_SPC),    TD(ENT_LAYER_CAPS)),

  /* Colemak
  * ,---------------------------------------------------------------------.
  * |   Q  |   W  |   F  |   P  |   B  |   J  |   L  |   U  |   Y  |   '  |
  * |------+------+------+------+------+-------------+------+------+------|
  * |   A  |   R  |   S  |   T  |   G  |   M  |   N  |   E  |   I  |   O  |
  * |------+------+------+------+------+------|------+------+------+------|
  * |   Z  |   X  |   C  |   D  |   V  |   K  |   H  |   ,  |   .  |   -  |
  * |------+------+------+------+------+------+------+------+------+------|
  * |                    | Bkspc|    Space    | Enter|                    |
  * `---------------------------------------------------------------------'
  */
  
  [_COLEMAK] = LAYOUT(
    KC_Q,  KC_W,         KC_F,         KC_P,         KC_B,  KC_J,   KC_L,         KC_U,         KC_Y,          KC_QUOT,
    KC_A,  CTL_T(KC_R),  ALT_T(KC_S),  GUI_T(KC_T),  KC_G,  KC_M,   GUI_T(KC_N),  ALT_T(KC_E),  RCTL_T(KC_I),  KC_O,
    KC_Z,  KC_X,         KC_C,         KC_D,         KC_V,  KC_K,   KC_H,         KC_COMM,      KC_DOT,        KC_MINS,
                                       KC_BSPC,      SFT_T(KC_SPC), TD(ENT_LAYER_CAPS)),

  /* Dvorak
  * ,---------------------------------------------------------------------.
  * |   ,  |   .  |   P  |   Y  |   F  |   G  |   C  |   R  |   L  |   '  |
  * |------+------+------+------+------+-------------+------+------+------|
  * |   A  |   O  |   E  |   U  |   I  |   D  |   H  |   T  |   N  |   S  |
  * |------+------+------+------+------+------|------+------+------+------|
  * |   -  |   Q  |   J  |   K  |   X  |   B  |   M  |   W  |   V  |   Z  |
  * |------+------+------+------+------+------+------+------+------+------|
  * |                    | Bkspc|    Space    | Enter|                    |
  * `---------------------------------------------------------------------'
  */
  
  [_DVORAK] = LAYOUT(
    KC_COMM, KC_DOT,      KC_P,        KC_Y,        KC_F, KC_G,    KC_C,        KC_R,          KC_L,         KC_QUOT,
    KC_A,    CTL_T(KC_O), ALT_T(KC_E), GUI_T(KC_U), KC_I, KC_D,    GUI_T(KC_H), ALT_T(KC_T),   RCTL_T(KC_N), KC_S,
    KC_MINS, KC_Q,        KC_J,        KC_K,        KC_X, KC_B,    KC_M,        KC_W,          KC_V,         KC_Z,
                                       KC_BSPC,     SFT_T(KC_SPC), TD(ENT_LAYER_CAPS)),

  /* Numbers
  * ,---------------------------------------------------------------------.
  * |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  |
  * |------+------+------+------+------+-------------+------+------+------|
  * |   `  |LCTRL | LALT | LGUI |ISO ~ |ISO | |   -  |   =  |   [  |   ]  |
  * |------+------+------+------+------+------|------+------+------+------|
  * |  DEL |   ;  |   \  | Left |  Up  | Down |Right |   ,  |   .  |   /  |
  * |------+------+------+------+------+------+------+------+------+------|
  * |                    | Bkspc|    Space    | Enter|                    |
  * `---------------------------------------------------------------------'
  */
  
  [_NUMS] = LAYOUT(
    KC_1,    KC_2,        KC_3,        KC_4,        KC_5,    KC_6,       KC_7,        KC_8,    KC_9,    KC_0,
    KC_GRV,  KC_LCTL,     KC_LALT,     KC_LGUI,     KC_NUHS, KC_NUBS,    KC_MINS,     KC_EQL,  KC_LBRC, KC_RBRC,
    KC_DEL,  KC_NO,       KC_NO,       KC_LEFT,     KC_UP,   KC_DOWN,    KC_RIGHT,    KC_SCLN, KC_BSLS, KC_SLSH,
                                       KC_BSPC,     SFT_T(KC_SPC),       TD(ENT_LAYER_CAPS)),

  /* Function
  * ,---------------------------------------------------------------------.
  * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  F7  |  F8  |  F9  | F10  |
  * |------+------+------+------+------+-------------+------+------+------|
  * |  F11 |  F12 |      |      |      |      | ISO #| ISO /|      |RGBST |
  * |------+------+------+------+------+------|------+------+------+------|
  * | RGBT | RGBF | RGBR |RGBHU |RGBHD |RGBSI |RGBSD |RGBBI |RGBBD |RGBAN |
  * |------+------+------+------+------+------+------+------+------+------|
  * |                    | Bkspc|    Space    | Enter|                    |
  * `---------------------------------------------------------------------'
  */
  
  [_FUNCT] = LAYOUT(
    KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,
    KC_F11,  KC_F12,  _______, _______, _______, _______, KC_NUHS, KC_NUBS, _______, RGB_M_P,
    RGB_TOG, RGB_MOD, RGB_RMOD,RGB_HUI, RGB_HUD, RGB_SAI, RGB_SAD, RGB_VAI, RGB_VAD, RGB_M_T,
                               KC_BSPC,  SFT_T(KC_SPC),   TD(ENT_LAYER_CAPS)),

  /* Mouse
  * ,---------------------------------------------------------------------.
  * |  SP0 |      |      |  B1  |  MU  |  WU  |  B2  |      |      |      |
  * |------+------+------+------+------+-------------+------+------+------|
  * |  SP1 |      |      |  ML  |  B3  |  B4  |  MR  |      |      |      |
  * |------+------+------+------+------+------|------+------+------+------|
  * |  SP2 |      |      |  WL  |  MD  |   WD |  WR  |      |      |      |
  * |------+------+------+------+------+------+------+------+------+------|
  * |                    | Bkspc|    Space    | Enter|                    |
  * `---------------------------------------------------------------------'
  */
  
  [_MOUSE] = LAYOUT(
    KC_ACL0,  KC_NO,  KC_NO, KC_BTN1,   KC_MS_U,   KC_WH_U,   KC_BTN2,   KC_NO,   KC_NO,   KC_NO,
    KC_ACL1,  KC_NO,  KC_NO, KC_MS_L,   KC_BTN3,   KC_BTN4,   KC_MS_R,   KC_NO,   KC_NO,   KC_NO,
    KC_ACL2,  KC_NO,  KC_NO, KC_WH_L,   KC_MS_D,   KC_WH_D,   KC_WH_R,   KC_NO,   KC_NO,   KC_NO,
                             KC_BSPC,   SFT_T(KC_SPC),         TD(ENT_LAYER_CAPS)),

  /* Adjust
  * ,---------------------------------------------------------------------.
  * |Qwerty|      |      |      |      |      |      |      |      |      |
  * |------+------+------+------+------+-------------+------+------+------|
  * |      |      |Dvorak| Funct|      |      |      |      |      |      |
  * |------+------+------+------+------+------|------+------+------+------|
  * |      |      |Colemk|      |      | Nums | Mouse|      |      |      |
  * |------+------+------+------+------+------+------+------+------+------|
  * |                    | RESET|     TAB     |      |                    |
  * `---------------------------------------------------------------------'
  */

  [_ADJUST] = LAYOUT(
    QWERTY,  _______, _______,  _______, _______, _______, _______, _______, _______, _______,
    _______, _______, DVORAK ,  FUNCT,   _______, _______, _______, _______, _______, _______,
    _______, _______, COLEMAK,  _______, _______, NUMS,    MOUSE,   _______, _______, _______,
                                RESET,      KC_TAB, _______)
};

uint8_t cur_dance(qk_tap_dance_state_t *state) {
  if (state->count == 1) {
    if (!state->pressed) return SINGLE_TAP;
    else return SINGLE_HOLD;
  } else if (state->count == 2) return DOUBLE_TAP;
  else return 8;
}

static tap ql_tap_state = {
  .is_press_action = true,
  .state = 0
};

void ql_finished(qk_tap_dance_state_t *state, void *user_data){
  ql_tap_state.state = cur_dance(state);
  switch (ql_tap_state.state) {
    case SINGLE_TAP:
      tap_code(KC_ENT);
      break;
    case SINGLE_HOLD:
      layer_on(_ADJUST);
      break;
    case DOUBLE_TAP:
      tap_code(KC_CAPS);
      break;
  }
}

void ql_reset(qk_tap_dance_state_t *state, void *user_data) {
  if (ql_tap_state.state == SINGLE_HOLD) {
    layer_off(_ADJUST);
  }
  ql_tap_state.state = 0;
}

qk_tap_dance_action_t tap_dance_actions[] = {
  [ENT_LAYER_CAPS] = ACTION_TAP_DANCE_FN_ADVANCED_TIME(NULL, ql_finished, ql_reset, 275)
};


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
    case MOUSE:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_MOUSE);
      }
      return false;
  }
  return true;
}
