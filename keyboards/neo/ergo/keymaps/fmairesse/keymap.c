#include QMK_KEYBOARD_H

#pragma region Layers
// clang-format off
enum layers {
    MAC_BASE,
    WIN_BASE,
    MAC_FN,
    WIN_FN,
    MAC_NAV,
    WIN_NAV,
    VOID
};
// clang-format on
#pragma endregion Layers

#pragma region Key aliases
// clang-format off

// Shortcuts
#define ZOIN🪟   LCTL(KC_EQUAL)
#define ZOIN🍏   LCMD(KC_EQUAL)
#define ZOOUT🪟  LCTL(KC_MINUS)
#define ZOOUT🍏  LCMD(KC_MINUS)
#define BAK🪟    LCTL_T(KC_WBAK)
#define BAK🍏    LCMD(KC_LBRC)
#define FWD🪟    LSFT_T(KC_WFWD)
#define FWD🍏    LCMD(KC_RBRC)
#define LSCR🍏   LCTL(LGUI(KC_Q)) // Lock screen
#define SPTL🍏   LCAG_T(KC_SPC) // Spotlight
#define PSCR🍏   LCTL(LSFT(LGUI(KC_4)))
#define HOME🍏   LCMD(KC_LEFT)
#define END🍏    LCMD(KC_RIGHT)

// Left pinkies
#define ESC🪟    LT(WIN_FN,KC_ESC)
#define ESC🍏    LT(MAC_FN,KC_ESC)

// Left alphas
#define _A🪟     LWIN_T(KC_A)
#define _A🍏     LCTL_T(KC_A)
#define _S       LALT_T(KC_S)
#define _D🪟     LCTL_T(KC_D)
#define _D🍏     LCMD_T(KC_D)
#define _F       LSFT_T(KC_F)
#define _F🍏     LSFT_T(KC_F)

// Right alphas
#define _J       RSFT_T(KC_J)
#define _K🪟     RCTL_T(KC_K)
#define _K🍏     RCMD_T(KC_K)
#define _L       RALT_T(KC_L)
#define _SCLN🪟  RWIN_T(KC_SCLN)
#define _SCLN🍏  RCTL_T(KC_SCLN)

// Right pinkies
#define BSPC🪟   LT(WIN_FN,KC_BSPC)
#define BSPC🍏   LT(MAC_FN,KC_BSPC)

// Last row
#define T1LFT🍏 LCMD_T(KC_BSPC)
#define T1LFT🪟 LCTL_T(KC_BSPC)
#define T2LFT🪟 LT(WIN_NAV, KC_SPC)
#define T2LFT🍏 LT(MAC_NAV, KC_SPC)
#define T2RGT   RALT_T(KC_SPC)
#define T1RGT   RALT_T(KC_DEL)
#define UP_SFT  RSFT_T(KC_UP)
#define SL_SFT  RSFT_T(KC_SLSH)

// Left pinkies
#define _TAB🍏   LCAG_T(KC_TAB)

//Base layer switch
#define TOMAC   DF(MAC_BASE)
#define TOWIN   DF(WIN_BASE)

// clang-format on
#pragma endregion Key aliases

#pragma region Combos
enum combo_events { BOOT_COMBO🪟, BOOT_COMBO🍏 };

const uint16_t PROGMEM boot_combo🪟[] = {KC_LCTL, ESC🪟, T2RGT, COMBO_END};
const uint16_t PROGMEM boot_combo🍏[] = {KC_LCTL, ESC🍏, T2RGT, COMBO_END};
const uint16_t PROGMEM caps_combo🪟[] = {_D🪟, _K🪟, COMBO_END};
const uint16_t PROGMEM caps_combo🍏[] = {_D🍏, _K🍏, COMBO_END};

combo_t key_combos[] = {
    COMBO(boot_combo🪟, QK_BOOT),
    COMBO(boot_combo🍏, QK_BOOT),
    COMBO(caps_combo🪟, KC_CAPS),
    COMBO(caps_combo🍏, KC_CAPS),
};
#pragma endregion Combos

