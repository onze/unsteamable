/*
 * Unsteamable.cpp
 *
 *  Created on: 2011-05-06
 *      Author: onze
 */

#include <iostream>

#include <Unsteamable.h>
#include <Level.h>
#include <Debug.h>
#include <tools/File.h>

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

    int width = 1280, height = 968;
    mEngine->init("plugins.cfg", false, width, height, "Unsteamable");
    mEngine->setRootDir(Steel::File::getCurrentDirectory());

    //TODO: intro cinematic
    //TODO: menu: play/options
    //TODO: for level in levels:

    //load next level
    Steel::Level *level = mEngine->createLevel("PG01-dev");
    level->load();

    Debug::log("launching main loop").endl();
    mEngine->mainLoop();
    //TODO: ending cinematic
    //credits
    Debug::log("run over. (a child)").endl();
}
// kate: indent-mode cstyle; indent-width 4; replace-tabs on; 
