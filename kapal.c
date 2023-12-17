#include "kapal.h"

Kapal kapal[] = {
  { 0, "Kapal A", "Gresik", 3, 100000 },
  { 1, "Kapal B", "Banjarmasin", 6, 100000 },
  { 2, "Kapal C", "Lombok", 9, 100000 },
};
int sizeKapal = sizeof(kapal) / sizeof(kapal[0]);

void printTabelKapal(Kapal *kapal, int sizeKapal) {
  printf("%-15s %-15s %-15s %-15s\n", "Nama kapal", "Rute", "Kapasitas", "Harga");
  for (int i = 0; i < sizeKapal; i++) {
    printf("%-15s %-15s %-15d %-15d\n", kapal[i].nama, kapal[i].rute, kapal[i].kapasitas, kapal[i].harga);
  }
}
