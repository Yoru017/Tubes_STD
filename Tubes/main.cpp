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
    string idArtef;
    string idArtefBuatCari;
    string namaSubstatBuatCari;
    int pilihint;
    string lanjut = "";
    infotype data;
    data.stats.namastat = "";
    string datasubstat = "";
    string datasubstatakhir = "";
    string datasubstatakhir2 = "";
    string datasubstatakhir3 = "";
    string datasubstatakhir4 = "";
    createListInduk(LI);
    createListChild(LC);
    data.stats.namastat = "";
    cout<<"Selamat Datang Di Program Artefak Genshin Impact!"<<endl;
    cout<<"Silakan Ikuti Instruksi dibawah Ini Untuk Menjalankan Program!"<<endl;
    cout<<"===================================="<<endl;
    while(lanjut!="stop"){
        cout<<"1. Tambah Artefak Baru (Parent)"<<endl;
        cout<<"2. Tambah Data Substats Baru (child)"<<endl;
        cout<<"3. Lihat Semua Artefak Yang Terdaftar (Show All Induk)"<<endl;
        cout<<"4. Lihat Semua Artefak Yang Terdaftar Beserta Substats nya (Show All Induk with Child)"<<endl;
        cout<<"5. Hapus Data Artefak Beserta Relasinya"<<endl;
        cout<<"6. Cari Artefak (Parent)"<<endl;
        cout<<"7. Cari Child"<<endl;
        cout<<"8. Cari Data Child Pada Artefak"<<endl;
        cout<<"9. Hapus Data Child Pada Artefak Tertentu"<<endl;
        cout<<"10. Hitung Banyak Child Pada Artefak Tertentu"<<endl;
        cout<<"<=> Ketik Apasaja Selain Opsi Diatas Untuk Keluar Dari Program <=>"<<endl;
        cin>>pilih;
        if(pilih=="1"){
            cout<<"Masukkan ID Artefak: "<<endl;
            cin>>data.id;
            while(cekID(LI,data.id)){
                cout<<"Sudah Ada Artefak Dengan ID "<<data.id<<endl;
                cout<<"Masukkan Ulang ID Artefak: ";
                cin>>data.id;
            }
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
            }else if(data.rarity == 2){
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
                    data.substats3 = 0;
                    data.substats4 = 0;
                    cout<<"Masukkan Nama Substats 2 Artefak: "<<endl;
                    datasubstat = "";
                    while(datasubstat!="."){
                        cin>>datasubstat;
                        if(datasubstatakhir2!=""&&datasubstat!="."){
                            datasubstatakhir2 = datasubstatakhir2+" "+datasubstat;
                        }
                        if(datasubstatakhir2=="" && datasubstat!="."){
                            datasubstatakhir2 = datasubstat;
                        }
                    }
                    carichild = searchChild(LC,datasubstatakhir2);
                    if (carichild == NULL){
                        cout<<"Gagal Menambahkan Artefak Karena Nama Substat Tidak Valid"<<endl;
                    }else{
                        cout<<"Masukkan Nilai Substats 2: "<<endl;
                        cin>>data.substats2;
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
                        hubungkanIndukChild(LI,LC,data.id,datasubstatakhir2);
                    }
                }
            }else if(data.rarity == 3){
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
                    data.substats4 = 0;
                    cout<<"Masukkan Nama Substats 2 Artefak: "<<endl;
                    datasubstat = "";
                    while(datasubstat!="."){
                        cin>>datasubstat;
                        if(datasubstatakhir2!=""&&datasubstat!="."){
                            datasubstatakhir2 = datasubstatakhir2+" "+datasubstat;
                        }
                        if(datasubstatakhir2=="" && datasubstat!="."){
                            datasubstatakhir2 = datasubstat;
                        }
                    }
                    carichild = searchChild(LC,datasubstatakhir2);
                    if (carichild == NULL){
                        cout<<"Gagal Menambahkan Artefak Karena Nama Substat Tidak Valid"<<endl;
                    }else{
                        cout<<"Masukkan Nilai Substats 2: "<<endl;
                        cin>>data.substats2;
                        cout<<"Masukkan Nama Substats 3 Artefak: "<<endl;
                        datasubstat = "";
                        while(datasubstat!="."){
                            cin>>datasubstat;
                            if(datasubstatakhir3!=""&&datasubstat!="."){
                                datasubstatakhir3 = datasubstatakhir3+" "+datasubstat;
                            }
                            if(datasubstatakhir3=="" && datasubstat!="."){
                                datasubstatakhir3 = datasubstat;
                            }
                        }
                        carichild = searchChild(LC,datasubstatakhir3);
                        if (carichild == NULL){
                            cout<<"Gagal Menambahkan Artefak Karena Nama Substat Tidak Valid"<<endl;
                        }else{
                            cout<<"Masukkan Nilai Substats 3: "<<endl;
                            cin>>data.substats3;
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
                            hubungkanIndukChild(LI,LC,data.id,datasubstatakhir2);
                            hubungkanIndukChild(LI,LC,data.id,datasubstatakhir3);
                        }
                    }
                }
            }else if(data.rarity == 4 || data.rarity == 5){
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
                    cout<<"Masukkan Nama Substats 2 Artefak: "<<endl;
                    datasubstat = "";
                    while(datasubstat!="."){
                        cin>>datasubstat;
                        if(datasubstatakhir2!=""&&datasubstat!="."){
                            datasubstatakhir2 = datasubstatakhir2+" "+datasubstat;
                        }
                        if(datasubstatakhir2=="" && datasubstat!="."){
                            datasubstatakhir2 = datasubstat;
                        }
                    }
                    carichild = searchChild(LC,datasubstatakhir2);
                    if (carichild == NULL){
                        cout<<"Gagal Menambahkan Artefak Karena Nama Substat Tidak Valid"<<endl;
                    }else{
                        cout<<"Masukkan Nilai Substats 2: "<<endl;
                        cin>>data.substats2;
                        cout<<"Masukkan Nama Substats 3 Artefak: "<<endl;
                        datasubstat = "";
                        while(datasubstat!="."){
                            cin>>datasubstat;
                            if(datasubstatakhir3!=""&&datasubstat!="."){
                                datasubstatakhir3 = datasubstatakhir3+" "+datasubstat;
                            }
                            if(datasubstatakhir3=="" && datasubstat!="."){
                                datasubstatakhir3 = datasubstat;
                            }
                        }
                        carichild = searchChild(LC,datasubstatakhir3);
                        if (carichild == NULL){
                            cout<<"Gagal Menambahkan Artefak Karena Nama Substat Tidak Valid"<<endl;
                            cout<<datasubstatakhir3<<endl;
                        }else{
                            cout<<"Masukkan Nilai Substats 3: "<<endl;
                            cin>>data.substats3;
                            cout<<"Masukkan Nama Substats 4 Artefak: "<<endl;
                            datasubstat = "";
                            while(datasubstat!="."){
                                cin>>datasubstat;
                                if(datasubstatakhir4!=""&&datasubstat!="."){
                                    datasubstatakhir4 = datasubstatakhir4+" "+datasubstat;
                                }
                                if(datasubstatakhir4=="" && datasubstat!="."){
                                    datasubstatakhir4 = datasubstat;
                                }
                            }
                            carichild = searchChild(LC,datasubstatakhir4);
                            if (carichild==NULL){
                                cout<<"Gagal Menambahkan Artefak Karena Nama Substat Tidak Valid"<<endl;
                            }else{
                                cout<<"Masukkan Nilai Substats 4: "<<endl;
                                cin>>data.substats4;
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
                                hubungkanIndukChild(LI,LC,data.id,datasubstatakhir2);
                                hubungkanIndukChild(LI,LC,data.id,datasubstatakhir3);
                                hubungkanIndukChild(LI,LC,data.id,datasubstatakhir4);
                            }
                        }
                    }
                }
            }
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
        }else if(pilih=="5"){
            if(LI.first==NULL){
                cout<<"List Artefak Kosong"<<endl;
            }else{
                cout<<"Masukkan ID Artefak yang Akan Dihapus: ";
                antibreak = true;
                cin>>idArtef;
                while(searchInduk(LI,idArtef)==NULL && antibreak){
                    cout<<"Artefak Dengan ID "<<idArtef<<" Tidak Ditemukan"<<endl;
                    cout<<"Silahkan Pilih Opsi Berikut"<<endl;
                    cout<<"1. Masukkan Ulang ID"<<endl;
                    cout<<"2. Batalkan Hapus Artefak"<<endl;
                    cin>>pilih;
                    while(!(pilih=="1" || pilih=="2")){
                        cout<<"Mohon Masukkan Opsi dengan benar!"<<endl;
                        cout<<"1. Masukkan Ulang ID"<<endl;
                        cout<<"2. Batalkan Hapus Artefak"<<endl;
                        cin>>pilih;
                    }
                    if(pilih=="1"){
                        cout<<"Masukkan ID Artefak yang Akan Dihapus: ";
                        cin>>idArtef;
                    }else if(pilih == "2"){
                        cout<<"Berhasil Membatalkan Hapus Artefak"<<endl;
                        antibreak = false;
                    }
                }
                if(antibreak){
                deleteIndukDanRelasi(LI,idArtef);
                cout<<"Artefak Dengan ID "<<idArtef<<" Berhasil Dihapus"<<endl;
                }
            }
        }else if(pilih=="6"){
            cout<<"Masukkan ID Artefak yang Akan Dicari: ";
            cin>>idArtefBuatCari;
            if(searchInduk(LI, idArtefBuatCari)!=NULL){
                cout<<"============================"<<endl;
                cout<<"Artefak Ditemukan Pada Element Ke "<<indeksInduk(LI,idArtefBuatCari)<<endl;
                cout<<"Artefak Berada Pada Alamat "<<searchInduk(LI,idArtefBuatCari)<<endl;
                cout<<"============================"<<endl;
            }else{
                if(LI.first==NULL){
                    cout<<"List Data Artefak Kosong"<<endl;
                    cout<<"============================"<<endl;
                }else{
                    cout<<"Data Artefak Tidak Ditemukan Pada List Parent"<<endl;
                    cout<<"============================"<<endl;
                }
            }
            idArtefBuatCari = "";
        }else if(pilih=="7"){
            datasubstat = "";
            datasubstatakhir = "";
            cout<<"Masukkan Nama Child yang Akan Dicari: ";
            while(datasubstat!="."){
                cin>>datasubstat;
                if(datasubstatakhir!=""&&datasubstat!="."){
                    datasubstatakhir = datasubstatakhir+" "+datasubstat;
                }
                if(datasubstatakhir=="" && datasubstat!="."){
                    datasubstatakhir = datasubstat;
                }
            }
            if(searchChild(LC,datasubstatakhir)!=NULL){
                cout<<"============================"<<endl;
                cout<<"Child Ditemukan Pada Element Ke "<<indeksChild(LC,datasubstatakhir)<<endl;
                cout<<"Child Berada Pada Alamat "<<searchChild(LC, datasubstatakhir)<<endl;
                cout<<"============================"<<endl;
            }else{
                if(LC.first==NULL){
                    cout<<"List Data Child Kosong"<<endl;
                    cout<<"============================"<<endl;
                }else{
                    cout<<"Data Child Tidak Ditemukan Pada List Child"<<endl;
                    cout<<"============================"<<endl;
                }
            }
            datasubstat = "";
            datasubstatakhir = "";
        }else if(pilih == "8"){
            cout<<"Masukkan Child Yang Akan Dicari: ";
            datasubstat = "";
            datasubstatakhir = "";
            while(datasubstat!="."){
                cin>>datasubstat;
                if(datasubstatakhir!=""&&datasubstat!="."){
                    datasubstatakhir = datasubstatakhir+" "+datasubstat;
                }
                if(datasubstatakhir=="" && datasubstat!="."){
                    datasubstatakhir = datasubstat;
                }
            }
            if(searchChild(LC,datasubstatakhir)==NULL){
                if(LC.first==NULL){
                    cout<<"List Data Child Kosong"<<endl;
                    cout<<"============================"<<endl;
                }else{
                    cout<<"Data Child Tidak Ada Didalam List Child"<<endl;
                    cout<<"============================"<<endl;
                }
            }else{
                cout<<"Masukkan ID Artefak yang Akan Dicari Childnya: ";
                cin>>idArtefBuatCari;
                if(searchInduk(LI, idArtefBuatCari)==NULL){
                    if(LI.first==NULL){
                        cout<<"List Data Artefak Kosong"<<endl;
                        cout<<"============================"<<endl;
                    }else{
                        cout<<"Data Artefak Dengan ID "<<idArtefBuatCari<<" Tidak Ditemukan"<<endl;
                        cout<<"============================"<<endl;
                    }
                }else{
                    if(findChildInParent(LI,LC,idArtefBuatCari,datasubstatakhir)){
                        cout<<"Terdapat Child "<<datasubstatakhir<<" didalam Artefak Dengan ID "<<idArtefBuatCari<<endl;
                    }else{
                        cout<<"Tidak Ada Child "<<datasubstatakhir<<" didalam Artefak Dengan ID "<<idArtefBuatCari<<endl;
                    }
                }
            }
        }else if(pilih=="9"){
            cout<<"Masukkan Child Yang Akan Dihapus: ";
            datasubstat = "";
            datasubstatakhir = "";
            while(datasubstat!="."){
                cin>>datasubstat;
                if(datasubstatakhir!=""&&datasubstat!="."){
                    datasubstatakhir = datasubstatakhir+" "+datasubstat;
                }
                if(datasubstatakhir=="" && datasubstat!="."){
                    datasubstatakhir = datasubstat;
                }
            }
            if(searchChild(LC,datasubstatakhir)==NULL){
                if(LC.first==NULL){
                    cout<<"List Data Child Kosong"<<endl;
                    cout<<"============================"<<endl;
                }else{
                    cout<<"Data Child Tidak Ada Didalam List Child"<<endl;
                    cout<<"============================"<<endl;
                }
            }else{
                cout<<"Masukkan ID Artefak yang Akan Dihapus Child "<<datasubstatakhir<<" nya: ";
                cin>>idArtefBuatCari;
                if(searchInduk(LI, idArtefBuatCari)==NULL){
                    if(LI.first==NULL){
                        cout<<"List Data Artefak Kosong"<<endl;
                        cout<<"============================"<<endl;
                    }else{
                        cout<<"Data Artefak Dengan ID "<<idArtefBuatCari<<" Tidak Ditemukan"<<endl;
                        cout<<"============================"<<endl;
                    }
                }else{
                    if(findChildInParent(LI,LC,idArtefBuatCari,datasubstatakhir)){
                        deleteChildDariInduk(LI,LC,idArtefBuatCari,datasubstatakhir);
                        cout<<"Data Child "<<datasubstatakhir<<" Pada Artefak dengan ID "<<idArtefBuatCari<<" Berhasil Dihapus"<<endl;
                    }else{
                        cout<<"Gagal Menghapus Child Pada Artefak!"<<endl;
                        cout<<"Tidak Ada Child "<<datasubstatakhir<<" didalam Artefak Dengan ID "<<idArtefBuatCari<<endl;
                    }
                }
            }
        }else if(pilih=="10"){
            cout<<"Masukkan ID Artefak yang Akan Dihitung Banyak Childnya: ";
                cin>>idArtefBuatCari;
                if(searchInduk(LI, idArtefBuatCari)==NULL){
                    if(LI.first==NULL){
                        cout<<"List Data Artefak Kosong"<<endl;
                        cout<<"============================"<<endl;
                    }else{
                        cout<<"Data Artefak Dengan ID "<<idArtefBuatCari<<" Tidak Ditemukan"<<endl;
                        cout<<"============================"<<endl;
                    }
                }else{
                    cout<<"Banyak Child Pada Artefak Dengan ID "<<idArtefBuatCari<<" adalah "<<banyakDataChild(LI,LC,idArtefBuatCari)<<endl;
                }
        }else{
            lanjut = "stop";
        }
        if(lanjut!="stop"){
            cout<<"Ketik Apapun Untuk Melanjutkan Program atau Ketik stop Untuk Keluar dari Program"<<endl;
            cin>>lanjut;
        }
        datasubstat = "";
        data.stats.namastat = "";
        datasubstatakhir = "";
        datasubstatakhir2 = "";
        datasubstatakhir3 = "";
        datasubstatakhir4 = "";
        antibreak = true;
        pilih = "999123999";
        data.stats.namastat = "";
        pilihint = 999123999;
    }
}
