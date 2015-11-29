#include "asd.h"
using namespace std;

void createlist (listj &l)
{
    l.first=NULL;
    l.last=NULL;
};
adrp alokasip (pembeli x)
{
    adrp p = new elmp;
    p->infop=x;
    p->next=NULL;
    p->prev=NULL;
    return p;
};
adrj alokasij (jadwal x)
{
    adrj p = new elmj;
    p->info=x;
    p->next=NULL;
    p->prev=NULL;
    p->pembeli=NULL;
    return p;
};
adrp findp (listj &l, string x)
{
    adrj q=l.first;
    adrp r=q->pembeli;
    if (q==0)
        return NULL;
    while (q!=0)
    {
        while (r!=NULL)
        {
            if(r->infop.idp==x)
            {
                return r;
            }
            r=r->next;
        }
        q=q->next;
    }
    cout << "Data tidak ditemukan!" << endl;
    return 0;
};
adrj findj (listj &l, string x)
{
    adrj q=l.first;
    if(q==NULL)
    {
        return 0;
    }
    while (q!=0)
    {
        if(q->info.id==x)
        {
            return q;
        }
        q=q->next;
    }
    //cout << "KOSONG!" <<endl;
    return 0;
};
adrj findjp (listj &l, string x, string y)
{
    adrj q=l.first;
    adrp r=q->pembeli;
    if (q==0)
        return NULL;
    while (q!=0)
    {
        if(q->info.id==x)
        {

            while(r!=NULL)
            {
                if(r->infop.idp==x)
                {
                    return q;
                }
                r=r->next;
            }
        }
        q=q->next;
    }
    cout << "Data tidak ditemukan!" << endl;
    return 0;
};

void insert_jadwal (listj &l, adrj p)
{
    adrj q;
    q=findj(l,p->info.id);

    if (q==NULL)
    {
        if (l.first==0)
        {
            l.first=p;
        }
        else
        {
            p->next=l.first;
            l.first->prev=p;
            l.first=p;
        }
    }
    else
        cout << "ID sudah ada!" << endl;
};
void insert_pembeli (listj &l, adrp p, string x)
{
    adrj q;

    q=findj(l,x);
    if(q!=NULL)
    {
        if(q->pembeli==NULL)
        {
            q->pembeli=p;
        }
        else
        {
            adrp r = q->pembeli;
            while(r->next!=NULL)
            {
                r=r->next;
            }
            r->next=p;
            p->prev=r;
            p->next=NULL;
        }
    }
};
void delete_pembeli (listj &l, adrj p, adrp q)
{
    if (p == NULL)
    {
        cout << "Data tidak ada!" << endl;
    }
    else if(p->pembeli==q)
    {
        p->pembeli=NULL;
    }
    else if(q->next==NULL)
    {
        q->prev->next=NULL;
        q->prev=NULL;
        q->next=NULL;
    }
    else
    {
        q->prev->next=q->next;
        q->next->prev=q->prev;
        q->next=NULL;
        q->prev=NULL;

    }
};
void delete_jadwal (listj &l, adrj p)
{
    if (p==NULL)
    {
        cout<<"Data kosong"<<endl;
    }
    else if(p->next==NULL)
    {
        l.first=NULL;
    }
    else if(p->next!=NULL)
    {
        l.first=p->next;
        l.first->prev=p;
        p->next=NULL;
        p->prev=NULL;
    }
    else if (p->next==NULL)
    {
        p->prev->next=NULL;
        p->prev=NULL;
        p->next=NULL;
    }
    else
    {
        p->prev->next=p->next;
        p->next->prev=p->prev;
        p->next=NULL;
        p->prev=NULL;
    }
};
void print_pembeli (listj l)
{
    adrj q=l.first;
    while (q!=0)
    {
        adrp r=q->pembeli;
        while(r!=NULL)
        {
            cout << "ID PEMBELI   : " << r->infop.idp << endl;
            cout << "NAMA PEMBELI : " << r->infop.namap << endl;
            cout << "TANGGAL BELI : " << r->infop.tanggalp << endl;
            cout << "HARGA TIKET  : " << r->infop.harga << endl;
            cout << "TEMPAT DUDUK : " << r->infop.duduk << endl;
            r=r->next;
        }
        q=q->next;
    }
    cout << endl;
};
void print_jadwal (listj l)
{
    adrj q=l.first;
    adrp r;
    while (q!=0)
    {
        cout<<"ID JADWAL  : "<<q->info.id<<endl;
        cout<<"JUDUL FILM : "<<q->info.judul<<endl;
        cout<<"JAM TAYANG : "<<q->info.jam<<endl;
        cout<<"KAPASITAS  : "<<q->info.kapasitas<<endl;
        adrp r=q->pembeli;
        cout << endl;

        while(r!=NULL)
        {

            cout <<"Pembeli yang memesan : "<<r->infop.namap<<endl;
            int i,a;
            i=0;
            while (r->infop.tempatduduk[i]!=1)
            {
                a=i;
                i=i+1;
            }
            cout << "Pembeli memesan kursi nomor : " << a << endl;
            r=r->next;
        }
        q=q->next;
    }
    cout << endl;
};
void ubah_jadwal (listj &l)
{
    string x;
    adrj p;
    cout << "Masukkan ID jadwal yang ingin diubah : ";
    cin >> x;
    p=findj(l,x);
    cout << "Masukkan ID jadwal baru : ";
    cin >> p->info.id;
    cout << "Masukkan JUDUL baru     : ";
    cin >> p->info.judul;
    cout << "Masukkan JAM baru       : ";
    cin >> p->info.jam;
    cout << "Masukkan KAPASITAS baru : ";
    cin >> p->info.kapasitas;

};
void ubah_pembeli (listj &l)
{
    string x;
    adrp p;
    cout << "Masukkan ID pembeli yang akan diubah : ";
    cin >> x;
    p=findp(l,x);
    cout << "Masukkan ID pembeli baru   : ";
    cin >> p->infop.idp;
    cout << "Masukkan Nama pembeli baru : ";
    cin >> p->infop.namap;
    cout << "Masukkan Tanggal beli baru : ";
    cin >> p->infop.tanggalp;
    cout << "Masukkan Harga beli baru   : ";
    cin >> p->infop.harga;
};
void rekap_total (listj &l)
{
    adrj p=l.first;
    adrp q;
    int x=0;
    if (p!=NULL)
    {
        while (q!=NULL)
        {
            x=x+q->infop.harga;
            q=q->next;
        }
    }
    cout << "Total penjualan tiket : " << x << endl;
}
pembeli input_pembeli (pembeli &x)
{
    int c;
    string d;
    jadwal j;

    cout << "Masukkan ID PEMBELI   : ";
    cin  >> x.idp;

    cout << "Masukkan NAMA PEMBELI : ";
    cin >> x.namap;

    cout << "Masukkan TANGGAl BELI : ";
    cin  >> x.tanggalp;

    cout << "Masukkan HARGA TIKET  : ";
    cin  >> x.harga;

    cout << "Masukkan TEMPAT DUDUK : ";
    cin >> c;

    //x.tempatduduk[c]=1;
    if (x.tempatduduk[c]<=j.kapasitas)
    {
        if (x.tempatduduk[c]==1)
        {
            cout << "Tempat sudah dipesan!" << endl;
        }
        else
        {
            x.duduk=c;
            x.tempatduduk[c]=1;
        }
    }
    else
    {
        cout << "Nomor tempat duduk melebihi kapasitas!";
    }

    cout << endl;
    return x;
};

