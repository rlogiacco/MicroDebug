/*
 LedDebug.h - MicroDebug library
 Copyright (c) 2014 Roberto Lo Giacco.

 This program is free software: you can redistribute it and/or modify
 it under the terms of the GNU Lesser General Public License as 
 published by the Free Software Foundation, either version 3 of the 
 License, or (at your option) any later version.

 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.

 You should have received a copy of the GNU General Public License
 along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef LED_DEBUG_H_
#define LED_DEBUG_H_

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

        #define PULSE_LNG_(NUM, LENGHT)  for(int __led_debug_count = 0; __led_debug_count < NUM; __led_debug_count++) {\
                                            digitalWrite(LED_DEBUG_PIN, HIGH);\
                                            delay(LENGHT);\
                                            digitalWrite(LED_DEBUG_PIN, LOW);\
                                            delay(LENGHT);\
                                          }\
                                          delay(LED_DEBUG_DELAY)
        
        #define PULSE_DEF_(NUM)          PULSE_LNG_(NUM, LED_DEBUG_LENGHT)
        
        #define PULSE_ONE_()             digitalWrite(LED_DEBUG_PIN, HIGH);\
                                          delay(LED_DEBUG_LENGHT);\
                                          digitalWrite(LED_DEBUG_PIN, LOW);\
                                          delay(LED_DEBUG_LENGHT);\
                                          delay(LED_DEBUG_DELAY)

        #define PULSE_X_(x,NUM,LENGHT,MACRO, ...) pinMode(LED_DEBUG_PIN, OUTPUT);MACRO

        #define PULSE(...)                PULSE_X_(,##__VA_ARGS__,\
                                            PULSE_LNG_(__VA_ARGS__),\
                                            PULSE_DEF_(__VA_ARGS__),\
                                            PULSE_ONE_(__VA_ARGS__)\
                                          )
    #else
        #define PULSE(...)
    #endif
#endif // LED_DEBUG_H_
