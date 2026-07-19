#include <stdio.h>      // Подключаем библиотеку ввода и вывода.
#include "structure.h"  // Продключаем файл с описанием структуры кубика Рубика.

// Сброс одной стороны кубика.
void structureSideReset(unsigned char defaultColor, struct sideCR *ptrSide){
    unsigned char counter = 1;  // Счётчик.
    for (int loop = 0; loop < 3; loop++){
        for (int pool = 0; pool < 3; pool++){
            ptrSide->side[loop][pool] = defaultColor + counter;
            counter++;
        }; // pool
    }; // loop
};

// Сброс кубика Рубика.
void structureCRReset(struct CubicRubik *ptrCR){
    structureSideReset(GREEN, &(ptrCR->sideU));
    structureSideReset(ORANGE, &(ptrCR->sideL));
    structureSideReset(YELLOW, &(ptrCR->sideF));
    structureSideReset(RED, &(ptrCR->sideR));
    structureSideReset(BLUE, &(ptrCR->sideD));
    structureSideReset(WHITE, &(ptrCR->sideB));
};

// Сохранение экземпляра кубика Рубика на диск.
void structureSaveCR(struct CubicRubik *ptrCR, char *filename){
    int size = sizeof(struct CubicRubik);   // Определяем размер структуры CubikRubik'а.
    FILE *fileCR = fopen(filename, "w");    // Открываем файл для записи.
    fwrite(ptrCR, size, 1, fileCR);         // Записываем структуру в файл.
    fclose(fileCR);                         // Закрываем файл.
};
