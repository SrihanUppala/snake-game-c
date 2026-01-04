#include <stdio.h>
#include <stdlib.h>
#include "game.h"
#include "ui.h"

int LENGTH, WIDTH;
int gameover = 0, score = 0;
int diff, worlds;

void difficulty() {
    system("cls");
    printsnek();
    printf("1.Easy\n2.Medium\n3.Hard\n4.Snek\n");
    scanf("%d", &diff);
}

void worldsize() {
    system("cls");
    printsnek();
    printf("1.Small\n2.Medium\n3.Large\n");
    scanf("%d", &worlds);

    if (worlds == 1) { LENGTH = 20; WIDTH = 25; }
    else if (worlds == 2) { LENGTH = 25; WIDTH = 50; }
    else { LENGTH = 30; WIDTH = 70; }
}

void startmenu() {
    printsnek();
    difficulty();
    worldsize();
}

void delay() {
    long i;
    for (i = 0; i < 100000000 / diff; i++);
}
