/* Copyright 2019 Thomas Baart <thomas@splitkb.com>
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
     _______, KC_Q , WIN_W  , KC_E   , KC_R   , TMUX_T,                                          KC_Y   , KC_U      , KC_I  , KC_O   , KC_P    , _______ ,
     _______, KC_A , ALT_S  , CTL_D  , NUM_F  , KC_G  ,                                          KC_H   , BRC_J     , CTL_K , ALT_L  , KC_SCLN , _______,
     _______, SFT_Z, KC_X   , KC_C   , KC_V   , KC_B  , _______ , _______,     _______, _______, KC_N   , KC_M      ,KC_COMM, KC_DOT , SFT_SLSH , _______,
                              KC_MUTE, _______,SYM_ESC, NAV_BSPC, KC_LGUI,     EUR    , KC_SPC , SYM_ENT, TT(_MOUSE),TEAM_MUTE
    ),

    [_NUM] = LAYOUT(
      _______, _______, _______, _______, _______, _______,                                     KC_ASTR,  KC_7, KC_8, KC_9, KC_EQL , _______,
      _______, _______, _______, _______, _______, _______,                                     KC_PLUS,  KC_4, KC_5, KC_6, KC_0   , _______,
      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_MINUS, KC_1, KC_2, KC_3, KC_PIPE, _______,
                                 _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),

    [_BRC] = LAYOUT(
     _______, KC_EXLM, KC_AT  , KC_LCBR, KC_RCBR, KC_PERCENT,                                         KC_ASTR,  KC_7, KC_8, KC_9, KC_EQL , _______,
     _______, KC_LABK, KC_RABK, KC_LBRC, KC_RBRC, KC_DOLLAR,                                          KC_PLUS,  KC_4, KC_5, KC_6, KC_0   , _______,
     _______, LSA(KC_GRV) ,KC_TILDE, KC_LPRN, KC_RPRN, KC_BSLASH, _______, _______, _______, _______, KC_MINUS, KC_1, KC_2, KC_3, KC_PIPE, _______,
                                 _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),

    [_NAV] = LAYOUT(
      _______, _______, _______, _______ , _______, _______,                                     _______, _______, _______, _______,  _______, _______,
      _______, _______, KC_MPRV, KC_PAUSE, KC_MNXT, _______,                                     KC_LEFT, KC_DOWN, KC_UP  , KC_RGHT, _______, _______,
      _______, _______, _______, _______ , _______, _______, _______, _______, _______, _______, KC_HOME, KC_PGDN, KC_PGUP, KC_END , _______, _______,
                                 _______ , _______, KC_CAPS, _______, _______, _______, KC_TAB , _______, _______, _______
    ),

    [_SYM] = LAYOUT(
      _______, KC_EXLM    , KC_AT   , KC_HASH, KC_DLR , KC_PERC,                                         KC_CIRC, KC_AMPR , KC_ASTR, KC_PLUS, KC_MINUS , _______,
      _______, KC_EQL     , KC_RABK , EUR    , _______, _______,                                         _______, KC_QUOTE, KC_DQT , _______, KC_UNDS  , _______,
      _______, LSA(KC_GRV), KC_TILDE, _______, _______, _______, _______, _______,     _______, _______, _______, _______ , _______, KC_PIPE, KC_BSLASH, _______,
                                      _______, _______, _______, _______, _______,     _______, _______, _______, _______ , _______
    ),

    [_WIN] = LAYOUT(
      _______, _______, _______, _______, _______, _______,                                     LSA(KC_H), LSA(KC_J) , LSA(KC_U) , LSA(KC_L) , _______, _______,
      _______, _______, _______, _______, _______, _______,                                     _______  , LGUI(KC_4), LGUI(KC_5), LGUI(KC_6), _______, _______,
      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______  , LGUI(KC_1), LGUI(KC_2), LGUI(KC_3), _______, _______,
                                 _______, _______, _______, _______, _______, _______, _______, _______  , _______, _______
    ),

    [_TMUX] = LAYOUT(
      _______, _______, _______, _______, _______, _______,                                     _______, T_7, T_8, T_9, _______, _______,
      _______, _______, _______, _______, _______, _______,                                     _______, T_4, T_5, T_6, T_ALT  , _______,
      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, T_NEW  , T_1, T_2, T_3, _______, _______,
                                 _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),

    [_MOUSE] = LAYOUT(
      _______, _______, KC_BTN1    , KC_MS_UP   , KC_BTN2    , _______,                                         _______, _______, _______, _______, _______, _______,
      _______, _______, KC_MS_LEFT , KC_MS_DOWN , KC_MS_RIGHT, _______,                                         _______, KC_ACL0, KC_ACL1, KC_ACL2, _______, _______,
      _______, _______, _______    , _______    , _______    , _______, _______, _______,     _______, _______, _______, _______, _______, _______, _______, _______,
                                         KC_BTN1    , _______, _______, _______, _______,     _______, _______, _______, _______, _______
    ),

//  * Layer template
//     [_LAYERINDEX] = LAYOUT(
//       _______, _______, _______, _______, _______, _______,                                     _______, _______, _______, _______, _______, _______,
//       _______, _______, _______, _______, _______, _______,                                     _______, _______, _______, _______, _______, _______,
//       _______, _______, _______, _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______, _______, _______, _______,
//                                  _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______
//     ),
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

/* LEADER_EXTERNS(); */
/* void matrix_scan_user(void) { */
/*   LEADER_DICTIONARY() { */
/*     leading = false; */
/*     leader_end(); */

