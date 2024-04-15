#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAP_SIZE 5
#define NUM_GEMS 5
#define GOAL_SCORE 100

// 宝石结构
typedef struct {
    int x;
    int y;
    int score;
} Gem;

// 地图和玩家位置
int map[MAP_SIZE][MAP_SIZE];
int playerX, playerY;
int playerScore;

// 创建宝石
Gem createGem(int x, int y, int score) {
    Gem newGem;
    newGem.x = x;
    newGem.y = y;
    newGem.score = score;
    return newGem;
}

// 初始化地图和玩家位置
void initialize() {
    int i, j;
    for (i = 0; i < MAP_SIZE; i++) {
        for (j = 0; j < MAP_SIZE; j++) {
            map[i][j] = 0;
        }
    }

    // 随机生成宝石
    for (i = 0; i < NUM_GEMS; i++) {
        int x = rand() % MAP_SIZE;
        int y = rand() % MAP_SIZE;
        int score = rand() % 10 + 1; // 宝石分值在1-10之间
        map[x][y] = score;
    }

    // 初始化玩家位置和分数
    playerX = rand() % MAP_SIZE;
    playerY = rand() % MAP_SIZE;
    playerScore = 0;
}

// 显示地图和玩家信息
void display() {
    int i, j;
    for (i = 0; i < MAP_SIZE; i++) {
        for (j = 0; j < MAP_SIZE; j++) {
            if (i == playerX && j == playerY) {
                printf("P ");
            } else {
                printf("%d ", map[i][j]);
            }
        }
        printf("\n");
    }
    printf("Score: %d\n", playerScore);
}

// 移动玩家
void move(int dx, int dy) {
    int newX = playerX + dx;
    int newY = playerY + dy;

    // 检查边界和障碍物
    if (newX >= 0 && newX < MAP_SIZE && newY >= 0 && newY < MAP_SIZE && map[newX][newY] != -1) {
        playerX = newX;
        playerY = newY;

        // 收集宝石并更新分数
        int score = map[playerX][playerY];
        playerScore += score;
        map[playerX][playerY] = 0;
    }
}

// 判断游戏是否结束
bool isGameOver() {
    return (playerScore >= GOAL_SCORE || playerScore == 0);
}

int main() {
    char input;
    initialize();

    while (!isGameOver()) {
        display();
        printf("Enter your move (w/a/s/d, q to quit): ");
        scanf(" %c", &input);
        scanf(" %c", &input);

        if (input == 'q') {
            break;
        }

        switch (input) {
            case 'w':
                move(-1, 0); // 上
                break;
            case 'a':
                move(0, -1); // 左
                break;
            case 's':
                move(1, 0);  // 下
                break;
            case 'd':
                move(0, 1);  // 右
                break;
            default:
                printf("Invalid move!\n");
        }
    }

    display();
    if (playerScore >= GOAL_SCORE) {
        printf("Congratulations! You reached the goal score.\n");
    } else {
        printf("Game over! You couldn't reach the goal score.\n");
    }

    return 0;
}

