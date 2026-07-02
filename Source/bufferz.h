#ifndef BUFFERZ_H
#define BUFFERZ_H

// Временный буфер для отладки в консоли.
struct BufferZ{
    /* Наглядное представление буфера для кубика Рубика как набор массивов:
     * По горизонтали 38, по вертикали 15;
     * 00              [11][12][13]
     * 01              [14][xx][xx]
     * 02              [17][xx][xx]
     * 03
     * 04 [21][22][23] [31][31][32] [41][41][43]
     * 05 [24][xx][xx] [34][xx][xx] [44][xx][xx]
     * 06 [27][xx][xx] [37][xx][xx] [47][xx][xx]
     * 07
     * 08              [51][51][52]
     * 09              [54][xx][xx]
     * 10              [57][xx][xx]
     * 11
     * 12              [61][61][62]
     * 13              [64][xx][xx]
     * 14              [67][xx][xx]
     */
    unsigned char signPlace[15][39];
};

// Объявление функций:
void bufferZClean(struct BufferZ *ptrBufferZ);
void bufferZOutputInConsole(struct BufferZ *ptrBufferZ);
void bufferZFillSide(int y, int x, struct sideCR *ptrSide, struct BufferZ *ptrBufferZ);
void bufferZFillData(struct CubicRubik *ptrCR, struct BufferZ *ptrBufferZ);

#endif
