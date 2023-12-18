#ifndef PENALTYSCENE_H
#define PENALTYSCENE_H

#include <deque>
#include <rt2d/timer.h>
#include <rt2d/scene.h>


class menuScene : public Scene
{
public:
	/// @brief Constructor
	menuScene();
	/// @brief Destructor
	virtual ~menuScene();

	/// @brief update is automatically called every frame
	/// @param deltaTime the elapsed time in seconds
	/// @return void
	virtual void update(float deltaTime);

private:
	/// @brief the rotating square in the middle of the screen

	/// @brief a Timer to rotate the color every n seconds
	Timer t;
};


#endif /* SCENE00_H */
