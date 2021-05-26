#include QMK_KEYBOARD_H

enum {
  TD_MINS_EQL = 0,
  TD_9_LBRC,
  TD_0_RBRC,
  TD_LSFT_CAPS
};

qk_tap_dance_action_t tap_dance_actions[] = {
  [TD_MINS_EQL] = ACTION_TAP_DANCE_DOUBLE(KC_MINS, KC_EQL),
  [TD_9_LBRC] = ACTION_TAP_DANCE_DOUBLE(KC_9, KC_LBRC),
  [TD_0_RBRC] = ACTION_TAP_DANCE_DOUBLE(KC_0, KC_RBRC),
  [TD_LSFT_CAPS] = ACTION_TAP_DANCE_DOUBLE(KC_LSFT, KC_CAPS)
};

const uint16_t PROGMEM enter_combo[] = {KC_L, KC_SCLN, COMBO_END};
combo_t key_combos[COMBO_COUNT] = {COMBO(enter_combo, KC_ENT)};

#define KC_LSZ LSFT_T(KC_Z)
#define KC_RSSL LSFT_T(KC_SLSH)
#define KC_LCTF LCTL_T(KC_F)
#define KC_RCTJ RCTL_T(KC_J)
#define KC_LGD LGUI_T(KC_D)
#define KC_RGK RGUI_T(KC_K)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [0] = LAYOUT(
    KC_GESC,  KC_Q,    KC_W,   KC_E,   KC_R,     KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,   KC_P  ,  KC_BSPC,
    KC_TAB,   KC_A,    KC_S,   KC_LGD, KC_LCTF,  KC_G,    KC_H,    KC_RCTJ, KC_RGK,  KC_L,   KC_SCLN,
    KC_LSFT,  KC_LSZ,  KC_X,   KC_C,   KC_V,     KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT, KC_RSSL,
    KC_LALT,  KC_LGUI, MO(1),  LT(2,   KC_SPC),  LT(2, KC_SPC),    MO(4),   MO(3)
  ),

  [1] = LAYOUT(
    KC_GRV ,  KC_1   ,  KC_2   ,  KC_3   ,  KC_4   ,  KC_5   ,  KC_6   ,  KC_7   ,  KC_8   ,  TD(TD_9_LBRC),  TD(TD_0_RBRC), TD(TD_MINS_EQL),
    KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS      ,  KC_QUOT,
    KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS      ,  KC_TRNS,
    KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS
  ),

  [2] = LAYOUT(
    KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,
    KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_LEFT,  KC_DOWN,  KC_UP,    KC_RIGHT, KC_TRNS,
    KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_BSLS,
    KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS
  ),

  [3] = LAYOUT(
    KC_TRNS,  KC_F1  ,  KC_F2  ,  KC_F3  ,  KC_F4  ,  KC_F5  ,  KC_F6  ,  KC_F7  ,  KC_F8  ,  KC_F9  ,  KC_F10 ,  KC_F11,
    KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,
    KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,
    KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS
  ),

  [4] = LAYOUT(
    RESET,    KC_MRWD,  KC_MPLY,  KC_MFFD,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,
    KC_TRNS,  KC_TRNS,  KC_VOLD,  KC_VOLU,  KC_MUTE,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,
    KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,
    KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS
  )
};

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case KC_LSZ:
      return TAPPING_SHIFT_TERM;
    case KC_RSSL:
      return TAPPING_SHIFT_TERM;
    default:
      return TAPPING_TERM;
  }
}
