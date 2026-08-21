#pragma once

#define TAPPING_TERM 200
#define TAPPING_TERM_PER_KEY
#define PERMISSIVE_HOLD
#define PERMISSIVE_HOLD_PER_KEY
#define CHORDAL_HOLD

/* Enable Chordal Hold logic */
#define HOLD_ON_OTHER_KEY_PRESS_PER_KEY

/* Flash Safety: Hold Escape (0,0) while plugging in to enter bootloader */
#define BOOTMAGIC_LITE_ROW 0
#define BOOTMAGIC_LITE_COLUMN 0

#define COMBO_TERM 50 // Time (in ms) that keys must be pressed to register as a combo
#define COMBO_MUST_HOLD_PER_COMBO // Only trigger combos if all keys are held, not just tapped

#define ONESHOT_TAP_TOGGLE 2  /* Tapping this number of times holds the key until tapped once again. */
#define ONESHOT_TIMEOUT 2000  /* Time (in ms) before the one shot key is released */
