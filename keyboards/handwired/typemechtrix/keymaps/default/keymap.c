#include "keymap_common.h"

#define _BASE  0
#define _FN    1
#define _NMPAD 2

// macro to cut/copy/paste
#define KC_MCUT  LSFT(KC_DELETE)
#define KC_MCPY  LCTL(KC_INSERT)
#define KC_MPSTE LSFT(KC_INSERT)


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
    KC_TAB, Q,  W,  E,  R,  T, BSPC  ,Y,   U,   I,   O,   P,  LBRC, RBRC,     \
            A,  S,  D,  F,  G,        H,   J,   K,   L,SCLN,  QUOT,           \
       LSFT,Z,  X,  C,  V,  B, ENT   ,N,   M,COMM, DOT,SLSH,BSLASH, RSFT,     \
    LCTL  , LALT,LT(_FN,KC_SPC),MO(_FN),RCTL,  RALT   ,    LGUI   ,TG(_NMPAD)),
#else
    [_BASE] = KEYMAP(                                                         \
       ESC, 1,  2,  3,  4,  5,        6,   7,   8,   9,   0,  MINS, EQL,      \
    KC_TAB, Q,  W,  E,  R,  T, BSPC  ,Y,   U,   I,   O,   P,  LBRC, RBRC,     \
            A,  S,  D,  F,  G,        H,   J,   K,   L,SCLN,  QUOT,           \
       LSFT,Z,  X,  C,  V,  B, ENT   ,N,   M,COMM, DOT,SLSH,BSLASH, RSFT,     \
       LCTL  , LALT  , RCTL  ,MO(_FN), SPC  ,  RALT   ,    LGUI   ,TG(_NMPAD)),
#endif
   /* _FN0:
    ,----------------------------------------------------------.
    | ` | F1| F2| F3| F4| F5|   | F6| F7| F8| F9 | F10| F11|F12|
    |-----------------------|Del|------------------------------|
    |Rst|   |   | Up|   |   |   |Udo|   | Up|    |    |    |PSc|
    |----------------------------------------------------------|
    |   |   |Lef|Dow|Rig|   |   |   |Lef|Dow|Rig |    |    |   |
    |CAP|-------------------|Sft|--------------------------|CAP|
    |   |   |   |   |   |   |   |Cut|Cpy|Pst|mute|vol-|vol+|   |
    |----------------------------------------------------------|
    |  Ctrl |  Win  |  Fn   |Fn |  Prev |  Play  |   Next  |Stp|
    `----------------------------------------------------------'
  */
    [_FN] = KEYMAP(                                                            \
      GRV,  F1 , F2 , F3 , F4 , F5 ,        F6 , F7 , F8  , F9 , F10, F11, F12,\
    RESET,TRNS,TRNS, UP ,TRNS,TRNS,DELETE, UNDO,TRNS, UP  ,TRNS,TRNS,TRNS,PSCR,\
           TRNS,LEFT,DOWN,RGHT,TRNS,       TRNS,LEFT,DOWN ,RGHT,TRNS,TRNS,     \
      CAPS,TRNS,TRNS,TRNS,TRNS,TRNS, LSFT, MCUT,MCPY,MPSTE,MUTE,VOLD,VOLU,CAPS,\
      TRNS     , LGUI    ,KC_TRNS ,KC_TRNS,MPRV ,   MPLY  ,    MNXT , KC_MSTP ),



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
      ESC, NO, NO , NO , NO ,DELETE,      DELETE,NO  , NO  ,NLCK,PSLS,PAST,PMNS,\
   KC_TRNS,NO, NO , UP , NO ,  NO  ,TRNS, UNDO ,NO  , NO  ,P7  ,P8  ,P9  ,PPLS,\
           NO,LEFT,DOWN,RGHT,  NO  ,      NO   ,NO  , NO  ,P4  ,P5  ,P6  ,     \
      TRNS,NO, NO , NO , NO ,  NO  ,TRNS, CUT  ,COPY,PASTE,P1  ,P2  ,P3  ,PENT,\
      TRNS   ,  TRNS   , KC_TRNS   ,KC_NO,   TRNS   ,   P0     ,  PDOT,KC_TRNS),
};
