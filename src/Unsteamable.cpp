/*
 * Unsteamable.cpp
 *
 *  Created on: 2011-05-06
 *      Author: onze
 */

#include <iostream>

#include <OgreWindowEventUtilities.h>

#include <Unsteamable.h>

using namespace std;

Unsteamable::Unsteamable()
{
	Steel::Engine engine();
}

Unsteamable::~Unsteamable()
{
}

void Unsteamable::go(void)
{
	cout << "Unsteamable::go()" << endl;

	engine.init("plugins.cfg",false,800,600,"Unsteamable");

	while (true)
	{
		// Pump window messages for nice behaviour
		Ogre::WindowEventUtilities::messagePump();

		if (engine.renderWindow()->isClosed()) break;

		if (!engine.update()) break;
	}
}
