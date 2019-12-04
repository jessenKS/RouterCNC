#include "Arduino.h"
#include "myLibs/lcd_telas.h"
#include "myLibs/buttons.h"
#include "myLibs/serial.h"
#include "myLibs/controller.h"
//The setup function is called once at startup of the sketch
void setup()
{
// Add your initialization code here
	init_lcd_display();
	inicializa_motor();
	init_serial();
	init_buttons();
	init_debouncer();
}

// The loop function is called in an endless loop
void loop()
{
	funcao_principal();
}
