/*
**************************
    Tomasz Potanski
        238 756
**************************
*/

#include <iostream>
#include <set>

#include "figura.hpp"
#include "pionek.hpp"
#include "wieza.hpp"
#include "goniec.hpp"
#include "hetman.hpp"
#include "kon.hpp"
#include "krol.hpp"

using namespace std;

set <Wieza *> wstawioneWieze;
set <Figura *> wstawioneFigury;
set <Wieza *>::iterator itw;
set <Figura *>::iterator itf;
set <int> wczesniejSkresloneWierszeN;
set <int> wczesniejSkresloneWierszeM;
set <int>::iterator it;

const int debug = 1;

/**
Funckcja zwraca minimum z dwoch liczb
*/
int min(int a, int b){
    return (a<b?a:b);
}

/**
Funckcja zwraca maximum z dwoch liczb
*/
int max(int a, int b){
    return (a<b?b:a);
}

/**
funkcja mowi, czy pole jest bite przez jakakolwiek z figur ze zbioru wstawioneFigury
@param x wspolrzedna pozioma
@param y wspolrzedna pionowa
*/
bool czyBija(int x, int y){
    bool result = false;
    for(Figura * f : wstawioneFigury){
        result |= f->czyBijeToPole(x, y);
    }
    return result;
}


/**
Atomowa funkcja zastosowanego podalgorytmu z rodziny Las Vegas zastosowanego
do odpowiedzi na pytanie, czy na planszy kwadratowej rozmiaru n na n mozna
ustawic iloscHetm tak, aby nie szachowaly sie wzajemnie.
@param n wielkoœæ szachownicy n x n
@param tr tablica intow, w ktorej zwracane beda wyniki ustawienia hetmanow
@param iloscHetm iloscHetmanow
*/
bool QueensALP(int n,int *tr, int iloscHetm){
    if (iloscHetm > n ){
        return false;
    }

    int *kolumna=new int[n];
    int *diag45=new int[2*n-1];
    int *diag135=new int[2*n-1];
    int i, j, nb, k;
    for (i=0;i<n;i++){
        kolumna[i]=0;
        diag45[i]=0;
        diag135[i]=0;
    }
    for (i=n;i<2*n-1;i++){
      diag45[i]=0;
      diag135[i]=0;
 }


    k=0;
    do {
        nb=0;
        for (i=0;i<n;i++){
            if (kolumna[i]==0 && diag45[n-1+k-i]==0 && diag135[k+i]==0){
                nb++;
                if (rand()%nb==0){
                    j=i;
                }
            }
        }
    if (nb>0){
        tr[k]=j;
        kolumna[j]=1;
        diag45[n-1+k-j]=1;
        diag135[k+j]=1;
        k++;
    }
    } while (k<iloscHetm && nb>0);

    delete[] kolumna;
    delete[] diag45;
    delete[] diag135;

    return nb>0;
}

void wyswietlWstawione(){
        printf("przykladowe ustawienie:\n");
        for (itw = wstawioneWieze.begin() ; itw  != wstawioneWieze.end(); itw++){
            cout << **itw << endl;
        }
        for (itf = wstawioneFigury.begin() ; itf  != wstawioneFigury.end(); itf++){
            cout << **itf << endl;
        }
}

