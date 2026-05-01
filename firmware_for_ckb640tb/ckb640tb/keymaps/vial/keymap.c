// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] ={
    [0] = LAYOUT_ortho_5x10(
        KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                                    KC_Y,    KC_U,    KC_I,        KC_O,    KC_P,
        KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                                    KC_H,    KC_J,    KC_K,        KC_L,    KC_ENT,
        KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_2,         KC_1,                  KC_N,    KC_M,    KC_COMM,     KC_DOT,  KC_SLASH,
        KC_LSFT, KC_TAB,  KC_LCTL,KC_LGUI, KC_LALT,  LT(1,KC_SPACE),                 LT(2,KC_SPACE), KC_BACKSPACE,KC_RSFT
    ),
        [1] = LAYOUT_ortho_5x10(
        KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                                    KC_6,    KC_7,    KC_8,        KC_9,    KC_0,
        KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                                    KC_H,    KC_J,    KC_K,        KC_L,    KC_ENT,
        KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_2,         KC_1,                  KC_N,    KC_M,    KC_COMM,     KC_DOT,  KC_SLASH,
        KC_LSFT, KC_TAB,  KC_LCTL,KC_LGUI, KC_LALT,  KC_NO,                          LT(2,KC_SPACE), KC_BACKSPACE,KC_RSFT
    ),
        [2] = LAYOUT_ortho_5x10(
        KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                                    KC_Y,    KC_U,    KC_I,        KC_O,    KC_P,
        KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                                    KC_H,    KC_J,    KC_K,        KC_L,    KC_ENT,
        KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_2,         KC_1,                  KC_N,    KC_M,    KC_COMM,     KC_DOT,  KC_SLASH,
        KC_LSFT, KC_TAB,  KC_LCTL,KC_LGUI, KC_LALT,  LT(1,KC_SPACE),                 KC_NO, KC_BACKSPACE,KC_RSFT
    ),
        [3] = LAYOUT_ortho_5x10(
        KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                                    KC_Y,    KC_U,    KC_I,        KC_O,    KC_P,
        KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                                    KC_H,    KC_J,    KC_K,        KC_L,    KC_ENT,
        KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_2,         KC_1,                  KC_N,    KC_M,    KC_COMM,     KC_DOT,  KC_SLASH,
        KC_LSFT, KC_TAB,  KC_LCTL,KC_LGUI, KC_LALT,  LT(1,KC_SPACE),                 LT(2,KC_SPACE), KC_BACKSPACE,KC_RSFT
    )
};


#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][2] = {
    [0] = { ENCODER_CCW_CW(KC_WH_D, KC_WH_U)},
    [1] = { ENCODER_CCW_CW(KC_WH_L, KC_WH_R)},
    [2] = { ENCODER_CCW_CW(KC_KB_VOLUME_DOWN, KC_KB_VOLUME_UP)},
    [3] = { ENCODER_CCW_CW(KC_C, KC_D)},
};
#endif
