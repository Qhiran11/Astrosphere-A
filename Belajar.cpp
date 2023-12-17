//Qhiran
#include <iostream>
using namespace std;

char ulang;
string warna;
string size;
int harga;
int uang;
int kembalian;
int total_barang = 0;
int stok1 = 15, stok2 = 25, stok3 = 20;
int pilihan = 0;

void pengguna();
void menu();
void fashion();
void tampilanstok();
void tambahstok();
void kurangstok();

// Fungsi untuk membeli fashion item
void beliBarang(string nama_barang, int &stok_barang, int harga_barang) {
    int jumlah_barang;
    cout << "Stok " << nama_barang << " saat ini : " << stok_barang << " pasang\n";
    cout << "Harga : Rp" << harga_barang << "\n";
    cout << "Warna : ";
    cin >> warna;
    cout << "Size : ";
    cin >> size;
    cout << "Jumlah barang : ";
    cin >> jumlah_barang;

    harga = jumlah_barang * harga_barang;
    if (jumlah_barang > 0 && jumlah_barang <= stok_barang) {
        stok_barang -= jumlah_barang;
        total_barang += jumlah_barang;
        cout << "Anda membeli " << nama_barang << " dengan warna " << warna << " dan ukuran " << size <<
            " sebanyak " << jumlah_barang << " pasang\n";
        cout << "Total = Rp" << harga << endl;
    } else {
        cout << "\nStok tidak mencukupi atau jumlah tidak valid.\n";
    }
}

// Fungsi untuk menambah stok barang (opsi admin)
void tambahStok(string nama_barang, int &stok_barang) {
    int tambahan_stok;
    cout << "Masukkan jumlah stok yang ingin ditambahkan untuk " << nama_barang << " : ";
    cin >> tambahan_stok;

    if (tambahan_stok > 0) {
        stok_barang += tambahan_stok;
        cout << "Stok " << nama_barang << " berhasil ditambahkan sebanyak " << tambahan_stok << " pasang.\n";
        cout << "Stok " << nama_barang << " saat ini : " << stok_barang << " pasang\n";
    } else {
        cout << "Jumlah yang dimasukkan tidak valid.\n";
    }
}

// Fungsi untuk menampilkan stok barang
void tampilkanStok(string nama_barang, int stok_barang) {
    cout << "Stok " << nama_barang << " saat ini\t: " << stok_barang << " pasang\n";
}

// Fungsi untuk memproses pembelian
void prosesPembelian() {
	int total = 0;
	while (pilihan != 3){
    system ("cls");
    cout << "-SELAMAT DATANG-\nDI FASHION TEKNIK\n\n";
    cout << "Anda adalah seorang pelanggan\n\n";
    int pil;
    do {
        cout << "Pilihlah fashion yang anda inginkan :\n1. Sepatu\n2. Baju\n3. Celana";
         cout << "\n\nMasukkan Pilihan : ";cin >> pil;
        switch (pil) {
            case 1:
                    beliBarang("Sepatu", stok1, 250000);
                    total += harga; // Tambahkan harga ke total
                    break;
            case 2:
                    beliBarang("Baju", stok2, 100000);
                    total += harga; // Tambahkan harga ke total
                    break;
            case 3:
                    beliBarang("Celana", stok3, 100000);
                    total += harga; // Tambahkan harga ke total
                    break;
            default:
                    cout << "Inputan tidak valid!!\n";
                    break;
            }
        cout << "\nApakah anda ingin memilih barang lain (y/t)?\nJawaban Anda : ";
        cin >> warna;
    } while (warna != "t");

    cout << "\n\nTotal jumlah Barang yang Dibeli : " << total_barang << " barang\n";
    cout << "Total harga barang yang dibeli : " << total << " barang\n";
    cout << "\nMasukkan jumlah uang anda : ";
    lagi :
    cin >> uang;
    kembalian = uang - total;
    if (uang < total){cout << "\nJumlah uang tidak cukup !!\nMasukkan uang Lagi : ";goto lagi;}
        else if ( uang >= total){ cout << "\nKembalian anda : " << kembalian << endl;
                    cout << "\nTerima Kasih Telah Berbelanja";}

                cout << "\n\nPermintaan Selesai\n";
                awal2 :
                cout << "1. Akhiri Program\n";
                cout << "2. Kembali Ke menu sebelumnya\n";
                cout << "3. Kembali Ke Login\n";
                cout << "\nPilihan Anda : ";cin >>pilihan;
                switch (pilihan){
                case 1 :
                    cout<<"\nProgram Berakhir :)\n\n";
                    break;
                case 2 :
                    system ("cls");
                    cout << "-SELAMAT DATANG-\nDI FASHION TEKNIK\n\n";
                    prosesPembelian();
                    break;
                case 3 :
                    system ("cls");
                    pengguna ();
                    break;

                default:
                    cout << "\nInputan tidak valid, Masukkan pilihan lagi !!\n";
                    goto awal2;
                    break;
            }
}
}