/**
Funkcja mowi, czy na planszy szachowej rozmiaru n na m mozna rozstawic <hetmanow> htemanow, <wiez> wiez oraz <goncow> goncow ;)
@param n wymiar poziomy
@param m wymiar pionowy
@param hetmanow liczba hetmanow
@param wiez liczba wiez
@param goncow liczba goncow
*/
bool czyMoznaRozstawic(int n, int m, int hetmanow, int wiez, int goncow){
    bool result = true;

    if ((min(n,m) < hetmanow + wiez) || (min(n,m) == hetmanow + wiez && goncow > 0) || (hetmanow == 1 && goncow == 0 && wiez == min(n,m)-1)){
        if (debug){//cout << "return1\n";
            wyswietlWstawione();
        }
        wstawioneFigury.clear();
        wstawioneWieze.clear();
        //delete[] wiersz;
        return false;
    }

    if (wiez > 0){
        for (int i = 0 ; i < wiez ; i++){
            Wieza * w = new Wieza();
            w->setPosition(n--,m--);
            wstawioneWieze.insert(w);
        }
    }
//---------
 srand( (unsigned)time( NULL ) );
 int *wiersz=new (nothrow) int[min(m,n)]; //tu beda wyniki
 for (int i=0;i<min(m,n);i++) wiersz[i]=-1;
 if (hetmanow > min(n,m)){
     if (debug){
        wyswietlWstawione();
     }
    wstawioneFigury.clear();
    wstawioneWieze.clear();
     delete[] wiersz;
    return false;
 } else {
    while (!QueensALP(min(n,m),wiersz, hetmanow));
    //wrzucam do setu
    int deltaN=0;// deltaM = 0;
    if (n >= m){
        //n >= m
        deltaN = n-m;
    } else {
        //m > n
        //deltaM = m - n;
    }
        int iloscDodanych = 0;
        while(iloscDodanych < hetmanow){
            Hetman * h = new Hetman();
            h->setPosition(wiersz[iloscDodanych]+deltaN+1,m-iloscDodanych);
            wstawioneFigury.insert(h);
            iloscDodanych++;
        }
        m-=hetmanow;
 }

    if (goncow > 0){
        int ileWstawilemGoncow = 0;
        if (debug){
            printf("n = %d, m = %d\n", n, m);
            cout << czyBija(1,1) << endl;
            cout << czyBija(4,2) << endl;
        }
        for (int i = 1 ; i <= n && ileWstawilemGoncow < goncow ; i++){
            for (int j = 1 ; j <= m && ileWstawilemGoncow < goncow; j++){
                if (!czyBija(i,j)){
                    Goniec * g = new Goniec();
                    g->setPosition(i,j);
                    wstawioneFigury.insert(g);
                    ileWstawilemGoncow++;
                }
            }
        }
        if (ileWstawilemGoncow < goncow){
            if (debug){
                wyswietlWstawione();
            }
            wstawioneFigury.clear();
            wstawioneWieze.clear();
            delete[] wiersz;
            return false;
        }
    }


    if (debug){
        wyswietlWstawione();
    }

    wstawioneFigury.clear();
    wstawioneWieze.clear();
     delete[] wiersz;

    return result;

}

void wyswietlInfo(){
    printf("Menu:\nn - nowe wprowadzenie\nq - wyjscie\n");
}

int main(void){
     //randomize();
 srand( (unsigned)time( NULL ) );

    printf("testy jednostkowe\nplansza 8x8\nilosc: hetmanow, wiez, goncow\n1-sukces, 0 - porazka\n");
    printf("2,2,2\n");
    //bool czyMoznaRozstawic(int n, int m, int hetmanow, int wiez, int goncow){
    cout << czyMoznaRozstawic(8, 8, 2,2, 2) << endl;
    printf("2,10,2\n");
    cout << czyMoznaRozstawic(8, 8, 2,10, 2) << endl;
    printf("0,0,8\n");
    cout << czyMoznaRozstawic(8, 8, 0,0, 8) << endl;

    printf("9,0,0\n");
    cout << czyMoznaRozstawic(8, 8, 9,0, 0) << endl;
    printf("0,9,0\n");
    cout << czyMoznaRozstawic(8, 8, 0, 9, 0) << endl;
    printf("3,3,4\n");
    cout << czyMoznaRozstawic(8, 8, 3, 3, 4) << endl;
    printf("8,0,0\n");
    cout << czyMoznaRozstawic(8, 8, 8, 0, 0) << endl;

    char c='d';

    wyswietlInfo();
    while(scanf("%c",&c)>0){
        if (c == 'q'){
            break;
        } else if (c == 'n'){
            int n,m, h, w, g;
            printf("wprowadz liczby oddzielone bialymi znakami: <rozmiar pionowy> <rozmiar poziomy> <il. hetmanow> <il. wiez> <il. goncow>" );
            scanf("%d %d %d %d %d", &n, &m, &h, &w, &g);
            bool result = czyMoznaRozstawic(n, m, h, w, g);
            if (result){
                //mozna
                printf("to rozmieszczenie jest wykonalne\n");
            } else {
                //nie mozna
                printf("tak nie mozna rozmiescic figur bez bicia\n");
            }
        }
        wyswietlInfo();
    }

    return 0;
}