#pragma region Keymaps
// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [MAC_BASE] = LAYOUT(
        KC_PGUP, ESC🍏,   KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_NUHS, BSPC🍏,
        KC_PGDN, _TAB🍏,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS,
        HOME🍏,  KC_ESC,  _A🍏,    _S,      _D🍏,    _F,      KC_G,    KC_H,    _J,      _K🍏,    _L,      _SCLN🍏, KC_QUOT,         KC_ENT,
        END🍏,   KC_LSFT, KC_NUBS, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  SL_SFT,  UP_SFT,  KC_RSFT,
                 KC_LCTL, LALT_T(KC_MCTL),                    T1LFT🍏, T2LFT🍏, T2RGT,   T1RGT,                              KC_LEFT, KC_DOWN, KC_RGHT
    ),
    [WIN_BASE] = LAYOUT(
        KC_PGUP, ESC🪟,   KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_NUHS, BSPC🪟,
        KC_PGDN, KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS,
        KC_HOME, KC_ESC,  _A🪟,    _S,      _D🪟,    _F,      KC_G,    KC_H,    _J,      _K🪟,    _L,      _SCLN🪟, KC_QUOT,          KC_ENT,
        KC_END,  KC_LSFT, KC_NUBS, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  SL_SFT,  UP_SFT,  KC_RSFT,
                 KC_LWIN, KC_LALT,                            T1LFT🪟, T2LFT🪟, T2RGT,   T1RGT,                              KC_LEFT, KC_DOWN, KC_RGHT
    ),

    [MAC_FN] = LAYOUT(
        _______, _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  _______, _______,
        _______, _______, _______, TOWIN,   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, LSCR🍏,  _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
        _______, _______, _______, _______, _______, _______, _______, _______, KC_LPAD, _______, TOMAC,   _______, _______, _______, _______, _______,
                 _______, _______,                            _______, _______, SPTL🍏,  _______,                            _______, _______, _______
    ),
    [WIN_FN] = LAYOUT(
        _______, _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  _______, _______,
        _______, _______, _______, TOWIN,   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, TOMAC,   _______, _______, _______, _______, _______,
                 _______, _______,                            _______, _______, _______, _______,                            _______, _______, _______
    ),

    [MAC_NAV] = LAYOUT(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_DEL,
        _______, _______, KC_9,    KC_8,    KC_7,    KC_6,   KC_5,     KC_PGUP, HOME🍏,  KC_UP,   END🍏,   KC_ESC,  _______, _______, _______,
        _______, KC_CAPS, KC_LCTL, KC_LALT, KC_LCMD, KC_LSFT, _______, KC_PGDN, KC_LEFT, KC_DOWN, KC_RGHT, KC_TAB,  _______,          _______,
        _______, _______, XXXXXXX, KC_4,    KC_3,    KC_2,    KC_1,    KC_0,    ZOOUT🍏, ZOIN🍏,  BAK🍏,   FWD🍏,   _______, _______, _______, _______,
                 _______, _______,                            _______, _______, KC_ENT,  KC_BSPC,                            _______, _______, _______
    ),
    [WIN_NAV] = LAYOUT(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_DEL,
        _______, _______, KC_ESC,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_PGUP, KC_HOME, KC_UP,   KC_END,  KC_ESC,  _______, _______, _______,
        _______, _______, KC_TAB,  KC_LALT, KC_LCTL, KC_LSFT, XXXXXXX, KC_PGDN, KC_LEFT, KC_DOWN, KC_RGHT, KC_TAB,  _______,          _______,
        _______, _______, XXXXXXX, KC_4,    KC_3,    KC_2,    KC_1,    KC_0,    ZOOUT🪟, ZOIN🪟,  BAK🪟,   FWD🪟,   _______, _______, _______, _______,
                 _______, _______,                            _______, _______, KC_ENT,  KC_BSPC,                            _______, _______, _______
    ),

    // [VOID] = LAYOUT(
    //     _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    //     _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    //     _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
    //     _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    //              _______, _______,                            _______, _______, _______, _______,                            _______, _______, _______
    // )
};
// clang-format on
#pragma endregion Keymaps

#pragma region Functions

bool get_chordal_hold(uint16_t tap_hold_keycode, keyrecord_t *tap_hold_record, uint16_t other_keycode, keyrecord_t *other_record) {
    // Exceptionally allow some one-handed chords for hotkeys.
    switch (tap_hold_keycode) {
        case T1LFT🪟:
        case T1LFT🍏:
        case T2LFT🪟:
        case T2LFT🍏:
        case T2RGT:
        case LALT_T(KC_MCTL):
            return true;
    }

    // Otherwise defer to the opposite hands rule.
    return get_chordal_hold_default(tap_hold_record, other_record);
}

#pragma endregion Functions
