/*  CubicRibikaSolution:
    Эмулятор кубика Рубика.
    Начало: 13 июня 2026 г.
    Изменено: 05 июля 2026 г. */

#include "structure.h"  // Продключаем файл с описанием структуры кубика Рубика.
#include "bufferz.h"    // Подключаем файл с описание буфера для вывода на консоль всего кубика Рубика.
#include "wca.h"        // Подключаем файл с командами вращения кубика Рубика.

// Основная программа:
// int main(int argc, char *argv[]){
int main(){
    struct CubicRubik currentCR;    // Создаем экземпляр кубика Рубика.
    struct BufferZ currentBuffer;   // Создаём кэземпляр буфера для вывода на консоль.

    bufferZClean(&currentBuffer);           // Очищаем буфер.
    structureCRReset(&currentCR);           // Сбрасываем кубик.

    /* для ТЕСТА!!!
    currentCR.sideF.side[0][0] = GREEN;
    currentCR.sideF.side[0][1] = ORANGE;
    currentCR.sideF.side[0][2] = YELLOW;
    currentCR.sideF.side[1][0] = RED;
    currentCR.sideF.side[1][1] = BLUE;
    currentCR.sideF.side[1][2] = WHITE;
    currentCR.sideF.side[2][0] = YELLOW;
    currentCR.sideF.side[2][1] = RED;
    currentCR.sideF.side[2][2] = ORANGE; */

    /*
    for (int loop = 0; loop < 3; loop++){
        for (int pool = 0; pool < 3; pool++){
            currentCR.sideU.side[loop][pool] = currentCR.sideF.side[loop][pool];
            currentCR.sideL.side[loop][pool] = currentCR.sideF.side[loop][pool];
            currentCR.sideR.side[loop][pool] = currentCR.sideF.side[loop][pool];
            currentCR.sideD.side[loop][pool] = currentCR.sideF.side[loop][pool];
        }; // pool
    }; // loop
    */


    bufferZFillData(&currentCR, &currentBuffer);        // Переносим кубик в буфер.
    bufferZOutputInConsole(&currentBuffer);             // Выводим буфер в консоль.

    //printf("wca_d\n");
    wca_f(&currentCR); // Тестовые вращения.
    bufferZFillData(&currentCR, &currentBuffer);        // Переносим кубик в буфер.
    bufferZOutputInConsole(&currentBuffer);             // Выводим буфер в консоль.
    structureSaveCR(&currentCR, CRSTORAGE"test.cr");    // Сохраняем кубик Рубик на диск.

    // Вывод аргументов
    //for (int i = 0; i < argc; i++) {
    //    printf("Аргумент %d: %s\n", i, argv[i]);
    //};

    return 0;
}
