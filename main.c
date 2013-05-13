#include <stdio.h>
#include <gmp.h>
mpz_t lol;
void main() {
  mpz_init(lol);
  mpz_set_si(lol, 1);
  long int i;
  for(i=1;i<=20000;i++) {
    mpz_mul_si(lol,lol,i);
  }
  printf(mpz_get_str(NULL,10,lol));
}
