#include <stdio.h>
#include <stdlib.h>
#include "ui.h"
#include "snake.h"
#include "game.h"

void printsnek()
{
    printf("\t\tSSSSS   NN   NN     AAAA    KK   KK  EEEEEEE\n");
    printf("\t\tSS      NNN  NN    AA  AA   KK  KK   EE\n");
    printf("\t\t SSSS   NN N NN   AA    AA  KKKKK    EEEEE\n");
    printf("\t\t    SS  NN  NNN   AAAAAAAA  KK  KK   EE\n");
    printf("\t\tSSSSS   NN   NN  AAA    AAA KK   KK  EEEEEEE\n");
}

void printonscr() {
    int x, y, i, printed;
    system("cls");

    for (y = 0; y < LENGTH; y++) {
        for (x = 0; x < WIDTH; x++) {
            if (y == 0 || y == LENGTH - 1 || x == 0 || x == WIDTH - 1)
                printf("#");
            else if (x == f.x && y == f.y)
                printf("*");
            else {
                printed = 0;
                for (i = 0; i < s.length; i++) {
                    if (s.x[i] == x && s.y[i] == y) {
                        printf(i == 0 ? "@" : "O");
                        printed = 1;
                        break;
                    }
                }
                if (!printed) printf(" ");
            }
        }
        printf("\n");
    }
    printf("Score: %d\n", score);
}

