#include "arrowEntity.h"

arrowEntity::arrowEntity() : Entity()
{
	this->addSprite("assets/arrowEntity.tga", 0.5f, 1.0f);
	//this->sprite()->color = GREEN;


}

arrowEntity::~arrowEntity()
{

}

void arrowEntity::update(float deltaTime)
{

}