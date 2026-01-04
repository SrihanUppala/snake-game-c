#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include "snake.h"
#include "game.h"

struct snake s;
struct food f;

void runtime() {
    int i;
    s.length = 2;
    s.dir = 'R';
    for (i = 0; i < s.length; i++) {
        s.x[i] = 5 - i;
        s.y[i] = 5;
    }
    f.x = 10;
    f.y = 5;
}

void input()
{
    char ch;

    if (kbhit())
    {
        ch = getch();

        if (ch == 'w' && s.dir != 'D') s.dir = 'U';
        if (ch == 'a' && s.dir != 'R') s.dir = 'L';
        if (ch == 's' && s.dir != 'U') s.dir = 'D';
        if (ch == 'd' && s.dir != 'L') s.dir = 'R';

        /* PAUSE MENU */
        if (ch == 'p' || ch == 'P')
        {
            system("cls");
            printsnek();
            printf("\tCurrent score: %d\n", score);
            printf("\tPress C to continue, any other key to quit\n");

            char pc = getch();
            if (pc != 'c' && pc != 'C')
                gameover = -1;
        }
    }
}

void movement() {
    int i;
    for (i = s.length - 1; i > 0; i--) {
        s.x[i] = s.x[i - 1];
        s.y[i] = s.y[i - 1];
    }

    if (s.dir == 'U') s.y[0]--;
    if (s.dir == 'D') s.y[0]++;
    if (s.dir == 'L') s.x[0]--;
    if (s.dir == 'R') s.x[0]++;
}

void selfcol() {
    int i;
    for (i = 1; i < s.length; i++) {
        if (s.x[0] == s.x[i] && s.y[0] == s.y[i]) {
            gameover = -1;
            break;
        }
    }
}

void isfoodeaten() {
    if (s.x[0] == f.x && s.y[0] == f.y) {
        if (s.length < MAXLEN) {
            s.length++;
            score += 10;
            f.x = rand() % (WIDTH - 2) + 1;
            f.y = rand() % (LENGTH - 2) + 1;
        }
    }
}

void walcol() {
    if (s.x[0] == 0 || s.x[0] == WIDTH - 1 ||
        s.y[0] == 0 || s.y[0] == LENGTH - 1) {
        gameover = -1;
    }
}

