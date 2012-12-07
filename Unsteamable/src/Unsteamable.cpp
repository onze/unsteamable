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

    unsigned int width = 1280, height = 968;
    mEngine->init("plugins.cfg", false, width, height, "Unsteamable");
    mEngine->setRootDir(Steel::File::getCurrentDirectory());

    mEngine->startEditMode();

    //TODO: intro cinematic
    //TODO: menu: play/options
    //TODO: for level in levels:

    //while (has next level)
    //load next level
    Steel::Level *level = mEngine->createLevel("PG01-dev");
    level->load();

    Debug::log("starting main loop").endl();
    
    mEngine->mainLoop();
    //TODO: ending cinematic
    //credits
    Debug::log("usmb done, exiting now.").endl();
}
// kate: indent-mode cstyle; indent-width 4; replace-tabs on; 
