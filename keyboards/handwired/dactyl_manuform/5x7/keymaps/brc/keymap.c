#include QMK_KEYBOARD_H

#define TMUX_PREFIX SS_LALT(SS_TAP(X_T) SS_DELAY(10))

#define SPACEMACS_DELAY 10
#define SPACEMACS_LEADER SS_TAP(X_SPC) SS_DELAY(SPACEMACS_DELAY)

enum custom_keycodes {
    SHFT_INS = SAFE_RANGE,

    /* Tmux macros
     */

    // Windows
    TM_NEWW,  // Create window
    TM_APPW,  // Create adjacent window and shift others ("append")
    TM_NXTW,  // Next window
    TM_PRVW,  // Previous window
    TM_ALTW,  // Alternate window
    TM_SELW,  // Choose window
    TM_MOVW,  // Move window
    TM_RENW,  // Rename window
    TM_NUMW,  // Renumber windows
    TM_ROTW,  // Rotate window downward
    TM_FNDW,  // Find window
    TM_SPLH,  // Split window horizontally
    TM_SPLV,  // Split window vertically

    // Panes
    TM_UPP,   // Select pane above
    TM_DWNP,  // Select pane below
    TM_RGHT,  // Select pane to right
    TM_LEFT,  // Select pane to left
    TM_ALTP,  // Alternate pane
    TM_DISP,  // Display panes
    TM_EQLP,  // Balance panes
    TM_NXTL,  // Cycle next pane layout
    TM_SWPU,  // Swap pane up/left
    TM_SWPD,  // Swap pane down/right
    TM_SYNC,  // Synchronize panes
    TM_ZOOM,  // Maximize pane
    TM_MAXV,  // Maximize pane vertically
    TM_UNDO,  // Restore previous layout
    TM_MARK,  // Mark pane
    TM_BRKP,  // Break pane
    TM_JOIN,  // Join pane

    // Misc
    TM_COPY,  // Enter copy mode
    TM_CPUP,  // Enter copy mode and scroll up one page
    TM_PUTB,  // Paste buffer
    TM_SELB,  // Choose buffer
    TM_RENB,  // Rename buffer
    TM_DELB,  // Delete buffer
    TM_CMD,   // Enter command prompt
    TM_HELP,  // List key bindings

    /* X11 WM macros
     */
    X_MINMZ,  // Iconify window
    X_MAXMZ,  // Maximize window
    X_MAX_H,  // Maximize horizontally
    X_MAX_V,  // Maximize vertically
    X_QT_N,   // Quick Tile above
    X_QT_S,   // Quick Tile below
    X_QT_E,   // Quick Tile right
    X_QT_W,   // Quick Tile left
    X_QT_NW,  // Quick Tile upper-left corner
    X_QT_NE,  // Quick Tile upper-right corner
    X_QT_SE,  // Quick Tile lower-right corner
    X_QT_SW,  // Quick Tile lower-left corner
    X_SHADE,  // Shade window
    X_RAISE,  // Raise window
    X_LOWER,  // Lower window
    X_GRID,   // Show application grid (explode all windows in picker)

    /* Emacs
     */
    EM_EVAL,  // (eval-expression)
    /* See more Spacemacs keys immediately below (Tapdance configs) */

    /* Gmail
     */
    GM_MARK,
};


/*
 * Tap Dance configs
 */
void td_spacemacs_save_clearhl(qk_tap_dance_state_t *state, void *user_data);
void td_spacemacs_magit_dispatch(qk_tap_dance_state_t *state, void *user_data);
void td_spacemacs_comint_send(qk_tap_dance_state_t *state, void *user_data);

enum TD_KEYS {
    EM_SVCL,  // Save file or Clear search highlight
    EM_MAGT,  // Magit menu or Git log
    EM_SEND,  // Comint send input (or send input and go to shell buffer)
};

qk_tap_dance_action_t tap_dance_actions[] = {
    [EM_SVCL] = ACTION_TAP_DANCE_FN(td_spacemacs_save_clearhl),
    [EM_MAGT] = ACTION_TAP_DANCE_FN(td_spacemacs_magit_dispatch),
    [EM_SEND] = ACTION_TAP_DANCE_FN(td_spacemacs_comint_send_line),
};


