#pragma once

#include <Box2D/box2d.h>
#include <memory>

class AnkrPhysic {
public:
	AnkrPhysic();
	~AnkrPhysic();

	void init(float _ppm, float gravityX=0.0f, float gravityY=-9.8f);
	void update(float deltaTime);
	[[nodiscard]] b2Body* initializeBody(float posX, float posY, float width, float height, bool isDynamic) const;
	[[nodiscard]] float to_met(float pixels) const;
	[[nodiscard]] float to_pix(float meters) const;
private:
	std::unique_ptr<b2World> world;
	float ppm;
};