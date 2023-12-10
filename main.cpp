#include <iostream>
#include "Tubes.h"
using namespace std;

int main()
{
    ListInduk LI;
    ListChild LC;
    adrchild carichild;
    adrinduk ind;
    bool antibreak = true;
    string pilih;
    int pilihint;
    string lanjut = "";
    infotype data;
    data.stats.namastat = "";
    string datasubstat = "";
    string datasubstatakhir = "";
    createListInduk(LI);
    createListChild(LC);
    data.stats.namastat = "";
    cout<<"Selamat Datang Di Program Artefak Genshin Impact!"<<endl;
    cout<<"Silakan Ikuti Instruksi dibawah Ini Untuk Menjalankan Program!"<<endl;
    cout<<"===================================="<<endl;
    while(lanjut!="stop"){
        cout<<"1. Tambah Artefak Baru (Parent)"<<endl;
        cout<<"2. Tambah Data Substats Baru (child)"<<endl;
        cin>>pilih;
        if(pilih=="1"){
            cout<<"Masukkan ID Artefak: "<<endl;
            cin>>data.id;
            cout<<"Masukkan Rarity Artefak: "<<endl;
            cin>>data.rarity;
            while(data.rarity<1 || data.rarity>5){
                cout<<"Rarity Artefak Hanya Bisa Dalam Range 1 Sampai 5"<<endl;
                cout<<"Masukkan Ulang Rarity Artefak: "<<endl;
                cin>>data.rarity;
            }
            cout<<"Masukkan Level Artefak: "<<endl;
            cin>>data.level;
            if(data.rarity==1){
                while(data.level<0||data.level>4){
                    cout<<"Level Artefak Dengan Rarity 1 Hanya Ada Dalam Range 0 Sampai 4"<<endl;
                    cout<<"Masukkan Ulang Level Artefak: "<<endl;
                    cin>>data.level;
                }
            }else if(data.rarity==2){
                while(data.level<0||data.level>8){
                    cout<<"Level Artefak Dengan Rarity 2 Hanya Ada Dalam Range 0 Sampai 8"<<endl;
                    cout<<"Masukkan Ulang Level Artefak: "<<endl;
                    cin>>data.level;
                }
            }else if(data.rarity==3){
                while(data.level<0||data.level>12){
                    cout<<"Level Artefak Dengan Rarity 3 Hanya Ada Dalam Range 0 Sampai 12"<<endl;
                    cout<<"Masukkan Ulang Level Artefak: "<<endl;
                    cin>>data.level;
                }
            }else if(data.rarity==4){
                while(data.level<0||data.level>16){
                    cout<<"Level Artefak Dengan Rarity 4 Hanya Ada Dalam Range 0 Sampai 16"<<endl;
                    cout<<"Masukkan Ulang Level Artefak: "<<endl;
                    cin>>data.level;
                }
            }else if(data.rarity==5){
                while(data.level<0||data.level>20){
                    cout<<"Level Artefak Dengan Rarity 5 Hanya Ada Dalam Range 0 Sampai 20"<<endl;
                    cout<<"Masukkan Ulang Level Artefak: "<<endl;
                    cin>>data.level;
                }
            }
            cout<<"Masukkan Piece Artefak: "<<endl;
            cin>>data.piece;
            cout<<"Masukkan Set Artefak: "<<endl;
            cin>>data.Set;
            cout<<"Masukkan Nama Main Stats Artefak: "<<endl;
            while(datasubstat!="."){
                cin>>datasubstat;
                if(data.stats.namastat!=""&&datasubstat!="."){
                    data.stats.namastat = data.stats.namastat+" "+datasubstat;
                }
                if(data.stats.namastat=="" && datasubstat!="."){
                    data.stats.namastat = datasubstat;
                }
            }
            datasubstat = "";
            cout<<"Masukkan Nilai Main Stats (Tidak Perlu Memakai %)"<<endl;
            cin>>data.stats.angka;
            if(data.rarity==1){
                cout<<"Masukkan Nama Substats 1 Artefak: "<<endl;
                while(datasubstat!="."){
                    cin>>datasubstat;
                    if(datasubstatakhir!=""&&datasubstat!="."){
                        datasubstatakhir = datasubstatakhir+" "+datasubstat;
                    }
                    if(datasubstatakhir=="" && datasubstat!="."){
                        datasubstatakhir = datasubstat;
                    }
                }
                carichild = searchChild(LC,datasubstatakhir);
                if(carichild==NULL){
                cout<<"Gagal Menambahkan Artefak Karena Nama Substat Tidak Valid"<<endl;
                }else{
                    cout<<"Masukkan Nilai Substat 1: "<<endl;
                    cin>>data.substats1;
                    data.substats2 = 0;
                    data.substats3 = 0;
                    data.substats4 = 0;
                    ind = createElementInduk(data);
                    cout<<"1. Insert First"<<endl;
                    cout<<"2. Insert Last"<<endl;
                    cin>>pilihint;
                    while(pilihint<1 || pilihint>2){
                        cout<<"Masukkan Opsi Dengan Benar!"<<endl;
                        cout<<"1. Insert First"<<endl;
                        cout<<"2. Insert Last"<<endl;
                        cin>>pilihint;
                    }
                    if(pilihint==1){
                        insertFirstInduk(LI,ind);
                    }else if(pilihint==2){
                        insertLastInduk(LI, ind);
                    }
                    hubungkanIndukChild(LI,LC,data.id,datasubstatakhir);
                }
            }
            datasubstat = "";
            data.stats.namastat = "";
            datasubstatakhir = "";
            antibreak = true;
            pilih = "999123999";
            data.stats.namastat = "";
            pilihint = 999123999;
        }else if(data.rarity == 2){
            cout<<"Masukkan Substats 2 Artefak: "<<endl;
            cout<<"Masukkan Substats 3 Artefak: "<<endl;
            cout<<"Masukkan Substats 4 Artefak: "<<endl;
        }else if(pilih=="2"){
            cout<<"Masukkan Nama Substats: "<<endl;
            while(datasubstat!="."){
                cin>>datasubstat;
                if(datasubstatakhir!=""&&datasubstat!="."){
                    datasubstatakhir = datasubstatakhir+" "+datasubstat;
                }
                if(datasubstatakhir=="" && datasubstat!="."){
                    datasubstatakhir = datasubstat;
                }
            }
            datasubstat = "";
            cout<<datasubstatakhir<<endl;
            if(!adaChild(LC,datasubstatakhir)){
                cout<<"1. Insert First"<<endl;
                cout<<"2. Insert Last"<<endl;
                cin>>pilihint;
                while(pilihint<1 || pilihint>2){
                    cout<<"Masukkan Opsi Dengan Benar!"<<endl;
                    cout<<"1. Insert First"<<endl;
                    cout<<"2. Insert Last"<<endl;
                    cin>>pilihint;
                }
                if(pilihint==1){
                    insertFirstChild(LC,createElementChild(datasubstatakhir));
                }else if(pilihint==2){
                    insertLastChild(LC,createElementChild(datasubstatakhir));
                }
                pilihint = 999123999;
            }
            datasubstatakhir = "";
        }else if(pilih=="3"){
            showAllInduk(LI);
        }else if(pilih=="4"){
            showAllIndukChild(LI,LC);
        }
        cout<<"SHOW ALL CHILD"<<endl;
        cout<<"============================"<<endl;
        showAllChild(LC);
        cout<<"Ketik Apapun Untuk Melanjutkan Program atau Ketik stop Untuk Keluar dari Program"<<endl;
        cin>>lanjut;
    }


}
