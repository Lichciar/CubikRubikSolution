#ifndef WCA_H
#define WCA_H

// Объявление функций.
// Вспомогательные функции:
void wca_clockewiseRotation(struct sideCR *ptrSide);
void wca_counterClockewiseRotation(struct sideCR *ptrSide);

// Вращение всего куба:
void wca_r(struct CubicRubik *ptrCR);
void wca_l(struct CubicRubik *ptrCR);
void wca_u(struct CubicRubik *ptrCR);
void wca_d(struct CubicRubik *ptrCR);
void wca_f(struct CubicRubik *ptrCR);
void wca_b(struct CubicRubik *ptrCR);

// Вращение ФРОНТАЛЬНОЙ стороны:
void wca_F(struct CubicRubik *ptrCR);
void wca_FA(struct CubicRubik *ptrCR);
void wca_Fw(struct CubicRubik *ptrCR);
void wca_FwA(struct CubicRubik *ptrCR);

// Вращение ТЫЛЬНОЙ стороны:
void wca_B(struct CubicRubik *ptrCR);
void wca_BA(struct CubicRubik *ptrCR);
void wca_Bw(struct CubicRubik *ptrCR);
void wca_BwA(struct CubicRubik *ptrCR);

// Вращение ЛЕВОЙ стороны:
void wca_L(struct CubicRubik *ptrCR);
void wca_LA(struct CubicRubik *ptrCR);
void wca_Lw(struct CubicRubik *ptrCR);
void wca_LwA(struct CubicRubik *ptrCR);

// Вращение ПРАВОЙ стороны:
void wca_R(struct CubicRubik *ptrCR);
void wca_RA(struct CubicRubik *ptrCR);
void wca_Rw(struct CubicRubik *ptrCR);
void wca_RwA(struct CubicRubik *ptrCR);

// Вращение ВЕРХНЕЙ стороны:
void wca_U(struct CubicRubik *ptrCR);
void wca_UA(struct CubicRubik *ptrCR);
void wca_Uw(struct CubicRubik *ptrCR);
void wca_UwA(struct CubicRubik *ptrCR);

// Вращение НИЖНЕЙ стороны:
void wca_D(struct CubicRubik *ptrCR);
void wca_DA(struct CubicRubik *ptrCR);
void wca_Dw(struct CubicRubik *ptrCR);
void wca_DwA(struct CubicRubik *ptrCR);

#endif
