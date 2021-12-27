#include "header.h"

adr_penyanyi create_musisi(string nama, string ttl){
    //create address buat penyanyi
    adr_penyanyi P = new elm_penyanyi;
    P->namaPenyanyi = nama;
    P->tempatTanggalLahir = ttl;
    P->next = NULL;
    P->nextLagu = NULL;
    P->prevLagu = NULL;

    return P;
}
adr_lagu create_lagu(string nama, string artis, int tahun_rilis){
    //create address buat lagu
    adr_lagu P = new elm_lagu;
    P->namaLagu = nama;
    P->artis = artis;
    P->tahunRilis = tahun_rilis;
    P->next = NULL;
    P->prev = NULL;

    return P;
}
void create_listMusisi(musisi &M){
    //create list musisi
    M.first = NULL;
    M.last = NULL;
}
void create_listLagu(lagu &L){
    //create list lagu
    L.first = NULL;
}

void insert_penyanyi(musisi &M, adr_penyanyi P){
    //memasukkan adr penyanyi ke list musisi
    if (M.first == NULL) {
        M.first = P;
        M.last = P;
    } else {
        adr_penyanyi Q = M.first;
        while (next(Q) != NULL) {
            Q = next(Q);
        }
        next(Q) = P;
        prev(P) = Q;
    }
}

void delete_penyanyi(musisi &M, adr_penyanyi &P) {
    //menghapus penyanyi dari list
    adr_penyanyi Prec = M.first;
    adr_penyanyi Q;
    if (Prec == P && next(Prec) == NULL) {
        M.first = NULL;
        M.last = NULL;
    } else if(P == M.last) {
        next(prev(M.last)) = NULL;
        M.last = NULL;
    } else {
        while (next(Prec) != P) {
            Prec = next(Prec);
        }
        Q = next(Prec);
        next(Prec) = next(Q);
        prev(next(Q)) = Prec;
        prev(P) = NULL;
        next(P) =  NULL;
    }

}

void show_penyanyi(musisi M) {
    //menampilkan list penyanyi
    adr_penyanyi P = M.first;
    if(P == NULL) {
        cout << "DAFTAR PENYANYI KOSONG" << endl;
    } else {
        int i = 1;
        while (next(P) != NULL) {
            cout << "[" << i++ << "]" << endl;
            cout << "Nama Penyanyi        : " << P->namaPenyanyi << endl;
            cout << "Tempat Tanggal Lahir : " << P->tempatTanggalLahir << endl;
            P = next(P);
        }
    }
}

adr_penyanyi find_penyanyi(musisi M, string nama) {
    //mencari alamat penyanyi berdasarkan nama
    adr_penyanyi P = M.first;
    while(P->namaPenyanyi != nama) {
        P = next(P);
    }
    if(P->namaPenyanyi == nama) {
        return P;
    } else {
        return NULL;
    }
}
