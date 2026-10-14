#include QMK_KEYBOARD_H

#pragma region Layers
enum layers {
    MAC_BASE,
    WIN_BASE,
    MAC_FN,
    WIN_FN,
    VOID
};
#pragma endregion Layers

#pragma region Key aliases

//Base layer switch
#define TOMAC   DF(MAC_BASE)
#define TOWIN   DF(WIN_BASE)

#pragma endregion Key aliases

#pragma region Combos
enum combo_events { BOOT_COMBO };

// clang-format off
const uint16_t PROGMEM boot_combo[]     = {KC_LCTL, KC_ESC, KC_SPC, COMBO_END};
// clang-format on

combo_t key_combos[] = {
    COMBO(boot_combo, QK_BOOT),
};
#pragma endregion Combos

#pragma region Keymaps
// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [MAC_BASE] = LAYOUT(
        KC_DEL,    KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_NUHS, KC_BSPC,
        KC_PGUP,   KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS,
        KC_PGDN,   KC_CAPS, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,          KC_ENT,
        MO(MAC_FN),KC_LSFT, KC_NUBS, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_UP,   KC_RSFT,
                   KC_LCTL, KC_LOPT,                            KC_LCMD, KC_SPC,  KC_SPC,  KC_RCMD,                            KC_LEFT, KC_DOWN, KC_RGHT
    ),
    [WIN_BASE] = LAYOUT(
        KC_DEL,    KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_NUHS, KC_BSPC,
        KC_PGUP,   KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS,
        KC_PGDN,   KC_CAPS, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,          KC_ENT,
        MO(WIN_FN),KC_LSFT, KC_NUBS, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_UP,   KC_RSFT,
                   KC_LCTL, KC_LGUI,                            KC_LALT, KC_SPC,  KC_SPC,  KC_RALT,                            KC_LEFT, KC_DOWN, KC_RGHT
     ),

    [MAC_FN] = LAYOUT(
        _______, _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  _______, _______,
        _______, _______, _______, TOWIN,   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, TOMAC,   _______, _______, _______, _______, _______,
                 _______, _______,                            _______, _______, _______,  _______,                            _______, _______, _______
    ),
    [WIN_FN] = LAYOUT(
        _______, _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  _______, _______,
        _______, _______, _______, TOWIN,   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, TOMAC,   _______, _______, _______, _______, _______,
                 _______, _______,                            _______, _______, _______, _______,                            _______, _______, _______
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

