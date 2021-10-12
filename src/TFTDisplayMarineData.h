#ifndef TFTDISPLAYMARINEDATA_H
#define TFTDISPLAYMARINEDATA_H

#include <TFT_eSPI.h> // Hardware-specific library
#include <SPI.h>
#include <Free_Fonts.h>

#define TFT_GREY 0x5AEB

void TFT_InitDisplay(String depthUnit);
void TFT_DrawDepth(float theDepth, bool alarm);
void TFT_DrawBaseDepthArea(String depthUnit);
static uint8_t conv2d(const char* p);

#endif