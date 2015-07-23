#include "FastLED.h"

#define NUM_STRIPS 2
#define NUM_LEDS_PER_STRIP 20
#define NUM_LEDS NUM_LEDS_PER_STRIP * NUM_STRIPS

CRGB leds[NUM_STRIPS * NUM_LEDS_PER_STRIP];

// For mirroring strips, all the "special" stuff happens just in setup.  We
// just addLeds multiple times, once for each strip
void setup() {
  FastLED.addLeds<NEOPIXEL, 9>(leds, 32);
  FastLED.addLeds<WS2801, 3, 2, RGB>(leds,20);
}

void loop() {
  for(int i = 0; i < NUM_LEDS; i++) {
    leds[i] = CRGB::Purple;
    FastLED.show();
    leds[i] = CRGB::Black;
    delay(100);
  }
}
