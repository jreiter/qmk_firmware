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

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[0] = LAYOUT(
    KC_1, 	           KC_2,     KC_3,     KC_4,   KC_5,    KC_6,
    KC_GESC,           KC_Q,     KC_W,     KC_E,   KC_R,    KC_T,     KC_Y,   KC_U,    KC_I,     KC_O,    KC_P,     KC_BSPC,
    KC_TAB,            KC_A,     KC_S,     KC_D,   KC_F,    KC_G,     KC_H,   KC_J,    KC_K,     KC_L,    KC_SCLN,  KC_ENT,
    TD(TD_LSFT_CAPS),  KC_Z,     KC_X,     KC_C,   KC_V,    KC_B,     KC_N,   KC_M,    KC_COMM,  KC_DOT,  KC_SLSH,  MO(3),
    KC_LCTL,           KC_LALT,  KC_LGUI,  KC_SPC, KC_SPC,  LT(1, KC_SPC),   KC_SPC, KC_RGUI, MO(2),    KC_RCTL
    ),
[1] = LAYOUT(
    KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,
    KC_GRV,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     TD(TD_9_LBRC),  TD(TD_0_RBRC),  TD(TD_MINS_EQL),
    KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_LEFT,  KC_DOWN,  KC_UP,    KC_RIGHT,       KC_QUOT,        KC_BSLS,
    KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,        KC_TRNS,        KC_TRNS,
    KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS
    ),
[2] = LAYOUT(
    KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,
    KC_TRNS,  KC_MRWD,  KC_MPLY,  KC_MFFD,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,
    KC_TRNS,  KC_TRNS,  KC_VOLD,  KC_VOLU,  KC_MUTE,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,
    KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,
    KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS
    ),
[3] = LAYOUT(
    KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,
    RESET,    KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,
    KC_TRNS,  KC_TRNS,  KC_VOLD,  KC_VOLU,  KC_MUTE,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,
    KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,
    KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS
    )
};

enum custom_keycodes {
  M_IME = SAFE_RANGE
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
    switch(keycode) {
      case M_IME:
        SEND_STRING(SS_DOWN(X_LSHIFT)SS_DOWN(X_LALT));
        return false;
    }
  }
  else {
    switch(keycode) {
      case M_IME:
        SEND_STRING(SS_UP(X_LSHIFT)SS_UP(X_LALT));
        return false;
    }
  }
  return true;
};

void process_indicator_update(uint32_t state, uint8_t usb_led) {
  if (state & (1<<3)) {
    writePinHigh(B5);
  } else {
    writePinLow(B5);
  }

  if (state & (1<<3)) {
    writePinHigh(B4);
  } else {
    writePinLow(B4);
  }
};

void keyboard_post_init_user(void) {
  setPinOutput(B6);
  writePinHigh(B6);
  setPinOutput(B5);
  setPinOutput(B4);
  process_indicator_update(layer_state, host_keyboard_leds());
};

void led_set_user(uint8_t usb_led) {
  process_indicator_update(layer_state, host_keyboard_leds());
};

uint32_t layer_state_set_user(uint32_t state) {
  process_indicator_update(state, host_keyboard_leds());
  return state;
};
