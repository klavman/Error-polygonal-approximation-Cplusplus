/*! 
  \file punto2D.hpp
  \brief Punto2D representa la clase punto del plano euclídeo
  \author Francisco Javier Clavero Alvarez
  \date 16-02-2015
*/

#ifndef __PUNTO2D_HPP__
#define __PUNTO2D_HPP__

#include <iostream>
#include <cassert>

namespace ed{

//!  Definición de la clase Punto2D
class Punto2D
{

//! \name Atributos privados de la clase Punto2D
private:

	float _x; //!< abscisa del Punto2D 
	float _y; //!< ordenada del Punto2D 

public:

	//! \name Constructores de la clase Punto2D
	/*! 
		\brief Constructor que crea un Punto2D a partir de sus coordenadas x e y
		\attention Función sobrecargada        
	 	\note Los parámetros tienen valores por defecto
		\param x de tipo float, valor por defecto 0.0
		\param y de tipo float, valor por defecto 0.0
		\pre Ninguna
		\post Ninguna
		\sa setX(), setY()
	*/

	inline Punto2D(float x=0.0, float y=0.0)
	{
		setX(x);
		setY(y);
	}


	/*! 
		\brief Devuelve la coordenadas "x" de un Punto2D
		\return componente "x" del Punto2D tipo float
		\pre El Punto2D debe existir
		\post Ninguna
		\sa getY()
	*/

	inline float getY()const { return _y; }

	/*! 
		\brief Devuelve la coordenadas "y" de un Punto2D
		\return componente "y" del Punto2D tipo float
		\pre El Punto2D debe existir
		\post Ninguna
		\sa getX()
	*/

	inline float getX()const { return _x; }

	/*! 
		\brief Asigna un valor "w" a la coordenada "x" de un Punto2D
		\param w de tipo float
		\pre El Punto2D debe existir
		\post Ninguna
		\sa setX()
	*/

	inline void setX(float w) { _x = w; }

	/*! 
		\brief Asigna un valor "w" a la coordenada "y" de un Punto2D
		\param w de tipo float
		\pre El Punto2D debe existir
		\post Ninguna
		\sa setY()
	*/

	inline void setY(float w) { _y = w; }

	/*! 
		\brief Comprueba que los dos puntos son iguales
		\return Valor booleano true = Iguales, false != Iguales
		\pre Los Puntos2D deben existir
		\post Ninguna
		\sa getX(), getY()
	*/

	inline bool sonIguales(Punto2D &p) 
	{
		return ((getX() == p.getX()) && (getY() == p.getY()));
	}

	/*! 
		\brief Asigna las coordenadas "x" e "y" a un Punto2D desde teclado.
		\pre El Punto2D debe existir
		\post Ninguna
		\sa setX(), setY()
	*/
	
	inline void leerPunto2D()
	{
		float x;
		float y;

		std::cout << "Coor x: " << std::endl;
		std::cin >> x;

		std::cout << "Coor y: " << std::endl;
		std::cin >> y;

		setX(x);
		setY(y);
	}

	/*! 
		\brief Escribe las coordenadas de un Punto2D por pantalla de la forma [x,y]
		\pre El Punto2D debe asignado un valor en sus coordenadas.
		\post Ninguna
		\sa getX(), getY()
	*/
	inline void escribirPunto2D()
	{
		std::cout << "[" << getX() << "," << getY() << "]" << std::endl;
	}

};

} // namespace ed

#endif