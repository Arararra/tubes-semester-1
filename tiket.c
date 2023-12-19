#include "tiket.h"

Tiket *tiket = NULL;
int sizeTiket = 0;

void initDummyTiket(Tiket **tiket, int *sizeTiket) {
  Tiket dummy[] = {
    { "Cahyadi", "23-12-2023", 3 },
    { "Andi", "25-12-2023", 2 },
    { "Dewi", "20-12-2023", 1 },
    { "Bayu", "20-12-2023", 1 },
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
    if (dataKapal.id == 0) printf("Kapal tidak tersedia\n");
    else if (dataKapal.kapasitas == 0) printf("Kapal sudah penuh\n");
  } while (dataKapal.id == -1 || dataKapal.kapasitas == 0);

  char konfirmasi;
  printf("Konfirmasi tiket (y/n): ");
  scanf(" %c", &konfirmasi);

  if (konfirmasi == 'y' || konfirmasi == 'Y') {
    for (int i = 0; i < sizeKapal; i++) {
      if (kapal[i].id == (*tiket)[*sizeTiket].idKapal) {
        kapal[i].kapasitas--;
      }
    }
    (*sizeTiket)++;
    
    printf("Tiket berhasil dibuat\n");
    printTabelTiket(*tiket, *sizeTiket, kapal, sizeKapal);
  } else {
    *tiket = realloc(*tiket, *sizeTiket * sizeof(Tiket));
    printf("Tiket batal dibuat\n");
  }

  return;
}

void sortTiket(Tiket *tiket, int sizeTiket) {
  int i, j;
  Tiket key;

  for (i = 1; i < sizeTiket; i++) {
    key = tiket[i];
    j = i - 1;

    while (j >= 0 && strcmp(tiket[j].nama, key.nama) > 0) {
      tiket[j + 1] = tiket[j];
      j = j - 1;
    }

    tiket[j + 1] = key;
  }

  printf("Data tiket berhasil diurutkan\n");
  return;
}

void departKapal(Kapal *kapal, int *sizeKapal, Tiket *tiket, int *sizeTiket) {
  printTabelKapal(kapal, *sizeKapal);
  
  int idKapalPilihan;
  Kapal kapalPilihan;
  do {
    printf("Pilih kapal: ");
    scanf("%d", &idKapalPilihan);
    kapalPilihan = cariKapal(kapal, *sizeKapal, idKapalPilihan);
    if (kapalPilihan.id == -1) printf("Kapal tidak tersedia\n");
  } while (kapalPilihan.id == -1);

  char konfirmasi;
  printf("Konfirmasi keberangkatan (y/n): ");
  scanf(" %c", &konfirmasi);

  if (konfirmasi == 'y' || konfirmasi == 'Y') {
    // hapus tiket yang terkait ke kapal
    for (int i = 0; i < *sizeTiket; i++) {
      if (tiket[i].idKapal == kapalPilihan.id) {
        for (int j = i; j < *sizeTiket - 1; j++) {
          tiket[j] = tiket[j + 1];
        }
        (*sizeTiket)--;
        i--;
      }
    }

    // hapus kapal
    for (int i = 0; i < *sizeKapal; i++) {
      if (kapal[i].id >= kapalPilihan.id) {      
        kapal[i] = kapal[i + 1];
      }
    }
    (*sizeKapal)--;
    
    printf("Kapal telah berangkat\n");
  } else {
    printf("Kapal batal berangkat\n");
  }

  return;
}
