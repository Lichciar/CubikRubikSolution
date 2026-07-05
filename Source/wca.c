// https://dedfoma.ru/kubikrubika/mezhdunarodnaya-sistema-oboznachenij.htm
// ' - Apostrophe - Апостроф

#include "structure.h"  // Продключаем файл с описанием структуры кубика Рубика.

// Вспомогательные функции:
// ------------------------

// Вращение стороны куба по часовой стрелке.
void wca_clockewiseRotation(struct sideCR *ptrSide){

    struct sideCR bufferSide; // Элемент стороны куба для вращения.

    // Переворачиваем выбранную сторону по часовой стрелке в буферную.
    for (int loop = 0; loop < 3; loop++){
        for (int pool = 0; pool < 3; pool++){
            bufferSide.side[pool][2 - loop] = ptrSide->side[loop][pool];
        }; // pool
    }; // loop

    // Записываем буферную зону в выбранную сторону.
    for (int loop = 0; loop < 3; loop++){
        for (int pool = 0; pool < 3; pool++){
            ptrSide->side[loop][pool] = bufferSide.side[loop][pool];
        }; // pool
    }; // loop
};

// Вращение стороны куба против часовой стрелки.
void wca_counterClockewiseRotation(struct sideCR *ptrSide){

    struct sideCR bufferSide; // Элемент стороны куба для вращения.

    // Переворачиваем выбранную сторону против часовой стрелке в буферную.
    for (int loop = 0; loop < 3; loop++){
        for (int pool = 0; pool < 3; pool++){
            bufferSide.side[2 - pool][loop] = ptrSide->side[loop][pool];
        }; // pool
    }; // loop

    // Записываем буферную зону в выбранную сторону.
    for (int loop = 0; loop < 3; loop++){
        for (int pool = 0; pool < 3; pool++){
            ptrSide->side[loop][pool] = bufferSide.side[loop][pool];
        }; // pool
    }; // loop
};

// Вращение всего куба:
// --------------------

// Вращение куба по часовой стрелки, если смотреть со стороны ПРАВОЙ грани.
void wca_r(struct CubicRubik *ptrCR){
    /*
     * R before     R after     L before     L after
     * [1][2][3]    [7][4][1]   [1][2][3]    [3][6][9]
     * [4][5][6] => [8][5][2]   [4][5][6] => [2][5][8]
     * [7][8][9]    [9][6][3]   [7][8][9]    [1][4][7]
     *     U        F
     *   L F R => L D R
     *     D        B
     *     B        U
     */

    struct sideCR bufferSide;       // Элемент стороны для работы.

    // Поворачиваем ПРАВУЮ сторону по часовой стрелке.
    wca_clockewiseRotation(&ptrCR->sideR);

    // Поворачиваем ЛЕВУЮ сторону против часовой стрелки.
    wca_counterClockewiseRotation(&ptrCR->sideL);

    // Стороны UFDB меняем на FDBU (вращение по часовой стрелки со стороны R).
    for (int loop = 0; loop < 3; loop++){
        for (int pool = 0; pool < 3; pool++){
            bufferSide.side[loop][pool] = ptrCR->sideU.side[loop][pool];
            ptrCR->sideU.side[loop][pool] = ptrCR->sideF.side[loop][pool];
            ptrCR->sideF.side[loop][pool] = ptrCR->sideD.side[loop][pool];
            ptrCR->sideD.side[loop][pool] = ptrCR->sideB.side[loop][pool];
            ptrCR->sideB.side[loop][pool] = bufferSide.side[loop][pool];
        }; // pool
    }; // loop
};

