#ifndef STRUCTURE_H
#define STRUCTURE_H

// Для упрощения работы с цветами:
#define EMPTY 0
#define GREEN 1
#define ORANGE 2
#define YELLOW 3
#define RED 4
#define BLUE 5
#define WHITE 6
#define LEFT 7
#define RIGTH 8

// Структура одной стороны кубика Рубика.
struct sideCR{
    unsigned char side[3][3];
};

// Структура кубика Рубика.
struct CubicRubik{
    /* Наглядное представление кубика Рубика как набор массивов:
     *               Сторона Up
     *                (зелёный)
     *                [0][1][2]
     *                [1][x][x]
     *                [2][x][x]
     *  Сторона Left Сторона Front Сторона Right
     *      (оранж.)  (жёлтый)  (красный)
     *      [0][1][2] [0][1][2] [0][1][2]
     *      [1][x][x] [1][x][x] [1][x][x]
     *      [2][x][x] [2][x][x] [2][x][x]
     *               Сторона Down
     *                 (синий)
     *                [0][1][2]
     *                [1][x][x]
     *                [2][x][x]
     *               Сторона Back
     *                 (белый)
     *                [0][1][2]
     *                [1][x][x]
     *                [2][x][x]
     */

    struct sideCR sideU;  // Up/Green - зелёный.
    struct sideCR sideL;  // Left/Orange - оранжевый.
    struct sideCR sideF;  // Front/Yellow - жёлтый.
    struct sideCR sideR;  // Right/Red - красный.
    struct sideCR sideD;  // Down/Blue - синий.
    struct sideCR sideB;  // Back/White - белый.
};

// Объявление фуекций:
void structureSideReset(unsigned char defaultColor, struct sideCR *ptrSide);
void structureCRReset(struct CubicRubik *ptrCR);

#endif
