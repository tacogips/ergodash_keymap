#include QMK_KEYBOARD_H

extern keymap_config_t keymap_config;

#define _QWERTY 0
//#define _LOWER 1
//#define _RAISE 2
//#define _ADJUST 16

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
// LOWER,
// RAISE,
// ADJUST,
};

#define EISU LALT(KC_GRV)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  /* Qwerty
 * ,-------------------------------------------------------------------------------------------------------------------------.
   * | ESC  |   1  |   2  |   3  |   4  |   5  |  6   |                    |   7  |   8  |   9  |   0  |  -   |   \  |  =   |
   * |------+------+------+------+------+------+------+--------------------+------+------+------+------+------+------+------|
   * | Tab  |   Q  |   W  |   E  |   R  |   T  |  `   |                    |   Y  |   U  |   I  |   O  |   P  |  [   |  ]   |
   * |------+------+------+------+------+------+------+--------------------+------+------+------+------+------+------+------|
   * |Enter |   A  |   S  |   D  |   F  |   G  | ESC  |                    |   H  |   J  |   K  |   L  |   ;  |  "   | Shift|
   * |------+------+------+------+------+------+---------------------------+------+------+------+------+------+------+------|
   * | Bksp | Shift|   Z  |   X  |   C  |   V  |   B  |                    |   N  |   M  |   ,  |   .  |   /  |  Up  | Shift|
   * |-------------+------+------+------+------+------+------+------+------+------+------+------+------+------+------+------|
   * | Tab  |  GUI |  ALt |  ALt |||||||| Shift| Ctrl |  Space |||||||| Space |Shift| ALt ||||||||Ctrl | Left | Down | Right|
   * ,----------------------------------------------------------------------------------------------------------------------.
   */
  [_QWERTY] = LAYOUT(	\
    KC_ESC,  KC_1,     KC_2,    KC_3,   KC_4,    KC_5,   KC_6,     										KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_BSLS, KC_EQL k  \
    KC_TAB,  KC_Q,     KC_W     KC_E,   KC_R,    KC_T,   K_GRV,                       KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC,  \
    KC_ENT,  KC_A,     KC_S,    KC_D,   KC_F,    KC_G,   KC_ESC,                       KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, KC_LSFT,  \
    KC_BSPC, KC_LSFT,  KC_Z,    KC_X,   KC_C,    KC_V,   KC_B,                         KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_UP,   KC_LSFT,   \
    KC_TAB,  KC_LGUI,  KC_LCTL,     KC_LALT,     KC_LSFT,  KC_LCTL, KC_SPC,        KC_SPC, KC_LSFT, KC_LALT,    KC_LCTL,     KC_LEFT, KC_DOWN,  KC_RGHT  \
  ),
};


// no need
//#ifdef AUDIO_ENABLE
//float tone_qwerty[][2]     = SONG(QWERTY_SOUND);
//#endif
//

void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {  switch (keycode) {

    case QWERTY:
      if (record->event.pressed) {
         print("mode just switched to qwerty and this is a huge string\n");
        set_single_persistent_default_layer(_QWERTY);
      }
      return false;
      break;

    //case LOWER:
    //  if (record->event.pressed) {
    //    layer_on(_LOWER);
    //    update_tri_layer(_LOWER, _RAISE, _ADJUST);
    //  } else {
    //    layer_off(_LOWER);
    //    update_tri_layer(_LOWER, _RAISE, _ADJUST);
    //  }
    //  return false;
    //  break;

    //case RAISE:
    //  if (record->event.pressed) {
    //    layer_on(_RAISE);
    //    update_tri_layer(_LOWER, _RAISE, _ADJUST);
    //  } else {
    //    layer_off(_RAISE);
    //    update_tri_layer(_LOWER, _RAISE, _ADJUST);
    //  }
    //  return false;
    //  break;

    //case ADJUST:
    //  if (record->event.pressed) {
    //    layer_on(_ADJUST);
    //  } else {
    //    layer_off(_ADJUST);
    //  }
    //  return false;
    //  break;
  }
  return true;
}
