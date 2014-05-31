#include <gmp.h>

//Algorithm used: 
//             oo   <---- Infinity sign
//           _____
//           \
// 1          \     (-1)^k * (6k)! * (13591409 + 545140134k)
// -- = 12 *   *   ------------------------------------------
// Pi         /         (3k)! * (k!)^3 * 640320^(3k+1.5)
//           /____
//            k=0

void calcpartpi(mpf_t out, unsigned long int start, unsigned long int end)
void calcpi(mpf_t out, unsigned long int iterations)
