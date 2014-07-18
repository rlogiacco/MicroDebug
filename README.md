ArduinoDebug
============

Whenever you run your projects you want to have some feedback of what's happening on your board, but most of the times you don't want those *debug* instructions to get into your production code, especially considering the limits in the Arduino memory capacity.

This library provides some means of easily handle this situation, exposing some pre-processor macro directives you can easily turn off to magically switch off the debug statements.

Usage
============

Serial interface
------------

The simplest and most used mean of interfacing to Arduino is through serial connection and I recommend to use this in every case where it is applicable.

The usage is very simple: include the `SerialDebug.h` header and you get two macros.

- the first one, to include in your `setup()` function, is `SERIAL_DEBUG_SETUP` which activates the serial connection at a specific baud rate
- the second one is instead a set of macros, but for simplicity you can consider them like an overloaded method `DEBUG` capable of accepting 0 to 10 parameters, each one will be printed onto the serial connection

In addition you get a couple of definitions you can override to customize the output:
- `SERIAL_DEBUG` defaults to `true` and activated/deactivates the entire library 
- `SERIAL_DEBUG_SEPARATOR` defaults to `" | "` (pipe character preceeded and followed by space) which is used as a separator between each argument

**NOTE** to deactivate the library for final release you must `#define SERIAL_DEBUG false` ***before*** including the `SerialDebug.h` header file. 

```
// uncomment the following to disable serial debug statements
//#define SERIAL_DEBUG false
#include <SerialDebug.h>

void setup() {
  SERIAL_DEBUG_SETUP(9600);
}

void loop() {
  DEBUG("time", millis());
  delay(1000);
}
```

LED interface
------------

If you are already using the serial interface for other purposes or if you don't have access to a serial interface at all, you can use an LED to monitor the execution status of your sketch: it will not provide you the ability to `print out` information, but you can still blink the LED to determine if something has been correctly processed or not.

In such cases you can include the `LedDebug.h` header to get the `PULSE` macro: call it with no parameter to blink the LED once, call it with one parameter to determine the number of blinks you want to reproduce or use the two parameters version to specify the number of pulses and their duration.


In addition you get a couple of definitions you can override to customize the pulses:
- `LED_DEBUG` defaults to `true` and activated/deactivates the entire library 
- `LED_DEBUG_PIN` defaults to the built in LED pin, usually digital pin 13
- `LED_DEBUG_DELAY` defaults to 50 and indicates the default interval in milliseconds between each PULSE invocation
- `LED_DEBUG_LENGHT` defaults to 125 and indicates the default duration in milliseconds of a blink 

**NOTE** to deactivate the library for final release you must `#define LED_DEBUG false` ***before*** including the `SerialDebug.h` header file. 


**NOTE** the library uses the standard `delay()`  function internally which can interfere with your sketch operations.

```
// uncomment the following to disable LED debug statements
//#define LED_DEBUG false
#include <LedDebug.h>

void loop() {
  // following statement will delay for 250ms and emits one blink, lasting 125ms
  PULSE();
  delay(1000);
  
  
  // following statement will delay for 550ms end emits two blinks, each one lasting 125ms
  PULSE(2);
  delay(5000);
}
```
