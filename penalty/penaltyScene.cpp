#include <fstream>
#include <sstream>

#include "penaltyScene.h"
#include "projects/collision/collider.h"
 
penaltyScene::penaltyScene() : Scene()
{
	// start the timer.
	t.start();
	//Scene* PenaltyScene = nullptr;
	// create a single instance of MyEntity in the middle of the screen.
	// the Sprite is added in Constructor of MyEntity.
	//PenaltyScene = new penaltyScene();

	BackGroundEntity = new backGroundEntity();
	BackGroundEntity->position = Point2(SWIDTH / 2, SHEIGHT / 2);

	ArrowEntity = new arrowEntity();
	ArrowEntity->position = Point2(SWIDTH / 2, SHEIGHT / 1.275);
	

	BallEntity = new ballEntity();
	BallEntity->position = Point2(SWIDTH / 2, SHEIGHT / 1.31);

	PowerBarCase = new powerBarCase();
	PowerBarCase->position = Point2(SWIDTH / 5, SHEIGHT / 2.5);

	PowerBar = new powerBar();
	PowerBar->position = Point2(SWIDTH / 5, SHEIGHT / 2.5);

	debugLayer = new BasicEntity();

	this->addChild(BackGroundEntity);
	this->addChild(ArrowEntity);
	this->addChild(BallEntity);
	this->addChild(PowerBarCase);
	this->addChild(PowerBar);
	this->addChild(debugLayer);


}


penaltyScene::~penaltyScene()
{
	// deconstruct and delete the Tree
	this->removeChild(BackGroundEntity);
	this->removeChild(ArrowEntity);
	this->removeChild(BallEntity);
	this->removeChild(PowerBarCase);
	this->removeChild(PowerBar);
	this->removeChild(debugLayer);

	// delete myentity from the heap (there was a 'new' in the constructor)
	delete BackGroundEntity;
	delete ArrowEntity;
	delete BallEntity;
	delete PowerBarCase;
	delete PowerBar;
	delete debugLayer;
}

void penaltyScene::update(float deltaTime)
{
	if (input()->getKeyUp(KeyCode::Escape)) {
		this->stop();
	}
	
	//mouse input 
	int mousex = input()->getMouseX() + camera()->position.x - SWIDTH / 2;
	int mousey = input()->getMouseY() + camera()->position.y - SHEIGHT / 2;
	Point2 mouse = Point2(mousex, mousey);

	//shoot debug
	Vector2 direction = Vector2(0, 800);
	direction.rotation(ArrowEntity->rotation.z - (PI / 2));
	debugLayer->ddClear();
	Vector2 line_start = ArrowEntity->position;
	Vector2 line_end = ArrowEntity->position + direction;
	debugLayer->ddLine(line_start, line_end, YELLOW);

	//// horizontal line
	Vector2 hor_start = PowerBar->position;
	Vector2 hor_end = PowerBar->position + Vector2(700, 0);
	debugLayer->ddLine(hor_start, hor_end, YELLOW);

	// Calculate intersection
	Vector2 intersectionPoint;

	//Goal rectangles
	Rectangle topleft = Rectangle(410, 160, 200, 100);
	Rectangle botleft = Rectangle(410, 260, 200, 100);

	//Top corner 1
	debugLayer->ddSquare(topleft.x, topleft.y, topleft.width, topleft.height, RED);
	//Bottom corner 1
	debugLayer->ddSquare(botleft.x, botleft.y, botleft.width, botleft.height, RED);
	//Top corner 2
	debugLayer->ddSquare(690, 160, 200, 100, RED);
	//Bottom corner 2
	debugLayer->ddSquare(690, 260, 200, 100, RED);
	//Middle
	debugLayer->ddSquare(610, 160, 80, 200, RED);

	// Check if the lines are not parallel
	if (line_start.x != line_end.x && hor_start.x != hor_end.x) {
		float Line1 = (line_end.y - line_start.y) / (line_end.x - line_start.x);
		float Line2 = (hor_end.y - hor_start.y) / (hor_end.x - hor_start.x);

		if (Line1 != Line2) {
			float x = (Line1 * line_start.x - Line2 * hor_start.x + hor_start.y - line_start.y) / (Line1 - Line2);
			float y = Line1 * (x - line_start.x) + line_start.y;

			intersectionPoint = Vector2(x, y);

			
			debugLayer->ddCircle(intersectionPoint.x, intersectionPoint.y, 8, YELLOW);
		}
	}
	 
	if (!arrowClicked)
	{
		ArrowEntity->rotation.z += rotationDirection * rotationSpeed * deltaTime;

		if (ArrowEntity->rotation.z >= maxRotation || ArrowEntity->rotation.z <= -maxRotation)
		{
			rotationDirection *= -1;  
		}

		if (input()->getMouseDown(0))
		{
			arrowClicked = true;
			barClicked = true;
		}
	}

	if (barClicked)
	{
		PowerBar->position.y += verticalMovementSpeed * deltaTime;

		// laagte
		if (PowerBar->position.y >= 335)
		{
			verticalMovementSpeed = -175;
		}
		//hoogte
		else if (PowerBar->position.y <= 150)
		{
			verticalMovementSpeed = 175;
		}

		if (input()->getMouseUp(0))
		{
			barClicked = false;
			/*shoot = true;*/
			BallEntity->position.y = intersectionPoint.y;
			BallEntity->position.x = intersectionPoint.x;
		}
	}

	if (input()->getKeyDown(KeyCode::Space))
	{
		std::cout << "Inter Y " << intersectionPoint.y << std::endl;
		std::cout << "Inter X " << intersectionPoint.x << std::endl;

		int r = rand() % 100;
		if (r < 25)
		{
			//Keeper goes to the correct corner
			if (Collider::point2rectangle(BallEntity->position, topleft))
			{

			}

			if (Collider::point2rectangle(BallEntity->position, botleft))
			{

			}
		}
		else
		{
			int rc = rand() % 6;
			//switch (rc) {
			//case 1:
			//	if (Collider::point2rectangle(BallEntity->position, topleft))
			//{

			//}
			//	break;
			//case 2:
			//	// code block
			//	break;
			//case 3:
			//	// code block
			//	break;
			//case 4:
			//	// code block
			//	break;
			//case 5:
			//	// code block
			//	break;
			//case 6:
			//	// code block
			//	break;
			//default:
			//	// code block
			//}
		}
	}

	/*if (shoot == true)
	{
		ballSpotY = BallEntity->position.y - intersectionPoint.y;
		ballSpotX = BallEntity->position.x - intersectionPoint.x;

		BallEntity->position.y = ballSpotY;
		BallEntity->position.x = ballSpotX;
	}*/

}






