#pragma once

#pragma once

#define RGBLIGHT_LAYERS
#define RGBLIGHT_LAYERS_OVERRIDE_RGB_OFF
#define RGBLIGHT_LAYERS_RETAIN_VAL
#define RGBLIGHT_DEFAULT_VAL 128
#define RGBLIGHT_DEFAULT_MODE RGBLIGHT_MODE_RAINBOW_SWIRL + 5
#define RGBLIGHT_SLEEP
/*== customize breathing effect ==*/
// #    define RGBLIGHT_BREATHE_TABLE_SIZE 150
// #    define RGBLIGHT_EFFECT_BREATHE_CENTER 1.0
// #    define RGBLIGHT_EFFECT_BREATHE_MAX    60

#define TAPPING_TERM 175
#define TAPPING_TERM_PER_KEY
#define PERMISSIVE_HOLD
#define PERMISSIVE_HOLD_PER_KEY
#define CHORDAL_HOLD
#define HOLD_ON_OTHER_KEY_PRESS
#define HOLD_ON_OTHER_KEY_PRESS_PER_KEY


/* Flash Safety: Hold Escape while plugging in to enter bootloader */
#define BOOTMAGIC_LITE_ROW 0
#define BOOTMAGIC_LITE_COLUMN 0

// #define COMBO_TERM 50 // Time (in ms) that keys must be pressed to register as a combo
// #define COMBO_MUST_HOLD_PER_COMBO // Only trigger combos if all keys are held, not just tapped

// #define ONESHOT_TAP_TOGGLE 2  /* Tapping this number of times holds the key until tapped once again. */
// #define ONESHOT_TIMEOUT 2000  /* Time (in ms) before the one shot key is released */