// Вращение куба по часовой стрелки, если смотреть со стороны ЛЕВОЙ грани.
void wca_l(struct CubicRubik *ptrCR){
    /*
     * R before     R after     L before     L after
     * [1][2][3]    [3][6][9]   [1][2][3]    [7][4][1]
     * [4][5][6] => [2][5][8]   [4][5][6] => [8][5][2]
     * [7][8][9]    [1][4][7]   [7][8][9]    [9][6][3]
     *     U        B
     *   L F R => L U R
     *     D        F
     *     B        D
     */

    struct sideCR bufferSide;       // Элемент стороны для работы.

    // Поворачиваем ПРАВУЮ сторону против часовой стрелки.
    wca_counterClockewiseRotation(&ptrCR->sideR);

    // Поворачиваем ЛЕВУЮ сторону по часовой стрелке.
    wca_clockewiseRotation(&ptrCR->sideL);

    // Стороны UFDB меняем на BUFD (вращение по часовой стрелки со стороны L).
    for (int loop = 0; loop < 3; loop++){
        for (int pool = 0; pool < 3; pool++){
            bufferSide.side[loop][pool] = ptrCR->sideB.side[loop][pool];
            ptrCR->sideB.side[loop][pool] = ptrCR->sideD.side[loop][pool];
            ptrCR->sideD.side[loop][pool] = ptrCR->sideF.side[loop][pool];
            ptrCR->sideF.side[loop][pool] = ptrCR->sideU.side[loop][pool];
            ptrCR->sideU.side[loop][pool] = bufferSide.side[loop][pool];
        }; // pool
    }; // loop
};

// Вращение куба по часовой стрелки, если смотреть со стороны ВЕРХНЕЙ грани.
void wca_u(struct CubicRubik *ptrCR){
    /*
     * U before     U after     D before     D after
     * [1][2][3]    [7][4][1]   [1][2][3]    [3][6][9]
     * [4][5][6] => [8][5][2]   [4][5][6] => [2][5][8]
     * [7][8][9]    [9][6][3]   [7][8][9]    [1][4][7]
     *     U        U
     *   L F R => F R B
     *     D        D
     *     B        L
     */

    struct sideCR bufferSide;       // Элемент стороны для работы.

    // Поворачиваем ВЕРХНЮЮ сторону по часовой стрелке.
    wca_clockewiseRotation(&ptrCR->sideU);

    // Поворачиваем НИЖНЮЮ сторону против часовой стрелки.
    wca_counterClockewiseRotation(&ptrCR->sideD);

    // Стороны LFRB меняем на FRBL (вращение по часовой стрелки со стороны U).
    for (int loop = 0; loop < 3; loop++){
        for (int pool = 0; pool < 3; pool++){
            // При записи из/в B нужно помнить, что B отзеркалена по вертикали.
            bufferSide.side[loop][pool] = ptrCR->sideL.side[loop][pool];
            ptrCR->sideL.side[loop][pool] = ptrCR->sideF.side[loop][pool];
            ptrCR->sideF.side[loop][pool] = ptrCR->sideR.side[loop][pool];
            ptrCR->sideR.side[loop][pool] = ptrCR->sideB.side[2 - loop][2 - pool];
            ptrCR->sideB.side[2 - loop][2 - pool] = bufferSide.side[loop][pool];
        }; // pool
    }; // loop
};

// Вращение куба по часовой стрелки, если смотреть со стороны НИЖНЕЙ грани.
void wca_d(struct CubicRubik *ptrCR){
    /*
     * D before     D after     U before     DU after
     * [1][2][3]    [7][4][1]   [1][2][3]    [3][6][9]
     * [4][5][6] => [8][5][2]   [4][5][6] => [2][5][8]
     * [7][8][9]    [9][6][3]   [7][8][9]    [1][4][7]
     *     U        U
     *   L F R => B L F
     *     D        D
     *     B        R
     */

    struct sideCR bufferSide;       // Элемент стороны для работы.

    // Поворачиваем НИЖНЮЮ сторону по часовой стрелке.
    wca_clockewiseRotation(&ptrCR->sideD);

    // Поворачиваем ВЕРХНЮЮ сторону против часовой стрелки.
    wca_counterClockewiseRotation(&ptrCR->sideU);

    // Стороны LFRB меняем на BLFR (вращение по часовой стрелки со стороны D).
    for (int loop = 0; loop < 3; loop++){
        for (int pool = 0; pool < 3; pool++){
            // При записи из/в B нужно помнить, что B отзеркалена по вертикали.
            bufferSide.side[loop][pool] = ptrCR->sideR.side[loop][pool];
            ptrCR->sideR.side[loop][pool] = ptrCR->sideF.side[loop][pool];
            ptrCR->sideF.side[loop][pool] = ptrCR->sideL.side[loop][pool];
            ptrCR->sideL.side[loop][pool] = ptrCR->sideB.side[2 - loop][2 - pool];
            ptrCR->sideB.side[2 - loop][2 - pool] = bufferSide.side[loop][pool];
        }; // pool
    }; // loop
};