void pengguna (){

	while (pilihan != 2){
    cout << "-SELAMAT DATANG-\nDI FASHION TEKNIK\n\n";
    awal :
    cout << " 1. Admin \n";
    cout << " 2. Pelanggan \n";
    cout << "Tentukan pilihan anda : ";
    cin >> pilihan;


	switch (pilihan)
	{
    	case 1 :
	        awal4 :
	        cout << "\nAnda adalah seorang admin\n";
	        cout << "\nMenu Admin:\n";
	        awal1 :
	        cout << "1. Tambah Stok Sepatu\n";
	        cout << "2. Tambah Stok Baju\n";
	        cout << "3. Tambah Stok Celana\n";
	        cout << "4. Tampilan Stok\n";

	        int opsi_admin;
	        cout << "\nPilih opsi admin : ";
	        cin >> opsi_admin;

                            switch (opsi_admin) {
                                case 1:
                                    tambahStok("Sepatu ", stok1);
                                    cout << endl;
                                    goto awal3;
                                    break;
                                case 2:
                                    tambahStok("Baju ", stok2);
                                    cout << endl;
                                    goto awal3;
                                    break;
                                case 3:
                                    tambahStok("Celana ", stok3);
                                    cout << endl;
                                    goto awal3;
                                    break;
                                case 4:
                                    tampilkanStok("Sepatu", stok1);
                                    tampilkanStok("Baju", stok2);
                                    tampilkanStok("Celana", stok3);
                                    goto awal3;
                                    break;
                                default:
                                    cout << "\nInputan tidak valid, Masukkan pilihan lagi !!\n";
                                    goto awal1;
                                    break;
                                }
                awal3 :
                cout << "\nPermintaan Selesai\n";
                awal2 :
                cout << "1. Akhiri Program\n";
                cout << "2. Kembali Ke menu sebelumnya\n";
                cout << "3. Kembali Ke menu Login\n";
                cout << "\nPilihan Anda : ";cin >>pilihan;
                switch (pilihan){
                case 1 :
                    cout<<"\nProgram Berakhir :)\n\n";
                    break;
                case 2 :
                    system ("cls");
                    cout << "-SELAMAT DATANG-\nDI FASHION TEKNIK\n\n";
                    goto awal4;
                    break;
                case 3 :
                    system ("cls");
                    pengguna ();
                    break;

                default:
                    cout << "\nInputan tidak valid, Masukkan pilihan lagi !!\n";
                    goto awal2;
                    break;
            }

	        break;
    	case 2 :
        	prosesPembelian();
        	break;
    	default :
        	cout << "Nilai yang anda masukkan salah\n\nMasukkan pilihan lagi !!\n";
        	goto awal;
        	break;
	}

            if (pilihan != 2) {
                cin.ignore();
                cin.get();
            }
	break;

    }
}

int main() {
    pengguna ();
    return 0;
}
