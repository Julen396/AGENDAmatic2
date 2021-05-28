#include <windows.h>
#include <cstdlib>
#include <iostream>


#include "Fichero.h"
#include "BaseDatos.h"

using namespace std;

int GetInput()
{
   int choice;
   cin >> choice;
   return choice;
}

void MostrarMenuPrincipal()
{
	cout << "¡Bienvenid@ a AgendaMatic! (V 2.0)\n";
    cout << "Por favor, haz tu selección:\n";
    cout << "1 - X\n";
    cout << "2 - Y\n";
    cout << "3 - Salir\n";
    cout << "Opcion: ";
}

int main(int argc, char *argv[])
{
    int choice = 0;

    do
    {
       system("cls");
       MostrarMenuPrincipal();
       choice = GetInput();
       switch(choice) {
               case 1:
                       cout << "Has elegido la opción 1\n";
                       break;
               case 2:
            	   	   cout << "Has elegido la opción 2\n";
                       break;
               case 3:
                       cout << "Gracias por usar AgendaMatic, ¡nos vemos!";
                       break;

               default:
                       break;
              }
      } while(choice!=3);
    system("PAUSE");
    return EXIT_SUCCESS;
}
