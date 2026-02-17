#include <iostream>
#include <ostream>
#include <string>

using namespace std;

class mobil {

private:
  string merk;
  int tahun_produksi;
  string warna;

public:
  mobil(string merek_mobil, int tahun_mobil, string warna_mobil) {
    merk = merek_mobil;
    tahun_produksi = tahun_mobil;
    warna = warna_mobil;
  }

  void nyalakan_mesin() {
    cout << "Mesin Mobil " << merk << " Hidup / menyala " << endl;
  }

  void klakson() { cout << "bim bim dari mobil " << merk << endl; }

  void ingpo_mobil() {
    cout << "Merk mobil: " << merk << endl;
    cout << "Tahun Produksi mobil: " << tahun_produksi << endl;
    cout << "Warna Mobil: " << warna << endl;
  }
};

int main() {
  mobil mobil_jaguar("jaguar sport x20", 2026, "hijau");

  mobil_jaguar.ingpo_mobil();
  mobil_jaguar.nyalakan_mesin();
  mobil_jaguar.klakson();

  return 0;
}
