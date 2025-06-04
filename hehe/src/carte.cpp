#include "carte.hpp"
#include "space_alerte_values.hpp"

carte::carte()
{
	c_action = INACTIF;
}

carte::carte(int action)
{
	c_action = action;
}

void carte::setc_action(int input)
{
	c_action = input;
}

int carte::getc_action() const
{
	return (c_action);
}

carte::~carte() {}
