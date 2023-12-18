#include "ballEntity.h"

ballEntity::ballEntity() : Entity()
{
	this->addSprite("assets/Ball.tga");
	//this->sprite()->color = GREEN;


}

ballEntity::~ballEntity()
{

}

void ballEntity::update(float deltaTime)
{

}

void ballEntity::draw(Ray& ray) {
	Ray copy(ray.position.x, ray.position.y, ray.direction.x, ray.direction.y);
	ddLine(copy.position.x, copy.position.y, copy.direction.x + copy.position.x, copy.direction.y + copy.position.y, GREEN);
}