jadwal input_jadwal (jadwal &x)
{
    //int c;
    cout << "Masukkan ID JADWAL  : ";
    cin  >> x.id;

    cout << "Masukkan JAM TAYANG : ";
    cin  >> x.jam;

    cin.ignore();
    cout << "Masukkan JUDUL FILM : ";
    getline(cin,x.judul);

    cout << "Masukkan KAPASITAS  : ";
    cin  >> x.kapasitas;

    cin.ignore();
    x.tempatduduk[x.kapasitas]=x.kapasitas;

    cout << endl;
    return x;
};
adrj cari_jadwal (listj &l, jadwal x)
{

    adrj p=l.first;
    cout << "Masukkan ID jadwal yang akan dicari : ";
    cin >> x.id;
    p=findj(l,x.id);
    //while (p!=NULL)
    //{
        if (p->info.id==x.id)
        {
            cout<<"ID JADWAL  : "<<p->info.id<<endl;
            cout<<"JUDUL FILM : "<<p->info.judul<<endl;
            cout<<"JAM TAYANG : "<<p->info.jam<<endl;
            cout<<"KAPASITAS  : "<<p->info.kapasitas<<endl;
        }
    //}
    p=p->next;
    cout << endl;
}
adrp cari_pembeli(listj &l, pembeli x)
{
    adrj p=l.first;
    adrp q;
    string g;
    cout << "Masukkan ID pembeli yang akan dicari : ";
    cin >> g;
    q=findp(l,g);
    //while (p!=NULL)
    //{
        if (q->infop.idp==g)
        {
            cout << "ID PEMBELI   : " << q->infop.idp << endl;
            cout << "NAMA PEMBELI : " << q->infop.namap << endl;
            cout << "TANGGAL BELI : " << q->infop.tanggalp << endl;
            cout << "HARGA TIKET  : " << q->infop.harga << endl;
            cout << "TEMPAT DUDUK : " << q->infop.duduk << endl;
        }
    //}
    //p=p->next;
    cout << endl;
}
void gotoxy(int x , int y)
{
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
void cek_kursi(listj &l, jadwal x)
{
    adrj p=l.first;
    adrp q;
    pembeli y;
    int a;
    cout << "Masukkan ID Jadwal : ";
    cin >> x.id;
    p=findj(l,x.id);
    if (p->info.id==x.id)
    {
        for (int i=0; i<=x.kapasitas;i++)
        {
            if (y.tempatduduk[i]==1)
            {
                a=a+1;
            }
        }
    }
    cout << "Sisa tempat duduk : " << x.kapasitas-a;
    cout << endl;
}
