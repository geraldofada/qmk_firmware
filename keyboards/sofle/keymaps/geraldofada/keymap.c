// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later
#include QMK_KEYBOARD_H

enum sofle_layers {
    _HOME,      // 0 - QWERTY base
    _SYMBOLS,   // 1 - Symbols, F-keys, special chars (hold right thumb)
    _NAV,       // 2 - Navigation + editing (hold left thumb)
    _ADJUST,    // 3 - Settings (hold both SYMBOLS + NAV - tri-layer)
    _GAME,      // 4
};

enum custom_keycodes {
    KC_PRVWD = QK_USER,
    KC_NXTWD,
    KC_LSTRT,
    KC_LEND,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/*
 * HOME
 * Row 0:   ~       1       2       3       4       5            6       7       8       9       0       `
 * Row 1:   Tab     Q       W       E       R       T            Y       U       I       O       P       Bspc
 * Row 2:   Esc     A       S       D       F       G            H       J       K       L       ;       '
 * Row 3:   Caps    Z       X       C       V       B       x    x       N       M       ,       .       /       Del
 * Thumbs:                  LAlt    LSft    LCtrl   Nav     Space        Enter   Sym     RCtrl   RSft    RGUI
 *
 * QWERTY base. Ctrl and Shift are duplicated on thumbs.
 * Layer switching: hold Nav with left thumb, hold Sym with right thumb.
 * Tri-layer uses TL_UPPR/TL_LOWR: hold Nav + Sym = Adjust.
 */
[_HOME] = LAYOUT(
  KC_TILD,   KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                        KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_GRV,
  KC_TAB,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                        KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
  KC_ESC,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                        KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
  KC_CAPS,   KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    XXXXXXX,  XXXXXXX,  KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_DEL,
                      KC_LALT, KC_LSFT, KC_LCTL, TL_UPPR,       KC_SPC,        KC_ENT,  TL_LOWR,      KC_RCTL, KC_RSFT, KC_RGUI
),

/*
 * SYMBOLS (hold right thumb Sym)
 * Row 0: F-keys (impossible from HOME)
 * Row 1: Number-row symbols (awkward from HOME: require Shift + top-row reach)
 * Row 2: Math / brackets (impossible from HOME)
 * Row 3: Backslash, pipe (impossible from HOME)
 *
 * Row 0:   F1      F2      F3      F4      F5      F6           F7      F8      F9      F10     F11     F12
 * Row 1:   ~       !       @       #       $       %            ^       &       *       (       )       PSCR
 * Row 2:   =       -       +       _       x       x            [       ]       {       }       x       x
 * Row 3:   x       x       x       x       x       \       |    x       x       x       x       x       x       x
 * Thumbs:                  x       x       x       x       x            x       x       x       x       x
 */
[_SYMBOLS] = LAYOUT(
  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,                     KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,
  KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,                   KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_PSCR,
  KC_EQL,  KC_MINS, KC_PLUS, KC_UNDS, _______, _______,                   KC_LBRC, KC_RBRC, KC_LCBR, KC_RCBR, _______, _______,
  _______, _______, _______, _______, _______, KC_BSLS, _______, _______, KC_PIPE, _______, _______, _______, _______, _______,
                    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
),

/*
 * NAV (hold left thumb Nav)
 * Row 0:   x       x       x       x       x       x            x       PSCR    PgUp    Home    End     x
 * Row 1:   x       PrvWd   x       x       x       x            x       x       x       NxtWd   x       x
 * Row 2:   x       LStr    x       x       x       x            Left    Down    Up      Right   x       x
 * Row 3:   Ins     Undo    Cut     Copy    Paste   LEnd    x    x       x       PgDn    Del     Bspc    x       x
 * Thumbs:                  x       x       x       x       x            x       x       x       x       x
 *
 * Right hand uses Vim-style HJKL positions: H=Left, J=Down, K=Up, L=Right.
 */
[_NAV] = LAYOUT(
  _______, _______, _______, _______, _______, _______,                   _______, KC_PSCR, KC_PGUP, KC_HOME, KC_END,  _______,
  _______, KC_PRVWD,_______, _______, _______, _______,                   _______, _______, _______, KC_NXTWD,_______,_______,
  _______, KC_LSTRT,_______, _______, _______, _______,                   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _______, _______,
  KC_INS,  C(KC_Z), C(KC_X), C(KC_C), C(KC_V), KC_LEND, _______, _______,_______, KC_PGDN, KC_DEL,  KC_BSPC, _______, _______,
                    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
),

/*
 * ADJUST (hold Sym + Nav)
 * Row 0:   x       x       x       x       x       x            x       x       x       x       x       x
 * Row 1:   Caps    x       x       x       x       x            x       x       x       x       Game    Boot
 * Row 2:   x       x       x       x       x       x            x       x       x       x       x       x
 * Row 3:   x       x       x       x       x       x       x    x       x       x       x       x       x       x
 * Thumbs:                  x       x       x       x       x            x       x       x       x       x
 */
[_ADJUST] = LAYOUT(
  _______, _______, _______, _______, _______, QK_BOOT,                   _______, _______, _______, _______, _______, _______,
  KC_CAPS, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, TG(_GAME), _______,
  _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
                    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
),

/*
 * GAME
 * Row 0:   M       1       2       3       4       5            6       7       8       9       0       x
 * Row 1:   Tab     T       Q       W       E       R            F10     x       x       x       x       Bspc
 * Row 2:   Esc     G       A       S       D       F            F11     x       x       x       x       x
 * Row 3:   x       Z       X       C       V       B       x    x       F12     x       x       x       x       x
 * Thumbs:                  x       LAlt    LSft    LCtrl   Space        Enter   x       RCtrl   RSft    Game
 *
 * WASD cluster shifted right to ESDF positions. Toggle back with rightmost thumb.
 */
[_GAME] = LAYOUT(
  KC_M,     KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                     KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    XXXXXXX,
  KC_TAB,   KC_T,    KC_Q,    KC_W,    KC_E,    KC_R,                     KC_F10,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_BSPC,
  KC_ESC,   KC_G,    KC_A,    KC_S,    KC_D,    KC_F,                     KC_F11,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  XXXXXXX,  KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    XXXXXXX, XXXXXXX,KC_F12,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                      XXXXXXX, KC_LALT, KC_LSFT, KC_LCTL, KC_SPC,         KC_ENT,  XXXXXXX, KC_RCTL, KC_RSFT, TG(_GAME)
),

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

// ===========================================================================
// OLED display
// ===========================================================================
#ifdef OLED_ENABLE

// ── Left half (master): portrait 32×128, 5 chars × 16 lines ────────────────

static void print_status_narrow(void) {
    uint8_t layer = get_highest_layer(layer_state);
    led_t   led_state = host_keyboard_led_state();

    // Layer (lines 0–1)
    oled_write_P(PSTR("LAYER\n"), false);
    switch (layer) {
        case _HOME:    oled_write_ln_P(PSTR("HOME"), false); break;
        case _SYMBOLS: oled_write_ln_P(PSTR("SYMB"), false); break;
        case _NAV:     oled_write_ln_P(PSTR("NAV "), false); break;
        case _ADJUST:  oled_write_ln_P(PSTR("ADJS"), false); break;
        default:       oled_write_ln_P(PSTR("????"), false); break;
    }

    // Spacer + separator (lines 2–4)
    oled_write_P(PSTR("\n\n-----\n"), false);

    // Caps Lock (lines 5–7)
    oled_write_P(PSTR("\nCAPS\n"), false);
    oled_write_P(led_state.caps_lock ? PSTR(" ON ") : PSTR("OFF "), false);
    oled_write_P(PSTR("\n"), false);   // << cursor now at line 9SSSS
}

static void print_game_mode_on(void) {
    // Header (lines 0–2)
    oled_write_P(PSTR("GAME\n"), false);
    oled_write_P(PSTR("MODE\n"), false);
    oled_write_P(PSTR(" ON \n"), false);
    // lines 3–15: blank padding
}

// ── Entry point ────────────────────────────────────────────────────────────
// Only the master (left) half has an OLED.

bool oled_task_user(void) {
    if (!is_keyboard_master()) {
        return false;   // No OLED on slave; skip everything.
    }
    if (get_highest_layer(layer_state) >= _GAME) {
        print_game_mode_on();
    } else {
        print_status_narrow();
    }
    return false;   // Skip keyboard-level oled_task_kb.
}

#endif // OLED_ENABLE
