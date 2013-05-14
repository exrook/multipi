#include <stdio.h>
#include <gmp.h>
#include <omp.h>

//Algorithm to be used: 
//             oo   <---- Infinity sign
//           _____
//           \
// 1          \     (-1)^k * (6k)! * (13591409 + 545140134k)
// -- = 12 *   *   ------------------------------------------
// Pi         /         (3k)! * (k!)^3 * 640320^(3k+1.5)
//           /____
//            k=0

void calcpi(mpf_t out, unsigned long int iterations) {
  mpf_t pi;
  mpz_t top;
  mpz_t bottom1;
  mpf_t bottom2;
  mpz_t tempi;
  mpf_t tempf;
  mpf_set_default_prec(4194304UL);
  unsigned long int k;
  mpf_init(pi);
  mpf_set_si(pi,0L);
  #pragma omp parallel shared(pi) private(top,bottom1,tempi,tempf,bottom2,k)
  {
    mpz_init(top);
    mpz_init(tempi);
    mpf_init(tempf);
    mpz_init(bottom1);
    mpf_init(bottom2);
    #pragma omp for schedule(dynamic) nowait
    for(k=0;k<=iterations;k++) {
      //start of top half
      mpz_set_si(top,-1L);
      mpz_pow_ui(top,top,k); //(-1)^k
      mpz_fac_ui(tempi,(6UL * k)); //(6k)!
      mpz_mul(top,top,tempi); //(-1)^k * (6k)!
      mpz_set_ui(tempi,545140134UL);
      mpz_mul_ui(tempi,tempi,k); //545140134k
      mpz_add_ui(tempi,tempi,13591409UL); //(13591409+54514013k)
      mpz_mul(top,top,tempi); //(-1)^k * (6k)! * (135911409+54514013k)
      //end of top half, start of bottom half
      mpz_fac_ui(bottom1,3UL * k);//(3k)!
      mpz_mfac_uiui(tempi,k,3UL);//(k!)^3
      mpz_mul(bottom1,bottom1,tempi);//(3k)! * (k!)^3
      //finished integer section, here comes the messy part
      mpz_ui_pow_ui(tempi,640320UL,(6UL*k)+3);//640320^(6k+3)
      mpf_set_z(bottom2,tempi);
      mpf_sqrt(bottom2,bottom2); //(640320^(6k+3))^(1/2)
      //finished float section
      mpf_set_z(tempf,bottom1);
      mpf_mul(bottom2,bottom2,tempf);//(3k)! * (k!)^3 * 640320^(3k+1.5)
      mpf_set_z(tempf,top);
      mpf_div(tempf,tempf,bottom2);// top/bottom
      #pragma omp critical
      {
        fprintf(stderr,"Thread %d adding to the total with iteration %d\n", omp_get_thread_num(), k);
        mpf_add(pi,pi,tempf);
      }
//    mpf_out_str(stdout,10,10,pi);
//    puts("\n");
    }
    mpf_clear(tempf);
    mpf_clear(bottom2);
    mpz_clear(bottom1);
    mpz_clear(tempi);
    mpz_clear(top);
    }
  #pragma omp taskwait
  mpf_mul_ui(pi,pi,12UL);// sum * 12
  mpf_ui_div(pi,1UL,pi); // inverse
  mpf_swap(out,pi);
  mpf_clear(pi);
}
