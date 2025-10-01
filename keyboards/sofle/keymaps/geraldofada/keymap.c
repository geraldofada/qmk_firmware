// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later
#include QMK_KEYBOARD_H

enum sofle_layers {
    _HOME,      // QWERTY base
    _SYMBOLS,   // F1-F10 na home row + modificadores
    _NAV,       // Navegação
    _GAME,
    _GAMEMOD1,
    _GAMEMOD2
};

enum custom_keycodes {
    KC_PRVWD = QK_USER,
    KC_NXTWD,
    KC_LSTRT,
    KC_LEND,
};

enum {
    TD_SHIFT_CAPS,
};

tap_dance_action_t tap_dance_actions[] = {
    [TD_SHIFT_CAPS] = ACTION_TAP_DANCE_DOUBLE(KC_LSFT, KC_CAPS),
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/*
 * HOME
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |  ~   |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |  `   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | TAB  |   Q  |   W  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |   P  | Bspc |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | ESC  |   A  |   S  |   D  |   F  |   G  |-------.    ,-------|   H  |   J  |   K  |   L  |   ;  |   '  |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |      |   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   N  |   M  |   ,  |   .  |   /  |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            |      |      |      |      | /       /       \      \  |      |      |      |      |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */
[_HOME] = LAYOUT(
  S(KC_GRV), KC_1, KC_2, KC_3, KC_4, KC_5,                     KC_6, KC_7, KC_8, KC_9, KC_0, KC_GRV,
  KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T,                     KC_Y, KC_U, KC_I, KC_O, KC_P, KC_BSPC,
  KC_ESC, KC_A, KC_S, KC_D, KC_F, KC_G,                     KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT,
  XXXXXXX, KC_Z, KC_X, KC_C, KC_V, KC_B, XXXXXXX, XXXXXXX, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, XXXXXXX,
            XXXXXXX, TO(_HOME), TD(TD_SHIFT_CAPS), KC_LCTL, KC_SPC, KC_ENT, KC_LGUI, KC_LALT, TG(_SYMBOLS), TG(_GAME)
),

[_SYMBOLS] = LAYOUT(
  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,                     KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11, KC_F12,
  KC_EQL, KC_LBRC, KC_RBRC, KC_LCBR, KC_RCBR, KC_BSLS,                   KC_SCLN, KC_COLN, KC_QUOT, KC_DQUO, KC_PIPE, _______,
  _______, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                      KC_6,    KC_7,    KC_8,    KC_9,    KC_0, KC_MINS,
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_DEL, _______,
                   _______, _______, _______, _______, _______, _______, _______, _______, TG(_NAV), _______
),


[_NAV] = LAYOUT(
  _______, _______, _______, _______, _______, _______,                     _______, _______, _______, _______, _______, _______,
  _______, KC_NXTWD, _______, _______, _______, _______,                     _______, _______, KC_LEND, _______, _______, _______,
  _______, KC_LSTRT, _______, KC_PGUP, KC_PGDN, _______,                     KC_LEFT, KC_DOWN, KC_UP, KC_RGHT, _______, _______,
  _______, _______, KC_BSPC, _______, _______, KC_PRVWD, _______,       _______, _______, _______, _______, _______, _______, _______,
                   _______, _______, _______, _______, _______, _______, _______, _______, XXXXXXX, _______
),

[_GAME] = LAYOUT(
  KC_M,   KC_1,   KC_2,    KC_3,    KC_4,    KC_5,                     KC_6,      KC_7,       KC_8,       KC_9,       KC_0,  XXXXXXX,
  KC_N,   KC_T,   KC_Q,    KC_W,    KC_E,    KC_R,                     KC_F10,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,  KC_BSPC,
  KC_ESC,   KC_G,   KC_A,    KC_S,    KC_D,    KC_F,                     KC_F11,    XXXXXXX,    XXXXXXX,    XXXXXXX, XXXXXXX,  XXXXXXX,
  XXXXXXX,  KC_Z,   KC_X,    KC_C,    KC_V,    KC_B, XXXXXXX,     XXXXXXX,KC_F12,    XXXXXXX, XXXXXXX,  XXXXXXX, XXXXXXX,  XXXXXXX,
                XXXXXXX, KC_LALT, KC_LSFT, KC_LCTL, KC_SPC,       KC_ENT, XXXXXXX, KC_RCTL, KC_RSFT, TG(_GAME)
),

[_GAMEMOD1] = LAYOUT(
  _______,   KC_8,   KC_9,    KC_0,    KC_F1,    KC_F2,                     _______,    _______,    _______,    _______,    _______,  _______,
  _______,   KC_7,   C(KC_Q), _______,    C(KC_R),    C(KC_T),                     _______,    _______,    _______,    _______,    _______,  _______,
  KC_TAB,   C(KC_G),   _______,    _______,    _______,    C(KC_F),                     _______,    _______,    _______,    _______, _______,  _______,
  _______,  C(KC_Z),   C(KC_X),    C(KC_E),    C(KC_C),    C(KC_V), _______,     _______,_______,    _______, _______,  _______, _______,  _______,
                _______, _______, _______, _______, _______,       _______, _______, _______, _______, _______
),


[_GAMEMOD2] = LAYOUT(
  _______,   KC_8,   KC_9,    KC_0,    KC_F1,    KC_F2,                     _______,    _______,    _______,    _______,    _______,  _______,
  _______,   KC_7,   A(KC_Q), _______,    A(KC_R),    A(KC_T),                     _______,    _______,    _______,    _______,    _______,  _______,
  S(KC_TAB),   A(KC_G),   _______,    _______,    _______,    A(KC_F),                     _______,    _______,    _______,    _______, _______,  _______,
  _______,  A(KC_Z),   A(KC_X),    A(KC_E),    A(KC_C),    A(KC_V), _______,     _______,_______,    _______, _______,  _______, _______,  _______,
                _______, _______, _______, _______, _______,       _______, _______, _______, _______, _______
)
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case KC_PRVWD:
            if (record->event.pressed) {
                if (keymap_config.swap_lctl_lgui) {
                    register_mods(mod_config(MOD_LALT));
                    register_code(KC_LEFT);
                } else {
                    register_mods(mod_config(MOD_LCTL));
                    register_code(KC_LEFT);
                }
            } else {
                if (keymap_config.swap_lctl_lgui) {
                    unregister_mods(mod_config(MOD_LALT));
                    unregister_code(KC_LEFT);
                } else {
                    unregister_mods(mod_config(MOD_LCTL));
                    unregister_code(KC_LEFT);
                }
            }
            break;
        case KC_NXTWD:
             if (record->event.pressed) {
                if (keymap_config.swap_lctl_lgui) {
                    register_mods(mod_config(MOD_LALT));
                    register_code(KC_RIGHT);
                } else {
                    register_mods(mod_config(MOD_LCTL));
                    register_code(KC_RIGHT);
                }
            } else {
                if (keymap_config.swap_lctl_lgui) {
                    unregister_mods(mod_config(MOD_LALT));
                    unregister_code(KC_RIGHT);
                } else {
                    unregister_mods(mod_config(MOD_LCTL));
                    unregister_code(KC_RIGHT);
                }
            }
            break;
        case KC_LSTRT:
            if (record->event.pressed) {
                if (keymap_config.swap_lctl_lgui) {
                     //CMD-arrow on Mac, but we have CTL and GUI swapped
                    register_mods(mod_config(MOD_LCTL));
                    register_code(KC_LEFT);
                } else {
                    register_code(KC_HOME);
                }
            } else {
                if (keymap_config.swap_lctl_lgui) {
                    unregister_mods(mod_config(MOD_LCTL));
                    unregister_code(KC_LEFT);
                } else {
                    unregister_code(KC_HOME);
                }
            }
            break;
        case KC_LEND:
            if (record->event.pressed) {
                if (keymap_config.swap_lctl_lgui) {
                    //CMD-arrow on Mac, but we have CTL and GUI swapped
                    register_mods(mod_config(MOD_LCTL));
                    register_code(KC_RIGHT);
                } else {
                    register_code(KC_END);
                }
            } else {
                if (keymap_config.swap_lctl_lgui) {
                    unregister_mods(mod_config(MOD_LCTL));
                    unregister_code(KC_RIGHT);
                } else {
                    unregister_code(KC_END);
                }
            }
            break;
    }
    return true;
}
