#ifndef RENTAL_H
#define RENTAL_H

#include <iostream>
#include <string>
using namespace std;

struct Toko {
    int idToko;
    string nama;
};

struct Barang {
    int idBarang;
    string nama;
    int harga;
};

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

struct ListToko { ElmToko *first; };
struct ListBarang { ElmBarang *first; };
struct ListRelasi { ElmRelasi *first; };

void initList(ListToko &LT, ListBarang &LB, ListRelasi &LR);
void insertToko(ListToko &LT, Toko T);
ElmToko* findToko(ListToko LT, int id);
void deleteToko(ListToko &LT, ListRelasi &LR, int id);
void insertBarang(ListBarang &LB, Barang B);
ElmBarang* findBarang(ListBarang LB, int id);
void deleteBarang(ListBarang &LB, ListRelasi &LR, int id);
void addRelasi(ListRelasi &LR, ElmToko *T, ElmBarang *B);
void showAll(ListToko LT, ListRelasi LR);
void showBarangByToko(ListRelasi LR, int idToko);
void showTokoByBarang(ListRelasi LR, int idBarang);
void tokoTerbanyakTersedikit(ListToko LT, ListRelasi LR);

#endif