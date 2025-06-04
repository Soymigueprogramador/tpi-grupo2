// Incluyendo librerias de C++.
#include <iostream>
#include <cstring>
#include <limits>
#include <cstdlib> 
#include <ctime>

using namespace std;

// Funcion para mostrar el menu.
int menuOpciones()
{

    // Variables para guardar la opcion seleccionada y validar si la opcion ingresada el valida o no.
    int opciones;
    bool opcionValida = false;

    // Ciclo do while para crear el listado de opciones.
    do
    {
        cout << " MENU DE OPCIONES " << endl;
        cout << "------------------------------------------------------------------------------------------------------------------------" << endl;
        cout << " Opcion 1 Jugar " << endl;
        cout << " Opcion 2 Estadistica " << endl;
        cout << " Opcion 3 Creditos " << endl;
        cout << " Opcion 0 Salir " << endl;
        cout << "------------------------------------------------------------------------------------------------------------------------" << endl;

        cout << " Ingresa un opcion " << endl;
        cin >> opciones;

        // Condicional para la validacion del ingreso de las opciones.
        if (cin.fail())
        {
            cin.clear(); // Se usa para limpiar errores.
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << " Ingreso invalido " << endl;
            system( " pause " );
        }
        else if (opciones >= 0 && opciones <= 3)
        {
            opcionValida = true;
        }
        else
        {
            cout << " La opcion " << opciones << " ingresada no es valida " << endl;
        }
    } while (!opcionValida);

    return opciones;
}

int main()
{
    int opcion;
    bool finalizar = false;

    /*
        1- Mientras sea diferente a finalizar se mostrara el menu con las opciones.
        2- Se usa un switch como condicional para que se ejecute la opcion ingresada por el usuario.
        3- A medida de que el juego sea desarrollado se debera ir modificando el menu de iociones.
    */
    while (!finalizar)
    {
        system( " cls " );
        opcion = menuOpciones();

        switch (opcion)
        {
        case 0:
            cout << " Saliste del juego " << endl;
            finalizar = true;
            break;

        case 1:
            cout << " Comenzara el juego " << endl;
            system( " pause " );
            break;

        case 2:
            cout << " Se mostraran las estadisticas del juego " << endl;
            system( " pause " );
            break;

        case 3:
            cout << " Se mostraran los creditos del juego " << endl;
            system( " pause " );
            break;
        }
    }

    return 0;
}