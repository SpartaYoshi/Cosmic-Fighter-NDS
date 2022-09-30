/**********************************************************
 * keypad_screen.c
 **********************************************************/
#include <nds.h>
#include <stdio.h>
#include "defines.h"
#include "sprites.h"



int is_the_screen_touched() {
	touchPosition screen_pos;
	touchRead(&screen_pos);
  	return !(screen_pos.px==0 && screen_pos.py==0);
} // is_the_screen_touched()


int pressed_key_value() {
	// TWO BUTTON CASES
	if (!(KEYS_DAT & 0x0012)) return RIGHTB; 
	else if (!(KEYS_DAT & 0x0022)) return LEFTB; 
	// ONE BUTTON CASES
	else if (!(KEYS_DAT & 0x0001)) return A; 
	else if (!(KEYS_DAT & 0x0002)) return B; 
	else if (!(KEYS_DAT & 0x0004)) return SELECT; 
	else if (!(KEYS_DAT & 0x0008)) return START; 
	else if (!(KEYS_DAT & 0x0010)) return RIGHT; 
	else if (!(KEYS_DAT & 0x0020)) return LEFT; 
	else if (!(KEYS_DAT & 0x0040)) return UP; 
	else if (!(KEYS_DAT & 0x0080)) return DOWN; 
	else if (!(KEYS_DAT & 0x0100)) return R; 
	else if (!(KEYS_DAT & 0x0200)) return L; 

	else return -1;
} // pressed_key_value()


void keypad_handler() {
	
	if (pressed_key_value() == B || pressed_key_value() == LEFTB || pressed_key_value() == RIGHTB){
		if (debug){
			iprintf("\x1b[10;00H  Interrupcion: <B>             ");
			iprintf("\x1b[11;00H                                ");
		}
		
		if (state == MENU)
			switch (code){
				case 6:
					code++;
				break;
			}		
			
		if ((state != MENU) && (state != PAUSE) && (state != GAMEOVER) && (state != EE))
			state = SHOOT;		
		
	} else if (pressed_key_value() == START) {
		if (debug){
			iprintf("\x1b[10;00H  Interrupcion: <START>         ");
			iprintf("\x1b[11;00H                                ");
		}
		
		if ((state != MENU) && (state != PAUSE) && (state != GAMEOVER) && (state != EE)){
			state = PAUSE;
			ctanim = 95;
			
		} else if (state == PAUSE) 
			state = RESUME;
			
		else if (state == GAMEOVER)
			state = PREINIT;
		
		else if (state == MENU) {
			if (!debug) {
				iprintf("\x1b[21;00H  DEBUG MODE: ON             ");
				debug = true;
			} else {
				iprintf("\x1b[21;00H  DEBUG MODE: OFF            ");
				debug = false;
				clearText(DEBUG);	
			}
			
			switch (code){
				case 9:
					debug = false;
					state = EE;
					kirboText();
					code = 0;
					ctanim = 155;
				break;
			}			
		}
		
	} else if (pressed_key_value() == SELECT) {
		if (debug){
			iprintf("\x1b[10;00H  Interrupcion: <SELECT>        ");
			iprintf("\x1b[11;00H                                ");
		}
		
		if (state == GAMEOVER){
			state = MENU;
			ctanim = 0;
			clearText(ALL);
		}
		
		if (state == MENU)
			switch (code){
				case 8:
					code++;
				break;
			}		
	}
} // keypad_handler()


// CLEAR TEXT FROM UPPER SCREEN
void clearText(type){
	if (type == DEBUG){
		iprintf("\x1b[10;00H                                ");
		iprintf("\x1b[11;00H                                ");
		iprintf("\x1b[12;00H                                ");
		iprintf("\x1b[14;00H                                ");

	} else if (type == ALL){
		iprintf("\x1b[10;00H                                ");
		iprintf("\x1b[11;00H                                ");
		iprintf("\x1b[12;00H                                ");
		iprintf("\x1b[13;00H                                ");
		iprintf("\x1b[14;00H                                ");
		iprintf("\x1b[15;00H                                ");
		iprintf("\x1b[16;00H                                ");
		iprintf("\x1b[17;00H                                ");
		iprintf("\x1b[18;00H                                ");
		iprintf("\x1b[19;00H                                ");
		iprintf("\x1b[20;00H                                ");
		iprintf("\x1b[21;00H                                ");
		iprintf("\x1b[22;00H                                ");
	}
}


// KIRBO
void kirboText(){
	clearText(ALL);
	iprintf("\x1b[00;00H                               ");
	iprintf("\x1b[01;00H                               ");
	iprintf("\x1b[02;00H                               ");
	iprintf("\x1b[03;00H                               ");
	iprintf("\x1b[04;00H                               ");
	iprintf("\x1b[05;00H                               ");
	iprintf("\x1b[06;00H             POYO.             ");
	iprintf("\x1b[07;00H                               ");
	iprintf("\x1b[08;00H                               ");
	iprintf("\x1b[09;00H                               ");
}	