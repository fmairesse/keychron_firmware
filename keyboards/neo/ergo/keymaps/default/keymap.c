#include QMK_KEYBOARD_H

// #region Layers
enum layers {
    WIN_BASE,
    WIN_FN,
    BASE_LAYER_SWITCH,
    WIN_NAV,
    MAC_BASE,
    MAC_FN,
};
// #endregion Layers

//#region Aliases
// #define _TNPAD   TG(_NUM_RIGHT)
// #define _1DK     KC_LEFT_BRACKET
// // #define _MAGIC  _RSFT

// // Left pinkies
#define _ESC     KC_ESC //LT(_FKEYS,KC_ESC)
// #define _TAB     KC_TAB
// #define _LSFT    LSFT_T(KC_NONUS_BACKSLASH)

// // Left alphas
// #define _A       LT(_NAV,KC_A)
// #define _A🍏      LT(_NAV🍏,KC_A)
// #define _S       LALT_T(KC_S)
// #define _D       LCTL_T(KC_D)
// #define _D🍏     LCMD_T(KC_D)
// #define _F       LSFT_T(KC_F)
// #define _V       KC_V

// // Right alphas
// #define _J       RSFT_T(KC_J)
// #define _K       RCTL_T(KC_K)
// #define _K🍏     RCMD_T(KC_K)
// #define _L       LALT_T(KC_L)
// #define _SCLN    LT(_NUM_LEFT,KC_SEMICOLON)
// #define _COMM    KC_COMM

// // Right pinkies
// #define _BSPC    LT(_FKEYS,KC_BSPC)
// #define _RSFT    RSFT_T(KC_SLASH)

// // Thumbs
// #define _T1LFT   TD(_TD_T1LFT)
// #define _T1LFT🍏 TD(_TD_T1LFT_MAC)
// #define _T2LFT   LT(_NUM_RIGHT,KC_SPC)
#define _T2RGT   KC_SPC //LT(_NUM_LEFT,KC_SPC)
// #define _T1RGT   RALT_T(KC_LEFT_BRACKET)

// // Shortcuts
// #define _ZOIN    LCTL(KC_EQUAL)
// #define _ZOIN🍏  LCMD(KC_EQUAL)
// #define _ZOOUT   LCTL(KC_MINUS)
// #define _ZOOUT🍏 LCMD(KC_MINUS)
// #define _BACK🍏  LCMD(KC_LBRC)
// #define _FWD🍏   LCMD(KC_RBRC)
// #define _MCTL🍏  TD(_TD_MCTL) // Mission control
// #define _LSCR🍏  LCTL(LGUI(KC_Q)) // Lock screen
// #define _LPAD🍏  LCTL(LGUI(LALT(KC_B)))

// //Base layer switch
// #define _TOMAC   DF(_MAC)
// #define _TOWIN   DF(_BASE)
//#endregion Aliases

// #region Combos
enum combo_events { _BOOT_COMBO, _BASE_LAYER_COMBO, _MAC_BASE_LAYER_COMBO };

const uint16_t PROGMEM boot_combo[]       = {KC_LCTL, _ESC, _T2RGT, COMBO_END};
const uint16_t PROGMEM base_layer_combo[] = {KC_LEFT, KC_RIGHT, COMBO_END};

combo_t key_combos[] = {
    [_BOOT_COMBO]       = COMBO(boot_combo, QK_BOOT),
    // [_BASE_LAYER_COMBO] = COMBO_ACTION(base_layer_combo),
};
// void process_combo_event(uint16_t combo_index, bool pressed) {
//     switch (combo_index) {
//         case _BASE_LAYER_COMBO:
//             if (pressed) {
//                 layer_on(BASE_LAYER_SWITCH);
//             } else {
//                 layer_off(BASE_LAYER_SWITCH);
//             }
//             break;
//     }
// }
// #endregion Combos

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [WIN_BASE] = LAYOUT(
        KC_DEL,    KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_NUHS, KC_BSPC,
        KC_PGUP,   KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS,
        KC_PGDN,   KC_CAPS, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,          KC_ENT,
        MO(WIN_FN),KC_LSFT, KC_NUBS, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_UP,   KC_RSFT,
                   KC_LCTL, KC_LGUI,                            KC_LALT, KC_SPC,  KC_SPC,  KC_RALT,                            KC_LEFT, KC_DOWN, KC_RGHT
    ),

    [WIN_FN] = LAYOUT(
        _______, KC_GRV,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, NK_TOGG, _______, _______, _______, _______, _______, _______,          _______,
        _______, _______, _______, UG_TOGG, UG_NEXT, UG_PREV, UG_HUED, UG_HUEU, UG_SATU, UG_SATD, UG_VALU, UG_VALD, _______, _______, _______, _______,
        _______, _______,                   _______, _______, _______, _______,                                     _______, _______, _______
    ),

    // [MAC_BASE] = LAYOUT(
    //     KC_DEL,  KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_NUHS, KC_BSPC,
    //     KC_PGUP, KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS,
    //     KC_PGDN, KC_CAPS, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,          KC_ENT,
    //     KC_NO,   KC_LSFT, KC_NUBS, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_UP,   KC_RSFT,
    //              KC_LCTL, KC_LALT,                            KC_LGUI, KC_SPC,  KC_SPC,  KC_RALT,                            KC_LEFT, KC_DOWN, KC_RGHT
    // ),

    // // [MAC_FN] = LAYOUT(
    // //     EE_CLR, KC_GRV,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  _______, _______,
    // //     _______, KC_NXT, LT(0, KC_BT1), LT(0, KC_BT2), LT(0, KC_BT3), LT(0, KC_2G4), _______, _______, KC_USB, _______, _______, _______, _______, _______, _______,
    // //     _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
    // //     _______, _______, _______, RGB_TOG, RGB_MOD, RGB_RMOD,RGB_HUI, RGB_HUD, RGB_HUD, RGB_SPI, RGB_SPD, RGB_VAI, RGB_VAD, _______, _______, _______,
    // //              _______, TO(WIN_BASE),                          _______, _______, _______, _______,                            _______, _______, _______
    // // )
    // [BASE_LAYER_SWITCH] = LAYOUT(
    //     _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    //     _______, _______, _______, _TOWIN,  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    //     _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    //     _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _TOMAC,  _______, _______, _______, _______, _______,
    //     _______, _______,                   _______, _______, _______, _______,                                     _______, _______, _______
    // )
};

// clang-format on
