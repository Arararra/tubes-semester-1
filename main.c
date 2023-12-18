#include <stdio.h>
#include "kapal.h"
#include "tiket.h"

// Gunakan command dibawah untuk menjalankan program
// clear ; gcc -o tubes main.c kapal.c tiket.c ; ./tubes

void main() {
  initDummyTiket(&tiket, &sizeTiket);

  startingPoint:

  printf("1. Lihat data kapal\n");
  printf("2. Lihat data tiket\n");
  printf("3. Tambahkan kapal\n");
  printf("4. Buat tiket baru\n");
  printf("5. Berangkatkan kapal\n");
  printf("6. Urutkan data tiket berdasarkan nama\n");
  printf("0. Keluar\n");
  printf("Masukkan pilihan anda: ");
  int inputPilihan = -1;
  scanf("%d", &inputPilihan);

  switch (inputPilihan) {
  case 1:
    printTabelKapal(kapal, sizeKapal);
    break;
  case 2:
    printTabelTiket(tiket, sizeTiket, kapal, sizeKapal);
    break;
  case 3:
    tambahKapal(kapal, &sizeKapal);
    break;
  case 4:
    tambahTiket(&tiket, &sizeTiket, kapal, sizeKapal);
    break;
  case 5:
    departKapal(kapal, &sizeKapal, tiket, &sizeTiket);
    break;
  case 6:
    sortTiket(tiket, sizeTiket);
    break;
  case 0:
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
