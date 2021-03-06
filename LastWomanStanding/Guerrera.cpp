#pragma once
#include <iostream>
#include <cmath>
#include <cstdlib>
#include "Guerrera.h"
#include <iomanip>
#include <string>


using namespace std;

int tiradaDados(int m, int n)
{
    //m es cantidad de dados
    //n es caras de dados
    int tirada; //resultado
    int resultado = 0;
    while (m > 0)
    {
        tirada = rand() % n + 1;
        resultado += tirada;
        --m;
    }

    return resultado;
}

Guerrera::Guerrera()
{
    defensa = false;
    vivo = true;
    
}

int Guerrera::atacarConArma()
{
   int dano = tiradaDados(m, n); 
   return dano;
}

int Guerrera::atacarConHechizo()
{
    if (mana > 0)
    {
        mana--;
        return tiradaDados(m, n) + bonoMagico;
    }

}

void Guerrera::defender()
{
    defensa = true;
    armadura *= 2;
}

void Guerrera::dejarDeDefender()
{
    if (defensa == true)
    {
        defensa = false;
        armadura /= 2;
    }
}

void Guerrera::recibirDano(int dano)
{


    if (dano == armadura)
    {
        armadura = 0;
       
    }
    else if (dano > armadura)
    {
        int sobrante;
        sobrante = dano - armadura;

        if (sobrante < vida)
        {
            vida -= sobrante;
            armadura = 0;
           
        }
        if (sobrante >= vida)
        {
            vida -= sobrante;
            armadura = 0;
            vivo = false;
            
        }

    }

}

int Guerrera::estadoArmadura()
{
    return armadura;
}

int Guerrera::estadoMana()
{
    return mana;
}

bool Guerrera::estadoVida()
{
    return vivo;
}

void Guerrera::imprimirEstadoGuerrera()
{
    string estadoVida;
    if (vivo == false)
    {
        estadoVida = "Muerta";
    }

    string estadoDefensa;
    if (defensa == true)
    {
        estadoDefensa = "Activada";
    }
    if (defensa == false)
    {
        estadoDefensa = "Desactivada";
    }


    cout << setw(1) << "---------------------------------------------------------------------------------------------" << endl;
    cout << "| Clase: " << setw(7) << claseGuerrera << ". | ";
    cout << "Vida: " << setw(7);
    if (vivo == false)
    {
        cout << estadoVida << ". | ";
    }
    else
    {
        cout << vida << ". | ";
    }
    cout << "Armadura: " << setw(3) << armadura << ". | ";
    cout << "Mana: " << setw(3)  << mana << ". | ";
    cout << "Defensa: " << setw(14) << estadoDefensa << ". | " << endl;
    cout << setw(1) << "---------------------------------------------------------------------------------------------" << endl;

}



Maga::Maga()
{
    claseGuerrera = "Maga";
    armadura = tiradaDados(1, 6);
    mana = 5;
    vida = tiradaDados(1, 6);
    m = 2;
    n = 4;
    bonoMagico = 4;
    
}

Druida::Druida()
{
    claseGuerrera = "Druida";
    armadura = tiradaDados(1, 8);
    mana = 3;
    vida = tiradaDados(1, 8);
    m = 2;
    n = 6;
    bonoMagico = 3;
}

Paladin::Paladin()
{
    claseGuerrera = "Paladin";
    armadura = tiradaDados(1, 10);
    mana = 2;
    vida = tiradaDados(1, 10);
    m = 1;
    n = 12;
    bonoMagico = 1;
}





