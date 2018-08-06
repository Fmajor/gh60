/*
Copyright 2013,2014 Kai Ryu <kai1103@gmail.com>

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

#include <avr/io.h>
#include <avr/interrupt.h>
#include <avr/pgmspace.h>
#include "backlight.h"
#include "action.h"

#ifdef BACKLIGHT_ENABLE

void backlight_enable(void);
void backlight_disable(void);
inline void backlight_set_raw(uint8_t raw);

static const uint8_t backlight_table[] PROGMEM = {
    0, 16, 128, 255
};

/* Backlight pin configuration
 * PWM:  PB6                  (Rev.CHN)
 */
void backlight_enable(void)
{
    // Turn on PWM
    DDRB |= (1<<PB6);
    cli();
    TCCR1A |= ((1<<WGM10) | (1<<COM1B1));
    TCCR1B |= ((1<<CS11) | (1<<CS10));
    sei();
}

void backlight_disable(void)
{
    // Turn off PWM
    cli();
    DDRB &= ~(1<<PB6);
    TCCR1A &= ~((1<<WGM10) | (1<<COM1B1));
    TCCR1B &= ~((1<<CS11) | (1<<CS10));
    sei();
    OCR1B = 0;
}

void backlight_set(uint8_t level)
{
    if (level > 0) {
        backlight_enable();
        backlight_set_raw(pgm_read_byte(&backlight_table[level]));
    }
    else {
        backlight_disable();
    }
}

inline void backlight_set_raw(uint8_t raw)
{
    OCR1B = raw;
}

#endif
