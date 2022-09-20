#include QMK_KEYBOARD_H
#include "version.h"

#define KC_MAC_UNDO LGUI(KC_Z)
#define KC_MAC_CUT LGUI(KC_X)
#define KC_MAC_COPY LGUI(KC_C)
#define KC_MAC_PASTE LGUI(KC_V)
#define KC_PC_UNDO LCTL(KC_Z)
#define KC_PC_CUT LCTL(KC_X)
#define KC_PC_COPY LCTL(KC_C)
#define KC_PC_PASTE LCTL(KC_V)
#define ES_LESS_MAC KC_GRAVE
#define ES_GRTR_MAC LSFT(KC_GRAVE)
#define ES_BSLS_MAC ALGR(KC_6)
#define NO_PIPE_ALT KC_GRAVE
#define NO_BSLS_ALT KC_EQUAL
#define LSA_T(kc) MT(MOD_LSFT | MOD_LALT, kc)
#define BP_NDSH_MAC ALGR(KC_8)
#define SE_SECT_MAC ALGR(KC_6)


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT(
//-----------------------------------------------------------------------------------------------------------------------
	KC_QUOTE, KC_1, KC_2, KC_3, KC_4, KC_5,        KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINUS, 
//-----------------------------------------------------------------------------------------------------------------------
	KC_TAB, KC_SLASH, KC_COMMA, KC_DOT, KC_P, KC_Y,        KC_F, KC_G, KC_C, KC_R, KC_L, KC_DEL, 
//-----------------------------------------------------------------------------------------------------------------------
 	OSM(MOD_LSFT), KC_A, KC_O, KC_E, KC_U, KC_I,         KC_D, KC_H, KC_T, KC_N, KC_S, OSM(MOD_LALT), 
//-----------------------------------------------------------------------------------------------------------------------
	OSM(MOD_RCTL), KC_NUBS, KC_Q, KC_J, KC_K, KC_X, KC_PGDOWN, KC_PGUP, KC_B, KC_M, KC_W, KC_V, KC_Z, OSM(MOD_RSFT), 
//-----------------------------------------------------------------------------------------------------------------------
	MT(MOD_LCTL, KC_ESCAPE), OSM(MOD_RCTL), TO(1), MT(MOD_LGUI, KC_SPACE),        RALT_T(KC_ENTER), TO(2), OSM(MOD_LALT), KC_BSPC 
  ),

  [1] = LAYOUT(
//-----------------------------------------------------------------------------------------------------------------------
	KC_QUOTE, KC_EXLM, KC_AT, KC_HASH, KC_DLR, KC_PERC,        KC_DQUO, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_MINUS, 
//-----------------------------------------------------------------------------------------------------------------------
	KC_TAB, KC_1, KC_2, KC_3, KC_4, KC_5,        KC_6, KC_7, KC_8, KC_9, KC_0, KC_EQUAL, 
//-----------------------------------------------------------------------------------------------------------------------
	OSM(MOD_LSFT), KC_GRAVE, KC_TILD, KC_CIRCUMFLEX, KC_QUOTE, KC_MINUS,        KC_PGDOWN, KC_LEFT, KC_DOWN, KC_UP, KC_RIGHT, KC_PGUP, 
//-----------------------------------------------------------------------------------------------------------------------
	OSM(MOD_RCTL),  KC_NUBS, KC_LBRC, KC_RBRC, KC_LPRN, KC_RPRN, KC_PGDOWN, KC_PGUP, KC_SEMICOLON, KC_DOT, KC_COMMA, KC_QUES, KC_EXLM, KC_CAPS, 
//-----------------------------------------------------------------------------------------------------------------------
	MT(MOD_LCTL, KC_ESCAPE), OSM(MOD_RCTL), TO(0),  MT(MOD_LGUI, KC_SPACE),     RALT_T(KC_ENTER), TO(2), OSM(MOD_LALT),  KC_BSPC 
  ),

  [2] = LAYOUT(
//-----------------------------------------------------------------------------------------------------------------------
	KC_F1, KC_F2, KC_F3, KC_F4, KC_F5,        KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, 
//-----------------------------------------------------------------------------------------------------------------------
	KC_AUDIO_MUTE,  KC_AUDIO_VOL_DOWN, KC_AUDIO_VOL_UP, KC_MEDIA_STOP, KC_BRIGHTNESS_DOWN, KC_BRIGHTNESS_UP,        KC_PSCREEN, KC_F13, KC_F14, KC_F15, KC_F16, KC_F17, 
//-----------------------------------------------------------------------------------------------------------------------
	KC_AMPR, KC_PEQL, KC_PSLS, KC_PAST, KC_PMNS, KC_PPLS,        KC_PGDOWN, KC_LEFT, KC_DOWN, KC_UP, KC_RIGHT, KC_PGUP, 
//-----------------------------------------------------------------------------------------------------------------------
	KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_PGDOWN, KC_PGUP, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, 
//-----------------------------------------------------------------------------------------------------------------------
	MT(MOD_LCTL, KC_ESCAPE), OSM(MOD_RCTL), TO(1), MT(MOD_LGUI, KC_SPACE),        RALT_T(KC_ENTER), TO(0), OSM(MOD_RALT),  KC_BSPC 
  )
};

typedef struct {
    bool is_press_action;
    uint8_t step;
} tap;

enum {
    SINGLE_TAP = 1,
    SINGLE_HOLD,
    DOUBLE_TAP,
    DOUBLE_HOLD,
    DOUBLE_SINGLE_TAP,
    MORE_TAPS
};

