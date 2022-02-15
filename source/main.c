/********************************************************** 
 * main.c
 *
 * Este codigo se ha implementado basandose en el ejemplo 
 * "Simple sprite demo" de dovoto y otro de Jaeden Amero
 **********************************************************/

#include <nds.h>
#include <stdio.h>
#include <stdlib.h>	    // srand, rand,...
#include <unistd.h>
#include <time.h>       // time 

#include "backgrounds.h"
#include "controllers.h"
#include "defines.h"
#include "keypad_screen.h"
#include "sprites.h"
#include "timers.h"

/* 
 * Variables globales
 **/

int state;							// Game state
int countdown;						// Time left in-game


cannon_t cannon;							// Cannon sprite
alien_t aliens[TOTAL_ALIENS];				// Alien sprites (array)
laser_t laser[3];							// Projectiles (array)
laser_t enemy_laser[10];					// Enemy projectiles (array)
expl_t explosionsp[5];						// Explosion sprites (array)





bool invaded = false;						// Checks if player has been invaded yet

bool debug = false;							// Debug mode
int code = 0;

int finaltime = 0;							// Seconds spent (at gameover)

int i = 0;							// alien index
int var = CRAB;						// alien variant
int ctmvmt = 0;						// cooldown time for movement
int ctanim = 0;						// cooldown time for bg animation
int cnanim_ct = 0;					// cooldown time for cannon animation
int cnanim_fr = 0;					// cannon frames counter for animation
bool cnanim_dir = false;			// cannon animation direction (true = up)
int dead_aliens = 0;				// number of dead aliens
int frame01 = 1;					// bg01 frames (total = 12)
int frame02 = 1;					// bg02 frames (total = 12)
int frame03 = 1;					// bg03 frames (total = 8)
int framek = 1;						// kirbo ee frames (total = 9)
int score = 0;						// Game score
int reason = 0;						// Reason of gameover

touchPosition screen_pos;


/*
sprite_t kcl_alien[TOTAL_ALIENS];	// Bottom left pixel of alien sprite (used for collision)

sprite_t kcl_laser;				// Top left pixel of laser sprite (used for collision)
	
int pxalien = 0;						// alien collision pixels
int pxlaser = 0;						// laser collision pixels
*/




void bootupText(){	
    iprintf("\x1b[00;00H  +--------------------------+  ");
    iprintf("\x1b[01;00H  : KE-EC 20/21      EC302   :  ");
    iprintf("\x1b[02;00H  +--------------------------+  ");

    iprintf("\x1b[04;00H  +--------------------------+  ");
    iprintf("\x1b[05;00H  : Septien Molano, Asier    :  ");
    iprintf("\x1b[06;00H  :        -=-=-=-=-         :  ");
    iprintf("\x1b[07;00H  : Zhan Xiang, Hai Yong     :  ");
    iprintf("\x1b[08;00H  +--------------------------+  ");
}



/* 
 * main()
 **/
