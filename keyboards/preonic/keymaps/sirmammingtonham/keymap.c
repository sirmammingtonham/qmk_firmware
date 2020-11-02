/* preonic layout rev2
* pls no errors
*
* by ethan
*/

#include QMK_KEYBOARD_H

#ifdef AUDIO_ENABLE
  #include "sounds.h"
  float sticky_fingers[][2] = SONG(USSR_ANTHEM);
  float song_game[][2]      = SONG(LEVEL_UP);
  float song_gamefuncs[][2] = SONG(COIN_SOUND);
  float song_numpad[][2]    = SONG(SONIC_RING);
  float song_adjust[][2]    = SONG(ZELDA_PUZZLE);
#endif

enum preonic_layers {
  _DEFAULT,
  _LOWER,
  _RAISE,
  _GAMER,
  _GAMERFUNCS,
  _NUMPAD,
  _ADJUST
};

// enum preonic_keycodes {
//   DEFAULT = SAFE_RANGE,
//   LOWER,
//   RAISE,
//   GAMER,
//   GAMERFUNCS,
//   NUMPAD,
//   ADJUST
// };

enum preonic_keycodes {
  LOWER = SAFE_RANGE,
  RAISE,
};


enum tap_dances {
    BRACKETS = 0
};

void brackets_everywhere(qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
        tap_code16(KC_LBRC);
    } else if (state->count == 2) {
        tap_code16(KC_RBRC);
    } else if (state->count == 3) {
        SEND_STRING("{"); // because only basic codes are allowed
    } else if (state->count == 4) {
        SEND_STRING("}");
    } else if (state->count >= 15) {
        PLAY_SONG(sticky_fingers);
    }
}

