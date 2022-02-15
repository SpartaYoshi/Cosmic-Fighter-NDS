/**********************************************************
 * timers.c
 **********************************************************/

/* 
 * Añadir los includes que sean necesarios
 **/
#include <nds.h>
#include <stdio.h>
#include "defines.h"
#include "sprites.h"


int ticks = 0;
int seconds = 0;
extern int countdown = 120;
bool menuinst = false;
bool using = false;			// if a laser is being used from the array

int it = 0;					// alien iteration
int itls = 0;				// laser spawn iteration
int irls = 0; 				// enemy laser spawn iteration
int movls = 0;				// laser movement iteration
int ir = 0; 				// random iteration
int iexp = 0; 				// explosion spawn iteration
int ctexp = 0;				// explosion count for for's
//int ctls = 0;				// cooldown time for laser





/* 
 * Rutina de atención a la interrupción del temporizador
 **/
void timer_handler() {
	
	if (state != PAUSE){
		ticks++;

		if (ticks == FREQ){
			seconds++;
			ticks = 0;
			
			if (!menuinst && state == MENU){
				menuinst = true;
				iprintf("\x1b[19;00H   < TAP THE SCREEN TO PLAY >   ");
			} else if (menuinst && state == MENU){
				menuinst = false;
				iprintf("\x1b[19;00H                                ");
			} else if (!menuinst && state == GAMEOVER){
				menuinst = true;
				iprintf("\x1b[16;00H   < PRESS START TO RESTART >   ");
				iprintf("\x1b[17;00H                                ");
				iprintf("\x1b[18;00H    < PRESS SELECT TO EXIT >    ");
				iprintf("\x1b[19;00H                                ");

			} else if (menuinst && state == GAMEOVER){
				menuinst = false;
				iprintf("\x1b[16;00H                                ");
				if (reason == GAMEINT)
					iprintf("\x1b[17;00H    < GAMEPLAY INTERRUPTED >    ");
				else if (reason == TIMEUP)
					iprintf("\x1b[17;00H         < TIME'S UP! >         ");
				else if (reason == INVASION)
					iprintf("\x1b[17;00H  < THE ALIENS HAVE INVADED! >  ");
				else if (reason == ENEMYSHOT)
					iprintf("\x1b[17;00H 	 	< YOU ARE DEAD >        ");
				iprintf("\x1b[18;00H                                ");
				iprintf("\x1b[19;00H                                ");


			}
		}
	} 

	
	switch(state){
		case PREINIT:
			countdown = 120;
			seconds = 0;
			ticks = 0;
			state = INIT;
			break;
			
		case SHOOT:
			countdown = 120 - seconds;
			itls = 0;
			using = false;
			
			// use available laser
			while (itls < 3 && !using){
				if (!laser[itls].active){
					laser[itls].active = true;
					laser[itls].x = cannon.x;
					laser[itls].y = cannon.y;
					using = true;
					display_projectile(itls + 100, laser[itls].x, laser[itls].y);
				} else 
					itls++;
			}
			
			state = IDLE;
		break;
			
			
			
			
		case PAUSE:
			break;
			
		default:
			if ((countdown != 0) && (state != MENU) && (state != PAUSE) && (state != GAMEOVER) && (state != EE))
				countdown = 120 - seconds;
			break;
	}
	
	if((state != MENU) && (state != PAUSE) && (state != GAMEOVER) && (state != EE)){
		
		// ALIEN MOVEMENT
		if (dead_aliens < 20) 
			alienClock(10);
		else if (dead_aliens < 40)
			alienClock(8);
		else if (dead_aliens < 60)
			alienClock(6);
		else if (dead_aliens < 100)
			alienClock(5);
		else if (dead_aliens < 145)
			alienClock(4);
		else if (dead_aliens < 200)
			alienClock(3);
		else if (dead_aliens < 275)
			alienClock(2);
		else
			alienClock(1);
	
		
		
		
		// SHOOTING
		for (movls = 0; movls < 3; movls++){
			if (laser[movls].active){
				laser[movls].y = laser[movls].y - 6;
				display_projectile(movls + 100, laser[movls].x, laser[movls].y);
				
				if (laser[movls].y <= 1) {
						laser[movls].active = false;
						remove_projectile(movls + 100, laser[movls].x, laser[movls].y);
				}
			
				// COLLISION
				for (it = 0; it < TOTAL_ALIENS; it++){
					if ((laser[movls].x < (aliens[it].x + 8)) && (laser[movls].x > (aliens[it].x - 8)) && 
					(laser[movls].y < (aliens[it].y + 8)) && (laser[movls].y > (aliens[it].y - 8))){			// hit
						laser[movls].active = false;
						remove_projectile(movls + 100, laser[movls].x, laser[movls].y);
						explode(aliens[it].x, aliens[it].y);
						dead_aliens++;
						
						if (aliens[it].var == CRAB){
							remove_crab_alien(it, aliens[it].x, aliens[it].y);
							respawnAlien(it, CRAB);
							score = score + 10;
						} else if (aliens[it].var == OCTOPUS){
							remove_octopus_alien(it, aliens[it].x, aliens[it].y);
							respawnAlien(it, OCTOPUS);
							score = score + 5;
						} else if (aliens[it].var == SQUID){
							remove_squid_alien(it, aliens[it].x, aliens[it].y);
							respawnAlien(it, SQUID);
							score = score + 25;
						}
					}
				}
			}
		}
		
		
		
		// ALIEN RANDOMIZED LASER SPAWNING
		for (ir = 0; ir < TOTAL_ALIENS; ir++){
			irls = 0;
			if (rand() % 1000 == 133) {
				using = false;
				// use available laser
				while (irls < 10 && !using){
					if (!enemy_laser[irls].active){
						enemy_laser[irls].active = true;
						enemy_laser[irls].x = aliens[ir].x;
						enemy_laser[irls].y = aliens[ir].y;
						using = true;
						display_enemy_projectile(irls + 50, enemy_laser[irls].x, enemy_laser[irls].y);
					} else 
						irls++;
				}
			}
		}
		
		// ENEMY LASER MOVEMENT		
		for (movls = 0; movls < 10; movls++){
			if (enemy_laser[movls].active){
				enemy_laser[movls].y = enemy_laser[movls].y + 3;
				display_enemy_projectile(movls + 50, enemy_laser[movls].x, enemy_laser[movls].y);
				
				if (enemy_laser[movls].y >= 191) {
						enemy_laser[movls].active = false;
						remove_enemy_projectile(movls + 50, enemy_laser[movls].x, enemy_laser[movls].y);
				}
			
				// COLLISION
				if ((enemy_laser[movls].x < (cannon.x + 8)) && (enemy_laser[movls].x > (cannon.x - 8)) && 
				(enemy_laser[movls].y < (cannon.y + 8)) && (enemy_laser[movls].y > (cannon.y - 8))){			// hit
					enemy_laser[movls].active = false;
					remove_enemy_projectile(movls + 50, enemy_laser[movls].x, enemy_laser[movls].y);
					remove_laser_cannon(cannon.x, cannon.y);

					gameOver(ENEMYSHOT);
				}
			}
		}
		
		
		
		// EXPLOSION TRIGGERED TIME
		for (ctexp = 0; ctexp < 5; ctexp++){
			if (explosionsp[ctexp].time >= 0)
				explosionsp[ctexp].time++;
			
			if (explosionsp[ctexp].time >= 3){
				explosionsp[ctexp].time = -1;
				remove_explosion(ctexp + 110, explosionsp[ctexp].x, explosionsp[ctexp].y);
			}
		}
	}

	
	
} // timer_handler()



