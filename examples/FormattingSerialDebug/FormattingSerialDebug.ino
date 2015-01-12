// This is optional, but set to false to disable
#define SERIAL_DEBUG true
#include <FormattingSerialDebug.h>

void setup() {
	SERIAL_DEBUG_SETUP(9600);
	DEBUG("Free memory is %u bytes", FREE_RAM);
	pinMode(A0, INPUT);
}

void loop() {
	int val = analogRead(A0);

	// Number of allowed parameters is limited only by the pre processor
	DEBUG("analog read is %u", val);

	delay(500);
}