// Вращение куба по часовой стрелки, если смотреть со стороны ФРОНТАЛЬНОЙ грани.
void wca_f(struct CubicRubik *ptrCR){
    /*
     * F before     F after     B before     B after
     * [1][2][3]    [7][4][1]   [1][2][3]    [3][6][9]
     * [4][5][6] => [8][5][2]   [4][5][6] => [2][5][8]
     * [7][8][9]    [9][6][3]   [7][8][9]    [1][4][7]
     *     U        L
     *   L F R => D F U
     *     D        R
     *     B        B
     */

    struct sideCR bufferSide;       // Элемент стороны для работы.

    // Поворачиваем ФРОНТАЛЬНУЮ сторону по часовой стрелке.
    wca_clockewiseRotation(&ptrCR->sideF);

    // Поворачиваем ТЫЛОВУЮ сторону против часовой стрелки.
    wca_counterClockewiseRotation(&ptrCR->sideB);

    // Стороны LURD меняем на DLUR (вращение по часовой стрелки со стороны F).
    for (int loop = 0; loop < 3; loop++){
        for (int pool = 0; pool < 3; pool++){
            bufferSide.side[loop][pool] = ptrCR->sideU.side[loop][pool];
            ptrCR->sideU.side[loop][pool] = ptrCR->sideL.side[2 - pool][loop];
            ptrCR->sideL.side[2 - pool][loop] = ptrCR->sideD.side[2 - loop][2 - pool];
            ptrCR->sideD.side[2 - loop][2 - pool] = ptrCR->sideR.side[pool][2 - loop];
            ptrCR->sideR.side[pool][2 - loop] = bufferSide.side[loop][pool];
        }; // pool
    }; // loop
};

// Вращение куба по часовой стрелки, если смотреть со стороны ТЫЛОВОЙ грани.
void wca_b(struct CubicRubik *ptrCR){
    /*
     * B before     B after     F before     F after
     * [1][2][3]    [7][4][1]   [1][2][3]    [3][6][9]
     * [4][5][6] => [8][5][2]   [4][5][6] => [2][5][8]
     * [7][8][9]    [9][6][3]   [7][8][9]    [1][4][7]
     *     U        R
     *   L F R => U F D
     *     D        L
     *     B        B
     */

    struct sideCR bufferSide;       // Элемент стороны для работы.

    // Поворачиваем ТЫЛОВУЮ сторону по часовой стрелке.
    wca_clockewiseRotation(&ptrCR->sideB);

    // Поворачиваем ФРОНТАЛЬНУЮ сторону против часовой стрелки.
    wca_counterClockewiseRotation(&ptrCR->sideF);

    // Стороны LURD меняем на URDL (вращение по часовой стрелки со стороны B).
    for (int loop = 0; loop < 3; loop++){
        for (int pool = 0; pool < 3; pool++){
            bufferSide.side[loop][pool] = ptrCR->sideU.side[loop][pool];
            ptrCR->sideU.side[loop][pool] = ptrCR->sideR.side[pool][2 - loop];
            ptrCR->sideR.side[pool][2 - loop] = ptrCR->sideD.side[2 - loop][2 - pool];
            ptrCR->sideD.side[2 - loop][2 - pool] = ptrCR->sideL.side[2 - pool][pool];
            ptrCR->sideL.side[2 - pool][loop] = bufferSide.side[loop][pool];
        }; // pool
    }; // loop
};

// Вращение ФРОНТАЛЬНОЙ стороны:
// -----------------------------

