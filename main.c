#include <stdio.h>
#include "kapal.h"
#include "tiket.h"

// Gunakan command dibawah untuk menjalankan program
// clear ; gcc -o tubes main.c kapal.c tiket.c ; ./tubes

void main() {
  int pilihAksi = -1;
  
  printf("1. Lihat kapal\n");
  printf("2. Lihat penjualan tiket\n");
  printf("5. Keluar\n");
  printf("Masukkan pilihan: ");
  scanf("%d", &pilihAksi);

  switch (pilihAksi) {
  case 1:
    printTabelKapal(kapal, sizeKapal);
    break;
  case 2:
    printTabelTiket(tiket, sizeTiket);
    break;
  case 5:
    return;
  default:
    break;
  }
}
