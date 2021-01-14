#include QMK_KEYBOARD_H
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

#define ___ KC_TRNS

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[0] = LAYOUT( \
//        ┌─────────┬─────────┬─────────┬─────────┬─────────┬─────────┬─────────┬─────────┬─────────┬─────────┬─────────┬─────────┬─────────┬─────────┬─────────┐
            KC_NO,     KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,                                   KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,    KC_LBRC,\
//        ├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤
            KC_GRV,    KC_A,     KC_S,     KC_D,     KC_F,     KC_G,                                   KC_H,     KC_J,     KC_K,     KC_L,    KC_SCLN,  KC_QUOT,\
//        ├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤
            KC_LSPO,   KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,                                   KC_N,     KC_M,    KC_COMM,  KC_DOT,   KC_SLSH,  KC_RSPC,\
//        └─────────┴─────────┼─────────┼─────────┼─────────┴─────────┴─────────┴─────────┴─────────┴─────────┴─────────┼─────────┼─────────┼─────────┴─────────┘
                                KC_LBRC,  KC_RBRC,                                                                        KC_MINS,  KC_EQL,\
//                            └─────────┴─────────┘                                                                     └─────────┴─────────┘
//                                      ┌───────────────────┬───────────────────┐         ┌───────────────────┬───────────────────┐
                                          LCTL_T(KC_ESC),                                                       RCTL_T(KC_BSPC),\
//                                      ├───────────────────┼───────────────────┤         ├───────────────────┼───────────────────┤
                                            LT(2,KC_ENT),       LT(1,KC_DEL),                 LT(1,KC_TAB),      LT(3,KC_SPC),\
//                                      ├───────────────────┼───────────────────┤         ├───────────────────┼───────────────────┤
                                        MT(MOD_LALT,KC_LCBR),  LGUI_T(KC_LBRC),              RGUI_T(KC_RBRC),  MT(MOD_RALT,KC_RCBR)),
//                                      └───────────────────┴───────────────────┘         └───────────────────┴───────────────────┘
	[1] = LAYOUT( \
//        ┌─────────┬─────────┬─────────┬─────────┬─────────┬─────────┬─────────┬─────────┬─────────┬─────────┬─────────┬─────────┬─────────┬─────────┬─────────┐
             KC_NO,    KC_1,     KC_2,     KC_3,     KC_4,     KC_5,                                   KC_6,     KC_7,     KC_8,     KC_9,     KC_0,    KC_MINS,\
//        ├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤
            KC_TILD,  KC_EXLM,   KC_AT,   KC_HASH,  KC_DLR,   KC_PERC,                                KC_CIRC,  KC_AMPR,  KC_ASTR,  KC_LPRN,  KC_RPRN,  KC_PLUS,\
//        ├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤
              ___,     KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,                                  KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO, \
//        └─────────┴─────────┼─────────┼─────────┼─────────┴─────────┴─────────┴─────────┴─────────┴─────────┴─────────┼─────────┼─────────┼─────────┴─────────┘
                                  ___,      ___,                                                                            ___,      ___,   \
//                            └─────────┴─────────┘                                                                     └─────────┴─────────┘
//                                      ┌───────────────────┬───────────────────┐         ┌───────────────────┬───────────────────┐
                                                 ___,                                                                  ___,       \
//                                      ├───────────────────┼───────────────────┤         ├───────────────────┼───────────────────┤
                                                 ___,                 ___,                        ___,                 ___,       \
//                                      ├───────────────────┼───────────────────┤         ├───────────────────┼───────────────────┤
                                                 ___,                 ___,                        ___,                 ___  ),
