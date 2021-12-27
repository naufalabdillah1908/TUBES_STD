#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED

#include <iostream>

#define next(P) (P)->next
#define prev(P) (P)->prev
#define first(L) ((L).first)
#define nextLagu(P) ((P)->nextLagu)

using namespace std;

typedef struct elm_penyanyi *adr_penyanyi;
typedef struct elm_lagu *adr_lagu;
struct elm_penyanyi
{
    string namaPenyanyi;
    string tempatTanggalLahir;
    adr_penyanyi next;
    adr_penyanyi prev;
    adr_lagu nextLagu;
    adr_lagu prevLagu;

};


struct elm_lagu
{
    string namaLagu;
    string artis;
    int tahunRilis;
    adr_lagu next;
    adr_lagu prev;
};

struct musisi
{
    adr_penyanyi first;
    adr_penyanyi last;
};

struct lagu {
    adr_lagu first;
};

adr_penyanyi create_musisi(string nama, string ttl);
adr_lagu create_lagu(string nama, string artis, int tahun_rilis);
void create_listMusisi(musisi &M);
void create_listLagu(lagu &L);
void insert_penyanyi(musisi &M, adr_penyanyi P);
void delete_penyanyi(musisi &M, adr_penyanyi &P);
void show_penyanyi(musisi M);
adr_penyanyi find_penyanyi(musisi M, string nama);
#endif // HEADER_H_INCLUDED
