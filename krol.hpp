#ifndef KROL_HPP
#define KROL_HPP

#include "figury.hpp"
#include "figura.hpp"
#include <assert.h>
#include <cmath>

class Krol : public Figura
{
        public:
		bool czyBijeToPole(int xx, int yy);
             Krol();
			 Krol(int xx, int yy);

};

Krol::Krol() : Figura::Figura(){
	czymJestem = krol;
}

Krol::Krol(int xx, int yy) : Figura(xx, yy){
	czymJestem = krol;
}

bool Krol::czyBijeToPole(int xx, int yy){
	//if (czyZainicjalizowanoX == false || czyZainicjalizowanoY == false){
		//throw (-1);

	//}
	assert(czyZainicjalizowanoX == true && czyZainicjalizowanoY == true);
	bool result = false;
	if (xx == x && yy == y){
		result = true;
	}
	if (std::abs((float)(x-xx))<= 1 && std::abs((float)(y-yy))<=1){
		result = true;
	}
	return result;
}

#endif
