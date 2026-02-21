// HW3 Starter Code
#include "MyBitManipulation.h"
#include <stdio.h>
//Brandon Moy 116187802


/*
* Toggle the bit at position pos in num
*/
int ToggleBit(int num, int pos) {

   return num ^ (1 << pos);

}

/*
* Return the position of the most significant set bit
* Return -1 if num == 0
*/
int GetMSB(int num) {

   if (num == 0){
      return -1;
   }

   for (int i = 31; i>=0; i--){

      int check = 1 << i;

      if ((num & check) != 0){
         return i;
      }
   }

   return -1;


}

/*
* Clear bits from start to end (inclusive)
*/
int ClearBitRange(int num, int start, int end) {
   
   if (start < 0 || end > 31 || start > end){
      return num;
   }

   for (int i = start; i<=end; i++){

      int checker = ~(1 << i);
      num = num & checker;

   }

   return num;


}

/*
* Rotate num to the left by d bits
*/
uint32_t RotateLeft(uint32_t num, int d) {
   
   // Nust make the int usigned otherwise we will get incorrect results due to the sign bit needing to stay preserved
   unsigned int n = (unsigned int)num;

   unsigned int shiftLeft = n << d;
   unsigned int rotateBits = n >> (32 - d);

   unsigned int result = shiftLeft | rotateBits;
   
   return (int)result;

}

/*
* Swap odd and even bits
*/
int SwapOddEvenBits(int num) {
   
   unsigned int n = (unsigned int)num;

   //We catch the bits at odd positions and shift them right 1 into the corresponding even position (index 1 -> index 0)
   unsigned int even_bits = (n & 0xAAAAAAAA) >> 1;

   //We catch the bits at even positions and shift them left 1 into correspodning odd positions (index 0 -> index 1)
   unsigned int odd_bits = (n & 0x55555555) << 1;

   return (int)(even_bits | odd_bits);


}


/* Test Cases for Part 1
1. ToggleBit(9, 0)
Inputs: Number = 9, Position = 0
Expected Output = 8

2. ToggleBit(9, 3)
Inputs: Number = 9, Position = 3 
Expected Output = 1

3. ToggleBit(15, 3)
Inputs: Number = 15, Position = 3
Expected Output = 7

4. GetMSB(18)
Inputs: Number = 18 
Expected Output = 4

5. GetMSB(0)
Inputs: Number = 0 
Expected Output = -1

6. GetMSB(31)
Inputs: Number = 31 
Expected Output = 4

7. GetMSB(1000)
Inputs: Number = 1000 
Expected Output = 9

8. ClearBitRange(73, 1, 3)
Inputs: Number = 73, Start = 1, End = 3
Expected Output = 65

9. ClearBitRange(1500, 2, 7)
Inputs: Number = 1500, Start = 2, End = 7
Expected Output = 1280

10. ClearBitRange(555, 1, 5)
Inputs: Number = 555, Start = 1, End = 5
Expected Output = 513

11. ClearBitRange(10, 5, 2)
Inputs: Number = 10, Start = 5, End = 2
Expected Output = 10

12. RotateLeft(5, 1)
Inputs: Number = 5, Shift = 1
Expected Output = 10

13. RotateLeft(5, 2)
Inputs: Number = 5, Shift = 2 
Expected Output = 20

14. RotateLeft(5, 3)
Inputs: Number = 5, Shift = 3 
Expected Output = 40

15. SwapOddEvenBits(23)
Inputs: Number = 23 
Expected Output = 43

16. SwapOddEvenBits(0)
Inputs: Number = 0 
Expected Output = 0

17. SwapOddEvenBits(1)
Inputs: Number = 1 
Expected Output = 2

18. SwapOddEvenBits(0xAAAAAAAA)
Inputs: Number = 0xAAAAAAAA 
Expected Output = 0x55555555
*/