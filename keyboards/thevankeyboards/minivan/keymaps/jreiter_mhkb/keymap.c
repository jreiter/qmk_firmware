#include QMK_KEYBOARD_H

enum {
  TD_LBRC_RBRC = 0,
  TD_MINS_EQL
};

qk_tap_dance_action_t tap_dance_actions[] = {
  [TD_LBRC_RBRC] = ACTION_TAP_DANCE_DOUBLE(KC_LBRC, KC_RBRC),
  [TD_MINS_EQL] = ACTION_TAP_DANCE_DOUBLE(KC_MINS, KC_EQL)
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 *
 * ,---------+------+------+------+------+------+------+------+------+------+------+-------------.
 * |Hyper/Tab|   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  |   Bksp      |
 * |---------`------`------`------`------`------`------`------`------`------`------`-------------|
 * | Ctrl/Esc |   A  |   S  | MC/D |   F  |   G  |   H  |   J  |   K  |   L  |GUI/; |   Alt/"    |
 * |----------`------`------`------`------`------`------`------`------`------`------`------------|
 * |   Shift   |   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |  Sft/Ent  |
 * |-----------`------`------`------`------`-----'-------`------`------`------`------`-----------|
 * |   Alt   |   GUI   |  Lower  |    TC/Space    |   TC/Space     |  Raise  |   Vol+  |  Play   |
 *  `--------+---------+---------+------^^^-------+-----^^^--------+---------+---------+---------'
 */
[0] = LAYOUT_arrow_command(
    KC_GESC,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,  KC_I,             KC_O,   KC_P,    KC_BSPC,
    KC_TAB,   KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,  KC_K,             KC_L,   KC_SCLN, KC_ENT,
    KC_LSFT,  KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,  KC_COMM,          KC_DOT, KC_SLSH, MO(3),
    KC_TRNS,  KC_LCTL, KC_LGUI, KC_LALT, MO(1),   KC_SPC,  KC_RGUI, MO(2), TD(TD_LBRC_RBRC), KC_TRNS
    ),
[1] = LAYOUT_arrow_command(
    KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,     KC_9,     KC_0,    TD(TD_MINS_EQL),
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_LEFT, KC_DOWN, KC_UP,    KC_RIGHT, KC_QUOT, KC_BSLS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS,  KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS
    ),
[2] = LAYOUT_arrow_command(
    KC_TRNS, KC_MRWD, KC_MPLY, KC_MFFD, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_VOLD, KC_VOLU, KC_MUTE, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
    ),
[3] = LAYOUT_arrow_command(
    KC_TRNS, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,   KC_F11,
    KC_TRNS, KC_TRNS, KC_VOLD, KC_VOLU, KC_MUTE, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
    )
};