qk_tap_dance_action_t tap_dance_actions[] = {
    [BRACKETS] = ACTION_TAP_DANCE_FN(brackets_everywhere),
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* DEFAULT
* ┌──────┬──────┬──────┬──────┬──────┬──────┬──────┬──────┬──────┬──────┬──────┬──────┐
* │ `/Esc│   1  │   2  │   3  │   4  │   5  │   6  │   7  │   8  │   9  │   0  │ GAME │
* ├──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┤
* │ []{} │   '  │   ,  │   .  │   P  │   Y  │   F  │   G  │   C  │   R  │   L  │  =   │
* ├──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┤
* │ Tab  │   A  │   O  │   E  │   U  │   I  │   D  │   H  │   T  │   N  │   S  │  -   │
* ├──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┤
* │ Shft │   ;  │   Q  │   J  │   K  │   X  │   B  │   M  │   W  │   V  │   Z  │Enter │
* ├──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┤
* │ Ctrl │   /  │ Alt  │ Gui  │Lower │Space │ Bksp │Raise │ Left │ Down │  Up  │ Right│
* └──────┴──────┴──────┴──────┴──────┴──────┴──────┴──────┴──────┴──────┴──────┴──────┘
*/
  [_DEFAULT] = LAYOUT_preonic_grid( \
    KC_GESC,        KC_1,      KC_2,      KC_3,      KC_4,      KC_5,      KC_6,      KC_7,      KC_8,      KC_9,      KC_0,      TO(_GAMER), \
    TD(BRACKETS),   KC_QUOT,   KC_COMM,   KC_DOT,    KC_P,      KC_Y,      KC_F,      KC_G,      KC_C,      KC_R,      KC_L,      KC_EQL,     \
    KC_TAB,         KC_A,      KC_O,      KC_E,      KC_U,      KC_I,      KC_D,      KC_H,      KC_T,      KC_N,      KC_S,      KC_MINS,    \
    KC_LSFT,        KC_SCLN,   KC_Q,      KC_J,      KC_K,      KC_X,      KC_B,      KC_M,      KC_W,      KC_V,      KC_Z,      KC_ENT,     \
    KC_LCTL,        KC_SLSH,   KC_LALT,   KC_LGUI,   LOWER,     KC_SPC,    KC_BSPC,   RAISE,     KC_LEFT,   KC_DOWN,   KC_UP,     KC_RGHT     \
  ),

/* LOWER
 * ┌──────┬──────┬──────┬──────┬──────┬──────┬──────┬──────┬──────┬──────┬──────┬──────┐
 * │  ~   │  !   │  @   │  #   │  $   │  %   │  ^   │  &   │  *   │  (   │  )   │  Del │
 * ├──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┤
 * │  ~   │  !   │  @   │  #   │  $   │  %   │  ^   │  &   │  *   │  (   │  )   │  =   │
 * ├──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┤
 * │      │      │      │      │      │      │      │      │      │      │  |   │  \   │
 * ├──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┤
 * │ Shft │      │      │      │      │      │      │      │  [   │  ]   │  {   │  }   │
 * ├──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┤
 * │      │      │      │      │      │Space │ Bksp │      │ Home │ PgDn │ PgUp │  End │
 * └──────┴──────┴──────┴──────┴──────┴──────┴──────┴──────┴──────┴──────┴──────┴──────┘
 */
  [_LOWER] = LAYOUT_preonic_grid( \
    KC_TILD,   KC_EXLM,   KC_AT,     KC_HASH,   KC_DLR,    KC_PERC,   KC_CIRC,   KC_AMPR,   KC_ASTR,   KC_LPRN,   KC_RPRN,   KC_DEL,    \
    KC_TILD,   KC_EXLM,   KC_AT,     KC_HASH,   KC_DLR,    KC_PERC,   KC_CIRC,   KC_AMPR,   KC_ASTR,   KC_LPRN,   KC_RPRN,   KC_EQL,    \
    KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_PIPE,   KC_BSLS,   \
    KC_LSFT,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_LBRC,   KC_RBRC,   KC_LCBR,   KC_RCBR,   \
    KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_SPC,    KC_BSPC,   KC_TRNS,   KC_HOME,   KC_PGDN,   KC_PGUP,   KC_END     \
  ),

/* RAISE
 * ┌──────┬──────┬──────┬──────┬──────┬──────┬──────┬──────┬──────┬──────┬──────┬──────┐
 * │  F1  │  F2  │  F3  │  F4  │  F5  │  F6  │  F7  │  F8  │  F9  │  F10 │  F11 │  F12 │
 * ├──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┤
 * │PrtScn│ ScrLk│ Paus │      │      │      │      │      │      │      │      │      │
 * ├──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┤
 * │  Ins │ Home │ PgUp │      │      │      │      │      │      │      │      │      │
 * ├──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┤
 * │  Del │  End │ PgDn │      │      │      │      │      │      │ Play │ Mute │      │
 * ├──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┤
 * │ Ctrl │NUMPAD│ Alt  │ Gui  │ App  │ Copy │ Paste│      │ Prev │ Vol- │ Vol+ │ Next │
 * └──────┴──────┴──────┴──────┴──────┴──────┴──────┴──────┴──────┴──────┴──────┴──────┘
 */
  [_RAISE] = LAYOUT_preonic_grid( \
    KC_F1,     KC_F2,        KC_F3,     KC_F4,     KC_F5,     KC_F6,     KC_F7,     KC_F8,     KC_F9,     KC_F10,    KC_F11,    KC_F12,    \
    KC_PSCR,   KC_SLCK,      KC_PAUS,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,   \
    KC_INS,    KC_HOME,      KC_PGUP,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,   \
    KC_DEL,    KC_END,       KC_PGDN,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_MPLY,   KC_MUTE,   KC_TRNS,   \
    KC_LCTL,   TO(_NUMPAD),  KC_LALT,   KC_LGUI,   KC_APP,    KC_COPY,   KC_PSTE,   KC_TRNS,   KC_MPRV,   KC_VOLD,   KC_VOLU,   KC_MNXT    \
  ),

/* GAMER
 * ┌──────┬──────┬──────┬──────┬──────┬──────┬──────┬──────┬──────┬──────┬──────┬──────┐
 * │ `/Esc│   1  │   2  │   3  │   4  │   5  │   6  │   7  │   8  │   9  │   0  │      │
 * ├──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┤
 * │  F1  │   Q  │   W  │   E  │   R  │   T  │   Y  │   U  │   I  │   O  │   P  │  -   │
 * ├──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┤
 * │ Tab  │   A  │   S  │   D  │   F  │   G  │   H  │   J  │   K  │   L  │   ;  │   '  │
 * ├──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┤
 * │ Shft │   Z  │   X  │   C  │   V  │   B  │   N  │   M  │   ,  │   .  │  Up  │Enter │
 * ├──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┤
 * │ Ctrl │   /  │ Alt  │ Gui  │OSL(4)│Space │ Bksp │TO(0) │ App  │ Left │ Down │ Right│
 * └──────┴──────┴──────┴──────┴──────┴──────┴──────┴──────┴──────┴──────┴──────┴──────┘
 */
  [_GAMER] = LAYOUT_preonic_grid( \
    KC_GESC,   KC_1,      KC_2,      KC_3,      KC_4,              KC_5,      KC_6,      KC_7,          KC_8,      KC_9,      KC_0,      KC_TRNS,   \
    KC_F1,     KC_Q,      KC_W,      KC_E,      KC_R,              KC_T,      KC_Y,      KC_U,          KC_I,      KC_O,      KC_P,      KC_MINS,   \
    KC_TAB,    KC_A,      KC_S,      KC_D,      KC_F,              KC_G,      KC_H,      KC_J,          KC_K,      KC_L,      KC_SCLN,   KC_QUOT,   \
    KC_LSFT,   KC_Z,      KC_X,      KC_C,      KC_V,              KC_B,      KC_N,      KC_M,          KC_COMM,   KC_DOT,    KC_UP,     KC_ENT,    \
    KC_LCTL,   KC_SLSH,   KC_LALT,   KC_LGUI,   OSL(_GAMERFUNCS),  KC_SPC,    KC_BSPC,   TO(_DEFAULT),  KC_APP,    KC_LEFT,   KC_DOWN,   KC_RGHT    \
  ),

/* GAMERFUNCS
 * ┌──────┬──────┬──────┬──────┬──────┬──────┬──────┬──────┬──────┬──────┬──────┬──────┐
 * │   `  │   1  │   2  │   3  │   4  │   5  │   6  │   7  │   8  │   9  │   0  │PrtScn│
 * ├──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┤
 * │  ~   │  !   │  @   │  #   │  $   │  %   │  ^   │  &   │  *   │  (   │  )   │  Del │
 * ├──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┤
 * │  Del │  F1  │  F2  │  F3  │  F4  │  F5  │  F6  │  -   │  =   │  [   │  ]   │  \   │
 * ├──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┤
 * │      │  F7  │  F8  │  F9  │  F10 │  F11 │  F12 │   #  │  \   │ Play │ Mute │TO(0) │
 * ├──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┤
 * │      │      │      │      │      │      │      │      │ Prev │ Vol- │ Vol+ │ Next │
 * └──────┴──────┴──────┴──────┴──────┴──────┴──────┴──────┴──────┴──────┴──────┴──────┘
 */
  [_GAMERFUNCS] = LAYOUT_preonic_grid( \
    KC_GRV,    KC_1,      KC_2,      KC_3,      KC_4,      KC_5,      KC_6,      KC_7,        KC_8,      KC_9,      KC_0,      KC_PSCR,      \
    KC_TILD,   KC_EXLM,   KC_AT,     KC_HASH,   KC_DLR,    KC_PERC,   KC_CIRC,   KC_AMPR,     KC_ASTR,   KC_LPRN,   KC_RPRN,   KC_DEL,       \
    KC_DEL,    KC_F1,     KC_F2,     KC_F3,     KC_F4,     KC_F5,     KC_F6,     KC_MINS,     KC_EQL,    KC_LBRC,   KC_RBRC,   KC_BSLS,      \
    KC_TRNS,   KC_F7,     KC_F8,     KC_F9,     KC_F10,    KC_F11,    KC_F12,    KC_NUHS,     KC_NUBS,   KC_MPLY,   KC_MUTE,   TO(_DEFAULT), \
    KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,   TO(_GAMER),  KC_MPRV,   KC_VOLD,   KC_VOLU,   KC_MNXT       \
  ),

/* NUMPAD
 * ┌──────┬──────┬──────┬──────┬──────┬──────┬──────┬──────┬──────┬──────┬──────┬──────┐
 * │ Esc  │      │      │ PgDn │ PgUp │  End │ Home │      │   /  │   *  │  -   │  Del │
 * ├──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┤
 * │ Tab  │      │  Up  │      │      │      │      │  7   │  8   │  9   │   +  │ Bksp │
 * ├──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┤
 * │ Bksp │ Left │ Down │ Right│      │      │      │  4   │  5   │  6   │      │   '  │
 * ├──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┤
 * │ Shft │      │      │      │      │      │   ,  │  1   │  2   │  3   │      │ Shft │
 * ├──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┤
 * │ Ctrl │      │ Alt  │ Gui  │Lower │Space │ Bksp │Raise │  0   │   .  │ Ctrl │ Shft │
 * └──────┴──────┴──────┴──────┴──────┴──────┴──────┴──────┴──────┴──────┴──────┴──────┘
 */
  [_NUMPAD] = LAYOUT_preonic_grid( \
    KC_ESC,    KC_TRNS,   KC_TRNS,   KC_PGDN,   KC_PGUP,       KC_END,    KC_HOME,   KC_TRNS,       KC_PSLS,   KC_PAST,   KC_PMNS,   KC_DEL,    \
    KC_TAB,    KC_TRNS,   KC_UP,     KC_TRNS,   KC_TRNS,       KC_TRNS,   KC_TRNS,   KC_P7,         KC_P8,     KC_P9,     KC_PPLS,   KC_BSPC,   \
    KC_BSPC,   KC_LEFT,   KC_DOWN,   KC_RGHT,   KC_TRNS,       KC_TRNS,   KC_TRNS,   KC_P4,         KC_P5,     KC_P6,     KC_TRNS,   KC_QUOT,   \
    KC_LSFT,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,       KC_TRNS,   KC_COMM,   KC_P1,         KC_P2,     KC_P3,     KC_TRNS,   KC_RSFT,   \
    KC_LCTL,   KC_TRNS,   KC_LALT,   KC_LGUI,   TO(_DEFAULT),  KC_SPC,    KC_BSPC,   TO(_DEFAULT),  KC_P0,     KC_PDOT,   KC_RCTL,   KC_RSFT    \
  ),

/* ADJUST
 * ┌──────┬──────┬──────┬──────┬──────┬──────┬──────┬──────┬──────┬──────┬──────┬──────┐
 * │  F1  │  F2  │  F3  │  F4  │  F5  │  F6  │  F7  │  F8  │  F9  │  F10 │  F11 │  F12 │
 * ├──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┤
 * │      │ Reset│ Debug│      │      │      │      │TermOn│TermOf│      │      │  Del │
 * ├──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┤
 * │      │      │Mu Mod│Au On │Au Off│AG Nrm│AG Swp│DEFALT│NUMPAD│      │      │      │
 * ├──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┤
 * │      │Voice-│Voice+│Mu On │Mu Off│Mi On │Mi Off│      │      │      │      │      │
 * ├──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┤
 * │ Light│      │      │      │      │      │      │      │      │      │      │      │
 * └──────┴──────┴──────┴──────┴──────┴──────┴──────┴──────┴──────┴──────┴──────┴──────┘
 */

  [_ADJUST] = LAYOUT_preonic_grid( \
    KC_F1,     KC_F2,     KC_F3,     KC_F4,     KC_F5,     KC_F6,     KC_F7,     KC_F8,         KC_F9,        KC_F10,    KC_F11,    KC_F12,    \
    KC_TRNS,   RESET,     DEBUG,     KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,   TERM_ON,       TERM_OFF,     KC_TRNS,   KC_TRNS,   KC_DEL,    \
    KC_TRNS,   KC_TRNS,   MU_MOD,    AU_ON,     AU_OFF,    AG_NORM,   AG_SWAP,   TO(_DEFAULT),  TO(_NUMPAD),  KC_TRNS,   KC_TRNS,   KC_TRNS,   \
    KC_TRNS,   MUV_DE,    MUV_IN,    MU_ON,     MU_OFF,    MI_ON,     MI_OFF,    KC_TRNS,       KC_TRNS,      KC_TRNS,   KC_TRNS,   KC_TRNS,   \
    RGB_TOG,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,       KC_TRNS,      KC_TRNS,   KC_TRNS,   KC_TRNS    \
  )
};