/*
 * Layers
 */
enum layers {
    _BASE,
    _NUM,
    _MISC,
    _FN,
    _X11,
    _TMUX,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT_5x7(
        // left hand
        KC_ESC,    KC_HASH,  KC_DLR,   KC_LPRN,  KC_LBRC,  KC_PERC,  KC_EXLM,
        KC_ESC,    KC_SLSH,  KC_COMM,  KC_DOT,   KC_P,     KC_Y,     XXXXXXX,
        KC_PIPE,   KC_A,     KC_O,     KC_E,     KC_U,     KC_I,     KC_ENT,
        OSL(_FN),  KC_SCLN,  KC_Q,     KC_J,     KC_K,     KC_X,
        KC_VOLD,   KC_VOLU,  KC_AT,    KC_QUOT,

        // Left thumb positional arguments:
        //     bottom to top
        //     left to right
        LT(_NUM, KC_ESC),  // numpad
        LCTL_T(KC_SPACE),  // control
        SHFT_INS,  // insert
        LSFT_T(KC_SPACE),  // shift
        OSL(_TMUX),  // tmux
        LCMD_T(KC_TAB),  // meta


        // right hand
        KC_ASTR,  KC_CIRC,  KC_RBRC,  KC_RPRN,  KC_EQL,   KC_GRV,   KC_BSPC,
        XXXXXXX,  KC_F,     KC_G,     KC_C,     KC_R,     KC_L,     KC_PLUS,
        KC_ENT,   KC_D,     KC_H,     KC_T,     KC_N,     KC_S,     KC_MINS,
                  KC_B,     KC_M,     KC_W,     KC_V,     KC_Z,     OSL(_X11),
                                      KC_DQUO,  KC_SCLN,  KC_PGDN,  KC_PGUP,

        // Right thumb positional arguments:
        //     top to bottom
        //     right to left
        RCTL_T(KC_SPACE),   // control
        LT(_MISC, KC_ESC),  // misc
        RSFT_T(KC_SPACE),   // shift
        KC_UNDS,  // _
        RCMD_T(KC_TAB),  // meta
        OSL(_TMUX)  // tmux
    ),


    [_NUM] = LAYOUT_5x7(
        // left hand
        _______,  _______,  _______,  _______,  _______,      _______,  _______,
        _______,  _______,  _______,  _______,  _______,      _______,  _______,
        _______,  _______,  _______,  _______,  TD(EM_SVCL),  _______,  _______,
        _______,  _______,  _______,  _______,  _______,      _______,
        _______,  _______,  _______,  _______,

        // Left thumb positional arguments:
        //     bottom to top
        //     left to right
        _______,  // numpad
        _______,  // control
        _______,  // insert
        _______,  // shift
        _______,  // tmux
        _______,  // meta


        // right hand
        _______,  _______,  KC_NLCK,  TD(EM_SEND),  _______,  _______,  TD(EM_MAGT),
        _______,  _______,  KC_P7,    KC_P8,        KC_P9,    _______,  _______,
        _______,  KC_DEL,   KC_P4,    KC_P5,        KC_P6,    _______,  _______,
                  _______,  KC_P1,    KC_P2,        KC_P3,    _______,  _______,
                                      KC_TILD,      KC_PDOT,  _______,  _______,

        // Right thumb positional arguments:
        //     top to bottom
        //     right to left
        KC_TILD,  // control
        KC_P0,    // misc
        _______,  // shift
        _______,  // _
        _______,  // meta
        KC_P0     // tmux
    ),


