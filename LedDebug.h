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
