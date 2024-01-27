// This is optional, but set to false to disable
#define SERIAL_DEBUG true
#include <SerialDebug.h>

// Set the following if you wish to override the default
#define SERIAL_DEBUG_SEPARATOR ", "

#ifndef A0 // esp32 doesn't define analog pins
#define A0 32
#endif

void setup() {
	SERIAL_DEBUG_SETUP(9600);
	pinMode(A0, INPUT);
}

void loop() {
	int val = analogRead(A0);

	// Up to 10 params can be written in one single call
	DEBUG("analog read", val);

	delay(500);
}
