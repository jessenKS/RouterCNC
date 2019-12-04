/*
 * controller.h
 *
 *  Created on: 27 de nov de 2019
 *      Author: Jessen
 */

#ifndef MYLIBS_CONTROLLER_H_
#define MYLIBS_CONTROLLER_H_

void inicializa_motor();
void setRpmX(int rpm);
void setRpmY(int rpm);
void setRpmZ(int rpm);
void setRpmS(int rpm);
void stepX(int steps);
void stepY(int steps);
void stepZ(int steps);
void stepS(int steps);
bool comanda_motor();
void manual_s(int manuals);
void interpolation(int x0, int y0, int x, int y);

#endif /* MYLIBS_CONTROLLER_H_ */
