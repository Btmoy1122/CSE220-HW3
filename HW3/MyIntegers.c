#include "MyIntegers.h"
#include <stdio.h>
#include <stdbool.h>
//Brandon Moy 116187802

void repr_convert(char source_repr, char target_repr, unsigned int repr) {

   /*
    * TODO:
    * 1. Validate source_repr and target_repr
    * 2. Decode the source representation
    * 3. Convert to target representation
    * 4. Print the result or error message
    */


    //Step 1 validating inputs
    if ((source_repr != '2' && source_repr != 'S') || (target_repr != '2' && target_repr != 'S')){
        printf("error\n");
        return;
    }


    unsigned int result = repr;

    //Step 2/3 Decode to Source and convert to target

    //Two's complement to Sign/Magnitude
    if (source_repr == '2' && target_repr == 'S'){
        //Edge case of unrepresentable number
        if (repr == 0x80000000){
            printf("undefined\n");
            return;
        }
        //Check Sign Bit for negative case
        if ((repr >> 31) == 1) {
            unsigned int magnitude = (~repr) +1;
            result = magnitude | 0x80000000;
        }
    }

    //Sign/magnitude to Two's complement
    else if (source_repr == 'S' && target_repr == '2'){
        //Edge case of getting a negative zero
        if (repr == 0x80000000){
            result = 0;
        }

        else if ((repr >> 31) != 0){
            unsigned int magnitude = repr & 0x7FFFFFFF; //Remove the sign bit
            result = (~magnitude) + 1;
        }
    }

    //Sign to Sign representation - just need to check for the negative zero case
    else if (source_repr == 'S' && target_repr == 'S'){
        if (repr == 0x80000000){
            result = 0;
        }
    }

    //Step 4 Print result
    printf("%08x\n", result);


    
}

/*Test Cases (with edge cases and error handling)
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
    */
