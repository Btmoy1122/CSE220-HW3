#include <stdio.h>
#include "MyBitManipulation.h"
#include "Myfloat.h"
#include "MyIntegers.h"
//Brandon Moy 116187802
int main(void) {

   /* PART 1: Bit Manipulation Tests */
   printf("ToggleBit(9, 0) = %d\n", ToggleBit(9, 0));
   printf("ToggleBit(9, 3) = %d\n", ToggleBit(9, 3));
   printf("ToggleBit(15, 3) = %d\n", ToggleBit(15, 3));

   printf("GetMSB(18) = %d\n", GetMSB(18));
   printf("GetMSB(0) = %d\n", GetMSB(0));
   printf("GetMSB(31) = %d\n", GetMSB(31));
   printf("GetMSB(1000) = %d\n", GetMSB(1000));
   
   printf("ClearBitRange(73, 1, 3) = %d\n", ClearBitRange(73, 1, 3));
   printf("ClearBitRange(1500, 2, 7) = %d\n", ClearBitRange(1500, 2, 7));
   printf("ClearBitRange(555, 1, 5) = %d\n", ClearBitRange(555, 1, 5));
   printf("ClearBitRange(10, 5, 2) = %d\n", ClearBitRange(10, 5, 2));
   
   printf("RotateLeft(5, 1) = %d\n", RotateLeft(5, 1));
   printf("RotateLeft(5, 2) = %d\n", RotateLeft(5, 2));
   printf("RotateLeft(5, 3) = %d\n", RotateLeft(5, 3));
   
   printf("SwapOddEvenBits(23) = %d\n", SwapOddEvenBits(23));
   printf("SwapOddEvenBits(0) = %d\n", SwapOddEvenBits(0));
   printf("SwapOddEvenBits(1) = %d\n", SwapOddEvenBits(1));
   

   /* PART 2: Float Construction */
   float f = construct_float_sf(0x00, 0x7F, 0x200000);
   printf("Float value = %g\n", f);
   printf("Float (0.002588)  = %g\n", construct_float_sf(0x00, 0x76, 0x299B6F));   
   printf("Float (-0.002588) = %g\n", construct_float_sf(0x01, 0x76, 0x299B6F));
   printf("Float (1374.44)   = %g\n", construct_float_sf(0x00, 0x89, 0xABCDEF));

   
   /* PART 3: Integer Representation Conversion */
   repr_convert('2', '2', 0x59f2ca50);
   repr_convert('Z', '2', 0x00000005);
   repr_convert('2', 'Z', 0x00000005);
   repr_convert('2', 'S', 0x80000000);
   repr_convert('S', '2', 0x80000000);
   repr_convert('S', 'S', 0x80000000);
   repr_convert('S', '2', 0x80000001);
   repr_convert('2', 'S', 0xFFFFFFFF);
   repr_convert('2', 'S', 0x00000005);
   repr_convert('F', '2', 0x00394812);
   repr_convert('S', '2', 0x00394812);

   return 0;
}
