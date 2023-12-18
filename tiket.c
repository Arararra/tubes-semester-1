#include "tiket.h"

Tiket *tiket = NULL;
int sizeTiket = 0;

void initDummyTiket(Tiket **tiket, int *sizeTiket) {
  Tiket dummy[] = {
    { "Bayu", "20-12-2023", 1 },
    { "Andi", "25-12-2023", 2 },
    { "Cahyadi", "23-12-2023", 3 },
    { "Dewi", "20-12-2023", 1 },
  };
  int dummySize = sizeof(dummy) / sizeof(dummy[0]);

  *tiket = realloc(*tiket, (*sizeTiket + dummySize) * sizeof(Tiket));

  for (int i = 0; i < dummySize; i++) {
    (*tiket)[*sizeTiket + i] = dummy[i];
  }

  *sizeTiket += dummySize;
  return;
}

void printTabelTiket(Tiket *tiket, int sizeTiket, Kapal *kapal, int sizeKapal) {
  if (sizeTiket == 0) {
    printf("Data tiket kosong\n");
    return;
  }
  
  printf("%-15s %-25s %-15s %-15s\n", "Pembeli", "Tanggal berangkat", "Nama kapal", "Rute");
  for (int i = 0; i < sizeTiket; i++) {
    Kapal dataKapal = cariKapal(kapal, sizeKapal, tiket[i].idKapal);
    printf("%-15s %-25s %-15s %-15s\n", tiket[i].nama, tiket[i].tanggal, dataKapal.nama, dataKapal.rute);
  }
  return;
}

void tambahTiket(Tiket **tiket, int *sizeTiket, Kapal *kapal, int sizeKapal) {
  *tiket = realloc(*tiket, (*sizeTiket + 1) * sizeof(Tiket));

  printf("Masukkan nama pembeli: ");
  scanf(" %[^\n]s", (*tiket)[*sizeTiket].nama);

  printf("Masukkan tanggal keberangkatan: ");
  scanf(" %[^\n]s", (*tiket)[*sizeTiket].tanggal);

  printTabelKapal(kapal, sizeKapal);
  
  Kapal dataKapal;
  do {
    printf("Pilih kapal: ");
    scanf("%d", &(*tiket)[*sizeTiket].idKapal);
    dataKapal = cariKapal(kapal, sizeKapal, (*tiket)[*sizeTiket].idKapal);
    if (dataKapal.id == -1) printf("Kapal tidak tersedia\n");
    else if (dataKapal.kapasitas == 0) printf("Kapal sudah penuh\n");
  } while (dataKapal.id == -1 || dataKapal.kapasitas == 0);

  char konfirmasi;
  printf("Konfirmasi tiket (y/n): ");
  scanf(" %c", &konfirmasi);

  if (konfirmasi == 'y' || konfirmasi == 'Y') {
    kapal[(*tiket)[*sizeTiket].idKapal - 1].kapasitas--;
    (*sizeTiket)++;
    
    printf("Tiket berhasil dibuat\n");
    printTabelTiket(*tiket, *sizeTiket, kapal, sizeKapal);
  } else {
    *tiket = realloc(*tiket, *sizeTiket * sizeof(Tiket));
    printf("Tiket batal dibuat\n");
  }

  return;
}
