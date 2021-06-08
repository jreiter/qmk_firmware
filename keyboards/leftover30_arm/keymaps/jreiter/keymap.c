/* Copyright 2020 marksard
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.  You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include QMK_KEYBOARD_H

enum layer_number {
    _BASE,
    _LOWER,
    _RAISE,
    _ADJUST,
};

enum custom_keycodes {
    RGBRST = SAFE_RANGE,
    LOWER,
    RAISE
};

#define KC_MQL TD(TD_MINS_EQL)
#define KC_9LB TD(TD_9_LBRC)
#define KC_0RB TD(TD_0_RBRC)

// #define KC_ESAD  LT(_ADJUST, KC_ESC)
// #define KC_BSLO  LT(_LOWER, KC_BSPC)
#define KC_LOWR  MO(_LOWER)
#define KC_SPRA  LT(_RAISE, KC_SPC)
#define KC_AJST  MO(_ADJUST)

#define KC_LSZ LSFT_T(KC_Z)
#define KC_RSSL LSFT_T(KC_SLSH)
#define KC_LCTF LCTL_T(KC_F)
#define KC_RCTJ RCTL_T(KC_J)
#define KC_LGD LGUI_T(KC_D)
#define KC_RGK RGUI_T(KC_K)
#define KC_LAS LALT_T(KC_S)


enum {
  TD_MINS_EQL = 0,
  TD_9_LBRC,
  TD_0_RBRC
};

qk_tap_dance_action_t tap_dance_actions[] = {
  [TD_MINS_EQL] = ACTION_TAP_DANCE_DOUBLE(KC_MINS, KC_EQL),
  [TD_9_LBRC] = ACTION_TAP_DANCE_DOUBLE(KC_9, KC_LBRC),
  [TD_0_RBRC] = ACTION_TAP_DANCE_DOUBLE(KC_0, KC_RBRC)
};

enum combo_events {
  QW_ESC,
  LSCLN_ENT,
  AS_TAB,
  ONETWO_GRV
};

const uint16_t PROGMEM esc_combo[] = {KC_Q, KC_W, COMBO_END};
const uint16_t PROGMEM enter_combo[] = {KC_L, KC_SCLN, COMBO_END};
const uint16_t PROGMEM tab_combo[] = {KC_A, KC_S, COMBO_END};
const uint16_t PROGMEM grv_combo[] = {KC_1, KC_2, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
  [QW_ESC] = COMBO(esc_combo, KC_ESC),
  [LSCLN_ENT] = COMBO(enter_combo, KC_ENTER),
  [AS_TAB] = COMBO(tab_combo, KC_TAB),
  [ONETWO_GRV] = COMBO(grv_combo, KC_GRV)
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = LAYOUT_all(
  //,-----------------------------------------------------------------------------------------------------------.
               KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,   KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|--------+--------+--------+--------+--------+--------|
               KC_A,    KC_LAS,  KC_LGD,  KC_LCTF, KC_G,    KC_H,    KC_RCTJ, KC_RGK,  KC_L,       KC_SCLN,
  //|--------+--------+--------+--------+--------+--------|--------+--------+--------+--------+--------+--------|
               KC_LSZ,  KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,     KC_RSSL,
  //|--------+--------+--------+--------+--------+--------|--------+--------+--------+--------+--------+--------|
      KC_MUTE, KC_LGUI,                                KC_SPRA,                                KC_AJST,  KC_LOWR
  //`-----------------------------------------------------------------------------------------------------------'
  ),

  [_LOWER] = LAYOUT_all(
  //,-----------------------------------------------------------------------------------------------------------.
               KC_F1,  KC_F2,   KC_F3,   KC_F4,   KC_F5,    KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10, KC_F11,
  //|--------+--------+--------+--------+--------+--------|--------+--------+--------+--------+--------+--------|
               KC_TRNS,KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,     KC_TRNS,
  //|--------+--------+--------+--------+--------+--------|--------+--------+--------+--------+--------+--------|
               KC_TRNS,KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,     KC_TRNS,
  //|--------+--------+--------+--------+--------+--------|--------+--------+--------+--------+--------+--------|
      _______, _______,                                KC_AJST,                                 _______, _______
  //`-----------------------------------------------------------------------------------------------------------'
  ),

  [_RAISE] = LAYOUT_all(
  //,-----------------------------------------------------------------------------------------------------------.
               KC_1,   KC_2,    KC_3,    KC_4,    KC_5,     KC_6,    KC_7,    KC_8,   KC_9LB,  KC_0RB,  KC_MQL,
  //|--------+--------+--------+--------+--------+--------|--------+--------+--------+--------+--------+--------|
               KC_TRNS,KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_LEFT, KC_DOWN, KC_UP,  KC_RIGHT,     KC_QUOT,
  //|--------+--------+--------+--------+--------+--------|--------+--------+--------+--------+--------+--------|
               KC_TRNS,KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS,KC_TRNS,      KC_BSLS,
  //|--------+--------+--------+--------+--------+--------|--------+--------+--------+--------+--------+--------|
      _______, _______,                                _______,                                 _______, _______
  //`-----------------------------------------------------------------------------------------------------------'
  ),

  [_ADJUST] = LAYOUT_all(
  //,-----------------------------------------------------------------------------------------------------------.
                 RESET,  RGBRST, XXXXXXX, XXXXXXX, XXXXXXX, KC_HOME, KC_PGDN, KC_PGUP,  KC_END,  KC_INS, KC_PSCR,
  //|--------+--------+--------+--------+--------+--------|--------+--------+--------+--------+--------+--------|
               RGB_TOG, RGB_HUI, RGB_SAI, RGB_VAI, XXXXXXX, KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R,     KC_NLCK,
  //|--------+--------+--------+--------+--------+--------|--------+--------+--------+--------+--------+--------|
               RGB_MOD, RGB_HUD, RGB_SAD, RGB_VAD, XXXXXXX, KC_BTN1, KC_BTN2, XXXXXXX, XXXXXXX,     XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|--------+--------+--------+--------+--------+--------|
      _______, _______,                                _______,                                 _______, _______
  //`-----------------------------------------------------------------------------------------------------------'
  )
};

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case KC_SPRA:
      return TAPPING_LAYER_TERM;
    case KC_LSZ:
    case KC_RSSL:
      return TAPPING_SHIFT_TERM;
    case KC_LAS:
    case KC_LGD:
    case KC_LCTF:
    case KC_RCTJ:
    case KC_RGK:
      return TAPPING_HM_TERM;
    default:
      return TAPPING_TERM;
  }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {

  bool result = false;
  switch (keycode) {
#ifdef RGBLIGHT_ENABLE
    case RGBRST:
        if (record->event.pressed) {
          eeconfig_update_rgblight_default();
          rgblight_enable();
        }
    break;
#endif
    default:
      result = true;
      break;
  }

  return result;
}

void encoder_update_user(uint8_t index, bool clockwise) {
  if (IS_LAYER_ON(_ADJUST)) {
    if (clockwise) {
      rgblight_increase_hue_noeeprom();
    } else {
      rgblight_decrease_hue_noeeprom();
    }
  } else {
    tap_code((clockwise == true) ? KC__VOLDOWN : KC__VOLUP);
  }
}

// for exsample customize of LED inducator
bool led_update_user(led_t led_state) {
    writePin(B10, IS_LAYER_ON(_LOWER));
    writePin(B11, IS_LAYER_ON(_RAISE));
    return false;
}
