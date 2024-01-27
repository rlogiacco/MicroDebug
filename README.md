### ⚠ **IMPORTANT**
 
> Please, before submitting a support request read carefully this README and check if an answer already exists among [previously answered questions](https://github.com/rlogiacco/MicroDebug/discussions): do not abuse of the Github issue tracker.

<!-- omit in toc -->
<h1>
  MicroDebug
  <a href=https://github.com/rlogiacco/MicroDebug/stargazers><img alt="GitHub stars" src=https://img.shields.io/github/stars/rlogiacco/MicroDebug.svg?style=social&label=Star /></a>
  <a href=https://github.com/rlogiacco/MicroDebug/network><img alt="GitHub forks" src=https://img.shields.io/github/forks/rlogiacco/MicroDebug.svg?style=social&label=Fork /></a>
  <a href=https://twitter.com/intent/tweet?text=Debug%20your%20code%20on%20embedded%20devices%20easily!&url=https://github.com/rlogiacco/MicroDebug&hashtags=IoT,Arduino,ESP8266,ESP32><img alt="Tweet" src=https://img.shields.io/twitter/url/http/shields.io.svg?style=social /></a>
</h1>

[![GitHub version](https://img.shields.io/github/release/rlogiacco/MicroDebug.svg)](https://github.com/rlogiacco/MicroDebug/releases)
[![GitHub download](https://img.shields.io/github/downloads/rlogiacco/MicroDebug/total.svg)](https://github.com/rlogiacco/MicroDebug/releases/latest)
[![GitHub stars](https://img.shields.io/github/stars/rlogiacco/MicroDebug.svg)](https://github.com/rlogiacco/MicroDebug/stargazers)
[![GitHub issues](https://img.shields.io/github/issues/rlogiacco/MicroDebug.svg)](https://github.com/rlogiacco/MicroDebug/issues)
[![Build Status](https://github.com/rlogiacco/MicroDebug/actions/workflows/main.yml/badge.svg)](https://github.com/rlogiacco/MicroDebug/actions/workflows/main.yml)
[![License](https://img.shields.io/badge/license-LGPL%203-blue.svg)](https://github.com/rlogiacco/MicroDebug/blob/master/LICENSE)

Whenever you run your projects you want to have some feedback on what's happening on your board, but most of the times you don't want those *debug* instructions to get into your production code, especially considering the limits of the microcontroller's memory capacity.

This library provides some means of easily handling this situation, exposing some pre-processor macro directives you can easily turn off to completely remove debug statements and save program memory.

<!-- toc -->
- [Serial interface](#serial-interface)
  - [Basic Serial](#basic-serial)
  - [Formatting Serial](#formatting-serial)
    - [Supported notation](#supported-notation)
- [LED interface](#led-interface)
- [Known Issues](#known-issues)

<!-- tocstop -->

# Serial interface

The simplest and most used way of interfacing with Arduino or other microcontrollers is through the serial connection and I recommend using this in every case where it is applicable.

There are two versions of this interface: a very basic one (`SerialDebug`) which uses a separator pattern and a more evolved one (`FormattingSerialDebug`) providing format capabilities through `printf` function. You should prefer the latter whenever you have access to `printf`, usually available through `stdio.h`.

Please also note both serial implementations support the use of the `F()` macro to reduce the RAM usage whenever necessary by using `PROGMEM` to store strings. To put it simply, the following two statements are both supported and produce the same output, but with different memory impacts:

```cpp
	DEBUG("elapsed time is %lums", millis()); // format string stored in RAM
	DEBUG(F("elapsed time is %lums"), millis()); // format string stored in PROGMEM
```

## Basic Serial

The usage is very simple: include the `SerialDebug.h` header and you get two macros.

- one, to include in your `setup()` function, is `SERIAL_DEBUG_SETUP` which activates the serial connection at a specific baud rate
- another one is instead a set of macros, but for simplicity, you can consider them like an overloaded method `DEBUG` capable of accepting 1 to 10 parameters, each one will be printed onto the serial connection

In addition, you get a couple of definitions you can override to customize the output:
- `SERIAL_DEBUG` defaults to `true` and activates/deactivates the entire library 
- `SERIAL_DEBUG_SEPARATOR` defaults to `" | "` (pipe character preceded and followed by space) which is used as a separator between each argument
- `SERIAL_DEBUG_IMPL` defaults to `Serial` which is the underlying serial target

**NOTE** to deactivate the library for final release you must `#define SERIAL_DEBUG false` ***before*** including the `SerialDebug.h` header file. 

```cpp
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

## Formatting Serial

The formatting version has been modeled on the same usage model of the basic implementation: the two are almost completely swappable by just changing the include statement to `FormattingSerialDebug.h` header:

- `SERIAL_DEBUG_SETUP`, which activates the serial connection at a specific baud rate, should be included in your `setup()` 
- `DEBUG` is capable of accepting 1 or more parameters, the first one being the formatting string in the `printf` [format](http://en.wikipedia.org/wiki/Printf_format_string) 

As for the basic version you have library control through definitions:
- `SERIAL_DEBUG` defaults to `true` and activates/deactivates the entire library 
- `SERIAL_DEBUG_IMPL` defaults to `Serial` which is the underlying serial target

**NOTE** to deactivate the library for final release you must `#define SERIAL_DEBUG false` ***before*** including the `FormattingSerialDebug.h` header file. 

```cpp
// uncomment the following to disable serial debug statements
//#define SERIAL_DEBUG false
#include <FormattingSerialDebug.h>

void setup() {
  SERIAL_DEBUG_SETUP(9600);
}

void loop() {
  DEBUG("time is %ums", millis());
  delay(1000);
}
```


### Supported notation

Due to the memory limitation of the devices, the general implementations of the `printf` function don't support floating point numbers, but in case you really need support for floating points then providing `-Wl,-u,vfprintf -lprintf_flt -lm` compilation options can enable it.

Please refer to [this page](http://www.cplusplus.com/reference/cstdio/printf/) for a full reference of the accepted format string.

# LED interface

If you are already using the serial interface for other purposes or if you don't have access to a serial interface at all, you can use an LED to monitor the execution status of your sketch: it will not provide you with the ability to `print out` information, but you can still blink the LED to determine if something has been correctly processed or not.

In such cases, you can include the `LedDebug.h` header to get the `PULSE` macro: call it with no parameter to blink the LED once, call it with one parameter to determine the number of blinks you want to reproduce or use the two parameters version to specify the number of pulses and their duration.


In addition, you get a couple of definitions you can override to customize the pulses:
- `LED_DEBUG` defaults to `true` and activates/deactivates the entire library 
- `LED_DEBUG_PIN` defaults to the built-in LED pin on Arduino boards, usually digital pin 13
- `LED_DEBUG_DELAY` defaults to 50 and indicates the default interval in milliseconds between each PULSE invocation
- `LED_DEBUG_LENGHT` defaults to 125 and indicates the default duration in milliseconds of a blink 

**NOTE** to deactivate the library for final release you must `#define LED_DEBUG false` ***before*** including the `LedDebug.h` header file. 


**NOTE** the library uses the standard `delay()`  function internally which can interfere with your sketch operations.

```cpp
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

# Known Issues

On `ESP8266` devices the `FormattingSerialDebug` implementation is unable to correctly print **floating point numbers**; the inability is due to a limitation in the `printf()` function implementation for the device, as [documented here](https://github.com/esp8266/Arduino/issues/73).
