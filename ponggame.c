#include <stdio.h>
#include <conio.h>
#include <windows.h>

int ballX, ballY;
int ballSpeedX, ballSpeedY;
int paddle1Y, paddle2Y;

int screenWidth = 60;
int screenHeight = 20;

void setup() {
    ballX = screenWidth / 2;
    ballY = screenHeight / 2;
    ballSpeedX = 1;
    ballSpeedY = 1;

    paddle1Y = screenHeight / 2 - 2;
    paddle2Y = screenHeight / 2 - 2;
}

void draw() {
    system("cls");

    for (int i = 0; i < screenWidth; i++)
        printf("-");
    printf("\n");

    for (int i = 0; i < screenHeight; i++) {
        for (int j = 0; j < screenWidth; j++) {
            if (j == 0 || j == screenWidth - 1)
                printf("|");
            else if (i == ballY && j == ballX)
                printf("O");
            else if (i >= paddle1Y && i < paddle1Y + 4 && j == 1)
                printf("#");
            else if (i >= paddle2Y && i < paddle2Y + 4 && j == screenWidth - 2)
                printf("#");
            else
                printf(" ");
        }
        printf("\n");
    }

    for (int i = 0; i < screenWidth; i++)
        printf("-");
    printf("\n");
}

void input() {
    if (_kbhit()) {
        char key = _getch();
        if (key == 'w' && paddle1Y > 0)
            paddle1Y--;
        if (key == 's' && paddle1Y + 4 < screenHeight)
            paddle1Y++;
        if (key == 'i' && paddle2Y > 0)
            paddle2Y--;
        if (key == 'k' && paddle2Y + 4 < screenHeight)
            paddle2Y++;
    }
}

void logic() {
    ballX += ballSpeedX;
    ballY += ballSpeedY;

    if (ballY == 0 || ballY == screenHeight - 1)
        ballSpeedY = -ballSpeedY;

    if (ballX == 1 && ballY >= paddle1Y && ballY < paddle1Y + 4)
        ballSpeedX = -ballSpeedX;

    if (ballX == screenWidth - 2 && ballY >= paddle2Y && ballY < paddle2Y + 4)
        ballSpeedX = -ballSpeedX;

    if (ballX < 0 || ballX >= screenWidth) {
        ballX = screenWidth / 2;
        ballY = screenHeight / 2;
        ballSpeedX = -ballSpeedX;
        ballSpeedY = -ballSpeedY;
    }
}

int main() {
    setup();

    while (1) {
        draw();
        input();
        logic();
        Sleep(50);
    }

    return 0;
}
