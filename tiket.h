#ifndef TIKET_H
#define TIKET_H

#include <stdio.h>
#include <stdlib.h>
#include "kapal.h"

typedef struct {
  char nama[50];
  char tanggal[100];
  int idKapal;
} Tiket;

void printTabelTiket(Tiket *tiket, int sizeTiket, Kapal *kapal, int sizeKapal);
void tambahTiket(Tiket **tiket, int *sizeTiket, Kapal *kapal, int sizeKapal);
void initDummyTiket(Tiket **tiket, int *sizeTiket);
void departKapal(Kapal *kapal, int *sizeKapal, Tiket *tiket, int *sizeTiket);

extern Tiket *tiket;
extern int sizeTiket;

#endif