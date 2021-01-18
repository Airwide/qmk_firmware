#include QMK_KEYBOARD_H
#include "4x6.h"
#include "g/keymap_combo.h"

enum unicode_names {
  SE_AA_HIGH,
  SE_AE_HIGH,
  SE_OE_HIGH,
  SE_AA_LOW,
  SE_AE_LOW,
  SE_OE_LOW,
};

const uint32_t PROGMEM unicode_map[] = {
  [SE_AA_HIGH] = 0x00C5,
  [SE_AE_HIGH] = 0x00C4,
  [SE_OE_HIGH] = 0x00D6,
  [SE_AA_LOW]  = 0x00E5,
  [SE_AE_LOW]  = 0x00E4,
  [SE_OE_LOW]  = 0x00F6,
};

#define SE_AA XP(SE_AA_LOW, SE_AA_HIGH)
#define SE_AE XP(SE_AE_LOW, SE_AE_HIGH)
#define SE_OE XP(SE_OE_LOW, SE_OE_HIGH)

#define KC____ KC_TRNS
#define KC_XXX KC_NO
#define KC_RESET RESET
#define KC_UC_MOD UC_MOD
//#define KC_CTL_ESC MT(MOD_LCTL, KC_ESC)
#define KC_CTL_Z MT(MOD_LCTL, KC_Z)
#define KC_SFT_A MT(MOD_LSFT, KC_A)
#define KC_ALT_X MT(MOD_LALT, KC_X)
#define KC_ALT_DOT MT(MOD_RALT, KC_DOT)
//#define KC_CTL_BSPC MT(MOD_RCTL, KC_BSPC)
#define KC_CTL_SLA MT(MOD_RCTL, KC_SLSH)
#define KC_SFT_SCN MT(MOD_RSFT, KC_SCLN)
#define KC_L2_ENT LT(2, KC_ENT)
//#define KC_L1_DEL LT(1, KC_DEL)
#define KC_L1_ESC LT(1, KC_ESC)
//#define KC_L1_TAB LT(1, KC_TAB)
#define KC_L3_SPC LT(3, KC_SPC)
#define KC_L1_BSPC LT(1, KC_BSPC)
#define KC_GUI_LBRC MT(MOD_LGUI,KC_LBRC)
#define KC_GUI_DEL MT(MOD_LGUI,KC_DEL)
#define KC_GUI_RBRC MT(MOD_RGUI,KC_RBRC)
#define KC_GUI_TAB MT(MOD_RGUI,KC_TAB)

#define KC_CMB_TOG CMB_TOG  // A hack to allow KC_-less keycode along with KC_-ful ones

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[0] = LAYOUT_kc( 
//       ┌───────┬───────┬───────┬───────┬───────┬───────┬───────┬───────┬───────┬───────┬───────┬───────┬───────┬───────┬───────┐
            XXX  ,   Q   ,   W   ,   E   ,   R   ,   T   ,                           Y   ,   U   ,   I   ,   O   ,   P   ,  XXX  ,
//       ├───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┤
            XXX  , SFT_A ,   S   ,   D   ,   F   ,   G   ,                           H   ,   J   ,   K   ,   L   ,SFT_SCN,  XXX  ,
//       ├───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┤
            XXX  , CTL_Z , ALT_X ,   C   ,   V   ,   B   ,                           N   ,   M   , COMM  ,ALT_DOT,CTL_SLA,  XXX  ,
//       └───────┴───────┼───────┼───────┼───────┴───────┴───────┴───────┴───────┴───────┴───────┼───────┼───────┼───────┴───────┘
                            XXX  ,  XXX  ,                                                          XXX  ,  XXX  ,
//                       └───────┴───────┘                                                       └───────┴───────┘
//                                       ┌───────┬───────┐                       ┌───────┬───────┐
                                           L1_ESC,                                        L1_BSPC,
//                                       ├───────┼───────┤                       ├───────┼───────┤
                                           L2_ENT,GUI_DEL,                        GUI_TAB, L3_SPC,
//                                       ├───────┼───────┤                       ├───────┼───────┤
                                            NO   ,  NO   ,                          NO   ,  NO  ),
//                                       └───────┴───────┘                       └───────┴───────┘
	[1] = LAYOUT_kc( \
//       ┌───────┬───────┬───────┬───────┬───────┬───────┬───────┬───────┬───────┬───────┬───────┬───────┬───────┬───────┬───────┐
            ___  ,   1   ,   2   ,   3   ,   4   ,   5   ,                           6   ,   7   ,   8   ,   9   ,   0   ,  ___  ,
//       ├───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┤
            ___  , EXLM  ,  AT   , HASH  ,  DLR  , PERC  ,                         CIRC  , AMPR  , ASTR  , LPRN  , RPRN  ,  ___  ,
//       ├───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┤
            ___  ,  ___  ,  ___  ,  ___  ,  ___  ,  ___  ,                          ___  ,  ___  ,  ___  ,  ___  ,  ___  ,  ___  , 
//       └───────┴───────┼───────┼───────┼───────┴───────┴───────┴───────┴───────┴───────┴───────┼───────┼───────┼───────┴───────┘
                            ___  ,  ___  ,                                                          ___  ,  ___  , 
//                       └───────┴───────┘                                                       └───────┴───────┘
//                                       ┌───────┬───────┐                       ┌───────┬───────┐
                                            ___  ,                                          ___  , 
//                                       ├───────┼───────┤                       ├───────┼───────┤
                                            ___  ,  ___  ,                          ___  ,  ___  , 
//                                       ├───────┼───────┤                       ├───────┼───────┤
                                            ___  ,  ___  ,                          ___  ,  ___ ), 
