#include "kapal.h"

Kapal *kapal = NULL;
int sizeKapal = 0;

void initDummyKapal(Kapal **kapal, int *sizeKapal) {
  Kapal dummy[] = {
    { 1, "Kapal A", "Gresik", 0, 100000 },
    { 2, "Kapal B", "Banjarmasin", 5, 100000 },
    { 3, "Kapal C", "Lombok", 10, 100000 },
  };
  int dummySize = sizeof(dummy) / sizeof(dummy[0]);

  *kapal = realloc(*kapal, (*sizeKapal + dummySize) * sizeof(Kapal));

  for (int i = 0; i < dummySize; i++) {
    (*kapal)[*sizeKapal + i] = dummy[i];
  }

  *sizeKapal += dummySize;
  return;
}

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
