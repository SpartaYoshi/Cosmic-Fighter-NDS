#ifndef _keypad
#define _keypad
/**********************************************************
 * keypad_screen.h
 **********************************************************/

int is_the_screen_touched();

int pressed_key_value();

void keypad_handler();

void moveLeft();

extern int countdown;

extern void clearText(type);

#endif