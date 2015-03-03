/*! 
  \file recta2D.hpp
  \brief Recta2D modela una recta en el plano
  \author Francisco Javier Clavero Alvarez
  \date 16-02-2015
*/

#ifndef __RECTA2D_HPP__
#define __RECTA2D_HPP__

#include <iostream>
#include <cmath>
#include <cassert>
#include "punto2D.hpp"

namespace ed {

//!  Definición de la clase Recta2D
class Recta2D
{

//! \name Atributos privados de la clase Recta2D
private:

	float _a; //!< coeficiente a de la recta 
	float _b; //!< coeficiente b de la recta
	float _c; //!< coeficiente c de la recta

public:


	//! \name Constructores de la clase Recta2D
	/*! 
		\brief Constructor que crea una Recta2D a partir de los coeficientes a, b, c usando la ecuación implícita ax+by+c=0       
	 	\note Los parámetros tienen valores por defecto
		\param a de tipo float, valor por defecto 0.0
		\param b de tipo float, valor por defecto 0.0
		\param c de tipo float, valor por defecto 0.0
		\pre Ninguna
		\post Ninguna
		\sa setA(), setB(), setC()
	*/

	inline Recta2D(float a=0.0, float b=0.0, float c=0.0)
	{
		setA(a);
		setB(b);
		setC(c);
	}

	/*! 
		\brief Constructor que crea una Recta2D a partir de dos Puntos2D      
		\pre Los puntos deben existir y ser distintos.
		\post Ninguna
		\sa setA(), setB(), setC(), getX(), getY()
	*/


	inline Recta2D(Punto2D &p1, Punto2D &p2)
	{
		assert(!p1.sonIguales(p2));
		float a, b, c;

		c = p1.getY() * p2.getX() - p1.getX() * p2.getY();
	   	a = p2.getY() - p1.getY();
		b = p1.getX() - p2.getX();

		setA(a);
		setB(b);
		setC(c);
	}

	/*! 
		\brief Funcion que calcula la distancia de un punto a una recta.  
		\return Valor distancia de tipo float.     
		\pre El Punto2D y la recta2D deben estar definidos.
		\post Ninguna
		\sa getA(), getB(), getC(), getX(), getY()
	*/


	inline float distanciaPuntoRecta(Punto2D &p)
	{

		float a, b, c;
		float x, y;

		a = getA();
		b = getB();
		c = getC();

		x = p.getX();
		y = p.getY();

		return std::abs(a * x + b * y + c) / sqrt(pow(a,2) + pow(b,2));

	}

	/*! 
		\brief Asigna un valor "w" al coeficiente a de la Recta2D
		\param w de tipo float
		\pre La Recta2D debe existir
		\post Ninguna
		\sa setA()
	*/

	inline void setA(float w) { _a = w; }

	/*! 
		\brief Asigna un valor "w" al coeficiente a de la Recta2D
		\param w de tipo float
		\pre La Recta2D debe existir
		\post Ninguna
		\sa setB()
	*/

	inline void setB(float w) { _b = w; }

	/*! 
		\brief Asigna un valor "w" al coeficiente a de la Recta2D
		\param w de tipo float
		\pre La Recta2D debe existir
		\post Ninguna
		\sa setB()
	*/

	inline void setC(float w) { _c = w; }


	/*! 
		\brief Devuelve el coeficiente "a" de la Recta2D
		\return coeficiente "a" de la Recta2D tipo float
		\pre La Recta2D debe existir
		\post Ninguna
		\sa getA()
	*/

	inline float getA()const { return _a; }

	/*! 
		\brief Devuelve el coeficiente "b" de la Recta2D
		\return coeficiente "b" de la Recta2D tipo float
		\pre La Recta2D debe existir
		\post Ninguna
		\sa getB()
	*/

	inline float getB()const { return _b; }

	/*! 
		\brief Devuelve el coeficiente "c" de la Recta2D
		\return coeficiente "c" de la Recta2D tipo float
		\pre La Recta2D debe existir
		\post Ninguna
		\sa getC()
	*/

	inline float getC()const { return _c; }

	/*! 
		\brief Asigna coeficientes "a", "b" y "c" leídas desde el teclado
		\pre La Recta2D debe existir
		\post Ninguna
		\sa setA(), setB(), setC()
	*/

	inline void leerRecta2D() 
	{ 
		float a;
		float b;
		float c;

		std::cout << "Coef. a: " << std::endl;
		std::cin >> a;

		std::cout << "Coef. b: " << std::endl;
		std::cin >> b;

		std::cout << "Coef. c: " << std::endl;
		std::cin >> c;		

		setA(a);
		setB(b);
		setC(c);
	}

	/*! 
		\brief Escribe por pantalla la Recta2D de la forma ax+by+c=0
		\pre Los coeficientes 
		\post Ninguna
		\sa getA(), getB(), getC()
	*/

	inline void escribirRecta2D() // Corregir para cuando falta algun coeficiente.
	{

		std::cout << getA() << "x+" << getB() << "y+" << getC() << "=0" << std::endl;

	}


};

} // namespace ed

#endif