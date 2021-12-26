#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED

#include <iostream>

#define info(P) (P)->info
#define next(P) (P)->next
#define first(L) ((L).first)
#define nextLagu(P) ((P)->nextLagu)

using namespace std;

typedef struct elm_penyanyi *adr_penyanyi;
struct elm_penyanyi
{
    string namaPenyanyi;
    string tempatTanggalLahir;
    adr_penyanyi next;
    adr_lagu nextLagu;

};

typedef struct elm_lagu *adr_lagu;
struct elm_lagu
{
    string namaLagu;
    string artis;
    int tahunRilis;
    adr_lagu next;
};

struct musisi
{
    adr_penyanyi first;
};
#endif // HEADER_H_INCLUDED