// Вращение ФРОНТАЛЬНОЙ стороны по часовой стрелке.
void wca_F(struct CubicRubik *ptrCR){
    /*
     * original     bufferSide
     * [1][2][3]    [7][4][1]    U
     * [4][5][6] => [8][5][2]  L F R
     * [7][8][9]    [9][6][3]    D
     *
     *  И не забываем что 4 соседние стороны тоже перемещаются по часовой стрелке.
     */

    unsigned char value;    // Временное хранилище.

    // Поворачиваем ФРОНТАЛЬНУЮ сторону по часовой стрелке.
    wca_clockewiseRotation(&ptrCR->sideF);

    // У соседних сторон поворачиваем сопряжённые грани по часовой стрелке.
    for (int loop = 0; loop < 3; loop++){
        value = ptrCR->sideU.side[2][loop];
        ptrCR->sideU.side[2][loop] = ptrCR->sideL.side[2 - loop][2];
        ptrCR->sideL.side[2 - loop][2] = ptrCR->sideD.side[0][2 - loop];
        ptrCR->sideD.side[0][2 - loop] = ptrCR->sideR.side[loop][0];
        ptrCR->sideR.side[loop][0] = value;
    }; // loop

};

// Вращение ФРОНТАЛЬНОЙ стороны против часовой стрелке.
void wca_FA(struct CubicRubik *ptrCR){
    /*
     * original     bufferSide
     * [1][2][3]    [3][6][9]    U
     * [4][5][6] => [2][5][8]  L F R
     * [7][8][9]    [1][4][7]    D
     *
     *  И не забываем что 4 соседние стороны тоже перемещаются против часовой стрелке.
     */

    unsigned char value;    // Временное хранилище.

    // Поворачиваем ФРОНТАЛЬНУЮ сторону против часовой стрелке.
    wca_counterClockewiseRotation(&ptrCR->sideF);

    // У соседних сторон поворачиваем сопряжённые грани против часовой стрелки.
    for (int loop = 0; loop < 3; loop++){
        value = ptrCR->sideU.side[2][loop];
        ptrCR->sideU.side[2][loop] = ptrCR->sideR.side[loop][0];
        ptrCR->sideR.side[loop][0] = ptrCR->sideD.side[0][2 - loop];
        ptrCR->sideD.side[0][2 - loop] = ptrCR->sideL.side[2 - loop][2];
        ptrCR->sideL.side[2 - loop][2] = value;
    }; // loop

};

// Вращение ФРОНТАЛЬНОЙ стороны по часовой стрелке и среднего слоя.
void wca_Fw(struct CubicRubik *ptrCR){
    /*
     * original     bufferSide
     * [1][2][3]    [7][4][1]    U
     * [4][5][6] => [8][5][2]  L F R
     * [7][8][9]    [9][6][3]    D
     *
     *  И не забываем что 4 соседние стороны тоже перемещаются по часовой стрелке.
     */

    unsigned char value;    // Временное хранилище.

    wca_F(ptrCR); // Вращаем ФРОНТАЛЬУЮ сторону по часовой стрелке.

    // У соседних сторон поворачиваем средний слой по часовой стрелке.
    for (int loop = 0; loop < 3; loop++){
        value = ptrCR->sideU.side[1][loop];
        ptrCR->sideU.side[1][loop] = ptrCR->sideL.side[2 - loop][1];
        ptrCR->sideL.side[2 - loop][1] = ptrCR->sideD.side[1][2 - loop];
        ptrCR->sideD.side[1][2 - loop] = ptrCR->sideR.side[loop][1];
        ptrCR->sideR.side[loop][1] = value;
    }; // loop

};

