#ifndef WCA_H
#define WCA_H

// Объявление функций:
void wca_clockewiseRotation(struct sideCR *ptrSide);
void wca_counterClockewiseRotation(struct sideCR *ptrSide);

void wca_r(struct CubicRubik *ptrCR);
void wca_l(struct CubicRubik *ptrCR);
void wca_u(struct CubicRubik *ptrCR);
void wca_d(struct CubicRubik *ptrCR);
void wca_f(struct CubicRubik *ptrCR);
void wca_b(struct CubicRubik *ptrCR);

void wca_F(struct CubicRubik *ptrCR);
void wca_FA(struct CubicRubik *ptrCR);
void wca_Fw(struct CubicRubik *ptrCR);
void wca_FwA(struct CubicRubik *ptrCR);

void wca_B(struct CubicRubik *ptrCR);
void wca_BA(struct CubicRubik *ptrCR);
void wca_Bw(struct CubicRubik *ptrCR);
void wca_BwA(struct CubicRubik *ptrCR);

void wca_L(struct CubicRubik *ptrCR);
//void wca_LA(struct CubicRubik *ptrCR);
//void wca_Lw(struct CubicRubik *ptrCR);
//void wca_LwA(struct CubicRubik *ptrCR);

#endif