    [_MISC] = LAYOUT_5x7(
        // left hand
        _______,  _______,  _______,  _______,  KC_CIRC,  _______,  _______,
        _______,  KC_BSLS,  _______,  KC_HOME,  KC_END,   _______,  _______,
        _______,  _______,  KC_HASH,  KC_LEFT,  KC_RGHT,  KC_TAB,   _______,
        _______,  _______,  KC_COLN,  KC_DOWN,  KC_UP,    _______,
        //  brightness
        KC_BRID,  KC_BRIU,  EM_EVAL,  KC_AMPR,

        // Left thumb positional arguments:
        //     bottom to top
        //     left to right
        _______,  // numpad
        _______,  // control
        _______,  // insert
        _______,  // shift
        _______,  // tmux
        _______,  // meta


        // right hand
        _______,  _______,  _______,  _______,  _______,    _______,  _______,
        _______,  _______,  _______,  _______,  _______,    _______,  _______,
        _______,  GM_MARK,  _______,  _______,  _______,    _______,  _______,
                  _______,  _______,  _______,  _______,    _______,  _______,
                                      _______,  _______,    _______,  RESET,

        // Right thumb positional arguments:
        //     top to bottom
        //     right to left
        _______,  // control
        _______,  // misc
        _______,  // shift
        _______,  // _
        _______,  // meta
        _______   // tmux
    ),


    [_FN] = LAYOUT_5x7(
        // left hand
        _______,  _______,  _______,  _______,  _______,  _______,  _______,
        _______,  _______,  _______,  _______,  _______,  _______,  _______,
        _______,  _______,  _______,  _______,  _______,  _______,  _______,
        _______,  _______,  _______,  _______,  _______,  _______,
        _______,  _______,  _______,  _______,

        // Left thumb positional arguments:
        //     bottom to top
        //     left to right
        _______,  // numpad
        _______,  // control
        _______,  // insert
        _______,  // shift
        _______,  // tmux
        _______,  // meta


        // right hand
        _______,  _______,  KC_F10,  KC_F11,   KC_F12,   _______,  _______,
        _______,  _______,  KC_F7,   KC_F8,    KC_F9,    _______,  _______,
        _______,  GM_MARK,  KC_F4,   KC_F5,    KC_F6,    _______,  _______,
                  _______,  KC_F1,   KC_F2,    KC_F3,    _______,  _______,
                                     _______,  _______,  _______,  _______,

        // Right thumb positional arguments:
        //     top to bottom
        //     right to left
        _______,  // control
        _______,  // misc
        _______,  // shift
        _______,  // _
        _______,  // meta
        _______   // tmux
    ),


    [_X11] = LAYOUT_5x7(
        // left hand
        _______,  _______,  _______,  X_SHADE,  _______,  _______,  _______,
        _______,  _______,  X_QT_NW,  X_QT_N,   X_QT_NE,  _______,  _______,
        X_MAX_H,  _______,  X_QT_W,   X_MAXMZ,  X_QT_E,   X_MINMZ,  _______,
        _______,  _______,  X_QT_SW,  X_QT_S,   X_QT_SE,  _______,
        _______,  _______,  _______,  X_LOWER,

        // Left thumb positional arguments:
        //     bottom to top
        //     left to right
        X_GRID,   // numpad
        X_MAXMZ,  // control
        X_MAX_V,  // insert
        X_MAX_H,  // shift
        X_LOWER,  // tmux
        X_RAISE,  // meta


        // right hand
        _______,  _______,  _______,  _______,  _______,    _______,  _______,
        _______,  _______,  _______,  _______,  _______,    _______,  _______,
        _______,  _______,  _______,  _______,  _______,    _______,  X_MAX_V,
                  _______,  _______,  _______,  _______,    _______,  _______,
                                      _______,  _______,    _______,  _______,

        // Right thumb positional arguments:
        //     top to bottom
        //     right to left
        _______,  // control
        _______,  // misc
        _______,  // shift
        X_MAX_V,  // _
        _______,  // meta
        _______   // tmux
    ),


