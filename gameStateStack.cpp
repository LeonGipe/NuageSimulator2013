#include "gameStateStack.hpp"

void gameStateStackClass::set(gameStateClass* state)
{
	while(!stateList.empty())
	{
		pop();
	}
	add(state);
}

void gameStateStackClass::add(gameStateClass* state)
{
	change = true;
	stateList.push_back(std::unique_ptr<gameStateClass>(state));
}

void gameStateStackClass::pop()
{
	change = true;
	if(!stateList.empty())
	{
		stateList.pop_back();
	}
}

void gameStateStackClass::update()
{
	if(!stateList.empty())
	{
		stateList.back()->update();
	}
}

void gameStateStackClass::draw()
{
	if(!stateList.empty())
	{
		stateList.back()->draw();
	}
}

bool gameStateStackClass::getChange()
{
	return change;
}

void gameStateStackClass::setChange(bool val)
{
	change = val;
}
