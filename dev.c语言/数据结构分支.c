#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define BOARD_SIZE 8
#define GEM_TYPES 5
#define MATCH_THRESHOLD 3
#define TIME_LIMIT 60

// ��ʯ�Ľṹ��
typedef struct {
    int type;
} Gem;

// ��Ϸ����
Gem board[BOARD_SIZE][BOARD_SIZE];

// ��ʼ����ʯ����
void initializeBoard() {
    srand(time(NULL));
  
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            board[i][j].type = rand() % GEM_TYPES;
        }
    }
}

// ��ӡ��ǰ��ʯ����
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

// ����Ƿ���ڿ������ı�ʯ
bool hasMatches() {
    bool matchesFound = false;
  
    // �����
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

    // �����
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

// ����ʯ����
void handleMatches() {
    bool matched[BOARD_SIZE][BOARD_SIZE] = {false};
  
    // ���ƥ��ı�ʯ
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
  
    // ���ƥ��ı�ʯ������
    for (int j = 0; j < BOARD_SIZE; j++) {
        int currentRow = BOARD_SIZE - 1;
        for (int i = BOARD_SIZE - 1; i >= 0; i--) {
            if (!matched[i][j]) {
                board[currentRow][j] = board[i][j];
                currentRow--;
            }
        }
      
        // �����µı�ʯ
        for (int i = currentRow; i >= 0; i--) {
            board[i][j].type = rand() % GEM_TYPES;
        }
    }
}

// ����÷�
int calculateScore(int matches) {
    return matches * MATCH_THRESHOLD * MATCH_THRESHOLD;
}

// �ж���Ϸ�Ƿ����
bool isGameOver(int timeRemaining) {
    // TODO: ʵ���ж��߼�
    return false;
}

// ��Ϸ����ʱ
void countdownTimer(int seconds) {
    for (int i = seconds; i >= 0; i--) {
        printf("ʣ��ʱ�䣺%d��\n", i);
        sleep(1);
    }
}

// ����Ϸѭ��
void playGame() {
    initializeBoard();
    int score = 0;
    int timeRemaining = TIME_LIMIT;
    int level = 1;

    while (!isGameOver(timeRemaining)) {
        printf("Level: %d\n", level);
        printf("Score: %d\n", score);
      
        printBoard();

        // ������Ҳ���
        int row1, col1, row2, col2;
        printf("������Ҫ������������ʯ�����꣺");
        scanf("%d%d%d%d", &row1, &col1, &row2, &col2);

        // ������ʯλ��
        Gem temp = board[row1][col1];
        board[row1][col1] = board[row2][col2];
        board[row2][col2] = temp;

        // ����Ƿ��п������ı�ʯ
        if (hasMatches()) {
            handleMatches();
            int matches = 0;
            while (hasMatches()) {
                handleMatches();
                matches++;
            }
            int levelScore = calculateScore(matches);
            score += levelScore;
            printf("ƥ��ɹ����÷� +%d\n", levelScore);
        } else {
            printf("�޷�ƥ�䣬����ѡ�񽻻�λ�á�\n");
            // �ָ�����ǰ�ı�ʯλ��
            temp = board[row1][col1];
            board[row1][col1] = board[row2][col2];
            board[row2][col2] = temp;
        }

        // ����ʱ��͹ؿ�
        timeRemaining--;
        if (timeRemaining == 0) {
            level++;
            timeRemaining = TIME_LIMIT;
        }
    }
  
    printf("��Ϸ������\n");
    printf("���յ÷֣�%d\n", score);
}

int main() {
    playGame();
    return 0;
}

