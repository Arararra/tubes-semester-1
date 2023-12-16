#include "tiket.h"
#include "kapal.h"

Tiket tiket[] = {
  { "Bayu", "20-12-2023", 0 },
  { "Andi", "25-12-2023", 1 },
  { "Cahyadi", "23-12-2023", 2 },
  { "Dewi", "20-12-2023", 0 },
};
int sizeTiket = sizeof(tiket) / sizeof(tiket[0]);

Kapal cariKapal(Kapal *kapal, int sizeKapal, int pencarian) {
  for (int i = 0; i < sizeKapal; i++) {
    if (kapal[i].id == pencarian) {
      return kapal[i];
    }
  }
}

void printTabelTiket(Tiket *tiket, int sizeTiket) {
  printf("%-15s %-25s %-15s %-15s\n", "Pembeli", "Tanggal berangkat", "Nama kapal", "Rute");
  for (int i = 0; i < sizeTiket; i++) {
    Kapal dataKapal = cariKapal(kapal, sizeKapal, tiket[i].idKapal);
    printf("%-15s %-25s %-15s %-15s\n", tiket[i].nama, tiket[i].tanggal, dataKapal.nama, dataKapal.rute);
  }
}
