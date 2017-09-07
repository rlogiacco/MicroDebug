// This is optional, but set to false to disable
#define SERIAL_DEBUG true
#include <SerialDebug.h>

// Set the following if you wish to override the default
#define SERIAL_DEBUG_SEPARATOR ", "

int free() {
	extern int __heap_start, *__brkval;
	int v;
	return (int) &v - (__brkval == 0 ? (int) &__heap_start : (int) __brkval);
}

void setup() {
	SERIAL_DEBUG_SETUP(9600);
	DEBUG("Available memory", free());
	pinMode(A0, INPUT);
}

void loop() {
	int val = analogRead(A0);

	// Up to 10 params can be written in one single call
	DEBUG("analog read", val);

	delay(500);
}
