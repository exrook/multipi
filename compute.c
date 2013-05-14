#include <stdio.h>
#include <gmp.h>
//#include <pi.c>

mpf_t pi;
mpf_t pio;
int main(int argc, char *argv[]) {
  mpf_init(pi);
  mpf_init(pio);
  calcpi(pio,1100);
  signed long int exp;
  unsigned long int i = 0;
  for(i=100;i<=1000;i=i+100) {
    calcpi(pi, i);
    mpf_sub(pi,pio,pi);
    mpf_abs(pi,pi);
    mpf_get_d_2exp(&exp,pi);
    printf("%d iterations is accurate to %d decimal places\n", i,2^exp);
    gmp_printf("%2.0Fe\n",pi);
  }
}
    
