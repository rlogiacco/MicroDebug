/*
 SerialDebug.h - MicroDebug library
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

#ifndef SERIAL_DEBUG_H_
#define SERIAL_DEBUG_H_

    #if (!defined(SERIAL_DEBUG) || SERIAL_DEBUG)

        #ifndef SERIAL_DEBUG_IMPL
            #define SERIAL_DEBUG_IMPL         Serial
        #endif

        #ifndef SERIAL_DEBUG_SEPARATOR
            #define SERIAL_DEBUG_SEPARATOR    " | "
        #endif

        #define SERIAL_DEBUG_SETUP(speed)     SERIAL_DEBUG_IMPL.begin(speed)

        #define DEBUG_0_(A)                  SERIAL_DEBUG_IMPL.println(A)

        #define DEBUG_1_(A,B)                SERIAL_DEBUG_IMPL.print(A);SERIAL_DEBUG_IMPL.print(SERIAL_DEBUG_SEPARATOR);\
                                              SERIAL_DEBUG_IMPL.println(B)

        #define DEBUG_2_(A,B,C)              SERIAL_DEBUG_IMPL.print(A);SERIAL_DEBUG_IMPL.print(SERIAL_DEBUG_SEPARATOR);\
                                              SERIAL_DEBUG_IMPL.print(B);SERIAL_DEBUG_IMPL.print(SERIAL_DEBUG_SEPARATOR);\
                                              SERIAL_DEBUG_IMPL.println(C)

        #define DEBUG_3_(A,B,C,D)            SERIAL_DEBUG_IMPL.print(A);SERIAL_DEBUG_IMPL.print(SERIAL_DEBUG_SEPARATOR);\
                                              SERIAL_DEBUG_IMPL.print(B);SERIAL_DEBUG_IMPL.print(SERIAL_DEBUG_SEPARATOR);\
                                              SERIAL_DEBUG_IMPL.print(C);SERIAL_DEBUG_IMPL.print(SERIAL_DEBUG_SEPARATOR);\
                                              SERIAL_DEBUG_IMPL.println(D)

        #define DEBUG_4_(A,B,C,D,E)          SERIAL_DEBUG_IMPL.print(A);SERIAL_DEBUG_IMPL.print(SERIAL_DEBUG_SEPARATOR);\
                                              SERIAL_DEBUG_IMPL.print(B);SERIAL_DEBUG_IMPL.print(SERIAL_DEBUG_SEPARATOR);\
                                              SERIAL_DEBUG_IMPL.print(C);SERIAL_DEBUG_IMPL.print(SERIAL_DEBUG_SEPARATOR);\
                                              SERIAL_DEBUG_IMPL.print(D);SERIAL_DEBUG_IMPL.print(SERIAL_DEBUG_SEPARATOR);\
                                              SERIAL_DEBUG_IMPL.println(E)

        #define DEBUG_5_(A,B,C,D,E,F)        SERIAL_DEBUG_IMPL.print(A);SERIAL_DEBUG_IMPL.print(SERIAL_DEBUG_SEPARATOR);\
                                              SERIAL_DEBUG_IMPL.print(B);SERIAL_DEBUG_IMPL.print(SERIAL_DEBUG_SEPARATOR);\
                                              SERIAL_DEBUG_IMPL.print(C);SERIAL_DEBUG_IMPL.print(SERIAL_DEBUG_SEPARATOR);\
                                              SERIAL_DEBUG_IMPL.print(D);SERIAL_DEBUG_IMPL.print(SERIAL_DEBUG_SEPARATOR);\
                                              SERIAL_DEBUG_IMPL.print(E);SERIAL_DEBUG_IMPL.print(SERIAL_DEBUG_SEPARATOR);\
                                              SERIAL_DEBUG_IMPL.println(F)

        #define DEBUG_6_(A,B,C,D,E,F,G)      SERIAL_DEBUG_IMPL.print(A);SERIAL_DEBUG_IMPL.print(SERIAL_DEBUG_SEPARATOR);\
                                              SERIAL_DEBUG_IMPL.print(B);SERIAL_DEBUG_IMPL.print(SERIAL_DEBUG_SEPARATOR);\
                                              SERIAL_DEBUG_IMPL.print(C);SERIAL_DEBUG_IMPL.print(SERIAL_DEBUG_SEPARATOR);\
                                              SERIAL_DEBUG_IMPL.print(D);SERIAL_DEBUG_IMPL.print(SERIAL_DEBUG_SEPARATOR);\
                                              SERIAL_DEBUG_IMPL.print(E);SERIAL_DEBUG_IMPL.print(SERIAL_DEBUG_SEPARATOR);\
                                              SERIAL_DEBUG_IMPL.print(F);SERIAL_DEBUG_IMPL.print(SERIAL_DEBUG_SEPARATOR);\
                                              SERIAL_DEBUG_IMPL.println(G)

        #define DEBUG_7_(A,B,C,D,E,F,G,H)    SERIAL_DEBUG_IMPL.print(A);SERIAL_DEBUG_IMPL.print(SERIAL_DEBUG_SEPARATOR);\
                                              SERIAL_DEBUG_IMPL.print(B);SERIAL_DEBUG_IMPL.print(SERIAL_DEBUG_SEPARATOR);\
                                              SERIAL_DEBUG_IMPL.print(C);SERIAL_DEBUG_IMPL.print(SERIAL_DEBUG_SEPARATOR);\
                                              SERIAL_DEBUG_IMPL.print(D);SERIAL_DEBUG_IMPL.print(SERIAL_DEBUG_SEPARATOR);\
                                              SERIAL_DEBUG_IMPL.print(E);SERIAL_DEBUG_IMPL.print(SERIAL_DEBUG_SEPARATOR);\
                                              SERIAL_DEBUG_IMPL.print(F);SERIAL_DEBUG_IMPL.print(SERIAL_DEBUG_SEPARATOR);\
                                              SERIAL_DEBUG_IMPL.print(G);SERIAL_DEBUG_IMPL.print(SERIAL_DEBUG_SEPARATOR);\
                                              SERIAL_DEBUG_IMPL.println(H)

        #define DEBUG_8_(A,B,C,D,E,F,G,H,I)  SERIAL_DEBUG_IMPL.print(A);SERIAL_DEBUG_IMPL.print(SERIAL_DEBUG_SEPARATOR);\
                                              SERIAL_DEBUG_IMPL.print(B);SERIAL_DEBUG_IMPL.print(SERIAL_DEBUG_SEPARATOR);\
                                              SERIAL_DEBUG_IMPL.print(C);SERIAL_DEBUG_IMPL.print(SERIAL_DEBUG_SEPARATOR);\
                                              SERIAL_DEBUG_IMPL.print(D);SERIAL_DEBUG_IMPL.print(SERIAL_DEBUG_SEPARATOR);\
                                              SERIAL_DEBUG_IMPL.print(E);SERIAL_DEBUG_IMPL.print(SERIAL_DEBUG_SEPARATOR);\
                                              SERIAL_DEBUG_IMPL.print(F);SERIAL_DEBUG_IMPL.print(SERIAL_DEBUG_SEPARATOR);\
                                              SERIAL_DEBUG_IMPL.print(G);SERIAL_DEBUG_IMPL.print(SERIAL_DEBUG_SEPARATOR);\
                                              SERIAL_DEBUG_IMPL.print(H);SERIAL_DEBUG_IMPL.print(SERIAL_DEBUG_SEPARATOR);\
                                              SERIAL_DEBUG_IMPL.println(I)

        #define DEBUG_9_(A,B,C,D,E,F,G,H,I,J)  SERIAL_DEBUG_IMPL.print(A);SERIAL_DEBUG_IMPL.print(SERIAL_DEBUG_SEPARATOR);\
                                              SERIAL_DEBUG_IMPL.print(B);SERIAL_DEBUG_IMPL.print(SERIAL_DEBUG_SEPARATOR);\
                                              SERIAL_DEBUG_IMPL.print(C);SERIAL_DEBUG_IMPL.print(SERIAL_DEBUG_SEPARATOR);\
                                              SERIAL_DEBUG_IMPL.print(D);SERIAL_DEBUG_IMPL.print(SERIAL_DEBUG_SEPARATOR);\
                                              SERIAL_DEBUG_IMPL.print(E);SERIAL_DEBUG_IMPL.print(SERIAL_DEBUG_SEPARATOR);\
                                              SERIAL_DEBUG_IMPL.print(F);SERIAL_DEBUG_IMPL.print(SERIAL_DEBUG_SEPARATOR);\
                                              SERIAL_DEBUG_IMPL.print(G);SERIAL_DEBUG_IMPL.print(SERIAL_DEBUG_SEPARATOR);\
                                              SERIAL_DEBUG_IMPL.print(H);SERIAL_DEBUG_IMPL.print(SERIAL_DEBUG_SEPARATOR);\
                                              SERIAL_DEBUG_IMPL.print(I);SERIAL_DEBUG_IMPL.print(SERIAL_DEBUG_SEPARATOR);\
                                              SERIAL_DEBUG_IMPL.println(J)

        #define DEBUG_X_(x,A,B,C,D,E,F,G,H,I,J,MACRO, ...) MACRO

        #define DEBUG(...)           DEBUG_X_(, ##__VA_ARGS__,\
                                                DEBUG_9_(__VA_ARGS__),\
                                                DEBUG_8_(__VA_ARGS__),\
                                                DEBUG_7_(__VA_ARGS__),\
                                                DEBUG_6_(__VA_ARGS__),\
                                                DEBUG_5_(__VA_ARGS__),\
                                                DEBUG_4_(__VA_ARGS__),\
                                                DEBUG_3_(__VA_ARGS__),\
                                                DEBUG_2_(__VA_ARGS__),\
                                                DEBUG_1_(__VA_ARGS__),\
                                                DEBUG_0_(__VA_ARGS__)\
                                            )

    #else
        #define DEBUG(...)
        #define SERIAL_DEBUG_SETUP(speed)
    #endif // SERIAL_DEBUG
#endif // SERIAL_DEBUG_H_
