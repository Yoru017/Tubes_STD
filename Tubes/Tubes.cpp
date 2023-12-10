#include <iostream>
#include "Tubes.h"
using namespace std;

void createListInduk(ListInduk &LI){
    LI.first = NULL;
}

void createListChild(ListChild &LC){
    LC.first = NULL;
}

adrinduk createElementInduk(infotype data){
    adrinduk ind = new ElementInduk;
    ind->info = data;
    ind->nextchild = NULL;
    ind->nextinduk = NULL;
    return ind;
}

adrchild createElementChild(string x){
    adrchild chi = new ElementChild;
    chi->info = x;
    chi->next = NULL;
    return chi;
}

//adrpointerchild createElementPointerChild(ListChild LC, string x){
//    adrchild chi = LC.first;
//    adrpointerchild pchi = new ElementPointerChild;
//    if (chi==NULL){
//        cout<<"List Data Child Kosong"<<endl;
//        return NULL;
//    }
//    while(chi!=NULL){
//        if(chi->info == x){
//            pchi->info = chi;
//            pchi->next = NULL;
//            return pchi;
//        }
//        chi = chi->next;
//    }
//    return NULL;
//}

void insertFirstInduk(ListInduk &LI, adrinduk ind){
    ind->nextinduk = LI.first;
    LI.first = ind;
}

void insertLastInduk(ListInduk &LI, adrinduk ind){
    adrinduk p = LI.first;
    if(p==NULL){
        LI.first = ind;
    }else{
        while(p->nextinduk!=NULL){
            p = p->nextinduk;
        }
        p->nextinduk = ind;
    }
}

void showAllInduk(ListInduk LI){
    int i = 1;
    adrinduk p = LI.first;
    if(p==NULL){
        cout<<"List Data Parent Kosong"<<endl;
    }else{
        while(p!=NULL){
            cout<<""<<endl;
            cout <<"List Data Parent Ke "<<i<<" :";
            cout<<"ID Artefak: "<<p->info.id<<endl;
            cout<<"Level Artefak: "<<p->info.level<<endl;
            cout<<"Piece: "<<p->info.piece<<endl;
            cout<<"Set: "<<p->info.Set<<endl;
            cout<<"Rarity: "<<p->info.rarity<<endl;
            cout<<"Main Stat: "<<p->info.stats.namastat<<" "<<p->info.stats.angka<<endl;
            cout<<"Sub stat 1: "<<p->info.substats1<<endl;
            cout<<"Sub stat 2: "<<p->info.substats2<<endl;
            cout<<"Sub stat 3: "<<p->info.substats3<<endl;
            cout<<"Sub stat 4: "<<p->info.substats4<<endl;
            cout<<"===================================="<<endl;
            i++;
            p = p->nextinduk;
        }
    }
}

void deleteIndukDanRelasi(ListInduk &LI,string idArtef){
    adrinduk ind = LI.first;
    adrinduk belakang = ind;
    adrpointerchild pchi;
    if(ind==NULL){
        cout<<"List Data Parent Kosong"<<endl;
    }else{
        while(ind!=NULL && ind->info.id != idArtef){
            belakang = ind;
            ind = ind->nextinduk;
        }
        if(ind->info.id == idArtef){
            pchi = ind->nextchild;
            while(pchi!=NULL){
                pchi->info = NULL;
                pchi = pchi->next;
            }
            delete ind->nextchild;
            ind->nextchild = NULL;
            if(ind == LI.first&&LI.first->nextinduk==NULL){
                LI.first = NULL;
            }else if (ind == LI.first && LI.first->nextinduk!=NULL){
                LI.first = LI.first->nextinduk;
                ind->nextinduk = NULL;
            }else if(ind->nextinduk == NULL && ind!=LI.first){
                belakang->nextinduk = NULL;
            }else{
                belakang->nextinduk = ind->nextinduk;
                ind->nextinduk = NULL;
            }
        }else{
            cout<<"Artefak Dengan ID "<<idArtef<<" tidak ditemukan"<<endl;
        }
    }
}

adrinduk searchInduk(ListInduk LI,string idArtef){
    adrinduk ind = LI.first;
    while(ind!=NULL){
        if(ind->info.id == idArtef){
            return ind;
        }
        ind = ind->nextinduk;
    }
    return NULL;
}

