/*
 * Unsteamable.h
 *
 *  Created on: 2011-05-06
 *      Author: onze
 */

#ifndef UNSTEAMABLE_H_
#define UNSTEAMABLE_H_

#include <Engine.h>
#include "InputManager.h"

class Unsteamable
{
public:
	Unsteamable();
	virtual ~Unsteamable();
	void run(void);
protected:
	Steel::Engine mEngine;
};

#endif /* UNSTEAMABLE_H_ */
