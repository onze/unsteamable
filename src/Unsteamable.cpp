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
	mEngine=new Steel::Engine();
}

Unsteamable::~Unsteamable()
{
}

void Unsteamable::run()
{
	cout << "Unsteamable::run()" << endl;

	int width = 800, height = 600;
	mEngine->init("plugins.cfg", false, width, height, "Unsteamable");

	//TODO: intro cinematic
	//TODO: menu: play/options
	//TODO: for level in levels:

	//load next level
	cout << "load level" << endl;
	Steel::Level *level = mEngine->createLevel("MyLevel");
	if (level == NULL)
		Debug::log("could not load level.").endl();

	Debug::log("launching main loop").endl();
	mEngine->mainLoop();
	//TODO: ending cinematic
	//credits
	Debug::log("run over. (a child)").endl();
}
