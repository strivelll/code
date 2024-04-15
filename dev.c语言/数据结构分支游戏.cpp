#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAP_SIZE 5
#define NUM_GEMS 5
#define GOAL_SCORE 100

// ��ʯ�ṹ
typedef struct {
    int x;
    int y;
    int score;
} Gem;

// ��ͼ�����λ��
int map[MAP_SIZE][MAP_SIZE];
int playerX, playerY;
int playerScore;

// ������ʯ
Gem createGem(int x, int y, int score) {
    Gem newGem;
    newGem.x = x;
    newGem.y = y;
    newGem.score = score;
    return newGem;
}

// ��ʼ����ͼ�����λ��
void initialize() {
    int i, j;
    for (i = 0; i < MAP_SIZE; i++) {
        for (j = 0; j < MAP_SIZE; j++) {
            map[i][j] = 0;
        }
    }

    // ������ɱ�ʯ
    for (i = 0; i < NUM_GEMS; i++) {
        int x = rand() % MAP_SIZE;
        int y = rand() % MAP_SIZE;
        int score = rand() % 10 + 1; // ��ʯ��ֵ��1-10֮��
        map[x][y] = score;
    }

    // ��ʼ�����λ�úͷ���
    playerX = rand() % MAP_SIZE;
    playerY = rand() % MAP_SIZE;
    playerScore = 0;
}

// ��ʾ��ͼ�������Ϣ
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

// �ƶ����
void move(int dx, int dy) {
    int newX = playerX + dx;
    int newY = playerY + dy;

    // ���߽���ϰ���
    if (newX >= 0 && newX < MAP_SIZE && newY >= 0 && newY < MAP_SIZE && map[newX][newY] != -1) {
        playerX = newX;
        playerY = newY;

        // �ռ���ʯ�����·���
        int score = map[playerX][playerY];
        playerScore += score;
        map[playerX][playerY] = 0;
    }
}

// �ж���Ϸ�Ƿ����
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
                move(-1, 0); // ��
                break;
            case 'a':
                move(0, -1); // ��
                break;
            case 's':
                move(1, 0);  // ��
                break;
            case 'd':
                move(0, 1);  // ��
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

