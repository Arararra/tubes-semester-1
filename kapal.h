#ifndef KAPAL_H
#define KAPAL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  int id;
  char nama[100];
  char rute[100];
  int kapasitas;
  int harga;
} Kapal;

Kapal cariKapal(Kapal *kapal, int sizeKapal, int pencarian);
void printTabelKapal(Kapal *kapal, int sizeKapal);
void tambahKapal(Kapal *kapal, int *sizeKapal);

extern Kapal kapal[4];
extern int sizeKapal;

#endif
