// https://dedfoma.ru/kubikrubika/mezhdunarodnaya-sistema-oboznachenij.htm
// ' - Apostrophe - Апостроф

#include "structure.h"  // Продключаем файл с описанием структуры кубика Рубика.

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

// Вращение куба по часовой стрелки, если смотреть со стороны ПРАВОЙ грани.
void wca_x(struct CubicRubik *ptrCR){
    /*
     * R before     R after     L before     L after
     * [1][2][3]    [7][4][1]   [1][2][3]    [3][6][9]
     * [4][5][6] => [8][5][2]   [4][5][6] => [2][5][8]
     * [7][8][9]    [9][6][3]   [7][8][9]    [1][4][7]
     *     U        F
     *   L F R => L D R
     *     D        B
     *     B        U
     *  И не забываем что сторону L и R тоже поворачивавем по часовой стрелке.
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

// Вращение куба против часовой стрелки, если смотреть со стороны ПРАВОЙ грани.
void wca_xA(struct CubicRubik *ptrCR){
    /*
     * R before     R after     L before     L after
     * [1][2][3]    [3][6][9]   [1][2][3]    [7][4][1]
     * [4][5][6] => [2][5][8]   [4][5][6] => [8][5][2]
     * [7][8][9]    [1][4][7]   [7][8][9]    [9][6][3]
     *     U        B
     *   L F R => L U R
     *     D        F
     *     B        D
     *  И не забываем что сторону L и R тоже поворачивавем по часовой стрелке.
     */

    struct sideCR bufferSide;       // Элемент стороны для работы.

    // Поворачиваем ПРАВУЮ сторону против часовой стрелки.
    wca_counterClockewiseRotation(&ptrCR->sideR);

    // Поворачиваем ЛЕВУЮ сторону по часовой стрелке.
    wca_clockewiseRotation(&ptrCR->sideL);

    // Стороны UFDB меняем на BUFD (вращение против часовой стрелки со стороны R).
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

// y сверху
//
// z фронтально

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

// Для остальных вращений можно пойти на хитрость: сначала поддельный кубик разворачивать нужной стороной на фронтальную.
// Затем вращать.
// Возвращать кубик в нужную сторону.
// Это будет окономичное написание кода, но не экономичное выполнение кода.
// В принципе можно и попробывать для прикола.
