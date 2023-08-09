#include <stdio.h>
#include <stdlib.h>
#include <math.h>


long long int mod_exp(long long int base, long long int exponent, long long int modulus) {
    
    long long int result = 1;
    base = base % modulus;

    while (exponent > 0) {
        
        if (exponent % 2 == 1) {
            result = (result * base) % modulus;
        }

        base = (base * base) % modulus;
        exponent = exponent / 2;
       
    }


    return result;
};


int main() {
    // Agree upon a prime number - p 
    long long int p = 23;
    // And root primitive, modulo p - g
    long long int g = 5;
    
    //Alice's Secret Key
    long long int a = 32;
    //Bob's Secret Key
    long long int b =15;
    
    //Alice computes A, and sends to Bob
    long long int A = mod_exp(g, a, p);
    //Bob computes B, and sends to Alice
    long long int B = mod_exp(g, b, p);
    
    //Alice uses B (sent to her by bob) to create secret_A
    long long int secret_A = mod_exp(B, a, p);
    //Bob uses A (sent to him by Alice) to create secret_B
    long long int secret_B = mod_exp(A, b, p);

    printf("Alice's secret key: %lld\n", secret_A);
    printf("Bob's secret key: %lld\n", secret_B);

    return 0;

};