int main() {

    /* 
 	 * Poner en marcha el motor grafico 2D.
 	 **/
    powerOn(POWER_ALL_2D); // <nds.h>

    /* 
     * Establecer la pantalla inferior como principal, inicializar 
     * el sistema grafico y configurar el sistema de fondos. 
     **/
    lcdMainOnBottom(); // <nds.h>
    init_video();
    init_background();

    /* 
 	 * Inicializar memoria de sprites y guardar en ella los sprites.
 	 **/
    init_sprite_memory();
    alloc_sprites_in_memory();

    /* 
 	 * Establecer las paletas para los sprites.
 	 **/
    set_main_palette();
    set_secondary_palette();

    /* Inicializa la consola (superior) de texto. 
     * Nota.- Para borrar la pantalla existe la funcion consoleClear() 
     **/
    consoleDemoInit(); // <nds.h>

    /* 
     * Para inicializar el generador de numeros aleatorios en funcion de una semilla,
	 * en este caso time(NULL). srand() solo se suele activar una vez por ejecucion y
	 * no devuelve ningun valor. 
	 * La funcion para generar valores aleatorios en el resto del programa es rand() 
	 **/
    srand(time(NULL));	





	// BOOTUP
	bootupText();


	state = MENU;	
	interrupts_setting();
	


	
	
	// GAME
	
	while(1) {		
		switch(state){

			case MENU:																			// Menu screen
				clearScreen();
				
				// BACKGROUND 01 ANIMATION
				ctanim++; 
				if(ctanim == 100){
					bgAnim01();
					ctanim = 0;
				}
				
				// EE
				eeCheck();
				
				
				if (is_the_screen_touched())
					state = PREINIT;
				break;
				
				
			case PREINIT:																		// Preinit (Cronometro)
			
				iprintf("\x1b[16;00H                                "); // press blinking text (start to restart)
				iprintf("\x1b[17;00H                                "); // press blinking text (start to restart)
				iprintf("\x1b[18;00H                                "); // press blinking text (select to exit)
				iprintf("\x1b[19;00H                                "); // tap blinking text (menu)
				iprintf("\x1b[21;00H                                "); // debug mode text
				break;
				
			case INIT:																			// Initialization
				clearScreen();
				cannon.x = 128;										
				cannon.y = 165;	
				score = 0;
				dead_aliens = 0;
				ctmvmt = 0;
				display_back02_f01();
				display_laser_cannon(cannon.x, cannon.y);
				
				var = OCTOPUS;
				for (i = 0; i < 10; i++)
					initAlien(i, var);
			
				var = CRAB;
				for (i = 10; i < 30; i++)
					initAlien(i, var);
				
				var = SQUID;
				for (i = 30; i < 40; i++)
					initAlien(i, var);
				
				
				for (i = 0; i < 10; i++){
					enemy_laser[i].active = false;
					remove_enemy_projectile(i + 50, enemy_laser[i].x, enemy_laser[i].y);
				}
				
				/*for (row = 0; row < 4; row++){												// Spawneo modo matriz (test)
					for (i = 0; i < 10; i++){
						aliens[i+10*row].x = 10 + 20*i + rand()%4;
						aliens[i+10*row].y = 5 + 20*row + rand()%4;
						display_crab_alien(i+10*row, aliens[i+10*row].x, aliens[i+10*row].y);
					}
				}
				*/
				
				for(i = 0; i < 5; i++)
					explosionsp[i].time = -1;
				
				state = IDLE;
				break;
			
			case IDLE:																			// Reposo
				if (pressed_key_value() == A)
					gameOver(GAMEINT);
				else if (countdown == 0)
					gameOver(TIMEUP);
				else {
					i = 0;
					while (i < TOTAL_ALIENS && !invaded){
						if (aliens[i].y >= cannon.y)
							invaded = true;
						i++;
					}
					if (invaded)
						gameOver(INVASION);
				}
				
				break;
				
				
			case PAUSE:
				// BACKGROUND 03 ANIMATION
				clearScreen();
				ctanim++; 
				if(ctanim == 100){
					bgAnim03();
					ctanim = 0;
				}
				break;
				
			case RESUME:
				state = IDLE;
				resumeScreen();
				ctanim = 495;
				break;
				
				
			case GAMEOVER:
				iprintf("\x1b[20;00H  FINAL SCORE: %d           ", score);
				iprintf("\x1b[22;00H  PLAY TIME: %d SECONDS     ", finaltime);
				iprintf("\x1b[23;00H                            ");
				break;
				
			case EE:
				if (pressed_key_value() == A){
					bootupText();
					state = MENU;
					ctanim = 95;
				}
				
				// KIRBO ANIMATION
				ctanim++; 
				if(ctanim == 30000){
					bgAnimKirbo();
					ctanim = 0;
				}
				break;
				
			default:
			break;
		}
		






		// IN-GAME
		if( (state != MENU) && (state != PAUSE) && (state != GAMEOVER) && (state != EE) ){
			
			// INPUTS (DETECCION DE TECLADO POR ENCUESTA)
			moveLeft();
			moveRight();
			cannonAnimation();
			
			
			
			
			// BACKGROUND 02 ANIMATION
			ctanim++; 
				if(ctanim == 500){
					bgAnim02();
					ctanim = 0;
				}
				
				

			/*
			// COLLISION
			collided = false;
			pxalien = 0;
			pxlaser = 0;
			
			while (!collided && cntlaser < 5){
				kcl_laser[cntlaser].x = laser[cntlaser].x + 5;
				kcl_laser[cntlaser].y = laser[cntlaser].y + 3;
			
				while (!collided && i < TOTAL_ALIENS){
					if (aliens[i].var == CRAB){
						kcl_alien[i].x = aliens[i].x + 1;
						kcl_alien[i].y = aliens[i].y + 12;
					}
					
					
					while (!collided && pxalien < 13){
						while (!collided && pxlaser < 5){
							if ((kcl_laser[cntlaser].x + pxlaser) == (kcl_alien[i].x + pxalien)){
								collided = true;
								remove_projectile(cntlaser, laser[cntlaser].x, laser[cntlaser].y);
								if (aliens[i].var == CRAB){
									remove_crab_alien(i, aliens[i].x, aliens[i].y);
									score = score + 100;
									dead_aliens++;
									iprintf("\x1b[21;00H  BEEP BOOP                     ");
								}
							}
							pxlaser++;
						}
						pxalien++;
					}
					i++;
				}
				cntlaser++;
			}	
			*/
			
			
			
			
		}
		
		
		
		
		
		// DEBUG ONLY: KEYPAD, STATE, SCREEN
		if (debug){
			
			// ENTRADA DE TECLADO POR ENCUESTA
			switch(pressed_key_value()){													
				case A:			iprintf("\x1b[10;00H  Encuesta: <A>                 ");
								iprintf("\x1b[11;00H                                ");
				break;
				case LEFT: 		iprintf("\x1b[10;00H  Encuesta: <LEFT>              ");
								iprintf("\x1b[11;00H                                ");
				break;
				case RIGHT:		iprintf("\x1b[10;00H  Encuesta: <RIGHT>             ");
								iprintf("\x1b[11;00H                                ");
				break;
				case UP:		iprintf("\x1b[10;00H  Encuesta: <UP>                ");
								iprintf("\x1b[11;00H                                ");
				break;
				case DOWN:		iprintf("\x1b[10;00H  Encuesta: <DOWN>              ");
								iprintf("\x1b[11;00H                                ");
				break;
				case R:			iprintf("\x1b[10;00H  Encuesta: <R>                 ");
								iprintf("\x1b[11;00H                                ");
				break;
				case L:			iprintf("\x1b[10;00H  Encuesta: <L>                 ");
								iprintf("\x1b[11;00H                                ");
				break;
			} // switch(pressed_key_value())
			
			
			// STATE
			iprintf("\x1b[14;00H  STATE: %d                            ", state);
			
			
			// DETECCION DE PRESION EN PANTALLA
			touchRead(&screen_pos);   
			iprintf("\x1b[12;00H  Screen: x = %d, y = %d    ", screen_pos.px, screen_pos.py);
		}
		
		

		
		
		// PUNTUACION Y TIEMPO
		if ((state != MENU) && (state != GAMEOVER) && (state != EE) ){
			iprintf("\x1b[20;00H  SCORE: %d                 ", score);
			iprintf("\x1b[22;00H  TIME LEFT: %d             ", countdown);
			iprintf("\x1b[23;00H                            ");
		} else if (state == MENU){
			iprintf("\x1b[20;00H                            ");
			iprintf("\x1b[22;00H                            ");
			iprintf("\x1b[23;00H                            ");
		}




	

    } // while
} // main()




