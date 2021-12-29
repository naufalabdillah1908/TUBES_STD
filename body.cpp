#include "header.h"

adr_penyanyi create_musisi(string nama, string ttl){
    //create address buat penyanyi
    adr_penyanyi P = new elm_penyanyi;
    P->nama = nama;
    P->tempatTanggalLahir = ttl;
    P->next = NULL;
    P->list_lagu.first = NULL;
    return P;
}
adr_lagu create_lagu(string nama, string artis, string collab, int tahun_rilis){
    //create address buat lagu
    adr_lagu P = new elm_lagu;
    P->judul = nama;
    P->artis = artis;
    P->collab = collab;
    P->tahunRilis = tahun_rilis;
    P->next = NULL;

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

void delete_penyanyi(musisi &M, string nama) {
    //menghapus penyanyi dari list
    adr_penyanyi Prec = M.first;
    adr_penyanyi Q;
    if (Prec->nama == nama) {
        if (next(Prec) == NULL) {
            M.first = NULL;
            M.last = NULL;
        } else {
            M.first = next(Prec);
            next(Prec) = NULL;
            prev(M.first) = NULL;
        }
    } else if(nama == M.last->nama) {
        next(prev(M.last)) = NULL;
        M.last = NULL;
    } else {
        while ((next(Prec))->nama != nama) {
            Prec = next(Prec);
        }
        Q = next(Prec);
        next(Prec) = next(Q);
        prev(next(Q)) = Prec;
        Q = NULL;

    }

}

void show_penyanyi(musisi M) {
    //menampilkan list penyanyi
    adr_penyanyi P = M.first;
    if(P == NULL) {
        cout << "DAFTAR PENYANYI KOSONG" << endl;
    } else {
        int i = 1;
        while (P != NULL) {
            cout << "[" << i++ << "]" << endl;
            cout << "Nama Penyanyi        : " << P->nama << endl;
            cout << "Tempat Tanggal Lahir : " << P->tempatTanggalLahir << endl;
            P = next(P);
        }
        cout << endl;
    }
}

adr_penyanyi find_penyanyi(musisi M, string nama) {
    //mencari alamat penyanyi berdasarkan nama
    adr_penyanyi P = M.first;
    while(P->nama != nama) {
        P = next(P);
    }
    if(P->nama == nama) {
        return P;
    } else {
        return NULL;
    }
}

void insert_lagu(lagu &L, adr_lagu P){
    if (L.first == NULL) {
        L.first = P;
    } else {
        P->next = L.first;
        L.first = P;
    }
}

void delete_lagu(lagu &L, string judul){
    //menghapus lagu dari list
    adr_lagu P = L.first;

    while (P->judul != judul || P->next != NULL) {
        P = P->next;
    }

    if (P == NULL) {
        cout<<"Tidak ada lagu yang ingin di delete"<<endl;
    } else if (P == L.first && P->next == NULL) {
        L.first = NULL;
    } else if (P == L.first && P->next != NULL) {
        P->next = L.first;
        P = NULL;
    } else if (P != L.first && P->next == NULL){
        P = NULL;
    } else {
        adr_lagu Q = L.first;
        while (Q->next != P) {
            Q = Q->next;
        }
        Q->next = P->next;
        P = NULL;
    }

}

adr_lagu find_lagu(lagu L, string judul){
    //mencari alamat lagu berdasarkan judul
    adr_lagu P = L.first;
    while(P->judul != judul && P != NULL) {
        P = next(P);
    }
    if(P->judul == judul) {
        return P;
    } else {
        return NULL;
    }
}


void add_lagu_to_musisi(musisi &M, lagu &L, string nama, string judul){

    adr_penyanyi P = find_penyanyi(M, nama);
    adr_lagu Q = find_lagu(L, judul);

    if (P != NULL && Q != NULL) {
        if (Q->artis == P->nama || Q->collab == P->nama) {
            adr_lagu R = create_lagu(Q->judul,Q->artis,Q->collab,Q->tahunRilis);

            insert_lagu(P->list_lagu, R);
        } else {
            cout<<"Penyanyi tidak membuat Tersebut"<<endl;
        }
    } else {
        cout<<"Tidak ada Penyanyi atau Lagu didalam list"<<endl;
    }
}

void del_lagu_from_musisi(musisi &M, lagu L, string nama, string judul){
    adr_penyanyi P;
    lagu L2;

    P = find_penyanyi(M, nama);
    adr_lagu Q = find_lagu(L, judul);
    if (P != NULL && Q != NULL) {
        if (Q->artis == P->nama || Q->collab == P->nama) {
            L2 = P->list_lagu;
            delete_lagu(L2, judul);
        }
    }
}

void del_penyanyi(musisi &M, string nama){
    //delete penyanyi sama relasinya
}

void del_lagu(musisi &M, lagu &L, string judul){
    //delete lagu di dalam list dan lagu dalam semua musisi;
    adr_penyanyi P = M.first;
    while (P != NULL) {
        delete_lagu(P->list_lagu, judul);
    }
    delete_lagu(L, judul);
}

//blom kucek wkwk, pusing liatnya
void show_lagu(musisi M, string nama) {
    lagu L2;

    //menampilkan lagu penyanyi berdasarkan nama yang dicari
    adr_penyanyi P = find_penyanyi(M, nama);
    L2 = P->list_lagu;
    if (P == NULL) {
        cout << "Tidak ada Penyanyi didalam list" << endl;
    } else if (L2.first == NULL) {
        cout << "tidak ada lagu yang dibuat oleh penyanyi" << endl;
    } else {
        adr_lagu X = first(L2);
        int i = 1;
        while (X != NULL) {
            cout << "[" << i++ << "]" << endl;
            cout << "Judul  : " << X->judul << endl;
            cout << "Artis  : " << X->artis << endl;
            cout << "Collab : " << X->collab << endl;
            cout << "Rilis  : " << X->tahunRilis << endl;
            X = next(X);
        }
    }
}


void show_all_lagu(lagu L){
    if (L.first == NULL) {
        cout<<"tidak ada lagu dalam list"<<endl;
    } else {
        adr_lagu X = first(L);
        int i = 1;
        while (X != NULL) {
            cout << "[" << i++ << "]" << endl;
            cout << "Judul  : " << X->judul << endl;
            cout << "Artis  : " << X->artis << endl;
            cout << "Collab : " << X->collab << endl;
            cout << "Rilis  : " << X->tahunRilis << endl;
            X = next(X);
        }
    }
}

void show_semua_musisi_dengan_lagunya(musisi M) {
//show all data, musisi dan lagunya
    adr_penyanyi P = M.first;
    adr_lagu x;
    int i = 0;
    while (P != NULL) {
        cout<<"["<<i++<<"]"<<endl;
        cout<<"Nama Musisi: "<<P->nama<<endl;
        cout<<"TTL: "<<P->tempatTanggalLahir<<endl;

        cout<<"Lagu yang dibuat:"<<endl;
        x = P->list_lagu.first;
        while (x != NULL) {
            cout<<"-"<<x->judul;
            if (x->collab != "-") {
                cout<<" ft."<<x->collab<<endl;
            } else {
                cout<<endl;
            }
            x = x->next;
        }
        P = P->next;
        cout<<endl;
    }
}

int count_lagu_dari_penyanyi(musisi M) {

}

int menu(){
    cout<<"--- Menu ---"<<endl<<endl;
    cout<<"Silahkan Pilih Apa yang anda ingin lakukan:"<<endl;
    cout<<"1. Input Penyanyi"<<endl;
    cout<<"2. Input Lagu"<<endl;
    cout<<"3. Delete Penyanyi;"<<endl;
    cout<<"4. Delete Lagu"<<endl;
    cout<<"5. Show semua Penyanyi"<<endl;
    cout<<"6. Show semua lagu yang ada di sistem"<<endl;
    cout<<"7. Show lagu yang dibuat oleh seorang penyanyi"<<endl;
    cout<<"8. Show semua penyanyi dengan lagunya"<<endl;
    cout<<"0. Exit"<<endl;
    cout<<endl<<endl;
    cout<<"Input nomor: ";
    int angka;
    cin>>angka;

    return angka;
}



