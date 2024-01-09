#ifndef PENALTYSCENE_H
#define PENALTYSCENE_H

#include <deque>
#include <rt2d/timer.h>
//#include "projects/demo/superscene.h"
#include <scene.h>
#include "projects/raycast/raycast.h"
//#include "basicentity.h"

#include "backGroundEntity.h"
#include "ballEntity.h"
#include "arrowEntity.h"
#include "powerBarCase.h"
#include "powerBar.h"
#include "basicEntity.h"
#include "collider.h"

class penaltyScene : public Scene
{
public:
	/// @brief Constructor
	penaltyScene();
	/// @brief Destructor
	virtual ~penaltyScene();

	/// @brief update is automatically called every frame
	/// @param deltaTime the elapsed time in seconds
	/// @return void
	virtual void update(float deltaTime);




private:
	/// @brief the rotating square in the middle of the screen
	backGroundEntity* BackGroundEntity;
	arrowEntity* ArrowEntity;
	ballEntity* BallEntity;
	powerBarCase* PowerBarCase;
	powerBar* PowerBar;
	BasicEntity* debugLayer;
	/// @brief a Timer to rotate the color every n seconds
	Timer t;
	bool arrowClicked = false;

	bool barClicked = false;

	bool shoot = false;

	const float maxRotation = 1.0f;
	const float rotationSpeed = 1.0f;

	int ballSpotY = 0;
	int ballSpotX = 0;

	int rotationDirection = 1;

	int verticalMovementSpeed = 175;

//protected:
//	unsigned int top_layer;
//	std::vector<BasicEntity*> layers;
};


#endif 