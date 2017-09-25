#include "keymap_common.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  KEYMAP( \
         ESC,  1,   2,   3,   4,   5,       6,   7,   8,   9,   0,  MINS, EQL,  \
         TAB,  Q,   W,   E,   R,   T, BSPC, Y,   U,   I,   O,   P,  LBRC, RBRC, \
               A,   S,   D,   F,   G,       H,   J,   K,   L,SCLN,  QUOT,       \
         LSFT, Z,   X,   C,   V,   B, ENT,  N,   M,COMM, DOT,SLSH,BSLASH, RSFT, \
         LCTL   ,  LALT   ,   SPC   , FN0,  RCTL  ,  RALT   ,    LGUI   , FN1   ),
};
const uint16_t PROGMEM fn_actions[] = {};
