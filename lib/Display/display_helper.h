#ifndef __DISPLAY_H
#define __DISPLAY_H

#include <radio.h>
#include <ssd1306.h>
#include <ssd1306_fonts.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Should receive data array of 128 elements (display width)
void printHistogram(int16_t *data);
void display_print_freq(char separator, uint32_t frequency,
                        enum modulation mod);

#endif