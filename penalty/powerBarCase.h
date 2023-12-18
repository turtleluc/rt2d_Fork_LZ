/**
 * Copyright 2015 Your Name <you@yourhost.com>
 *
 * @file myentity.h
 *
 * @brief description of MyEntity behavior.
 */

#ifndef POWERBARCASE_H
#define POWERBARCASE_H

#include <rt2d/entity.h>
#include "projects/raycast/raycast.h"

 /// @brief The MyEntity class is the Entity implementation.
class powerBarCase : public Entity
{
public:
	/// @brief Constructor
	powerBarCase();
	/// @brief Destructor
	virtual ~powerBarCase();

	/// @brief update is automatically called every frame
	/// @param deltaTime the elapsed time in seconds
	/// @return void
	virtual void update(float deltaTime);


private:
	/* add your private declarations */
	
};

#endif /* MYENTITY_H */
