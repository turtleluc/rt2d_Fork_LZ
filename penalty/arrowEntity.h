/**
 * Copyright 2015 Your Name <you@yourhost.com>
 *
 * @file myentity.h
 *
 * @brief description of MyEntity behavior.
 */

#ifndef ARROWENTITY_H
#define ARROWENTITY_H

#include <rt2d/entity.h>
#include "projects/raycast/raycast.h"

 /// @brief The MyEntity class is the Entity implementation.
class arrowEntity : public Entity
{
public:
	/// @brief Constructor
	arrowEntity();
	/// @brief Destructor
	virtual ~arrowEntity();

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