// CONTROLES

void moveLeft(){
	if (((pressed_key_value() == LEFT) || (pressed_key_value() == LEFTB)) && (cannon.x > 0)){
		ctmvmt++;
		if (debug){											// Igualar latencia de while
			if (ctmvmt == 5){
				cannon.x--;
				display_laser_cannon(cannon.x, cannon.y);
				ctmvmt = 0;
			}
		} else {
			if (ctmvmt == 15){
				cannon.x--;
				display_laser_cannon(cannon.x, cannon.y);
				ctmvmt = 0;
			}
		}
	}
} // void moveLeft()


void moveRight() {
	if (((pressed_key_value() == RIGHT) || (pressed_key_value() == RIGHTB)) && (cannon.x < 239)){
		ctmvmt++;
		if (debug){
			if (ctmvmt == 5){
				cannon.x++;
				display_laser_cannon(cannon.x, cannon.y);
				ctmvmt = 0;
			}
		} else {
			if (ctmvmt == 15){
				cannon.x++;
				display_laser_cannon(cannon.x, cannon.y);
				ctmvmt = 0;
			}
		}
	}
} // void moveRight()



// CANNON ANIMATION
void cannonAnimation() {
	cnanim_ct++;
	if (cnanim_ct == 300) {
		cnanim_ct = 0;
		cnanim_fr++;
		if (cnanim_dir)
			cannon.y--;
		else
			cannon.y++;
		
		display_laser_cannon(cannon.x, cannon.y);
	}
	
	if (cnanim_fr == 3){
		cnanim_ct = 0;
		cnanim_fr = 0;
		cnanim_dir = !cnanim_dir;
	}
}


	



