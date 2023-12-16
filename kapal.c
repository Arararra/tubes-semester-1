#include "kapal.h"

Kapal kapal[] = {
  { "Kapal A", "Gresik", 5 },
  { "Kapal B", "Banjarmasin", 7 },
  { "Kapal C", "Lombok", 10 },
};
int sizeKapal = sizeof(kapal) / sizeof(kapal[0]);

void printTabelKapal(Kapal *kapal, int sizeKapal) {
  printf("%-15s %-15s %-15s\n", "Nama kapal", "Rute", "Kapasitas");
  for (int i = 0; i < sizeKapal; i++) {
    printf("%-15s %-15s %-15d\n", kapal[i].nama, kapal[i].rute, kapal[i].kapasitas);
  }
}
