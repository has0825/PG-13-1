#include "Enemy.h"
#include <Novice.h>
#include <algorithm>

// 静的メンバ変数の初期化
std::vector<Enemy> Enemy::enemies;

Enemy::Enemy(float startX, float startY, float initialSpeedX)
    : x(startX), y(startY), speedX(initialSpeedX), isAlive(true) {
    // 新しい敵を敵リストに追加
    enemies.push_back(*this);
}

void Enemy::Update() {
    if (isAlive) {
        x += speedX;
        if (x <= 0.0f || x >= 1248.0f) {
            speedX = -speedX;
        }
    }
}

void Enemy::Draw() {
    if (isAlive) {
        Novice::DrawEllipse(static_cast<int>(x), static_cast<int>(y), 16, 16, 0.0f, 0xFF0000FF, kFillModeSolid);
    }
}

void Enemy::CheckCollision(float bulletX, float bulletY) {
    for (auto& enemy : enemies) {
        if (enemy.isAlive &&
            bulletX > enemy.x - 16 && bulletX < enemy.x + 16 &&
            bulletY > enemy.y - 16 && bulletY < enemy.y + 16) {
            // 衝突が検出されたら、すべての敵を非アクティブにする
            for (auto& e : enemies) {
                e.isAlive = false;
            }
            break;
        }
    }
}

void Enemy::ResetAll() {
    for (auto& enemy : enemies) {
        enemy.isAlive = true;
    }
}
