#ifndef BUTTONS_H_
#define BUTTONS_H_

#define P	       31
#define UP		   33
#define DOWN	   35
#define SET		   37

void init_buttons();
void init_debouncer();
void update_buttons();
bool p_button();
bool set_button();
bool up_button();
bool down_button();


#endif
