/*
 * controller.cpp
 *
 *  Created on: 27 de nov de 2019
 *      Author: Jessen
 */

#include <Stepper.h>
#include <Arduino.h>
#include "lcd_telas.h"

const int passos = 10;  // passos por volta
bool flag_x, flag_y, flag_z;
const int stepsPerRevolution = 20;
Stepper eixoX(stepsPerRevolution, 2, 3, 4, 5);
Stepper eixoY(stepsPerRevolution, 6, 7, 8, 9);
Stepper eixoZ(stepsPerRevolution, 10, 11, 12, 13);
Stepper eixoS(stepsPerRevolution, 44, 46);

void inicializa_motor()
{
  // velocidade (60 RPM):
  eixoX.setSpeed(60);
  eixoY.setSpeed(60);
  eixoZ.setSpeed(60);
  flag_x, flag_y, flag_z = false;
}

void setRpmX(int rpm){
	eixoX.setSpeed(rpm);
}

void stepX(int steps){
	eixoX.step(steps);
}

void setRpmY(int rpm){
	eixoY.setSpeed(rpm);
}

void stepY(int steps){
	eixoY.step(steps);
}

void setRpmZ(int rpm){
	eixoZ.setSpeed(rpm);
}

void stepZ(int steps){
	eixoZ.step(steps);
}


bool comanda_motor()
{
  while (!(flag_x == true && flag_y == true && flag_z == true))
  {
    //heart_beating();
    if (digitalRead(19) == LOW)
    	eixoX.step(-passos);
    else
      flag_x = true;
    if (digitalRead(20) == LOW)
    	eixoY.step(-passos);
    else
      flag_y = true;
    if (digitalRead(21) == LOW)
    	eixoZ.step(-passos);
    else
      flag_z = true;
  }

  return true;
}

void manual_s(int manuals)
{
	if(manuals != 0)
		manuals = map(manuals, 0, 500, 0, 255);

	analogWrite(SPINDLE, manuals);
}


void interpolation(int x0, int y0, int xf, int yf){
	int posX = 0, posY = 0, i = 0, maior = 0;

	x = x0;
	y = y0;

	if(xf > yf) {
		Serial.println("X maior que Y ");
		posX = (xf - x0)/(yf - y0);
		posY = (xf - x0)%(yf - y0);
		if(posY == 0) {
			stepY(10*(yf - y0));
			y += (yf - y0);

		}
		maior = 1;
		//posX++;
		Serial.println(posX);
		Serial.println(posY);
	}
	else if(yf > xf) {
		posY = (yf - y0)/(xf - x0);
		posX = (yf - y0)%(xf - x0);
		if(posX == 0) {
			stepX(10*(xf - x0));
			x += (xf - x0);

		}
		maior = 2;

		//posY++;
	}

	while((y != yf) && (x != xf)){

		if(x <= xf){
			for(i=0; i<posX; i++){
				stepX(10);
				x+=1;
				Serial.print("X: ");
				Serial.println(x);

			}
		}

		if(y <= yf){
			for(i=0; i<posY; i++){
				stepY(10);
				y+=1;

				Serial.print("Y: ");
				Serial.println(y);
			}
		}
	}

	if(maior == 1){
		if(y == yf){
			stepX(10*posY);
			x += posY;
			Serial.print("X: ");
		}

	}
	else if(maior == 2){
		if(x == xf){
			stepY(10*posX);
			y += posX;
			Serial.print("Y: ");
		}

	}

}




