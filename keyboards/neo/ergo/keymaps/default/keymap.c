#include QMK_KEYBOARD_H

//#region Layers
enum layers {
    MAC_BASE,
    WIN_BASE,
    MAC_FN,
    WIN_FN,
    MAC_NAV,
    WIN_NAV,
    NUM,
    VOID
};
// #endregion Layers


//#region Tap Dance
enum {
    TD_MCTL_🍏,
    TD_T1LFT,
};

static bool mission_control_held;

static void mission_control_finished(tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
        if (state->pressed) {
            mission_control_held = true;
            register_code(KC_LCMD);
        } else {
            tap_code(KC_MCTL);
        }
    } else if (state->count == 2) {
        tap_code16(LCTL(KC_DOWN));
    }
}

static void mission_control_reset(tap_dance_state_t *state, void *user_data) {
    if (mission_control_held) {
        unregister_code(KC_LCMD);
        mission_control_held = false;
    }
}

//#region Tap dance for T1LFT
// tapped once: oneshot shift,
// held: send LALT
static bool t1lft_held;

static void t1lft_finished(tap_dance_state_t *state, void *user_data) {
    if (state->pressed) {
        t1lft_held = true;
        register_code(KC_LALT);
        // if (state->index == _TD_T1LFT_MAC) {
        //     t1lft_mac_held = true;
        //     register_code(KC_LCMD);
        // } else {
        // }
    } else {
        set_oneshot_mods(MOD_BIT(KC_LSFT));
    }
}

static void t1lft_reset(tap_dance_state_t *state, void *user_data) {
    if (t1lft_held) {
        unregister_code(KC_LALT);
        t1lft_held = false;
    }
    // if (t1lft_mac_held) {
    //     unregister_code(KC_LCMD);
    //     t1lft_mac_held = false;
    // }
}

//#endregion Tap dance for T1LFT

tap_dance_action_t tap_dance_actions[] = {
    // TD_MCTL_🍏:
    // tapped once: send MCTL,
    // tapped twice: send LCTL+DOWN (to hide mission control)
    // held: send LCMD
    [TD_MCTL_🍏]   = ACTION_TAP_DANCE_FN_ADVANCED(NULL, mission_control_finished, mission_control_reset),
    [TD_T1LFT]    = ACTION_TAP_DANCE_FN_ADVANCED(NULL, t1lft_finished, t1lft_reset),
};
//#endregion Tap Dance

//#region Aliases
// #define _TNPAD   TG(_NUM_RIGHT)
// #define _1DK     KC_LEFT_BRACKET
// // #define _MAGIC  _RSFT

// // Left pinkies
#define ESC🪟    LT(WIN_FN,KC_ESC)
#define ESC🍏    LT(MAC_FN,KC_ESC)

// Left alphas
#define _A🪟     LT(WIN_NAV,KC_A)
#define _A🍏     LT(MAC_NAV,KC_A)
#define _S       LALT_T(KC_S)
#define _D🪟     LCTL_T(KC_D)
#define _D🍏     LCMD_T(KC_D)
#define _F       LSFT_T(KC_F)
#define _V       KC_V

// Right alphas
#define _J       RSFT_T(KC_J)
#define _K🪟     RCTL_T(KC_K)
#define _K🍏     RCMD_T(KC_K)
#define _L       LALT_T(KC_L)
#define _SCLN    LT(NAV,KC_SEMICOLON)
#define _COMM    KC_COMM

// Right pinkies
#define BSPC🪟   LT(WIN_FN,KC_BSPC)
#define BSPC🍏   LT(MAC_FN,KC_BSPC)

// Last row
#define T1LFT   TD(TD_T1LFT)
#define T2LFT🪟 RCTL_T(KC_SPC)
#define T2LFT🍏 RCMD_T(KC_SPC)
#define T2RGT   KC_SPC //LT(_NUM_LEFT,KC_SPC)
#define T1RGT   RALT_T(KC_LEFT_BRACKET)

// Shortcuts
#define ZOIN🪟  LCTL(KC_EQUAL)
#define ZOIN🍏  LCMD(KC_EQUAL)
#define ZOOUT🪟 LCTL(KC_MINUS)
#define ZOOUT🍏 LCMD(KC_MINUS)
#define BAK🪟   LCTL_T(KC_WBAK)
#define BAK🍏   LCMD(KC_LBRC)
#define FWD🪟   LSFT_T(KC_WFWD)
#define FWD🍏   LCMD(KC_RBRC)
#define MCTL🍏  TD(TD_MCTL_🍏) // Mission control
#define LSCR🍏  LCTL(LGUI(KC_Q)) // Lock screen
#define LPAD🍏  LCTL(LGUI(LALT(KC_B)))

// //Base layer switch
#define TOMAC   DF(MAC_BASE)
#define TOWIN   DF(WIN_BASE)
//#endregion Aliases

