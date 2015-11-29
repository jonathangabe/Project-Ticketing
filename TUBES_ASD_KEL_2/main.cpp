#include <iostream>
#include "asd.h"

using namespace std;
string d;
int p1,p2,p3,c;
int main()
{
    listj l;
    adrj p,q;
    adrp pp,qq;
    jadwal j;
    pembeli x;
    int tempatduduk[50];

    createlist(l);
    int i;
    for(i=10; i<70; i++)
    {

        delay(50);
        gotoxy(33,10);
        cout << "SELAMAT DATANG" << endl;
        gotoxy(9,12);
        cout << "[";
        gotoxy(71,12);
        cout << "]";
        gotoxy(i-1,12);
        //printf(" ");
        //gotoxy(i,1);
        printf("||");

    }
    system("cls");
    do
    {
        gotoxy(25,4);
        cout << "\tMENU TICKETING STUDIO \n" << endl;
        gotoxy(20,5);
        cout << "\t1. MENU JADWAL" << endl;
        gotoxy(20,6);
        cout << "\t2. MENU PEMBELI" << endl;
        gotoxy(20,7);
        cout << "\t3. REKAP TOTAL TIKET" << endl;
        gotoxy(20,8);
        cout << "\t0. KELUAR" << endl;
        gotoxy(20,9);
        cout << "\tMenu : ";
        cin >> p1;
        cout << endl;
        switch (p1)
        {
        case 1 :
            do
            {
                system("cls");
                gotoxy(25,4);
                cout << "\tMENU TICKETING STUDIO" << endl;
                gotoxy(20,5);
                cout << "1. TAMBAH JADWAL" << endl;
                gotoxy(20,6);
                cout << "2. UBAH JADWAL" << endl;
                gotoxy(20,7);
                cout << "3. HAPUS JADWAL" << endl;
                gotoxy(20,8);
                cout << "4. CARI JADWAL" << endl;
                gotoxy(20,9);
                cout << "5. LIHAT JADWAL" << endl;
                gotoxy(20,10);
                cout << "0. KEMBALI KE MENU UTAMA" << endl;
                gotoxy(20,11);
                cout << "Pilihan : ";
                cin >> p2;
                cout << endl;
                switch (p2)
                {
                case 1:
                    input_jadwal(j);
                    p=alokasij(j);
                    insert_jadwal(l,p);
                    cout << "Jadwal telah ditambah" << endl;
                    getch();
                    system("cls");
                    break;

                case 2:
                    ubah_jadwal(l);
                    cout << "Jadwal telah diubah" << endl;
                    getch();
                    break;

                case 3:
                    cout << "Masukkan ID Jadwal yang akan dihapus : ";
                    cin >> d;
                    p=findj(l,d);
                    delete_jadwal(l,p);
                    getch();
                    break;

                case 4:
                    cari_jadwal(l,j);
                    getch();
                    break;

                case 5:
                    print_jadwal(l);
                    getch();
                    break;
                }
            }
            while(p2!=0);
            system("cls");
            break;

        case 2 :
            do
            {
                system("cls");
                gotoxy(25,4);
                cout << "\tMENU TICKETING STUDIO" << endl;
                gotoxy(20,5);
                cout << "1. TAMBAH PEMBELI" << endl;
                gotoxy(20,6);
                cout << "2. UBAH PEMBELI" << endl;
                gotoxy(20,7);
                cout << "3. HAPUS PEMBELI" << endl;
                gotoxy(20,8);
                cout << "4. CARI PEMBELI" << endl;
                gotoxy(20,9);
                cout << "5. LIHAT PEMBELI" << endl;
                gotoxy(20,10);
                cout << "6. CEK KURSI" << endl;
                gotoxy(20,11);
                cout << "0. KEMBALI KE MENU UTAMA" << endl;
                gotoxy(20,12);
                cout << "Pilihan : ";
                cin >> p3;
                cout << endl;
                switch (p3)
                {
                case 1:
                    input_pembeli(x);
                    cout << "Masukkan ID JADWAL yang akan dibeli : ";
                    cin >> d;
                    p=findj(l,x.idp);
                    if (p==NULL)
                    {
                        pp=alokasip(x);
                        insert_pembeli(l,pp,d);
                    }
                    cout << "Data pembeli terdaftar" << endl;
                    getch();
                    break;

                case 2:
                    ubah_pembeli(l);
                    cout << "Data pembeli telah diubah" << endl;
                    break;

                case 3:
                    cout << "Masukkan ID pembeli yang akan dihapus : ";
                    cin >> d;
                    pp=findp(l,d);
                    delete_pembeli(l,p,pp);
                    break;

                case 4:
                    cari_pembeli(l,x);
                    break;
                case 5:
                    print_pembeli(l);
                    getch();
                    break;
                case 6:
                    cek_kursi(l,j);
                    getch();
                    break;
                }
            }
            while(p3!=0);
            system("cls");
            break;
        case 3:
            rekap_total(l);
            getch();
            system("cls");
            break;
        }
    }
    while (p1!=0);
    system("cls");
    gotoxy(30,10);
    cout << "T E R I M A  K A S I H" << endl;
    getch();
    return 0;
}
