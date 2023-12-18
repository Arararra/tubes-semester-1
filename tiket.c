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

Kapal cariKapal(Kapal *kapal, int sizeKapal, int pencarian) {
  for (int i = 0; i < sizeKapal; i++) {
    if (kapal[i].id == pencarian) {
      return kapal[i];
    }
  }
  return (Kapal){ -1, "", "", 0, 0 };
}

void printTabelTiket(Tiket *tiket, int sizeTiket) {
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

void tambahTiket(Tiket **tiket, int *sizeTiket) {
  *tiket = realloc(*tiket, (*sizeTiket + 1) * sizeof(Tiket));

  printf("Masukkan nama pembeli: ");
  scanf(" %[^\n]s", (*tiket)[*sizeTiket].nama);

  printf("Masukkan tanggal keberangkatan: ");
  scanf(" %[^\n]s", (*tiket)[*sizeTiket].tanggal);

  printf("%-5s %-15s %-15s %-15s\n", "ID", "Nama kapal", "Rute", "Kapasitas");
  for (int i = 0; i < sizeKapal; i++) {
    printf("%-5d %-15s %-15s %-15d\n", kapal[i].id, kapal[i].nama, kapal[i].rute, kapal[i].kapasitas);
  }
  
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
    printTabelTiket(*tiket, *sizeTiket);
  } else {
    *tiket = realloc(*tiket, *sizeTiket * sizeof(Tiket));
    printf("Tiket batal dibuat\n");
  }

  return;
}
