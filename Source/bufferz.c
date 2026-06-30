#include <stdio.h>      // Подключаем библиотеку ввода и вывода.
#include "structure.h"  // Продключаем файл с описанием структуры кубика Рубика.
#include "bufferz.h"    // Подключаем файл с описание буфера для вывода на консоль всего кубика Рубика.

// Очистка буфера.
void bufferZClean(struct BufferZ *ptrBufferZ){
    for (int loop = 0; loop < 12; loop++){
        for (int pool = 0; pool < 27; pool++){
            ptrBufferZ->signPlace[loop][pool] = 0;
        }; // pool
    }; // loop
};

// Вывод буфера на экран.
void bufferZOutputInConsole(struct BufferZ *ptrBufferZ){
    char *outputSign = " GOYRBW[]"; // Отображаемые символы на экране.
    unsigned char index;            // Временная переменная.

    for (int loop = 0; loop < 12; loop++){
        for (int pool = 0; pool < 27; pool++){
            index = (ptrBufferZ->signPlace[loop][pool]);
            printf("%c", outputSign[index]);
        }; // pool
        printf("\n"); // Переводим каретку на новую строку.
    }; // loop
    printf("\n"); // Делаем отступ для читаемости.
};

// Переносим сторону кубика Рубика в буфер.
void bufferZFillSide(int x, int y, struct sideCR *ptrSide, struct BufferZ *ptrBufferZ){
    for (int loop = 0; loop < 3; loop++){
        for (int pool = 0; pool < 3; pool++){
            ptrBufferZ->signPlace[y + loop][x + pool * 3] = LEFT;
            ptrBufferZ->signPlace[y + loop][x + pool * 3 + 1] = ptrSide->side[loop][pool];
            ptrBufferZ->signPlace[y + loop][x + pool * 3 + 2] = RIGTH;
        }; // pool
    }; // loop
};

// Переносим кубик Рубика в буфер.
void bufferZFillData(struct CubicRubik *ptrCR, struct BufferZ *ptrBufferZ){
    bufferZFillSide(9, 0, &ptrCR->sideU, ptrBufferZ);
    bufferZFillSide(0, 3, &ptrCR->sideL, ptrBufferZ);
    bufferZFillSide(9, 3, &ptrCR->sideF, ptrBufferZ);
    bufferZFillSide(18, 3, &ptrCR->sideR, ptrBufferZ);
    bufferZFillSide(9, 6, &ptrCR->sideD, ptrBufferZ);
    bufferZFillSide(9, 9, &ptrCR->sideB, ptrBufferZ);
};