    [_TMUX] = LAYOUT_5x7(
        // left hand
        _______,  TM_ALTW,  _______,  TM_NUMW,  TM_SWPU,  _______,  TM_BRKP,
        _______,  TM_HELP,  TM_RENW,  TM_MOVW,  TM_PRVW,  _______,  _______,
        TM_SPLH,  TM_APPW,  TM_ROTW,  TM_LEFT,  TM_RGHT,  _______,  _______,
        _______,  _______,  TM_CMD,   TM_DWNP,  TM_UPP,   _______,
        _______,  _______,  _______,  TM_JOIN,

        // Left thumb positional arguments:
        //     bottom to top
        //     left to right
        TM_DISP,  // numpad
        TM_CPUP,  // control
        _______,  // insert
        TM_NXTL,  // shift
        TM_PUTB,  // tmux
        _______,  // meta


        // right hand
        TM_SYNC,  _______,  TM_SWPD,  _______,  TM_EQLP,  _______,  _______,
        _______,  TM_FNDW,  _______,  TM_NEWW,  TM_RENB,  TM_RGHT,  TM_ZOOM,
        _______,  TM_DELB,  TM_LEFT,  TM_ALTP,  TM_NXTW,  _______,  TM_SPLV,
                  TM_SELB,  TM_MARK,  TM_SELW,  TM_PUTB,  TM_UNDO,  _______,
                                      _______,  _______,  _______,  _______,

        // Right thumb positional arguments:
        //     top to bottom
        //     right to left
        _______,  // control
        _______,  // misc
        TM_NXTL,  //shift
        TM_MAXV,  // _
        _______,  // meta
        TM_COPY   // tmux
    ),
};

/*
 * Allow "rolling" keypresses (like "aoeu") within TAPPING_TERM to remain as
 * individual taps and not register a hold; do this for individual MTs
 * (per IGNORE_MOD_TAP_INTERRUPT_PER_KEY).
 *
 * See https://docs.qmk.fm/#/tap_hold?id=ignore-mod-tap-interrupt
 */
bool get_ignore_mod_tap_interrupt(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LCTL_T(KC_SPACE):
        case RCTL_T(KC_SPACE):
        case LSFT_T(KC_SPACE):
        case RSFT_T(KC_SPACE):
            // Do not force the mod-tap key press to be handled as a modifier
            // if any other key was pressed while the mod-tap key is held down.
            return true;
        default:
            // Force the mod-tap key press to be handled as a modifier if any
            // other key was pressed while the mod-tap key is held down.
            return false;
    }
}

/*
 * Do the opposite as above; force "rolling" keypresses (like "aoeu") within
 * TAPPING_TERM to register a layer hold. We need this because LTs are treated
 * differently than MTs. Do this for individual LTs only. (per
 * HOLD_ON_OTHER_KEY_PRESS_PER_KEY).
 *
 * See https://docs.qmk.fm/#/tap_hold?id=hold-on-other-key-press
 */
bool get_hold_on_other_key_press(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
    case LT(_NUM,KC_ESC):
    case LT(_MISC,KC_ESC):
    case LCMD_T(KC_TAB):
        // Immediately select the hold action when another key is pressed.
        return true;
    default:
        // Do not select the hold action when another key is pressed.
        return false;
    }
}

/*
 * "Hold on other key press" only covers the case of "rolling" keypresses within
 * TAPPING_TERM, not the case of "nested" keypresses as defined at the link
 * below. Also force holds for nested chords for certain keys (per
 * PERMISSIVE_HOLD_PER_KEY).
 *
 * See https://docs.qmk.fm/#/tap_hold?id=permissive-hold
 */
bool get_permissive_hold(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
    case LT(_NUM,KC_ESC):
    case LT(_MISC,KC_ESC):
    case LCMD_T(KC_TAB):
        // Immediately select the hold action when another key is tapped.
        return true;
    default:
        // Do not select the hold action when another key is tapped.
        return false;
    }
}

/*
 * Use a completely different TAPPING_TERM for the following Tap Dance keys
 * since it's more convenient to be comfortable/lazy for these particular
 * tapdances and not rush against the timer.
 *
 * See https://docs.qmk.fm/#/tap_hold?id=tapping-term
 */
uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
    case TD(EM_SVCL):
        return 350;  // tapping timeout in ms
    case TD(EM_MAGT):
        return 180;  // tapping timeout in ms
    case TD(EM_SEND):
        return 250;  // tapping timeout in ms
    default:
        return TAPPING_TERM;
    }
}

