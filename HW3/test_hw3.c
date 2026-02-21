#include <criterion/criterion.h>
#include "MyBitManipulation.h"
#include "Myfloat.h"
#include "MyIntegers.h"
//Brandon Moy 116187802

/* =========================
* PART 1: Bit Manipulation
* ========================= */

Test(ToggleBit, examples) {
   cr_assert_eq(ToggleBit(9, 0), 8);
   cr_assert_eq(ToggleBit(9, 3), 1);
   cr_assert_eq(ToggleBit(15, 3), 7);
   cr_assert_eq(ToggleBit(0, 15), 32768);
   cr_assert_eq(ToggleBit(0xFFFFFFFF, 31), 0x7FFFFFFF);
}

Test(GetMSB, examples) {
   cr_assert_eq(GetMSB(18), 4);
   cr_assert_eq(GetMSB(0), -1);
   cr_assert_eq(GetMSB(31), 4);
   cr_assert_eq(GetMSB(1000), 9);
   cr_assert_eq(GetMSB(64), 6);
}

Test(ClearBitRange, examples) {
   cr_assert_eq(ClearBitRange(73, 1, 3), 65);
   cr_assert_eq(ClearBitRange(1500, 2, 7), 1280);
   cr_assert_eq(ClearBitRange(555, 1, 5), 513);
   cr_assert_eq(ClearBitRange(10, 5, 2), 10);
   cr_assert_eq(ClearBitRange(0xF, 2, 2), 11);
}

Test(RotateLeft, examples) {
   cr_assert_eq(RotateLeft(5, 1), 10);
   cr_assert_eq(RotateLeft(5, 2), 20);
   cr_assert_eq(RotateLeft(5, 3), 40);
   cr_assert_eq(RotateLeft(0xABBBBBBB, 32), 0xABBBBBBB);
   cr_assert_eq(RotateLeft(0x0000000F, 4), 0x000000F0);
}
Test(SwapOddEvenBits, examples) {
   cr_assert_eq(SwapOddEvenBits(23), 43);
   cr_assert_eq(SwapOddEvenBits(0), 0);
   cr_assert_eq(SwapOddEvenBits(1), 2);
   cr_assert_eq(SwapOddEvenBits(0xAAAAAAAA), 0x55555555);  
   cr_assert_eq(SwapOddEvenBits(0xFFFFFFFF), 0xFFFFFFFF);
}

/* =========================
* PART 2: IEEE 754 Float
* ========================= */

Test(ConstructFloat, positive_examples) {
   float f = construct_float_sf(0x00, 0x7F, 0x200000);
   cr_assert_float_eq(f, 1.25, 0.00001);

   f = construct_float_sf(0x00, 0x81, 0x300000);
   cr_assert_float_eq(f, 5.5, 0.00001);

   f = construct_float_sf(0x00, 0x76, 0x299B6F);
   cr_assert_float_eq(f, 0.002588, 0.000001);

   f = construct_float_sf(0x00, 0x89, 0xABCDEF);
   cr_assert_float_eq(f, 1374.44, 0.01);

   f = construct_float_sf(0x00, 0x90, 0x7973C0);
   cr_assert_float_eq(f, 255439.0, 0.1);

   f = construct_float_sf(0x00, 0x01, 0x000000); 
   cr_assert_float_eq(f, 1.17549435e-38, 1e-45);

   f = construct_float_sf(0x00, 0x80, 0x400000);
   cr_assert_float_eq(f, 3.0, 0.00001);

   f = construct_float_sf(0x00, 0x82, 0x200000);
   cr_assert_float_eq(f, 10.0, 0.00001);

   f = construct_float_sf(0x00, 0x7E, 0x000000);
   cr_assert_float_eq(f, 0.5, 0.00001);

   f = construct_float_sf(0x00, 0xFE, 0x7FFFFF);
   cr_assert(f > 3.4e38);

   

}

Test(ConstructFloat, negative_examples) {
   float f = construct_float_sf(0x01, 0x7F, 0x200000);
   cr_assert_float_eq(f, -1.25, 0.00001);

   f = construct_float_sf(0x01, 0x81, 0x300000);
   cr_assert_float_eq(f, -5.5, 0.00001);

   f = construct_float_sf(0x01, 0x76, 0x299B6F);
   cr_assert_float_eq(f, -0.002588, 0.000001);

   f = construct_float_sf(0x01, 0x89, 0xABCDEF);
   cr_assert_float_eq(f, -1374.44, 0.01);

   f = construct_float_sf(0x01, 0x90, 0x7973C0);
   cr_assert_float_eq(f, -255439.0, 0.1);

   f = construct_float_sf(0x01, 0x80, 0x400000);
   cr_assert_float_eq(f, -3.0, 0.00001);
   
   f = construct_float_sf(0x01, 0xFF, 0x000000);
   cr_assert(f < -1e37);

   f = construct_float_sf(0x01, 0x82, 0x200000);
   cr_assert_float_eq(f, -10.0, 0.00001);

   f = construct_float_sf(0x01, 0x7E, 0x000000);
   cr_assert_float_eq(f, -0.5, 0.00001);

   f = construct_float_sf(0x01, 0x01, 0x000000);
   cr_assert_float_eq(f, -1.17549435e-38, 1e-45);

}

/* =========================
* PART 3: Integer Conversion
* ========================= */
/* NOTE:
* We do NOT test output matching here.
* Students are encouraged to visually inspect output.
* TAs will use stronger hidden tests.
*/

Test(ReprConvert, basic_run) {
   repr_convert('2', '2', 0x59f2ca50);
   repr_convert('S', '2', 0x80000000);
}