// Вращение ФРОНТАЛЬНОЙ стороны против часовой стрелки и среднего слоя.
void wca_FwA(struct CubicRubik *ptrCR){
    /*
     * original     bufferSide
     * [1][2][3]    [7][4][1]    U
     * [4][5][6] => [8][5][2]  L F R
     * [7][8][9]    [9][6][3]    D
     *
     *  И не забываем что 4 соседние стороны тоже перемещаются по часовой стрелке.
     */

        unsigned char value;    // Временное хранилище.

    wca_FA(ptrCR); // Вращаем ФРОНТАЛЬНУЮ сторону против часовой стрелки.

    // У соседних сторон поворачиваем средний слой против часовой стрелки.
    for (int loop = 0; loop < 3; loop++){
        value = ptrCR->sideU.side[1][loop];
        ptrCR->sideU.side[1][loop] = ptrCR->sideR.side[loop][1];
        ptrCR->sideR.side[loop][1] = ptrCR->sideD.side[1][2 - loop];
        ptrCR->sideD.side[1][2 - loop] = ptrCR->sideL.side[2 - loop][1];
        ptrCR->sideL.side[2 - loop][1] = value;
    }; // loop

};

/*  Вращение ТЫЛОВОЙ стороны:
    -- Хитрые вращения кубика --
    ---------------------------- */

// Вращения ТЫЛОВОЙ стороны по часовой стрелке.
void wca_B(struct CubicRubik *ptrCR){

    // Вращаем два раза по часовой стрелке со стороны U, чтобы сторона F стала В.
    wca_u(ptrCR);
    wca_u(ptrCR);

    // И применяем ФРОНТАЛЬНОЕ вращение по часовой стрелке.
    wca_F(ptrCR);

    // Вращаем два раза по часовой стрелке со стороны D, для того чтобы вернуть в исходное положение.
    wca_d(ptrCR);
    wca_d(ptrCR);
};

// Вращения ТЫЛОВОЙ стороны против часовой стрелке.
void wca_BA(struct CubicRubik *ptrCR){

    // Вращаем два раза по часовой стрелке со стороны U, чтобы сторона F стала В.
    wca_u(ptrCR);
    wca_u(ptrCR);

    // И применяем ФРОНТАЛЬНОЕ вращение против часовой стрелке.
    wca_FA(ptrCR);

    // Вращаем два раза по часовой стрелке со стороны D, для того чтобы вернуть в исходное положение.
    wca_d(ptrCR);
    wca_d(ptrCR);
};

// Вращения ТЫЛОВОЙ стороны по часовой стрелке и среднего слоя.
void wca_Bw(struct CubicRubik *ptrCR){

    // Вращаем два раза по часовой стрелке со стороны U, чтобы сторона F стала В.
    wca_u(ptrCR);
    wca_u(ptrCR);

    // И применяем ФРОНТАЛЬНОЕ вращение по часовой стрелке стороны и среднего слоя.
    wca_Fw(ptrCR);

    // Вращаем два раза по часовой стрелке со стороны D, для того чтобы вернуть в исходное положение.
    wca_d(ptrCR);
    wca_d(ptrCR);
};

// Вращения ТЫЛОВОЙ стороны против часовой стрелке и среднего слоя.
void wca_BwA(struct CubicRubik *ptrCR){

    // Вращаем два раза по часовой стрелке со стороны U, чтобы сторона F стала В.
    wca_u(ptrCR);
    wca_u(ptrCR);

    // И применяем ФРОНТАЛЬНОЕ вращение против часовой стрелке стороны и среднего слоя.
    wca_FwA(ptrCR);

    // Вращаем два раза по часовой стрелке со стороны D, для того чтобы вернуть в исходное положение.
    wca_d(ptrCR);
    wca_d(ptrCR);
};

/*  Вращение ЛЕВОЙ стороны:
    -- Хитрые вращения кубика --
    ---------------------------- */

// Вращения ЛЕВОЙ стороны по часовой стрелке.
void wca_L(struct CubicRubik *ptrCR){

    // Вращаем по часовой стрелке со стороны D, чтобы сторона F стала L.
    wca_d(ptrCR);

    // И применяем ФРОНТАЛЬНОЕ вращение по часовой стрелке.
    wca_F(ptrCR);

    // Вращаем по часовой стрелке со стороны U, для того чтобы вернуть в исходное положение.
    wca_u(ptrCR);
};

