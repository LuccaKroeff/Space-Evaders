#include "collisions.h"

bool SpaceshipAsteroidCollision(HitBox SpaceshipHitBox, HitBox AsteroidHitBox){
    // Verifica a colis�o entre duas caixas delimitadas (hit boxes)
    if (SpaceshipHitBox.maxPoint.x < AsteroidHitBox.minPoint.x ||
        SpaceshipHitBox.minPoint.x > AsteroidHitBox.maxPoint.x ||
        SpaceshipHitBox.maxPoint.y < AsteroidHitBox.minPoint.y ||
        SpaceshipHitBox.minPoint.y > AsteroidHitBox.maxPoint.y ||
        SpaceshipHitBox.maxPoint.z < AsteroidHitBox.minPoint.z ||
        SpaceshipHitBox.minPoint.z > AsteroidHitBox.maxPoint.z) {

        // Sem colis�o
        return false;
    }

    // Se chegou aqui, h� colis�o
    return true;
}

bool SpaceshipCoinCollision(HitBox SpaceshipHitBox, HitBox CoinHitBox){
    // Verifica a colis�o entre duas caixas delimitadas (hit boxes)
    if (SpaceshipHitBox.maxPoint.x < CoinHitBox.minPoint.x ||
        SpaceshipHitBox.minPoint.x > CoinHitBox.maxPoint.x ||
        SpaceshipHitBox.maxPoint.y < CoinHitBox.minPoint.y ||
        SpaceshipHitBox.minPoint.y > CoinHitBox.maxPoint.y ||
        SpaceshipHitBox.maxPoint.z < CoinHitBox.minPoint.z ||
        SpaceshipHitBox.minPoint.z > CoinHitBox.maxPoint.z) {

        // Sem colis�o
        return false;
    }

    // Se chegou aqui, h� colis�o
    return true;

}

bool SpaceshipMoonCollision(HitBox SpaceshipHitBox, HitSphere MoonHitSphere){
    // Calcula a dist�ncia entre o centro da esfera e o ponto mais pr�ximo na caixa delimitada (hit box)
    glm::vec3 closestPoint = glm::clamp(MoonHitSphere.center, SpaceshipHitBox.minPoint, SpaceshipHitBox.maxPoint);
    glm::vec3 offset = MoonHitSphere.center - closestPoint;
    float distanceSquared = glm::dot(offset, offset);

    // Verifica se a dist�ncia ao quadrado � menor que o quadrado do raio da esfera
    if (distanceSquared <= (MoonHitSphere.radius * MoonHitSphere.radius)) {
        // H� colis�o
        return true;
    }

    // Sem colis�o
    return false;

}

bool SpaceshipUniverseCollision(HitBox SpaceshipHitBox, float limit){
    // Verifica se a nave encontra-se a uma dist�ncia maior que a do limite
    if(SpaceshipHitBox.maxPoint.x > limit || SpaceshipHitBox.minPoint.x < -limit ||
       SpaceshipHitBox.maxPoint.y > limit || SpaceshipHitBox.minPoint.y < -limit ||
       SpaceshipHitBox.maxPoint.z > limit || SpaceshipHitBox.minPoint.z < -limit)
    {
        // H� colis�o
        return true;
    }

    // Sem colis�o
    return false;

}