// process custom keycodes
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    // case DEFAULT:
    //     if (record->event.pressed) {
    //         layer_on(_DEFAULT);
    //     }
    //     return false;
    // case GAMER:
    //     if (record->event.pressed) {
    //         layer_on(_GAMER);
    //     }
    //     return false;
    // case NUMPAD:
    //     if (record->event.pressed) {
    //         layer_on(_NUMPAD);
    //     }
    //     return false;
    case LOWER:
        if (record->event.pressed) {
            layer_on(_LOWER);
            update_tri_layer(_LOWER, _RAISE, _ADJUST);
        } else {
            layer_off(_LOWER);
            update_tri_layer(_LOWER, _RAISE, _ADJUST);
        }
        return false;
    case RAISE:
        if (record->event.pressed) {
            layer_on(_RAISE);
            update_tri_layer(_LOWER, _RAISE, _ADJUST);
        } else {
            layer_off(_RAISE);
            update_tri_layer(_LOWER, _RAISE, _ADJUST);
        }
        return false;
    }
    return true;
};


// handle layer change led switching and sound playing
layer_state_t layer_state_set_user(layer_state_t state) {
    switch (get_highest_layer(state)) {
    case _RAISE:
        rgblight_setrgb(RGB_BLUE);
        break;
    case _LOWER:
        rgblight_setrgb(RGB_GOLD);
        break;
    case _GAMER:
        PLAY_SONG(song_game);
        rgblight_setrgb(RGB_WHITE);
        break;
    case _GAMERFUNCS:
        PLAY_SONG(song_gamefuncs);
        rgblight_setrgb(RGB_CORAL);
        break;
    case _NUMPAD:
        PLAY_SONG(song_numpad);
        rgblight_setrgb(RGB_TURQUOISE);
        break;
    case _ADJUST:
        PLAY_SONG(song_adjust);
        rgblight_setrgb(RGB_CHARTREUSE);
        break;
    default: //  for any other layers, or the default layer
        rgblight_setrgb(RGB_PURPLE);
        break;
    }
  return state;
}
