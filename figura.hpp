#ifndef FIGURA_HPP
#define FIGURA_HPP

#include "figury.hpp"
#include <string>
#include <cstdio>
#include <sstream>
#include <iostream>

class Figura{

   public:
      /** Mówi, czy ta figura bije pole, ktorego
		wspolrzedne sa podane jako parametr.
	  pure virtaul function
	  @param xx wspolrzedna x pola, ktore sprawdzamy
	  @param yy wspolrzedna y pola, ktore sprawdzamy
	  */
      virtual bool czyBijeToPole(int xx, int yy) = 0;
	  /**
	  Konstruktor umiejscawiajacy figure na plaszy
	  @param x wspolrzedna pozioma
	  @param y wspolrzedna pionowa
	  */
	  Figura(int xx, int yy);
	  /**
	  Konstruktor nie umiejscawiajacy figury
	  */
	  Figura();
	  /**
	  Setter wspolrzednej poziomej
	  @param xx wspolrzedna pozioma
	  */
	  void setX(int xx);
	  /**
	  Setter wspolrzednej pionowej
	  @param y wspolrzedna pionowa
	  */
	  void setY(int yy);
	  /**
	  Metoda ustawia figure w danym miejscu na planszy
	  @param xx wsporzedna pozioma
	  @param yy wsporzedna pionowa
	  */
	  void setPosition(int xx, int yy);
		std::string toString()const;
		friend std::ostream & operator<< (std::ostream &wyjscie, const Figura &f);
   private:

	protected:
      int x;      /**< wspolrzedna x*/
      int y;     /**< wspolrzedna y*/
		figury czymJestem;	/**< rodzaj figury*/
	  bool czyZainicjalizowanoX;
	  bool czyZainicjalizowanoY;
};

std::string Figura::toString()const{
	char message[70];
	char rodzaj [50] = "pionek";
	if (czymJestem == wieza){
		sprintf(rodzaj,"wieza");
	} else if (czymJestem == goniec){
		sprintf(rodzaj,"goniec");
	} else if (czymJestem == kon){
		sprintf(rodzaj,"kon");
	} else if (czymJestem == krol){
		sprintf(rodzaj,"krol");
	} else if (czymJestem == hetman){
		sprintf(rodzaj,"hetman");
	}
	sprintf(message, "%s: (%d, %d)", rodzaj, x, y);	
	return std::string(message);
}					

std::ostream & operator<< (std::ostream &wyjscie, const Figura &f){
	return wyjscie << f.toString();
}

Figura::Figura(){
	czyZainicjalizowanoX = false;
	czyZainicjalizowanoY = false;
}

Figura::Figura(int xx, int yy){
	x = xx;
	y = yy;
	czyZainicjalizowanoX = true;
	czyZainicjalizowanoY = true;
}

void Figura::setPosition(int xx, int yy){
	x = xx;
	y = yy;
	czyZainicjalizowanoX = true;
	czyZainicjalizowanoY = true;
}

void Figura::setX(int xx){
	x = xx;
	czyZainicjalizowanoX = true;
}

void Figura::setY(int yy){
	y = yy;
	czyZainicjalizowanoY = true;
}



#endif