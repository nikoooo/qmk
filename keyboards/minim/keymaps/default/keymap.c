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


#define SFT_1 RSFT(KC_1)
#define SFT_2 RSFT(KC_2)
#define SFT_3 RSFT(KC_3)
#define SFT_4 RSFT(KC_4)
#define SFT_5 RSFT(KC_5)
#define SFT_6 RSFT(KC_6)
#define SFT_7 RSFT(KC_7)
#define SFT_8 RSFT(KC_8)
#define SFT_9 RSFT(KC_9)
#define SFT_0 RSFT(KC_0)

#define ALT_1 RALT(KC_1)
#define ALT_2 RALT(KC_2)
#define ALT_3 RALT(KC_3)
#define ALT_4 RALT(KC_4)
#define ALT_5 RALT(KC_5)
#define ALT_6 RALT(KC_6)
#define ALT_7 RALT(KC_7)
#define ALT_8 RALT(KC_8)
#define ALT_9 RALT(KC_9)
#define ALT_0 RALT(KC_0)


enum layer_names {
  _QWERTY = 0,
  _LOWER = 3,
  _RAISE = 4,
  _ADJUST = 16,
};

// Defines the keycodes used by our macros in process_record_user
enum custom_keycodes {
  QMKBEST = SAFE_RANGE,
  LOWER,
  RAISE,
  ADJUST,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  LAYOUT(
    KC_ESC,  KC_Q,     KC_W,    KC_E,    KC_R,  KC_T,    KC_Y,   KC_U,  KC_I,    KC_O,    KC_P,    KC_LBRC, KC_BSPC, \
             KC_TAB,   KC_A,    KC_S,    KC_D,  KC_F,    KC_G,   KC_H,  KC_J,    KC_K,    KC_L,    KC_SCLN, KC_ENT, \
             KC_LSFT,  KC_Z,    KC_X,    KC_C,  KC_V,    KC_B,   KC_N,  KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,  \
             KC_LCTRL, KC_LGUI, KC_LALT, MO(1), MO(2),  KC_SPC,  MO(5), KC_RALT,  MO(4),  MO(3)                     \
  ),
  // MO(1)
  LAYOUT(
    KC_GRAVE,    KC_1,    KC_2,     KC_3,   KC_4,    KC_5,    KC_6,    KC_7,     KC_8,    KC_9,    KC_0, KC_MINS,  KC_DEL, \
              MO(4), _______, _______,      EQ,  RCROCO, _______, LCBRACK,   LPARAN,  RPARAN, RCBRACK, _______, KC_BSLS, \
              _______, _______, _______, _______, _______, _______,  LCROCO,  LHBRACK, RHBRACK,  RCROCO, _______, KC_RSFT, \
              _______, _______, _______, _______, _______, _______, _______,  KC_RALT, _______, _______                    \
  ),
  // MO(2)
  LAYOUT(
    KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN,  _______, KC_DEL,  \
             _______, _______, _______, _______, _______, _______, KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT, _______, KC_PIPE, \
             _______, _______, _______, _______, _______, _______, KC_HOME, KC_PGDN, KC_PGUP, KC_END,   _______, _______, \
             _______, _______, _______, _______, _______, _______, _______, _______, _______, _______                     \
  ),
  // MO(3)
  LAYOUT(
    _______, KC_MPRV, KC_MPLY, KC_MNXT, _______, _______, _______, _______, _______, _______, _______, _______, RESET,   \
             _______, KC_MUTE, KC_VOLD, KC_VOLU, _______, _______, _______, _______, _______, _______, _______, _______, \
             _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
             _______, _______, _______, _______, _______, _______, _______, _______, _______, _______                    \
  ),
  // MO(4)
  LAYOUT(
    KC_NO,    KC_F1,    KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10,  KC_F11,  KC_F12, \
             _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
             _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
             _______, _______, _______, _______, _______, _______, _______, _______, _______, _______                    \
  ),
  // MO(5)
  LAYOUT(
    KC_NO,    ALT_1,    ALT_2,   ALT_3,   ALT_4,   ALT_5,   ALT_6,   ALT_7,   ALT_8,   ALT_9,   ALT_0,      EQ,  KC_NO, \
             _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
             _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
             _______, _______, _______, _______, _______, _______, _______, _______, _______, _______                    \
  ),
};

void matrix_init_user(void) {

}

void matrix_scan_user(void) {

}

void led_set_user(uint8_t usb_led) {

}
