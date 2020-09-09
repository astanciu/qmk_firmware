 /* Copyright 2019 Alec P.
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
#include "quantum.h"

// Layer names
enum{
  // - Base layer:
  _BASE,
  // - Symbols, numbers, and functions:
  _FN1,
  // - Alternate Function layer:
  _FN2,
    // - HYPE-BOI MLG BBY! layer:
  _GAME,
  _FN3
};

//Tap Dance Declarations
enum {
  TD_SLSH_RSFT = 0
};

//Tap Dance Definitions
qk_tap_dance_action_t tap_dance_actions[] = {
  //Tap once for /?, twice for Enter
  [TD_SLSH_RSFT]  = ACTION_TAP_DANCE_DOUBLE(KC_SLSH, KC_RSFT)
};

#define SlShft TD(TD_SLSH_RSFT)
#define XXXXXX KC_TRNS

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* Default QWERTY layer
     * ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┐   ┌───┐
     * │Esc│ Q │ W │ E │ R │ T │ Y │ U │ I │ O │ P │Del│BkS│   │PgU│
     * ├───┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴───┤   ├───┤
     * │Tab │ A │ S │ D │ F │ G │ H │ J │ K │ L │ ' │Enter │   │PgD│
     * ├────┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴──┬───┘   ├───┤
     * │LShift│ Z │ X │ C │ V │ B │ N │ M │ , │ . │Sft/│ ┌───┐ │TO3│
     * ├────┬─┴─┬─┴──┬┴───┴───┴─┬─┴───┴──┬┴───│───┴┬───┘ │ ↑ │ └───┘
     * │LCtl│OS │LAlt│    Fn    │  Space │RAlt│ Ln │ ┌───┤───├───┐
     * └────┴───┴────┴──────────┴────────┴────┴────┘ │ ← │ ↓ │ → │
     *                                               └───┴───┴───┘
     */
    [_BASE] = LAYOUT_split_space(
        KC_ESC,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_DEL, KC_BSPC,    KC_PGUP,
        KC_TAB,   KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_QUOTE,   KC_ENTER,       MO(_FN2),
        KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT, RSFT_T(KC_SLSH),    KC_UP, TO(_GAME),
        KC_LCTL, KC_LALT, KC_LGUI, MO(_FN1), KC_SPACE, MO(_FN1),   MO(_FN2),  KC_LEFT, KC_DOWN, KC_RIGHT
    ),
    /* Main Numbers, Symbols & Function Layer (MOMENTARY)
     * ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┐   ┌───┐
     * │   │ 1  │ 2 │ 3 │ 4 │ 5  │ 6 │ 7 │ 8  │ 9 │ 0 │ \ │   │    │Hme│
     * ├───┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴───┤   ├───┤
     * │    │ 1  │ 2 │ 3 │ 4 │ 5  │ 6 │ 7 │ 8  │ 9 │ 0 │      │    │End│
     * ├────┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴──┬───┘    ├───┤
     * │      │ ( │ )  │ ; │ .  │   │ - │ + │ *  │ / │ =  │  ┌───┐ │   │
     * ├────┬─┴─┬─┴──┬┴───┴───┴─┬─┴───┴──┬┴───│───┴┬───┘  │   │ └───┘
     * │    │   │     │           │        │     │     │ ┌───┤───├───┐
     * └────┴───┴────┴──────────┴────────┴────┴────┘  │   │   │   │
     *                                                    └───┴───┴───┘
     */

    [_FN1] = LAYOUT_split_space(
        XXXXXX, KC_1,    KC_2,    KC_3,     KC_4,       KC_5,    KC_6,      KC_7,       KC_8,       KC_9,       KC_0,       KC_MINS,    KC_EQL,  KC_HOME,
        XXXXXX, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS,    KC_TRNS, KC_TRNS,   KC_TRNS,    KC_LBRC,    KC_RBRC,    KC_SCLN,    KC_ENTER,   KC_END,
        XXXXXX, XXXXXX, XXXXXX, XXXXXX,  XXXXXX, XXXXXX,  XXXXXX, XXXXXX, XXXXXX, XXXXXX, KC_RSFT, XXXXXX,     XXXXXX,
        XXXXXX, XXXXXX, XXXXXX, XXXXXX,                      XXXXXX,           XXXXXX,   XXXXXX,       XXXXXX, XXXXXX, XXXXXX
    ),

    /* ALTERNATE Function layer (MOMENTARY)
     * ┌────┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┐
     * │ PWR│F1 │F2  │F3 │ F4 │F5 │F6 │ F7 │F8 │F9 │F10│PRV│NXT│    │VL+│
     * ├────┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴───┼───┼───┤
     * │ SLP │    │   │   │    │   │   │   │   │   │     │ PLAY │     │VL-│
     * ├─────┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴──┬───┴───│───│
     * │ WAKE  │   │   │   │   │   │   │   │   │   │    │ ┌───┐ │   │
     * ├────┬──┴─┬─┴──┬┴───┴───┴─┬─┴───┴──┬┴───│───┴┬───┘ │   │ └───┘
     * │RSET│    │    │          │        │    │    │ ┌───│───│───┐
     * └────┴────┴────┴──────────┴────────┴────┴────┘ │   │   │   │
     *                                                └───┴───┴───┘
     */
    [_FN2] = LAYOUT_split_space(
        KC_PWR,  KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,    KC_MPRV, KC_MNXT,    KC_VOLU,
        KC_SLEP,   XXXXXX,    XXXXXX,    XXXXXX,    XXXXXX,    XXXXXX,    XXXXXX,    XXXXXX,    XXXXXX,    XXXXXX,    XXXXXX,   KC_MPLY,         KC_VOLD,
        KC_WAKE,     XXXXXX,    XXXXXX,    XXXXXX,    XXXXXX,    XXXXXX,    XXXXXX,    XXXXXX,    XXXXXX, XXXXXX, XXXXXX,        XXXXXX,     XXXXXX,
        RESET,      XXXXXX,     XXXXXX,             XXXXXX,             XXXXXX,            XXXXXX,   XXXXXX,           XXXXXX, XXXXXX, XXXXXX
    ),

    /* GAME HYPE MLG BBY Layer (TOGGLE)
     * ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┐
     * │Esc│ Q │ W │ E │ R │ T │ Y │ U │ I │ O │ P │Del│BkS│   │INS│
     * ├───┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴───┼───┼───┤
     * │Tab │ A │ S │ D │ F │ G │ H │ J │ K │ L │ ; │Enter │   │PgD│
     * ├────┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴──┬───┴───│───│
     * │LShift│ Z │ X │ C │ V │ B │ N │ M │ , │ . │Sft/│ ┌───┐ │LY0│
     * ├────┬─┴─┬─┴──┬┴───┴───┴─┬─┴───┴──┬┴───│───┴┬───┘ │ ↑ │ └───┘
     * │LCtl│OS │LAlt│   Space  │  Space │ Fn │ Ln │ ┌───│───│───┐
     * └────┴───┴────┴──────────┴─────────────┴────┘ │ ← │ ↓ │ → │
     *                                               └───┴───┴───┘
     */
    [_GAME] = LAYOUT_split_space(
        KC_ESC,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_DEL, KC_BSPC,    KC_INSERT,
        KC_TAB,   KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_QUOTE,   KC_ENTER,       KC_PGUP,
        KC_LSFT,     KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT, RSFT_T(KC_SLSH),        KC_UP,     TO(_BASE),
        KC_LCTL, KC_LGUI, KC_LALT,            KC_SPACE,           MO(_FN3),            MO(_FN1),   MO(_FN2),  KC_LEFT, KC_DOWN, KC_RIGHT
    ),

    [_FN3] = LAYOUT_split_space(
        XXXXXX, KC_1,    KC_2,    KC_3,     KC_4,       KC_5,    KC_6,      KC_7,       KC_8,       KC_9,       KC_0,       KC_MINS,    KC_EQL,  KC_HOME,
        XXXXXX, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS,    KC_TRNS, KC_TRNS,   KC_TRNS,    KC_LBRC,    KC_RBRC,    KC_SCLN,    KC_ENTER,   KC_END,
        XXXXXX, XXXXXX, XXXXXX, XXXXXX,  XXXXXX, XXXXXX,  XXXXXX, XXXXXX, XXXXXX, XXXXXX, KC_RSFT, XXXXXX,     XXXXXX,
        XXXXXX, XXXXXX, XXXXXX, XXXXXX,                      XXXXXX,           XXXXXX,   XXXXXX,       XXXXXX, XXXXXX, XXXXXX
    ),
};

//function for layer indicator LED
uint32_t layer_state_set_user(uint32_t state)
{
    if (biton32(state) == 1) {
    writePinHigh(D0);
	} else {
		writePinLow(D0);
    }
    if (biton32(state) == 2) {
    writePinHigh(D1);
	} else {
		writePinLow(D1);
    }
    if (biton32(state) == 3) {
    writePinHigh(D2);
	} else {
		writePinLow(D2);
    }
    return state;
}

void encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) {
        if (clockwise) {
            tap_code(KC_VOLU);
        } else {
            tap_code(KC_VOLD);
        }
    }
}
