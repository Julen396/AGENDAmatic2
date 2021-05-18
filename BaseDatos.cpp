/*
 * BaseDatos.cpp
 *
 *  Created on: 18 may. 2021
 *      Author: Julen
 */
#include "BaseDatos.h"
#include <stdio.h>
#include "sqlite3.h"
#include <string.h>

#include <string>
using namespace std;

#include "Tarea.h";

int insertNewCountry(sqlite3 *db, Tarea *tarea) {
	sqlite3_stmt *stmt;

	//char *surnamee="Hola";



	char sql[] = "insert into tareas (id, fecha, importancia, duracion, titulo, Descripcion) values (NULL, ?, ?, ?, ?, ?)";
	int result = sqlite3_prepare_v2(db, sql, strlen(sql) + 1, &stmt, NULL) ; // @suppress("Invalid arguments")
	if (result != SQLITE_OK) {
		printf("Error preparing statement (INSERT)\n");
		printf("%s\n", sqlite3_errmsg(db)); // @suppress("Invalid arguments")
		return result;
	}

	printf("SQL query prepared (INSERT)\n");

	result = sqlite3_bind_text(stmt, 1, tarea->getFecha(), strlen(tarea->getFecha()), SQLITE_STATIC); // @suppress("Invalid arguments")
	if (result != SQLITE_OK) {
		printf("Error binding parameters\n");
		printf("%s\n", sqlite3_errmsg(db)); // @suppress("Invalid arguments")
		return result;
	}

	result = sqlite3_bind_int(stmt, 2, tarea->getImportancia()); // // @suppress("Invalid arguments")
	if (result != SQLITE_OK) {
		printf("Error binding parameters\n");
		printf("%s\n", sqlite3_errmsg(db)); // @suppress("Invalid arguments")
		return result;
	}

	result = sqlite3_bind_int(stmt, 3, tarea->getDuracion()); // // @suppress("Invalid arguments")
	if (result != SQLITE_OK) {
		printf("Error binding parameters\n");
		printf("%s\n", sqlite3_errmsg(db)); // @suppress("Invalid arguments")
		return result;
	}

	result = sqlite3_bind_text(stmt, 4, tarea->getTitulo(), strlen(tarea->getTitulo()), SQLITE_STATIC); // @suppress("Invalid arguments")
	if (result != SQLITE_OK) {
		printf("Error binding parameters\n");
		printf("%s\n", sqlite3_errmsg(db)); // @suppress("Invalid arguments")
		return result;
	}

	result = sqlite3_bind_text(stmt, 5, tarea->getDescripcion(), strlen(tarea->getDescripcion()), SQLITE_STATIC); // @suppress("Invalid arguments")
	if (result != SQLITE_OK) {
		printf("Error binding parameters\n");
		printf("%s\n", sqlite3_errmsg(db)); // @suppress("Invalid arguments")
		return result;
	}

	result = sqlite3_step(stmt); // @suppress("Invalid arguments")
	if (result != SQLITE_DONE) {
		printf("Error inserting new data into country table\n");
		return result;
	}

	result = sqlite3_finalize(stmt); // @suppress("Invalid arguments")
	if (result != SQLITE_OK) {
		printf("Error finalizing statement (INSERT)\n");
		printf("%s\n", sqlite3_errmsg(db)); // @suppress("Invalid arguments")
		return result;
	}

	printf("Prepared statement finalized (INSERT)\n");

	return SQLITE_OK;
}



