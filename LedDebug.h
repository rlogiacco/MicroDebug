/*
 LedDebug.h - MicroDebug library
 Copyright (c) 2014 Roberto Lo Giacco.  All right reserved.

 This library is free software; you can redistribute it and/or
 modify it under the terms of the GNU Lesser General Public
 License as published by the Free Software Foundation; either
 version 2.1 of the License, or (at your option) any later version.

 This library is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 Lesser General Public License for more details.

 You should have received a copy of the GNU Lesser General Public
 License along with this library; if not, write to the Free Software
 Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
 */

#ifndef __LED_DEBUG__
#define __LED_DEBUG__

    #if (!defined(LED_DEBUG) || LED_DEBUG)

        #ifndef LED_DEBUG_PIN
            #define LED_DEBUG_PIN 		LED_BUILTIN
        #endif

        #ifndef LED_DEBUG_DELAY
            #define LED_DEBUG_DELAY 	50
        #endif

        #ifndef LED_DEBUG_LENGHT
            #define LED_DEBUG_LENGHT 	125
        #endif

        #define __PULSE_LNG(NUM, LENGHT)  for(int __led_debug_count = 0; __led_debug_count < NUM; __led_debug_count++) {\
                                            digitalWrite(LED_DEBUG_PIN, HIGH);\
                                            delay(LENGHT);\
                                            digitalWrite(LED_DEBUG_PIN, LOW);\
                                            delay(LENGHT);\
                                          }\
                                          delay(LED_DEBUG_DELAY)
        
        #define __PULSE_DEF(NUM)          __PULSE_LNG(NUM, LED_DEBUG_LENGHT)
        
        #define __PULSE_ONE()             digitalWrite(LED_DEBUG_PIN, HIGH);\
                                          delay(LED_DEBUG_LENGHT);\
                                          digitalWrite(LED_DEBUG_PIN, LOW);\
                                          delay(LED_DEBUG_LENGHT);\
                                          delay(LED_DEBUG_DELAY)

        #define __PULSE_X(x,NUM,LENGHT,MACRO, ...) pinMode(LED_DEBUG_PIN, OUTPUT);MACRO

        #define PULSE(...)                __PULSE_X(,##__VA_ARGS__,\
                                            __PULSE_LNG(__VA_ARGS__),\
                                            __PULSE_DEF(__VA_ARGS__),\
                                            __PULSE_ONE(__VA_ARGS__)\
                                          )
    #else
        #define PULSE(...)
    #endif
#endif // __LED_DEBUG__
