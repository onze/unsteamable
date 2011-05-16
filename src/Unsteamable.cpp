/*
 * Unsteamable.cpp
 *
 *  Created on: 2011-05-06
 *      Author: onze
 */

#include <iostream>

#include <Unsteamable.h>
#include <Level.h>

using namespace std;

Unsteamable::Unsteamable()
{
	Steel::Engine engine();
}

Unsteamable::~Unsteamable()
{
}

void Unsteamable::run(void)
{
//	cout << "Unsteamable::go()" << endl;

	int width = 800, height = 600;

	mEngine.init("plugins.cfg", false, width, height, "Unsteamable");

	//TODO: intro cinematic
	//TODO: menu: play/options
	//TODO: for level in levels:

	//load next level
	Steel::Level level(&mEngine);
	mEngine.mainLoop();
	//TODO: ending cinematic
	//credits
}
