#include "structure.h"  // Продключаем файл с описанием структуры кубика Рубика.

// Сброс одной стороны кубика.
void structureSideReset(unsigned char defaultColor, struct sideCR *ptrSide){
    for (int loop = 0; loop < 3; loop++){
        for (int pool = 0; pool < 3; pool++){
            ptrSide->side[loop][pool] = defaultColor;
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
