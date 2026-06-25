#include QMK_KEYBOARD_H
#include "keychron_common.h"

//#region Layers
enum layers {
    MAC_BASE,
    MAC_FN,
    WIN_BASE,
    WIN_FN,
    _NAV,
    _NUM
};
//#endregion Layers

// #region Key aliases

// Left alphas
#define _A      LT(_NAV,KC_A)
#define _S      LALT_T(KC_S)
#define _D      LCTL_T(KC_D)
#define _F      LSFT_T(KC_F)

// Right alphas
#define _J      RSFT_T(KC_J)
#define _K      RCTL_T(KC_K)
#define _L      LALT_T(KC_L)
#define _SCLN   LT(_NAV,KC_SCLN)

// Thumbs
#define _T1LEFT LALT_T(KC_BSPC)
#define _T2LEFT LCTL_T(KC_SPC)
#define _T3LEFT MO(WIN_FN)
#define _T2RGHT RALT_T(KC_SPC)
#define _T1RGHT LT(_NUM,KC_DEL)

// Shortcuts
#define _ZOIN   LCTL(KC_EQUAL)
#define _ZOOUT  LCTL(KC_MINUS)
#define _WBAK   LCTL_T(KC_WBAK)
#define _WFWD   LSFT_T(KC_WFWD)
// #endregion

//#region Combos
const uint16_t PROGMEM boot_combo[] = {KC_LCTL, KC_CAPS, _T2RGHT, COMBO_END};

combo_t key_combos[] = {
    COMBO(boot_combo, QK_BOOT),
};
//#endregion Combos

//#region Key Overrides
const key_override_t w_override = {
    .trigger_mods      = MOD_MASK_CTRL | MOD_BIT_LALT | MOD_MASK_GUI,
    .layers            = (1UL << MAC_BASE) | (1UL << WIN_BASE),
    .negative_mod_mask = 0,
    .suppressed_mods   = 0,
    .replacement       = KC_BSLS,
    .trigger           = KC_W,
    .options           = ko_options_default | ko_option_one_mod,
    .custom_action     = NULL,
    .context           = NULL,
    .enabled           = NULL,
};
const key_override_t z_override = {
    .trigger_mods      = MOD_MASK_CTRL | MOD_BIT_LALT | MOD_MASK_GUI,
    .layers            = (1UL << MAC_BASE) | (1UL << WIN_BASE),
    .negative_mod_mask = 0,
    .suppressed_mods   = 0,
    .trigger           = KC_Z,
    .replacement       = KC_RIGHT_BRACKET,
    .options           = ko_options_default | ko_option_one_mod,
    .custom_action     = NULL,
    .context           = NULL,
    .enabled           = NULL,
};

const key_override_t **key_overrides = (const key_override_t *[]){
    &w_override,
    &z_override,
    NULL,
};
//#endregion Key Overrides


// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [MAC_BASE] = LAYOUT_ansi_90(
        KC_MUTE,  KC_ESC,   KC_BRID,  KC_BRIU,  KC_MCTRL, KC_LNPAD, RGB_VAD,  RGB_VAI,  KC_MPRV,  KC_MPLY, KC_MNXT,   KC_MUTE,  KC_VOLD,  KC_VOLU,  KC_INS,             KC_DEL,
        MC_1,     KC_GRV,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,    KC_9,      KC_0,     KC_MINS,  KC_EQL,   KC_BSPC,            KC_PGUP,
        MC_2,     KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_Y,     KC_U,     KC_I,    KC_O,      KC_P,     KC_LBRC,  KC_RBRC,  KC_BSLS,            KC_PGDN,
        MC_3,     KC_CAPS,  KC_A,     KC_S,     KC_D,     KC_F,     KC_G,     KC_H,     KC_J,     KC_K,    KC_L,      KC_SCLN,  KC_QUOT,            KC_ENT,             KC_HOME,
        MC_4,     KC_LSFT,            KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_B,     KC_N,    KC_M,      KC_COMM,  KC_DOT,   KC_SLSH,  KC_RSFT,  KC_UP,
        MC_5,     KC_LCTL,  KC_LOPTN,           KC_LCMMD, KC_SPC,   MO(MAC_FN),                   KC_SPC,             KC_RCMMD, KC_RCTL,            KC_LEFT,  KC_DOWN,  KC_RGHT),

    [MAC_FN] = LAYOUT_ansi_90(
        RGB_TOG,  _______,  KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,     KC_F8,    KC_F9,   KC_F10,   KC_F11,   KC_F12,   _______,            _______,
        _______,  _______,  BT_HST1,  BT_HST2,  BT_HST3,  P2P4G,    _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,            _______,
        _______,  RGB_TOG,  RGB_MOD,  RGB_VAI,  RGB_HUI,  RGB_SAI,  RGB_SPI,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,            _______,
        _______,  _______,  RGB_RMOD, RGB_VAD,  RGB_HUD,  RGB_SAD,  RGB_SPD,  _______,  _______,  _______,  _______,  _______,  _______,            _______,            KC_END,
        _______,  _______,            _______,  _______,  _______,  _______,  BAT_LVL,  BAT_LVL,  NK_TOGG,  _______,  _______,  _______,  _______,  _______,  _______,
        _______,  _______,  _______,            _______,  _______,  _______,                      _______,            _______,  _______,            _______,  _______,  _______),

    [WIN_BASE] = LAYOUT_ansi_90(
        KC_MUTE,  KC_CAPS,  KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,   KC_INS,             KC_DEL,
        MC_1,     KC_GRV,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,  KC_EQL,   KC_BSPC,            KC_PGDN,
        MC_2,     KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_LBRC,  KC_RBRC,  KC_BSLS,            KC_HOME,
        MC_3,     KC_ESC,   _A,       _S,       _D,       _F,       KC_G,     KC_H,     _J,       _K,       _L,       _SCLN,    KC_QUOT,            KC_ENT,             KC_END,
        MC_4,     KC_LSFT,            KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,  KC_RSFT,  KC_UP,
        MC_5,     KC_LCTL,  KC_LWIN,            _T1LEFT,  _T2LEFT,  _T3LEFT,                      _T2RGHT,            _T1RGHT,  KC_RCTL,            KC_LEFT,  KC_DOWN,  KC_RGHT),

    [WIN_FN] = LAYOUT_ansi_90(
        RGB_TOG,  _______,  KC_BRID,  KC_BRIU,  KC_TASK,  KC_FILE,  RGB_VAD,  RGB_VAI,  KC_MPRV,  KC_MPLY,  KC_MNXT,  KC_MUTE,  KC_VOLD,  KC_VOLU,  _______,            _______,
        _______,  _______,  BT_HST1,  BT_HST2,  BT_HST3,  P2P4G,    _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,            KC_PGUP,
        _______,  RGB_TOG,  RGB_MOD,  RGB_VAI,  RGB_HUI,  RGB_SAI,  RGB_SPI,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,            _______,
        _______,  _______,  RGB_RMOD, KC_PSCR,  RGB_HUD,  RGB_SAD,  RGB_SPD,  _______,  _______,  _______,  _______,  _______,  _______,            _______,            _______,
        _______,  _______,            _______,  _______,  _______,  _______,  BAT_LVL,  BAT_LVL,  NK_TOGG,  _______,  _______,  _______,  _______,  _______,  _______,
        _______,  _______,  _______,            _______,  _______,  _______,                      _______,            _______,  _______,            _______,  _______,  _______),

    [_NAV] = LAYOUT_ansi_90(
        _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,            _______,
        _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,            _______,
        _______,  _______,  KC_ESC,   XXXXXXX,  _ZOOUT,   _ZOIN,    XXXXXXX,  KC_PGUP,  KC_HOME,  KC_UP,    KC_END,   KC_ESC,   _______,  _______,  _______,            _______,
        _______,  _______,  KC_TAB,   KC_LALT,  _WBAK,    _WFWD,    XXXXXXX,  KC_PGDN,  KC_LEFT,  KC_DOWN,  KC_RGHT,  KC_TAB,   _______,            _______,            _______,
        _______,  _______,            XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  _______,  _______,  _______,  _______,
        _______,  _______,  _______,            _______,  _______,  _______,                      KC_ENT,             _______,  _______,            _______,  _______,  _______),

    [_NUM] = LAYOUT_ansi_90(
        _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,            _______,
        _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,            _______,
        _______,  _______, RALT(KC_D),KC_6,     KC_5,     KC_4,    RALT(KC_T),KC_PGUP,  KC_HOME,  KC_UP,    KC_END,   KC_ESC,   _______,  _______,  _______,            _______,
        _______,  _______, RALT(KC_S),KC_3,     KC_2,     KC_1,    RALT(KC_G),KC_PGDN,  KC_LEFT,  KC_DOWN,  KC_RGHT,  KC_TAB,   _______,            _______,            _______,
        _______,  _______,           RALT(KC_Z),KC_9,     KC_8,    KC_7,     RALT(KC_B),XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  _______,  _______,  _______,  _______,
        _______,  _______,  _______,            _______,  _______, KC_0,                          KC_ENT,             _______,  _______,            _______,  _______,  _______),
};

const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][2] = {
    [MAC_BASE] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU)},
    [MAC_FN]   = { ENCODER_CCW_CW(RGB_VAD, RGB_VAI)},
    [WIN_BASE] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU)},
    [WIN_FN]   = { ENCODER_CCW_CW(RGB_VAD, RGB_VAI)},
    [_NAV]     = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU)},
    [_NUM]     = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU)},
};

// clang-format on
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    // Quick software reset handler
    if (keycode == QK_BOOT && record->event.pressed) {
        reset_keyboard();
    } else if (!process_record_keychron_common(keycode, record)) {
        return false;
    }
    return true;
}

bool get_hold_on_other_key_press(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case _T1LEFT:
        case _T2LEFT:
        case _T2RGHT:
        case _T1RGHT:
            // Immediately select the hold action when another key is pressed.
            return true;
        default:
            // Do not select the hold action when another key is pressed.
            return false;
    }
}

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case _S:
        case _D:
        case _F:
        case _J:
        case _K:
        case _L:
            return TAPPING_TERM + 30;
        default:
            return TAPPING_TERM;
    }
}
