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
	string linea1;
	char temp1[linea1.size() + 1];

	string linea2;
	char temp2[linea2.size() + 1];

	string linea3;
	char temp3[linea3.size() + 1];

	string linea4;
	char temp4[linea4.size() + 1];

	string linea5;
	char temp5[linea5.size() + 1];


	Tarea *t = new Tarea("", 0, 0, "", "");
	ifstream fichero("Tareas.txt");
	if( fichero.fail() )
	{
	   cout << "No existe el fichero!" << endl;
	   exit(1);
	}

	while (!fichero.eof())
	{
		int i=0;
		for (i = 0; i < 5; i++)
		{
			if (!fichero.eof())
			{
				if(i==4)
				{
					getline(fichero,linea1);
					cout << linea1 << endl;//Prueba

					strcpy(temp1, linea1.c_str()); // @suppress("Invalid arguments")
					t->setDescripcion(temp1);

				}else
				{

					if(i==0)
					{
						fichero >> linea2;
						cout << linea2 << endl;//Prueba
						//char as[]=linea;
						//wfdc=linea;

						strcpy(temp2, linea2.c_str());
						t->setFecha(temp2);
					}
					if(i==1)
					{
						fichero >> linea4;
						cout << linea4 << endl;//Prueba
						//char as[]=linea;
						//wfdc=linea;

						strcpy(temp4, linea4.c_str());

						t->setDuracion(atoi(temp4));
						//cout << "edewcwef" << endl;
					}
					if(i==2)
					{
						fichero >> linea5;
						cout << linea5 << endl;//Prueba
						//char as[]=linea;
						//wfdc=linea;

						strcpy(temp5, linea5.c_str());

						t->setImportancia(atoi(temp5));
					}
					if(i==3)
					{
						fichero >> linea3;
						cout << linea3 << endl;//Prueba
						//char as[]=linea;
						//wfdc=linea;

						strcpy(temp3, linea3.c_str());
						t->setTitulo(temp3);
					}

				}

			}
		}
		insertarTareas(db, t); // @suppress("Invalid arguments")

	}
	fichero.close();
}