/*     // switch between terminal and browser, in combination with better touch tool */
/*     SEQ_ONE_KEY(KC_LEAD) { */
/*       SEND_STRING(SS_LSFT(SS_LGUI("6"))); */
/*     } */

/*     // copy & pase */
/*     SEQ_ONE_KEY(KC_C) { */
/*       SEND_STRING(SS_LGUI("c")); */
/*     } */
/*     SEQ_ONE_KEY(KC_V) { */
/*       SEND_STRING(SS_LGUI("v")); */
/*     } */
  
/*     // for umlauts */
/*     SEQ_ONE_KEY(KC_U) { */
/*       SEND_STRING(SS_LALT("u")); */
/*     } */
/*     SEQ_TWO_KEYS(KC_U, KC_U) { */
/*       SEND_STRING(SS_LALT("u") "u"); */
/*     } */
/*     SEQ_TWO_KEYS(KC_U, KC_A) { */
/*       SEND_STRING(SS_LALT("u") "a"); */
/*     } */
/*     SEQ_TWO_KEYS(KC_U, KC_O) { */
/*       SEND_STRING(SS_LALT("u") "o"); */
/*     } */
    
/*     // caps lock */
/*     SEQ_ONE_KEY(KC_F) { */
/*       SEND_STRING(SS_TAP(X_CAPS)); */
/*     } */
    
/*     /1* SEQ_TWO_KEYS(KC_W, KC_M) { *1/ */
/*     /1*   SEND_STRING(SS_LGUI("1")); *1/ */
/*     /1* } *1/ */

/*   } */
/* } */

#ifdef OLED_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) { return OLED_ROTATION_180; }

