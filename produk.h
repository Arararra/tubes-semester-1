#ifndef PRODUK_H
#define PRODUK_H

#include <stdio.h>

typedef struct {
  char nama[50];
  int harga;
} Product;

void printTabelProduk(Product *produk, int sizeProduk) {
  printf("%-15s %-15s\n", "Nama", "Harga");
  for (int i = 0; i < sizeProduk; i++) {
    printf("%-15s %-15d\n", produk[i].nama, produk[i].harga);
  }
}

extern Product kapal[];
extern Product tujuan[];
extern int sizeKapal;
extern int sizeTujuan;

#endif