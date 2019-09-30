/*
Base Copyright 2017 Luiz Ribeiro <luizribeiro@gmail.com>
Modified 2017 Andrew Novak <ndrw.nvk@gmail.com>
Modified 2018 Wayne Jones (WarmCatUK) <waynekjones@gmail.com>
This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.
This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.
You should have received a copy of the GNU General Public LicensezZZ
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include QMK_KEYBOARD_H

#define ______ KC_TRNS
#define _DEFLT 0
#define _NAV 1
#define _SYMNUM 2
#define _FN 3
#define _TRANS 4

enum custom_keycodes {
    P_MACRO = SAFE_RANGE,
    VS_CODE,
    CHROME,
    SLACK,
    SPOTIFY,
};

// GBP £ Macro (sends alt 156 - windows users only)
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
        switch(keycode) {
            case P_MACRO:
                SEND_STRING(SS_DOWN(X_LALT));
                SEND_STRING(SS_TAP(X_KP_1));
                SEND_STRING(SS_TAP(X_KP_5));
                SEND_STRING(SS_TAP(X_KP_6));
                SEND_STRING(SS_UP(X_LALT));
                return false; break;
            case VS_CODE:
                if (record->event.pressed) {
                    SEND_STRING(SS_LGUI(" "));
                    _delay_ms(70);
                    SEND_STRING("code");
                    _delay_ms(20);
                    SEND_STRING(SS_TAP(X_ENTER));
                    // _delay_ms(10);
                }
                return false;
                break;
            case CHROME:
                if (record->event.pressed) {
                    SEND_STRING(SS_LGUI(" "));
                    _delay_ms(70);
                    SEND_STRING("chrome");
                    _delay_ms(20);
                    SEND_STRING(SS_TAP(X_ENTER));
                    // _delay_ms(10);
                }
                return false;
                break;
            case SLACK:
                if (record->event.pressed) {
                    SEND_STRING(SS_LGUI(" "));
                    _delay_ms(70);
                    SEND_STRING("slack");
                    _delay_ms(20);
                    SEND_STRING(SS_TAP(X_ENTER));
                    // _delay_ms(10);
                }
                return false;
                break;
            case SPOTIFY:
                if (record->event.pressed) {
                    SEND_STRING(SS_LGUI(" "));
                    _delay_ms(70);
                    SEND_STRING("spotify");
                    _delay_ms(20);
                    SEND_STRING(SS_TAP(X_ENTER));
                    // _delay_ms(10);
                }
                return false;
                break;
        }
    }
    return true;
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    /* Qwerty
     * ,-----------------------------------------------------------------------------------.
     * | Lock |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  |      |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | Esc  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  "   |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |Enter | (Hold for shift / tap for enter)
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |  Fn  | Ctrl |      | Alt  | GUI  | Nav  |Space | GUI  | Alt  | Caps | Ctrl |      |
     * `-----------------------------------------------------------------------------------'
     */
    [_DEFLT] = LAYOUT( \
        LCTL(LGUI(KC_Q)), KC_1,    KC_2,    KC_3, KC_4, KC_5,    KC_6,    KC_7,    KC_8,    KC_9, KC_0, _______,       \
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,      \
        KC_ESC,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,      \
        KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, RSFT_T(KC_ENT),\
        MO(_FN), KC_LCTL, MO(_NAV), KC_LALT, KC_LGUI, MO(_SYMNUM), LT(_SYMNUM,KC_SPC), KC_RGUI,KC_RALT,KC_CAPS, KC_RCTL,_______  \
    ),

    /* Transition Layer
     * ,-----------------------------------------------------------------------------------.
     * |      |      |      |      |      |      |      |      |      |      |      |      |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |      |      |      |      |      |      |      |      |      |      |      |      |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |      |      |      |      |      |      |      |      |      |      |      |      |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |      |      |      |      |      |      |      |      |      |      |      |      |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |      |      |      |      |SYMNUM|      |      |SYMNUM|      |      |      |      |
     * `-----------------------------------------------------------------------------------'
     */
    [_TRANS] = LAYOUT( \
       _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
       _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
       _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
       _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
       _______, _______, _______, _______, MO(_SYMNUM),_______,_______,MO(_SYMNUM), _______, _______, _______, _______    \
    ),

    /* Navigation
     * ,-----------------------------------------------------------------------------------.
     * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |      |      |      |SPOTIF|SLACK |      |      | Prev | Next | Alt<-| Alt->|      |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |      |VSCODE|CHROME| Prev | Next |      | Left | Down |  Up  |Right |      |      |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |      |      |      |      |      |      | Home | PDN  |  PUP |  End |      |      |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |      |      |      |      |      |Lower |Lower |      | Next | Vol- | Vol+ | Play |
     * `-----------------------------------------------------------------------------------'
     */

    [_NAV] = LAYOUT( \
       KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  \
       _______, _______, _______, SPOTIFY, SLACK  , _______, _______, LGUI(KC_LCBR), LGUI(KC_RCBR), LALT(KC_LEFT), LALT(KC_RIGHT), _______, \
       _______, VS_CODE, CHROME , LGUI(KC_LCBR), LGUI(KC_RCBR), _______,  KC_LEFT, KC_DOWN, KC_UP,  KC_RIGHT, _______, _______,  \
       _______, _______, _______, _______, _______, _______,  KC_HOME, KC_PGDN, KC_PGUP, KC_END, _______, _______,  \
       _______, _______, _______, _______, _______, _______, _______, _______, KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY  \
    ),

    /* Lower
     * ,-----------------------------------------------------------------------------------.
     * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  |      |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |      |   ~  |      |      |      |      |   &  |   _  |   (  |   )  |   -  |  \   |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |      |   `  |   {  |   }  |      |      |   :  |   +  |   [  |   ]  |   =  |      |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |      |      |      |      |      |             |      | Next | Vol- | Vol+ | Play |
     * `-----------------------------------------------------------------------------------'
     */

    [_SYMNUM] = LAYOUT( \
        KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,    \
        KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    ______,  \
        _______, KC_TILD, _______, _______, _______, _______, KC_AMPR, KC_UNDS, KC_LPRN, KC_RPRN, KC_MINS, KC_BSLS,     \
        _______, KC_GRV, KC_LCBR, KC_RCBR, _______, _______, KC_COLN, KC_PPLS, KC_LBRC, KC_RBRC, KC_EQL, _______, \
        _______, _______, _______, _______, _______, _______, _______, _______, KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY    \
    ),

    /* Fn
     * ,-----------------------------------------------------------------------------------.
     * |      |      |  £   |      |      |      |      |      |      |      |      |      |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |      |      |      |      |      |      |      |      |      |      |      |      |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |      |      |      |      |      |      |      |      |      |      |      |      |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |      |      |      |      |      |      |      |      |      |      |      |      |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |      |      |      |      |      |      |      |      |BL_OFF|BL_DEC|BL_INC|BL_ON |
     * `-----------------------------------------------------------------------------------'
     */
    [_FN] = LAYOUT( \
       _______, _______, P_MACRO, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
       _______, _______, _______, _______, _______, _______, _______, _______, _______, RGB_MOD, _______, _______, \
       _______, _______, _______, _______, _______, _______, _______, _______, RGB_HUI, RGB_SAI, RGB_VAI, _______, \
       _______, _______, _______, _______, _______, _______, _______, _______, RGB_HUD, RGB_SAD, RGB_VAD, _______, \
       _______, _______, _______, _______, _______, _______, _______, RGB_TOG, BL_OFF,  BL_DEC,  BL_INC,  BL_ON    \
    )
};
