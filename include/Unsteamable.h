/*
 * Unsteamable.h
 *
 *  Created on: 2011-05-06
 *      Author: onze
 */

#ifndef UNSTEAMABLE_H_
#define UNSTEAMABLE_H_

#include <Engine.h>

class Unsteamable
{
public:
	Unsteamable();
	virtual ~Unsteamable();
	void go(void);
protected:
	Steel::Engine engine;
};

#endif /* UNSTEAMABLE_H_ */