// replantear codigo (while = timer_handler). añadir booleano al laser para ver si esta activo. hacer colisiones
// el shoot() inicializa la posicion del laser y activa un misil si hay uno disponible
// cambiar estado SHOOT. hacer colisiones en el TIMER tambien





// BACKGROUND 01 ANIMATION
void bgAnim01(){
	switch(frame01){
		case 1:
			display_back01_f01();
			frame01++;
			break;
		case 2:
			display_back01_f02();
			frame01++;
			break;
		case 3:
			display_back01_f03();
			frame01++;
			break;
		case 4:
			display_back01_f04();
			frame01++;
			break;
		case 5:
			display_back01_f05();
			frame01++;
			break;
		case 6:
			display_back01_f06();
			frame01++;
			break;
		case 7:
			display_back01_f07();
			frame01++;
			break;
		case 8:
			display_back01_f08();
			frame01++;
			break;
		case 9:
			display_back01_f09();
			frame01++;
			break;
		case 10:
			display_back01_f10();
			frame01++;
			break;
		case 11:
			display_back01_f11();
			frame01++;
			break;
		case 12:
			display_back01_f12();
			frame01 = 1;
			break;
		default:
			break;
	}
} // void bganim02()





// BACKGROUND 02 ANIMATION
void bgAnim02(){
	switch(frame02){
		case 1:
			display_back02_f01();
			frame02++;
			break;
		case 2:
			display_back02_f02();
			frame02++;
			break;
		case 3:
			display_back02_f03();
			frame02++;
			break;
		case 4:
			display_back02_f04();
			frame02++;
			break;
		case 5:
			display_back02_f05();
			frame02++;
			break;
		case 6:
			display_back02_f06();
			frame02++;
			break;
		case 7:
			display_back02_f07();
			frame02++;
			break;
		case 8:
			display_back02_f08();
			frame02++;
			break;
		case 9:
			display_back02_f09();
			frame02++;
			break;
		case 10:
			display_back02_f10();
			frame02++;
			break;
		case 11:
			display_back02_f11();
			frame02++;
			break;
		case 12:
			display_back02_f12();
			frame02 = 1;
			break;
		default:
			break;
	}
} // void bganim02()




// BACKGROUND 03 ANIMATION
void bgAnim03(){
	switch(frame03){
		case 1:
			display_back03_f01();
			frame03++;
			break;
		case 2:
			display_back03_f02();
			frame03++;
			break;
		case 3:
			display_back03_f03();
			frame03++;
			break;
		case 4:
			display_back03_f04();
			frame03++;
			break;
		case 5:
			display_back03_f05();
			frame03++;
			break;
		case 6:
			display_back03_f06();
			frame03++;
			break;
		case 7:
			display_back03_f07();
			frame03++;
			break;
		case 8:
			display_back03_f08();
			frame03 = 1;
			break;
		default:
			break;
	}
} // void bganim03()


// BACKGROUND EE ANIMATION
void bgAnimKirbo(){
	switch(framek){
		case 1:
			display_kirbo_f01();
			framek++;
			break;

		case 2:
			display_kirbo_f03();
			framek++;
			break;

		case 3:
			display_kirbo_f05();
			framek++;
			break;

		case 4:
			display_kirbo_f07();
			framek++;
			break;

		case 5:
			display_kirbo_f09();
			framek = 1;
			break;
		default:
			break;
	}
} // void bgAnimKirbo()





	
	
	
// ALIEN SPAWNING
void initAlien(index, var){
	aliens[index].var = var;
	aliens[index].right = rand() & 1;
	aliens[index].x = (rand() % 16) * 16;

	if (var == OCTOPUS){
		aliens[index].y = ((rand() % 1) + 5) * 16;
		display_octopus_alien(index, aliens[index].x, aliens[index].y);
	} else if (var == CRAB){
		aliens[index].y = ((rand() % 4) + 1) * 16;
		display_crab_alien(index, aliens[index].x, aliens[index].y);
	} else if (var == SQUID){
		aliens[index].y = (rand() % 1) * 16;
		display_squid_alien(index, aliens[index].x, aliens[index].y); 
	}
	
} // void initAlien(index)





