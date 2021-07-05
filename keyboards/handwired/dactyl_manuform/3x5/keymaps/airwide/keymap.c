#include QMK_KEYBOARD_H
#include "3x5.h"
#include "keymap_swedish.h"

#define _COLEMAK 0
#define _QWERTY 1
#define _SYMBOL 2
#define _NUMBER 3
#define _NAVIGATION 4
#define _FUNCTION 5

#define _____ KC_TRNS
#define XXXXX KC_NO
#define CTL_Z MT(MOD_LCTL, KC_Z)
#define SFT_A MT(MOD_LSFT, KC_A)
#define ALT_X MT(MOD_LALT, KC_X)
#define ALT_DOT MT(MOD_LALT, KC_DOT)
#define ALT_SPC MT(MOD_LALT, KC_SPC)
#define CTL_MIN MT(MOD_RCTL, SE_MINS)
#define CTL_TAB LCTL_T(KC_TAB)
#define SFT_SCN MT(MOD_RSFT, KC_SCLN)
#define SFT_O MT(MOD_RSFT, KC_O)
#define NUM_S LT(_NUMBER, KC_S)
#define NUM_R LT(_NUMBER, KC_R)
#define FUN_L LT(_FUNCTION, KC_L)
#define FUN_I LT(_FUNCTION, KC_I)
#define SYM_ESC LT(_SYMBOL, KC_ESC)
#define NAV_ENT LT(_NAVIGATION, KC_ENT)
#define SYM_BSP LT(_SYMBOL, KC_BSPC)
#define GUI_DEL MT(MOD_RGUI,KC_DEL)
#define GUI_ESC MT(MOD_LGUI,KC_ESC)
#define COLEMAK DF(_COLEMAK)
#define QWERTY DF(_QWERTY)

#include "g/keymap_combo.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  
/* Colemak DHm
//       ┌─────┬─────┬─────┬─────┬─────┐                   ┌─────┬─────┬─────┬─────┬─────┐
         |  q  |  w  |  f  |  p  |  b  |                   |  j  |  l  |  u  |  y  |  ;  |
//       ├─────┼─────┼─────┼─────┼─────┤                   ├─────┼─────┼─────┼─────┼─────┤
         |sft-a|num-r|  s  |  t  |  g  |                   |  m  |  n  |  e  |fun-i|sft-o|
//       ├─────┼─────┼─────┼─────┼─────┤                   ├─────┼─────┼─────┼─────┼─────┤
         |ctl-z|alt-x|  c  |  d  |  v  |                   |  k  |  h  |  ,  |alt-.|ctl-/|
//       └─────┴─────┴─────┴─────┴─────┘                   └─────┴─────┴─────┴─────┴─────┘
//                         ┌─────┬─────┬─────┐       ┌─────┬─────┬─────┐
                           |c-tab|a-spc|g-esc|       |g-del|na-en|sy-bs|
//                         └─────┴─────┴─────┘       └─────┴─────┴─────┘
*/
	[_COLEMAK] = LAYOUT(
	     KC_Q,  KC_W,  KC_F,  KC_P,  KC_B,                         KC_J, KC_L, KC_U,    KC_Y,    SE_ODIA, 
	     SFT_A, NUM_R, KC_S,  KC_T,  KC_G,                         KC_M, KC_N, KC_E,    FUN_I,   SFT_O,   
	     CTL_Z, ALT_X, KC_C,  KC_D,  KC_V,                         KC_K, KC_H, KC_COMM, ALT_DOT, CTL_MIN, 
	     
                             CTL_TAB, ALT_SPC, GUI_ESC,       GUI_DEL, NAV_ENT, SYM_BSP),