//                                       └───────┴───────┘                       └───────┴───────┘
	[2] = LAYOUT_kc( \
//       ┌───────┬───────┬───────┬───────┬───────┬───────┬───────┬───────┬───────┬───────┬───────┬───────┬───────┬───────┬───────┐
            ___  , PSCR  , SLCK  , NLCK  , CAPS  , PAUS  ,                         ASTR  ,   7   ,   8   ,   9   , MINS  ,  ___  , 
//       ├───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┤
            ___  ,  F1   ,  F3   ,  F5   ,  F7   ,  F9   ,                         SLSH  ,   4   ,   5   ,   6   , PLUS  ,  ___  , 
//       ├───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┤
            ___  ,  ___  ,  ___  ,  INS  ,  F10  ,  F12  ,                           0   ,   1   ,   2   ,   3   ,  ENT  ,  ___  , 
//       └───────┴───────┼───────┼───────┼───────┴───────┴───────┴───────┴───────┴───────┴───────┼───────┼───────┼───────┴───────┘
                            ___  ,  ___  ,                                                          ___  ,  ___  , 
//                       └───────┴───────┘                                                       └
//                                       ┌───────┬───────┐                       ┌───────┬───────┐
                                            ___  ,                                          ___  , 
//                                       ├───────┼───────┤                       ├───────┼───────┤
                                            ___  ,  ___  ,                          ___  ,  ___  , 
//                                       ├───────┼───────┤                       ├───────┼───────┤
                                            ___  ,  ___  ,                          ___  ,  ___ ), 
//                                       └───────┴───────┘                       └───────┴───────┘
	[3] = LAYOUT_kc( \
//       ┌───────┬───────┬───────┬───────┬───────┬───────┬───────┬───────┬───────┬───────┬───────┬───────┬───────┬───────┬───────┐
            ___  ,  ___  ,  ___  , RESET , BRMU  , _VOLUP,                         HOME  , PGDN  , PGUP  ,  END  , BTN3  ,  ___  , 
//       ├───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┤
            ___  ,  ___  ,  ___  ,  ___  , BRMD  ,_VOLDOWN,                        LEFT  , DOWN  ,  UP   , RIGHT , BTN2  ,  ___  ,
//       ├───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┤
            ___  ,  ___  ,  ___  ,  ___  ,  ___  , _MUTE ,                         MS_L  , MS_D  , MS_U  , MS_R  , BTN1  ,  ___  ,  
//       └───────┴───────┼───────┼───────┼───────┴───────┴───────┴───────┴───────┴───────┴───────┼───────┼───────┼───────┴───────┘
                            ___  ,  ___  ,                                                          ___  ,  ___  , 
//                       └───────┴───────┘                                                       └───────┴───────┘
//                                       ┌───────┬───────┐                       ┌───────┬───────┐
                                            ___  ,                                          ___  , 
//                                       ├───────┼───────┤                       ├───────┼───────┤
                                            ___  ,  ___  ,                          ___  ,  ___  , 
//                                       ├───────┼───────┤                       ├───────┼───────┤
                                            ___  ,  ___  ,                          ___  ,  ___ ) 
//                                       └───────┴───────┘                       └───────┴───────┘
/* Layer template
	[4] = LAYOUT_kc( \
//       ┌───────┬───────┬───────┬───────┬───────┬───────┬───────┬───────┬───────┬───────┬───────┬───────┬───────┬───────┬───────┐
            ___  ,  ___  ,  ___  ,  ___  ,  ___  ,  ___  ,                          ___  ,  ___  ,  ___  ,  ___  ,  ___  ,  ___  , 
//       ├───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┤
            ___  ,  ___  ,  ___  ,  ___  ,  ___  ,  ___  ,                          ___  ,  ___  ,  ___  ,  ___  ,  ___  ,  ___  , 
//       ├───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┤
            ___  ,  ___  ,  ___  ,  ___  ,  ___  ,  ___  ,                          ___  ,  ___  ,  ___  ,  ___  ,  ___  ,  ___  , 
//       └───────┴───────┼───────┼───────┼───────┴───────┴───────┴───────┴───────┴───────┴───────┼───────┼───────┼───────┴───────┘
                            ___  ,  ___  ,                                                          ___  ,  ___  , 
//                       └───────┴───────┘                                                       └───────┴───────┘
//                                       ┌───────┬───────┐                       ┌───────┬───────┐
                                            ___  ,                                          ___  , 
//                                       ├───────┼───────┤                       ├───────┼───────┤
                                            ___  ,  ___  ,                          ___  ,  ___  , 
//                                       ├───────┼───────┤                       ├───────┼───────┤
                                            ___  ,  ___  ,                          ___  ,  ___ ), 
//                                       └───────┴───────┘                       └───────┴───────┘
*/

};
