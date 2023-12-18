/**
 * Copyright 2015 Your Name <you@yourhost.com>
 *
 * @file myentity.h
 *
 * @brief description of MyEntity behavior.
 */

#ifndef BACKGROUNDENTITY_H
#define BACKGROUNDENTITY_H

#include <rt2d/entity.h>

 /// @brief The MyEntity class is the Entity implementation.
class backGroundEntity : public Entity
{
public:
	/// @brief Constructor
	backGroundEntity();
	/// @brief Destructor
	virtual ~backGroundEntity();

	/// @brief update is automatically called every frame
	/// @param deltaTime the elapsed time in seconds
	/// @return void
	virtual void update(float deltaTime);

private:
	/* add your private declarations */
};

#endif /* MYENTITY_H */
