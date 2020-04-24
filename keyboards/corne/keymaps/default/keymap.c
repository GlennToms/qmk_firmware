#include QMK_KEYBOARD_H


extern uint8_t is_master;

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _TYPING 0
#define _NUMBERS 1
#define  _ARROWS 2

enum custom_keycodes {
  TYPING = SAFE_RANGE,
  NUMBERS,
  ARROWS
};

enum macro_keycodes {
  KC_SAMPLEMACRO,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_TYPING] = LAYOUT( \
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      KC_TAB,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                         KC_Y,    KC_U,    KC_I,    KC_O,   KC_P,  KC_BSPC,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LSFT,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                         KC_H,    KC_J,    KC_K,    KC_L, KC_QUOT, LSFT_T(KC_ENT),  \
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LCTL,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                      KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH, TT(_NUMBERS),\
  //|--------+--------+--------+--------+--------+--------+--------|        |--------+--------+--------+--------+--------+--------+--------|
                            TO(_TYPING),   TT(_NUMBERS),  MO(_ARROWS),        KC_ENT,  KC_SPC,  KC_RALT \
                                      //`--------------------------'        `--------------------------'

  ),

  [_NUMBERS] = LAYOUT( \
  //,-----------------------------------------------------.                              ,-----------------------------------------------------.
      KC_GESC, KC_EXLM, KC_AT, KC_ASTR, KC_LCBR, KC_RCBR,                                   XXXXXXX, KC_7,  KC_8,   KC_9,   XXXXXXX,    KC_BSPC,\
  //|--------+--------+--------+--------+--------+--------|                              |--------+--------+--------+--------+--------+--------|
      KC_TRNS, KC_CIRC, KC_AMPR, KC_MINS, KC_LPRN, KC_RPRN,                                XXXXXXX, KC_4,   KC_5,   KC_6,   XXXXXXX,    KC_TRNS,\
  //|--------+--------+--------+--------+--------+--------|                              |--------+--------+--------+--------+--------+--------|
      KC_TRNS, XXXXXXX, XXXXXXX, KC_HASH, KC_EQL, XXXXXXX,                                KC_0,    KC_1,   KC_2,   KC_3,   XXXXXXX,    XXXXXXX,\
  //|--------+--------+--------+--------+--------+--------+--------|              |--------+--------+--------+--------+--------+--------+--------|
                            TG(_NUMBERS),  TT(_ARROWS), KC_TRNS,               KC_TRNS,  KC_TRNS, KC_PDOT \
                                      //`--------------------------'              `--------------------------'
    ),

  [_ARROWS] = LAYOUT( \
  //,-----------------------------------------------------.                         ,-----------------------------------------------------.
       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX, XXXXXXX,                        KC_F7, KC_F8, KC_F9, KC_END, KC_HOME, KC_BSPC,\
  //|--------+--------+--------+--------+--------+--------|                         |--------+--------+--------+--------+--------+--------|
      KC_TRNS, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                             KC_F4,  KC_F5, KC_F6, KC_DEL, KC_UP,  KC_TRNS,\
  //|--------+--------+--------+--------+--------+--------|                         |--------+--------+--------+--------+--------+--------|
      KC_TRNS, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                             KC_F1, KC_F2, KC_F3, KC_LEFT, KC_DOWN, KC_RIGHT,\
  //|--------+--------+--------+--------+--------+--------+--------|                |--------+--------+--------+--------+--------+--------+--------|
                                TG(_ARROWS),   XXXXXXX,  KC_TRNS,                      KC_TRNS,  KC_TRNS, KC_RALT \
                                      //`--------------------------'                `--------------------------'
  )
};
