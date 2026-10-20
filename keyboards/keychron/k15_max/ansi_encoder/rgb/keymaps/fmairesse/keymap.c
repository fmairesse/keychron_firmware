#include QMK_KEYBOARD_H
#include "keychron_common.h"

#pragma region Layers
// clang-format off
enum layers {
    MAC_BASE,
    WIN_BASE,
    MAC_FN,
    WIN_FN,
    MAC_NAV,
    WIN_NAV,
    MAC_NAV_LOCKED,
    WIN_NAV_LOCKED,
};

#define _DEFAULT_LAYER MAC_BASE
// clang-format on
#pragma endregion Layers

#pragma region Tap Dance
enum {
    TD_MCTL_🍏,
};

#pragma region Mission Control
static bool mctl_held;
static bool mctl_esc;

static void mctl_each_tap(tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
        // Capture Alt before the tap dance timeout, even if it is released first.
        mctl_esc = (get_mods() & MOD_BIT(KC_RALT)) != 0;
    }
}

static void mctl_finished(tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
        if (state->pressed) {
            mctl_held = true;
            register_code(KC_LCMD);
        } else if (mctl_esc) {
            const uint8_t saved_mods = get_mods();

            del_mods(MOD_BIT(KC_RALT));
            tap_code(KC_ESC);
            set_mods(saved_mods);
            send_keyboard_report();
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
#pragma endregion Mission Control

tap_dance_action_t tap_dance_actions[] = {
    // TD_MCTL_🍏:
    // tapped once: send MCTL,
    // tapped once with T1RGT held: send Esc without Right Alt,
    // tapped twice: send LCTL+DOWN
    // held: send LCMD
    [TD_MCTL_🍏] = ACTION_TAP_DANCE_FN_ADVANCED(mctl_each_tap, mctl_finished, mctl_reset),
};

#pragma endregion Tap Dance

#pragma region Key aliases
// clang-format off

// Shortcuts
#define ZOIN🪟   LCTL(KC_EQUAL)
#define ZOIN🍏   LCMD(KC_EQUAL)
#define ZOOUT🪟  LCTL(KC_MINUS)
#define ZOOUT🍏  LCMD(KC_MINUS)
#define BAK🪟    KC_WBAK
#define BAK🍏    LCMD(KC_LBRC)
#define FWD🪟    KC_WFWD
#define FWD🍏    LCMD(KC_RBRC)
#define LSCR🍏   LCTL(LGUI(KC_Q)) // Lock screen
#define SPTL🍏   LCAG(KC_SPC) // Spotlight
#define PSCR🍏   LCTL(LSFT(LGUI(KC_4)))
#define HOME🍏   LCMD(KC_LEFT)
#define END🍏    LCMD(KC_RIGHT)

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
#define _L       LALT_T(KC_L)
#define _SCLN🪟  LWIN_T(KC_SCLN) // left Win so that Ubuntu triggers "mission control"
#define _SCLN🍏  RCTL_T(KC_SCLN)

#pragma region Thumbs
#define T1LFT🍏  TD(TD_MCTL_🍏)
#define T1LFT🪟  LCTL_T(KC_BSPC)
#define SPC🪟    LT(WIN_NAV, KC_SPC)
#define SPC🍏    LT(MAC_NAV, KC_SPC)
#define T3LFT🪟  MO(WIN_FN)
#define T3LFT🍏  MO(MAC_FN)
#define T1RGT    RALT_T(KC_BSPC)
#define T0RGT    RCMD_T(KC_DEL)
#pragma endregion Thumbs

// Pinkies
#define TAB🍏    LCAG_T(KC_TAB)

// Base layers switchers
#define TOMAC    DF(MAC_BASE)
#define TOWIN    DF(WIN_BASE)

// Nav
#define NV_BSPC  RSFT_T(C(KC_BSPC))

// Renaming
#define TAB KC_TAB

// Nav layer
#define NVLK🪟 TG(WIN_NAV_LOCKED)
#define NVLK🍏 TG(MAC_NAV_LOCKED)
#define NVSPC  LSFT_T(KC_ENT)

// clang-format on
#pragma endregion Key aliases

#pragma region Combos
const uint16_t PROGMEM boot_combo🍏[] = {KC_LCTL, KC_ESC, SPC🍏, COMBO_END};
const uint16_t PROGMEM boot_combo🪟[] = {KC_LGUI, KC_ESC, SPC🪟, COMBO_END};
const uint16_t PROGMEM caps_combo🪟[] = {_D🪟, _K🪟, COMBO_END};
const uint16_t PROGMEM caps_combo🍏[] = {_D🍏, _K🍏, COMBO_END};

combo_t key_combos[] = {
    COMBO(boot_combo🍏, QK_BOOT),
    COMBO(boot_combo🪟, QK_BOOT),
    COMBO(caps_combo🪟, KC_CAPS),
    COMBO(caps_combo🍏, KC_CAPS),
};
#pragma endregion Combos

#pragma region Keymaps
// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [MAC_BASE] = LAYOUT_ansi_90(
        KC_MUTE,   KC_ESC,    KC_F1,     KC_F2,     KC_F3,     KC_F4,     KC_F5,     KC_F6,     KC_F7,     KC_F8,     KC_F9,     KC_F10,    KC_F11,    KC_F12,    KC_INS,               KC_DEL,
        SPTL🍏,    KC_GRV,    KC_1,      KC_2,      KC_3,      KC_4,      KC_5,      KC_6,      KC_7,      KC_8,      KC_9,      KC_0,      KC_MINS,   KC_EQL,    KC_BSPC,              KC_PGDN,
        MC_2,      TAB🍏,     KC_Q,      KC_W,      KC_E,      KC_R,      KC_T,      KC_Y,      KC_U,      KC_I,      KC_O,      KC_P,      KC_LBRC,   KC_RBRC,   KC_BSLS,              HOME🍏,
        KC_CAPS,   KC_ESC,    _A🍏,      _S,        _D🍏,      _F,        KC_G,      KC_H,      _J,        _K🍏,      _L,        _SCLN🍏,   KC_QUOT,              KC_ENT,               END🍏,
        KC_LNPAD,  KC_LSFT,              KC_Z,      KC_X,      KC_C,      KC_V,      KC_B,      KC_B,      KC_N,      KC_M,      KC_COMM,   KC_DOT,    KC_SLSH,   KC_RSFT,   KC_UP,
        KC_MCTRL,  KC_LCTL,   KC_LALT,              T1LFT🍏,   SPC🍏,     T3LFT🍏,                         SPC🍏,                T1RGT,     T0RGT,                KC_LEFT,   KC_DOWN,   KC_RGHT
    ),
    [WIN_BASE] = LAYOUT_ansi_90(
        KC_MUTE,   KC_ESC,    KC_F1,     KC_F2,     KC_F3,     KC_F4,     KC_F5,     KC_F6,     KC_F7,     KC_F8,     KC_F9,     KC_F10,    KC_F11,    KC_F12,    KC_INS,               KC_DEL,
        MC_1,      KC_GRV,    KC_1,      KC_2,      KC_3,      KC_4,      KC_5,      KC_6,      KC_7,      KC_8,      KC_9,      KC_0,      KC_MINS,   KC_EQL,    KC_BSPC,              KC_PGDN,
        MC_2,      KC_TAB,    KC_Q,      KC_W,      KC_E,      KC_R,      KC_T,      KC_Y,      KC_U,      KC_I,      KC_O,      KC_P,      KC_LBRC,   KC_RBRC,   KC_BSLS,              KC_HOME,
        KC_CAPS,   KC_ESC,    _A🪟,      _S,        _D🪟,      _F,        KC_G,      KC_H,      _J,        _K🪟,      _L,        _SCLN🪟,   KC_QUOT,              KC_ENT,               KC_END,
        MC_4,      KC_LSFT,              KC_Z,      KC_X,      KC_C,      KC_V,      KC_B,      KC_B,      KC_N,      KC_M,      KC_COMM,   KC_DOT,    RSFT_T(KC_SLSH),   KC_RSFT,   KC_UP,
        MC_5,      KC_LCTL,   KC_LWIN,              T1LFT🪟,   SPC🪟,     T3LFT🪟,                         SPC🪟,                T1RGT,     KC_RCTL,              KC_LEFT,   KC_DOWN,   KC_RGHT
    ),

    [MAC_FN] = LAYOUT_ansi_90(
        UG_TOGG,   _______,   KC_BRID,   KC_BRIU,   KC_MCTRL,  KC_LNPAD,  UG_VALD,   UG_VALU,   KC_MPRV,   KC_MPLY,   KC_MNXT,   KC_MUTE,   KC_VOLD,   KC_VOLU,   _______,              _______,
        _______,   _______,   BT_HST1,   BT_HST2,   BT_HST3,   P2P4G,     _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,              KC_PGUP,
        _______,   _______,   _______,   TOWIN,     _______,   KC_MCTRL,  _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,              _______,
        _______,   KC_CAPS,   _______,   PSCR🍏,    _______,   _______,   _______,   _______,   _______,   _______,   LSCR🍏,    _______,   _______,              _______,              _______,
        _______,   _______,              _______,   _______,   _______,   _______,   KC_LNPAD,  _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,
        _______,   _______,   _______,              _______,   _______,   _______,                         SPTL🍏,               _______,   _______,              _______,   _______,   _______
    ),
    [WIN_FN] = LAYOUT_ansi_90(
        UG_TOGG,   _______,   KC_BRID,   KC_BRIU,   KC_TASK,   KC_FILE,   UG_VALD,   UG_VALU,   KC_MPRV,   KC_MPLY,   KC_MNXT,   KC_MUTE,   KC_VOLD,   KC_VOLU,   _______,              _______,
        _______,   _______,   BT_HST1,   BT_HST2,   BT_HST3,   P2P4G,     _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,              KC_PGUP,
        _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,              _______,
        _______,   KC_CAPS,   _______,   KC_PSCR,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,              _______,              _______,
        _______,   _______,              _______,   _______,   _______,   _______,   _______,   _______,   _______,   TOMAC,     _______,   _______,   _______,   _______,   _______,
        _______,   _______,   _______,              _______,   _______,   _______,                         _______,              _______,   _______,              _______,   _______,   _______
    ),

    [WIN_NAV] = LAYOUT_ansi_90(
        _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,              _______,
        _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,              _______,
        _______,   _______,   C(S(TAB)), C(TAB),    A(TAB),    XXXXXXX,   XXXXXXX,   KC_PGUP,   KC_HOME,   KC_UP,     KC_END,    KC_ESC,    KC_BSPC,   _______,   _______,              KC_PGUP,
        _______,   _______,   KC_4,      KC_3,      KC_2,      KC_1,      KC_0,      KC_PGDN,   KC_LEFT,   KC_DOWN,   KC_RGHT,   KC_TAB,    KC_ENT,               KC_ENT,               _______,
        _______,   _______,              XXXXXXX,   KC_WBAK,   KC_WFWD,   KC_CAPS,   KC_LWIN,   XXXXXXX,   NVLK🪟,    SELWBAK,   SELLINE,   SELWORD,   _______,   _______,   S(KC_UP),
        _______,   _______,   _______,              _______,   NVSPC,     _______,                         NVSPC,                C(KC_BSPC),C(KC_DEL),            S(KC_LEFT),S(KC_DOWN),S(KC_RIGHT)
    ),
    [MAC_NAV] = LAYOUT_ansi_90(
        _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,              _______,
        _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   KC_BSPC,              _______,
        _______,   _______,   C(S(TAB)), C(TAB),    A(TAB),    KC_LPAD,   SPTL🍏,    KC_PGUP,   HOME🍏,    KC_UP,     END🍏,     KC_ESC,    _______,   _______,   KC_ENT,               KC_PGUP,
        _______,   _______,   KC_4,      KC_3,      KC_2,      KC_1,      KC_0,      KC_PGDN,   KC_LEFT,   KC_DOWN,   KC_RGHT,   KC_TAB,    _______,              _______,              _______,
        _______,   _______,              XXXXXXX,   BAK🍏,     FWD🍏,     KC_CAPS,   KC_LPAD,   XXXXXXX,   NVLK🍏,    SELWBAK,   SELLINE,   SELWORD,   _______,   _______,   S(KC_UP),
        _______,   _______,   _______,              _______,   NVSPC,     _______,                         NVSPC,                A(KC_BSPC),A(KC_DEL),            S(KC_LEFT),S(KC_DOWN),S(KC_RIGHT)
    ),
    [WIN_NAV_LOCKED] = LAYOUT_ansi_90(
        _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,              _______,
        _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,              _______,
        _______,   _______,   C(KC_Y),   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   KC_PGUP,   KC_HOME,   KC_UP,     KC_END,    KC_ESC,    KC_BSPC,   _______,   _______,              KC_PGUP,
        _______,   KC_CAPS,   KC_LWIN,   KC_LALT,   KC_LCTL,   KC_LSFT,   XXXXXXX,   KC_PGDN,   KC_LEFT,   KC_DOWN,   KC_RGHT,   KC_TAB,    KC_ENT,               KC_ENT,               _______,
        _______,   _______,              C(KC_Z),   C(KC_X),   C(KC_C),   C(KC_V),   XXXXXXX,   XXXXXXX,   NVLK🪟,    SELWBAK,   SELLINE,   SELWORD,   _______,   _______,   KC_UP,
        _______,   _______,   _______,              _______,   NVSPC,     _______,                         NVSPC,                C(KC_BSPC),C(KC_DEL),            KC_LEFT,  KC_DOWN,   KC_RIGHT
    ),
    [MAC_NAV_LOCKED] = LAYOUT_ansi_90(
        _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,              _______,
        _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   KC_BSPC,              _______,
        _______,   _______,   G(KC_Y),   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   KC_PGUP,   HOME🍏,    KC_UP,     END🍏,     KC_ESC,    _______,   _______,   KC_ENT,               KC_PGUP,
        _______,   KC_CAPS,   C(S(TAB)), C(TAB),    BAK🍏,     FWD🍏,     XXXXXXX,   KC_PGDN,   KC_LEFT,   KC_DOWN,   KC_RGHT,   KC_TAB,    _______,              _______,              _______,
        _______,   _______,              G(KC_Z),   G(KC_X),   G(KC_C),   G(KC_V),   XXXXXXX,   XXXXXXX,   NVLK🍏,    SELWBAK,   SELLINE,   SELWORD,   _______,   _______,   S(KC_UP),
        _______,   _______,   _______,              _______,   NVSPC,     _______,                         NVSPC,                A(KC_BSPC),A(KC_DEL),            S(KC_LEFT),S(KC_DOWN),S(KC_RIGHT)
    ),
};

