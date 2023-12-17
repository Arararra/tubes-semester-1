#include <stdio.h>
#include "kapal.h"
#include "tiket.h"

// Gunakan command dibawah untuk menjalankan program
// clear ; gcc -o tubes main.c kapal.c tiket.c ; ./tubes

void main() {
  startingPoint:

  printf("1. Lihat data kapal\n");
  printf("2. Lihat data tiket\n");
  printf("3. Buat tiket baru\n");
  printf("4. Keluar\n");
  printf("Masukkan pilihan anda: ");
  int inputPilihan = -1;
  scanf("%d", &inputPilihan);

  switch (inputPilihan) {
  case 1:
    printTabelKapal(kapal, sizeKapal);
    break;
  case 2:
    printTabelTiket(tiket, sizeTiket);
    break;
  case 3:
    buatTiket(&tiket, &sizeTiket);
    break;
  case 4:
    printf("Terima kasih telah menggunakan program kami :)\n");
    return;
    break;
  default:
    printf("Input tidak ada dalam pilihan\n");
    break;
  }
  printf("\n");

  goto startingPoint;
}
