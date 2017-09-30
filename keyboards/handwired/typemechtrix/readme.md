TypeMechTrix
===

A 60% orthogonal handwired mechanical keyboard inspired by the Typematrix.

The aim was to use Emacs easily, so that a Ctrl key is accessible with the left thumb (right thumb if SPACEBAR_ON_LEFT_THUMB is defined) while the spacebar is on the right thumb (left thumb if SPACEBAR_ON_LEFT_THUMB is defined).



### Layout
The layout is available [here](http://www.keyboard-layout-editor.com/#/gists/4110a75ecdb349b13e17).


### Features
 * reset Teensy with Fn + Tab
 * space when spacebar tapped, Fn when held
 * caps locks when shift key is tapped, shift key when held
 * cut/copy/paste shortcuts


### Hand wiring:

The following works out of box with a Teensy 2.

Column pin configuration:

| col | 0  | 1  | 2  | 3  | 4  | 5  | 6  | 7  | 8  | 9  | 10 | 11 | 12 | 13 |
|-----|----|----|----|----|----|----|----|----|----|----|----|----|----|----|
| pin | B6 | F7 | F6 | F5 | F4 | F1 | F0 | B1 | B2 | B7 | D0 | D1 | D2 | D3 |

Row pin configuration:

| row | 0  | 1  | 2  | 3  | 4  |
|-----|----|----|----|----|----|
| pin | B5 | B4 | D7 | D6 | B0 |

For different wiring, update definitions of functions init_cols, read_cols, unselect_rows and select_row in matrix.c and MATRIX_COL_PINS/MATRIX_ROW_PINS in config.h


### Build firmware

To get the firmware for this keyboard:

     make handwired-typemechtrix


To compile and copy the firmware to the teensy (requires [teensy-loader-cli](https://github.com/PaulStoffregen/teensy_loader_cli) installed and set in the PATH):

     make handwired-typemechtrix-teensy


See [build environment setup](https://docs.qmk.fm/build_environment_setup.html) then the [make instructions](https://docs.qmk.fm/make_instructions.html) for more information.



