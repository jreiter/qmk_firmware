/* Copyright 2018 Holten Campbell
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include QMK_KEYBOARD_H

enum {
  TD_MINS_EQL = 0,
  TD_9_LBRC,
  TD_0_RBRC,
  TD_LSFT_CAPS,
};

qk_tap_dance_action_t tap_dance_actions[] = {
  [TD_MINS_EQL] = ACTION_TAP_DANCE_DOUBLE(KC_MINS, KC_EQL),
  [TD_9_LBRC] = ACTION_TAP_DANCE_DOUBLE(KC_9, KC_LBRC),
  [TD_0_RBRC] = ACTION_TAP_DANCE_DOUBLE(KC_0, KC_RBRC),
  [TD_LSFT_CAPS] = ACTION_TAP_DANCE_DOUBLE(KC_LSFT, KC_CAPS)
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT(
    KC_ESC,            KC_Q,     KC_W,     KC_E,           KC_R,     KC_T,     KC_Y,     KC_U,     KC_I,    KC_O,     KC_P,     KC_DEL,  KC_BSPC,
    KC_TAB,            KC_A,     KC_S,     KC_D,           KC_F,     KC_G,     KC_H,     KC_J,     KC_K,    KC_L,     KC_SCLN,  KC_ENT,
    TD(TD_LSFT_CAPS),  KC_Z,     KC_X,     KC_C,           KC_V,     KC_B,     KC_B,     KC_N,     KC_M,    KC_COMM,  KC_DOT,   KC_SLSH,           MO(3),
    KC_LCTL,           KC_LALT,  KC_LGUI,  MO(1),  LT(2, KC_SPC),   KC_RGUI,  KC_RALT,  MO(4)
  ),
  [1] = LAYOUT(
    KC_GRV,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     TD(TD_9_LBRC),  TD(TD_0_RBRC),   KC_MINS, KC_EQL,
    KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_QUOT,        KC_SCLN,         KC_BSLS,
    KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,        KC_TRNS,         KC_TRNS, KC_TRNS,
    KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS
  ),
  [2] = LAYOUT(
    KC_TRNS,  KC_MRWD,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS, KC_TRNS,
    KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_LEFT,  KC_DOWN,  KC_UP,    KC_RGHT,  KC_TRNS,  KC_TRNS,
    KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS, KC_TRNS,
    KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS
  ),
  [3] = LAYOUT(
    KC_TRNS,  KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,
    KC_TRNS,  KC_TRNS,  KC_VOLD,  KC_VOLU,  KC_MUTE,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,
    KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_LBRC,  KC_RBRC,  KC_BSLS, KC_TRNS,
    KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS
  ),
  [4] = LAYOUT(
    KC_TRNS,  KC_MRWD,  KC_MPLY,  KC_MFFD,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS, KC_TRNS,
    KC_TRNS,  KC_TRNS,  KC_VOLD,  KC_VOLU,  KC_MUTE,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,
    KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS, KC_TRNS,
    RESET,    KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS
  ),
};

void matrix_init_user(void) {
  // set CapsLock LED to output and low
  setPinOutput(B1);
  writePinLow(B1);
  // set NumLock LED to output and low
  setPinOutput(B2);
  writePinLow(B2);
  // set ScrollLock LED to output and low
  setPinOutput(B3);
  writePinLow(B3);
}

//function for layer indicator LED
uint32_t layer_state_set_user(uint32_t state)
{
  if (state & (1<<1)) {
    writePinHigh(B1);
  } else {
    writePinLow(B1);
  }
  if (state & (1<<2)) {
    writePinHigh(B2);
  } else {
    writePinLow(B2);
  }
  if (state & (1<<3)) {
    writePinHigh(B3);
  } else {
    writePinLow(B3);
  }
  return state;
}
