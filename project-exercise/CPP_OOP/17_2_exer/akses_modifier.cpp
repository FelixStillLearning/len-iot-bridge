#include <iostream>
#include <string>
using namespace std;

class Pegawai {
public:
  string nama_pegawai;
  int usia_pegawai;

  Pegawai(string nama, int usia, double gaji) {
    nama_pegawai = nama;
    usia_pegawai = usia;
    gaji_dasar = gaji;
    bonus_tahunan = 0;
  }

  double dapatkan_ingpo_gaji() { return gaji_dasar; }

  void ingpo_pegawai() {
    cout << "=== Data Pegawai ===" << endl;
    cout << "Nama: " << nama_pegawai << endl;
    cout << "Usia: " << usia_pegawai << " tahun" << endl;
    cout << "Gaji Dasar: Rp." << gaji_dasar << endl;
    cout << "Bonus: Rp." << bonus_tahunan << endl;
    cout << "--------------------" << endl;
  }

  void atur_bonus(double bonus) {
    if (bonus >= 0) {
      bonus_tahunan = bonus;
      gaji_dasar = gaji_dasar + bonus;
      cout << "[Sistem] Bonus berhasil diatur: Rp." << bonus_tahunan << endl;
    } else {
      cout << "[Error] Bonus tidak valid!" << endl;
    }
  }

  double hitung_total_pendapatan() { return gaji_dasar + bonus_tahunan; }

private:
  double gaji_dasar;
  double bonus_tahunan;
};

int main() {
  Pegawai pegawai_pertama("Felix Angga Resky", 21, 300000);

  pegawai_pertama.ingpo_pegawai();

  pegawai_pertama.atur_bonus(20000);

  cout << "Total Pendapatan (Gaji + Bonus): Rp."
       << pegawai_pertama.hitung_total_pendapatan() << endl;

  pegawai_pertama.ingpo_pegawai();
  return 0;
}
