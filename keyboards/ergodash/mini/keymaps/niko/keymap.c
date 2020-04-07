#include QMK_KEYBOARD_H

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


// Mappings

#define LPARAN RSFT(KC_8) // (
#define RPARAN RSFT(KC_9) // )

#define LCBRACK RALT(KC_7) // {
#define RCBRACK RALT(KC_0) // }

#define LHBRACK RALT(KC_8) // [
#define RHBRACK RALT(KC_9) // ]

#define LCROCO KC_NUBS // <
#define RCROCO LSFT(KC_NUBS) // > 

#define EQ RSFT(KC_0) // =
#define QMRK RSFT(KC_MINS) // =


#define _QWERTY 0
#define _LOWER 1
#define _RAISE 2
#define _SUPER 3
#define _ADJUST 16

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  LOWER,
  RAISE,
  ADJUST,
};

#define EISU LALT(KC_GRV)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  /* Qwerty
   * ,----------------------------------------------------------------------------------------------------------------------.
   * |  Esc |   Q  |   W  |   E  |   R  |   T  |   -  |                    |   =  |   Y  |   U  |   I  |   O  |   P  |  \   |
   * |------+------+------+------+------+------+------+--------------------+------+------+------+------+------+------+------|
   * | Tab  |   A  |   S  |   D  |   F  |   G  |   [  |                    |   ]  |   H  |   J  |   K  |   L  |   ;  |  "   |
   * |------+------+------+------+------+------+---------------------------+------+------+------+------+------+------+------|
   * | Shift|   Z  |   X  |   C  |   V  |   B  | Space|                    | Enter|   N  |   M  |   ,  |   .  |   /  | Shift|
   * |-------------+------+------+------+------+------+------+------+------+------+------+------+------+------+-------------|
   * | Ctrl |  GUI |  ALt | EISU |||||||| Lower| Space|Delete|||||||| Bksp | Enter| Raise|||||||| Left | Down |  Up  | Right|
   * ,----------------------------------------------------------------------------------------------------------------------.
   */
  [_QWERTY] = LAYOUT(
    KC_ESC,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,       KC_RBRC,                    KC_EQL,     KC_Y,      KC_U,    KC_I,     KC_O,    KC_P,     KC_BSPC, \
    KC_TAB,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,       KC_NUBS,                    KC_BSLS,    KC_H,      KC_J,    KC_K,     KC_L,    KC_SCLN,  KC_ENT,  \
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,       KC_NO,                      KC_NO,      KC_N,      KC_M,    KC_COMM,  KC_DOT,  KC_SLSH,  KC_RSFT, \
    KC_LCTL, KC_LCTL, KC_LGUI, KC_LALT, KC_SPACE, MO(_LOWER) , KC_NO,                      KC_NO,    MO(_RAISE),KC_SPACE, KC_RALT,  KC_NO,   KC_RCTL,  KC_RCTL    \
  ),

  /* Lower
   * ,----------------------------------------------------------------------------------------------------------------------.
   * |   `  |   !  |   @  |   #  |   $  |   %  |   _  |                    |   +  |   ^  |   &  |   *  |   (  |   )  |  |   |
   * |------+------+------+------+------+------+------+--------------------+------+------+------+------+------+-----+------|
   * |   ~  |   1  |   2  |   3  |   4  |   5  |   {  |                    |   }  | Left | Down |  Up  | Right|   :  |  "   |
   * |------+------+------+------+------+------+---------------------------+------+------+------+------+------+------+------|
   * | Shift|   6  |   7  |   8  |   9  |   0  | Space|                    | Enter|   N  |   M  |   <  |   >  |   ?  | Shift|
   * |-------------+------+------+------+------+------+------+------+------+------+------+------+------+------+-------------|
   * | Ctrl |  GUI |  ALt | EISU |||||||| Lower| Space|Delete|||||||| Bksp | Enter| Raise|||||||| Home |PageDn|PageUp|  End |
   * ,----------------------------------------------------------------------------------------------------------------------.
   */
  [_LOWER] = LAYOUT(
    KC_NO, SFT_1,   SFT_2,   SFT_3,   SFT_4,   SFT_5,   KC_NO,                          QMRK,    SFT_6,   SFT_7,    SFT_8,    SFT_9,    SFT_0,   KC_DEL,   \
    MO(_SUPER), KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_NO,                     KC_NO,    LCBRACK, LPARAN,   RPARAN,   RCBRACK,  KC_NO,   KC_NO,    \
    KC_NO, KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_NO,                          KC_NO,    LCROCO,  LHBRACK,  RHBRACK,  RCROCO,   KC_NO,   KC_NO,    \
    KC_NO, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                          KC_NO,    KC_NO,   KC_NO,    KC_NO,    KC_NO,    KC_NO,   KC_NO     \
  ),

  /* Raise
  * ,----------------------------------------------------------------------------------------------------------------------.
  * |   `  |   !  |   @  |   #  |   $  |   %  |   _  |                    |   +  |   ^  |   &  |   *  |   (  |   )  |  |   |
  * |------+------+------+------+------+------+------+--------------------+------+------+------+------+------+------+------|
  * |   ~  |   F1 |   F2 |   F3 |   F4 |   F5 |   {  |                    |   }  | Left | Down |  Up  | Right|   :  |  "   |
  * |------+------+------+------+------+------+---------------------------+------+------+------+------+------+------+------|
  * | Shift|   F6 |   F7 |   F8 |   F9 |  F10 | Space|                    | Enter|   N  |   M  |   <  |   >  |   ?  | Shift|
  * |-------------+------+------+------+------+------+------+------+------+------+------+------+------+------+-------------|
  * | Ctrl |  F11 |  F12 | EISU |||||||| Lower| Space|Delete|||||||| Bksp | Enter| Raise|||||||| Home |PageDn|PageUp|  End |
  * ,----------------------------------------------------------------------------------------------------------------------.
  */
  [_RAISE] = LAYOUT(
    KC_NO, ALT_1,   ALT_2,    ALT_3,   ALT_4,   ALT_5,    KC_BSLS,                        KC_NO,    ALT_6,   ALT_7,    ALT_8,    ALT_9,   ALT_0,   KC_NO,    \
    KC_NO, KC_F1,   KC_F2,    KC_F3,   KC_F4,   KC_F5,    KC_NO,                          KC_NO,    KC_LEFT, KC_DOWN,  KC_UP,   KC_RIGHT, KC_NO,   KC_NO,    \
    KC_NO, KC_F6,   KC_F7,    KC_F8,   KC_F9,   KC_F10,   KC_NO,                          KC_NO,    KC_HOME, KC_PGDN,  KC_PGUP, KC_END,   KC_NO,   KC_NO,    \
    KC_NO, KC_F11,  KC_F12,   KC_NO,   KC_NO,   KC_NO,    KC_NO,                          KC_NO,    KC_NO,   KC_NO,    KC_NO,   KC_NO,    KC_NO,   RESET     \
  ),

  [_SUPER] = LAYOUT(
    KC_NO, ALT_1,   ALT_2,    ALT_3,   ALT_4,   ALT_5,    KC_BSLS,                        KC_NO,    ALT_6,   KC_NO,    KC_UP,    ALT_9,   ALT_0,   KC_NO,    \
    KC_NO, KC_F1,   KC_F2,    KC_F3,   KC_F4,   KC_F5,    KC_NO,                          KC_NO,    KC_NO,   KC_LEFT,  KC_DOWN,  KC_RIGHT,   KC_RIGHT, KC_NO,\
    KC_NO, KC_F6,   KC_F7,    KC_F8,   KC_F9,   KC_F10,   KC_NO,                          KC_NO,    KC_HOME, KC_PGDN,  KC_PGUP, KC_END,   KC_NO,   KC_NO,    \
    KC_NO, KC_F11,  KC_F12,   KC_NO,   KC_NO,   KC_NO,    KC_NO,                          KC_NO,    KC_NO,   KC_NO,    KC_NO,   KC_NO,    KC_NO,   RESET     \
  ),

  /* Adjust
   * ,----------------------------------------------------------------------------------------------------------------------.
   * |      | Reset|RGB ON|  MODE|  HUE-|  HUE+|      |                    |      |  SAT-|  SAT+|  VAL-|  VAL+|      |      |
   * |------+------+------+------+------+------+---------------------------+------+------+------+------+------+------+------|
   * |      |      |      |      |      |      |      |                    |      |      |      |      |      |      |      |
   * |------+------+------+------+------+------+---------------------------+------+------+------+------+------+------+------|
   * |      |      |      |      |      |      |      |                    |      |      |      |      |      |      |      |
   * |-------------+------+------+------+------+------+------+------+------+------+------+------+------+------+-------------|
   * |      |      |      |      ||||||||      |      |      ||||||||      |      |      ||||||||      |      |      |      |
   * ,----------------------------------------------------------------------------------------------------------------------.
   */
  [_ADJUST] = LAYOUT(
    _______, RESET  , RGB_TOG, RGB_MOD, RGB_HUD, RGB_HUI,_______,                       _______, RGB_SAD, RGB_SAI, RGB_VAD, RGB_VAI, _______, _______, \
    _______, _______, BL_TOGG, BL_BRTG, BL_INC , BL_DEC ,_______,                       _______, _______, _______, _______, _______, _______, _______, \
    _______, _______, _______, _______, _______, _______,_______,                       _______, _______, _______, _______, _______, _______, _______, \
    _______, _______, _______, _______,          _______,_______,_______,       _______,_______, _______,          _______, _______, _______, _______  \
  )
};

