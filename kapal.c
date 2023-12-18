#include "kapal.h"

Kapal kapal[] = {
  { 1, "Kapal A", "Gresik", 0, 100000 },
  { 2, "Kapal B", "Banjarmasin", 5, 100000 },
  { 3, "Kapal C", "Lombok", 10, 100000 },
};
int sizeKapal = sizeof(kapal) / sizeof(kapal[0]);
int maxKapal = 4;

void printTabelKapal(Kapal *kapal, int sizeKapal) {
  if (sizeKapal == 0) {
    printf("Data kapal kosong\n");
    return;
  }

  printf("%-15s %-15s %-15s %-15s\n", "Nama kapal", "Rute", "Kapasitas", "Harga");
  for (int i = 0; i < sizeKapal; i++) {
    printf("%-15s %-15s %-15d %-15d\n", kapal[i].nama, kapal[i].rute, kapal[i].kapasitas, kapal[i].harga);
  }
}
