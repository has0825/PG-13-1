#pragma once
#include <vector>

class Enemy {
public:
    float x, y;
    float speedX;
    bool isAlive;
     
    Enemy(float startX, float startY, float initialSpeedX);
    
    void Update();
    void Draw();
    static void CheckCollision(std::vector<Enemy>& enemies, float bulletX, float bulletY);
    static void ResetAll(std::vector<Enemy>& enemies);
};