// Вращения ЛЕВОЙ стороны против часовой стрелке.
void wca_LA(struct CubicRubik *ptrCR){

    // Вращаем по часовой стрелке со стороны D, чтобы сторона F стала L.
    wca_d(ptrCR);

    // И применяем ФРОНТАЛЬНОЕ вращение против часовой стрелке.
    wca_FA(ptrCR);

    // Вращаем по часовой стрелке со стороны U, для того чтобы вернуть в исходное положение.
    wca_u(ptrCR);
};

// Вращения ЛЕВОЙ стороны по часовой стрелке и среднего слоя.
void wca_Lw(struct CubicRubik *ptrCR){

    // Вращаем по часовой стрелке со стороны D, чтобы сторона F стала L.
    wca_d(ptrCR);

    // И применяем ФРОНТАЛЬНОЕ вращение по часовой стрелке стороны и среднего слоя.
    wca_Fw(ptrCR);

    // Вращаем по часовой стрелке со стороны U, для того чтобы вернуть в исходное положение.
    wca_u(ptrCR);
};

// Вращения ЛЕВОЙ стороны против часовой стрелке и среднего слоя.
void wca_LwA(struct CubicRubik *ptrCR){

    // Вращаем по часовой стрелке со стороны D, чтобы сторона F стала L.
    wca_d(ptrCR);

    // И применяем ФРОНТАЛЬНОЕ вращение против часовой стрелке стороны и среднего слоя.
    wca_FwA(ptrCR);

    // Вращаем по часовой стрелке со стороны U, для того чтобы вернуть в исходное положение.
    wca_u(ptrCR);
};

/*  Вращение ПРАВОЙ стороны:
    -- Хитрые вращения кубика --
    ---------------------------- */

// Вращения ПРАВОЙ стороны по часовой стрелке.
void wca_R(struct CubicRubik *ptrCR){

    // Вращаем по часовой стрелке со стороны U, чтобы сторона F стала R.
    wca_u(ptrCR);

    // И применяем ФРОНТАЛЬНОЕ вращение по часовой стрелке.
    wca_F(ptrCR);

    // Вращаем по часовой стрелке со стороны D, для того чтобы вернуть в исходное положение.
    wca_d(ptrCR);
};

// Вращения ПРАВОЙ стороны против часовой стрелке.
void wca_RA(struct CubicRubik *ptrCR){

    // Вращаем по часовой стрелке со стороны U, чтобы сторона F стала R.
    wca_u(ptrCR);

    // И применяем ФРОНТАЛЬНОЕ вращение против часовой стрелке.
    wca_FA(ptrCR);

    // Вращаем по часовой стрелке со стороны D, для того чтобы вернуть в исходное положение.
    wca_d(ptrCR);
};

// Вращения ПРАВОЙ стороны по часовой стрелке и среднего слоя.
void wca_Rw(struct CubicRubik *ptrCR){

    // Вращаем по часовой стрелке со стороны U, чтобы сторона F стала R.
    wca_u(ptrCR);

    // И применяем ФРОНТАЛЬНОЕ вращение по часовой стрелке стороны и среднего слоя.
    wca_Fw(ptrCR);

    // Вращаем по часовой стрелке со стороны D, для того чтобы вернуть в исходное положение.
    wca_d(ptrCR);
};

// Вращения ЛЕВОЙ стороны против часовой стрелке и среднего слоя.
void wca_RwA(struct CubicRubik *ptrCR){

    // Вращаем по часовой стрелке со стороны U, чтобы сторона F стала R.
    wca_u(ptrCR);

    // И применяем ФРОНТАЛЬНОЕ вращение против часовой стрелке стороны и среднего слоя.
    wca_FwA(ptrCR);

    // Вращаем по часовой стрелке со стороны D, для того чтобы вернуть в исходное положение.
    wca_d(ptrCR);
};

/*  Вращение ВЕРХНЕЙ стороны:
    -- Хитрые вращения кубика --
    ---------------------------- */

// Вращения ВЕРХНЕЙ стороны по часовой стрелке.
void wca_U(struct CubicRubik *ptrCR){

    // Вращаем по часовой стрелке со стороны L, чтобы сторона F стала U.
    wca_l(ptrCR);

    // И применяем ФРОНТАЛЬНОЕ вращение по часовой стрелке.
    wca_F(ptrCR);

    // Вращаем по часовой стрелке со стороны R, для того чтобы вернуть в исходное положение.
    wca_r(ptrCR);
};

