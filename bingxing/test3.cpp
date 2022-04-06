#include <stdio.h>

#include <C:\MinGW\include\gmp.h>
#include <C:\MinGW\include\mpfr.h>

int main (void) {

    mpfr_t sum, tmp, num1, num2;
    double N = 50000;
    int NUM = 5000;
    mpfr_init2 (sum, N);
    mpfr_set_d (sum, 0.000000000000000000000000000000, MPFR_RNDN);
    mpfr_init2 (tmp, N);
    mpfr_init2 (num1, N);
    mpfr_set_d (num1, 1.00000000000000000000000000, MPFR_RNDN);
    mpfr_init2 (num2, N);
    mpfr_set_d (num2, 2.00000000000000000000000000, MPFR_RNDN);

    for(auto i = 0; i < N; i++){
        mpfr_t numi;
        mpfr_init2 (numi, N);
        mpfr_set_d (numi, double(i+1), MPFR_RNDN);
        mpfr_div (tmp, num1, numi, MPFR_RNDN);
        //mpfr_out_str (stdout, 10, 0, tmp, MPFR_RNDD);
        //putchar ('\n');
        if(i%2 == 0)
            mpfr_add (sum, sum, tmp, MPFR_RNDN);
        else
            mpfr_sub(sum, sum, tmp, MPFR_RNDN);
    }
    //
    mpfr_div (sum, num1, sum, MPFR_RNDN);
    mpfr_pow (sum, num2, sum, MPFR_RNDN);
    mpfr_out_str (stdout, 10, 0, sum, MPFR_RNDN);
}