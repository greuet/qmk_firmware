#include "keymap_common.h"

#define _BASE  0
#define _FN    1
#define _NMPAD 2

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  /* _BASE: QWERTY. If your OS is set to use BÉPO then this is the layout to use
    ,-------------------------------------------------------.
    |ESC|  1|  2|  3|  4|  5|   |  6|  7|  8|  9|  0|  -|  =|
    |-----------------------|BSP|---------------------------|
    |Tab|  Q|  W|  E|  R|  T|   |  Y|  U|  I|  O|  P|  [|  ]|
    |-------------------------------------------------------|
    |   |  A|  S|  D|  F|  G|   |  H|  J|  K|  L|  ;|  '|   |
    |Sft|-------------------|RET|-----------------------|Sft|
    |   |  Z|  X|  C|  V|  B|   |  N|  M|  ,|  .|  /|  \|   |
    |-------------------------------------------------------|
    |  Ctrl |  Alt  | Space |Fn |  Ctrl | AltGr |  Win  |NmP|
    `-------------------------------------------------------'
  */
#ifdef SPACEBAR_ON_LEFT_THUMB
    [_BASE] = KEYMAP(                                                         \
       ESC, 1,  2,  3,  4,  5,        6,   7,   8,   9,   0,  MINS, EQL,      \
       TAB, Q,  W,  E,  R,  T, BSPC  ,Y,   U,   I,   O,   P,  LBRC, RBRC,     \
            A,  S,  D,  F,  G,        H,   J,   K,   L,SCLN,  QUOT,           \
       LSFT,Z,  X,  C,  V,  B, ENT   ,N,   M,COMM, DOT,SLSH,BSLASH, RSFT,     \
       LCTL  , LALT  ,  SPC  ,MO(_FN),RCTL  ,  RALT   ,    LGUI   ,TG(_NMPAD)),
#else
    [_BASE] = KEYMAP(                                                         \
       ESC, 1,  2,  3,  4,  5,        6,   7,   8,   9,   0,  MINS, EQL,      \
       TAB, Q,  W,  E,  R,  T, BSPC  ,Y,   U,   I,   O,   P,  LBRC, RBRC,     \
            A,  S,  D,  F,  G,        H,   J,   K,   L,SCLN,  QUOT,           \
       LSFT,Z,  X,  C,  V,  B, ENT   ,N,   M,COMM, DOT,SLSH,BSLASH, RSFT,     \
       LCTL  , LALT  , RCTL  ,MO(_FN), SPC  ,  RALT   ,    LGUI   ,TG(_NMPAD)),
#endif
   /* _FN0:
    ,----------------------------------------------------------.
    | ` | F1| F2| F3| F4| F5|   | F6| F7| F8| F9 | F10| F11|F12|
    |-----------------------|Del|------------------------------|
    |Tab|   |   | Up|   |   |   |Udo|   | Up|    |    |    |PSc|
    |----------------------------------------------------------|
    |   |   |Lef|Dow|Rig|   |   |   |Lef|Dow|Rig |    |    |   |
    |CAP|-------------------|Sft|--------------------------|CAP|
    |   |   |   |   |   |   |   |Cut|Cpy|Pst|mute|vol-|vol+|   |
    |----------------------------------------------------------|
    |  Ctrl |  Alt  |  Win  |Fn |  Prev |  Play  |   Next  |Stp|
    `----------------------------------------------------------'
  */
    [_FN] = KEYMAP(                                                            \
      GRV,  F1 , F2 , F3 , F4 , F5 ,DELETE, F6 , F7 , F8  , F9 , F10, F11, F12,\
      TRNS,TRNS,TRNS, UP ,TRNS,TRNS,       UNDO,TRNS, UP  ,TRNS,TRNS,TRNS,PSCR,\
      CAPS,TRNS,LEFT,DOWN,RGHT,TRNS, LSFT ,TRNS,LEFT,DOWN ,RGHT,TRNS,TRNS,     \
           TRNS,TRNS,TRNS,TRNS,TRNS,        CUT,COPY,PASTE,MUTE,VOLD,VOLU,CAPS,\
      TRNS     , TRNS    ,  LGUI   ,KC_TRNS,MPRV,   MPLY  ,    MNXT , KC_MSTP ),



    /* _NMPAD = numpad mode:
    ,-------------------------------------------------------.
    |ESC|   |   |   |   |Del|   |Del|   |   |num| / | * | - |
    |-----------------------|BSP|---------------------------|
    |Tab|   |   | Up|   |   |   |Udo|   |   | 7 | 8 | 9 | + |
    |-------------------------------------------------------|
    |   |   |Lft|Dow|Rig|   |   |   |   |   | 4 | 5 | 6 |   |
    |Sft|-------------------|RET|-----------------------|RET|
    |   |   |   |   |   |   |   |Cut|Cpy|Pst| 1 | 2 | 3 |   |
    |-------------------------------------------------------|
    |  Ctrl |  Alt  | Space |   |  Ctrl |   0  |   .    |NmP|
    `-------------------------------------------------------'
  */

    [_NMPAD] = KEYMAP(                                                        \
      ESC, NO, NO , NO , NO ,DELETE,TRNS,DELETE,NO  , NO  ,NLCK,PSLS,PAST,PMNS,\
      TRNS,NO, NO , UP , NO ,  NO  ,      UNDO ,NO  , NO  ,P7  ,P8  ,P9  ,PPLS,\
      TRNS,NO,LEFT,DOWN,RGHT,  NO  ,TRNS, NO   ,NO  , NO  ,P4  ,P5  ,P6  ,     \
           NO, NO , NO , NO ,  NO  ,      CUT  ,COPY,PASTE,P1  ,P2  ,P3  ,PENT,\
      TRNS   ,  TRNS   , TRNS      ,KC_NO,   TRNS   ,   P0     ,  PDOT,KC_TRNS),
};


const uint16_t PROGMEM fn_actions[] = {};