const char chordal_hold_layout[MATRIX_ROWS][MATRIX_COLS] PROGMEM =
    LAYOUT_ansi_90(
        '*',       '*',      '*',        '*',       '*',       '*',       '*',       '*',       '*',       '*',       '*',       '*',       '*',       '*',       '*',                  '*',
        '*',       '*',      'L',        'L',       'L',       'L',       'L',       'R',       'R',       'R',       'R',       'R',       'R',       'R',       '*',                  '*',
        '*',       '*',      'L',        'L',       'L',       'L',       'L',       'R',       'R',       'R',       'R',       'R',       'R',       'R',       'R',                  '*',
        '*',       '*',      'L',        'L',       'L',       'L',       'L',       'R',       'R',       'R',       'R',       'R',       'R',                  '*',                  '*',
        '*',       '*',                  'L',       'L',       'L',       'L',       'L',       'R',       'R',       'R',       'R',       'R',       'R',       '*',       '*',
        '*',       '*',      '*',                   '*',       '*',       '*',                             '*',                  '*',       '*',                  '*',       '*',       '*'

    );
// clang-format on
#pragma endregion Keymaps

#pragma region Encoder
// clang-format off
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][2] = {
    [MAC_BASE]       = {ENCODER_CCW_CW(KC_VOLD, KC_VOLU)},
    [MAC_FN]         = {ENCODER_CCW_CW(UG_VALD, UG_VALU)},
    [WIN_BASE]       = {ENCODER_CCW_CW(KC_VOLD, KC_VOLU)},
    [WIN_FN]         = {ENCODER_CCW_CW(UG_VALD, UG_VALU)},
    [WIN_NAV]        = {ENCODER_CCW_CW(KC_VOLD, KC_VOLU)},
    [MAC_NAV]        = {ENCODER_CCW_CW(KC_VOLD, KC_VOLU)},
    [WIN_NAV_LOCKED] = {ENCODER_CCW_CW(KC_VOLD, KC_VOLU)},
    [MAC_NAV_LOCKED] = {ENCODER_CCW_CW(KC_VOLD, KC_VOLU)},
};
// clang-format on
#pragma endregion Encoder

#pragma region Functions
// Set the default layer after keyboard initialization
void keyboard_post_init_user(void) {
    default_layer_set(1UL << _DEFAULT_LAYER);
}

bool process_detected_host_os_user(os_variant_t detected_os) {
    switch (detected_os) {
        case OS_MACOS:
        case OS_IOS:
            default_layer_set(1UL << MAC_BASE);
            break;

        case OS_WINDOWS:
        case OS_LINUX:
            default_layer_set(1UL << WIN_BASE);
            break;

        default:
            break;
    }

    return true;
}

bool get_hold_on_other_key_press(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case T1LFT🪟:
        case T1LFT🍏:
        case SPC🪟:
        case SPC🍏:
        case T1RGT:
            return true;
        default:
            return false;
    }
}


#pragma endregion Functions
