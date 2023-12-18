/**
 * Copyright 2015 Your Name <you@yourhost.com>
 *
 * @file myentity.h
 *
 * @brief description of MyEntity behavior.
 */

#ifndef BALLENTITY_H
#define BALLENTITY_H

#include <rt2d/entity.h>
#include "projects/raycast/raycast.h"

 /// @brief The MyEntity class is the Entity implementation.
class ballEntity : public Entity
{
public:
	/// @brief Constructor
	ballEntity();
	/// @brief Destructor
	virtual ~ballEntity();

	/// @brief update is automatically called every frame
	/// @param deltaTime the elapsed time in seconds
	/// @return void
	virtual void update(float deltaTime);

	void draw(Boundary& wall);
	void draw(Ray& ray);

private:
	/* add your private declarations */
	
};

#endif /* MYENTITY_H */
