#ifndef TIKET_H
#define TIKET_H

#include <stdio.h>

typedef struct {
  char nama[50];
  char tanggal[100];
  int idKapal;
} Tiket;

void printTabelTiket(Tiket *tiket, int sizeTiket);

extern Tiket tiket[];
extern int sizeTiket;

#endif