/*
 * BaseDatos.h
 *
 *  Created on: 18 may. 2021
 *      Author: Julen
 */
#include <stdio.h>
#include "sqlite3.h"
#include <string.h>
#include "Tarea.h";

#ifndef BASEDATOS_H_
#define BASEDATOS_H_


int insertNewCountry(sqlite3 *db, Tarea *tarea);


#endif /* BASEDATOS_H_ */