/*
 * Tap Dances for Spacemacs (macros)
 */
void td_spacemacs_save_clearhl(qk_tap_dance_state_t *state, void *user_data) {
	if (state->count == 1) {
        // SPC f s (Save file)
        SEND_STRING(SPACEMACS_LEADER
                    SS_TAP(X_F) SS_DELAY(SPACEMACS_DELAY)
                    SS_TAP(X_S));
    }
    else if (state->count == 2) {
        // SPC s c (Clear search)
        SEND_STRING(SPACEMACS_LEADER
                    SS_TAP(X_S) SS_DELAY(SPACEMACS_DELAY)
                    SS_TAP(X_C));
    }
}

void td_spacemacs_magit_dispatch(qk_tap_dance_state_t *state, void *user_data) {
	if (state->count == 1) {
        // SPC g m (Magit menu)
        SEND_STRING(SPACEMACS_LEADER
                    SS_TAP(X_G) SS_DELAY(SPACEMACS_DELAY)
                    SS_TAP(X_M));
    }
    else if (state->count == 2) {
        // SPC g m l l (Git log)
        SEND_STRING(SPACEMACS_LEADER
                    SS_TAP(X_G) SS_DELAY(SPACEMACS_DELAY)
                    SS_TAP(X_M) SS_DELAY(SPACEMACS_DELAY)
                    SS_TAP(X_L) SS_DELAY(SPACEMACS_DELAY)
                    SS_TAP(X_L));
    }
}

