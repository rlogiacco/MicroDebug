#ifndef __SERIAL_DEBUG__
#define __SERIAL_DEBUG__

    #if (defined ARDUINO && (!defined(SERIAL_DEBUG) || SERIAL_DEBUG))

/*
 * d, i	int as a signed decimal number. '%d' and '%i' are synonymous for output, but are different when used with scanf() for input (where using %i will interpret a number as hexadecimal if it's preceded by 0x, and octal if it's preceded by 0.)
 * u	Print decimal unsigned int.
 * f, F	double in normal (fixed-point) notation. 'f' and 'F' only differs in how the strings for an infinite number or NaN are printed ('inf', 'infinity' and 'nan' for 'f', 'INF', 'INFINITY' and 'NAN' for 'F').
 * e, E	double value in standard form ([-]d.ddd e[+/-]ddd). An E conversion uses the letter E (rather than e) to introduce the exponent. The exponent always contains at least two digits; if the value is zero, the exponent is 00. In Windows, the exponent contains three digits by default, e.g. 1.5e002, but this can be altered by Microsoft-specific _set_output_format function.
 * g, G	double in either normal or exponential notation, whichever is more appropriate for its magnitude. 'g' uses lower-case letters, 'G' uses upper-case letters. This type differs slightly from fixed-point notation in that insignificant zeroes to the right of the decimal point are not included. Also, the decimal point is not included on whole numbers.
 * x, X	unsigned int as a hexadecimal number. 'x' uses lower-case letters and 'X' uses upper-case.
 * o	unsigned int in octal.
 * s	null-terminated string.
 * c	char (character).
 * p	void * (pointer to void) in an implementation-defined format.
 * a, A	double in hexadecimal notation, starting with "0x" or "0X". 'a' uses lower-case letters, 'A' uses upper-case letters.[7][8] (C++11 iostreams have a hexfloat that works the same).
 * n	Print nothing, but write number of characters successfully written so far into an integer pointer parameter.
 * %	a literal '%' character (this type doesn't accept any flags, width, precision or length).
 */
		#ifndef SERIAL_DEBUG_IMPL
            #define SERIAL_DEBUG_IMPL Serial
        #endif
#include<stdio.h>
		int serial_putc(char c, FILE *) { SERIAL_DEBUG_IMPL.write(c); return c; }

		#define SERIAL_DEBUG_SETUP(speed) SERIAL_DEBUG_IMPL.begin(speed);fdevopen( &serial_putc, 0 )

        #define __DEBUG_() printf("### SerialDebug ###")
        #define __DEBUG_0(A)  printf(A)
        #define __DEBUG_1(A,B)  printf(A,B)
        #define __DEBUG_2(A,B,C)  printf(A,B,C)
        #define __DEBUG_3(A,B,C,D)  printf(A,B,C,D)
        #define __DEBUG_4(A,B,C,D,E)  printf(A,B,C,D,E)
        #define __DEBUG_5(A,B,C,D,E,F)  printf(A,B,C,D,E,F)
        #define __DEBUG_6(A,B,C,D,E,F,G)  printf(A,B,C,D,E,F,G)
        #define __DEBUG_7(A,B,C,D,E,F,G,H)  printf(A,B,C,D,E,F,G,H)
        #define __DEBUG_8(A,B,C,D,E,F,G,H,I)  printf(A,B,C,D,E,F,G,H,I)

        #define __DEBUG_X(x,A,B,C,D,E,F,G,H,I,MACRO, ...) MACRO;printf("\r\n")

        #define DEBUG(...)          __DEBUG_X(,##__VA_ARGS__,\
										__DEBUG_8(__VA_ARGS__),__DEBUG_7(__VA_ARGS__),\
										__DEBUG_6(__VA_ARGS__),__DEBUG_5(__VA_ARGS__),__DEBUG_4(__VA_ARGS__),\
										__DEBUG_3(__VA_ARGS__),__DEBUG_2(__VA_ARGS__),__DEBUG_1(__VA_ARGS__),\
										__DEBUG_0(__VA_ARGS__),__DEBUG_(__VA_ARGS__)\
									)

    #else
        #define DEBUG(...)
        #define SERIAL_DEBUG_SETUP(speed)
    #endif // SERIAL_DEBUG
#endif //__SERIAL_DEBUG__
