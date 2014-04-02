#ifndef GONIEC_HPP
#define GONIEC_HPP

#include "figury.hpp"
#include "figura.hpp"
#include <assert.h> 

class Goniec : public Figura
{					
        public:
		bool czyBijeToPole(int xx, int yy);
             Goniec();
			 Goniec(int xx, int yy);
		
};

Goniec::Goniec() : Figura::Figura(){
	czymJestem = goniec;
}

Goniec::Goniec(int xx, int yy) : Figura(xx, yy){
	czymJestem = goniec;
}

bool Goniec::czyBijeToPole(int xx, int yy){
	//if (czyZainicjalizowanoX == false || czyZainicjalizowanoY == false){
		//throw (-1);
		
	//}	
	assert(czyZainicjalizowanoX == true && czyZainicjalizowanoY == true);
	bool result = false;
	if (xx == x && yy == y){
		result = true;
	}
	int delta = x - xx;
	if (delta == y - yy || delta == yy - y){
		result = true;
	}
	return result;
}

#endif