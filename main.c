#include <stdio.h>
#include <gmp.h>
#include <omp.h>
#include <stdlib.h>

//Algorithm to be used: 
//             oo   <---- Infinity sign
//           _____
//           \
// 1          \     (-1)^k * (6k)! * (13591409 + 545140134k)
// -- = 12 *   *   ------------------------------------------
// Pi         /         (3k)! * (k!)^3 * 640320^(3k+1.5)
//           /____
//            k=0
mpf_t pi;
unsigned long int iter = 0;
unsigned long int length = 100;
int main(int argc, char *argv[]) {
  if (argc > 3) {
    printf("Usage: %s <iterations> <output length>\n", argv[0]);
    puts("Where iterations is a positive integer");
    puts("If iterations is not an integer, not present,\n or positive, the default value of 20 is used");
    puts("Output length is the length of the output,\n in digits. Default 100");
    return 1;
  } else if (argc > 1) {
    long long int tmp = strtoll(argv[1], (char **) NULL, 10);
    if (tmp <= 0) {
      iter = 20UL;
    } else {
      iter = (unsigned long) tmp;
    }
  } else if (iter == 0) {
    iter = 20UL;
  } if (argc == 3) {
    long long int tmp = strtoll(argv[2], (char**) NULL, 10);
    if (tmp < 0) {
      length = 100UL;
    } else {
      length = (unsigned long) tmp;
    }
  }
  fprintf(stderr,"Computing %d iterations\n", iter);
  mpf_set_default_prec(65536UL);
  mpf_init(pi);
  calcpi(pi,iter);
  mpf_out_str(stdout,10,length,pi);
  puts("");
  return 0;
}
