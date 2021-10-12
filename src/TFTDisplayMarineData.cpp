#include <TFTDisplayMarineData.h>

TFT_eSPI _tft = TFT_eSPI();                            // Invoke custom library
float sx = 0, sy = 1, mx = 1, my = 0, hx = -1, hy = 0; // Saved H, M, S x & y multipliers
float sdeg = 0, mdeg = 0, hdeg = 0;
uint16_t osx = 120, osy = 120, omx = 120, omy = 120, ohx = 120, ohy = 120; // Saved H, M, S x & y coords
uint16_t x0 = 0, x1 = 0, yy0 = 0, yy1 = 0;
uint32_t targetTime = 0; // for next 1 second timeout
bool initial = 1;
uint8_t hh = conv2d(__TIME__), mm = conv2d(__TIME__ + 3), ss = conv2d(__TIME__ + 6); // Get H, M, S from compile time

void TFT_InitDisplay(String depthUnit)
{
  _tft.init();
  _tft.setRotation(0);
  _tft.fillScreen(TFT_BLACK);

  _tft.setTextColor(TFT_WHITE, TFT_BLACK); // Adding a background colour erases previous text automatically

  TFT_DrawBaseDepthArea(depthUnit);
}
void TFT_DrawBaseDepthArea(String depthUnit) {
  _tft.fillCircle(120, 120, 118, TFT_GREEN);
  _tft.fillCircle(120, 120, 110, TFT_BLACK);

  // Draw text at position 120,260 using fonts 4
  // Only font numbers 2,4,6,7 are valid. Font 6 only contains characters [space] 0 1 2 3 4 5 6 7 8 9 : . - a p m
  // Font 7 is a 7 segment font and only contains characters [space] 0 1 2 3 4 5 6 7 8 9 : .
  _tft.setFreeFont(FSS18);
  _tft.setTextColor(TFT_WHITE, TFT_BLACK);
  _tft.drawCentreString(depthUnit.c_str(), 120, 180, GFXFF);
}

void TFT_DrawDepth(float theDepth, bool alarm)
{
  String _depth = String(theDepth);
  /*
  if (_depth.length() < 6)
  {
    for (int i = 0; i <= 6 - _depth.length(); i++)
    {
      _depth = " " + _depth;
    }
  }
  */
  if(alarm) {
    _tft.setTextColor(TFT_WHITE, TFT_RED);
  } else {
    _tft.setTextColor(TFT_WHITE, TFT_BLACK);
  }
  _tft.drawCentreString(_depth.c_str(), 120, 96, FONT7);
}

static uint8_t conv2d(const char *p)
{
  uint8_t v = 0;
  if ('0' <= *p && *p <= '9')
    v = *p - '0';
  return 10 * v + *++p - '0';
}