/* QWERTY
//       ┌─────┬─────┬─────┬─────┬─────┐                   ┌─────┬─────┬─────┬─────┬─────┐
         |  q  |  w  |  e  |  r  |  t  |                   |  y  |  u  |  i  |  o  |  p  |
//       ├─────┼─────┼─────┼─────┼─────┤                   ├─────┼─────┼─────┼─────┼─────┤
         |sft-a|num-s|  d  |  f  |  g  |                   |  h  |  j  |  k  |fun-l|sft-;|
//       ├─────┼─────┼─────┼─────┼─────┤                   ├─────┼─────┼─────┼─────┼─────┤
         |ctl-z|alt-x|  c  |  v  |  b  |                   |  n  |  m  |  ,  |alt-.|ctl-/|
//       └─────┴─────┴─────┴─────┴─────┘                   └─────┴─────┴─────┴─────┴─────┘
//                         ┌─────┬─────┬─────┐       ┌─────┬─────┬─────┐
                           |     |     |     |       |     |     |     |
//                         └─────┴─────┴─────┘       └─────┴─────┴─────┘
*/
	[_QWERTY] = LAYOUT(
             KC_Q,  KC_W,  KC_E,  KC_R, KC_T,                            KC_Y, KC_U, KC_I,    KC_O,    KC_P,    
             SFT_A, NUM_S, KC_D,  KC_F, KC_G,                            KC_H, KC_J, KC_K,    FUN_L,   SFT_SCN, 
             CTL_Z, ALT_X, KC_C,  KC_V, KC_B,                            KC_N, KC_M, KC_COMM, ALT_DOT, CTL_MIN, 
	                                                                          
                                _____, _____, _____,              _____, _____, _____),
/* Symbols
//       ┌─────┬─────┬─────┬─────┬─────┐                   ┌─────┬─────┬─────┬─────┬─────┐
         |  !  |  "  |  #  |  €  |  §  |                   |     |  /  |  \  |  |  |  =  |
//       ├─────┼─────┼─────┼─────┼─────┤                   ├─────┼─────┼─────┼─────┼─────┤
         |  '  |  {  |  [  |  (  |  %  |                   |  &  |  )  |  ]  |  }  |  +  |
//       ├─────┼─────┼─────┼─────┼─────┤                   ├─────┼─────┼─────┼─────┼─────┤
         |  ~  |  @  |  £  |  $  |  ´  |                   |  ¨  |  ?  |  <  |  >  |  *  |
//       └─────┴─────┴─────┴─────┴─────┘                   └─────┴─────┴─────┴─────┴─────┘
//                         ┌─────┬─────┬─────┐       ┌─────┬─────┬─────┐
                           |     |     |     |       |     |     |     |
//                         └─────┴─────┴─────┘       └─────┴─────┴─────┘
*/
	[_SYMBOL] = LAYOUT(
	     SE_EXLM, SE_DQUO,     SE_HASH, SE_CURR, SE_LABK,                _____,   SE_SLSH, SE_BSLS_MAC, SE_PIPE_MAC, SE_EQL,  
	     SE_QUOT, SE_LCBR_MAC, SE_LBRC, SE_LPRN, SE_PERC,                SE_AMPR, SE_RPRN, SE_RBRC,     SE_RCBR_MAC, SE_PLUS, 
	     SE_TILD, SE_AT,       SE_PND,  SE_DLR,  SE_ACUT,                SE_DIAE, SE_QUES, SE_LESS_MAC, SE_GRTR_MAC, SE_ASTR, 
                                                                                                
                                              _____, _____, _____,      _____, _____, _____),
/* Numbers
//       ┌─────┬─────┬─────┬─────┬─────┐                   ┌─────┬─────┬─────┬─────┬─────┐
         |     |     |     |CapLk|Pause|                   |  *  |  7  |  8  |  9  |  -  |
//       ├─────┼─────┼─────┼─────┼─────┤                   ├─────┼─────┼─────┼─────┼─────┤
         |     |     |     |NumLk| Ins |                   |  /  |  4  |  5  |  6  |  +  |
//       ├─────┼─────┼─────┼─────┼─────┤                   ├─────┼─────┼─────┼─────┼─────┤
         |     |     |     |PrScn|ScrLk|                   |  0  |  1  |  2  |  3  |Enter|
//       └─────┴─────┴─────┴─────┴─────┘                   └─────┴─────┴─────┴─────┴─────┘
//                         ┌─────┬─────┬─────┐       ┌─────┬─────┬─────┐
                           |     |     |     |       |     |     |  0  |
//                         └─────┴─────┴─────┘       └─────┴─────┴─────┘
*/
	[_NUMBER] = LAYOUT(
             _____, _____, _____, KC_CAPS, KC_PAUS,                  SE_ASTR, KC_7, KC_8,  KC_9,  SE_MINS, 
             _____, _____, _____, KC_NLCK, KC_INS,                   SE_SLSH, KC_4, KC_5,  KC_6,  SE_PLUS, 
             _____, _____, _____, KC_PSCR, KC_SLCK,                  _____,   KC_1, KC_2,  KC_3,  KC_ENT,  
                                                                               
                                      _____, _____, _____,    _____, _____, KC_0),
