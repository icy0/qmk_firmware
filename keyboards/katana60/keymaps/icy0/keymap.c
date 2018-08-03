/* Copyright 2017 Baris Tosun
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

#define _______ KC_TRNS
#define XXXXXXX KC_NO

// Windows based definitions.
#define K_SPCFN LT(SYMB, KC_SPACE) // Tap for space, hold for symbols layer
#define K_PRVWD LCTL(KC_LEFT)      // Previous word
#define K_NXTWD LCTL(KC_RIGHT)     // Next word
#define K_LSTRT KC_HOME            // Start of line
#define K_LEND  KC_END             // End of line
#define UNDO    LCTL(KC_Z)         // UNDO
#define CUT     LCTL(KC_X)         // CUT
#define COPY    LCTL(KC_C)         // COPY
#define PASTE   LCTL(KC_V)         // PASTE


#define BASE 0 // Default
#define NUMB 1 // Numbers
#define SYMB 2 // Symbols
#define CURS 3 // Text Editing

/*
 * DF(layer) - switches the default layer. The default layer is the always-active base layer that other layers stack on top of. 
 * See below for more about the default layer. This 	might be used to switch from QWERTY to Dvorak layout. 
 * (Note that this is a temporary switch that only persists until the keyboard loses power. 
 * To modify the default layer in a persistent way requires deeper customization, such as calling the set_single_persistent_default_layer function inside of process_record_user.)
 * 
 * MO(layer) - momentarily activates layer. As soon as you let go of the key, the layer is deactivated.
 * 
 * LM(layer, mod) - Momentarily activates layer (like MO), but with modifier(s) mod active. Only supports layers 0-15 and the left modifiers.
 * 
 * LT(layer, kc) - momentarily activates layer when held, and sends kc when tapped.
 * 
 * TG(layer) - toggles layer, activating it if it's inactive and vice versa
 * 
 * TO(layer) - activates layer and de-activates all other layers (except your default layer). 
 * This function is special, because instead of just adding/removing one layer to your active layer stack, 
 * it will completely replace your current active layers, uniquely allowing you to replace higher layers with a lower one. 
 * This is activated on keydown (as soon as the key is pressed).
 * 
 * TT(layer) - Layer Tap-Toggle. If you hold the key down, layer is activated, and then is de-activated when you let go (like MO). 
 * If you repeatedly tap it, the layer will be toggled on or off (like TG). It needs 5 taps by default, 
 * but you can change this by defining TAPPING_TOGGLE -- for example, #define TAPPING_TOGGLE 2 to toggle on just two taps.
 
 */

// _______ == KC_TRNS
 
 const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[BASE] = LAYOUT( /* Base */
  KC_ESC,  KC_BSLS, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    TO(1),   KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_PLUS,
  KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_LBRC,          KC_RBRC, KC_Z,    KC_U,    KC_I,    KC_O,    KC_P,    KC_SLSH,
  MO(3),   KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_HOME,          KC_PGUP, KC_H,    KC_J,    KC_K,    KC_L,    KC_QUOT, KC_LALT,
  KC_LSFT, KC_Y,    KC_X,    KC_C,    KC_V,    KC_B,    KC_END,  KC_DEL,  KC_PGDN, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SCLN, KC_RSFT,
  KC_LCTL, KC_LGUI, KC_LALT, MO(2),            KC_SPC,  		 KC_ENT,  KC_BSPC,          KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT, KC_APP
    ),
[NUMB] = LAYOUT(
         ,        ,        ,        ,        ,        ,        , DF(0),       ,        , KC_PSLS, KC_PAST,    KC_PMNS,           ,        ,
         ,        ,        , KC_MS_U,        ,        ,        ,              ,    KC_7,    KC_8,    KC_9,    KC_PPLS,        ,        ,
         , KC_BTN2, KC_MS_L, KC_MS_D, KC_MS_R,        ,        ,              ,    KC_4,    KC_5,    KC_6,    KC_PCMM,        ,        , 
         ,        , KC_ACL0, KC_ACL1, KC_ACL2,        ,        ,      ,       ,    KC_1,    KC_2,    KC_3,    KC_PENT,        ,        ,
		 , 	      ,        ,        ,                   KC_BTN1,      ,       ,   KC_P0, KC_PDOT, KC_PENT,           ,
    ),
[SYMB] = LAYOUT(
    RESET,          ,     KC_F1,     KC_F2,   KC_F3,   KC_F4,   KC_F5,          , KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,
   KC_GRV,   KC_CIRC,          ,          ,        ,        ,        ,                 ,        ,        ,        ,        ,        ,        ,
         ,UNICODE(Ü),UNICODE(Ö),UNICODE(Ä),        ,        , KC_VOLD,          KC_VOLU,        ,        ,        ,        ,        ,        ,
         ,          ,          ,          ,        ,        , KC_MPRV, KC_MPLY, KC_MNXT,        ,        ,        ,        ,        ,        ,
         ,          ,          ,          ,                          ,        ,        ,                 ,        ,        ,        ,        
    ),
[CURS] = LAYOUT(
         ,        ,        ,        ,        ,        ,        ,        ,        ,        ,        ,        ,        ,        ,        ,
         ,        , KC_WH_U,        ,        ,        ,        ,                 ,        , K_PRVWD, KC_UP,   K_NXTWD,        ,        ,
         , KC_LCTL, KC_WH_D, KC_LSFT,        ,        ,        ,                 , K_LSTRT, KC_LEFT, KC_DOWN, KC_RIGHT, K_LEND,        ,
         , UNDO,    CUT,     COPY,    PASTE,          ,        ,        ,        ,        , KC_BSPC,        , KC_DEL,         ,        ,
         ,        ,        ,        ,                          ,        ,        ,                 ,        ,       ,         ,        
    )

};


const uint16_t PROGMEM fn_actions[] = {
    [0] = ACTION_LAYER_TAP_KEY(CURS, KC_BSPC),
    [1] = ACTION_LAYER_TAP_KEY(SYMB, KC_SPACE),
};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
  // MACRODOWN only works in this function
      switch(id) {
        case 0:
          if (record->event.pressed) {
            register_code(KC_RSFT);
          } else {
            unregister_code(KC_RSFT);
          }
        break;
      }
    return MACRO_NONE;
};


void matrix_init_user(void) {

}

void matrix_scan_user(void) {

}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  return true;
}

void led_set_user(uint8_t usb_led) {

}
