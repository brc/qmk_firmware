#include QMK_KEYBOARD_H
#include "version.h"
/* #include "keymap_german.h" */
/* #include "keymap_nordic.h" */
/* #include "keymap_french.h" */
/* #include "keymap_spanish.h" */
/* #include "keymap_hungarian.h" */
/* #include "keymap_swedish.h" */
/* #include "keymap_br_abnt2.h" */
/* #include "keymap_canadian_multilingual.h" */
/* #include "keymap_german_ch.h" */
/* #include "keymap_jp.h" */
/* #include "keymap_bepo.h" */
/* #include "keymap_italian.h" */
/* #include "keymap_slovenian.h" */
/* #include "keymap_danish.h" */
/* #include "keymap_norwegian.h" */
/* #include "keymap_portuguese.h" */
/* #include "keymap_contributions.h" */
/* #include "keymap_czech.h" */
/* #include "keymap_romanian.h" */
/* #include "keymap_russian.h" */
/* #include "keymap_uk.h" */
/* #include "keymap_estonian.h" */

#define KC_MAC_UNDO LGUI(KC_Z)
#define KC_MAC_CUT LGUI(KC_X)
#define KC_MAC_COPY LGUI(KC_C)
#define KC_MAC_PASTE LGUI(KC_V)
#define KC_PC_UNDO LCTL(KC_Z)
#define KC_PC_CUT LCTL(KC_X)
#define KC_PC_COPY LCTL(KC_C)
#define KC_PC_PASTE LCTL(KC_V)
#define ES_LESS_MAC KC_GRAVE
#define ES_GRTR_MAC LSFT(KC_GRAVE)
#define ES_BSLS_MAC ALGR(KC_6)
#define NO_PIPE_ALT KC_GRAVE
#define NO_BSLS_ALT KC_EQUAL
#define LSA_T(kc) MT(MOD_LSFT | MOD_LALT, kc)
#define BP_NDSH_MAC ALGR(KC_8)

