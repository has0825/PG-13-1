#pragma once
#include <vector>

class Enemy {
public:
    float x, y;
    float speedX;
    bool isAlive;

    // 静的メンバ変数
    static std::vector<Enemy> enemies;

    Enemy(float startX, float startY, float initialSpeedX);

    void Update();
    void Draw();
    void CheckCollision(float bulletX, float bulletY);
    void ResetAll();
};
