#include <display_helper.h>

void printHistogram(int16_t *data) {
  ssd1306_DrawRectangle(0, 0, 126, 64 - 10, White);
  for (int i = 0; i < 126; i++) {
    ssd1306_Line(i, 1, i, data[i], White);
  }
}

void display_print_freq(char separator, uint32_t frequency,
                        enum modulation mod) {
  char buff[16];
  const int32_t MHz = frequency / 1000000;
  frequency %= 1000000;
  const int32_t kHz = frequency / 1000;
  frequency %= 1000;
  snprintf(buff, 16, "%2ld%c%03ld%c%c%c%c", MHz, separator, kHz, separator, 'k',
           'H', 'z');
  int8_t lastlineY = 7 * 8;  // 8lines * 8charheight
  ssd1306_SetCursor(0, lastlineY);
  ssd1306_WriteString(buff, Font_6x8, White);
  ssd1306_SetCursor(18 * 6, lastlineY);
  switch (mod) {
    case AM:
      ssd1306_WriteString("AM", Font_6x8, White);
      break;
    case UpSB:
      ssd1306_WriteString("USB", Font_6x8, White);
      break;
    case LoSB:
      ssd1306_WriteString("LSB", Font_6x8, White);
      break;
    case CW:
      ssd1306_WriteString("CW", Font_6x8, White);
      break;
  }
}