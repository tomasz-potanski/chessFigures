#ifndef KON_HPP
#define KON_HPP

#include "figury.hpp"
#include "figura.hpp"
#include <assert.h>
#include <cmath>

class Kon : public Figura
{
        public:
		bool czyBijeToPole(int xx, int yy);
             Kon();
			 Kon(int xx, int yy);

};

Kon::Kon() : Figura::Figura(){
	czymJestem = kon;
}

Kon::Kon(int xx, int yy) : Figura(xx, yy){
	czymJestem = kon;
}

bool Kon::czyBijeToPole(int xx, int yy){
	//if (czyZainicjalizowanoX == false || czyZainicjalizowanoY == false){
		//throw (-1);

	//}
	assert(czyZainicjalizowanoX == true && czyZainicjalizowanoY == true);
	bool result = false;
	if (xx == x && yy == y){
		result = true;
	}
	if ((std::abs((float)(xx-x)) == 2 && std::abs ((float)(yy-y))==1) || (std::abs((float)(xx-x)) == 1 && std::abs ((float)(yy-y))==2)){
		result = true;
	}
	return result;
}

#endif
