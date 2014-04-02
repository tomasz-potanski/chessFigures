#ifndef HETMAN_HPP
#define HETMAN_HPP

#include "figury.hpp"
#include "figura.hpp"
#include <assert.h> 

class Hetman : public Figura
{					
        public:
		bool czyBijeToPole(int xx, int yy);
             Hetman();
			 Hetman(int xx, int yy);
		
};

Hetman::Hetman() : Figura::Figura(){
	czymJestem = hetman;
}

Hetman::Hetman(int xx, int yy) : Figura(xx, yy){
	czymJestem = hetman;
}

bool Hetman::czyBijeToPole(int xx, int yy){
	//if (czyZainicjalizowanoX == false || czyZainicjalizowanoY == false){
		//throw (-1);
		
	//}	
	assert(czyZainicjalizowanoX == true && czyZainicjalizowanoY == true);
	bool result = false;
	if (xx == x && yy == y){
		result = true;
	}
	int delta = x - xx;
	if (delta == y - yy || delta == yy - y || xx == x || yy == y){
		result = true;
	}
	return result;
}

#endif