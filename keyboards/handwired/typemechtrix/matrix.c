/*
Copyright 2012 Jun Wako <wakojun@gmail.com>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

/*
 * scan matrix
 */
#include <stdint.h>
#include <stdbool.h>
#include <avr/io.h>
#include <util/delay.h>
#include "print.h"
#include "debug.h"
#include "util.h"
#include "matrix.h"


#ifndef DEBOUNCE
#   define DEBOUNCE	5
#endif
static uint8_t debouncing = DEBOUNCE;

/* matrix state(1:on, 0:off) */
static matrix_row_t matrix[MATRIX_ROWS];
static matrix_row_t matrix_debouncing[MATRIX_ROWS];

static matrix_row_t read_cols(void);
static void init_cols(void);
static void unselect_rows(void);
static void select_row(uint8_t row);


inline
uint8_t matrix_rows(void)
{
    return MATRIX_ROWS;
}

inline
uint8_t matrix_cols(void)
{
    return MATRIX_COLS;
}

void matrix_init(void)
{
    // initialize row and col
    unselect_rows();
    init_cols();

    // initialize matrix state: all keys off
    for (uint8_t i=0; i < MATRIX_ROWS; i++) {
        matrix[i] = 0;
        matrix_debouncing[i] = 0;
    }

    //debug
    debug_matrix = true;
    LED_ON();
    _delay_ms(500);
    LED_OFF();
}

uint8_t matrix_scan(void)
{
    for (uint8_t i = 0; i < MATRIX_ROWS; i++) {
        select_row(i);
        _delay_us(30);  // without this wait read unstable value.
        matrix_row_t cols = read_cols();
        if (matrix_debouncing[i] != cols) {
            matrix_debouncing[i] = cols;
            if (debouncing) {
                debug("bounce!: "); debug_hex(debouncing); debug("\n");
            }
            debouncing = DEBOUNCE;
        }
        unselect_rows();
    }

    if (debouncing) {
        if (--debouncing) {
            _delay_ms(1);
        } else {
            for (uint8_t i = 0; i < MATRIX_ROWS; i++) {
                matrix[i] = matrix_debouncing[i];
            }
        }
    }

    matrix_scan_quantum();

    return 1;
}

inline
bool matrix_is_on(uint8_t row, uint8_t col)
{
    return (matrix[row] & ((matrix_row_t)1<<col));
}

inline
matrix_row_t matrix_get_row(uint8_t row)
{
    return matrix[row];
}

void matrix_print(void)
{
    print("\nr/c 0123456789ABCDEF\n");
    for (uint8_t row = 0; row < MATRIX_ROWS; row++) {
        phex(row); print(": ");
        pbin_reverse16(matrix_get_row(row));
        print("\n");
    }
}

/* Column pin configuration
 * col: 0   1   2   3   4   5   6   7   8   9   10  11  12  13
 * pin: B6  F7  F6  F5  F4  F1  F0  B1  B2  B7  D0  D1  D2  D3
 */
static void  init_cols(void)
{
    // Input with pull-up(DDR:0, PORT:1)
    DDRB  &= ~0b11000110;
    PORTB |=  0b11000110;
    DDRF  &= ~0b11110011;
    PORTF |=  0b11110011;
    DDRD  &= ~0b00001111;
    PORTD |=  0b00001111;
    
}

/* Returns status of switches(1:on, 0:off) */
static matrix_row_t read_cols(void)
{
    return (PINB&(1<<6) ? 0 : (1<<0)) |
      (PINF&(1<<7) ? 0 : (1<<1))  |
      (PINF&(1<<6) ? 0 : (1<<2))  |
      (PINF&(1<<5) ? 0 : (1<<3))  |
      (PINF&(1<<4) ? 0 : (1<<4))  |
      (PINF&(1<<1) ? 0 : (1<<5))  |
      (PINF&(1<<0) ? 0 : (1<<6))  |
      (PINB&(1<<1) ? 0 : (1<<7))  |
      (PINB&(1<<2) ? 0 : (1<<8))  |
      (PINB&(1<<7) ? 0 : (1<<9))  |
      (PIND&(1<<0) ? 0 : (1<<10)) |
      (PIND&(1<<1) ? 0 : (1<<11)) |
      (PIND&(1<<2) ? 0 : (1<<12)) |
      (PIND&(1<<3) ? 0 : (1<<13));
}

/* Row pin configuration
 * row: 0   1   2   3   4
 * pin: B5  B4  D7  D6  B0
 */
static void unselect_rows(void)
{
    // Hi-Z(DDR:0, PORT:0) to unselect
    DDRD  &= ~0b11000000;
    PORTD &= ~0b11000000;
    DDRB  &= ~0b00110001;
    PORTB &= ~0b00110001;
}


static void select_row(uint8_t row)
{
    // Output low(DDR:1, PORT:0) to select
  switch (row) {
  case 0:
    DDRB  |= (1<<5);
    PORTB &= ~(1<<5);
    break;
  case 1:
    DDRB  |= (1<<4);
    PORTB &= ~(1<<4);
    break;
  case 2:
    DDRD  |= (1<<7);
    PORTD &= ~(1<<7);
    break;
  case 3:
    DDRD  |= (1<<6);
    PORTD &= ~(1<<6);
    break;
  case 4:
    DDRB  |= (1<<0);
    PORTB &= ~(1<<0);
    break;
  }
}
