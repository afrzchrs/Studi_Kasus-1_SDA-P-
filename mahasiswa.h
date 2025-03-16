#ifndef MAHASISWA_H
#define MAHASISWA_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "boolean.h"

typedef struct Mahasiswa {
    char nama[50];
    int nilai;
    struct Mahasiswa *next;
} Mahasiswa;

typedef Mahasiswa* address;

// Fungsi-fungsi utama
boolean isEmpty(address p);

void Create_Node(address *p);

void Isi_Node(address *p, char *nama, int nilai);

void Tampil_List(address p);

void Ins_Awal(address *p, address PNew);

void Ins_Akhir(address *p, address PNew);

void Ins_SortedByName(address *head, char *nama, int nilai);

void TampilListDescending(address head);

int hitungElements(address head);

void copydiatas70(address L1, address *L2);

void hapusDuplikasi(address *head);

void hapusList(address *head);

address Search(address p, char *nama);

address BalikList(address p);

#endif
