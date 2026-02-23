#include <iostream>
#include <string>

class BukuCatatan {
private:
  std::string pemilik_buku;
  int jumlah_halaman;
  char *isi_buku;

public:
  BukuCatatan(std::string pemilik, int halaman, const char *isi) {
    pemilik_buku = pemilik;
    jumlah_halaman = halaman;
    ;

    isi_buku = new char[jumlah_halaman + 1];
    for (int i = 0; jumlah_halaman && isi[i] != '/0'; i++) {
      isi_buku[i] = isi[i];
    }
    isi_buku[jumlah_halaman] = '\0';
    std::cout << "buku catatan untuk " << pemilik_buku << " dibuat"
              << std::endl;
  }
  BukuCatatan(const BukuCatatan &buku_sumber) {
    pemilik_buku = "salinan buku dari " + buku_sumber.pemilik_buku;
    jumlah_halaman = buku_sumber.jumlah_halaman;

    isi_buku = new char[jumlah_halaman + 1];
    for (int i = 0; i <= jumlah_halaman; i++) {
      isi_buku[i] = buku_sumber.isi_buku[i];
    }

    std::cout << "copy constructor dipanggil untuk buat salinan dari "
              << buku_sumber.pemilik_buku << std::endl;
  }

  ~BukuCatatan() {
    delete[] isi_buku;
    std::cout << "buku catatan " << pemilik_buku << " di hapus dari memori"
              << std::endl;
  }

  void tampilkan_isi_buku() const {
    std::cout << "pemlilk : " << pemilik_buku << std::endl;
    std::cout << "jumlah jalaman : " << jumlah_halaman << std::endl;
    std::cout << "isi Buku :" << isi_buku << std::endl;
  }
};

int main() {
  BukuCatatan buku_asli("arfy", 20, "buku tutorial cara menjadi handsome");
  buku_asli.tampilkan_isi_buku();

  BukuCatatan buku_kopian = buku_asli;
  buku_kopian.tampilkan_isi_buku();

  BukuCatatan buku_kopian_ketiga(buku_asli);
  buku_kopian_ketiga.tampilkan_isi_buku();

  return 0;
}