//                                      └───────────────────┴───────────────────┘         └───────────────────┴───────────────────┘
	[2] = LAYOUT( \
//        ┌─────────┬─────────┬─────────┬─────────┬─────────┬─────────┬─────────┬─────────┬─────────┬─────────┬─────────┬─────────┬─────────┬─────────┬─────────┐
            KC_SLCK,   KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,                                 KC_SLSH,    KC_7,    KC_8,     KC_9,    KC_MINS,  KC_PIPE,\
//        ├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤
            KC_CAPS,   KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,                                KC_ASTR,    KC_4,    KC_5,     KC_6,    KC_PLUS,  KC_BSLS,\
//        ├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤
            KC_NLCK,  KC_F11,   KC_F12,   KC_PSCR,  KC_PAUS,   KC_INS,                                 KC_NO,     KC_1,    KC_2,     KC_3,    KC_ENT,     ___,  \
//        └─────────┴─────────┼─────────┼─────────┼─────────┴─────────┴─────────┴─────────┴─────────┴─────────┴─────────┼─────────┼─────────┼─────────┴─────────┘
                                 RESET,    UC_MOD,                                                                         KC_0,    KC_DOT, \
//                            └─────────┴─────────┘                                                                     └─────────┴─────────┘
//                                      ┌───────────────────┬───────────────────┐         ┌───────────────────┬───────────────────┐
                                                 ___,                                                                  ___,       \
//                                      ├───────────────────┼───────────────────┤         ├───────────────────┼───────────────────┤
                                                 ___,                ___,                          ___,               ___,        \
//                                      ├───────────────────┼───────────────────┤         ├───────────────────┼───────────────────┤
                                                 ___,                ___,                          ___,               ___  ),
//                                      └───────────────────┴───────────────────┘         └───────────────────┴───────────────────┘
	[3] = LAYOUT( \
//        ┌─────────┬─────────┬─────────┬─────────┬─────────┬─────────┬─────────┬─────────┬─────────┬─────────┬─────────┬─────────┬─────────┬─────────┬─────────┐
              ___,      ___,      ___,      ___,    KC_BRMU, KC__VOLUP,                               KC_HOME,  KC_PGDN,  KC_PGUP,  KC_END,   KC_BTN4,  KC_BTN5,\
//        ├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤
              ___,      ___,      ___,      ___,    KC_BRMD,KC__VOLDOWN,                              KC_LEFT,  KC_DOWN,   KC_UP,   KC_RIGHT, KC_BTN2,  KC_BTN3,\
//        ├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤
              ___,      ___,      ___,      ___,      ___,    KC__MUTE,                               KC_MS_L,  KC_MS_D,  KC_MS_U,  KC_MS_R,  KC_BTN1,    ___,  \
//        └─────────┴─────────┼─────────┼─────────┼─────────┴─────────┴─────────┴─────────┴─────────┴─────────┴─────────┼─────────┼─────────┼─────────┴─────────┘
                                  ___,      ___,                                                                            ___,      ___,  \
//                            └─────────┴─────────┘                                                                     └─────────┴─────────┘
//                                      ┌───────────────────┬───────────────────┐         ┌───────────────────┬───────────────────┐
                                                 ___,                                                                  ___,       \
//                                      ├───────────────────┼───────────────────┤         ├───────────────────┼───────────────────┤
                                                 ___,                ___,                          ___,                ___,       \
//                                      ├───────────────────┼───────────────────┤         ├───────────────────┼───────────────────┤
                                                 ___,                ___,                          ___,                ___  ),
//                                      └───────────────────┴───────────────────┘         └───────────────────┴───────────────────┘

/* Layer template
	[4] = LAYOUT( \
//        ┌─────────┬─────────┬─────────┬─────────┬─────────┬─────────┬─────────┬─────────┬─────────┬─────────┬─────────┬─────────┬─────────┬─────────┬─────────┐
              ___,      ___,      ___,      ___,      ___,      ___,                                    ___,      ___,      ___,      ___,      ___,      ___,  \
//        ├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤
              ___,      ___,      ___,      ___,      ___,      ___,                                    ___,      ___,      ___,      ___,      ___,      ___,  \
//        ├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤
              ___,      ___,      ___,      ___,      ___,      ___,                                    ___,      ___,      ___,      ___,      ___,      ___,  \
//        └─────────┴─────────┼─────────┼─────────┼─────────┴─────────┴─────────┴─────────┴─────────┴─────────┴─────────┼─────────┼─────────┼─────────┴─────────┘
                                  ___,      ___,                                                                            ___,      ___,  \
//                            └─────────┴─────────┘                                                                     └─────────┴─────────┘
//                                      ┌───────────────────┬───────────────────┐         ┌───────────────────┬───────────────────┐
                                                 ___,                                                                  ___,       \
//                                      ├───────────────────┼───────────────────┤         ├───────────────────┼───────────────────┤
                                                 ___,                ___,                          ___,                ___,       \
//                                      ├───────────────────┼───────────────────┤         ├───────────────────┼───────────────────┤
                                                 ___,                ___,                          ___,                ___  ),
//                                      └───────────────────┴───────────────────┘         └───────────────────┴───────────────────┘
*/

};
