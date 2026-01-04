#ifndef SNAKE_H
#define SNAKE_H

#define MAXLEN 100

struct snake {
    int x[MAXLEN];
    int y[MAXLEN];
    int length;
    char dir;
};

struct food {
    int x;
    int y;
};

extern struct snake s;
extern struct food f;

void runtime();
void input();
void movement();
void selfcol();
void isfoodeaten();
void walcol();

#endif

