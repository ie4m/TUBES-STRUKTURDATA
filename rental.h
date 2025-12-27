#ifndef RENTAL_H
#define RENTAL_H

#include <iostream>
using namespace std;

/* ====== STRUCT DATA ====== */
struct Toko {
    int idToko;
    string nama;
};

struct Barang {
    int idBarang;
    string nama;
    int harga;
};

/* ====== NODE ====== */
struct ElmToko {
    Toko info;
    ElmToko *next;
};

struct ElmBarang {
    Barang info;
    ElmBarang *next;
};

struct ElmRelasi {
    ElmToko *toko;
    ElmBarang *barang;
    ElmRelasi *next;
};

/* ====== LIST ====== */
struct ListToko {
    ElmToko *first;
};

struct ListBarang {
    ElmBarang *first;
};

struct ListRelasi {
    ElmRelasi *first;
};

/* ====== PROTOTYPE ====== */
void initList(ListToko &LT, ListBarang &LB, ListRelasi &LR);

/* TOKO */
void insertToko(ListToko &LT, Toko T);
ElmToko* findToko(ListToko LT, int id);
void deleteToko(ListToko &LT, ListRelasi &LR, int id);
void showToko(ListToko LT);

/* BARANG */
void insertBarang(ListBarang &LB, Barang B);
ElmBarang* findBarang(ListBarang LB, int id);
void deleteBarang(ListBarang &LB, ListRelasi &LR, int id);
void showBarang(ListBarang LB);

/* RELASI */
void addRelasi(ListRelasi &LR, ElmToko *T, ElmBarang *B);
void showAll(ListToko LT, ListRelasi LR);
void showBarangByToko(ListRelasi LR, int idToko);
void showTokoByBarang(ListRelasi LR, int idBarang);
void tokoTerbanyakTersedikit(ListToko LT, ListRelasi LR);

#endif