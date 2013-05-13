#include <stdio.h>
#include <gmp.h>

//Algorithm to be used: 
//             oo   <---- Infinity sign
//           _____
//           \
// 1          \     (-1)^k * (6k)! * (13591409 + 545140134k)
// -- = 12 *   *   ------------------------------------------
// Pi         /         (3k)! * (k!)^3 * 640320^(3k+1.5)
//           /____
//            k=0

mpz_t pi;
void main() {
  mpz_init(pi);
  mpz_set_si(pi,0);
  
  printf(mpz_get_str(NULL,10,pi));
}
