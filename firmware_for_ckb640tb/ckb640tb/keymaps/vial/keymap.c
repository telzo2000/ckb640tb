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

// 1. スクロールの感度設定（お好みで調整）
#define SCROLL_DIVIDER 1 


report_mouse_t pointing_device_task_user(report_mouse_t mouse_report) {
    // 2. 「LAYER_1」が有効なときだけ実行（レイヤー名は適宜書き換えてください）
    if (IS_LAYER_ON(1)) {
        // ボールの動き(x, y)をスクロール(h, v)に変換
        // SCROLL_DIVIDER で割ることで、速すぎて制御不能になるのを防ぎます
        mouse_report.h = mouse_report.x*2/3 / SCROLL_DIVIDER;
        mouse_report.v = mouse_report.y*2/3 / SCROLL_DIVIDER;
        
        // 本来のマウスカーソルの動きは止める
        mouse_report.x = 0;
        mouse_report.y = 0;
    }
    return mouse_report;
}

enum custom_keycodes {
    CPI_SW = SAFE_RANGE, // または QK_USER_0
};


// CPIのリスト（例：400から1200まで200刻み）
static uint16_t cpi_list[] = {400, 600, 800, 1000, 1200};
static uint8_t cpi_index = 2; // デフォルトは800

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case CPI_SW:
            if (record->event.pressed) {
                // インデックスを回してCPIを設定
                cpi_index = (cpi_index + 1) % (sizeof(cpi_list) / sizeof(cpi_list[0]));
                pointing_device_set_cpi(cpi_list[cpi_index]);
            }
            return false;
    }
    return true;
}
