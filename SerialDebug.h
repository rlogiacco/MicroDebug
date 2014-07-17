#ifndef __SERIAL_DEBUG__
#define __SERIAL_DEBUG__

    #if (!defined(SERIAL_DEBUG) || SERIAL_DEBUG)

        #ifndef SERIAL_DEBUG_SEPARATOR
            #define SERIAL_DEBUG_SEPARATOR " | "
        #endif

        #define SERIAL_DEBUG_SETUP(speed)     Serial.begin(speed)

        #define __DEBUG_0()                   Serial.println("### SerialDebug ###")

        #define __DEBUG_1(A)                  Serial.println(A)

        #define __DEBUG_2(A,B)                Serial.print(A);Serial.print(SERIAL_DEBUG_SEPARATOR);\
                                              Serial.println(B)

        #define __DEBUG_3(A,B,C)              Serial.print(A);Serial.print(SERIAL_DEBUG_SEPARATOR);\
                                              Serial.print(B);Serial.print(SERIAL_DEBUG_SEPARATOR);\
                                              Serial.println(C)

        #define __DEBUG_4(A,B,C,D)            Serial.print(A);Serial.print(SERIAL_DEBUG_SEPARATOR);\
                                              Serial.print(B);Serial.print(SERIAL_DEBUG_SEPARATOR);\
                                              Serial.print(C);Serial.print(SERIAL_DEBUG_SEPARATOR);\
                                              Serial.println(D)

        #define __DEBUG_5(A,B,C,D,E)          Serial.print(A);Serial.print(SERIAL_DEBUG_SEPARATOR);\
                                              Serial.print(B);Serial.print(SERIAL_DEBUG_SEPARATOR);\
                                              Serial.print(C);Serial.print(SERIAL_DEBUG_SEPARATOR);\
                                              Serial.print(D);Serial.print(SERIAL_DEBUG_SEPARATOR);\
                                              Serial.println(E)

        #define __DEBUG_6(A,B,C,D,E,F)        Serial.print(A);Serial.print(SERIAL_DEBUG_SEPARATOR);\
                                              Serial.print(B);Serial.print(SERIAL_DEBUG_SEPARATOR);\
                                              Serial.print(C);Serial.print(SERIAL_DEBUG_SEPARATOR);\
                                              Serial.print(D);Serial.print(SERIAL_DEBUG_SEPARATOR);\
                                              Serial.print(E);Serial.print(SERIAL_DEBUG_SEPARATOR);\
                                              Serial.println(F)

        #define __DEBUG_7(A,B,C,D,E,F,G)      Serial.print(A);Serial.print(SERIAL_DEBUG_SEPARATOR);\
                                              Serial.print(B);Serial.print(SERIAL_DEBUG_SEPARATOR);\
                                              Serial.print(C);Serial.print(SERIAL_DEBUG_SEPARATOR);\
                                              Serial.print(D);Serial.print(SERIAL_DEBUG_SEPARATOR);\
                                              Serial.print(E);Serial.print(SERIAL_DEBUG_SEPARATOR);\
                                              Serial.print(F);Serial.print(SERIAL_DEBUG_SEPARATOR);\
                                              Serial.println(G)

        #define __DEBUG_8(A,B,C,D,E,F,G,H)    Serial.print(A);Serial.print(SERIAL_DEBUG_SEPARATOR);\
                                              Serial.print(B);Serial.print(SERIAL_DEBUG_SEPARATOR);\
                                              Serial.print(C);Serial.print(SERIAL_DEBUG_SEPARATOR);\
                                              Serial.print(D);Serial.print(SERIAL_DEBUG_SEPARATOR);\
                                              Serial.print(E);Serial.print(SERIAL_DEBUG_SEPARATOR);\
                                              Serial.print(F);Serial.print(SERIAL_DEBUG_SEPARATOR);\
                                              Serial.print(G);Serial.print(SERIAL_DEBUG_SEPARATOR);\
                                              Serial.println(H)

        #define __DEBUG_9(A,B,C,D,E,F,G,H,I)  Serial.print(A);Serial.print(SERIAL_DEBUG_SEPARATOR);\
                                              Serial.print(B);Serial.print(SERIAL_DEBUG_SEPARATOR);\
                                              Serial.print(C);Serial.print(SERIAL_DEBUG_SEPARATOR);\
                                              Serial.print(D);Serial.print(SERIAL_DEBUG_SEPARATOR);\
                                              Serial.print(E);Serial.print(SERIAL_DEBUG_SEPARATOR);\
                                              Serial.print(F);Serial.print(SERIAL_DEBUG_SEPARATOR);\
                                              Serial.print(G);Serial.print(SERIAL_DEBUG_SEPARATOR);\
                                              Serial.print(H);Serial.print(SERIAL_DEBUG_SEPARATOR);\
                                              Serial.println(I)

        #define __DEBUG_X(x,A,B,C,D,E,F,G,H,I,MACRO, ...) MACRO

        #define DEBUG(...)                  __DEBUG_X(,##__VA_ARGS__,\
                                                __DEBUG_9(__VA_ARGS__),\
                                                __DEBUG_8(__VA_ARGS__),\
                                                __DEBUG_7(__VA_ARGS__),\
                                                __DEBUG_6(__VA_ARGS__),\
                                                __DEBUG_5(__VA_ARGS__),\
                                                __DEBUG_4(__VA_ARGS__),\
                                                __DEBUG_3(__VA_ARGS__),\
                                                __DEBUG_2(__VA_ARGS__),\
                                                __DEBUG_1(__VA_ARGS__),\
                                                __DEBUG_0(__VA_ARGS__)\
                                            )

    #else
        #define DEBUG(...)
        #define SERIAL_DEBUG_SETUP(speed)
    #endif // SERIAL_DEBUG
#endif //__SERIAL_DEBUG__