adrchild searchChild(ListChild LC,string keyword){
    adrchild chi = LC.first;
    while(chi!=NULL){
        if(chi->info == keyword){
//            cout<<"Child dengan nama: "<<keyword<<" ditemukan pada alamat "<<chi<<endl;
            return chi;
        }
        chi = chi->next;
    }
    return NULL;
}

void insertFirstChild(ListChild &LC, adrchild chi){
    chi->next = LC.first;
    LC.first = chi;
}

void insertLastChild(ListChild &LC, adrchild chi){
    adrchild p = LC.first;
    if(p==NULL){
        LC.first = chi;
    }else{
        while(p->next!=NULL){
            p = p->next;
        }
        p->next = chi;
    }
}

void hubungkanIndukChild(ListInduk &LI, ListChild LC, string idArtef, string namachild){
    adrpointerchild pchi;
    adrpointerchild baru = new ElementPointerChild;
    adrchild chi = LC.first;
    adrinduk cari = LI.first;
    if(chi==NULL){
        cout<<"Tidak Ada List Data Child yang Bisa Dihubungkan"<<endl;
    }else{
        while(chi!=NULL && chi->info!= namachild){
            chi = chi->next;
        }
        if(chi==NULL){
            cout<<"Tidak Ditemukan Data Child Dengan Nama "<<namachild<<endl;
        }else{
            if(cari==NULL){
                cout<<"List Data Parent Kosong"<<endl;
            }else{
                while(cari!=NULL && cari->info.id!=idArtef){
                    cari = cari->nextinduk;
                }
                if(cari==NULL){
                    cout<<"Tidak Ditemukan Data Artefak Dengan ID: "<<idArtef<<endl;
                }else{
                    pchi = cari->nextchild;
                    if(pchi==NULL){
                        cari->nextchild = baru;
                        baru->info = chi;
                        baru->next = NULL;
                    }else{
                        while(pchi->next!=NULL){
                            pchi = pchi->next;
                        }
                        pchi->next = baru;
                        baru->info = chi;
                        baru->next = NULL;
                    }
                }
            }
        }
    }
}

void showAllIndukChild(ListInduk LI, ListChild LC){
    adrinduk ind = LI.first;
    adrpointerchild pchi;
    int i = 1;
    int iterasiSubstat = 0;
    if(ind==NULL){
        cout<<"List Data Artefak Kosong"<<endl;
    }else{
        while(ind!=NULL){
            pchi = ind->nextchild;
            cout <<"Data Artefak Ke "<<i<<" :";
            cout<<"ID Artefak: "<<ind->info.id<<endl;
            cout<<"Level Artefak: "<<ind->info.level<<endl;
            cout<<"Piece: "<<ind->info.piece<<endl;
            cout<<"Set: "<<ind->info.Set<<endl;
            cout<<"Rarity: "<<ind->info.rarity<<endl;
            cout<<"Main Stat: "<<ind->info.stats.namastat<<" "<<ind->info.stats.angka<<endl;
            if (pchi!=NULL){
                cout<<"Sub stat 1: "<<pchi->info->info<<" "<<ind->info.substats1<<endl;
                pchi = pchi->next;
            }else{
//                cout<<"Sub stat 1: 0"<<endl;
            }
            if (pchi!=NULL){
                cout<<"Sub stat 2: "<<pchi->info->info<<" "<<ind->info.substats2<<endl;
                pchi = pchi->next;
            }else{
//                cout<<"Sub stat 2: 0"<<endl;
            }
            if (pchi!=NULL){
                cout<<"Sub stat 3: "<<pchi->info->info<<" "<<ind->info.substats3<<endl;
                pchi = pchi->next;
            }else{
//                cout<<"Sub stat 3: 0"<<endl;
            }
            if (pchi!=NULL){
                cout<<"Sub stat 4: "<<pchi->info->info<<" "<<ind->info.substats4<<endl;
                pchi = pchi->next;
            }else{
//                cout<<"Sub stat 4: 0"<<endl;
            }
            cout<<"===================================="<<endl;
            i++;
            ind = ind->nextinduk;
        }
    }
}

bool findChildInParent(ListInduk LI, ListChild LC, string idArtef, string carichild){
    adrchild chi = LC.first;
    adrinduk ind = LI.first;
    adrpointerchild pchi;
    while(chi!=NULL && chi->info!=carichild){
        chi = chi->next;
    }
    if(chi==NULL){
        return false;
    }else{
        while(ind!=NULL){
            if(ind->info.id == idArtef){
                pchi = ind->nextchild;
                while(pchi!=NULL){
                    if(pchi->info == chi){
                        return true;
                    }
                    pchi = pchi->next;
                }
            }
            ind = ind->nextinduk;
        }
    }
    return false;
}

