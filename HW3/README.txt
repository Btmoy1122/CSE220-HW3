----------------------------------------------------------------------------------------------------
CSE 220 - Homework 3
Brandon Moy 
116187802
----------------------------------------------------------------------------------------------------


Homework Structure:
HW3/
├── Makefile
├── HW3_main.c
├── MyBitManipulation.h
├── MyBitManipulation.c
├── Myfloat.h
├── Myfloat.c
├── MyIntegers.h
├── MyIntegers.c
└── README.txt  


I tested both Part 1 and Part 2 using Criterion
Part 3 was tested using prints in HW3_main.c
I passed 100% of the test cases that I thought of and tried to be exhaustive with the test cases.
I also tested all the cases given in the homework.

Part 1: Bit Manipulation - 
ToggleBit - Tested inputs with bits in the middle the LSB and MSB cases.
GetMSB - Tested with standard cases in powers of 2 and the edge case of 0 which returns -1
ClearBitRange - Tested cases of one-bit being cleared (when start=end) and multiple bits being cleared. Also tested invalid cases like start>end
RotateLeft - Tested the case of a 32 bit shift returns the same number and checked normal multi-bit left shifts. Made sure to include cases where bits would need to rotate from the LSB to MSB
SwapOddEvenBits - Tested normal swaps and the cases like 0xFFFFFFFF staying the same.

Part 2: IEEE 754 Float Construction
Included atleast 10 positive and 10 negative test cases
Tested values across a large range (small values like 1.17e-38 and large values like 3.4e38)


Part 3: Integer representation
Tested exhaustively across possible edge cases and error handling.
Checked normal conversion between twos complement so sign/magnitude or sign/magnitude to twos complement
Made sure negative zero was always outputted instead as positive zero
Checked cases with -2^31 for sign/magnitude
Checked the cases for incorrect inputs(source or target) and ensured error string output

My approach to part 3 was testing all cases in which you may have to convert starting with the incorrect inputs. 
There may be shorter/more optimal ways to do this, but this way seemed the most clear to me.
