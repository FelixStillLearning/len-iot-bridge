#include <iostream>
#include <string>
using namespace std;

class Mahasiswa {
public:
  Mahasiswa(string nama, int nomor_induk, double ipk, int sks) {
    nama_mahasiswa = nama;
    nim = nomor_induk;
    nilai_ipk = ipk;
    jumlah_sks = sks;
  }
  void Ingfo_Mahasiswa() {
    cout << "nama " << nama_mahasiswa << endl;
    cout << "nim " << nim << endl;
    cout << "nilai_ipk " << nilai_ipk << endl;
    cout << "jumlah_sks " << jumlah_sks << endl;
  }

  bool apakah_lulus() {
    if (nilai_ipk >= 2.0) {
      return true;
    } else {
      return false;
    }
  }

  void tambah_sks(int sks_tambahan) {
    jumlah_sks += sks_tambahan;
    cout << "sks sudah ditambahkan, totakl sks sekarang adalah: " << jumlah_sks
         << endl;
  }

  string dapatkan_predikat() {
    if (nilai_ipk >= 3.5) {
      return "kamu sudah cumlaude";
    } else if (nilai_ipk >= 3.0) {
      return "nilai kamu memuaskan";
    } else {
      return "nilai kamu sudah cukup";
    }
  }
  // assessor
  string ingpo_nama_mahasiswa() { return nama_mahasiswa; }
  int ingfo_jumlah_sks_mahasiswa() { return jumlah_sks; }
  double ingfo_ipk_dari_mahasiswa() { return nilai_ipk; }

  void atur_nilai_ipk(double nilai_baru) { nilai_ipk = nilai_baru; }

private:
  string nama_mahasiswa;
  int nim;
  double nilai_ipk;
  int jumlah_sks;
};

int main() {
  Mahasiswa mahasiswa_pertama("james_mono", 152023148, 3.75, 110);
  Mahasiswa mahasiswa_kedua("Felix Angga", 152023144, 4.00, 120);

  mahasiswa_pertama.Ingfo_Mahasiswa();

  cout << "status kelulusan "
       << (mahasiswa_pertama.apakah_lulus() ? "lulus" : "tidak lulus") << endl;
  mahasiswa_pertama.tambah_sks(90);

  cout << "nama Mahasiswa adalah: " << mahasiswa_pertama.ingpo_nama_mahasiswa()
       << endl;

  cout << "jumlah sks mahasiswa adalah: "
       << mahasiswa_pertama.ingfo_jumlah_sks_mahasiswa() << endl;

  mahasiswa_kedua.tambah_sks(70);
  cout << "jumlah sksdari si felix adalah : "
       << mahasiswa_kedua.ingfo_jumlah_sks_mahasiswa() << endl;

  cout << "status predikat dari nama "
       << mahasiswa_pertama.ingpo_nama_mahasiswa() << " dengan predikat"
       << mahasiswa_pertama.dapatkan_predikat() << endl;

  cout << "ipk sebelum di ganti "
       << mahasiswa_pertama.ingfo_ipk_dari_mahasiswa()
       << mahasiswa_pertama.ingpo_nama_mahasiswa() << endl;

  mahasiswa_pertama.atur_nilai_ipk(3.53);
  mahasiswa_pertama.ingpo_nama_mahasiswa();
  mahasiswa_pertama.Ingfo_Mahasiswa();

  return 0;
}
