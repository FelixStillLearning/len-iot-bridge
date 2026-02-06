# Apa itu Open DDS?

OpenDDS adalah library OpenSource C++ yang digunakna sebagai middleware atau alat untuk komunikasi antar backend.

menggunakan RTPS 

real time publish subricribe, berbeda dengan mqtt yang dimana membutuh kan sebuah server pusat untuk perpindah dahan  data, openDDS ini dia langsung tanpa ada server pusat, peer to peer antar komputer, tidak ada penggunaan IP 

OpenDDS juga menggunakan yang namanya IDL (Interface Definition Language) 

segala sesuatu di opendds dimulai dengan kesepakatan, sebelum satu baris code ditulis pun ada kesepeatakatan yang harus digunakan nah ada idl ini, seperti bahasa yang di gunakanbersama antar backend

IDL juga berperan sebagai kontrak bahasa jika ada type data yang berbeda maka idl akan langsung menolak nya

Tidak ada penggunaan konsep IP itu karena disini menggunakan konsep TOPIC, topic adalah nama data yang dipertukarkan.

di dalam rtps itu ada yang namanya Publisher dan Subscriber

1. Publisher itu penyiar atau pemberi data
2. Subscriber itu adalah sang penerima data 

publisher dan subscriber tidak perlu tau lokasi masing2 data tapi hanya memerlukan topic yang dibutuhkan saja

 perlu diingat juga publisher tidak perludi siapa yang menerima dan subscriber tidak peduli siapa yang mengirim ini disebut dengan decoupling, maka jika ada 10 komputer baru sebagai subscriber, code diposisi publisher itu tidak perlu diubah satupun.

ada hal penting juga yang dimiliki oleh OpenDDS yaitu (Discovery & RTPS) kalo tidak ada Ip addres yang dituju bagaimana datanya bisa sampai ? disinilah protokol RTPSfunsginya kelihatan, dimanan nanti disaat openDDS dijalankan ia bertindak sebagai detektif dimana ia akan mengrim sinyal ke jaringan( biasanya multi cast) halo ini ada data x, aplikasi yang ada dijaringan tersebut akan menangkap sinyal tersebut jika cocok openDDS akan membangun jaringan secara otomatis

