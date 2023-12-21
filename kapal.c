#include "kapal.h"

Kapal kapal[4] = {
  { 1, "Kapal A", "Gresik", "12-12-2023", 0, 100000 },
  { 2, "Kapal B", "Banjarmasin", "17-12-2023", 5, 100000 },
  { 3, "Kapal C", "Lombok", "20-12-2023", 10, 100000 },
};
int sizeKapal = 3;

Kapal cariKapal(Kapal *kapal, int sizeKapal, int pencarian) {
  for (int i = 0; i < sizeKapal; i++) {
    if (kapal[i].id == pencarian) {
      return kapal[i];
    }
  }
  return (Kapal){ 0, "", "", 0, 0 };
}

void printTabelKapal(Kapal *kapal, int sizeKapal) {
  if (sizeKapal == 0) {
    printf("Data kapal kosong\n");
    return;
  }

  printf("%-5s %-15s %-15s %-25s %-15s %-15s\n", "ID", "Nama kapal", "Rute", "Tanggal Berangkat", "Kapasitas", "Harga");
  for (int i = 0; i < sizeKapal; i++) {
    printf("%-5d %-15s %-15s %-25s %-15d %-15d\n", kapal[i].id, kapal[i].nama, kapal[i].rute, kapal[i].tanggal, kapal[i].kapasitas, kapal[i].harga);
  }
}

void tambahKapal(Kapal *kapal, int *sizeKapal) {
  if (*sizeKapal >= 4) {
    printf("Dermaga sudah penuh\n");
    return;
  }

  Kapal kapalBaru;
  kapalBaru.id = (*sizeKapal > 0) ? kapal[*sizeKapal - 1].id + 1 : 1;

  printf("Masukkan nama kapal: ");
  scanf(" %[^\n]s", kapalBaru.nama);

  printf("Masukkan rute: ");
  scanf(" %[^\n]s", kapalBaru.rute);

  printf("Masukkan tanggal keberangkatan: ");
  scanf(" %[^\n]s", kapalBaru.tanggal);

  printf("Masukkan kapasitas: ");
  scanf("%d", &kapalBaru.kapasitas);

  printf("Masukkan harga: ");
  scanf("%d", &kapalBaru.harga);

  char konfirmasi;
  printf("Konfirmasi kapal (y/n): ");
  scanf(" %c", &konfirmasi);

  if (konfirmasi == 'y' || konfirmasi == 'Y') {
    kapal[*sizeKapal] = kapalBaru;
    (*sizeKapal)++;
    
    printf("Kapal berhasil ditambahkan %d\n", *sizeKapal);
    printTabelKapal(kapal, *sizeKapal);
  } else {
    printf("Kapal batal ditambahkan\n");
  }

  return;
}