// GAME OVER
void gameOver(endr){
	clearText(ALL);
	state = GAMEOVER;
	reason = endr;
	finaltime = 120 - countdown;
	invaded = false;
}








// CLEAR SCREEN FROM SPRITES
void clearScreen() {
	remove_laser_cannon(cannon.x, cannon.y);
	
	for (i = 0; i < TOTAL_ALIENS; i++){
		if (aliens[i].var == CRAB)
			remove_crab_alien(i, aliens[i].x, aliens[i].y);
		else if (aliens[i].var == OCTOPUS)
			remove_octopus_alien(i, aliens[i].x, aliens[i].y);
		else if (aliens[i].var == SQUID)
			remove_squid_alien(i, aliens[i].x, aliens[i].y);
	}
	
	for (i = 0; i < 3; i++)
		remove_projectile(i + 100, laser[i].x, laser[i].y);
	
	for (i = 0; i < 10; i++)
		remove_enemy_projectile(i + 50, enemy_laser[i].x, enemy_laser[i].y);
	
	for (i = 0; i < 5; i++)
		remove_explosion(i + 110, explosionsp[i].x, explosionsp[i].y);
}





// RESUME SPRITES ON SCREEN
void resumeScreen() {
	display_laser_cannon(cannon.x, cannon.y);
	
	for (i = 0; i < TOTAL_ALIENS; i++){
		if (aliens[i].var == CRAB)
			display_crab_alien(i, aliens[i].x, aliens[i].y);
		else if (aliens[i].var == OCTOPUS)
			display_octopus_alien(i, aliens[i].x, aliens[i].y);
		else if (aliens[i].var == SQUID)
			display_squid_alien(i, aliens[i].x, aliens[i].y);
	}
	
	for (i = 0; i < 3; i++)
		display_projectile(i + 100, laser[i].x, laser[i].y);
	
	for (i = 0; i < 10; i++)
		display_enemy_projectile(i + 50, enemy_laser[i].x, enemy_laser[i].y);
}



// EE CHECK
void eeCheck(){
	switch(code){
		case 0:
			if (pressed_key_value() == UP)
				code++;
			break;
			
		case 1:
			if (pressed_key_value() == UP || pressed_key_value() == -1)
				;
			else if (pressed_key_value() == DOWN)
				code++;
			else
				code = 0;
			break;
			
		case 2:
			if (pressed_key_value() == DOWN || pressed_key_value() == -1)
				;
			else if (pressed_key_value() == LEFT)
				code++;
			else
				code = 0;
			break;
			
		case 3:
			if (pressed_key_value() == LEFT || pressed_key_value() == -1)
				;
			else if (pressed_key_value() == RIGHT)
				code++;
			else
				code = 0;
			break;
			
		case 4:
			if (pressed_key_value() == RIGHT || pressed_key_value() == -1)
				;
			else if (pressed_key_value() == LEFT)
				code++;
			else
				code = 0;
			break;
			
		case 5:
			if (pressed_key_value() == LEFT || pressed_key_value() == -1)
				;
			else if (pressed_key_value() == RIGHT)
				code++;
			else
				code = 0;
			break;
			
		case 6:
			if (pressed_key_value() == -1 || pressed_key_value() == RIGHT)
				;
			else if (pressed_key_value() != B)
				code = 0;
			break;
			
		case 7:
			if (pressed_key_value() == -1 || pressed_key_value() == B)
				;
			else if (pressed_key_value() == A)
				code++;
			else
				code = 0;
			break;
			
		case 8:
			if (pressed_key_value() == -1 || pressed_key_value() == A)
				;
			else if (pressed_key_value() != SELECT)
				code = 0;
			break;
			
		case 9:
			if (pressed_key_value() == -1 || pressed_key_value() == SELECT)
				;
			else if (pressed_key_value() != START)
				code = 0;
			break;
			
		default:
			break;
	}
}