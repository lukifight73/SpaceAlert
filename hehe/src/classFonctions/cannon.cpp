#include "../include/cannon.hpp"
#include "SA_Values.hpp"

cannon::cannon()
{
}
cannon::cannon(std::string cannon, int puissance, int portee, int type)
{
	nom_cannon = cannon;
	puissance_cannon = puissance;
	portee_cannon = portee;
	type_cannon = type;
}

void cannon::debuf_puissance_cannon(int debuf)
{
	puissance_cannon -= debuf;
	if (puissance_cannon < 0)
		puissance_cannon = 0;
}

void cannon::setpuissance_cannon(int input)
{
	puissance_cannon = input;
}

void cannon::setportee_cannon(int input)
{
	portee_cannon = input;
}

int cannon::getpuissance_cannon() const
{
	return (puissance_cannon);
}

int cannon::getportee_cannon() const
{
	return (portee_cannon);
}

int cannon::gettype_cannon() const
{
	return (type_cannon);
}

std::string cannon::getnom_cannon () const
{
	return (nom_cannon);
}

void cannon::debuf_portee_cannon(int debuf)
{
	portee_cannon -= debuf;
	if (portee_cannon < 0)
		portee_cannon = 0;
}

cannon::~cannon() {}
