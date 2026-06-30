#ifndef BUFFERZ_H
#define BUFFERZ_H

// Временный буфер для отладки в консоли.
struct BufferZ{
    /* Наглядное представление буфера для кубика Рубика как набор массивов:
     * По горизонтали 27, по вертикали 12;
     * 00           [0][1][2]
     * 01           [1][x][x]
     * 02           [2][x][x]
     * 03 [0][1][2] [0][1][2] [0][1][2]
     * 04 [1][x][x] [1][x][x] [1][x][x]
     * 05 [2][x][x] [2][x][x] [2][x][x]
     * 06           [0][1][2]
     * 07           [1][x][x]
     * 08           [2][x][x]
     * 09           [0][1][2]
     * 10           [1][x][x]
     * 11           [2][x][x]
     */
    unsigned char signPlace[21][35];
};

// Объявление функций:
void bufferZClean(struct BufferZ *ptrBufferZ);
void bufferZOutputInConsole(struct BufferZ *ptrBufferZ);
void bufferZFillSide(int x, int y, struct sideCR *ptrSide, struct BufferZ *ptrBufferZ);
void bufferZFillData(struct CubicRubik *ptrCR, struct BufferZ *ptrBufferZ);

#endif
