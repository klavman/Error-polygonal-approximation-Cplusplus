/*! 
  \file funciones_axiliares.cpp
  \brief  Calcular el error cometido por la aproximación poligonal de un contorno
  \author Francisco Javier Clavero Alvarez
  \date 16-02-2015
*/

#include <iostream>
#include <vector>

//Para los flujos de entrada/salida en ficheros.
#include <fstream>  
#include <string>

//Para usar exit.
#include <cstdlib> 


#include "funciones.hpp"
#include "recta2D.hpp"



using namespace ed;

  /*! 
    \brief Carga el contorno de puntos leidos desde un fichero a un vector STL
    \param contorno vector de tipo Punto2D.
    \param ficheroContorno tipo string que indica el nombre del fichero.
    \pre Ninguna
    \post Ninguna
  */

void cargaContorno(std::vector<Punto2D> &contorno, std::string ficheroContorno)
{

   std::ifstream leerfichero;
   float x, y;
   Punto2D aux;
   

   //Se abre el fichero para leer.
   leerfichero.open(ficheroContorno.c_str(), std::ios::in); 

   if (!leerfichero)
   {
    std::cout << "Error al abrir el fichero\n";
    exit(1);
   }

   while(leerfichero >> x >> y )
   {
   	 aux.setX(x);
   	 aux.setY(y);
   	 contorno.push_back(aux);
	 }
    


   //Cerramos el fichero.
   leerfichero.close();

}

  /*! 
    \brief Carga los indices de la aproximacion leidos desde un fichero a un vector STL
    \param aproximacionPoligonal vector de tipo entero.
    \param ficheroAproximacionPoligonal tipo string que indica el nombre del fichero de aproximaciones.
    \pre Ninguna
    \post Ninguna
  */

void cargaAproximacionPoligonal (std::vector<int> &aproximacionPoligonal, std::string ficheroAproximacionPoligonal)
{

   std::ifstream leerfichero;
   int n;
   
   //Se abre el fichero para leer.
   leerfichero.open(ficheroAproximacionPoligonal.c_str(), std::ios::in); 

   if (!leerfichero)
   {
    std::cout << "Error al abrir el fichero\n";
    exit(1);
   }

   while(leerfichero >> n)
   	 aproximacionPoligonal.push_back(n);
   

   leerfichero.close(); // Cerrar fichero
}


  /*! 
    \brief Caulcula el error de un contorno referente a su aproximacion poligonal.
    \return El error total de tipo double.
    \pre Los vectores con el contorno y aproximacion deben existir.
    \post Ninguna
    \sa distanciaPuntoRecta()
  */


double calcularError(const std::vector<Punto2D> &contorno, const std::vector<int> &aproximacionPoligonal)
{

  double sum = 0.0;
  double distancia = 0.0;
  int numeroIndices = aproximacionPoligonal.size();
  int N = contorno.size();
   
  for (int i=0; i< numeroIndices-1; i++) // Hasta -1 para que no llegue al ultimo punto (primero)
  {
    int actual = aproximacionPoligonal[i];
    int siguiente = aproximacionPoligonal[(i+1)%numeroIndices];
   
   
    Punto2D p1 = contorno[actual];
    Punto2D p2 = contorno[siguiente];
 
    Recta2D r(p1,p2);
 
    if (actual < siguiente)
    {
     for (int j = actual+1; j < siguiente; j++)
     {

      p1 = contorno[j];
      distancia = r.distanciaPuntoRecta(p1);
      sum += distancia*distancia;
      
     }
    }

    // hay que dividirlo en dos partes:
    // Primero desde actual+1 hasta el indice máximo.
    // Segundo desde 0 hasta indice pedido.

   else
   {
     for (int j = actual+1; j < N; j++)
      {
        p1 = contorno[j];

        distancia = r.distanciaPuntoRecta(p1);
        sum += distancia*distancia;
      }
 
     for (int j = 0; j < siguiente; j++)
      {
        p1 = contorno[j];

        distancia = r.distanciaPuntoRecta(p1);
        sum += distancia*distancia;
      }
   }
  }
 
  return sum;
}