// #region Combos
enum combo_events { BOOT_COMBO🪟, BOOT_COMBO🍏 };

const uint16_t PROGMEM boot_combo🪟[]     = {KC_LCTL, ESC🪟, T2RGT, COMBO_END};
const uint16_t PROGMEM boot_combo🍏[]     = {KC_LCTL, ESC🍏, T2RGT, COMBO_END};

combo_t key_combos[] = {
    [BOOT_COMBO🪟]       = COMBO(boot_combo🪟, QK_BOOT),
    [BOOT_COMBO🍏]       = COMBO(boot_combo🍏, QK_BOOT),
};
// #endregion Combos

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [MAC_BASE] = LAYOUT(
        KC_DEL,  ESC🍏,   KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_NUHS, BSPC🍏,
        KC_PGUP, KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS,
        KC_PGDN, KC_ESC,  _A🍏,    _S,      _D🍏,    _F,      KC_G,    KC_H,    _J,      _K🍏,    _L,      KC_SCLN, KC_QUOT,          KC_ENT,
        XXXXXXX, KC_LSFT, KC_NUBS, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_UP,   KC_RSFT,
                 KC_LCTL, MCTL🍏,                             T1LFT,   T2LFT🍏, T2RGT,   T1RGT,                              KC_LEFT, KC_DOWN, KC_RGHT
    ),
    [WIN_BASE] = LAYOUT(
        KC_DEL,  ESC🪟,   KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_NUHS, BSPC🪟,
        KC_PGUP, KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS,
        KC_PGDN, KC_ESC,  _A🪟,    _S,      _D🪟,    _F,      KC_G,    KC_H,    _J,      _K🪟,    _L,      KC_SCLN, KC_QUOT,          KC_ENT,
        XXXXXXX, KC_LSFT, KC_NUBS, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_UP,   KC_RSFT,
                 KC_LCTL, KC_LGUI,                            T1LFT,   T2LFT🪟, T2RGT,   T1RGT,                              KC_LEFT, KC_DOWN, KC_RGHT
    ),


    [MAC_FN] = LAYOUT(
        _______, _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  _______, _______,
        _______, _______, _______, TOWIN,   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, TOMAC,   _______, _______, _______, _______, _______,
        _______, _______,                   _______, _______, _______, _______,                                     _______, _______, _______
    ),
    [WIN_FN] = LAYOUT(
        _______, _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  _______, _______,
        _______, _______, _______, TOWIN,   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, TOMAC,   _______, _______, _______, _______, _______,
        _______, _______,                   _______, _______, _______, _______,                                     _______, _______, _______
    ),

    [MAC_NAV] = LAYOUT(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, KC_ESC,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_PGUP, KC_HOME, KC_UP,   KC_END,  KC_ESC,  _______, _______, _______,
        _______, _______, KC_TAB,  KC_LALT, KC_LCTL, KC_LSFT, XXXXXXX, KC_PGDN, KC_LEFT, KC_DOWN, KC_RGHT, KC_TAB,  _______,          _______,
        _______, _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, ZOOUT🍏, ZOIN🍏,  BAK🍏,   FWD🍏,   _______, _______, _______, _______,
        _______, _______,                            _______, _______, KC_ENT,  KC_BSPC,                            _______, _______, _______
    ),
    [WIN_NAV] = LAYOUT(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, KC_ESC,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_PGUP, KC_HOME, KC_UP,   KC_END,  KC_ESC,  _______, _______, _______,
        _______, _______, KC_TAB,  KC_LALT, KC_LCTL, KC_LSFT, XXXXXXX, KC_PGDN, KC_LEFT, KC_DOWN, KC_RGHT, KC_TAB,  _______,          _______,
        _______, _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, ZOOUT🪟, ZOIN🪟,  BAK🪟,   FWD🪟,   _______, _______, _______, _______,
        _______, _______,                            _______, _______, KC_ENT,  KC_BSPC,                            _______, _______, _______
    ),

    [NUM] = LAYOUT(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, KC_3,    KC_2,    KC_1,    _______, _______, _______, _______, _______, _______, _______,          _______,
        _______, _______, _______, _______, _______, KC_0,    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
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


bool get_hold_on_other_key_press(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
    case T1LFT:
    case T1RGT:
        return true;
    default:
        return false;
    }
}

/**
 * PERMISSIVE HOLD
 * Chordal Hold already settles same-hand rolls as taps, so home row mods
 * don't need Permissive Hold disabled; doing so only breaks the
 * opposite-hand nested-tap case Permissive Hold is meant to catch.
 */
bool get_permissive_hold(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case T2RGT:
            return false;
        default:
            return true;
    }
}

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case T2RGT:
            return TAPPING_TERM + 30;
        default:
            return TAPPING_TERM;
    }
}
