#ifndef KAPAL_H
#define KAPAL_H

#include <stdio.h>

typedef struct {
  int id;
  char nama[50];
  char rute[50];
  int kapasitas;
  int harga;
} Kapal;

void printTabelKapal(Kapal *kapal, int sizeKapal);

extern Kapal kapal[];
extern int sizeKapal;

#endif
