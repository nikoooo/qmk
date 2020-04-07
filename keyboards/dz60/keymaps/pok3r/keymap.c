#include QMK_KEYBOARD_H

// const uint16_t PROGMEM layer3_combo[] = {MO(1), KC_LALT, COMBO_END};
// combo_t key_combos[COMBO_COUNT] = {COMBO(layer3_combo, MO(3))};
//
#define LPARAN RSFT(KC_8) // (
#define RPARAN RSFT(KC_9) // )

#define LCBRACK RALT(KC_7) // {
#define RCBRACK RALT(KC_0) // }

#define LHBRACK RALT(KC_8) // [
#define RHBRACK RALT(KC_9) // ]

#define LCROCO KC_NUBS // <
#define RCROCO LSFT(KC_NUBS) // > 

#define EQ RSFT(KC_0) // =

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

	LAYOUT(
		KC_GESC, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINS, KC_EQL, KC_NO, KC_BSPC,
		KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_LBRC, KC_RBRC, KC_BSLS,
		MO(1), KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT, KC_ENT,
		KC_LSFT, KC_NO, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_RSFT, KC_NO,
		KC_LCTL, KC_LGUI, KC_LALT, KC_SPC, KC_SPC, KC_SPC, KC_RALT, MO(1), KC_NO, MO(2), KC_RCTL),

	LAYOUT(
		KC_GRV, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, _______, KC_DEL,
		_______, KC_MPRV, KC_MPLY, KC_MNXT, RESET, _______, KC_CALC, KC_PGUP, KC_UP, KC_PGDN, KC_PSCR, KC_SLCK, KC_PAUS, _______,
		_______, _______, KC_VOLD, KC_VOLU, KC_MUTE, _______, KC_HOME, KC_LEFT, KC_DOWN, KC_RGHT, KC_INS, KC_DEL, KC_NUBS,
		_______, KC_APP, _______, _______, KC_CAPS, _______, KC_END, _______, _______, _______, _______, _______, _______, _______,
		_______, _______, MO(3), _______, _______, _______, _______, _______, _______, _______, _______),

	LAYOUT(
		RGB_TOG, RGB_M_P, RGB_M_B, RGB_M_R, RGB_M_SW, RGB_M_SN, RGB_M_K, RGB_M_X, RGB_M_G, RGB_M_T, _______, RGB_RMOD, RGB_MOD, _______, _______,
		_______, RGB_HUI, RGB_SAI, RGB_VAI, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
		_______, RGB_HUD, RGB_SAD, RGB_VAD, _______, _______, _______, _______, _______, _______, _______, _______, _______,
		_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
		_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______),

	LAYOUT(
	        _______, _______, _______, _______, _______, _______, _______, EQ, RCROCO, _______, _______, _______, _______, _______, _______,
		_______, _______, _______, _______, _______, _______, LCBRACK, LPARAN, RPARAN, RCBRACK, _______, _______, _______, _______,
		_______, _______, _______, _______, _______, _______, LCROCO, LHBRACK, RHBRACK, RCROCO, _______, _______, _______,
		_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
		_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______),
};
