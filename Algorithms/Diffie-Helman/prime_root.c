#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int* getFactors(int x) {

    //Create an array with all the factors of x
    static int numberArray[50] = {};
    int count = 0;
    for (int i = 0; i < x; i++)
        if ( x % (i + 1) == 0 && ( i + 1 != 1 || i + 1 != x ) ) {
            numberArray[count] = i + 1;
            count += 1;
            } 
    return numberArray;
};

int main () {
    
    int* numberArray = getFactors(12);
    int i;
    int length = sizeof(numberArray);
    printf("length: %lu\n", length); 
    for (i = 0; i < length; i++)
        printf("%d\n", numberArray[i]);
    
    return 0;
};
