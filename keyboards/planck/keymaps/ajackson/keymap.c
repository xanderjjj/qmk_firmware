/* Copyright 2015-2017 Jack Humbert
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

#include "planck.h"
#include "action_layer.h"

extern keymap_config_t keymap_config;

enum planck_layers {
  _QWERTY,
  _LOWER,
  _RAISE,
  _CSGO,
  _PUBG,
  _ADJUST
};

enum planck_keycodes {
  QWERTY = SAFE_RANGE,
  CSGO,
  PUBG,
  LOWER,
  RAISE,
  BACKLIT,
  EXT_CS,
  EXT_PG
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * ,-----------------------------------------------------------------------------------.
 * | Esc  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Tab  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |  ;:  |  '"  |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |  ,<  |  .>  |  Up  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl |  OS  | Alt  |Raise |Lower |    Space    |Delete|  /?  | Left | Down |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_QWERTY] = {
  {KC_ESC,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC},
  {KC_TAB,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT},
  {KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_UP,   KC_ENT },
  {KC_LCTL, KC_LALT, KC_LGUI, RAISE,   LOWER,   KC_SPC,  KC_SPC,  KC_DEL,  KC_SLSH, KC_LEFT, KC_DOWN, KC_RGHT}
},

/* Lower
 * ,-----------------------------------------------------------------------------------.
 * |      |  F1  |  F2  |  F3  |  F4  |      |      |      |   7  |   8  |   9  | Home |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |  F5  |  F6  |  F7  |  F8  |      |      |      |   4  |   5  |   6  | End  |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |  F9  |  F10 |  F11 |  F12 |      |      |      |   1  |   2  |   3  | Pg ^ |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |Insert|      |   0  |      | Pg v |
 * `-----------------------------------------------------------------------------------'
 */
[_LOWER] = {
  {_______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   _______, _______, _______, KC_7,    KC_8,    KC_9,    KC_HOME},
  {_______, KC_F5,   KC_F6,   KC_F7,   KC_F8,   _______, _______, _______, KC_4,    KC_5,    KC_6,    KC_END},
  {_______, KC_F9,   KC_F10,  KC_F11,  KC_F12,  _______, _______, _______, KC_1,    KC_2,    KC_3,    KC_PGUP},
  {_______, _______, _______, _______, _______, _______, _______, KC_INS,  _______, KC_0,    _______, KC_PGDN}
},

/* Raise
 * ,-----------------------------------------------------------------------------------.
 * |   ~  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |   `  |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   (  |   )  |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |   _  |   +  |   {  |   }  |   |  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |   -  |   =  |   [  |   ]  |   \  |
 * `-----------------------------------------------------------------------------------'
 */
[_RAISE] = {
  {KC_TILD, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _______},
  {KC_GRV,  KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, _______},
  {_______, _______, _______, _______, _______, _______, _______, KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_PIPE},
  {_______, _______, _______, _______, _______, _______, _______, KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_BSLS}
},

/* CSGO layer
 * ,-----------------------------------------------------------------------------------.
 * |  Esc |      |   W  |      |      |      |      |      |      |      |      | Exit |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |  Tab |   A  |   S  |   D  |   G  |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|      |      |      |      |      |      |      |  F1  |  F2  |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl |      |      |   K  |   E  |      R      |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */

[_CSGO] = {
  {KC_ESC,  XXXXXXX, KC_W,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  EXT_CS},
  {KC_TAB,  KC_A,    KC_S,    KC_D,    KC_G,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX},
  {KC_LSFT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_F1,   KC_F2,   XXXXXXX, XXXXXXX},
  {KC_LCTL, XXXXXXX, XXXXXXX, KC_K,    KC_E,    KC_R,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX}
},

/* PUBG layer
 * ,-----------------------------------------------------------------------------------.
 * |  Esc |   Q  |   W  |   E  |      |      |      |      |   7  |   8  |   9  | Exit |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |  Tab |   A  |   S  |   D  |      |      |      |      |   4  |   5  |      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |      |   M  |   1  |   2  |   3  | Pg ^ |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl |      |  Alt |      |   F  |      R      |      |   =  |      |      | Pg v |
 * `-----------------------------------------------------------------------------------'
 */

