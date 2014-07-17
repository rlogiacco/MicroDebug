// This is optional, but set to false to disable
#define LED_DEBUG true
#include <LedDebug.h>

// Set this to override the default value
#define LED_DEBUG_PIN 13

void setup() {
	// No setup required
}

void loop() {
	int val = analogRead(A0);

	// Emits one single pulse
	PULSE();

	delay(500);

	// Emits multiple pulses
	PULSE(5);

	delay(500);

	// Emits multiple pulses of custom duration
	PULSE(3, 250);

	delay(500);
}
