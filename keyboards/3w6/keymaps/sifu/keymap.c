/* Copyright 2021 weteor
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

enum layers {
    _QWERTY = 0,
    _NAV,
    _NUM,
    _BRC,
    _SYM,
    _WIN,
    _TMUX,
    _MOUSE,
};

enum custom_keycodes {
  // tmux
  T_ALT = SAFE_RANGE,
  T_NEW,
  T_1,
  T_2,
  T_3,
  T_4,
  T_5,
  T_6,
  T_7,
  T_8,
  T_9,
};

#define SFT_Z     MT( MOD_LSFT, KC_Z    )
#define ALT_S     MT( MOD_LALT, KC_S    )
#define CTL_D     MT( MOD_LCTL, KC_D    )
#define NUM_F     LT( _NUM, KC_F )
#define BRC_J     LT( _BRC, KC_J    )
#define CTL_K     MT( MOD_LCTL, KC_K    )
#define ALT_L     MT( MOD_LALT, KC_L    )
#define SFT_SLSH  MT( MOD_LSFT, KC_SLSH )

#define WIN_W     LT( _WIN, KC_W )
#define TMUX_T    LT( _TMUX, KC_T )
#define NAV_BSPC  LT( _NAV, KC_BSPC )
#define SYM_ENT   LT( _SYM, KC_ENT )
#define SYM_ESC   LT( _SYM, KC_ESC )
#define EUR       LSA( KC_2 )
#define TEAM_MUTE LSG( KC_M )

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_QWERTY] = LAYOUT(
      KC_Q , WIN_W  , KC_E   , KC_R   , TMUX_T,                          KC_Y   , KC_U      , KC_I  , KC_O   , KC_P    ,
      KC_A , ALT_S  , CTL_D  , NUM_F  , KC_G  ,                          KC_H   , BRC_J     , CTL_K , ALT_L  , KC_SCLN ,
      SFT_Z, KC_X   , KC_C   , KC_V   , KC_B  ,                          KC_N   , KC_M      ,KC_COMM, KC_DOT , SFT_SLSH ,

                             SYM_ESC, NAV_BSPC, KC_LGUI,        EUR    , KC_SPC , SYM_ENT
    ),

    [_NUM] = LAYOUT(
      _______, _______, _______, _______, _______,                            KC_ASTR,  KC_7, KC_8, KC_9, KC_EQL ,
      _______, _______, _______, _______, _______,                            KC_PLUS,  KC_4, KC_5, KC_6, KC_0   ,
      _______, _______, _______, _______, _______,                            KC_MINUS, KC_1, KC_2, KC_3, KC_PIPE,

                                 _______, _______, _______,          _______, _______, _______
    ),

    [_BRC] = LAYOUT(
      KC_EXLM, KC_AT  , KC_LCBR, KC_RCBR, KC_PERCENT,                         KC_ASTR,  KC_7, KC_8, KC_9, KC_EQL ,
      KC_LABK, KC_RABK, KC_LBRC, KC_RBRC, KC_DOLLAR,                          KC_PLUS,  KC_4, KC_5, KC_6, KC_0   ,
      LSA(KC_GRV),KC_TILDE, KC_LPRN, KC_RPRN, KC_BSLASH,                      KC_MINUS, KC_1, KC_2, KC_3, KC_PIPE,

                                 _______, _______, _______,          _______, _______, _______
    ),

    [_NAV] = LAYOUT(
      _______, _______, _______ , _______, _______,                           _______, _______, _______, _______, _______,
      _______, KC_MPRV, KC_PAUSE, KC_MNXT, _______,                           KC_LEFT, KC_DOWN, KC_UP  , KC_RGHT, _______,
      _______, _______, _______ , _______, _______,                           KC_HOME, KC_PGDN, KC_PGUP, KC_END , _______,

                                  _______, _______, _______,         _______, KC_TAB , _______
    ),

    [_SYM] = LAYOUT(
      KC_EXLM    , KC_AT   , KC_HASH, KC_DLR , KC_PERC,                            KC_CIRC, KC_AMPR , KC_ASTR, KC_PLUS, KC_MINUS ,
      KC_EQL     , KC_RABK , EUR    , _______, _______,                            _______, KC_QUOTE, KC_DQT , _______, KC_UNDS  ,
      LSA(KC_GRV), KC_TILDE, _______, _______, _______,                            _______, _______ , _______, KC_PIPE, KC_BSLASH,

                                      _______, _______, _______,          _______, _______, _______
    ),

    [_WIN] = LAYOUT(
      _______, _______, _______, _______, _______,                            LSA(KC_H), LSA(KC_J) , LSA(KC_U) , LSA(KC_L) , _______,
      _______, _______, _______, _______, _______,                            _______  , LGUI(KC_4), LGUI(KC_5), LGUI(KC_6), _______,
      _______, _______, _______, _______, _______,                            _______  , LGUI(KC_1), LGUI(KC_2), LGUI(KC_3), _______,

                                 _______, _______, _______,          _______, _______, _______
    ),

    [_TMUX] = LAYOUT(
      _______, _______, _______, _______, _______,                            _______, T_7, T_8, T_9, _______,
      _______, _______, _______, _______, _______,                            _______, T_4, T_5, T_6, T_ALT  ,
      _______, _______, _______, _______, _______,                            T_NEW  , T_1, T_2, T_3, _______,

                                 _______, _______, _______,          _______, _______, _______
    ),

    [_MOUSE] = LAYOUT(
      _______, KC_BTN1    , KC_MS_UP   , KC_BTN2    , _______,                       _______, _______, _______, _______, _______,
      _______, KC_MS_LEFT , KC_MS_DOWN , KC_MS_RIGHT, _______,                       _______, KC_ACL0, KC_ACL1, KC_ACL2, _______,
      _______, _______    , _______    , _______    , _______,                       _______, _______, _______, _______, _______,
                                         KC_BTN1    , _______, _______,     _______, _______, _______
    ),
};


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
    switch (keycode) {
      case T_1:
        SEND_STRING( SS_LCTL("y") "1" );
        break;
      case T_2:
        SEND_STRING( SS_LCTL("y") "2" );
        break;
      case T_3:
        SEND_STRING( SS_LCTL("y") "3" );
        break;
      case T_4:
        SEND_STRING( SS_LCTL("y") "4" );
        break;
      case T_5:
        SEND_STRING( SS_LCTL("y") "5" );
        break;
      case T_6:
        SEND_STRING( SS_LCTL("y") "6" );
        break;
      case T_7:
        SEND_STRING( SS_LCTL("y") "7" );
        break;
      case T_8:
        SEND_STRING( SS_LCTL("y") "8" );
        break;
      case T_9:
        SEND_STRING( SS_LCTL("y") "9" );
        break;
      case T_ALT:
        SEND_STRING( SS_LCTL("yy") );
        break;
      case T_NEW:
        SEND_STRING( SS_LCTL("y") "t" );
        break;
    }
  }
  return true;
};
