#include "rental.h"
#include <limits>

int main() {
    ListToko LT; ListBarang LB; ListRelasi LR;
    initList(LT, LB, LR);
    int pilih;

    do {
        cout << "\n=== MENU RENTAL ===\n";
        cout << "1. Tambah Toko\n2. Tambah Barang\n3. Hubungkan Sewa\n4. Tampilkan Semua\n";
        cout << "5. Hapus Toko\n6. Hapus Barang\n7. Statistik\n0. Keluar\nPilih: ";
        
        if (!(cin >> pilih)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }
        cin.ignore();

        if (pilih == 1) {
            Toko T;
            cout << "ID Toko: "; cin >> T.idToko; cin.ignore();
            cout << "Nama Toko: "; getline(cin, T.nama);
            insertToko(LT, T);
        } else if (pilih == 2) {
            Barang B;
            cout << "ID Barang: "; cin >> B.idBarang; cin.ignore();
            cout << "Nama Barang: "; getline(cin, B.nama);
            cout << "Harga: "; cin >> B.harga; cin.ignore();
            insertBarang(LB, B);
        } else if (pilih == 3) {
            int idT, idB;
            cout << "ID Toko: "; cin >> idT;
            cout << "ID Barang: "; cin >> idB;
            addRelasi(LR, findToko(LT, idT), findBarang(LB, idB));
        } else if (pilih == 4) {
            showAll(LT, LR);
        } else if (pilih == 5) {
            int id; cout << "ID Toko yang dihapus: "; cin >> id;
            deleteToko(LT, LR, id);
        } else if (pilih == 6) {
            int id; cout << "ID Barang yang dihapus: "; cin >> id;
            deleteBarang(LB, LR, id);
        } else if (pilih == 7) {
            tokoTerbanyakTersedikit(LT, LR);
        }
    } while (pilih != 0);
    return 0;
}