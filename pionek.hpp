#ifndef PIONEK_HPP
#define PIONEK_HPP

#include "figury.hpp"
#include "figura.hpp"
#include <assert.h> 

/**
Enumeracja opisujaca kolor jako strone/gracza.
Konieczna ze wzgledu na charakterystyke bicia pionka
*/
enum kolor{
	czarny,
	bialy
};

class Pionek : public Figura
{					
        public:
		bool czyBijeToPole(int xx, int yy);
			/**
			Konstruktor pionka nie umiejscawiajacy go na planszy. 
			Istnieje koniecznosc podania koloru pionka
			@param jaki kolor pionka
			*/
             Pionek(kolor jaki);
			/**
			Konstruktor pionka umiejscawiajacy go na planszy. 
			Istnieje koniecznosc podania koloru pionka
			@param jaki kolor pionka
			@param xx wspolrzedna pozioma
			@param yy wspolrzedna pionowa
			*/
			 Pionek(int xx, int yy, kolor jaki);
		private:
			/**
			kolor pionka/strona/gracz
			*/
			kolor mojKolor;
};

Pionek::Pionek(kolor jaki) : Figura::Figura(){
	czymJestem = pionek;
	mojKolor = jaki;
}

Pionek::Pionek(int xx, int yy, kolor jaki) : Figura(xx, yy){
	czymJestem = pionek;
	mojKolor = jaki;
}

bool Pionek::czyBijeToPole(int xx, int yy){
	//if (czyZainicjalizowanoX == false || czyZainicjalizowanoY == false){
		//throw (-1);
		
	//}	
	assert(czyZainicjalizowanoX == true && czyZainicjalizowanoY == true);
	bool result = false;
	if (xx == x && yy == y){
		result = true;
	}
	if (mojKolor == czarny){
		//czarny
		if (yy == y + 1){
			if (xx == x - 1 || xx == x + 1){
				result = true;
			}
		}
	} else {
		//bialy
		if (yy == y -1){
			if (xx == x - 1 || xx == x + 1){
				result = true;
			}		
		}
	}
	
	return result;
}

#endif