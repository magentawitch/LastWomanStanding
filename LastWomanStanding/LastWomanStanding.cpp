#pragma once
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <cstdio>
#include "Guerrera.h"
#include <ctime>

using namespace std;

#define NUMGUERRERAS 10

//cantidad de vivos


int cantidadVivos(Guerrera* Equipo[])
{
    int totalVivos = 0;
    for (int i = 0; i < NUMGUERRERAS; i++)
    {
        if (Equipo[i]->estadoVida() == true)
        {
            totalVivos++;
        }
    }
    return totalVivos;
}



//turno

void turno(Guerrera* jugador[], Guerrera* enemigo[])
{
    if (cantidadVivos(jugador) > 0)
    {
        cout << "\nEstas son tus guerreras: " << endl;
        int i = 0;
        while (i < NUMGUERRERAS)
        {
            cout << "\nGuerrera " << i + 1 << endl;
            jugador[i]->dejarDeDefender();
            jugador[i]->imprimirEstadoGuerrera();
            i++;
        }

        cout << "\nSelecciona el numero de la guerrera con la que queres jugar este turno: " << endl;

        short indiceElegido;
        cin >> indiceElegido;


        while (indiceElegido <= 0 || indiceElegido > NUMGUERRERAS || jugador[indiceElegido - 1]->estadoVida() == false)
        {
            if (indiceElegido <= 0 || indiceElegido > NUMGUERRERAS)
            {
                cout << "\nEl numero introducido no es valido. Ingresalo de nuevo: " << endl;
                cin >> indiceElegido;

            }
            if (jugador[indiceElegido - 1]->estadoVida() == false)
            {
                cout << "\nLa guerrera esta muerta. Elegi una nueva guerrera: " << endl;
                cin >> indiceElegido;
            }
        }
        Guerrera* elegida = jugador[indiceElegido - 1];


        cout << "\nSelecciona que queres hacer este turno. Para eso debes introducir el numero correspondiente: " << endl;
        cout << "1) Atacar con arma. \n2) Atacar con hechizo. \n3) Defender. " << endl;
        short accion;
        cin >> accion;

        if (accion == 2)
        {
            int mana = elegida->estadoMana();
            if (mana == 0)
            {
                cout << "No tienes suficiente mana para conjurar el hechizo. Elige otra accion." << endl;
                cout << "1) Atacar con arma. \n3) Defender. " << endl;
                cin >> accion;
                while (accion == 2)
                {
                    cout << "No tienes suficiente mana para conjurar el hechizo. Elige otra accion." << endl;
                    cout << "1) Atacar con arma. \n3) Defender. " << endl;
                    cin >> accion;
                }
            }
        }

        if (accion == 1 || accion == 2)
        {

            cout << "\nEstas son las guerreras enemigas: " << endl;

            int i2 = 0;
            while (i2 < NUMGUERRERAS)
            {
                cout << "\nGuerrera " << i2 + 1 << endl;
                enemigo[i2]->imprimirEstadoGuerrera();
                i2++;
            }

            cout << "\nSelecciona el numero de la guerrera enemiga a la que queres atacar este turno: " << endl;

            short indiceEnemigo;
            cin >> indiceEnemigo;

            while (indiceEnemigo <= 0 || indiceEnemigo > NUMGUERRERAS || enemigo[indiceEnemigo - 1]->estadoVida() == false)
            {
                if (indiceEnemigo <= 0 || indiceEnemigo > NUMGUERRERAS)
                {
                    cout << "\nEl numero introducido no es valido. Ingresalo de nuevo: " << endl;
                    cin >> indiceEnemigo;
                }

                if (enemigo[indiceEnemigo - 1]->estadoVida() == false)
                {
                    cout << "\nLa guerrera esta muerta. Elegi una nueva guerrera: " << endl;
                    cin >> indiceEnemigo;
                }

            }



            Guerrera* enemiga = enemigo[indiceEnemigo - 1];

            if (accion == 1)
            {
                int dano = elegida->atacarConArma();
                cout << "\nEl dano realizado es de " << dano << "." << endl;
                enemiga->recibirDano(dano);
            }

            if (accion == 2)
            {
                int dano = elegida->atacarConHechizo();
                cout << "\nEl dano realizado es de " << dano << "." << endl;
                enemiga->recibirDano(dano);
            }
        }

        if (accion == 3)
        {
            elegida->defender();
        }
    }

}


int main()
{
    srand(time(NULL));
    //array de equipos
    Guerrera* Magenta[NUMGUERRERAS];
    Guerrera* Violeta[NUMGUERRERAS];

    //composicion de equipos
    for (int i = 0; i < NUMGUERRERAS; i++)
    {
        int clase = rand() % 3;

        switch (clase)
        {
        case 0:
            Magenta[i] = new Maga();
            Violeta[i] = new Paladin();
            break;
        case 1:
            Magenta[i] = new Druida();
            Violeta[i] = new Maga();
            break;
        case 2:
            Magenta[i] = new Paladin();
            Violeta[i] = new Druida();
            break;
        }
    }

    cout << "Este es un juego por turnos. Tienes un equipo de " << NUMGUERRERAS << " guerreras con diferentes especializaciones. "
        "Tu objetivo es derribar a todas las guerreras del equipo contrario." << endl;

    while (cantidadVivos(Magenta) != 0 && cantidadVivos(Violeta) != 0)
    {
        if (cantidadVivos(Magenta)> 0)
        {
            cout << "\nEs el turno de las guerreras Magenta. " << endl;
            turno(Magenta, Violeta);
        }
        if (cantidadVivos(Violeta) > 0)
        {
            cout << "\nEs el turno de las guerreras Violeta. " << endl;
            turno(Violeta, Magenta);
        }

        if (cantidadVivos(Magenta) == 0)
        {

            cout << "\nEl equipo Violeta ha eliminado todas las guerreras adversarias y es, por lo tanto, "
                "el equipo ganador." << endl;
        }

        if (cantidadVivos(Violeta) == 0)
        {
            cout << "\nEl equipo Magenta ha eliminado todas las guerreras adversarias y es, por lo tanto, "
                "el equipo ganador." << endl;
        }

    }

 
     
}

