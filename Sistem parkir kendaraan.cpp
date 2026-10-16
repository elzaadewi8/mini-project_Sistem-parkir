#include <iostream>
using namespace std;

int main() {
    // ===== LOGIN PETUGAS =====
    string userBenar = "admin";
    string passBenar = "parkir123";
    string userInput, passInput;

    int percobaan = 0;
    bool loginBerhasil = false;

    while (percobaan < 3) {
        cout << "Username: ";
        cin >> userInput;
        cout << "Password: ";
        cin >> passInput;

        if (userInput == userBenar && passInput == passBenar) {
            loginBerhasil = true;
            cout << "\nLogin berhasil!\n";
            break;
        } else {
            percobaan++;
            cout << "Login salah! Percobaan ke-" << percobaan << endl;
        }
    }

    // ===== MENU PARKIR =====
    if (loginBerhasil) {
        int saldoKas = 50000;
        int pilihanMenu;
        int totalMasuk = 0;
        int totalKeluar = 0;
        int lamaParkir;
        char jenisKendaraan;
        char ulangMenu = 'y';
        bool biayaTetapDiproses = false;

        do {
            cout << "\n===== MENU PARKIR =====\n";
            cout << "1. Lihat Saldo Kas\n";
            cout << "2. Kendaraan Masuk\n";
            cout << "3. Kendaraan Keluar\n";
            cout << "4. Laporan Parkir\n";
            cout << "5. Biaya Tetap Parkir\n";
            cout << "6. Keluar\n";
            cout << "Pilih menu (1-6): ";
            cin >> pilihanMenu;

            switch (pilihanMenu) {

            case 1:
                cout << "Saldo kas parkir: Rp. " << saldoKas << endl;
                break;

            case 2:
                cout << "Jenis kendaraan (M = Mobil, K = Motor): ";
                cin >> jenisKendaraan;

                if (jenisKendaraan == 'M' || jenisKendaraan == 'm') {
                    saldoKas += 5000;
                    totalMasuk += 5000;
                    cout << "Mobil masuk. Biaya Rp. 5.000\n";
                }
                else if (jenisKendaraan == 'K' || jenisKendaraan == 'k') {
                    saldoKas += 2000;
                    totalMasuk += 2000;
                    cout << "Motor masuk. Biaya Rp. 2.000\n";
                }
                else {
                    cout << "Jenis kendaraan tidak valid!\n";
                }
                break;

            case 3:
                cout << "Masukkan lama parkir (jam): ";
                cin >> lamaParkir;

                int biayaKeluar;
                biayaKeluar = lamaParkir * 3000;

                if (biayaKeluar > saldoKas) {
                    cout << "Saldo kas tidak mencukupi!\n";
                } else {
                    saldoKas -= biayaKeluar;
                    totalKeluar += biayaKeluar;
                    cout << "Kendaraan keluar. Biaya Rp. " << biayaKeluar << endl;
                }
                break;

            case 4:
                cout << "\n===== LAPORAN PARKIR =====\n";
                cout << "Total uang masuk  : Rp. " << totalMasuk << endl;
                cout << "Total uang keluar : Rp. " << totalKeluar << endl;
                cout << "Saldo kas         : Rp. " << saldoKas << endl;
                break;

            case 5:
                if (!biayaTetapDiproses) {
                    saldoKas -= 10000;
                    biayaTetapDiproses = true;
                    cout << "Biaya tetap parkir Rp. 10.000 dipotong.\n";
                } else {
                    cout << "Biaya tetap sudah diproses.\n";
                }
                break;

            case 6:
                cout << "Terima kasih. Sistem parkir ditutup.\n";
                break;

            default:
                cout << "Pilihan tidak valid!\n";
            }

            if (pilihanMenu != 6) {
                cout << "\nKembali ke menu? (y/t): ";
                cin >> ulangMenu;
            }

        } while (ulangMenu == 'y' || ulangMenu == 'Y');

    } else {
        cout << "\nAkses ditolak! Login gagal 3 kali.\n";
    }

    return 0;
}
