#ifndef WCA_H
#define WCA_H

// Объявление функций:
void wca_clockewiseRotation(struct sideCR *ptrSide);
void wca_counterClockewiseRotation(struct sideCR *ptrSide);

void wca_x(struct CubicRubik *ptrCR);
void wca_xA(struct CubicRubik *ptrCR);

void wca_F(struct CubicRubik *ptrCR);
void wca_FA(struct CubicRubik *ptrCR);
void wca_Fw(struct CubicRubik *ptrCR);
void wca_FwA(struct CubicRubik *ptrCR);

#endif
