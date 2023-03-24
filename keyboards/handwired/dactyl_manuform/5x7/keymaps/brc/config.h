/*
  Set any config.h overrides for your specific keymap here.
  See config.h options at https://docs.qmk.fm/#/config_options?id=the-configh-file
*/

#pragma once

#define USE_SERIAL

//#define EE_HANDS
//#define MASTER_LEFT
#define MASTER_RIGHT

#undef TAPPING_TERM
#define TAPPING_TERM 150

#undef ONESHOT_TIMEOUT
#define ONESHOT_TIMEOUT 2038

// https://docs.qmk.fm/#/tap_hold?id=tapping-term
// https://docs.qmk.fm/#/tap_hold?id=ignore-mod-tap-interrupt
// https://docs.qmk.fm/#/tap_hold?id=permissive-hold
// https://docs.qmk.fm/#/tap_hold?id=hold-on-other-key-press
#define TAPPING_TERM_PER_KEY
#define IGNORE_MOD_TAP_INTERRUPT_PER_KEY
#define PERMISSIVE_HOLD_PER_KEY
#define HOLD_ON_OTHER_KEY_PRESS_PER_KEY
