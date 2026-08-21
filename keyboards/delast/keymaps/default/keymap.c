#include QMK_KEYBOARD_H

//#region Layers
enum layers {
    _BASE,
    _MAC,
    _NAV,
    _NAV🍏,
    _NUM_RIGHT,
    _NUM_LEFT,
    _FKEYS,
    _BASE_LAYER_SWITCH
};
//#endregion Layers

//#region Tap Dance
enum {
    _TD_MCTL,
};
tap_dance_action_t tap_dance_actions[] = {
    [_TD_MCTL] = ACTION_TAP_DANCE_DOUBLE(LCMD_T(KC_MCTL), LCTL(KC_DOWN))
};
//#endregion Tap Dance

//#region Aliases
#define _TNPAD   TG(_NUM_RIGHT)
#define _1DK     KC_LEFT_BRACKET
// #define _MAGIC  _RSFT

// Left pinkies
#define _ESC     LT(_FKEYS,KC_ESC)
#define _TAB     KC_TAB
#define _LSFT    LSFT_T(KC_NONUS_BACKSLASH)

// Left alphas
#define _A       LT(_NAV,KC_A)
#define _A🍏      LT(_NAV🍏,KC_A)
#define _S       LALT_T(KC_S)
#define _D       LCTL_T(KC_D)
#define _D🍏     LCMD_T(KC_D)
#define _F       LSFT_T(KC_F)
#define _V       KC_V

// Right alphas
#define _J       RSFT_T(KC_J)
#define _K       RCTL_T(KC_K)
#define _K🍏     RCMD_T(KC_K)
#define _L       LALT_T(KC_L)
#define _SCLN    LT(_NUM_LEFT,KC_SEMICOLON)
#define _COMM    KC_COMM

// Right pinkies
#define _BSPC    LT(_FKEYS,KC_BSPC)
#define _RSFT    RSFT_T(KC_SLASH)

// Thumbs
#define _T1LFT   LCTL_T(KC_BSPC)
#define _T1LFT🍏 LCMD_T(KC_SPC)
#define _T2LFT   LT(_NUM_RIGHT,KC_SPC)
#define _T2RGT   LT(_NUM_LEFT,KC_SPC)
#define _T1RGT   RALT_T(KC_DEL)

// Shortcuts
#define _ZOIN    LCTL(KC_EQUAL)
#define _ZOIN🍏  LCMD(KC_EQUAL)
#define _ZOOUT   LCTL(KC_MINUS)
#define _ZOOUT🍏 LCMD(KC_MINUS)
#define _BACK🍏  LCMD(KC_LBRC)
#define _FWD🍏   LCMD(KC_RBRC)
#define _MCTL🍏  TD(_TD_MCTL) // Mission control

//Base layer switch
#define _TOMAC   DF(_MAC)
#define _TOWIN   DF(_BASE)
//#endregion Aliases

//#region Combos
enum combo_events {
    _BOOT_COMBO,
    _CAPS_COMBO,
    _DEL_COMBO,
    _NUMPAD_ON_COMBO,
    _NUMPAD_OFF_COMBO,
    _BASE_LAYER_COMBO,
};

const uint16_t PROGMEM boot_combo[] = {KC_LCTL, _ESC, _T2RGT, COMBO_END};
const uint16_t PROGMEM caps_combo[] = {_LSFT, KC_Z, COMBO_END};
const uint16_t PROGMEM del_combo[] = {_BSPC, KC_P, COMBO_END};
const uint16_t PROGMEM numpad_on_combo[] = {KC_O, KC_P, _BSPC, COMBO_END};
const uint16_t PROGMEM numpad_off_combo[] = {KC_7, KC_8, COMBO_END};
const uint16_t PROGMEM base_layer_combo[] = {KC_LEFT, KC_RIGHT, COMBO_END};

