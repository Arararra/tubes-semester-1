#include "tiket.h"

Tiket tiket[] = {
  { "Bayu", "20-12-2023", 0 },
  { "Andi", "25-12-2023", 1 },
  { "Cahyadi", "23-12-2023", 2 },
  { "Dewi", "20-12-2023", 0 },
};
int sizeTiket = sizeof(tiket) / sizeof(tiket[0]);

void printTabelTiket(Tiket *tiket, int sizeTiket) {
  printf("%-15s %-25s %-15s\n", "Pembeli", "Tanggal berangkat", "ID Kapal");
  for (int i = 0; i < sizeTiket; i++) {
    printf("%-15s %-25s %-15d\n", tiket[i].nama, tiket[i].tanggal, tiket[i].idKapal);
  }
}
