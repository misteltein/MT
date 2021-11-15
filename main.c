#include <assert.h>
#include <stdio.h>

#include "MT.h"

int main() {
   init_mti();
   for (size_t i = 0; i < 8; ++i) {
      init_genrand(12345678, i);
   }
   for (size_t step = 0; step < 100000; ++step) {
      unsigned long result[THREAD_N];
      for (size_t i = 0; i < 8; ++i) {
         result[i] = genrand_int32(i);
      }
      for (size_t i = 0; i < 8; ++i) {
         assert(result[0] == result[i]);
      }
   }
}
