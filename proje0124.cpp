#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct site
{
    vector<string> urun;
    vector<double> fiyati;
    int makale;
};

void urunara(vector<site>& urunler, int uruntop, int topgun){
    int makaleAra;
    cout<<"\nAranacak makale: ";  
    cin>>makaleAra;
    bool found = false;
    for (int i = 0; i < topgun; i++)
    {
        for (int j = 0; j < uruntop; j++)
        {
            if (urunler[i].makale == makaleAra)
            {
                found=true;
                cout<<"\nBulundugu urun adi--> "<<urunler[i].urun[j]
                <<"\nGun olarak--> "<<i+1
                <<"\nMakalesi--> "<<urunler[i].makale
                <<"\nFiyati--> "<<urunler[i].fiyati[j]<<endl;
            }
        }
    }

    if (!found)
    {
        cout<<"Bu makale ile urun bukunmamaktadir";
    }
}
void urunedit(vector<site>& urunler, int uruntop, int topgun) {
    int eraseurun;
    cout << "Silmek istediğiniz öğenin dizinini girin: ";
    cin >> eraseurun;
    eraseurun--;

    if (eraseurun >= 0 && eraseurun < topgun) {
        urunler.erase(urunler.begin() + eraseurun);
        cout << "Öğe başarıyla silindi.\n";
    } else {
        cout << "Geçersiz dizin. Silinen öğe yok.\n";
    }
}
int main(int argc, char const *argv[])
{
    int topgun;
    cout<<"Toplam kac gun gireceksiniz? ";
    cin>>topgun;
    vector<site> urunler(topgun);
    
    int uruntop;
    for (int i = 0; i < topgun; i++)
    {
        string urun;
        double fiyati;
        cout<<"\nGun: "<<i+1<<", \n";
        cout<<"Kac urun girilecek--> ";
        cin>>uruntop;
        for (int j = 0; j < uruntop; j++)
        {
            cout<<"Urun "<<j+1<<" giriniz: ";
            cin>>urun;
            urunler[i].urun.push_back(urun);
            cout<<"Urunun makalesi: ";
            cin>>urunler[i].makale;
            cout<<urunler[i].urun.back()<<" Urunun fiyati ne kadar--> ";
            cin>>fiyati;
            urunler[i].fiyati.push_back(fiyati);
        }
    }
    int secenek=0;
    cout<<"Tamam, "<<uruntop<<" urun kaydedildi\n\nSecenekler:\n\t1 - Makale ile programda urun aramak\n\t2 - Programi edit etmek\n\t3 - Programdan cikmak\n\nBir secenek seciniz: ";
    cin>>secenek;
    while (secenek < 1 || secenek > 3)
    {
        cout<<"Girdiginiz numarayi kontrol ediniz lutfen, 1-den 3-e kadar: ";
        cin>>secenek;
    }
    if (secenek==1)
    {
        urunara(urunler, uruntop, topgun);
    }
    if (secenek==2)
    {
        urunedit(urunler, uruntop, topgun);
    }
    return 0;
}