void oled_task_user(void) {
  if (is_keyboard_master()) {
    // clang-format off
    static const char PROGMEM qmk_logo[] = {
      0x80,0x81,0x82,0x83,0x84,0x85,0x86,0x87,0x88,0x89,0x8a,0x8b,0x8c,0x8d,0x8e,0x8f,0x90,0x91,0x92,0x93,0x94,
      0xa0,0xa1,0xa2,0xa3,0xa4,0xa5,0xa6,0xa7,0xa8,0xa9,0xaa,0xab,0xac,0xad,0xae,0xaf,0xb0,0xb1,0xb2,0xb3,0xb4,
      0xc0,0xc1,0xc2,0xc3,0xc4,0xc5,0xc6,0xc7,0xc8,0xc9,0xca,0xcb,0xcc,0xcd,0xce,0xcf,0xd0,0xd1,0xd2,0xd3,0xd4,0};
        // clang-format on

        oled_write_P(qmk_logo, false);
        oled_write_P(PSTR("\nS I F U\n\n"), false);

        // Host Keyboard Layer Status
        oled_write_P(PSTR("Layer: "), false);
        switch (get_highest_layer(layer_state|default_layer_state)) {
            case _QWERTY:
                oled_write_P(PSTR("QWERTY\n"), false);
                break;
            case _NUM:
                oled_write_P(PSTR("Numbers\n"), false);
                break;
            case _NAV:
                oled_write_P(PSTR("Nav\n"), false);
                break;
            case _BRC:
                oled_write_P(PSTR("Brackets\n"), false);
                break;
            case _SYM:
                oled_write_P(PSTR("Symbols\n"), false);
                break;
            case _WIN:
                oled_write_P(PSTR("Window\n"), false);
                break;
            case _TMUX:
                oled_write_P(PSTR("Tmux\n"), false);
                break;
            case _MOUSE:
                oled_write_P(PSTR("Mouse\n"), false);
                break;
            default:
                oled_write_P(PSTR("Undefined\n"), false);
        }

        // Write host Keyboard LED Status to OLEDs
        led_t led_usb_state = host_keyboard_led_state();
        oled_write_P(led_usb_state.num_lock    ? PSTR("NUMLCK ") : PSTR("       "), false);
        oled_write_P(led_usb_state.caps_lock   ? PSTR("CAPLCK ") : PSTR("       "), false);
        oled_write_P(led_usb_state.scroll_lock ? PSTR("SCRLCK ") : PSTR("       "), false);
    } else {
        // clang-format off
        static const char PROGMEM kyria_logo[] = {
            0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,128,128,192,224,240,112,120, 56, 60, 28, 30, 14, 14, 14,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7, 14, 14, 14, 30, 28, 60, 56,120,112,240,224,192,128,128,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
            0,  0,  0,  0,  0,  0,  0,192,224,240,124, 62, 31, 15,  7,  3,  1,128,192,224,240,120, 56, 60, 28, 30, 14, 14,  7,  7,135,231,127, 31,255,255, 31,127,231,135,  7,  7, 14, 14, 30, 28, 60, 56,120,240,224,192,128,  1,  3,  7, 15, 31, 62,124,240,224,192,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
            0,  0,  0,  0,240,252,255, 31,  7,  1,  0,  0,192,240,252,254,255,247,243,177,176, 48, 48, 48, 48, 48, 48, 48,120,254,135,  1,  0,  0,255,255,  0,  0,  1,135,254,120, 48, 48, 48, 48, 48, 48, 48,176,177,243,247,255,254,252,240,192,  0,  0,  1,  7, 31,255,252,240,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
            0,  0,  0,255,255,255,  0,  0,  0,  0,  0,254,255,255,  1,  1,  7, 30,120,225,129,131,131,134,134,140,140,152,152,177,183,254,248,224,255,255,224,248,254,183,177,152,152,140,140,134,134,131,131,129,225,120, 30,  7,  1,  1,255,255,254,  0,  0,  0,  0,  0,255,255,255,  0,  0,  0,  0,255,255,  0,  0,192,192, 48, 48,  0,  0,240,240,  0,  0,  0,  0,  0,  0,240,240,  0,  0,240,240,192,192, 48, 48, 48, 48,192,192,  0,  0, 48, 48,243,243,  0,  0,  0,  0,  0,  0, 48, 48, 48, 48, 48, 48,192,192,  0,  0,  0,  0,  0,
            0,  0,  0,255,255,255,  0,  0,  0,  0,  0,127,255,255,128,128,224,120, 30,135,129,193,193, 97, 97, 49, 49, 25, 25,141,237,127, 31,  7,255,255,  7, 31,127,237,141, 25, 25, 49, 49, 97, 97,193,193,129,135, 30,120,224,128,128,255,255,127,  0,  0,  0,  0,  0,255,255,255,  0,  0,  0,  0, 63, 63,  3,  3, 12, 12, 48, 48,  0,  0,  0,  0, 51, 51, 51, 51, 51, 51, 15, 15,  0,  0, 63, 63,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 48, 48, 63, 63, 48, 48,  0,  0, 12, 12, 51, 51, 51, 51, 51, 51, 63, 63,  0,  0,  0,  0,  0,
            0,  0,  0,  0, 15, 63,255,248,224,128,  0,  0,  3, 15, 63,127,255,239,207,141, 13, 12, 12, 12, 12, 12, 12, 12, 30,127,225,128,  0,  0,255,255,  0,  0,128,225,127, 30, 12, 12, 12, 12, 12, 12, 12, 13,141,207,239,255,127, 63, 15,  3,  0,  0,128,224,248,255, 63, 15,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
            0,  0,  0,  0,  0,  0,  0,  3,  7, 15, 62,124,248,240,224,192,128,  1,  3,  7, 15, 30, 28, 60, 56,120,112,112,224,224,225,231,254,248,255,255,248,254,231,225,224,224,112,112,120, 56, 60, 28, 30, 15,  7,  3,  1,128,192,224,240,248,124, 62, 15,  7,  3,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
            0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  1,  1,  3,  7, 15, 14, 30, 28, 60, 56,120,112,112,112,224,224,224,224,224,224,224,224,224,224,224,224,224,224,224,224,112,112,112,120, 56, 60, 28, 30, 14, 15,  7,  3,  1,  1,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0
        };
        // clang-format on
        oled_write_raw_P(kyria_logo, sizeof(kyria_logo));
    }
}
#endif

#ifdef ENCODER_ENABLE
bool encoder_update_user(uint8_t index, bool clockwise) {
  switch (get_highest_layer(layer_state)) {
    case _QWERTY:
      if (index == 0) {
        // Volume control
        if (clockwise) {
          tap_code(KC_VOLD);
        } else {
          tap_code(KC_VOLU);
        }
      } else if (index == 1) {
        // Page up/Page down
        if (clockwise) {
          tap_code(KC_MS_WH_DOWN);
        } else {
          tap_code(KC_MS_WH_UP);
        }
      }
      break;

    case _MOUSE:
      if (index == 0) {
        // Volume control
        if (clockwise) {
          /* KC_MS_ACCEL2 */
          register_code(KC_MS_ACCEL2);
          tap_code(KC_MS_LEFT);
          unregister_code(KC_MS_ACCEL2);
        } else {
          register_code(KC_MS_ACCEL2);
          tap_code(KC_MS_RIGHT);
          unregister_code(KC_MS_ACCEL2);
        }
      } else if (index == 1) {
        // Page up/Page down
        if (clockwise) {
          register_code(KC_MS_ACCEL2);
          tap_code(KC_MS_UP);
          unregister_code(KC_MS_ACCEL2);
        } else {
          register_code(KC_MS_ACCEL2);
          tap_code(KC_MS_DOWN);
          unregister_code(KC_MS_ACCEL2);
        }
      }
      break;

    default:
      break;

  }
  return false;
}
#endif
