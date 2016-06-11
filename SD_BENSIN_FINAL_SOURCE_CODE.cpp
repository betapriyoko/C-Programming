#include <iostream>
#include <windows.h>
#define maxBensin 20000 //mendefinisikan maxBensin/daya tampung tangki 20000 Liter
using namespace std;

//struktur BBM di inisialisasi dengan nama bensin, struktur ini berisi variabel totalBenisin = maxBensin yaitu 20000 Liter, dan var total jual mula mula adalah 0 Liter;
struct BBM
{
    int totalBensin=maxBensin;
    int totalJual=0;
}bensin;

//fungsi Jual mempunyai parameter _liter;
int Jual(int _liter)
{
    bensin.totalBensin=bensin.totalBensin-_liter;	//berfungsi untuk mendapatkan sisa bensin setelah terjual;
    bensin.totalJual+=_liter;	//Berfungsi untuk menambah total Jual Bensin. ketika bensin terjual, maka totalJual Bensin Akan Bertambah;
    cout<<"Bensin Telah Terjual!"<<endl; //Notifikasi Bahwa Bensin telah Terjual;
}

//fungsi isiTangki dengan Parameter _isi;
int isiTangki(int _isi)
{
    if(bensin.totalBensin+_isi>maxBensin)//akan dicek, apakah pengisian tangki melebihi Daya Tampung;
    {
    	//Jika Ya Maka
        cout<<"Stop! Tangki Sudah penuh."<<endl;//Akan Muncul notifikasi tangki Penuh !;
        cout<<"Hanya Ditambah "<<maxBensin-bensin.totalBensin<<" Liter"<<endl; 
        bensin.totalBensin=maxBensin; //karena Tangki Penuhmaka totalBensin Di atur ke 20000 Liter
    }
    else
    {
    	//Jika Tidak Maka
        bensin.totalBensin=bensin.totalBensin+_isi; //berfungsi memperoleh totaalbensin Setelah Diisi;
        cout<<"Pengisian Tangki Selesai!"<<endl;//Muncul Notifikasi Bahwa Pengisian Tangki Selesai;
    }
}
int main()
{

    int opsi,liter; //deklarasi variabel opsi dan liter;
    do
    {
         cout<<"                    .:: DATA PENJUALAN BENSIN ::. \n";
        cout<<"--------------------------------------------------------------------- \n";
        cout<<"| Harga per Liter    | Daya Tampung Tangki    |    Bensin Tersedia  |"<<endl;
        cout<<"---------------------------------------------------------------------"<<endl;
        cout<<"|      Rp.7000,00    |         20000 Liter    |      "<<bensin.totalBensin<<" Liter    |"<<endl; //Informasi harga,Daya Tampung Tangki dan TotalBensin
        cout<<"--------------------------------------------------------------------- \n";
        cout<<"                             Bensin Terjual   |      "<<bensin.totalJual<<" Liter\n"<<endl;
        cout<<"                             Hasil Penjualan  |   Rp."<<bensin.totalJual*7000<<",00"<<endl;
        cout<<"[1] Jual Bensin"<<endl;
        cout<<"[2] Isi Tangki "<<endl;
        cout<<"Masukan Pilihan :";cin>>opsi;
        switch(opsi)
        {
        case 1: //Fungsi Jual Bensin
            if(bensin.totalBensin == 0) //jika Totalbensin = 0 Liter
            {
                cout<<"Maaf, Stok Bensin Kosong."<<endl; //Muncul Notifikasi Bensin Kosong.
                system("pause");
            }
            else
            {
            	//jika total bensin >0 maka akan di suruh untuk Menginputkan berapa liter yang ingin dijual
                cout<<"Berapa Liter: ";cin>>liter;
                if(liter>bensin.totalBensin)//akan dicek apakah value liter > total Bensin , Jika Ya Maka Muncul Notifikasi Bahwa Bensin hanya tersedia ... Liter;
                {
                    cout<<"Maaf, Bensin Hanya Tersedia "<<bensin.totalBensin<<" Liter."<<endl;
                }
                else
                {
                	//jika Tidak, maka akan memanggil Fungsi Jual dengan parameter liter yang diinputkan;
                    Jual(liter);
                }
                system("pause");
            }
            break;
        case 2: //Fungsi Isi Tangki
           if(bensin.totalJual<5)// akan dicek apakah total Penjualan sudah mencapai 5 liter atau belum
           {
           	//jika Belum Maka Muncul Notifikasi
               cout<<"Tangki Tidak Dapat Diisi ! Total Penjualan bensin Belum Mencapai 5 Liter."<<endl;
               cout<<"Total Penjualan saat ini : "<<bensin.totalJual<<" Liter."<<endl;
               system("pause");
           }
           else if(bensin.totalBensin==maxBensin)
           {
           		//Jika total Penjulan lebih dari atau sama dengan 5 Liter dan tangki masih penuh, maka muncul Notifikasi ;
                cout<<"Tangki Masih Penuh!"<<endl;
                system("pause");
           }
           else
           {
           		//Jika total Penjualan lebih dari atau sama dengan 5 literdan tangki Belum Penuh, Maka akan disuruh untuk Mengisikan Berapa Liter Untuk Mengisi Tangki;
                cout<<"Berapa Liter : ";cin>>liter;
                isiTangki(liter); //Memanggil Fungsi isi Tangki dengan parameter Liter;
                system("pause");
           }
           break;
        }
        system("cls");
    }while(opsi++);
}
