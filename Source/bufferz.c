#include <stdio.h>      // Подключаем библиотеку ввода и вывода.
#include "structure.h"  // Продключаем файл с описанием структуры кубика Рубика.
#include "bufferz.h"    // Подключаем файл с описание буфера для вывода на консоль всего кубика Рубика.

// Очистка буфера.
void bufferZClean(struct BufferZ *ptrBufferZ){
    for (int loop = 0; loop < 15; loop++){
        for (int pool = 0; pool < 39; pool++){
            ptrBufferZ->signPlace[loop][pool] = EMPTY;
        }; // pool
    }; // loop
};

// Вывод буфера на экран.
void bufferZOutputInConsole(struct BufferZ *ptrBufferZ){
    char *outputNumber = " 123456789";  // Словарь с цифрами.
    char *outputSign = " GOYRBW[]";     // Словарь с символами.

    unsigned char index;    // Временная переменная.

    // Перебираем все элементы буфера.
    for (int loop = 0; loop < 15; loop++){
        for (int pool = 0; pool < 39; pool++){

            // Считываем значение элемента кубика.
            index = (ptrBufferZ->signPlace[loop][pool]);

            if (index > 9){
                printf("%c", outputSign[index/10]);
            } else {
                printf("%c", outputNumber[index]);
            };
        }; // pool
        printf("\n"); // Переводим каретку на новую строку.

    }; // loop
    printf("\n"); // Делаем отступ для читаемости.
    printf("--------------------------------------\n\n");
};

// Переносим сторону кубика Рубика в буфер.
void bufferZFillSide(int y, int x, struct sideCR *ptrSide, struct BufferZ *ptrBufferZ){

    unsigned char counter;  // Счётчик для цвета элементов кубика.

    for (int loop = 0; loop < 3; loop++){
        for (int pool = 0; pool < 3; pool++){

            counter = 0; // Сброс счётчика.

            // Определяемся с цветом элемента.
            while (ptrSide->side[loop][pool] > counter * 10 + 9){
                counter++;
            };

            // Заполняем буфер.
            ptrBufferZ->signPlace[y + loop][x + pool * 4] = LEFT;
            ptrBufferZ->signPlace[y + loop][x + pool * 4 + 1] = counter * 10;                               // Цвет.
            ptrBufferZ->signPlace[y + loop][x + pool * 4 + 2] = ptrSide->side[loop][pool] - counter * 10;   // Индекс.
            ptrBufferZ->signPlace[y + loop][x + pool * 4 + 3] = RIGTH;
        }; // pool
    }; // loop
};

// Переносим кубик Рубика в буфер.
void bufferZFillData(struct CubicRubik *ptrCR, struct BufferZ *ptrBufferZ){
    bufferZFillSide(0, 13, &ptrCR->sideU, ptrBufferZ);
    bufferZFillSide(4, 0, &ptrCR->sideL, ptrBufferZ);
    bufferZFillSide(4, 13, &ptrCR->sideF, ptrBufferZ);
    bufferZFillSide(4, 26, &ptrCR->sideR, ptrBufferZ);
    bufferZFillSide(8, 13, &ptrCR->sideD, ptrBufferZ);
    bufferZFillSide(12, 13, &ptrCR->sideB, ptrBufferZ);
};
