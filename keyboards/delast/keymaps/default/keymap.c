#include QMK_KEYBOARD_H

//#region Layers
enum layers {
    _BASE,
    _NAVLEFT,  // nav layer triggered by left pinky
    _NAVRIGHT, // nav layer triggered by right pinky
    _NUMPAD,
    _NUMROW,
    _FKEYS 
};
//#endregion Layers

//#region Tap Dance
enum {
    TD_CAPSLOCK,
};
tap_dance_action_t tap_dance_actions[] = {
    [TD_CAPSLOCK] = ACTION_TAP_DANCE_DOUBLE(KC_LSFT, KC_CAPS)
};
//#endregion Tap Dance

//#region Aliases

// Left pinkies
#define _ESC    LT(_FKEYS,KC_ESC)
#define _TAB    KC_TAB
#define _LSFT   KC_LSFT

// Left alphas
#define _A      LT(_NAVLEFT,KC_A)
#define _S      LALT_T(KC_S)
#define _D      LCTL_T(KC_D)
#define _F      LSFT_T(KC_F)
#define _V      KC_V

// Right alphas
#define _J      RSFT_T(KC_J)
#define _K      RCTL_T(KC_K)
#define _L      LALT_T(KC_L)
#define _SCLN   LT(_NAVRIGHT,KC_SCLN)
#define _COMM   KC_COMM

// Right pinkies
#define _BSPC   LT(_FKEYS,KC_BSPC)
#define _DEL    RSFT_T(KC_DEL)

// Thumbs
#define _TLEFT1 LCTL_T(KC_NONUS_BACKSLASH)
#define _TLEFT2 LT(_NUMPAD,KC_SPC)
#define _TRGHT2 LT(_NUMROW,KC_SPC)
#define _TRGHT1 RALT_T(KC_LEFT_BRACKET)

// Shortcuts
#define _ZOIN   LCTL(KC_MINUS)
#define _ZOOUT  LCTL(KC_EQUAL)
#define _WBAK   LCTL_T(KC_WBAK)
#define _WFWD   LSFT_T(KC_WFWD)
//#endregion Aliases

//#region Combos
const uint16_t PROGMEM boot_combo[] = {KC_LCTL, _ESC, _TRGHT2, COMBO_END};
const uint16_t PROGMEM slash_combo[] = {KC_DOT, KC_UP, COMBO_END};
const uint16_t PROGMEM caps_combo[] = {KC_LSFT, KC_Z, COMBO_END};
const uint16_t PROGMEM del_combo[] = {_BSPC, KC_P, COMBO_END};

