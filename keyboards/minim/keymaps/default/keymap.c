/* Copyright 2019 Robin
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

#define LPARAN RSFT(KC_8) // (
#define RPARAN RSFT(KC_9) // )

#define LCBRACK RALT(KC_7) // {
#define RCBRACK RALT(KC_0) // }

#define LHBRACK RALT(KC_8) // [
#define RHBRACK RALT(KC_9) // ]

#define LCROCO KC_NUBS // <
#define RCROCO LSFT(KC_NUBS) // > 

#define EQ RSFT(KC_0) // =


enum layer_names {
  _QWERTY = 0,
  _LOWER = 3,
  _RAISE = 4,
  _ADJUST = 16,
  _FUNCTION = 40,
};

// Defines the keycodes used by our macros in process_record_user
enum custom_keycodes {
  QMKBEST = SAFE_RANGE,
  LOWER,
  RAISE,
  ADJUST,
  FUNCTION
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QWERTY] = LAYOUT(
    KC_ESC,  KC_Q,     KC_W,    KC_E,    KC_R,  KC_T,    KC_Y,   KC_U,  KC_I,    KC_O,    KC_P,    KC_LBRC, KC_BSPC, \
             KC_TAB,   KC_A,    KC_S,    KC_D,  KC_F,    KC_G,   KC_H,  KC_J,    KC_K,    KC_L,    KC_SCLN, KC_ENT, \
             KC_LSFT,  KC_Z,    KC_X,    KC_C,  KC_V,    KC_B,   KC_N,  KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,  \
             KC_LCTRL, FUNCTION,    KC_LGUI, KC_LALT, LOWER, KC_SPC, RAISE, KC_RALT, KC_0,    ADJUST                     \
  ),
  [_LOWER] = LAYOUT(
    KC_GRAVE, _______, _______, _______, _______, _______, _______, _______,    EQ,    RCROCO, _______, _______, _______, \
              _______, _______, _______, _______, _______, _______, LCBRACK,  LPARAN,  RPARAN, RCBRACK, _______, _______, \
              _______, _______, _______, _______, _______, _______, LCROCO,  LHBRACK, RHBRACK,  RCROCO, _______, _______, \
              _______, _______, _______, _______, _______, _______, _______, _______, _______, _______                    \
  ),
  [_RAISE] = LAYOUT(
    KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN,  _______, KC_DEL,  \
             _______, _______, _______, _______, _______, _______, KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT, _______, KC_PIPE, \
             _______, _______, _______, _______, _______, _______, KC_HOME, KC_PGDN, KC_PGUP, KC_END,   _______, _______, \
             _______, _______, _______, _______, _______, _______, _______, _______, _______, _______                     \
  ),
  [_ADJUST] = LAYOUT(
    _______, KC_MPRV, KC_MPLY, KC_MNXT, _______, _______, _______, _______, _______, _______, _______, _______, RESET,   \
             _______, KC_MUTE, KC_VOLD, KC_VOLU, _______, _______, _______, _______, _______, _______, _______, _______, \
             _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
             _______, _______, _______, _______, _______, _______, _______, _______, _______, _______                    \
  ),
  [_FUNCTION] = LAYOUT(
    KC_0, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
             _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
             _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
             _______, _______, _______, _______, _______, _______, _______, _______, _______, _______                    \
  ),
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case LOWER:
      if (record->event.pressed) {
        layer_on(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case RAISE:
      if (record->event.pressed) {
        layer_on(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case ADJUST:
      if (record->event.pressed) {
        layer_on(_ADJUST);
      } else {
        layer_off(_ADJUST);
      }
      return false;
      break;
    case FUNCTION:
      if (record->event.pressed) {
        layer_on(_FUNCTION);
      } else {
        layer_off(_FUNCTION);
      }
      return false;
      break;
  }
  return true;
}

void matrix_init_user(void) {

}

void matrix_scan_user(void) {

}

void led_set_user(uint8_t usb_led) {

}
