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

#include "BaseDatos.h"
#include "Tarea.h"
#include <String.h>

void leerFichero(sqlite3 *db)
{
	string linea;
	//Tarea tarea("", 0, 0, "", "");
	//char temp[]="";
	char temp[linea.size() + 1];
	Tarea *t = new Tarea("", 0, 0, "", "");
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

					strcpy(temp, linea.c_str()); // @suppress("Invalid arguments")
					t->setDescripcion(temp);

				}else
				{
					fichero >> linea;
					cout << linea << endl;//Prueba
					//char as[]=linea;
					//wfdc=linea;

					strcpy(temp, linea.c_str());
					if(i==0)
					{
						t->setFecha(temp);
					}
					if(i==1)
					{
						t->setDuracion((int)temp);
						//cout << "edewcwef" << endl;
					}
					if(i==2)
					{
						t->setImportancia((int)temp);
					}
					if(i==3)
					{
						t->setTitulo(temp);
					}

				}

			}
		}
		insertNewCountry(db, t); // @suppress("Invalid arguments")

	}
	fichero.close();
}