// ALIEN MOVEMENT
void moveAlien(index){
	if (aliens[index].right){
		if (aliens[index].x >= 239){
			aliens[index].right = false;
			aliens[index].y = aliens[index].y + 16;
		}
		else
			aliens[index].x = aliens[index].x + 8;
	}
	else {
		if (aliens[index].x <= 1){
			aliens[index].right = true;
			aliens[index].y = aliens[index].y + 16;
		}
		else 
			aliens[index].x = aliens[index].x - 8;
	}
} // void moveAlien(index)

void alienClock(tickrange) {
	if (ticks % tickrange == 0){
		for (it = 0; it < TOTAL_ALIENS; it++){
			moveAlien(it);
		
			if (aliens[it].var == CRAB)
				display_crab_alien(it, aliens[it].x, aliens[it].y);
			else if (aliens[it].var == SQUID)
				display_squid_alien(it, aliens[it].x, aliens[it].y);
			else if (aliens[it].var == OCTOPUS)
				display_octopus_alien(it, aliens[it].x, aliens[it].y);
		}
	}
}


// ALIEN RESPAWNING
void respawnAlien(index, var){
	aliens[index].var = var;
	aliens[index].right = rand() & 1;
	aliens[index].x = (rand() % 16) * 16;
	aliens[index].y = (rand() % 1) * 16;
	
	if (var == OCTOPUS){
		display_octopus_alien(index, aliens[index].x, aliens[index].y);
	} else if (var == CRAB){
		display_crab_alien(index, aliens[index].x, aliens[index].y);
	} else if (var == SQUID){
		display_squid_alien(index, aliens[index].x, aliens[index].y); 
	}
}



// DRAW EXPLOSION
void explode(x, y) {
	explosionsp[iexp].x = x;
	explosionsp[iexp].y = y;
	explosionsp[iexp].time = 0;
	display_explosion(iexp + 110, explosionsp[iexp].x, explosionsp[iexp].y);
	iexp++;
	if (iexp >= 5)
		iexp = 0;
}
	
	
	
	
	
	
/*
// LASER SHOOTING (OLD CODE)
void shoot(){
	display_projectile(126, laser.x, laser.y);
	while (laser.y > 0) {
		ctls++;
		if (ctls == 14500){
			laser.y--;
			display_projectile(126, laser.x, laser.y);
			ctls = 0;
		}
	}
	remove_projectile(126, laser.x, laser.y);

} // void shoot() */