combo_t key_combos[] = {
    [_BOOT_COMBO]       = COMBO(boot_combo, QK_BOOT),
    [_CAPS_COMBO]       = COMBO(caps_combo, KC_CAPS),
    [_DEL_COMBO]        = COMBO(del_combo, KC_DEL),
    [_NUMPAD_ON_COMBO]  = COMBO(numpad_on_combo, _TNPAD),
    [_NUMPAD_OFF_COMBO] = COMBO(numpad_off_combo, _TNPAD),
    [_BASE_LAYER_COMBO] = COMBO_ACTION(base_layer_combo),
};
void process_combo_event(uint16_t combo_index, bool pressed) {
    switch (combo_index) {
        case _BASE_LAYER_COMBO:
            if (pressed) {
                layer_on(_BASE_LAYER_SWITCH);
            } else {
                layer_off(_BASE_LAYER_SWITCH);
            }
            break;
    }
}

//#endregion Combos

//#region Key Overrides
const key_override_t alt_up_slash_override = {
    .trigger_mods      = MOD_BIT_RALT,
    .layers            = (1UL << _BASE),
    .negative_mod_mask = 0,
    .suppressed_mods   = 0,
    .trigger           = KC_UP,
    .replacement       = KC_SLSH,
    .options           = ko_options_default,
    .custom_action     = NULL,
    .context           = NULL,
    .enabled           = NULL,
};
const key_override_t w_override = {
    .trigger_mods      = MOD_MASK_CTRL | MOD_BIT_LALT | MOD_MASK_GUI,
    .layers            = (1UL << _BASE),
    .negative_mod_mask = 0,
    .suppressed_mods   = 0,
    .trigger           = KC_W,
    .replacement       = KC_BACKSLASH,
    .options           = ko_options_default | ko_option_one_mod,
    .custom_action     = NULL,
    .context           = NULL,
    .enabled           = NULL,
};
const key_override_t z_override = {
    .trigger_mods      = MOD_MASK_CTRL | MOD_BIT_LALT | MOD_MASK_GUI,
    .layers            = (1UL << _BASE),
    .negative_mod_mask = 0,
    .suppressed_mods   = 0,
    .trigger           = KC_Z,
    .replacement       = KC_RIGHT_BRACKET,
    .options           = ko_options_default | ko_option_one_mod,
    .custom_action     = NULL,
    .context           = NULL,
    .enabled           = NULL,
};