// Вращения ВЕРХНЕЙ стороны против часовой стрелке.
void wca_UA(struct CubicRubik *ptrCR){

    // Вращаем по часовой стрелке со стороны L, чтобы сторона F стала U.
    wca_l(ptrCR);

    // И применяем ФРОНТАЛЬНОЕ вращение против часовой стрелке.
    wca_FA(ptrCR);

    // Вращаем по часовой стрелке со стороны R, для того чтобы вернуть в исходное положение.
    wca_r(ptrCR);
};

// Вращения ВЕРХНЕЙ стороны по часовой стрелке и среднего слоя.
void wca_Uw(struct CubicRubik *ptrCR){

    // Вращаем по часовой стрелке со стороны L, чтобы сторона F стала U.
    wca_l(ptrCR);

    // И применяем ФРОНТАЛЬНОЕ вращение по часовой стрелке стороны и среднего слоя.
    wca_Fw(ptrCR);

    // Вращаем по часовой стрелке со стороны R, для того чтобы вернуть в исходное положение.
    wca_r(ptrCR);
};

// Вращения ВЕРХНЕЙ стороны против часовой стрелке и среднего слоя.
void wca_UwA(struct CubicRubik *ptrCR){

    // Вращаем по часовой стрелке со стороны L, чтобы сторона F стала U.
    wca_l(ptrCR);

    // И применяем ФРОНТАЛЬНОЕ вращение против часовой стрелке стороны и среднего слоя.
    wca_FwA(ptrCR);

    // Вращаем по часовой стрелке со стороны R, для того чтобы вернуть в исходное положение.
    wca_r(ptrCR);
};

/*  Вращение НИЖНЕЙ стороны:
    -- Хитрые вращения кубика --
    ---------------------------- */

// Вращения НИЖНЕЙ стороны по часовой стрелке.
void wca_D(struct CubicRubik *ptrCR){

    // Вращаем по часовой стрелке со стороны R, чтобы сторона F стала D.
    wca_r(ptrCR);

    // И применяем ФРОНТАЛЬНОЕ вращение по часовой стрелке.
    wca_F(ptrCR);

    // Вращаем по часовой стрелке со стороны L, для того чтобы вернуть в исходное положение.
    wca_l(ptrCR);
};

// Вращения НИЖНЕЙ стороны против часовой стрелке.
void wca_DA(struct CubicRubik *ptrCR){

    // Вращаем по часовой стрелке со стороны R, чтобы сторона F стала D.
    wca_r(ptrCR);

    // И применяем ФРОНТАЛЬНОЕ вращение против часовой стрелке.
    wca_FA(ptrCR);

    // Вращаем по часовой стрелке со стороны L, для того чтобы вернуть в исходное положение.
    wca_l(ptrCR);
};

// Вращения ВЕРХНЕЙ стороны по часовой стрелке и среднего слоя.
void wca_Dw(struct CubicRubik *ptrCR){

    // Вращаем по часовой стрелке со стороны R, чтобы сторона F стала D.
    wca_r(ptrCR);

    // И применяем ФРОНТАЛЬНОЕ вращение по часовой стрелке стороны и среднего слоя.
    wca_Fw(ptrCR);

    // Вращаем по часовой стрелке со стороны L, для того чтобы вернуть в исходное положение.
    wca_l(ptrCR);
};

// Вращения ВЕРХНЕЙ стороны против часовой стрелке и среднего слоя.
void wca_DwA(struct CubicRubik *ptrCR){

    // Вращаем по часовой стрелке со стороны R, чтобы сторона F стала D.
    wca_r(ptrCR);

    // И применяем ФРОНТАЛЬНОЕ вращение против часовой стрелке стороны и среднего слоя.
    wca_FwA(ptrCR);

    // Вращаем по часовой стрелке со стороны L, для того чтобы вернуть в исходное положение.
    wca_l(ptrCR);
};
