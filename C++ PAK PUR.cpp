#include <iostream>
#include <string>
using namespace std;

struct Jabatan {
    double gaji;
    double tunjangan;
    double potongan;
};

Jabatan direktur = { 10000000, 5000000, 0.07 };
Jabatan manager = { 7500000, 4000000, 0.05 };
Jabatan staff = { 5000000, 2000000, 0.02 };

double potonganGaji(double gaji, double tunjangan, double potongan, int cuti) {
    double gajitotal = gaji + tunjangan;
    double fee_cuti = (gajitotal * potongan) * (cuti / 30.0);
    double fixsalary = gajitotal - fee_cuti;
    return fixsalary;
}

void dataPegawai(string nama, string role, int cuti) {
    Jabatan jabatan;
    if (role == "Direktur") {
        jabatan = direktur;
    }    else if (role == "Manager") {
        jabatan = manager;
    }
    else if (role == "Staff") {
        jabatan = staff;
    }
    else {
        cout << "[System] Jabatan tidak valid." << endl;
        return;
    }

    double fixsalary = potonganGaji(jabatan.gaji, jabatan.tunjangan, jabatan.potongan, cuti);

    cout << "Nama: " << nama << endl;
    cout << "Jabatan: " << role << endl;
    cout << "Gaji Pokok: " << jabatan.gaji << endl;
    cout << "Tunjangan: " << jabatan.tunjangan << endl;
    cout << "Total Gaji Bulanan: " << fixsalary << endl;
    cout << "Jumlah Cuti: " << cuti << " Hari/30 Hari" << endl;
    cout << "Gaji Diterima: " << fixsalary << endl;
}

int main() {
    string nama;
    string role;
    int cuti;
    
    cout << "Rizki Ramadhan X-XPL\n";
    cout << "\n";
    cout << "MENGHITUNG GAJI KARYAWAN\n";
    cout << "\n";
    cout << "\n";

    cout << "[System] Masukkan Nama Karyawan: ";
    cin >> nama;
    cout << "[System] Masukkan Jabatannya (Direktur/Manager/Staff): ";
    cin >> role;
    cout << "[System] Jumlah Cuti: ";
    cin >> cuti;

    dataPegawai(nama, role, cuti);
    
    return 0;
}