const key_override_t *key_overrides[] = {
    &alt_up_slash_override,
    &w_override,
    &z_override,
};
//#endregion Key Overrides

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [_BASE] = LAYOUT(
        _ESC,      KC_Q,      KC_W,      KC_E,      KC_R,      KC_T,      KC_Y,      KC_U,      KC_I,      KC_O,      KC_P,      _BSPC,
        _TAB,      _A,        _S,        _D,        _F,        KC_G,      KC_H,      _J,        _K,        _L,        _SCLN,     KC_ENT,
        _LSFT,     KC_Z,      KC_X,      KC_C,      _V,        KC_B,      KC_N,      KC_M,      _COMM,     KC_DOT,    KC_UP,     _RSFT,
        KC_LCTL,   KC_LGUI,   KC_LALT,   KC_MUTE,   _T1LFT,    _T2LFT,    _T2RGT,    _T1RGT,    XXXXXXX,   KC_LEFT,   KC_DOWN,   KC_RGHT
    ),

    [_MAC] = LAYOUT(
        _ESC,      KC_Q,      KC_W,      KC_E,      KC_R,      KC_T,      KC_Y,      KC_U,      KC_I,      KC_O,      KC_P,      _BSPC,
        _TAB,      _A🍏,      _S,        _D🍏,      _F,        KC_G,      KC_H,      _J,        _K🍏,      _L,        _SCLN,     KC_ENT,
        _LSFT,     KC_Z,      KC_X,      KC_C,      _V,        KC_B,      KC_N,      KC_M,      _COMM,     KC_DOT,    KC_UP,     _RSFT,
        KC_LCTL,   _MCTL🍏,   KC_LALT,   KC_MUTE,   _T1LFT🍏,  _T2LFT,    _T2RGT,    _T1RGT,    XXXXXXX,   KC_LEFT,   KC_DOWN,   KC_RGHT
    ),

    // nav layer triggered by left pinky
    [_NAV] = LAYOUT(
        _______,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   KC_PGUP,   KC_HOME,   KC_UP,     KC_END,    KC_ESC,    XXXXXXX,
        _______,   XXXXXXX,   KC_LALT,   KC_LCTL,   KC_LSFT,   XXXXXXX,   KC_PGDN,   KC_LEFT,   KC_DOWN,   KC_RGHT,   KC_TAB,    XXXXXXX,
        _______,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   _ZOOUT,    _ZOIN,     KC_WBAK,   KC_WFWD,   XXXXXXX,   XXXXXXX,
        _______,   _______,   _______,   XXXXXXX,   _______,   _______,   KC_ENT,    KC_BSPC,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX
    ),

    // nav layer triggered by left pinky
    [_NAV🍏] = LAYOUT(
        _______,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   KC_PGUP,   KC_HOME,   KC_UP,     KC_END,    KC_ESC,    XXXXXXX,
        _______,   XXXXXXX,   KC_LALT,   KC_LCMD,   KC_LSFT,   XXXXXXX,   KC_PGDN,   KC_LEFT,   KC_DOWN,   KC_RGHT,   KC_TAB,    XXXXXXX,
        _______,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   _ZOOUT🍏,  _ZOIN🍏,   _BACK🍏,   _FWD🍏,    XXXXXXX,   XXXXXXX,
        _______,   _______,   _______,   XXXXXXX,   _______,   _______,   KC_ENT,    KC_BSPC,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX
    ),

    [_NUM_RIGHT] = LAYOUT(
        _TNPAD,    RALT(KC_Q),RALT(KC_W),RALT(KC_E),RALT(KC_R),RALT(KC_T),RALT(KC_Y),RALT(KC_L),RALT(KC_I),KC_7,      KC_8,      KC_9,
        _______,   RALT(KC_A),RALT(KC_S),RALT(KC_D),RALT(KC_F),RALT(KC_G),RALT(KC_L),RALT(KC_J),RALT(KC_K),KC_4,      KC_5,      KC_6,
        _______,   RALT(KC_Z),RALT(KC_X),RALT(KC_C),RALT(KC_V),RALT(KC_B),RALT(KC_N),RALT(KC_M),XXXXXXX,   KC_1,      KC_2,      KC_3,
        _______,   _______,   _______,   XXXXXXX,   _______,   _______,   _______,   KC_BSPC,   XXXXXXX,   KC_0,      KC_PCMM,   KC_PENT
    ),

    [_NUM_LEFT] = LAYOUT(
        _______,   RALT(KC_D),KC_9,      KC_8,      KC_7,      RALT(KC_T),RALT(KC_Y),RALT(KC_U),RALT(KC_I),RALT(KC_O),RALT(KC_P),_______,
        _______,   RALT(KC_S),KC_3,      KC_2,      KC_1,      RALT(KC_G),RALT(KC_H),RALT(KC_J),RALT(KC_K),RALT(KC_L),XXXXXXX,   _______,
        _______,   RALT(KC_Z),KC_6,      KC_5,      KC_4,      RALT(KC_B),RALT(KC_N),RALT(KC_M),_______,   _______,   _______,   _______,
        _______,   _______,   _______,   XXXXXXX,   KC_0,      _______,   _______,   _______,   XXXXXXX,   _______,   _______,   _______
    ),

    [_FKEYS] = LAYOUT(
        KC_F1,     KC_F2,     KC_F3,     KC_F4,     KC_F5,     KC_F6,     KC_F7,     KC_F8,     KC_F9,     KC_F10,    KC_F11,    KC_F12,
        _______,   XXXXXXX,   KC_PSCR,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,
        _______,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   KC_PGUP,   XXXXXXX,
        _______,   _______,   _______,   KC_MPLY,   _______,   _______,   _______,   _______,   XXXXXXX,   KC_HOME,   KC_PGDN,   KC_END
    ),

    [_BASE_LAYER_SWITCH] = LAYOUT(
        XXXXXXX,   XXXXXXX,   _TOWIN,    XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,
        XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,
        XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   _TOMAC,    XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,
        XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX
    )
};

