#include "snake.h"
#include "game.h"
#include "ui.h"

int main() {
    startmenu();
    runtime();

    while (!gameover) {
        input();
        movement();
        selfcol();
        isfoodeaten();
        walcol();
        printonscr();
        delay();
    }

    system("cls");
    printsnek();
    printf("\nGAME OVER\nFinal Score: %d\n", score);
    return 0;
}

