#include "keymap_common.h"

#define _BASE              0
#define _BASE_RIGHT_SPACE  1
#define _FN                2

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
    |  Ctrl |  Alt  |Spc/Win|Fn |  Ctrl | AltGr |  Win  |NmP|
    `-------------------------------------------------------'
  */
    [_BASE] = KEYMAP(                                                         \
       ESC, 1,  2,  3,  4,  5,        6,   7,   8,   9,   0,  MINS, EQL,      \
    KC_TAB, Q,  W,  E,  R,  T, BSPC  ,Y,   U,   I,   O,   P,  LBRC, RBRC,     \
            A,  S,  D,  F,  G,        H,   J,   K,   L,SCLN,  QUOT,           \
MT(MOD_LSFT,KC_CAPS),Z,  X,  C,  V,  B, ENT   ,N,   M,COMM, DOT,SLSH,BSLASH,MT(MOD_RSFT,KC_CAPS), \
    LCTL  , LALT,GUI_T(KC_SPC),MO(_FN),KC_RCTL,  RALT   ,    LGUI   ,TG(_BASE_RIGHT_SPACE)),


  /* _BASE: QWERTY with Spacebar on right thumb
    ,-------------------------------------------------------.
    |ESC|  1|  2|  3|  4|  5|   |  6|  7|  8|  9|  0|  -|  =|
    |-----------------------|BSP|---------------------------|
    |Tab|  Q|  W|  E|  R|  T|   |  Y|  U|  I|  O|  P|  [|  ]|
    |-------------------------------------------------------|
    |   |  A|  S|  D|  F|  G|   |  H|  J|  K|  L|  ;|  '|   |
    |Sft|-------------------|RET|-----------------------|Sft|
    |   |  Z|  X|  C|  V|  B|   |  N|  M|  ,|  .|  /|  \|   |
    |-------------------------------------------------------|
    |  Ctrl |  Alt  |  Ctrl |Fn |Spc/Win| AltGr |  Win  |NmP|
    `-------------------------------------------------------'
  */
    [_BASE_RIGHT_SPACE] = KEYMAP(                                                         \
       ESC, 1,  2,  3,  4,  5,        6,   7,   8,   9,   0,  MINS, EQL,      \
    KC_TAB, Q,  W,  E,  R,  T, BSPC  ,Y,   U,   I,   O,   P,  LBRC, RBRC,     \
            A,  S,  D,  F,  G,        H,   J,   K,   L,SCLN,  QUOT,           \
MT(MOD_LSFT,KC_CAPS),Z,  X,  C,  V,  B, ENT   ,N,   M,COMM, DOT,SLSH,BSLASH,MT(MOD_RSFT,KC_CAPS), \
       LCTL  , LALT  , KC_RCTL  ,MO(_FN), GUI_T(KC_SPC),  RALT   ,    LGUI   ,KC_TRNS),

   /* _FN:
    ,----------------------------------------------------------.
    | ` | F1| F2| F3| F4| F5|   | F6| F7| F8| F9 | F10| F11|F12|
    |-----------------------|Del|------------------------------|
    |Rst|   |   | Up|   |   |   |Udo|   | Up|    |    |    |PSc|
    |----------------------------------------------------------|
    |   |   |Lef|Dow|Rig|   |   |   |Lef|Dow|Rig |    |    |   |
    |Sft|-------------------|Sft|--------------------------|Sft|
    |   |   |   |   |   |   |   |Cut|Cpy|Pst|mute|vol-|vol+|   |
    |----------------------------------------------------------|
    |  Ctrl |  Alt  |Spc/Win|Fn |  Prev |  Play  |   Next  |Stp|
    `----------------------------------------------------------'
  */
    [_FN] = KEYMAP(                                                            \
      GRV,  F1 , F2 , F3 , F4 , F5 ,        F6 , F7 , F8  , F9 , F10, F11, F12,\
    RESET,TRNS,TRNS, UP ,TRNS,TRNS,DELETE, UNDO,TRNS, UP  ,TRNS,TRNS,TRNS,PSCR,\
           TRNS,LEFT,DOWN,RGHT,TRNS,       TRNS,LEFT,DOWN ,RGHT,TRNS,TRNS,     \
 KC_TRNS,TRNS,TRNS,TRNS,TRNS,TRNS, LSFT, MCUT,MCPY,MPSTE,MUTE,VOLD,VOLU,KC_TRNS,\
      TRNS     , TRNS  ,GUI_T(KC_SPC) ,KC_TRNS,KC_MPRV ,   MPLY  ,    MNXT , KC_MSTP ),
};
