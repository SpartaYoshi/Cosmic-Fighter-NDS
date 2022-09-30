#ifndef _defines
#define _defines
/**********************************************************
 * defines.h
 **********************************************************/

#include <nds.h>
#include <stdio.h>

/* 
 * Aquí se definen los registros del gestor de interrupciones
 **/
#define IME		(*(vuint16*)0x04000208) //Interrupt Master Enable - Habilita o deshabilita todas las interrupciones
#define IE		(*(vuint32*)0x04000210) //Interrupt Enable - Activa o desactiva las interrupciones una a una
#define IF		(*(vuint32*)0x04000214) //Interrupt Flag - Guarda las peticiones de interrupcion

/* 
 * Aquí se definen algunas funciones para el tratamiento de las interrupciones
 **/
#define enable_ints() 	IME=1 //Habilita todas las interrupciones
#define disable_ints() 	IME=0 //Inhibe todas las interrupciones

/* 
 * Aquí se definen los registros del teclado
 **/
#define KEYS_DAT	(*(vuint16*)0x4000130) //Registro de datos del teclado
#define KEYS_CNT	(*(vuint16*)0x4000132) //Registro de control del teclado

/* 
 * Aquí se definen los registros del temporizador
 **/
#define TIMER0_CNT  (*(vuint16*)0x04000102) //Registro de control del temporizador
    /* 
     * El temporizador se activa poniendo un 1 en el bit 7.
     * El temporizador interrumpirá al desbordarse el contador, si hay un 1 en el bit 6.
     * Los dos bits de menos peso indican lo siguiente:
     *		00 frecuencia 33554432 hz 
     *		01 frecuencia 33554432/64 hz
     *		10 frecuencia 33554432/256 hz
     *		11 frecuencia 33554432/1024 hz
     **/
#define TIMER0_DAT  (*(vuint16*)0x04000100) //Registro de datos del temporizador
    /* 
     * Se utiliza para indicar a partir de qué valor tiene que empezar a contar
     **/


// CONTROLS
#define A		0 
#define B		1
#define SELECT	2 
#define START	3
#define RIGHT	4 
#define LEFT	5
#define UP		6 
#define DOWN	7
#define R		8 
#define L		9
#define LEFTB	30
#define RIGHTB	31


// GLOBAL VARIABLES
extern bool debug;

extern int state;
extern int ctanim;
extern int reason;
extern int dead_aliens;
extern int score;
extern int code;

	
// STATES
#define MENU		0
#define PREINIT		1
#define INIT		2
#define IDLE		3
#define SHOOT 	 	4
#define PAUSE 		5
#define RESUME		6
#define GAMEOVER 	7
#define EE			8


// GENERAL SPRITE TYPE
typedef struct {		
	int x;
	int y;
} cannon_t;


// LASER SPRITE TYPE
typedef struct {		
	int x;
	int y;
	bool active;
} laser_t;


// ALIEN SPRITE TYPE
typedef struct {
	int x;
	int y;
	int var;
	bool right;
} alien_t;

// EXPLOSION SPRITE TYPE
typedef struct {		
	int x;
	int y;
	int time;
} expl_t;


// Constants
#define FREQ 			20
#define TOTAL_ALIENS 	40


// Alien variants
#define CRAB 		0
#define SQUID		1
#define OCTOPUS		2


// clearText() types
#define DEBUG		0
#define ALL			1


// Gameover reasons
#define GAMEINT		0
#define TIMEUP		1
#define INVASION	2
#define ENEMYSHOT   3


extern cannon_t cannon;								// Cannon sprite
extern alien_t aliens[TOTAL_ALIENS];				// Alien sprites (array)
extern laser_t laser[3];							// Projectiles (array)
extern laser_t enemy_laser[10];						// Enemy projectiles (array)
extern expl_t explosionsp[5];				      		// Explosion sprites (array)


#endif