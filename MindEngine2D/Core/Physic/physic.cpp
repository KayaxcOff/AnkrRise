#include "physic.hpp"

AnkrPhysic::AnkrPhysic() : world(nullptr), ppm(0) {}

AnkrPhysic::~AnkrPhysic() {
	this->world.reset();
}

void AnkrPhysic::init(float _ppm, float gravityX, float gravityY) {
	this->ppm = _ppm;
	b2Vec2 gravity(gravityX, gravityY);
	this->world = std::make_unique<b2World>(gravity);
}

void AnkrPhysic::update(float deltaTime) {
	const int32 velocityIterations = 6;
	const int32 positionIterations = 2;
	this->world->Step(deltaTime, velocityIterations, positionIterations);
}

b2Body* AnkrPhysic::initializeBody(float posX, float posY, float width, float height, bool isDynamic) const {
	b2BodyDef bodyDef;
	if (isDynamic) {
		bodyDef.type = b2_dynamicBody;
	} else {
		bodyDef.type = b2_staticBody;
	}
	bodyDef.position.Set(this->to_met(posX), this->to_met(posY));
	b2Body* body = this->world->CreateBody(&bodyDef);
	b2PolygonShape boxShape;
	boxShape.SetAsBox(this->to_met(width) / 2.0f, this->to_met(height) / 2.0f);
	b2FixtureDef fixtureDef;
	fixtureDef.shape = &boxShape;
	fixtureDef.density = 1.0f;
	fixtureDef.friction = 0.3f;
	body->CreateFixture(&fixtureDef);
	return body;
}

float AnkrPhysic::to_met(float pixels) const {
	return pixels / this->ppm;
}

float AnkrPhysic::to_pix(float meters) const {
	return meters * this->ppm;
}