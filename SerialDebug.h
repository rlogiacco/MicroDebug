/*
 SerialDebug.h - MicroDebug library
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

#ifndef __SERIAL_DEBUG__
#define __SERIAL_DEBUG__

    #define FREE_RAM (uint16_t)(RAMEND - size_t (__malloc_heap_start))

    #if (!defined(SERIAL_DEBUG) || SERIAL_DEBUG)

        #ifndef SERIAL_DEBUG_IMPL
            #define SERIAL_DEBUG_IMPL         Serial
        #endif

        #ifndef SERIAL_DEBUG_SEPARATOR
            #define SERIAL_DEBUG_SEPARATOR    " | "
        #endif

        #define SERIAL_DEBUG_SETUP(speed)     SERIAL_DEBUG_IMPL.begin(speed)

        #define __DEBUG_0(A)                  SERIAL_DEBUG_IMPL.println(A)

        #define __DEBUG_1(A,B)                SERIAL_DEBUG_IMPL.print(A);SERIAL_DEBUG_IMPL.print(SERIAL_DEBUG_SEPARATOR);\
                                              SERIAL_DEBUG_IMPL.println(B)

        #define __DEBUG_2(A,B,C)              SERIAL_DEBUG_IMPL.print(A);SERIAL_DEBUG_IMPL.print(SERIAL_DEBUG_SEPARATOR);\
                                              SERIAL_DEBUG_IMPL.print(B);SERIAL_DEBUG_IMPL.print(SERIAL_DEBUG_SEPARATOR);\
                                              SERIAL_DEBUG_IMPL.println(C)

        #define __DEBUG_3(A,B,C,D)            SERIAL_DEBUG_IMPL.print(A);SERIAL_DEBUG_IMPL.print(SERIAL_DEBUG_SEPARATOR);\
                                              SERIAL_DEBUG_IMPL.print(B);SERIAL_DEBUG_IMPL.print(SERIAL_DEBUG_SEPARATOR);\
                                              SERIAL_DEBUG_IMPL.print(C);SERIAL_DEBUG_IMPL.print(SERIAL_DEBUG_SEPARATOR);\
                                              SERIAL_DEBUG_IMPL.println(D)

        #define __DEBUG_4(A,B,C,D,E)          SERIAL_DEBUG_IMPL.print(A);SERIAL_DEBUG_IMPL.print(SERIAL_DEBUG_SEPARATOR);\
                                              SERIAL_DEBUG_IMPL.print(B);SERIAL_DEBUG_IMPL.print(SERIAL_DEBUG_SEPARATOR);\
                                              SERIAL_DEBUG_IMPL.print(C);SERIAL_DEBUG_IMPL.print(SERIAL_DEBUG_SEPARATOR);\
                                              SERIAL_DEBUG_IMPL.print(D);SERIAL_DEBUG_IMPL.print(SERIAL_DEBUG_SEPARATOR);\
                                              SERIAL_DEBUG_IMPL.println(E)

        #define __DEBUG_5(A,B,C,D,E,F)        SERIAL_DEBUG_IMPL.print(A);SERIAL_DEBUG_IMPL.print(SERIAL_DEBUG_SEPARATOR);\
                                              SERIAL_DEBUG_IMPL.print(B);SERIAL_DEBUG_IMPL.print(SERIAL_DEBUG_SEPARATOR);\
                                              SERIAL_DEBUG_IMPL.print(C);SERIAL_DEBUG_IMPL.print(SERIAL_DEBUG_SEPARATOR);\
                                              SERIAL_DEBUG_IMPL.print(D);SERIAL_DEBUG_IMPL.print(SERIAL_DEBUG_SEPARATOR);\
                                              SERIAL_DEBUG_IMPL.print(E);SERIAL_DEBUG_IMPL.print(SERIAL_DEBUG_SEPARATOR);\
                                              SERIAL_DEBUG_IMPL.println(F)

        #define __DEBUG_6(A,B,C,D,E,F,G)      SERIAL_DEBUG_IMPL.print(A);SERIAL_DEBUG_IMPL.print(SERIAL_DEBUG_SEPARATOR);\
                                              SERIAL_DEBUG_IMPL.print(B);SERIAL_DEBUG_IMPL.print(SERIAL_DEBUG_SEPARATOR);\
                                              SERIAL_DEBUG_IMPL.print(C);SERIAL_DEBUG_IMPL.print(SERIAL_DEBUG_SEPARATOR);\
                                              SERIAL_DEBUG_IMPL.print(D);SERIAL_DEBUG_IMPL.print(SERIAL_DEBUG_SEPARATOR);\
                                              SERIAL_DEBUG_IMPL.print(E);SERIAL_DEBUG_IMPL.print(SERIAL_DEBUG_SEPARATOR);\
                                              SERIAL_DEBUG_IMPL.print(F);SERIAL_DEBUG_IMPL.print(SERIAL_DEBUG_SEPARATOR);\
                                              SERIAL_DEBUG_IMPL.println(G)

        #define __DEBUG_7(A,B,C,D,E,F,G,H)    SERIAL_DEBUG_IMPL.print(A);SERIAL_DEBUG_IMPL.print(SERIAL_DEBUG_SEPARATOR);\
                                              SERIAL_DEBUG_IMPL.print(B);SERIAL_DEBUG_IMPL.print(SERIAL_DEBUG_SEPARATOR);\
                                              SERIAL_DEBUG_IMPL.print(C);SERIAL_DEBUG_IMPL.print(SERIAL_DEBUG_SEPARATOR);\
                                              SERIAL_DEBUG_IMPL.print(D);SERIAL_DEBUG_IMPL.print(SERIAL_DEBUG_SEPARATOR);\
                                              SERIAL_DEBUG_IMPL.print(E);SERIAL_DEBUG_IMPL.print(SERIAL_DEBUG_SEPARATOR);\
                                              SERIAL_DEBUG_IMPL.print(F);SERIAL_DEBUG_IMPL.print(SERIAL_DEBUG_SEPARATOR);\
                                              SERIAL_DEBUG_IMPL.print(G);SERIAL_DEBUG_IMPL.print(SERIAL_DEBUG_SEPARATOR);\
                                              SERIAL_DEBUG_IMPL.println(H)

        #define __DEBUG_8(A,B,C,D,E,F,G,H,I)  SERIAL_DEBUG_IMPL.print(A);SERIAL_DEBUG_IMPL.print(SERIAL_DEBUG_SEPARATOR);\
                                              SERIAL_DEBUG_IMPL.print(B);SERIAL_DEBUG_IMPL.print(SERIAL_DEBUG_SEPARATOR);\
                                              SERIAL_DEBUG_IMPL.print(C);SERIAL_DEBUG_IMPL.print(SERIAL_DEBUG_SEPARATOR);\
                                              SERIAL_DEBUG_IMPL.print(D);SERIAL_DEBUG_IMPL.print(SERIAL_DEBUG_SEPARATOR);\
                                              SERIAL_DEBUG_IMPL.print(E);SERIAL_DEBUG_IMPL.print(SERIAL_DEBUG_SEPARATOR);\
                                              SERIAL_DEBUG_IMPL.print(F);SERIAL_DEBUG_IMPL.print(SERIAL_DEBUG_SEPARATOR);\
                                              SERIAL_DEBUG_IMPL.print(G);SERIAL_DEBUG_IMPL.print(SERIAL_DEBUG_SEPARATOR);\
                                              SERIAL_DEBUG_IMPL.print(H);SERIAL_DEBUG_IMPL.print(SERIAL_DEBUG_SEPARATOR);\
                                              SERIAL_DEBUG_IMPL.println(I)

        #define __DEBUG_9(A,B,C,D,E,F,G,H,I,J)  SERIAL_DEBUG_IMPL.print(A);SERIAL_DEBUG_IMPL.print(SERIAL_DEBUG_SEPARATOR);\
                                              SERIAL_DEBUG_IMPL.print(B);SERIAL_DEBUG_IMPL.print(SERIAL_DEBUG_SEPARATOR);\
                                              SERIAL_DEBUG_IMPL.print(C);SERIAL_DEBUG_IMPL.print(SERIAL_DEBUG_SEPARATOR);\
                                              SERIAL_DEBUG_IMPL.print(D);SERIAL_DEBUG_IMPL.print(SERIAL_DEBUG_SEPARATOR);\
                                              SERIAL_DEBUG_IMPL.print(E);SERIAL_DEBUG_IMPL.print(SERIAL_DEBUG_SEPARATOR);\
                                              SERIAL_DEBUG_IMPL.print(F);SERIAL_DEBUG_IMPL.print(SERIAL_DEBUG_SEPARATOR);\
                                              SERIAL_DEBUG_IMPL.print(G);SERIAL_DEBUG_IMPL.print(SERIAL_DEBUG_SEPARATOR);\
                                              SERIAL_DEBUG_IMPL.print(H);SERIAL_DEBUG_IMPL.print(SERIAL_DEBUG_SEPARATOR);\
                                              SERIAL_DEBUG_IMPL.print(I);SERIAL_DEBUG_IMPL.print(SERIAL_DEBUG_SEPARATOR);\
                                              SERIAL_DEBUG_IMPL.println(J)

        #define __DEBUG_X(x,A,B,C,D,E,F,G,H,I,J,MACRO, ...) MACRO

        #define DEBUG(...)           __DEBUG_X(, ##__VA_ARGS__,\
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
