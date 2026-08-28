#include QMK_KEYBOARD_H
#include "keychron_common.h"

//#region Layers
enum layers {
    MAC_BASE,
    MAC_FN,
    WIN_BASE,
    WIN_FN,
    _NAV,
    _NAV🍏,
    _NUM
};
//#endregion Layers

//#region Tap Dance
enum {
    _TD_MCTL,
};

static bool mctl_held;

static void mctl_finished(tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
        if (state->pressed) {
            mctl_held = true;
            register_code(KC_LCMD);
        } else {
            tap_code(KC_MCTL);
        }
    } else if (state->count == 2) {
        tap_code16(LCTL(KC_DOWN));
    }
}

static void mctl_reset(tap_dance_state_t *state, void *user_data) {
    if (mctl_held) {
        unregister_code(KC_LCMD);
        mctl_held = false;
    }
}

tap_dance_action_t tap_dance_actions[] = {
    // _TD_MCTL:
    // tapped once: send MCTL,
    // tapped twice: send LCTL+DOWN
    // held: send LCMD
    [_TD_MCTL] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, mctl_finished, mctl_reset)
};
//#endregion Tap Dance

// #region Key aliases

// Left alphas
#define _A       LT(_NAV,KC_A)
#define _A🍏     LT(_NAV🍏,KC_A)
#define _S       LALT_T(KC_S)
#define _D       LCTL_T(KC_D)
#define _D🍏     LCMD_T(KC_D)
#define _F       LSFT_T(KC_F)

// Right alphas
#define _J       RSFT_T(KC_J)
#define _K       RCTL_T(KC_K)
#define _K🍏     RCMD_T(KC_K)
#define _L       LALT_T(KC_L)
#define _SCLN    LT(_NAV,KC_SCLN)
#define _SCLN🍏  LT(_NAV🍏,KC_SCLN)

// Thumbs
#define _T1LFT   LALT_T(KC_BSPC)
#define _T2LFT   LCTL_T(KC_SPC)
#define _T2LFT🍏 LCMD_T(KC_SPC)
#define _T3LFT   MO(WIN_FN)
#define _T3LFT🍏 MO(MAC_FN)
#define _T2RGT   RALT_T(KC_SPC)
#define _T1RGT   RALT_T(KC_DEL)

// Shortcuts
#define _ZOIN    LCTL(KC_EQUAL)
#define _ZOIN🍏  LCMD(KC_EQUAL)
#define _ZOOUT   LCTL(KC_MINUS)
#define _ZOOUT🍏 LCMD(KC_MINUS)
#define _BAK     LCTL_T(KC_WBAK)
#define _BAK🍏   LCMD(KC_LBRC)
#define _FWD     LSFT_T(KC_WFWD)
#define _FWD🍏   LCMD(KC_RBRC)
#define _LSCR🍏  LCTL(LGUI(KC_Q)) // Lock screen
#define _MCTL🍏  TD(_TD_MCTL) // Mission control
#define _SPTL🍏  LCTL(LGUI(LALT(KC_SPC))) // Spotlight

// Base layers switchers
#define _TOMAC   DF(MAC_BASE)
#define _TOWIN   DF(WIN_BASE)

// #endregion Key aliases

//#region Combos
const uint16_t PROGMEM boot_combo[] = {KC_LCTL, KC_ESC, _T2RGT,  COMBO_END};

combo_t key_combos[] = {
    COMBO(boot_combo, QK_BOOT),
};
//#endregion Combos

//#region Key Overrides
// const key_override_t w_override = {
//     .trigger_mods      = MOD_MASK_CTRL | MOD_BIT_LALT | MOD_MASK_GUI,
//     .layers            = (1UL << MAC_BASE) | (1UL << WIN_BASE),
//     .negative_mod_mask = 0,
//     .suppressed_mods   = 0,
//     .replacement       = KC_BSLS,
//     .trigger           = KC_W,
//     .options           = ko_options_default | ko_option_one_mod,
//     .custom_action     = NULL,
//     .context           = NULL,
//     .enabled           = NULL,
// };
// const key_override_t z_override = {
//     .trigger_mods      = MOD_MASK_CTRL | MOD_BIT_LALT | MOD_MASK_GUI,
//     .layers            = (1UL << MAC_BASE) | (1UL << WIN_BASE),
//     .negative_mod_mask = 0,
//     .suppressed_mods   = 0,
//     .trigger           = KC_Z,
//     .replacement       = KC_RIGHT_BRACKET,
//     .options           = ko_options_default | ko_option_one_mod,
//     .custom_action     = NULL,
//     .context           = NULL,
//     .enabled           = NULL,
// };

const key_override_t **key_overrides = (const key_override_t *[]){
    // &w_override,
    // &z_override,
    NULL,
};
//#endregion Key Overrides


// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [MAC_BASE] = LAYOUT_ansi_90(
        KC_MUTE,  KC_ESC,   KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,   KC_F9,     KC_F10,   KC_F11,   KC_F12,   KC_INS,             KC_DEL,
        _SPTL🍏,  KC_GRV,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,    KC_9,      KC_0,     KC_MINS,  KC_EQL,   KC_BSPC,            KC_PGDN,
        MC_2,     KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_Y,     KC_U,     KC_I,    KC_O,      KC_P,     KC_LBRC,  KC_RBRC,  KC_BSLS,            KC_HOME,
        KC_CAPS,  KC_ESC,   _A🍏,      _S,       _D🍏,     _F,       KC_G,     KC_H,     _J,       _K🍏,    _L,       _SCLN🍏,  KC_QUOT,            KC_ENT,             KC_END,
        KC_LNPAD, KC_LSFT,            KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_B,     KC_N,    KC_M,      KC_COMM,  KC_DOT,   KC_SLSH,  KC_RSFT,  KC_UP,
        KC_MCTRL, KC_LCTL,  _MCTL🍏,            _T1LFT,   _T2LFT🍏, _T3LFT🍏,                     _T2RGT,             _T1RGT,   KC_RCTL,            KC_LEFT,  KC_DOWN,  KC_RGHT),

    [MAC_FN] = LAYOUT_ansi_90(
        RGB_TOG,  _______,  KC_BRID,  KC_BRIU,  KC_MCTRL, KC_LNPAD, RGB_VAD,  RGB_VAI,  KC_MPRV,  KC_MPLY, KC_MNXT,   KC_MUTE,  KC_VOLD,  KC_VOLU,  _______,            _______,
        _TOMAC,   _______,  BT_HST1,  BT_HST2,  BT_HST3,  P2P4G,    _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,            _______,
        _TOWIN,   RGB_TOG,  RGB_MOD,  RGB_VAI,  RGB_HUI,  RGB_SAI,  RGB_SPI,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,            _______,
        _______,  _______,  RGB_RMOD, KC_PSCR,  RGB_HUD,  RGB_SAD,  RGB_SPD,  _______,  _______,  _______,  _LSCR🍏,   _______,  _______,            _______,            KC_END,
        _______,  _______,            _______,  _______,  _______,  _______,  BAT_LVL,  BAT_LVL,  NK_TOGG,  _______,  _______,  _______,  _______,  _______,  _______,
        _______,  _______,  _______,            _______,  _______,  _______,                      _SPTL🍏,            _______,  _______,            _______,  _______,  _______),

    [WIN_BASE] = LAYOUT_ansi_90(
        KC_MUTE,  KC_ESC,   KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,   KC_INS,             KC_DEL,
        MC_1,     KC_GRV,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,  KC_EQL,   KC_BSPC,            KC_PGDN,
        MC_2,     KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_LBRC,  KC_RBRC,  KC_BSLS,            KC_HOME,
        KC_CAPS,  KC_ESC,   _A,       _S,       _D,       _F,       KC_G,     KC_H,     _J,       _K,       _L,       _SCLN,    KC_QUOT,            KC_ENT,             KC_END,
        MC_4,     KC_LSFT,            KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,  KC_RSFT,  KC_UP,
        MC_5,     KC_LCTL,  KC_LWIN,            _T1LFT,   _T2LFT,   _T3LFT,                       _T2RGT,             _T1RGT,   KC_RCTL,            KC_LEFT,  KC_DOWN,  KC_RGHT),

    [WIN_FN] = LAYOUT_ansi_90(
        RGB_TOG,  _______,  KC_BRID,  KC_BRIU,  KC_TASK,  KC_FILE,  RGB_VAD,  RGB_VAI,  KC_MPRV,  KC_MPLY,  KC_MNXT,  KC_MUTE,  KC_VOLD,  KC_VOLU,  _______,            _______,
        _TOMAC,   _______,  BT_HST1,  BT_HST2,  BT_HST3,  P2P4G,    _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,            KC_PGUP,
        _TOWIN,   RGB_TOG,  RGB_MOD,  RGB_VAI,  RGB_HUI,  RGB_SAI,  RGB_SPI,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,            _______,
        _______,  _______,  RGB_RMOD, KC_PSCR,  RGB_HUD,  RGB_SAD,  RGB_SPD,  _______,  _______,  _______,  _______,  _______,  _______,            _______,            _______,
        _______,  _______,            _______,  _______,  _______,  _______,  BAT_LVL,  BAT_LVL,  NK_TOGG,  _______,  _______,  _______,  _______,  _______,  _______,
        _______,  _______,  _______,            _______,  _______,  _______,                      _______,            _______,  _______,            _______,  _______,  _______),

    [_NAV] = LAYOUT_ansi_90(
        _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,            _______,
        _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,            _______,
        _______,  _______,  KC_ESC,   XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  KC_PGUP,  KC_HOME,  KC_UP,    KC_END,   KC_ESC,   _______,  _______,  _______,            _______,
        _______,  _______,  KC_TAB,   KC_LALT,  KC_LCTL,  KC_LSFT,  XXXXXXX,  KC_PGDN,  KC_LEFT,  KC_DOWN,  KC_RGHT,  KC_TAB,   _______,            _______,            _______,
        _______,  _______,            XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  _ZOOUT,   _ZOIN,    _BAK,     _FWD,     _______,  _______,  _______,
        _______,  _______,  _______,            _______,  _______,  _______,                      KC_ENT,             KC_BSPC,  _______,            _______,  _______,  _______),

    [_NAV🍏] = LAYOUT_ansi_90(
        _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,            _______,
        _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,            _______,
        _______,  _______,  KC_ESC,   XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  KC_PGUP,  KC_HOME,  KC_UP,    KC_END,   KC_ESC,   _______,  _______,  _______,            _______,
        _______,  _______,  KC_TAB,   KC_LALT,  KC_LCMD,  KC_LSFT,  XXXXXXX,  KC_PGDN,  KC_LEFT,  KC_DOWN,  KC_RGHT,  KC_TAB,   _______,            _______,            _______,
        _______,  _______,            XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  _ZOOUT🍏,  _ZOIN🍏,  _BAK🍏,  _FWD🍏,   _______,  _______,  _______,
        _______,  _______,  _______,            _______,  _______,  _______,                      KC_ENT,             KC_BSPC,  _______,            _______,  _______,  _______),

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
    [_NAV🍏]     = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU)},
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
        case _T1LFT:
        case _T2LFT:
        case _T1RGT:
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
