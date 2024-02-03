#ifndef COLLISIONS_H
#define COLLISIONS_H

#include <glm/glm.hpp>

struct HitBox
{
    glm::vec3 minPoint;
    glm::vec3 maxPoint;
};

struct HitSphere
{
    glm::vec3 center;
    float radius;
};

bool SpaceshipAsteroidCollision(HitBox SpaceshipHitBox, HitBox AsteroidHitBox);
bool SpaceshipCoinCollision(HitBox SpaceshipHitBox, HitBox CoinHitBox);
bool SpaceshipUniverseCollision(HitBox SpaceshipHitBox, HitSphere UniverseHitSphere);

#endif