enum custom_keycodes {
  RGB_SLD = EZ_SAFE_RANGE,
  ST_MACRO_0,
  ST_MACRO_1,
  ST_MACRO_2,
  ST_MACRO_3,
  ST_MACRO_4,
  ST_MACRO_5,
  ST_MACRO_6,
  ST_MACRO_7,
  ST_MACRO_8,
  ST_MACRO_9,
  ST_MACRO_10,
  ST_MACRO_11,
  ST_MACRO_12,
  ST_MACRO_13,
  ST_MACRO_14,
  ST_MACRO_15,
  ST_MACRO_16,
  ST_MACRO_17,
  ST_MACRO_18,
  ST_MACRO_19,
  ST_MACRO_20,
  ST_MACRO_21,
  ST_MACRO_22,
  ST_MACRO_23,
  ST_MACRO_24,
  ST_MACRO_25,
  ST_MACRO_26,
  ST_MACRO_27,
  ST_MACRO_28,
  ST_MACRO_29,
  ST_MACRO_30,
  ST_MACRO_31,
  ST_MACRO_32,
  ST_MACRO_33,
  ST_MACRO_34,
  ST_MACRO_35,
  ST_MACRO_36,
  ST_MACRO_37,
  ST_MACRO_38,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT_ergodox_pretty(
    KC_ESCAPE,      KC_HASH,        KC_DLR,         KC_LPRN,        KC_LBRACKET,    KC_PERC,        KC_EXLM,                                        KC_ASTR,        KC_CIRC,        KC_RBRACKET,    KC_RPRN,        KC_EQUAL,       KC_DQUO,        KC_ESCAPE,
    KC_ESCAPE,      KC_SLASH,       KC_COMMA,       KC_DOT,         KC_P,           KC_Y,           LT(2,KC_TAB),                                   KC_BSPACE,      KC_F,           KC_G,           KC_C,           KC_R,           KC_L,           KC_PLUS,
    KC_PIPE,        KC_A,           KC_O,           KC_E,           KC_U,           KC_I,                                                                           KC_D,           KC_H,           KC_T,           KC_N,           KC_S,           KC_MINUS,
    OSL(4),         KC_SCOLON,      KC_Q,           KC_J,           KC_K,           KC_X,           KC_ENTER,                                       KC_ENTER,       KC_B,           KC_M,           KC_W,           KC_V,           KC_Z,           OSL(4),
    KC_DELETE,      KC_COLN,        KC_AT,          KC_AMPR,        LCTL_T(KC_SPACE),                                                                                                OSL(3),         KC_DOWN,        KC_LEFT,        KC_RIGHT,       OSM(MOD_RCTL),
                                                                                                    KC_AUDIO_VOL_DOWN,KC_AUDIO_VOL_UP,KC_INSERT,      KC_INSERT,
                                                                                                                    KC_TRANSPARENT, KC_PGUP,
                                                                                    LSFT_T(KC_SPACE),KC_LGUI,        OSL(1),         KC_PGDOWN,      KC_RGUI,        RSFT_T(KC_SPACE)
  ),
  [1] = LAYOUT_ergodox_pretty(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_NUMLOCK,     KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_7,           KC_8,           KC_9,           KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                                                 KC_TRANSPARENT, KC_4,           KC_5,           KC_6,           KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_1,           KC_2,           KC_3,           KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                                                                                 KC_0,           KC_TRANSPARENT, KC_KP_DOT,      KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                                    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                                                    KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
  ),
  [2] = LAYOUT_ergodox_pretty(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_F10,         KC_F11,         KC_F12,         KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_F7,          KC_F8,          KC_F9,          KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                                                 KC_TRANSPARENT, KC_F4,          KC_F5,          KC_F6,          KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_F1,          KC_F2,          KC_F3,          KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                                                                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                                    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                                                    KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
  ),
  [3] = LAYOUT_ergodox_pretty(
    KC_PGUP,        KC_TRANSPARENT, KC_TRANSPARENT, KC_SCROLLLOCK,  KC_PSCREEN,     KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_PGDOWN,      KC_BSLASH,      KC_TRANSPARENT, KC_HOME,        KC_END,         KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_GRAVE,       KC_TILD,        KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_HASH,        KC_LEFT,        KC_RIGHT,       KC_UNDS,                                                                        KC_TRANSPARENT, KC_QUOTE,       KC_DQUO,        KC_BSLASH,      KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_COLN,        KC_DOWN,        KC_UP,          KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_UNDS,        KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_CIRC,        KC_ESCAPE,                                                                                                      KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                                    KC_BRIGHTNESS_DOWN,KC_BRIGHTNESS_UP,KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                                                    KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
  ),
  [4] = LAYOUT_ergodox_pretty(
    KC_TRANSPARENT, ST_MACRO_0,     KC_TRANSPARENT, ST_MACRO_1,     ST_MACRO_2,     KC_TRANSPARENT, ST_MACRO_3,                                     ST_MACRO_19,    KC_TRANSPARENT, ST_MACRO_20,    KC_TRANSPARENT, ST_MACRO_21,    KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, ST_MACRO_4,     ST_MACRO_5,     ST_MACRO_6,     ST_MACRO_7,     KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, ST_MACRO_22,    KC_TRANSPARENT, ST_MACRO_23,    ST_MACRO_24,    ST_MACRO_25,    ST_MACRO_26,
    ST_MACRO_8,     ST_MACRO_9,     ST_MACRO_10,    KC_TRANSPARENT, ST_MACRO_11,    KC_TRANSPARENT,                                                                 ST_MACRO_27,    ST_MACRO_28,    ST_MACRO_29,    ST_MACRO_30,    KC_TRANSPARENT, ST_MACRO_31,
    KC_TRANSPARENT, KC_TRANSPARENT, ST_MACRO_12,    ST_MACRO_13,    ST_MACRO_14,    KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, ST_MACRO_32,    KC_TRANSPARENT, ST_MACRO_33,    ST_MACRO_34,    KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, ST_MACRO_15,    ST_MACRO_16,                                                                                                    ST_MACRO_35,    ST_MACRO_36,    ST_MACRO_37,    ST_MACRO_38,    KC_TRANSPARENT,
                                                                                                    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                                                    KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                    ST_MACRO_17,    KC_TRANSPARENT, ST_MACRO_18,    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
  ),
};


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case ST_MACRO_0:
    if (record->event.pressed) {
      SEND_STRING(SS_LALT(SS_TAP(X_T)) SS_DELAY(100) SS_LSFT(SS_TAP(X_3)));

    }
    break;
    case ST_MACRO_1:
    if (record->event.pressed) {
      SEND_STRING(SS_LALT(SS_TAP(X_T)) SS_DELAY(100) SS_LSFT(SS_TAP(X_R)));

    }
    break;
    case ST_MACRO_2:
    if (record->event.pressed) {
      SEND_STRING(SS_LALT(SS_TAP(X_T)) SS_DELAY(100) SS_LSFT(SS_TAP(X_LBRACKET)));

    }
    break;
    case ST_MACRO_3:
    if (record->event.pressed) {
      SEND_STRING(SS_LALT(SS_TAP(X_T)) SS_DELAY(100) SS_LSFT(SS_TAP(X_1)));

    }
    break;
    case ST_MACRO_4:
    if (record->event.pressed) {
      SEND_STRING(SS_LALT(SS_TAP(X_T)) SS_DELAY(100) SS_LSFT(SS_TAP(X_SLASH)));

    }
    break;
    case ST_MACRO_5:
    if (record->event.pressed) {
      SEND_STRING(SS_LALT(SS_TAP(X_T)) SS_DELAY(100) SS_TAP(X_COMMA));

    }
    break;
    case ST_MACRO_6:
    if (record->event.pressed) {
      SEND_STRING(SS_LALT(SS_TAP(X_T)) SS_DELAY(100) SS_TAP(X_DOT));

    }
    break;
    case ST_MACRO_7:
    if (record->event.pressed) {
      SEND_STRING(SS_LALT(SS_TAP(X_T)) SS_DELAY(100) SS_LALT(SS_TAP(X_P)));

    }
    break;
    case ST_MACRO_8:
    if (record->event.pressed) {
      SEND_STRING(SS_LALT(SS_TAP(X_T)) SS_DELAY(100) SS_LSFT(SS_TAP(X_BSLASH)));

    }
    break;
    case ST_MACRO_9:
    if (record->event.pressed) {
      SEND_STRING(SS_LALT(SS_TAP(X_T)) SS_DELAY(100) SS_TAP(X_A));

    }
    break;
    case ST_MACRO_10:
    if (record->event.pressed) {
      SEND_STRING(SS_LALT(SS_TAP(X_T)) SS_DELAY(100) SS_LCTL(SS_TAP(X_O)));

    }
    break;
    case ST_MACRO_11:
    if (record->event.pressed) {
      SEND_STRING(SS_LALT(SS_TAP(X_T)) SS_DELAY(100) SS_LALT(SS_TAP(X_T)));

    }
    break;
    case ST_MACRO_12:
    if (record->event.pressed) {
      SEND_STRING(SS_LALT(SS_TAP(X_T)) SS_DELAY(100) SS_LSFT(SS_TAP(X_SCOLON)));

    }
    break;
    case ST_MACRO_13:
    if (record->event.pressed) {
      SEND_STRING(SS_LALT(SS_TAP(X_T)) SS_DELAY(100) SS_TAP(X_J));

    }
    break;
    case ST_MACRO_14:
    if (record->event.pressed) {
      SEND_STRING(SS_LALT(SS_TAP(X_T)) SS_DELAY(100) SS_TAP(X_K));

    }
    break;
    case ST_MACRO_15:
    if (record->event.pressed) {
      SEND_STRING(SS_LALT(SS_TAP(X_T)) SS_DELAY(100) SS_LSFT(SS_TAP(X_7)));

    }
    break;
    case ST_MACRO_16:
    if (record->event.pressed) {
      SEND_STRING(SS_LALT(SS_TAP(X_T)) SS_DELAY(100) SS_TAP(X_PGUP));

    }
    break;
    case ST_MACRO_17:
    if (record->event.pressed) {
      SEND_STRING(SS_LALT(SS_TAP(X_T)) SS_DELAY(100) SS_TAP(X_SPACE));

    }
    break;
    case ST_MACRO_18:
    if (record->event.pressed) {
      SEND_STRING(SS_LALT(SS_TAP(X_T)) SS_DELAY(100) SS_TAP(X_Q));

    }
    break;
    case ST_MACRO_19:
    if (record->event.pressed) {
      SEND_STRING(SS_LALT(SS_TAP(X_T)) SS_DELAY(100) SS_LALT(SS_TAP(X_S)));

    }
    break;
    case ST_MACRO_20:
    if (record->event.pressed) {
      SEND_STRING(SS_LALT(SS_TAP(X_T)) SS_DELAY(100) SS_LSFT(SS_TAP(X_RBRACKET)));

    }
    break;
    case ST_MACRO_21:
    if (record->event.pressed) {
      SEND_STRING(SS_LALT(SS_TAP(X_T)) SS_DELAY(100) SS_TAP(X_EQUAL));

    }
    break;
    case ST_MACRO_22:
    if (record->event.pressed) {
      SEND_STRING(SS_LALT(SS_TAP(X_T)) SS_DELAY(100) SS_TAP(X_F));

    }
    break;
    case ST_MACRO_23:
    if (record->event.pressed) {
      SEND_STRING(SS_LALT(SS_TAP(X_T)) SS_DELAY(100) SS_TAP(X_C));

    }
    break;
    case ST_MACRO_24:
    if (record->event.pressed) {
      SEND_STRING(SS_LALT(SS_TAP(X_T)) SS_DELAY(100) SS_LALT(SS_TAP(X_R)));

    }
    break;
    case ST_MACRO_25:
    if (record->event.pressed) {
      SEND_STRING(SS_LALT(SS_TAP(X_T)) SS_DELAY(100) SS_TAP(X_L));

    }
    break;
    case ST_MACRO_26:
    if (record->event.pressed) {
      SEND_STRING(SS_LALT(SS_TAP(X_T)) SS_DELAY(100) SS_LSFT(SS_TAP(X_EQUAL)));

    }
    break;
    case ST_MACRO_27:
    if (record->event.pressed) {
      SEND_STRING(SS_LALT(SS_TAP(X_T)) SS_DELAY(100) SS_LALT(SS_TAP(X_D)));

    }
    break;
    case ST_MACRO_28:
    if (record->event.pressed) {
      SEND_STRING(SS_LALT(SS_TAP(X_T)) SS_DELAY(100) SS_TAP(X_H));

    }
    break;
    case ST_MACRO_29:
    if (record->event.pressed) {
      SEND_STRING(SS_LALT(SS_TAP(X_T)) SS_DELAY(100) SS_TAP(X_T));

    }
    break;
    case ST_MACRO_30:
    if (record->event.pressed) {
      SEND_STRING(SS_LALT(SS_TAP(X_T)) SS_DELAY(100) SS_LALT(SS_TAP(X_N)));

    }
    break;
    case ST_MACRO_31:
    if (record->event.pressed) {
      SEND_STRING(SS_LALT(SS_TAP(X_T)) SS_DELAY(100) SS_TAP(X_MINUS));

    }
    break;
    case ST_MACRO_32:
    if (record->event.pressed) {
      SEND_STRING(SS_LALT(SS_TAP(X_T)) SS_DELAY(100) SS_LALT(SS_TAP(X_B)));

    }
    break;
    case ST_MACRO_33:
    if (record->event.pressed) {
      SEND_STRING(SS_LALT(SS_TAP(X_T)) SS_DELAY(100) SS_TAP(X_W));

    }
    break;
    case ST_MACRO_34:
    if (record->event.pressed) {
      SEND_STRING(SS_LALT(SS_TAP(X_T)) SS_DELAY(100) SS_LALT(SS_TAP(X_H)));

    }
    break;
    case ST_MACRO_35:
    if (record->event.pressed) {
      SEND_STRING(SS_LALT(SS_TAP(X_T)) SS_DELAY(100) SS_LCTL(SS_TAP(X_UP)));

    }
    break;
    case ST_MACRO_36:
    if (record->event.pressed) {
      SEND_STRING(SS_LALT(SS_TAP(X_T)) SS_DELAY(100) SS_LCTL(SS_TAP(X_DOWN)));

    }
    break;
    case ST_MACRO_37:
    if (record->event.pressed) {
      SEND_STRING(SS_LALT(SS_TAP(X_T)) SS_DELAY(100) SS_LCTL(SS_TAP(X_LEFT)));

    }
    break;
    case ST_MACRO_38:
    if (record->event.pressed) {
      SEND_STRING(SS_LALT(SS_TAP(X_T)) SS_DELAY(100) SS_LCTL(SS_TAP(X_RIGHT)));

    }
    break;
  }
  return true;
}

uint32_t layer_state_set_user(uint32_t state) {
  uint8_t layer = biton32(state);
  ergodox_board_led_off();
  ergodox_right_led_1_off();
  ergodox_right_led_2_off();
  ergodox_right_led_3_off();
  switch (layer) {
    case 1:
      ergodox_right_led_1_on();
      break;
    case 2:
      ergodox_right_led_2_on();
      break;
    case 3:
      ergodox_right_led_3_on();
      break;
    case 4:
      ergodox_right_led_1_on();
      ergodox_right_led_2_on();
      break;
    case 5:
      ergodox_right_led_1_on();
      ergodox_right_led_3_on();
      break;
    case 6:
      ergodox_right_led_2_on();
      ergodox_right_led_3_on();
      break;
    case 7:
      ergodox_right_led_1_on();
      ergodox_right_led_2_on();
      ergodox_right_led_3_on();
      break;
    default:
      break;
  }
  return state;
};
