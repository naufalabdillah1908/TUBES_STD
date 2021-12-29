#include "header.h"
int main()
{
    //list tetap
    musisi M;
    lagu L;

    //create list
    create_listMusisi(M);
    create_listLagu(L);

    //define adr
    adr_penyanyi P;
    adr_lagu X;

    //buat input penyanyi
    string nama;
    string TTL;

    //buat input lagu
    string judul;
    string pembuat1;
    string pembuat2;
    int tahun_rilis;
    string iscollab;


    int pilihan = menu();
    while (pilihan > 0 && pilihan <= 8){
        switch (pilihan) {
    case 1:
        cout<<"Masukkan nama Penyanyi: ";
        cin>>nama;

        cout<<"Masukkan Tempat dan tanggal lahir Penyanyi: ";
        cin>>TTL;

        P = create_musisi(nama, TTL);
        insert_penyanyi(M, P);

    case 2:
        cout<<"Masukkan Judul lagu: ";
        cin>>judul;

        cout<<"Masukkan nama pembuat: ";
        cin>>pembuat1;

        cout<<"Ada Collab?(Y/N)";
        cin>>iscollab;

        if (iscollab == "Y") {
            cout<<"Masukkan nama collab: ";
            cin>>pembuat2;
        } else {
            pembuat2 = "-";
        }

        cout<<"Masukkan Tahun Rilis: ";
        cin>>tahun_rilis;

        X = create_lagu(judul, pembuat1, pembuat2, tahun_rilis);
        insert_lagu(L, X);

        add_lagu_to_musisi(M, L, pembuat1, judul);

        if (iscollab == "Y") {
            add_lagu_to_musisi(M, L, pembuat2, judul);
        }

    case 3:
        cout<<"Masukkan nama penyanyi yang ingin di delete: ";
        cin>>nama;

        del_penyanyi(M, nama);

    case 4:
        cout<<"Masukkan Judul Lagu yang ingin di delete: ";
        cin>>judul;

        del_lagu(M, L, judul);

    case 5:
        show_penyanyi(M);

    case 6:
        show_all_lagu(L);

    case 7:
        cout<<"Masukkan nama penyanyi: ";
        cin>>nama;

        show_lagu(M, nama);

    case 8:

        }
    }

    return 0;
}
