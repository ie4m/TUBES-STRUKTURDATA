#include "rental.h"

/* INIT */
void initList(ListToko &LT, ListBarang &LB, ListRelasi &LR) {
    LT.first = NULL;
    LB.first = NULL;
    LR.first = NULL;
}

/* ===== TOKO ===== */
void insertToko(ListToko &LT, Toko T) {
    ElmToko *P = new ElmToko;
    P->info = T;
    P->next = LT.first;
    LT.first = P;
}

ElmToko* findToko(ListToko LT, int id) {
    ElmToko *P = LT.first;
    while (P != NULL) {
        if (P->info.idToko == id) return P;
        P = P->next;
    }
    return NULL;
}

void deleteToko(ListToko &LT, ListRelasi &LR, int id) {
    ElmToko *P = LT.first, *prev = NULL;
    while (P != NULL && P->info.idToko != id) {
        prev = P;
        P = P->next;
    }
    if (P != NULL) {
        if (prev == NULL) LT.first = P->next;
        else prev->next = P->next;

        ElmRelasi *R = LR.first, *pr = NULL;
        while (R != NULL) {
            if (R->toko == P) {
                if (pr == NULL) LR.first = R->next;
                else pr->next = R->next;
                delete R;
                R = (pr == NULL) ? LR.first : pr->next;
            } else {
                pr = R;
                R = R->next;
            }
        }
        delete P;
    }
}

void showToko(ListToko LT) {
    ElmToko *P = LT.first;
    while (P != NULL) {
        cout << "ID: " << P->info.idToko << " | Nama: " << P->info.nama << endl;
        P = P->next;
    }
}

/* ===== BARANG ===== */
void insertBarang(ListBarang &LB, Barang B) {
    ElmBarang *P = new ElmBarang;
    P->info = B;
    P->next = LB.first;
    LB.first = P;
}

ElmBarang* findBarang(ListBarang LB, int id) {
    ElmBarang *P = LB.first;
    while (P != NULL) {
        if (P->info.idBarang == id) return P;
        P = P->next;
    }
    return NULL;
}

void deleteBarang(ListBarang &LB, ListRelasi &LR, int id) {
    ElmBarang *P = LB.first, *prev = NULL;
    while (P != NULL && P->info.idBarang != id) {
        prev = P;
        P = P->next;
    }
    if (P != NULL) {
        if (prev == NULL) LB.first = P->next;
        else prev->next = P->next;

        ElmRelasi *R = LR.first, *pr = NULL;
        while (R != NULL) {
            if (R->barang == P) {
                if (pr == NULL) LR.first = R->next;
                else pr->next = R->next;
                delete R;
                R = (pr == NULL) ? LR.first : pr->next;
            } else {
                pr = R;
                R = R->next;
            }
        }
        delete P;
    }
}