[_PUBG] = {
  {KC_ESC,  KC_Q,    KC_W,    KC_E,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_7,    KC_8,    KC_9,    EXT_PG},
  {KC_TAB,  KC_A,    KC_S,    KC_D,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_4,    KC_5,    XXXXXXX, XXXXXXX},
  {KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    XXXXXXX, KC_M,    KC_1,    KC_2,    KC_3,    KC_PGUP},
  {KC_LCTL, XXXXXXX, KC_LGUI, XXXXXXX, KC_F,    KC_R,    XXXXXXX, XXXXXXX, KC_EQL,  XXXXXXX, XXXXXXX, KC_PGDN}
},

/* Adjust (Lower + Raise)
 * ,-----------------------------------------------------------------------------------.
 * | Reset|      |      |      |      |      |      |      |      |      | CSGO |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |Voice+|Mus on|Aud on|      |      |      |      |      |      | PUBG |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |Voice-|Musoff|Audoff|      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |   BACKLIT   |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_ADJUST] = {
  {  RESET, _______, _______, _______, _______, _______, _______, _______, _______, _______,    CSGO, _______},
  {_______,  MUV_IN,   MU_ON,   AU_ON, _______, _______, _______, _______, _______, _______,    PUBG, _______},
  {_______,  MUV_DE,  MU_OFF,  AU_OFF, _______, _______, _______, _______, _______, _______, _______, _______},
  {_______, _______, _______, _______, _______, BACKLIT, _______, _______, _______, _______, _______, _______}
}


};

#ifdef AUDIO_ENABLE
  float plover_song[][2]     = SONG(PLOVER_SOUND);
  float plover_gb_song[][2]  = SONG(PLOVER_GOODBYE_SOUND);
#endif

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        print("mode just switched to qwerty and this is a huge string\n");
        set_single_persistent_default_layer(_QWERTY);
      }
      return false;
      break;
    case LOWER:
      if (record->event.pressed) {
        layer_on(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case RAISE:
      if (record->event.pressed) {
        layer_on(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case BACKLIT:
      if (record->event.pressed) {
        register_code(KC_RSFT);
        #ifdef BACKLIGHT_ENABLE
          backlight_step();
        #endif
      } else {
        unregister_code(KC_RSFT);
      }
      return false;
      break;
    case CSGO:
      if (record->event.pressed) {
        #ifdef AUDIO_ENABLE
          stop_all_notes();
          PLAY_SONG(plover_song);
        #endif
        layer_off(_RAISE);
        layer_off(_LOWER);
        layer_off(_ADJUST);
        layer_on(_CSGO);
        if (!eeconfig_is_enabled()) {
            eeconfig_init();
        }
        keymap_config.raw = eeconfig_read_keymap();
        keymap_config.nkro = 1;
        eeconfig_update_keymap(keymap_config.raw);
      }
      return false;
      break;
    case EXT_CS:
      if (record->event.pressed) {
        #ifdef AUDIO_ENABLE
          PLAY_SONG(plover_gb_song);
        #endif
        layer_off(_CSGO);
      }
      return false;
      break;
    case PUBG:
      if (record->event.pressed) {
        #ifdef AUDIO_ENABLE
          stop_all_notes();
          PLAY_SONG(plover_song);
        #endif
        layer_off(_RAISE);
        layer_off(_LOWER);
        layer_off(_ADJUST);
        layer_on(_PUBG);
        if (!eeconfig_is_enabled()) {
            eeconfig_init();
        }
        keymap_config.raw = eeconfig_read_keymap();
        keymap_config.nkro = 1;
        eeconfig_update_keymap(keymap_config.raw);
      }
      return false;
      break;
    case EXT_PG:
      if (record->event.pressed) {
        #ifdef AUDIO_ENABLE
          PLAY_SONG(plover_gb_song);
        #endif
        layer_off(_PUBG);
      }
      return false;
      break;
  }
  return true;
}
