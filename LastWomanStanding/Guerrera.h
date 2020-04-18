#pragma once
#include <string>
class Guerrera
{
protected:
	int armadura; //armadura funciona como vida. Cuando se daña la armadura, se muere la guerrera.
	int mana; //disponible para realizar hechizos
	int m; //cantidad de dados 
	int n; //cara de dados
	int vida;
	bool defensa;
	bool vivo;
	int bonoMagico;
	std::string claseGuerrera;
public:
	Guerrera();
	virtual int atacarConArma();
	virtual int atacarConHechizo();
	virtual void defender();
	virtual void dejarDeDefender();
	virtual void recibirDano(int dano);
	virtual bool estadoVida();
	virtual void imprimirEstadoGuerrera();
	virtual int estadoMana();
	virtual int estadoArmadura();
};

class Maga : public Guerrera
{
public:
	Maga();
};

class Druida : public Guerrera
{
public:
	Druida();
};

class Paladin : public Guerrera
{
public:
	Paladin();
};