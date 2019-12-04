#ifndef LCD_TELAS_H_
#define LCD_TELAS_H_

#define INIT		0
#define ERROR		1
#define PROGRESS	2
#define POSITION 	3
#define OVERTRAVEL	4
#define COVERCLOSED 18
#define SPINDLE 44

extern int state;
extern bool coverClosed;
extern int x;
extern int y;
extern int z;
extern int s;
extern int overTravel;

void interruptCover();
void init_screen();
void error_screen();
void progress_screen();
void position_screen();
void overtravel_screen();
void init_lcd_display();
void funcao_principal();

#endif
