#include <rt2d/core.h>

#include "penaltyScene.h"
#include "menuScene.h"

int main(void)
{
	// Core instance
	Core core;

	// Scene01
	//Scene* MenuScene = nullptr;
	Scene* PenaltyScene = new penaltyScene();// create Scene on the heap
	while (PenaltyScene->isRunning()) { // check status of Scene every frame
		core.run(PenaltyScene); // update and render the current scene
		core.showFrameRate(5); // show framerate in output every n seconds
	}
	//core.cleanup(); // cleanup ResourceManager (Textures + Meshes, but not Shaders)
	delete PenaltyScene; // delete Scene and everything in it from the heap to make space for next Scene

	// No need to explicitly clean up the core.
	// As a local var, core will go out of scope and destroy Renderer->ResourceManager.
	// ResourceManager destructor also deletes Shaders.

	return 0;
}

