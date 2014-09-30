#ifndef __SERIAL_DEBUG__
#define __SERIAL_DEBUG__

    #if (defined ARDUINO && (!defined(SERIAL_DEBUG) || SERIAL_DEBUG))
        #include<stdio.h>

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
 * a, A	double in hexadecimal notation, starting with "0x" or "0X". 'a' uses lower-case letters, 'A' uses upper-case letters.
 * n	Print nothing, but write number of characters successfully written so far into an integer pointer parameter.
 * %	a literal '%' character (this type doesn't accept any flags, width, precision or length).
 */
		#ifndef SERIAL_DEBUG_IMPL
            #define SERIAL_DEBUG_IMPL Serial
        #endif
		int _serialDebug(char c, FILE *) { SERIAL_DEBUG_IMPL.write(c); return c; }

		#define SERIAL_DEBUG_SETUP(speed) SERIAL_DEBUG_IMPL.begin(speed);fdevopen( &_serialDebug, 0 )

        #define DEBUG(format, ...)  printf(format "\r\n", ##__VA_ARGS__)

    #else
        #define DEBUG(format, ...)
        #define SERIAL_DEBUG_SETUP(speed)
    #endif // SERIAL_DEBUG
#endif //__SERIAL_DEBUG__