/* Navigation
//       ┌─────┬─────┬─────┬─────┬─────┐                   ┌─────┬─────┬─────┬─────┬─────┐
         |Reset|     |     |BriUp|VolUp|                   |Home |PgDn |PgUp | End |But3 |
//       ├─────┼─────┼─────┼─────┼─────┤                   ├─────┼─────┼─────┼─────┼─────┤
         |     |     |     |BriDo|VolDo|                   |Left |Down | Up  |Right|But2 |
//       ├─────┼─────┼─────┼─────┼─────┤                   ├─────┼─────┼─────┼─────┼─────┤
         |     |Qwert|Colem|     |Mute |                   |MousL|MousD|MousU|MousR|But1 |
//       └─────┴─────┴─────┴─────┴─────┘                   └─────┴─────┴─────┴─────┴─────┘
//                         ┌─────┬─────┬─────┐       ┌─────┬─────┬─────┐
                           |     |     |     |       |     |     |     |
//                         └─────┴─────┴─────┘       └─────┴─────┴─────┘
*/
	[_NAVIGATION] = LAYOUT(
             RESET, _____,  _____,   KC_BRMU, KC__VOLUP,                    KC_HOME, KC_PGDN, KC_PGUP, KC_END,   KC_BTN3, 
             _____, _____,  _____,   KC_BRMD, KC__VOLDOWN,                  KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT, KC_BTN2, 
             _____, QWERTY, COLEMAK, _____,   KC__MUTE,                     KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R,  KC_BTN1, 
                                                                                           
                                          _____, _____, _____,      _____,  _____, _____),
/* Function
//       ┌─────┬─────┬─────┬─────┬─────┐                   ┌─────┬─────┬─────┬─────┬─────┐
         | F1  | F2  | F3  | F4  | F5  |                   |     |     |     |     |     |
//       ├─────┼─────┼─────┼─────┼─────┤                   ├─────┼─────┼─────┼─────┼─────┤
         | F6  | F7  | F8  | F9  | F10 |                   |     |     |     |     |     |
//       ├─────┼─────┼─────┼─────┼─────┤                   ├─────┼─────┼─────┼─────┼─────┤
         | F11 | F12 |     |     |     |                   |     |     |     |     |     |
//       └─────┴─────┴─────┴─────┴─────┘                   └─────┴─────┴─────┴─────┴─────┘
//                         ┌─────┬─────┬─────┐       ┌─────┬─────┬─────┐
                           |     |     |     |       |     |     |     |
//                         └─────┴─────┴─────┘       └─────┴─────┴─────┘
*/
	[_FUNCTION] = LAYOUT(
             KC_F1,  KC_F2,  KC_F3, KC_F4, KC_F5,                       _____, _____, _____, _____, _____, 
             KC_F6,  KC_F7,  KC_F8, KC_F9, KC_F10,                      _____, _____, _____, _____, _____, 
             KC_F11, KC_F12, _____, _____, _____,                       _____, _____, _____, _____, _____, 
                                                                                 
                                    _____, _____, _____,        _____,  _____, _____)
/* Layer  illustration template
//       ┌─────┬─────┬─────┬─────┬─────┐                   ┌─────┬─────┬─────┬─────┬─────┐
         |     |     |     |     |     |                   |     |     |     |     |     |
//       ├─────┼─────┼─────┼─────┼─────┤                   ├─────┼─────┼─────┼─────┼─────┤
         |     |     |     |     |     |                   |     |     |     |     |     |
//       ├─────┼─────┼─────┼─────┼─────┤                   ├─────┼─────┼─────┼─────┼─────┤
         |     |     |     |     |     |                   |     |     |     |     |     |
//       └─────┴─────┴─────┴─────┴─────┘                   └─────┴─────┴─────┴─────┴─────┘
//                         ┌─────┬─────┬─────┐       ┌─────┬─────┬─────┐
                           |     |     |     |       |     |     |     |
//                         └─────┴─────┴─────┘       └─────┴─────┴─────┘
	[4] = LAYOUT(
             _____, _____, _____, _____, _____,                        _____,  _____, _____, _____, _____, 
             _____, _____, _____, _____, _____,                        _____,  _____, _____, _____, _____, 
             _____, _____, _____, _____, _____,                        _____,  _____, _____, _____, _____, 
                                                                                 
                                  _____, _____, _____,         _____,  _____, _____),
*/

};
