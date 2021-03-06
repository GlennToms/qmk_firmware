#include QMK_KEYBOARD_H


extern uint8_t is_master;

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _TYPING 0
#define _NUMBERS 1
#define  _ARROWS 2
#define  _FKEYS 3

enum custom_keycodes {
  TYPING = SAFE_RANGE,
  NUMBERS,
  ARROWS,
  FKEYS
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
      KC_LCTL,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                      KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH, XXXXXXX,\
  //|--------+--------+--------+--------+--------+--------+--------|        |--------+--------+--------+--------+--------+--------+--------|
                                    KC_LALT,  KC_LGUI,  MO(_ARROWS),        MO(_ARROWS),  LT(_NUMBERS, KC_SPC),  KC_LGUI \
                                      //`--------------------------'        `--------------------------'

  ),

  [_NUMBERS] = LAYOUT( \
  //,-----------------------------------------------------.                              ,-----------------------------------------------------.
      KC_GESC, KC_GRAVE, KC_TRNS, KC_TRNS, KC_LCBR, KC_RCBR,                                   XXXXXXX, KC_7,  KC_8,   KC_9,   XXXXXXX,    KC_DEL,\
  //|--------+--------+--------+--------+--------+--------|                              |--------+--------+--------+--------+--------+--------|
      KC_TRNS, KC_NUHS, KC_EQL, KC_MINS, KC_LPRN, KC_RPRN,                                KC_DOT, KC_4,   KC_5,   KC_6,   KC_SCLN,    KC_TRNS,\
  //|--------+--------+--------+--------+--------+--------|                              |--------+--------+--------+--------+--------+--------|
      KC_TRNS, KC_NUBS, KC_TRNS, KC_TRNS, KC_LBRC, KC_RBRC,                                KC_0,    KC_1,   KC_2,   KC_3,   KC_DOT,    KC_TRNS,\
  //|--------+--------+--------+--------+--------+--------+--------|              |--------+--------+--------+--------+--------+--------+--------|
                                    KC_TRNS,  KC_TRNS, KC_TRNS,                    KC_TRNS,  KC_TRNS, KC_TRNS \
                                      //`--------------------------'              `--------------------------'
    ),

  [_ARROWS] = LAYOUT( \
  //,-----------------------------------------------------.                         ,-----------------------------------------------------.
       KC_GESC, XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX, XXXXXXX,                        XXXXXXX, XXXXXXX, XXXXXXX, KC_PGUP, KC_PGDN, KC_BSPC,\
  //|--------+--------+--------+--------+--------+--------|                         |--------+--------+--------+--------+--------+--------|
      KC_TRNS, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                          XXXXXXX, XXXXXXX, XXXXXXX, KC_HOME,  KC_UP,  KC_END,\
  //|--------+--------+--------+--------+--------+--------|                         |--------+--------+--------+--------+--------+--------|
      KC_TRNS, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                          XXXXXXX, XXXXXXX, XXXXXXX, KC_LEFT, KC_DOWN, KC_RIGHT,\
  //|--------+--------+--------+--------+--------+--------+--------|                |--------+--------+--------+--------+--------+--------+--------|
                                KC_TRNS,   KC_TRNS,  KC_TRNS,              MO(_FKEYS),  KC_TRNS, KC_TRNS \
                                      //`--------------------------'                `--------------------------'
  ),
  
  [_FKEYS] = LAYOUT( \
  //,-----------------------------------------------------.                              ,-----------------------------------------------------.
      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                                   KC_TRNS, KC_F7,  KC_F8,   KC_F9,   KC_F10,    KC_BSPC,\
  //|--------+--------+--------+--------+--------+--------|                              |--------+--------+--------+--------+--------+--------|
      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                                  KC_TRNS, KC_F4,   KC_F5,   KC_F6,   KC_F11,    KC_TRNS,\
  //|--------+--------+--------+--------+--------+--------|                              |--------+--------+--------+--------+--------+--------|
      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                                KC_TRNS,  KC_F1,   KC_F2,   KC_F3,   KC_F12,    KC_TRNS,\
  //|--------+--------+--------+--------+--------+--------+--------|              |--------+--------+--------+--------+--------+--------+--------|
                                        KC_TRNS,  KC_TRNS, KC_TRNS,               KC_TRNS,  KC_TRNS, KC_TRNS \
                                      //`--------------------------'              `--------------------------'
    ),
};
