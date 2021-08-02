#include <Arduino.h>
#include <FastLED.h>
#include <JC_Button.h>

#define NUM_LEDS    6
#define PIN_LEDS    6   // D6
#define PIN_BTN     7   // D7

#define COLOR_ORDER GRB
#define BRIGHTNESS  255
#define ARRAY_SIZE(x) (sizeof(x) / sizeof((x)[0]))

Button btn(PIN_BTN);
CRGB leds[NUM_LEDS];

int incomingByte = 0;

byte stp;
unsigned long timeForAction;

struct LRGBT {
	byte led, R, G, B; 
	unsigned long time;
};
LRGBT *seq;
long seqSize;
int seqNum;

#include "animation.h"

void setup() {
	seqNum = 0;
	seq = aniBlank;
	seqSize = ARRAY_SIZE(aniBlank);
	delay(100);

	btn.begin();
	
	FastLED.addLeds<WS2811, PIN_LEDS, COLOR_ORDER>(leds, NUM_LEDS).setCorrection(TypicalLEDStrip);
	FastLED.setBrightness(BRIGHTNESS);
	FastLED.clear(true);
	FastLED.show();
}

void loop() {
	btn.read();
	if (btn.wasReleased()) {
		seqNum++;
		// hlidani poctu sekvenci
		// kdyz pridate dalsi je potreba cislo zvetsit
		if (seqNum > 4) seqNum = 0;
		FastLED.clear(true);
		stp = 0;
		timeForAction = 0;
		// prepinani sekveci
		switch (seqNum) {
			// sekvence c. 1
			case 1:
				seq = aniBlikacka;
				seqSize = ARRAY_SIZE(aniBlikacka);
				break;
			// sekvence c. 2
			case 2:
				seq = aniBlikacka2;
				seqSize = ARRAY_SIZE(aniBlikacka2);
				break;
			// sekvence c. 3
			case 3:
				seq = aniMajak;
				seqSize = ARRAY_SIZE(aniMajak);
				break;
			// sekvence c. 4
			case 4:
				seq = aniRotace;
				seqSize = ARRAY_SIZE(aniRotace);
				break;

			// sekvence c. 0
			// slouzi jako vychozi, po zapnuti
			case 0:
			default:
				seq = aniBlank;
				seqSize = ARRAY_SIZE(aniBlank);
				break;
		}
	}

	// vlastni prehravac sekveni
	if (millis() > timeForAction) {
		leds[seq[stp].led] = CRGB(seq[stp].R, seq[stp].G, seq[stp].B);
		FastLED.show();
		timeForAction = millis() + seq[stp].time;
		stp = (stp + 1) % seqSize;
	}
}