// Configuration for rotary turns per layer
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][2] = {
    [_BASE]              = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
    [_MAC]               = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
    [_NAV]               = { ENCODER_CCW_CW(KC_NO, KC_NO) },
    [_NAV🍏]              = { ENCODER_CCW_CW(KC_NO, KC_NO) },
    [_NUM_RIGHT]         = { ENCODER_CCW_CW(KC_NO, KC_NO) },
    [_NUM_LEFT]          = { ENCODER_CCW_CW(KC_NO, KC_NO) },
    [_FKEYS]             = { ENCODER_CCW_CW(KC_MPRV, KC_MNXT) },
    [_BASE_LAYER_SWITCH] = { ENCODER_CCW_CW(KC_NO, KC_NO) },
};

/**
 * CHORDAL HOLD / MOD-STACKING LOGIC
 * This function decides IF a hold should be triggered when ANOTHER key is pressed.
 */
bool get_hold_on_other_key_press(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
    case _T1LFT:
    case _T2LFT:
    case _T1RGT:
    case _T2RGT:
        return true;
    default:
        return false;
    }
}

/**
 * PERMISSIVE HOLD (Anti-jd Logic)
 */
bool get_permissive_hold(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case _S:
        case _D:
        case _F:
        case _J:
        case _K:
        case _L:
        case _SCLN:
        case _BSPC:
            return false;
        default:
            return true;
    }
}

// uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
//     switch (keycode) {
//         case _LSFT:
//             return 400;
//         default:
//             return TAPPING_TERM;
//     }
// }

// State variable to track the last pressed alpha key for the Magic Key logic
uint16_t last_keycode = KC_NO;

// Custom behavior and Quick software reset handler
// bool process_record_user(uint16_t keycode, keyrecord_t* record) {
    // // MAGIC KEY INTERCEPT
    // if (keycode == _MAGIC) {
    //     // record->tap.count > 0 means QMK resolved this as a tap, not a hold.
    //     if (record->tap.count > 0) {
    //         if (record->event.pressed) {
    //             switch (last_keycode) {
    //                 case KC_T: // t* → the·
    //                     SEND_STRING("hk ");
    //                     break;
    //                 case KC_W: // w* → which·
    //                     SEND_STRING("hich ");
    //                     break;
    //                 case KC_C: // c* → ctrl
    //                     SEND_STRING("t");
    //                     break;
    //                 case KC_S: // s* → should·
    //                     SEND_STRING("hould ");
    //                     break;
    //                 case KC_G: // g* → git·
    //                     SEND_STRING("it ");
    //                     break;
    //                 case KC_Q: // q* → quand·
    //                     SEND_STRING("uajd ");
    //                     break;
    //                 case KC_Y: // y* → analy
    //                     SEND_STRING("\bajaly");
    //                     break;
    //                 default:
    //                 // tap_code(_1DK);
    //                 break;
    //             }
    //         }
    //         last_keycode = KC_NO;
    //         // Return false on BOTH press and release to completely block the magic key from reaching the OS
    //         return false;
    //     }
    //     // If tap.count == 0, it is a hold. Return true so QMK handles the RALT modifier normally.
    //     return true;
    // }

    // // MAGIC KEY TRACKING: Extract base keycode to track previous tap
    // if (record->event.pressed) {
    //     uint16_t base_keycode = keycode;

    //     // Strip out Layer-Tap and Mod-Tap modifiers to find the actual alpha pressed
    //     if ((keycode >= QK_MOD_TAP && keycode <= QK_MOD_TAP_MAX) ||
    //         (keycode >= QK_LAYER_TAP && keycode <= QK_LAYER_TAP_MAX)) {
    //         base_keycode = keycode & 0xFF;
    //     }

    //     // Only track standard alphas A-Z
    //     if (base_keycode >= KC_A && base_keycode <= KC_Z) {
    //         last_keycode = base_keycode;
    //     }
    //     // Reset tracking on space/backspace/enter to prevent unintended cross-word combos
    //     else { //if (base_keycode == KC_SPACE || base_keycode == KC_BSPC || base_keycode == KC_ENT) {
    //         last_keycode = KC_NO;
    //     }
    // }

//     return true;
// }
