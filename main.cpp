#include "header.h"
int main()
{
    //tes
    musisi M;
    lagu L;

    create_listMusisi(M);
    create_listLagu(L);

    adr_penyanyi P;
    adr_lagu X;

    P = create_musisi("Johanes", "Jakarta, 4 April 2000");
    insert_penyanyi(M, P);
    show_penyanyi(M);

    P = create_musisi("Raphael", "Lebak, 8 Agustus 2000");
    insert_penyanyi(M, P);
    show_penyanyi(M);

    //delete_penyanyi(M, "Johanes");
    //show_penyanyi(M);

    P = find_penyanyi(M, "Raphael");
    cout << P->nama << endl;
    cout << P->tempatTanggalLahir << endl;

    // Masih blm ngerti pas masukin lagunya,
    X = create_lagu("Smoke W Everyday", "Raphael", "Johanes", 2016);
    insert_lagu(L, X);
    add_lagu_to_musisi(M, L, "Raphael", "Smoke W Everyday");
    show_lagu(M, "Raphael");
    return 0;
}
