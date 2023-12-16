#include <stdio.h>
#include "produk.h"

void main() {
  int pilihAksi = -1;
  
  printf("1. Lihat kapal\n");
  printf("2. Lihat tujuan\n");
  printf("5. Keluar\n");
  printf("Masukkan pilihan: ");
  scanf("%d", &pilihAksi);

  switch (pilihAksi) {
  case 1:
    printTabelProduk(kapal, sizeKapal);
    break;
  case 2:
    printTabelProduk(tujuan, sizeTujuan);
    break;
  case 5:
    return;
    break;
  default:
    break;
  }
}
