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

void tambahKapal(Kapal *kapal, int *sizeKapal, int maxKapal) {
  if (*sizeKapal >= maxKapal) {
    printf("Dermaga sudah penuh\n");
    return;
  }

  Kapal kapalBaru;
  kapalBaru.id = 4;

  printf("Masukkan nama kapal: ");
  scanf(" %[^\n]s", kapalBaru.nama);

  printf("Masukkan rute: ");
  scanf(" %[^\n]s", kapalBaru.rute);

  printf("Masukkan kapasitas: ");
  scanf("%d", &kapalBaru.kapasitas);

  printf("Masukkan harga: ");
  scanf("%d", &kapalBaru.harga);

  char konfirmasi;
  printf("Konfirmasi tiket (y/n): ");
  scanf(" %c", &konfirmasi);

  if (konfirmasi == 'y' || konfirmasi == 'Y') {
    kapal[*sizeKapal] = kapalBaru;
    
    printf("Kapal berhasil ditambahkan\n");
    printTabelKapal(kapal, *sizeKapal);
  } else {
    printf("Kapal batal ditambahkan\n");
  }
}
