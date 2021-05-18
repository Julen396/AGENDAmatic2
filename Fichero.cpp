/*
 * Fichero.cpp
 *
 *  Created on: 18 may. 2021
 *      Author: Julen
 */
#include "Fichero.h"
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
using namespace std;

void leerFichero()
{
	string nombre;
	string linea;

	ifstream fichero("Tareas.txt");
	if( fichero.fail() )
	{
	   cout << "No existe el fichero!" << endl;
	   exit(1);
	}

	while (!fichero.eof())
	{
		for (int i = 0; i < 5; i++)
		{
			if (!fichero.eof())
			{
				if(i==4)
				{
					getline(fichero,linea);
					cout << linea << endl;//Prueba
				}else
				{
					fichero >> linea;
					cout << linea << endl;//Prueba
				}

			}
		}
	}
	fichero.close();
}

