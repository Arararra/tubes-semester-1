#include <stdio.h>
#include "kapal.h"
#include "tiket.h"

// Gunakan command dibawah untuk menjalankan program
// clear ; gcc -o tubes main.c kapal.c tiket.c ; ./tubes

void main() {
  printTabelKapal(kapal, sizeKapal);
  printf("\n");
  printTabelTiket(tiket, sizeTiket);
}
