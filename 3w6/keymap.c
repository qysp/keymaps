/*
Copyright 2021 weteor

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include QMK_KEYBOARD_H
#include "pimoroni_trackball.h"

enum layers
{
    _ALPHA_QWERTY = 0,
    _SYM,
    _NAV,
    _NUM,
    _WM,
    _MISC,
};

enum custom_keycodes
{
    BALL_SCR = SAFE_RANGE,
    COPY,
    PASTE,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_ALPHA_QWERTY] = LAYOUT(
        KC_Q,         KC_W,    KC_E,    KC_R,    KC_T,                                                   KC_Y,     KC_U,      KC_I,       KC_O,       KC_P,
        KC_A,         KC_S,    KC_D,    KC_F,    KC_G,                                                   KC_H,     KC_J,      KC_K,       KC_L,       KC_SCLN,
        LSFT_T(KC_Z), KC_X,    KC_C,    KC_V,    KC_B,                                                   KC_N,     KC_M,      KC_COMM,    KC_DOT,     RSFT_T(KC_SLSH),
                       LCTL_T(KC_LGUI), LT(_NAV, KC_TAB), LT(_NUM, KC_SPC),            LALT_T(KC_ENTER), LT(_SYM, KC_BSPC), XXXXXXX
    ),
    [_SYM] = LAYOUT(
        KC_EXLM,      KC_AT,   KC_HASH, KC_DLR,  KC_PERC,                                                KC_CIRC,  KC_AMPR,   KC_ASTR,    XXXXXXX,    KC_GRV,
        KC_SLSH,      KC_LBRC, KC_LCBR, KC_LPRN, KC_EQL,                                                 KC_MINS,  KC_RPRN,   KC_RCBR,    KC_RBRC,    KC_QUOT,
        _______,      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                                                XXXXXXX,  XXXXXXX,   XXXXXXX,    XXXXXXX,    RSFT_T(KC_BSLS),
                                       KC_ESC, LM(_WM, MOD_LGUI), OSM(MOD_RALT),                    XXXXXXX, XXXXXXX, XXXXXXX
    ),
    [_NAV] = LAYOUT(
        XXXXXXX,      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                                                XXXXXXX,  KC_HOME,   KC_END,     KC_PGDN,    KC_PGUP,
        BALL_SCR,     XXXXXXX, XXXXXXX, KC_LCTL, KC_LALT,                                                KC_LEFT,  KC_DOWN,   KC_UP,      KC_RGHT,    KC_DEL,
        KC_LSFT,      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                                                XXXXXXX,  COPY,      PASTE,      XXXXXXX,    XXXXXXX,
                                        XXXXXXX, XXXXXXX, XXXXXXX,                              KC_LALT, MO(_MISC), XXXXXXX
    ),
    [_NUM] = LAYOUT(
        KC_NUM,       KC_F9,   KC_F10,  KC_F11,  KC_F12,                                                 KC_PPLS, KC_P7,      KC_P8,      KC_P9,      KC_PSLS,
        XXXXXXX,      KC_F5,   KC_F6,   KC_F7,   KC_F8,                                                  KC_P0,   KC_P4,      KC_P5,      KC_P6,      KC_PDOT,
        XXXXXXX,      KC_F1,   KC_F2,   KC_F3,   KC_F4,                                                  KC_PMNS, KC_P1,      KC_P2,      KC_P3,      KC_PAST,
                                        XXXXXXX, XXXXXXX, XXXXXXX,                              KC_PEQL, KC_PENT, XXXXXXX
    ),
    [_WM] = LAYOUT(
        KC_Q,         RGUI(KC_7), RGUI(KC_8), RGUI(KC_9), KC_T,                                          KC_Y,    KC_U,       KC_I,       KC_O,       KC_P,
        KC_A,         RGUI(KC_4), RGUI(KC_5), RGUI(KC_6), KC_ENTER,                                      KC_H,    KC_J,       KC_K,       KC_L,       XXXXXXX,
        KC_LSFT,      RGUI(KC_1), RGUI(KC_2), RGUI(KC_3), KC_B,                                          KC_N,    KC_M,       XXXXXXX,    XXXXXXX,    KC_RSFT,
                                        XXXXXXX, XXXXXXX, XXXXXXX,                              XXXXXXX, XXXXXXX, XXXXXXX
    ),
    [_MISC] = LAYOUT(
        XXXXXXX,      KC_VOLD, KC_MUTE, KC_VOLU, XXXXXXX,                                                XXXXXXX, XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,
        KC_MPRV,      KC_MPLY, KC_MSTP, KC_MNXT, XXXXXXX,                                                XXXXXXX, KC_BTN1,    KC_BTN2,    XXXXXXX,    XXXXXXX,
        XXXXXXX,      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                                                XXXXXXX, XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,
                                        XXXXXXX, XXXXXXX, XXXXXXX,                              XXXXXXX, XXXXXXX, XXXXXXX
    ),
};


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
    case BALL_SCR:
        if(record->event.pressed)
            trackball_set_scrolling(true);
        else
            trackball_set_scrolling(false);
        break;
    case COPY:
        if (record->event.pressed)
            SEND_STRING(SS_LCTL("c"));
        break;
    case PASTE:
        if (record->event.pressed)
            SEND_STRING(SS_LCTL("v"));
        break;
    }

    return true;
}