void deleteChildDariInduk(ListInduk &LI, ListChild LC,string idArtef, string carichild){
    adrpointerchild pchi;
    adrpointerchild belakang;
    adrinduk ind = LI.first;
    adrchild chi = searchChild(LC,carichild);
    int i = 1;
    if(LC.first==NULL){
        cout<<"List Data Child Kosong"<<endl;
    }else if(chi==NULL){
        cout<<"Tidak Ada Data Child Dengan Nama "<<carichild<<endl;
    }else{
        if(ind==NULL){
            cout<<"List Data Artefak Kosong"<<endl;
        }else{
            while(ind!=NULL && ind->info.id!=idArtef){
                ind = ind->nextinduk;
            }
            if(ind==NULL){
                cout<<"Tidak Ada Artefak Dengan ID "<<idArtef<<endl;
            }else{
                pchi = ind->nextchild;
                belakang = pchi;
                while(pchi!=NULL && pchi->info!=chi){
                    belakang = pchi;
                    pchi = pchi->next;
                    i++;
                }
                if(pchi==ind->nextchild){
                    pchi->info = NULL;
                    ind->nextchild = pchi->next;
                    pchi->next = NULL;
                    ind->info.substats1 = 0;
                }else if(pchi->next==NULL){
                    pchi->info=NULL;
                    belakang->next=NULL;
                    ind->info.substats4 = 0;
                }else if(pchi==NULL){
                    cout<<"Tidak Ada Data Child "<<carichild<<" didalam Artefak Dengan ID "<<idArtef<<endl;
                }else{
                    belakang->next = pchi->next;
                    pchi->info = NULL;
                    pchi->next = NULL;
                    if(i==2){
                        ind->info.substats2 = 0;
                    }else if(i==3){
                        ind->info.substats3 = 0;
                    }
                }
            }
        }
    }
}

int banyakDataChild(ListInduk LI, ListChild LC, string idArtef){
    adrinduk ind = LI.first;
    adrpointerchild pchi;
    int i = 0;
    if (LI.first == NULL){
        cout<<"List Data Artefak Kosong"<<endl;
        return 0;
    }else {
        while(ind!=NULL && ind->info.id!=idArtef){
            ind = ind->nextinduk;
        }
        if (ind==NULL){
            cout<<"Tidak Ada Artefak Dengan ID "<<idArtef<<endl;
            return 0;
        }else{
            pchi = ind->nextchild;
            while(pchi!=NULL){
                i++;
                pchi = pchi->next;
            }
            return i;
        }
    }
}

bool adaChild(ListChild LC,string namachild){
    adrchild chi = LC.first;
    bool hasil = false;
    if(LC.first==NULL){
        return false;
    }else{
        while(chi!=NULL){
            if(chi->info==namachild){
                return true;
            }
            chi = chi->next;
        }
    }
    return false;
}

void showAllChild(ListChild LC){
    adrchild chi = LC.first;
    int i = 1;
    if(LC.first==NULL){
        cout<<"List Data Child Kosong"<<endl;
    }else{
        cout<<"Berikut Adalah List Data Child yang Terdaftar"<<endl;
        while(chi!=NULL){
            cout<<i<<". "<<chi->info<<endl;
            i++;
            chi = chi->next;
        }
    }
}

bool cekID(ListInduk LI, string idArtef){
    bool hasil = false;
    adrinduk ind = LI.first;
    while(ind!=NULL){
        if(ind->info.id == idArtef){
            return true;
        }
        ind = ind->nextinduk;
    }
    return false;
}

int indeksInduk(ListInduk LI,string idArtef){
    int i = 1;
    adrinduk ind = LI.first;
    while(ind!=NULL){
        if(ind->info.id==idArtef){
            return i;
        }
        i++;
        ind = ind->nextinduk;
    }
    return 0;
}

int indeksChild(ListChild LC, string namachild){
    int i = 1;
    adrchild chi = LC.first;
    while(chi!=NULL){
        if(chi->info==namachild){
            return i;
        }
        i++;
        chi = chi->next;
    }
    return 0;
}







