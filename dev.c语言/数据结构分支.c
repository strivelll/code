#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define BOARD_SIZE 8
#define GEM_TYPES 5
#define MATCH_THRESHOLD 3
#define TIME_LIMIT 60

// 宝石的结构体
typedef struct {
    int type;
} Gem;

// 游戏棋盘
Gem board[BOARD_SIZE][BOARD_SIZE];

// 初始化宝石布局
void initializeBoard() {
    srand(time(NULL));
  
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            board[i][j].type = rand() % GEM_TYPES;
        }
    }
}

// 打印当前宝石布局
void printBoard() {
    printf("\n");
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            printf("%d ", board[i][j].type);
        }
        printf("\n");
    }
    printf("\n");
}

// 检查是否存在可消除的宝石
bool hasMatches() {
    bool matchesFound = false;
  
    // 检查行
    for (int i = 0; i < BOARD_SIZE; i++) {
        int count = 1;
        for (int j = 0; j < BOARD_SIZE - 1; j++) {
            if (board[i][j].type == board[i][j + 1].type) {
                count++;
            } else {
                count = 1;
            }
          
            if (count >= MATCH_THRESHOLD) {
                matchesFound = true;
            }
        }
    }

    // 检查列
    for (int j = 0; j < BOARD_SIZE; j++) {
        int count = 1;
        for (int i = 0; i < BOARD_SIZE - 1; i++) {
            if (board[i][j].type == board[i + 1][j].type) {
                count++;
            } else {
                count = 1;
            }
          
            if (count >= MATCH_THRESHOLD) {
                matchesFound = true;
            }
        }
    }
  
    return matchesFound;
}

// 处理宝石消除
void handleMatches() {
    bool matched[BOARD_SIZE][BOARD_SIZE] = {false};
  
    // 标记匹配的宝石
    for (int i = 0; i < BOARD_SIZE; i++) {
        int count = 1;
        for (int j = 0; j < BOARD_SIZE - 1; j++) {
            if (board[i][j].type == board[i][j + 1].type) {
                count++;
            } else {
                count = 1;
            }
          
            if (count >= MATCH_THRESHOLD) {
                for (int k = 0; k < count; k++) {
                    matched[i][j - k] = true;
                }
            }
        }
    }

    for (int j = 0; j < BOARD_SIZE; j++) {
        int count = 1;
        for (int i = 0; i < BOARD_SIZE - 1; i++) {
            if (board[i][j].type == board[i + 1][j].type) {
                count++;
            } else {
                count = 1;
            }
          
            if (count >= MATCH_THRESHOLD) {
                for (int k = 0; k < count; k++) {
                    matched[i - k][j] = true;
                }
            }
        }
    }
  
    // 清除匹配的宝石并下落
    for (int j = 0; j < BOARD_SIZE; j++) {
        int currentRow = BOARD_SIZE - 1;
        for (int i = BOARD_SIZE - 1; i >= 0; i--) {
            if (!matched[i][j]) {
                board[currentRow][j] = board[i][j];
                currentRow--;
            }
        }
      
        // 生成新的宝石
        for (int i = currentRow; i >= 0; i--) {
            board[i][j].type = rand() % GEM_TYPES;
        }
    }
}

// 计算得分
int calculateScore(int matches) {
    return matches * MATCH_THRESHOLD * MATCH_THRESHOLD;
}

// 判断游戏是否结束
bool isGameOver(int timeRemaining) {
    // TODO: 实现判断逻辑
    return false;
}

// 游戏倒计时
void countdownTimer(int seconds) {
    for (int i = seconds; i >= 0; i--) {
        printf("剩余时间：%d秒\n", i);
        sleep(1);
    }
}

// 主游戏循环
void playGame() {
    initializeBoard();
    int score = 0;
    int timeRemaining = TIME_LIMIT;
    int level = 1;

    while (!isGameOver(timeRemaining)) {
        printf("Level: %d\n", level);
        printf("Score: %d\n", score);
      
        printBoard();

        // 输入玩家操作
        int row1, col1, row2, col2;
        printf("请输入要交换的两个宝石的坐标：");
        scanf("%d%d%d%d", &row1, &col1, &row2, &col2);

        // 交换宝石位置
        Gem temp = board[row1][col1];
        board[row1][col1] = board[row2][col2];
        board[row2][col2] = temp;

        // 检查是否有可消除的宝石
        if (hasMatches()) {
            handleMatches();
            int matches = 0;
            while (hasMatches()) {
                handleMatches();
                matches++;
            }
            int levelScore = calculateScore(matches);
            score += levelScore;
            printf("匹配成功！得分 +%d\n", levelScore);
        } else {
            printf("无法匹配，重新选择交换位置。\n");
            // 恢复交换前的宝石位置
            temp = board[row1][col1];
            board[row1][col1] = board[row2][col2];
            board[row2][col2] = temp;
        }

        // 更新时间和关卡
        timeRemaining--;
        if (timeRemaining == 0) {
            level++;
            timeRemaining = TIME_LIMIT;
        }
    }
  
    printf("游戏结束！\n");
    printf("最终得分：%d\n", score);
}

int main() {
    playGame();
    return 0;
}