combo_t key_combos[] = {
    COMBO(boot_combo, QK_BOOT),
    COMBO(slash_combo, KC_SLSH),
    COMBO(caps_combo, KC_CAPS),
    COMBO(del_combo, KC_DEL)
};
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
        _LSFT,     KC_Z,      KC_X,      KC_C,      _V,        KC_B,      KC_N,      KC_M,      _COMM,     KC_DOT,    KC_UP,     _DEL,
        KC_LCTL,   KC_LGUI,   KC_LALT,   KC_MUTE,   _TLEFT1,   _TLEFT2,   _TRGHT2,   _TRGHT1,   XXXXXXX,   KC_LEFT,   KC_DOWN,   KC_RGHT
    ),

    // nav layer triggered by left pinky
    [_NAVLEFT] = LAYOUT(
        _______,   XXXXXXX,   XXXXXXX,   _ZOIN,     _ZOOUT,    XXXXXXX,   XXXXXXX,   KC_HOME,   KC_UP,     KC_END,    KC_ESC,    XXXXXXX,
        _______,   XXXXXXX,   KC_LALT,   _WBAK,     _WFWD,     XXXXXXX,   XXXXXXX,   KC_LEFT,   KC_DOWN,   KC_RGHT,   KC_TAB,    XXXXXXX,
        _______,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,
        _______,   _______,   _______,   XXXXXXX,   _______,   _______,   KC_ENT,    KC_BSPC,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX
    ),

    // nav layer triggered by right pinky
    [_NAVRIGHT] = LAYOUT(
        _______,   KC_ESC,    XXXXXXX,   _ZOIN,     _ZOOUT,    XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,
        _______,   KC_TAB,    XXXXXXX,   _WBAK,     _WFWD,     XXXXXXX,   XXXXXXX,   KC_RSFT,   KC_RCTL,   KC_LALT,   XXXXXXX,   XXXXXXX,
        _______,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,
        _______,   _______,   _______,   XXXXXXX,   KC_BSPC,   KC_ENT,    _______,   _______,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX
    ),

    [_NUMPAD] = LAYOUT(
        _______,   RALT(KC_Q),RALT(KC_W),RALT(KC_E),RALT(KC_R),RALT(KC_T),RALT(KC_Y),RALT(KC_U),RALT(KC_I),KC_7,      KC_8,      KC_9,
        _______,   RALT(KC_A),RALT(KC_S),RALT(KC_D),RALT(KC_F),RALT(KC_G),RALT(KC_H),RALT(KC_J),RALT(KC_K),KC_4,      KC_5,      KC_6,
        _______,   RALT(KC_Z),RALT(KC_X),RALT(KC_C),RALT(KC_V),RALT(KC_B),RALT(KC_N),RALT(KC_M),XXXXXXX,   KC_1,      KC_2,      KC_3,
        _______,   _______,   _______,   XXXXXXX,   _______,   _______,   _______,   KC_BSPC,   XXXXXXX,   KC_0,      KC_PCMM,   KC_PENT
    ),

    [_NUMROW] = LAYOUT(
        KC_1,      KC_2,      KC_3,      KC_4,      KC_5,      RALT(KC_T),RALT(KC_Y),RALT(KC_U),RALT(KC_I),RALT(KC_O),RALT(KC_P),_______,
        KC_6,      KC_7,      KC_8,      KC_9,      KC_0,      RALT(KC_G),RALT(KC_H),RALT(KC_J),RALT(KC_K),RALT(KC_L),XXXXXXX,   _______,
        _______,   RALT(KC_Z),RALT(KC_X),RALT(KC_C),RALT(KC_V),RALT(KC_B),RALT(KC_N),RALT(KC_M),_______,   _______,   _______,   _______,
        _______,   _______,   _______,   XXXXXXX,   _______,   _______,   _______,   _______,   XXXXXXX,   _______,   _______,   _______
    ),

    [_FKEYS] = LAYOUT(
        KC_F1,     KC_F2,     KC_F3,     KC_F4,     KC_F5,     KC_F6,     KC_F7,     KC_F8,     KC_F9,     KC_F10,    KC_F11,    KC_F12,
        _______,   XXXXXXX,   KC_PSCR,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,
        _______,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   KC_PGUP,   XXXXXXX,
        _______,   _______,   _______,   KC_MPLY,   _______,   _______,   _______,   _______,   XXXXXXX,   KC_HOME,   KC_PGDN,   KC_END
    )
};

// Configuration for rotary turns per layer
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][2] = {
    [_BASE]    = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
    [_NAVLEFT] = { ENCODER_CCW_CW(KC_NO, KC_NO) },
    [_NAVRIGHT]= { ENCODER_CCW_CW(KC_NO, KC_NO) },
    [_NUMPAD]  = { ENCODER_CCW_CW(KC_NO, KC_NO) },
    [_NUMROW]  = { ENCODER_CCW_CW(KC_NO, KC_NO) },
    [_FKEYS]   = { ENCODER_CCW_CW(KC_MPRV, KC_MNXT) }
};

/**
 * CHORDAL HOLD / MOD-STACKING LOGIC
 * This function decides IF a hold should be triggered when ANOTHER key is pressed.
 */
bool get_hold_on_other_key_press(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
    case _TLEFT1:
    case _TLEFT2:
    case _TRGHT1:
    case _TRGHT2:
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

// Quick software reset handler
bool process_record_user(uint16_t keycode, keyrecord_t* record) {
  if (keycode == QK_BOOT && record->event.pressed) {
      reset_keyboard();
  }
  return true;
}
