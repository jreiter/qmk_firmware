/* Copyright 2020 Worldspawn <mcmancuso@gmail.com>
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
};

qk_tap_dance_action_t tap_dance_actions[] = {
  [TD_MINS_EQL] = ACTION_TAP_DANCE_DOUBLE(KC_MINS, KC_EQL),
  [TD_9_LBRC] = ACTION_TAP_DANCE_DOUBLE(KC_9, KC_LBRC),
  [TD_0_RBRC] = ACTION_TAP_DANCE_DOUBLE(KC_0, KC_RBRC)
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [0] = LAYOUT_stagger(
        KC_GESC,  KC_Q,     KC_W,     KC_E,   KC_R,           KC_T,    KC_Y,   KC_U,     KC_I,     KC_O,    KC_P,            KC_DEL,  KC_BSPC,  KC_MUTE,
        KC_TAB,   KC_A,     KC_S,     KC_D,   KC_F,           KC_G,    KC_H,   KC_J,     KC_K,     KC_L,    KC_SCLN,         KC_ENT,
        KC_LSFT,  KC_Z,     KC_X,     KC_C,   KC_V,           KC_B,    KC_N,   KC_M,     KC_COMM,  KC_DOT,  LT(3, KC_SLSH),  KC_UP,
        KC_LCTL,  KC_LALT,  KC_LGUI,  MO(1),  LT(2, KC_SPC),  KC_RGUI, MO(4),  KC_LEFT,  KC_DOWN,  KC_RGHT
    ),

    [1] = LAYOUT_stagger(
        KC_GRV,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     TD(TD_9_LBRC),  TD(TD_0_RBRC),   KC_MINS, KC_EQL, KC_TRNS,
        KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_QUOT,        KC_SCLN,         KC_BSLS,
        KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,        KC_TRNS,         KC_TRNS,
        KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS
    ),

    [2] = LAYOUT_stagger(
        KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,
        KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_LEFT,  KC_DOWN,  KC_UP,    KC_RGHT,  KC_TRNS,  KC_TRNS,
        KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,
        KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS
    ),

    [3] = LAYOUT_stagger(
        KC_TRNS, KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,   KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
    ),

    [4] = LAYOUT_stagger(
        RESET,    KC_MRWD,  KC_MPLY,  KC_MFFD,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  EEPROM_RESET,  KC_TRNS,
        KC_TRNS,  KC_TRNS,  KC_VOLU,  KC_VOLD,  KC_MUTE,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,
        RGB_MOD,  RGB_HUI,  RGB_HUD,  RGB_SAI,  RGB_SAD,  RGB_VAI,  RGB_VAD,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,
        KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS
    )
};

void matrix_init_user(void) {
  setPinOutput(B5);
  writePinLow(B5);
  setPinOutput(B6);
  writePinLow(B6);
  setPinOutput(B7);
  writePinLow(B7);
}

uint32_t layer_state_set_user(uint32_t state)
{
  if (state & (1<<1)) {
    writePinHigh(B7);
    writePinLow(B6);
  } else if (state & (1<<2)) {
    writePinLow(B7);
    writePinHigh(B6);
  } else if (state & (1<<3)) {
    writePinHigh(B7);
    writePinHigh(B6);
  } else {
    writePinLow(B7);
    writePinLow(B6);
  }
  return state;
}

bool led_update_user(led_t led_state) {
    writePin(B5, led_state.caps_lock);
    return false;
}

void encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) {
        if (clockwise) {
            tap_code(KC_VOLD);
        } else {
            tap_code(KC_VOLU);
        }
    }
}