void td_spacemacs_comint_send(qk_tap_dance_state_t *state, void *user_data) {
	if (state->count == 1) {
        // SPC o r (brc/send-line-or-region)
        SEND_STRING(SPACEMACS_LEADER
                    SS_TAP(X_O) SS_DELAY(SPACEMACS_DELAY)
                    SS_TAP(X_R));
    }
    else if (state->count == 2) {
        // SPC o R (brc/send-line-or-region-and-go)
        SEND_STRING(SPACEMACS_LEADER
                    SS_TAP(X_O) SS_DELAY(SPACEMACS_DELAY)
                    SS_LSFT(SS_TAP(X_R)));
    }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
    case SHFT_INS:
        if (record->event.pressed)
            SEND_STRING(SS_LSFT(SS_TAP(X_INSERT)));
        break;

    // Tmux windows
    ////////////////////////////////////////////

    case TM_NEWW:
        if (record->event.pressed)
            SEND_STRING(TMUX_PREFIX SS_TAP(X_C));  // c
        break;

    case TM_APPW:
        if (record->event.pressed)
            SEND_STRING(TMUX_PREFIX SS_TAP(X_A));  // a
        break;

    case TM_NXTW:
        if (record->event.pressed)
            SEND_STRING(TMUX_PREFIX SS_TAP(X_N));  // n
        break;

    case TM_PRVW:
        if (record->event.pressed)
            SEND_STRING(TMUX_PREFIX SS_TAP(X_P));  // p
        break;

    case TM_ALTW:
        if (record->event.pressed)
            SEND_STRING(TMUX_PREFIX SS_LSFT(SS_TAP(X_3)));  // #
        break;

    case TM_SELW:
        if (record->event.pressed)
            SEND_STRING(TMUX_PREFIX SS_TAP(X_W));  // w
        break;

    case TM_MOVW:
        if (record->event.pressed)
            SEND_STRING(TMUX_PREFIX SS_TAP(X_DOT));  // .
        break;

    case TM_RENW:
        if (record->event.pressed)
            SEND_STRING(TMUX_PREFIX SS_TAP(X_COMMA));  // ,
        break;

    case TM_NUMW:
        if (record->event.pressed)
            SEND_STRING(TMUX_PREFIX SS_LSFT(SS_TAP(X_R)));  // R
        break;

    case TM_ROTW:
        if (record->event.pressed)
            SEND_STRING(TMUX_PREFIX SS_LCTL(SS_TAP(X_O)));  // C-o
        break;

    case TM_FNDW:
        if (record->event.pressed)
            SEND_STRING(TMUX_PREFIX SS_TAP(X_F));  // f
        break;

    case TM_SPLH:
        if (record->event.pressed)
            SEND_STRING(TMUX_PREFIX SS_LSFT(SS_TAP(X_BSLASH)));  // |
        break;

    case TM_SPLV:
        if (record->event.pressed)
            SEND_STRING(TMUX_PREFIX SS_TAP(X_MINUS));  // -
        break;

    // Tmux panes
    ////////////////////////////////////////////

    case TM_UPP:
        if (record->event.pressed)
            SEND_STRING(TMUX_PREFIX SS_TAP(X_K));  // k
        break;

    case TM_DWNP:
        if (record->event.pressed)
            SEND_STRING(TMUX_PREFIX SS_TAP(X_J));  // j
        break;

    case TM_RGHT:
        if (record->event.pressed)
            SEND_STRING(TMUX_PREFIX SS_TAP(X_L));  // l
        break;

    case TM_LEFT:
        if (record->event.pressed)
            SEND_STRING(TMUX_PREFIX SS_TAP(X_H));  // h
        break;

    case TM_ALTP:
        if (record->event.pressed)
            SEND_STRING(TMUX_PREFIX SS_TAP(X_T));  // t
        break;

    case TM_DISP:
        if (record->event.pressed)
            SEND_STRING(TMUX_PREFIX SS_TAP(X_Q));  // q
        break;

    case TM_EQLP:
        if (record->event.pressed)
            SEND_STRING(TMUX_PREFIX SS_TAP(X_EQUAL));  // =
        break;

    case TM_NXTL:
        if (record->event.pressed)
            SEND_STRING(TMUX_PREFIX SS_TAP(X_SPACE));  // SPC
        break;

    case TM_SWPU:
        if (record->event.pressed)
            SEND_STRING(TMUX_PREFIX SS_LSFT(SS_TAP(X_LBRACKET)));  // {
        break;

    case TM_SWPD:
        if (record->event.pressed)
            SEND_STRING(TMUX_PREFIX SS_LSFT(SS_TAP(X_RBRACKET)));  // }
        break;

    case TM_SYNC:
        if (record->event.pressed)
            SEND_STRING(TMUX_PREFIX SS_LALT(SS_TAP(X_S)));  // M-s
        break;

    case TM_ZOOM:
        if (record->event.pressed)
            SEND_STRING(TMUX_PREFIX SS_LSFT(SS_TAP(X_EQUAL))); // +
        break;

    case TM_MAXV:
        if (record->event.pressed)
            SEND_STRING(TMUX_PREFIX SS_LSFT(SS_TAP(X_MINUS))); // _
        break;

    case TM_UNDO:
        if (record->event.pressed)
            SEND_STRING(TMUX_PREFIX SS_TAP(X_Z)); // z
        break;

    case TM_MARK:
        if (record->event.pressed)
            SEND_STRING(TMUX_PREFIX SS_TAP(X_M)); // m
        break;

    case TM_BRKP:
        if (record->event.pressed)
            SEND_STRING(TMUX_PREFIX SS_LSFT(SS_TAP(X_1)));  // !
        break;

    case TM_JOIN:
        if (record->event.pressed)
            SEND_STRING(TMUX_PREFIX SS_LSFT(SS_TAP(X_7)));  // &
        break;

    // Tmux Misc
    ////////////////////////////////////////////

    case TM_COPY:
        if (record->event.pressed)
            SEND_STRING(TMUX_PREFIX SS_LALT(SS_TAP(X_T)));  // M-t
        break;

    case TM_CPUP:
        if (record->event.pressed)
            SEND_STRING(TMUX_PREFIX SS_TAP(X_PGUP));  // ppage (copy-mode -u)
        break;

    case TM_PUTB:
        if (record->event.pressed)
            SEND_STRING(TMUX_PREFIX SS_LALT(SS_TAP(X_H)));  // M-h
        break;

    case TM_SELB:
        if (record->event.pressed)
            SEND_STRING(TMUX_PREFIX SS_LALT(SS_TAP(X_B)));  // M-b
        break;

    case TM_RENB:
        if (record->event.pressed)
            SEND_STRING(TMUX_PREFIX SS_LALT(SS_TAP(X_R)));  // M-r
        break;

    case TM_DELB:
        if (record->event.pressed)
            SEND_STRING(TMUX_PREFIX SS_LALT(SS_TAP(X_D)));  // M-d
        break;

    case TM_CMD:
        if (record->event.pressed)
            SEND_STRING(TMUX_PREFIX SS_LSFT(SS_TAP(X_SCOLON)));  // :
        break;

    case TM_HELP:
        if (record->event.pressed)
            SEND_STRING(TMUX_PREFIX SS_LSFT(SS_TAP(X_SLASH)));  // ?
        break;

    /*
     * X11
     */

    case X_MINMZ:
        if (record->event.pressed)
            SEND_STRING(SS_LALT(SS_TAP(X_P0)));
        break;

    case X_MAXMZ:
        if (record->event.pressed)
            SEND_STRING(SS_LALT(SS_TAP(X_P5)));
        break;

    case X_MAX_H:
        if (record->event.pressed)
            /* XXX See quantum/send_string_keycodes.h
             *     Only KC_BACKSLASH and KC_BSLS are documented in
             *     docs/keycodes_basic.md
             */
            SEND_STRING(SS_LALT(SS_LCTL(SS_LSFT(SS_TAP(X_BSLASH)))));  // M-|
        break;

    case X_MAX_V:
        if (record->event.pressed)
            SEND_STRING(SS_LALT(SS_LSFT(SS_TAP(X_MINUS))));  // M-_
        break;

    case X_QT_N:
        if (record->event.pressed)
            SEND_STRING(SS_LALT(SS_TAP(X_P8)));
        break;

    case X_QT_S:
        if (record->event.pressed)
            SEND_STRING(SS_LALT(SS_TAP(X_P2)));
        break;

    case X_QT_E:
        if (record->event.pressed)
            SEND_STRING(SS_LALT(SS_TAP(X_P6)));
        break;

    case X_QT_W:
        if (record->event.pressed)
            SEND_STRING(SS_LALT(SS_TAP(X_P4)));
        break;

    case X_QT_NW:
        if (record->event.pressed)
            SEND_STRING(SS_LALT(SS_TAP(X_P7)));
        break;

    case X_QT_NE:
        if (record->event.pressed)
            SEND_STRING(SS_LALT(SS_TAP(X_P9)));
        break;

    case X_QT_SE:
        if (record->event.pressed)
            SEND_STRING(SS_LALT(SS_TAP(X_P3)));
        break;

    case X_QT_SW:
        if (record->event.pressed)
            SEND_STRING(SS_LALT(SS_TAP(X_P1)));
        break;

    case X_SHADE:
        if (record->event.pressed)
            SEND_STRING(SS_LALT(SS_LSFT(SS_TAP(X_0))));  // M-)
        break;

    case X_RAISE:
        if (record->event.pressed)
            SEND_STRING(SS_LALT(SS_LSFT(SS_TAP(X_R))));  // M-R
        break;

    case X_LOWER:
        if (record->event.pressed)
            SEND_STRING(SS_LALT(SS_LSFT(SS_TAP(X_V))));  // M-V
        break;

    case X_GRID:
        if (record->event.pressed)
            SEND_STRING(SS_LALT(SS_LSFT(SS_TAP(X_G))));  // M-G
        break;

    /*
     * Emacs
     */

    case EM_EVAL:
        if (record->event.pressed)
            SEND_STRING(SS_LALT(SS_LSFT(SS_TAP(X_SCLN))));  // M-:
        break;

    /*
     * GMail
     */

    case GM_MARK:
        if (record->event.pressed)
            /* This mimics default mutt behavior when you press `d' in the
             * index to delete a message, which automatically moves to the next
             * message (so you can delete multiple messages by repeatedly
             * pressing a single key).
             */
            SEND_STRING("xj");  // select message ("x"), move cursor down ("j")
        break;
    }

    return true;
}
