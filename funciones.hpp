/*! 
  \file funciones.hpp
  \brief  Calcular el error cometido por la aproximación poligonal de un contorno
  \author Francisco Javier Clavero Alvarez
  \date 16-02-2015
*/

#include <vector>
#include "punto2D.hpp"

using namespace ed;

void cargaContorno(std::vector<Punto2D> &contorno, std::string ficheroContorno);

void cargaAproximacionPoligonal (std::vector<int> &aproximacionPoligonal, std::string ficheroAproximacionPoligonal);

double calcularError(const std::vector<Punto2D> &contorno, const std::vector<int> &aproximacionPoligonal);