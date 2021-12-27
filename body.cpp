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
