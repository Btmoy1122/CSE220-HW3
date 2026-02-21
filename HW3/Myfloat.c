#include "Myfloat.h"
#include <stdio.h>
//Brandon Moy 116187802
float construct_float_sf(char sign_bit, char exponent, unsigned int fraction) {
   unsigned int f = 0;

   /*
    * Start coding here
    * Use bitwise operations to construct the IEEE 754 float
    */


    //We shift the sign bit to position 31
    unsigned int s = (unsigned int)(sign_bit & 1) << 31;

    //We shift the exponent bits to 30-23 and make sure we only take the 8 bits
    unsigned int e = (exponent & 0xFF) << 23;

    //We dont need to shift the fraction bits but we just make sure we take only the first 23 bits
    unsigned int frac = (fraction & 0x7FFFFF);

    f = s | e | frac;


   return *(float *)&f;
}

/* Test Cases for Part 2
   printf("Float (5.5): Expected 5.5, Actual %g\n", construct_float_sf(0x00, 0x81, 0x300000));
   printf("Float (1.25): Expected 1.25, Actual %g\n", construct_float_sf(0x00, 0x7F, 0x200000));
   printf("Float (1374.44): Expected 1374.44, Actual %g\n", construct_float_sf(0x00, 0x89, 0xABCDEF));
   
 */