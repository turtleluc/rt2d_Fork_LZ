/**
 * Copyright 2015 Your Name <you@yourhost.com>
 *
 * @file myentity.h
 *
 * @brief description of MyEntity behavior.
 */

#ifndef POWERBAR_H
#define POWERBAR_H

#include <rt2d/entity.h>
#include "projects/raycast/raycast.h"

 /// @brief The MyEntity class is the Entity implementation.
class powerBar : public Entity
{
public:
	/// @brief Constructor
	powerBar();
	/// @brief Destructor
	virtual ~powerBar();

	/// @brief update is automatically called every frame
	/// @param deltaTime the elapsed time in seconds
	/// @return void
	virtual void update(float deltaTime);


private:
	/* add your private declarations */
	
};

#endif /* MYENTITY_H */
