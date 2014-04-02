#ifndef WIEZA_HPP
#define WIEZA_HPP

#include "figury.hpp"
#include "figura.hpp"
#include <assert.h> 

class Wieza : public Figura
{					
        public:
		bool czyBijeToPole(int xx, int yy);
             Wieza();
			 Wieza(int xx, int yy);
		
};

Wieza::Wieza() : Figura::Figura(){
	czymJestem = wieza;
}

Wieza::Wieza(int xx, int yy) : Figura(xx, yy){
	czymJestem = wieza;
}

bool Wieza::czyBijeToPole(int xx, int yy){
	//if (czyZainicjalizowanoX == false || czyZainicjalizowanoY == false){
		//throw (-1);
		
	//}	
	assert(czyZainicjalizowanoX == true && czyZainicjalizowanoY == true);
	bool result = false;
	if (xx == x && yy == y){
		result = true;
	}
	if (xx == x || yy == y){
		result = true;
	}
	return result;
}

#endif