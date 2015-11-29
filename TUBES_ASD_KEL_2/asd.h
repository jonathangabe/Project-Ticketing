#ifndef ASD_H_INCLUDED
#define ASD_H_INCLUDED

#include <iostream>
#include <string>
#include <conio.h>
#include <cstdlib>
#include <windows.h>
#include <dos.h>
#include <stdio.h>

#define delay Sleep

using namespace std;
struct pembeli
{
    string  idp;
    string  namap;
    string  tanggalp;
    int     harga;
    int     tempatduduk[50];
    int     duduk;
};
struct jadwal
{
    string  id;
    string  judul;
    string  jam;
    int     kapasitas;
    int     tempatduduk[50];
};

typedef struct elmp *adrp;
struct elmp
{
    pembeli infop;
    adrp next;
    adrp prev;
};
typedef struct elmj *adrj;
struct elmj
{
    jadwal info;
    adrj next;
    adrj prev;
    adrp pembeli;
};

struct listj
{
    adrj first;
    adrj last;
};

void createlist (listj &l);
adrp alokasip (pembeli x);
adrj alokasij (jadwal x);
adrp findp (listj &l, string x);
adrj findj (listj &l, string x);

void insert_jadwal (listj &l, adrj p);
void insert_pembeli (listj &l, adrp p, string x);
void delete_pembeli (listj &l, adrj p, adrp q);
void delete_jadwal (listj &l, adrj p);
void print_pembeli (listj l);
void print_jadwal (listj l);
void ubah_jadwal (listj &l);
void ubah_pembeli (listj &l);

adrp cari_pembeli (listj &l, pembeli x);
adrj cari_jadwal (listj &l, jadwal x);
void rekap_total (listj &l);
void cek_kursi (listj &l, jadwal x);

jadwal input_jadwal (jadwal &x);
pembeli input_pembeli (pembeli &x);

void gotoxy(int x,int y);
#endif // ASD_H_INCLUDED
