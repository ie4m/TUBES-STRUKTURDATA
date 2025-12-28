#include "rental.h"

void initList(ListToko &LT, ListBarang &LB, ListRelasi &LR) {
    LT.first = NULL; LB.first = NULL; LR.first = NULL;
}

void insertToko(ListToko &LT, Toko T) {
    ElmToko *P = new ElmToko;
    P->info = T; P->next = LT.first; LT.first = P;
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
        prev = P; P = P->next;
    }
    if (P != NULL) {
        if (prev == NULL) LT.first = P->next;
        else prev->next = P->next;

        ElmRelasi *R = LR.first, *pr = NULL;
        while (R != NULL) {
            if (R->toko == P) {
                if (pr == NULL) LR.first = R->next;
                else pr->next = R->next;
                ElmRelasi *temp = R;
                R = R->next;
                delete temp;
            } else {
                pr = R; R = R->next;
            }
        }
        delete P;
        cout << "Toko berhasil dihapus.\n";
    }
}

void insertBarang(ListBarang &LB, Barang B) {
    ElmBarang *P = new ElmBarang;
    P->info = B; P->next = LB.first; LB.first = P;
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
        prev = P; P = P->next;
    }
    if (P != NULL) {
        if (prev == NULL) LB.first = P->next;
        else prev->next = P->next;

        ElmRelasi *R = LR.first, *pr = NULL;
        while (R != NULL) {
            if (R->barang == P) {
                if (pr == NULL) LR.first = R->next;
                else pr->next = R->next;
                ElmRelasi *temp = R;
                R = R->next;
                delete temp;
            } else {
                pr = R; R = R->next;
            }
        }
        delete P;
        cout << "Barang berhasil dihapus.\n";
    }
}

void addRelasi(ListRelasi &LR, ElmToko *T, ElmBarang *B) {
    if (T != NULL && B != NULL) {
        ElmRelasi *R = new ElmRelasi;
        R->toko = T; R->barang = B; R->next = LR.first; LR.first = R;
        cout << "Relasi ditambahkan!\n";
    } else {
        cout << "ID Toko atau Barang tidak ditemukan!\n";
    }
}

void showAll(ListToko LT, ListRelasi LR) {
    ElmToko *T = LT.first;
    if (T == NULL) cout << "Daftar Toko Kosong.\n";
    while (T != NULL) {
        cout << "\nToko: " << T->info.nama << " (ID: " << T->info.idToko << ")" << endl;
        ElmRelasi *R = LR.first;
        bool hasBarang = false;
        while (R != NULL) {
            if (R->toko == T) {
                // TAMBAHKAN info.harga DI SINI
                cout << "  - " << R->barang->info.nama 
                     << " [ID: " << R->barang->info.idBarang 
                     << "] | Harga: Rp" << R->barang->info.harga << endl;
                hasBarang = true;
            }
            R = R->next;
        }
        if (!hasBarang) cout << "  (Belum ada barang sewa)\n";
        T = T->next;
    }
}

void showBarangByToko(ListRelasi LR, int idToko) {
    ElmRelasi *R = LR.first;
    bool found = false;
    while (R != NULL) {
        if (R->toko->info.idToko == idToko) {
            cout << "- " << R->barang->info.nama << endl;
            found = true;
        }
        R = R->next;
    }
    if (!found) cout << "Barang tidak ditemukan.\n";
}

void showTokoByBarang(ListRelasi LR, int idBarang) {
    ElmRelasi *R = LR.first;
    bool found = false;
    while (R != NULL) {
        if (R->barang->info.idBarang == idBarang) {
            cout << "- " << R->toko->info.nama << endl;
            found = true;
        }
        R = R->next;
    }
    if (!found) cout << "Toko tidak ditemukan.\n";
}

void tokoTerbanyakTersedikit(ListToko LT, ListRelasi LR) {
    if (LT.first == NULL) return;
    int maxVal = -1, minVal = 999999;
    string maxT, minT;
    ElmToko *T = LT.first;
    while (T != NULL) {
        int count = 0;
        ElmRelasi *R = LR.first;
        while (R != NULL) {
            if (R->toko == T) count++;
            R = R->next;
        }
        if (count > maxVal) { maxVal = count; maxT = T->info.nama; }
        if (count < minVal) { minVal = count; minT = T->info.nama; }
        T = T->next;
    }
    cout << "Toko Terbanyak: " << maxT << " (" << maxVal << " barang)\n";
    cout << "Toko Tersedikit: " << minT << " (" << minVal << " barang)\n";
}