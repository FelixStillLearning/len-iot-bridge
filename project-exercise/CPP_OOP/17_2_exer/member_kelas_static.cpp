#include <iostream>
#include <string>

using namespace std;

// factory method
class Mahasiswa {

public:
  Mahasiswa(string nama, int nim) {
    nama_mahasiswa = nama;
    nim_mahasiswa = nim;

    jumlah_total_mahasiswa++;
    cout << "nama mahasiswa: " << nama_mahasiswa << "sudah terdaftar " << endl;
  }
  // getter
  void ingfo_mahasiswa() {
    cout << "nama_mahasiswa adalah: " << nama_mahasiswa << endl;
    cout << "nim mahasiswa adalah: " << nim_mahasiswa << endl;
    cout << "universitas mahasiswa adalah : " << nama_universitas << endl;
  }
  // setter
  static void atur_nama_universitas(string nama) {
    nama_universitas = nama;
    cout << "nama universitas tekah diubah menjadi" << nama_universitas << endl;
  }
  // static member function
  static int ingfo_jumlah_mahasiswa() { return jumlah_total_mahasiswa; }

  // static member function
  static void tampilkan_info_kampus() {
    cout << "nama kampus adalah: " << nama_universitas << endl;
    cout << "jumlah mahasiswa di kampus tersebut adalah : "
         << jumlah_total_mahasiswa << endl;
  }

private:
  int nim_mahasiswa;
  string nama_mahasiswa;

  static int jumlah_total_mahasiswa;
  static string nama_universitas;
};

int Mahasiswa::jumlah_total_mahasiswa = 0;
string Mahasiswa::nama_universitas = "Itenas kampus kebanggan";

int main() {
  Mahasiswa::tampilkan_info_kampus();

  cout << endl;

  Mahasiswa mahasiswa_pertama("Felix", 152023148);
  Mahasiswa mahasiswa_kedua("julian", 15023223);
  Mahasiswa mahasiswa_ketiga("chandra", 152023144);

  cout << endl;

  Mahasiswa::atur_nama_universitas("ITB");

  cout << endl;

  mahasiswa_pertama.ingfo_mahasiswa();

  cout << endl;
  Mahasiswa::tampilkan_info_kampus();
  return 0;
}
