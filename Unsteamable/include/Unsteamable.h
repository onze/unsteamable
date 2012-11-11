/*
 * Unsteamable.h
 *
 *  Created on: 2011-05-06
 *      Author: onze
 */

#ifndef UNSTEAMABLE_H_
#define UNSTEAMABLE_H_

#include <Engine.h>

#include "unsteamabletypes.h"
#include "InputManager.h"

class Unsteamable
{
public:
	Unsteamable();
	virtual ~Unsteamable();
	void run();
protected:
	Steel::Engine *mEngine;
};

#endif

/*UNSTEAMABLE_H_ */
