#include <stdio.h>

#include <C:\MinGW\include\gmp.h>
#include <C:\MinGW\include\mpfr.h>

int main (void) {
    unsigned int i;
    mpfr_t s, t, u;
    int N = 500;

    mpfr_init2 (t, N);
    mpfr_set_d (t, 2.0, MPFR_RNDD);
    mpfr_init2 (s, N);
    mpfr_set_d (s, 0.5, MPFR_RNDD);
    mpfr_init2 (u, N);

    mpfr_pow(u, t, s, MPFR_RNDD);
    mpfr_out_str (stdout, 10, 0, u, MPFR_RNDD);

}