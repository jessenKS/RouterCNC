/*
 * serial.cpp
 *
 *  Created on: 27 de nov de 2019
 *      Author: Jessen
 */

#include <string.h>
#include <stdlib.h>
#include <Arduino.h>
#include "controller.h"
#include "lcd_telas.h"

String comando, f_valor, s_aux, cw_aux, ccw_aux, x_aux, y_aux, z_aux;
char recebe, termina = '0', s_valor[4], cw_valor[4], ccw_valor[4], x_valor[4], y_valor[4], z_valor[4];
int posicoes[8], s_posicao, cw_posicao, ccw_posicao, f_posicao, x_posicao, y_posicao, z_posicao, final_posicao, y_final, z_final, x_final, s = 0, x, y, z;

void init_serial()
{
  Serial.begin(115200);
  Serial.println("Start");
}

int positions(int atual_posicao, int *posicoes)
{
  int i, proximo;
  for (i = 7; i > 0; i--)
  {
    if (i == 7)
      proximo = posicoes[i];
    else if (atual_posicao < posicoes[i] && posicoes[i] < proximo)
      proximo = posicoes[i];
  }
  return proximo;
}

void comands()
{
  int proximo;
  if (Serial.available() > 0)
  {
    recebe = Serial.read();
    comando.concat(recebe);
    if (comando.startsWith("$") && comando.endsWith("#"))
    {
      s_posicao = comando.indexOf("S=");
      posicoes[0] = s_posicao;

      cw_posicao = comando.indexOf("M3");
      posicoes[1] = cw_posicao;

      ccw_posicao = comando.indexOf("M4");
      posicoes[2] = ccw_posicao;

      f_posicao = comando.indexOf("F=");
      posicoes[3] = f_posicao;

      x_posicao = comando.indexOf("X=");
      posicoes[4] = x_posicao;

      y_posicao = comando.indexOf("Y=");
      posicoes[5] = y_posicao;

      z_posicao = comando.indexOf("Z=");
      posicoes[6] = z_posicao;

      final_posicao = comando.indexOf("#");
      posicoes[7] = final_posicao;

      Serial.print("COMANDOS SERIAL: ");
      Serial.println(comando);

      if (s_posicao > 0)
      {
        proximo = positions(s_posicao, posicoes);
        Serial.print("VALOR DE S: ");
        s_aux = comando.substring(s_posicao + 2, proximo + 1);
        s_aux.toCharArray(s_valor, s_aux.length());
        s = atoi(s_valor);
        Serial.println(s);

       }

      if(x_posicao > 0 && y_posicao > 0){
    	  proximo = positions(x_posicao, posicoes);
		  Serial.print("VALOR DE X: ");
		  x_aux = comando.substring(x_posicao + 2, proximo + 1);
		  x_aux.toCharArray(x_valor, x_aux.length());
		  x_final = atoi(x_valor);
		  Serial.println(x_final);

		  proximo = positions(y_posicao, posicoes);
		  Serial.print("VALOR DE Y: ");
		  y_aux = comando.substring(y_posicao + 2, proximo + 1);
		  y_aux.toCharArray(y_valor, y_aux.length());
		  y_final = atoi(y_valor);
		  Serial.println(y_final);

		  interpolation(x, y, x_final, y_final);

      }

      if (f_posicao > 0)
      {
        proximo = positions(f_posicao, posicoes);
        Serial.print("VALOR DE F: ");
        f_valor = comando.substring(f_posicao + 2, proximo);
        Serial.println(f_valor);
      }

      if (x_posicao > 0)
      {
        proximo = positions(x_posicao, posicoes);
        Serial.print("VALOR DE X: ");
        x_aux = comando.substring(x_posicao + 2, proximo + 1);
        x_aux.toCharArray(x_valor, x_aux.length());
        x_final = atoi(x_valor);
        Serial.println(x_final);
      }

      if (y_posicao > 0)
      {
        proximo = positions(y_posicao, posicoes);
        Serial.print("VALOR DE Y: ");
        y_aux = comando.substring(y_posicao + 2, proximo + 1);
        y_aux.toCharArray(y_valor, y_aux.length());
        y_final = atoi(y_valor);
        Serial.println(y_final);
      }

      if (z_posicao > 0)
      {
        proximo = positions(z_posicao, posicoes);
        Serial.print("VALOR DE Z: ");
        z_aux = comando.substring(z_posicao + 2, proximo + 1);
        z_aux.toCharArray(z_valor, z_aux.length());
        z_final = atoi(z_valor);
        Serial.println(z_final);
      }
      if(cw_posicao > 0)
      {
        Serial.println("ROTACAO SENTIDO CW: M3");
      }
      if(ccw_posicao > 0)
      {
        Serial.println("ROTACAO SENTIDO CCW: M4");
      }
      comando = "\0";
    }
  }
}



