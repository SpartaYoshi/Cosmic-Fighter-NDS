/********************************************************** 
 * sprites.c
 *
 * Este codigo se ha implementado basandose en el ejemplo
 * "Simple sprite demo" de dovoto y otro de Jaeden Amero 
 **********************************************************/

#include <nds.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "sprites.h"
#include "defines.h"

u16* gfx_laser_cannon;
u16* gfx_crab_alien;
u16* gfx_octopus_alien;
u16* gfx_squid_alien;
u16* gfx_projectile;
u16* gfx_enemy_projectile;
u16* gfx_explosion;

/* 
 * Dibujado de un sprite de 16x16 pixels 
 * Debido al funcionamiento de los bancos de memoria, las primeras cuatro filas 
 * forman el cuadrante superior izquiero, las siguientes, el cuadrante superior 
 * derecho, las siguientes el cuadrante inferior izquierdo y las últimas cuatro
 * filas, el cuadrante inferior derecho, como se muestra al lado.
 */

u8 laser_cannon[256] = {
0	,	0	,	0	,	0	,	0	,	0	,	0	,	6	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	6	,	 //	0	0	0	0	0	0	0	6	0	0	0	0	0	0	0	0
0	,	0	,	0	,	0	,	0	,	0	,	6	,	23	,	0	,	0	,	0	,	0	,	0	,	0	,	6	,	23	,	 //	0	0	0	0	0	0	0	6	0	0	0	0	0	0	0	0
0	,	0	,	0	,	0	,	0	,	6	,	23	,	23	,	0	,	0	,	0	,	0	,	0	,	6	,	23	,	23	,	 //	0	0	0	0	0	0	6	23	6	0	0	0	0	0	0	0
0	,	0	,	0	,	0	,	6	,	4	,	4	,	23	,	0	,	0	,	0	,	0	,	6	,	4	,	4	,	23	,	 //	0	0	0	0	0	0	6	23	6	0	0	0	0	0	0	0
0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	 //	0	0	0	0	0	6	23	23	23	6	0	0	0	0	0	0
6	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	6	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	 //	0	0	0	0	0	6	23	23	23	6	0	0	0	0	0	0
23	,	6	,	0	,	0	,	0	,	0	,	0	,	0	,	23	,	6	,	0	,	0	,	0	,	0	,	0	,	0	,	 //	0	0	0	0	6	4	4	23	4	4	6	0	0	0	0	0
4	,	4	,	6	,	0	,	0	,	0	,	0	,	0	,	4	,	4	,	6	,	0	,	0	,	0	,	0	,	0	,	 //	0	0	0	0	6	4	4	23	4	4	6	0	0	0	0	0
0	,	0	,	0	,	6	,	4	,	4	,	4	,	4	,	0	,	0	,	0	,	6	,	4	,	4	,	4	,	4	,	 //	0	0	0	6	4	4	4	4	4	4	4	6	0	0	0	0
0	,	0	,	6	,	21	,	4	,	4	,	4	,	4	,	0	,	0	,	6	,	21	,	4	,	4	,	21	,	21	,	 //	0	0	0	6	4	4	4	4	4	4	4	6	0	0	0	0
0	,	6	,	21	,	4	,	21	,	21	,	6	,	6	,	0	,	6	,	21	,	21	,	9	,	9	,	0	,	0	,	 //	0	0	6	21	4	4	4	4	4	4	4	21	6	0	0	0
6	,	21	,	6	,	6	,	12	,	12	,	0	,	0	,	6	,	6	,	0	,	0	,	12	,	12	,	0	,	0	,	 //	0	0	6	21	4	4	21	21	21	4	4	21	6	0	0	0
4	,	4	,	4	,	6	,	0	,	0	,	0	,	0	,	4	,	4	,	4	,	6	,	0	,	0	,	0	,	0	,	 //	0	6	21	4	21	21	6	6	6	21	21	4	21	6	0	0
4	,	4	,	4	,	21	,	6	,	0	,	0	,	0	,	21	,	4	,	4	,	21	,	6	,	0	,	0	,	0	,	 //	0	6	21	21	9	9	0	0	0	9	9	21	21	6	0	0
6	,	21	,	21	,	4	,	21	,	6	,	0	,	0	,	0	,	9	,	9	,	21	,	21	,	6	,	0	,	0	,	 //	6	21	6	6	12	12	0	0	0	12	12	6	6	21	6	0
0	,	12	,	12	,	6	,	6	,	21	,	6	,	0	,	0	,	12	,	12	,	0	,	0	,	6	,	6	,	0	,	 //	6	6	0	0	12	12	0	0	0	12	12	0	0	6	6	0

};

u8 crab_alien[256] = {
0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	 //	0	0	0	0	0	0	0	0	0	0	0	0	0	0	0	0
0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	 //	0	0	0	0	0	0	0	0	0	0	0	0	0	0	0	0
0	,	0	,	0	,	6	,	6	,	0	,	0	,	0	,	0	,	0	,	6	,	21	,	21	,	6	,	0	,	6	,	 //	0	0	0	0	0	0	0	0	0	0	0	0	0	0	0	0
0	,	6	,	21	,	0	,	6	,	21	,	21	,	21	,	0	,	0	,	0	,	6	,	21	,	4	,	4	,	4	,	 //	0	0	0	0	0	0	0	0	0	0	0	0	0	0	0	0
0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	 //	0	0	0	6	6	0	0	0	0	0	6	6	0	0	0	0
0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	 //	0	0	6	21	21	6	0	6	0	6	21	21	6	0	0	0
0	,	0	,	6	,	6	,	0	,	0	,	0	,	0	,	0	,	6	,	21	,	21	,	6	,	0	,	0	,	0	,	 //	0	6	21	0	6	21	21	21	21	21	6	0	21	6	0	0
21	,	21	,	6	,	0	,	21	,	6	,	0	,	0	,	4	,	4	,	21	,	6	,	0	,	0	,	0	,	0	,	 //	0	0	0	6	21	4	4	4	4	4	21	6	0	0	0	0
0	,	0	,	6	,	4	,	4	,	6	,	4	,	4	,	0	,	6	,	21	,	23	,	4	,	4	,	4	,	4	,	 //	0	0	6	4	4	6	4	4	4	6	4	4	6	0	0	0
0	,	0	,	6	,	21	,	23	,	0	,	23	,	23	,	0	,	0	,	6	,	21	,	21	,	0	,	0	,	0	,	 //	0	6	21	23	4	4	4	4	4	4	4	23	21	6	0	0
0	,	0	,	0	,	6	,	6	,	6	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	 //	0	0	6	21	23	0	23	23	23	0	23	21	6	0	0	0
0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	 //	0	0	6	21	21	0	0	0	0	0	21	21	6	0	0	0
4	,	6	,	4	,	4	,	6	,	0	,	0	,	0	,	4	,	4	,	4	,	23	,	21	,	6	,	0	,	0	,	 //	0	0	0	6	6	6	0	0	0	6	6	6	0	0	0	0
23	,	0	,	23	,	21	,	6	,	0	,	0	,	0	,	0	,	0	,	21	,	21	,	6	,	0	,	0	,	0	,	 //	0	0	0	0	0	0	0	0	0	0	0	0	0	0	0	0
0	,	6	,	6	,	6	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	 //	0	0	0	0	0	0	0	0	0	0	0	0	0	0	0	0
0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	 //	0	0	0	0	0	0	0	0	0	0	0	0	0	0	0	0
};

u8 squid_alien[256] = {
0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	 //	0	0	0	0	0	0	0	0	0	0	0	0	0	0	0	0
0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	6	,	 //	0	0	0	0	0	0	0	0	0	0	0	0	0	0	0	0
0	,	0	,	0	,	0	,	0	,	0	,	6	,	19	,	0	,	0	,	0	,	0	,	0	,	6	,	19	,	5	,	 //	0	0	0	0	0	0	0	0	0	0	0	0	0	0	0	0
0	,	0	,	0	,	0	,	6	,	6	,	5	,	5	,	0	,	0	,	0	,	6	,	19	,	5	,	3	,	5	,	 //	0	0	0	0	0	0	0	6	6	0	0	0	0	0	0	0
0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	 //	0	0	0	0	0	0	6	19	19	6	0	0	0	0	0	0
0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	6	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	 //	0	0	0	0	0	6	19	5	5	19	6	0	0	0	0	0
19	,	6	,	0	,	0	,	0	,	0	,	0	,	0	,	5	,	19	,	6	,	0	,	0	,	0	,	0	,	0	,	 //	0	0	0	0	6	6	5	5	5	5	6	6	0	0	0	0
5	,	5	,	6	,	6	,	0	,	0	,	0	,	0	,	5	,	3	,	5	,	19	,	6	,	0	,	0	,	0	,	 //	0	0	0	6	19	5	3	5	5	3	5	19	6	0	0	0
0	,	0	,	6	,	6	,	19	,	6	,	19	,	19	,	0	,	0	,	0	,	0	,	0	,	15	,	0	,	15	,	 //	0	0	6	6	19	6	19	19	19	19	6	19	6	6	0	0
0	,	0	,	0	,	0	,	15	,	0	,	15	,	0	,	0	,	0	,	15	,	15	,	0	,	15	,	0	,	0	,	 //	0	0	0	0	0	15	0	15	15	0	15	0	0	0	0	0
0	,	0	,	0	,	0	,	15	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	 //	0	0	0	0	15	0	15	0	0	15	0	15	0	0	0	0
0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	 //	0	0	15	15	0	15	0	0	0	0	15	0	15	15	0	0
19	,	19	,	6	,	19	,	6	,	6	,	0	,	0	,	15	,	0	,	15	,	0	,	0	,	0	,	0	,	0	,	 //	0	0	0	0	15	0	0	0	0	0	0	15	0	0	0	0
0	,	15	,	0	,	15	,	0	,	0	,	0	,	0	,	0	,	0	,	15	,	0	,	15	,	15	,	0	,	0	,	 //	0	0	0	0	0	0	0	0	0	0	0	0	0	0	0	0
0	,	0	,	0	,	15	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	 //	0	0	0	0	0	0	0	0	0	0	0	0	0	0	0	0
0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	 //	0	0	0	0	0	0	0	0	0	0	0	0	0	0	0	0

};

u8 octopus_alien[256] = {
0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	 //	0	0	0	0	0	0	0	0	0	0	0	0	0	0	0	0
0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	6	,	6	,	 //	0	0	0	0	0	0	0	0	0	0	0	0	0	0	0	0
0	,	0	,	0	,	0	,	6	,	6	,	2	,	2	,	0	,	0	,	0	,	6	,	2	,	2	,	2	,	2	,	 //	0	0	0	0	0	0	0	0	0	0	0	0	0	0	0	0
0	,	0	,	6	,	2	,	2	,	24	,	24	,	2	,	0	,	6	,	22	,	2	,	24	,	3	,	3	,	24	,	 //	0	0	0	0	0	0	6	6	6	6	0	0	0	0	0	0
0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	 //	0	0	0	0	6	6	2	2	2	2	6	6	0	0	0	0
0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	6	,	6	,	0	,	0	,	0	,	0	,	0	,	0	,	 //	0	0	0	6	2	2	2	2	2	2	2	2	6	0	0	0
2	,	2	,	6	,	6	,	0	,	0	,	0	,	0	,	2	,	2	,	2	,	2	,	6	,	0	,	0	,	0	,	 //	0	0	6	2	2	24	24	2	2	24	24	2	2	6	0	0
2	,	24	,	24	,	2	,	2	,	6	,	0	,	0	,	24	,	3	,	3	,	24	,	2	,	22	,	6	,	0	,	 //	0	6	22	2	24	3	3	24	24	3	3	24	2	22	6	0
0	,	0	,	6	,	22	,	2	,	24	,	2	,	2	,	0	,	0	,	0	,	6	,	22	,	2	,	22	,	22	,	 //	0	0	6	22	2	24	2	2	2	2	24	2	22	6	0	0
0	,	0	,	6	,	22	,	22	,	6	,	11	,	22	,	0	,	6	,	22	,	6	,	6	,	10	,	6	,	11	,	 //	0	0	0	6	22	2	22	22	22	22	2	22	6	0	0	0
0	,	6	,	6	,	22	,	0	,	0	,	0	,	6	,	0	,	6	,	0	,	6	,	22	,	0	,	0	,	0	,	 //	0	0	6	22	22	6	11	22	22	11	6	22	22	6	0	0
0	,	0	,	0	,	0	,	6	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	 //	0	6	22	6	6	10	6	11	11	6	10	6	6	22	6	0
2	,	2	,	24	,	2	,	22	,	6	,	0	,	0	,	22	,	22	,	2	,	22	,	6	,	0	,	0	,	0	,	 //	0	6	6	22	0	0	0	6	6	0	0	0	22	6	6	0
22	,	11	,	6	,	22	,	22	,	6	,	0	,	0	,	11	,	6	,	10	,	6	,	6	,	22	,	6	,	0	,	 //	0	6	0	6	22	0	0	0	0	0	0	22	6	0	6	0
6	,	0	,	0	,	0	,	22	,	6	,	6	,	0	,	0	,	0	,	0	,	22	,	6	,	0	,	6	,	0	,	 //	0	0	0	0	6	0	0	0	0	0	0	6	0	0	0	0
0	,	0	,	0	,	6	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	 //	0	0	0	0	0	0	0	0	0	0	0	0	0	0	0	0

};

u8 projectile[256] = {
0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	 //	0	0	0	0	0	0	0	0	0	0	0	0	0	0	0	0
0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	7	,	 //	0	0	0	0	0	0	0	0	0	0	0	0	0	0	0	0
0	,	0	,	0	,	0	,	0	,	0	,	5	,	7	,	0	,	0	,	0	,	0	,	0	,	5	,	7	,	7	,	 //	0	0	0	0	0	0	0	0	0	0	0	0	0	0	0	0
0	,	0	,	0	,	0	,	0	,	0	,	5	,	7	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	7	,	 //	0	0	0	0	0	0	0	7	0	0	0	0	0	0	0	0
0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	 //	0	0	0	0	0	0	5	7	7	0	0	0	0	0	0	0
0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	 //	0	0	0	0	0	5	7	7	0	0	0	0	0	0	0	0
7	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	 //	0	0	0	0	0	0	5	7	5	0	0	0	0	0	0	0
5	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	7	,	5	,	0	,	0	,	0	,	0	,	0	,	0	,	 //	0	0	0	0	0	0	0	7	7	5	0	0	0	0	0	0
0	,	0	,	0	,	0	,	0	,	0	,	5	,	7	,	0	,	0	,	0	,	0	,	0	,	5	,	7	,	7	,	 //	0	0	0	0	0	0	5	7	5	0	0	0	0	0	0	0
0	,	0	,	0	,	0	,	0	,	0	,	5	,	7	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	7	,	 //	0	0	0	0	0	5	7	7	0	0	0	0	0	0	0	0
0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	 //	0	0	0	0	0	0	5	7	7	0	0	0	0	0	0	0
0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	 //	0	0	0	0	0	0	0	7	0	0	0	0	0	0	0	0
5	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	 //	0	0	0	0	0	0	0	0	0	0	0	0	0	0	0	0
7	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	 //	0	0	0	0	0	0	0	0	0	0	0	0	0	0	0	0
0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	 //	0	0	0	0	0	0	0	0	0	0	0	0	0	0	0	0
0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	 //	0	0	0	0	0	0	0	0	0	0	0	0	0	0	0	0

};

u8 enemy_projectile[256] = {
0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	 //	0	0	0	0	0	0	0	0	0	0	0	0	0	0	0	0
0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	12	,	 //	0	0	0	0	0	0	0	0	0	0	0	0	0	0	0	0
0	,	0	,	0	,	0	,	0	,	0	,	1	,	12	,	0	,	0	,	0	,	0	,	0	,	1	,	12	,	12	,	 //	0	0	0	0	0	0	0	0	0	0	0	0	0	0	0	0
0	,	0	,	0	,	0	,	0	,	0	,	1	,	12	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	12	,	 //	0	0	0	0	0	0	0	12	0	0	0	0	0	0	0	0
0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	 //	0	0	0	0	0	0	1	12	12	0	0	0	0	0	0	0
0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	 //	0	0	0	0	0	1	12	12	0	0	0	0	0	0	0	0
12	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	 //	0	0	0	0	0	0	1	12	1	0	0	0	0	0	0	0
1	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	12	,	1	,	0	,	0	,	0	,	0	,	0	,	0	,	 //	0	0	0	0	0	0	0	12	12	1	0	0	0	0	0	0
0	,	0	,	0	,	0	,	0	,	0	,	1	,	12	,	0	,	0	,	0	,	0	,	0	,	1	,	12	,	12	,	 //	0	0	0	0	0	0	1	12	1	0	0	0	0	0	0	0
0	,	0	,	0	,	0	,	0	,	0	,	1	,	12	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	12	,	 //	0	0	0	0	0	1	12	12	0	0	0	0	0	0	0	0
0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	 //	0	0	0	0	0	0	1	12	12	0	0	0	0	0	0	0
0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	 //	0	0	0	0	0	0	0	12	0	0	0	0	0	0	0	0
1	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	 //	0	0	0	0	0	0	0	0	0	0	0	0	0	0	0	0
12	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	 //	0	0	0	0	0	0	0	0	0	0	0	0	0	0	0	0
0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	 //	0	0	0	0	0	0	0	0	0	0	0	0	0	0	0	0
0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	 //	0	0	0	0	0	0	0	0	0	0	0	0	0	0	0	0

};

u8 explosion[256] = {
0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	1	,	0	,	0	,	12	,	1	,	 //	0	0	0	0	0	0	0	0	0	0	0	0	0	0	0	0
0	,	0	,	1	,	0	,	0	,	1	,	2	,	12	,	0	,	1	,	12	,	0	,	1	,	12	,	2	,	2	,	 //	0	0	0	1	0	0	12	1	1	0	0	1	1	0	0	0
0	,	12	,	0	,	1	,	12	,	2	,	2	,	3	,	0	,	0	,	1	,	12	,	2	,	2	,	3	,	3	,	 //	0	0	1	0	0	1	2	12	1	1	1	0	12	1	0	0
0	,	0	,	1	,	12	,	3	,	3	,	3	,	2	,	0	,	1	,	12	,	3	,	2	,	3	,	2	,	2	,	 //	0	1	12	0	1	12	2	2	12	12	1	1	0	12	0	0
0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	1	,	0	,	0	,	1	,	1	,	0	,	0	,	0	,	 //	0	12	0	1	12	2	2	3	3	2	12	12	1	0	1	0
1	,	1	,	1	,	0	,	12	,	1	,	0	,	0	,	12	,	12	,	1	,	1	,	0	,	12	,	0	,	0	,	 //	0	0	1	12	2	2	3	3	3	3	2	12	1	0	0	0
3	,	2	,	12	,	12	,	1	,	0	,	1	,	0	,	3	,	3	,	2	,	12	,	1	,	0	,	0	,	0	,	 //	0	0	1	12	3	3	3	2	2	2	3	2	12	1	0	0
2	,	2	,	3	,	2	,	12	,	1	,	0	,	0	,	3	,	3	,	2	,	2	,	12	,	1	,	0	,	0	,	 //	0	1	12	3	2	3	2	2	3	3	2	2	12	1	0	0
0	,	12	,	12	,	2	,	2	,	3	,	3	,	3	,	0	,	1	,	12	,	12	,	2	,	2	,	3	,	3	,	 //	0	12	12	2	2	3	3	3	3	2	2	3	12	12	1	0
0	,	0	,	1	,	2	,	12	,	3	,	3	,	2	,	0	,	0	,	1	,	1	,	12	,	2	,	2	,	2	,	 //	0	1	12	12	2	2	3	3	2	3	3	2	12	12	1	0
0	,	1	,	0	,	1	,	12	,	12	,	2	,	12	,	0	,	0	,	1	,	0	,	1	,	1	,	1	,	1	,	 //	0	0	1	2	12	3	3	2	3	1	12	2	2	1	0	0
0	,	0	,	0	,	12	,	0	,	0	,	1	,	12	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	 //	0	0	1	1	12	2	2	2	12	1	2	12	12	1	0	0
3	,	2	,	2	,	3	,	12	,	12	,	1	,	0	,	2	,	3	,	3	,	2	,	12	,	12	,	1	,	0	,	 //	0	1	0	1	12	12	2	12	1	12	12	12	1	0	1	0
3	,	1	,	12	,	2	,	2	,	1	,	0	,	0	,	12	,	1	,	2	,	12	,	12	,	1	,	0	,	0	,	 //	0	0	1	0	1	1	1	1	12	12	1	1	0	1	0	0
1	,	12	,	12	,	12	,	1	,	0	,	1	,	0	,	12	,	12	,	1	,	1	,	0	,	1	,	0	,	0	,	 //	0	0	0	12	0	0	1	12	1	1	0	0	12	0	0	0
1	,	1	,	0	,	0	,	12	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	 //	0	0	0	0	0	0	0	0	0	0	0	0	0	0	0	0


};

/* 
 * Inicializar la memoria de sprites. 
 **/
void init_sprite_memory() {
	oamInit(&oamMain, SpriteMapping_1D_32, false);
	oamInit(&oamSub, SpriteMapping_1D_32, false);

	gfx_laser_cannon  = oamAllocateGfx(&oamMain, SpriteSize_16x16, SpriteColorFormat_256Color);
	gfx_crab_alien    = oamAllocateGfx(&oamMain, SpriteSize_16x16, SpriteColorFormat_256Color);
	gfx_squid_alien   = oamAllocateGfx(&oamMain, SpriteSize_16x16, SpriteColorFormat_256Color);
	gfx_octopus_alien = oamAllocateGfx(&oamMain, SpriteSize_16x16, SpriteColorFormat_256Color);
	gfx_projectile    = oamAllocateGfx(&oamMain, SpriteSize_16x16, SpriteColorFormat_256Color);
	gfx_enemy_projectile = oamAllocateGfx(&oamMain, SpriteSize_16x16, SpriteColorFormat_256Color);
	gfx_explosion = oamAllocateGfx(&oamMain, SpriteSize_16x16, SpriteColorFormat_256Color);

} // init_sprite_memory()


/* 
 * Dentro de esta función hay que definir el color con el que se mostrará cada uno de los 256 
 * colores posibles en la pantalla principal. El 0 es transparente y los no definidos son negros.
 */

void set_main_palette() {
                                         // 0: TRANSPARENTE
   SPRITE_PALETTE[1]  = RGB15(31,0,0);   // ROJO:           RGB24={FF,00,00}
   SPRITE_PALETTE[2]  = RGB15(31,31,0);  // AMARILLO:       RGB24={FF,FF,00}
   SPRITE_PALETTE[3]  = RGB15(31,31,31); // BLANCO:         RGB24={FF,FF,FF}
   SPRITE_PALETTE[4]  = RGB15(0,31,0);   // VERDE:          RGB24={00,FF,00}
   SPRITE_PALETTE[5]  = RGB15(0,0,31);   // AZUL:           RGB24={00,00,FF}
   SPRITE_PALETTE[6]  = RGB15(0,0,0);    // NEGRO:          RGB24={00,00,00}
   SPRITE_PALETTE[7]  = RGB15(0,31,31);  // CYAN:           RGB24={00,FF,FF}
   SPRITE_PALETTE[8]  = RGB15(31,0,31);  // MAGENTA:        RGB24={FF,00,FF}
   SPRITE_PALETTE[9]  = RGB15(16,16,16); // GRIS:           RGB24={80,80,80}
   SPRITE_PALETTE[10] = RGB15(25,25,25); // GRIS CLARO:     RGB24={D0,D0,D0}
   SPRITE_PALETTE[11] = RGB15(8,8,8);    // GRIS OSCURO:    RGB24={40,40,40}
   SPRITE_PALETTE[12] = RGB15(31,19,0);  // NARANJA:        RGB24={FF,99,00}
   SPRITE_PALETTE[13] = RGB15(19,0,4);   // GRANATE:        RGB24={99,00,21}
   SPRITE_PALETTE[14] = RGB15(25,0,0);   // MARRON:         RGB24={66,00,00}
   SPRITE_PALETTE[15] = RGB15(16,0,16);  // MORADO:         RGB24={80,00,80}
   SPRITE_PALETTE[16] = RGB15(25,19,31); // LILA:           RGB24={CC,99,FF}
   SPRITE_PALETTE[17] = RGB15(31,19,25); // ROSA:           RGB24={FF,99,CC}
   SPRITE_PALETTE[18] = RGB15(23,21,21); // AZUL CLARO:     RGB24={BB,FF,FF}
   SPRITE_PALETTE[19] = RGB15(0,0,16);   // AZUL MARINO:    RGB24={00,00,80}
   SPRITE_PALETTE[20] = RGB15(0,16,16);  // VERDE AZULADO:  RGB24={00,80,80}
   SPRITE_PALETTE[21] = RGB15(0,12,0);   // VERDE OSCURO:   RGB24={00,66,00}
   SPRITE_PALETTE[22] = RGB15(16,16,0);  // VERDE OLIVA:    RGB24={80,80,00}
   SPRITE_PALETTE[23] = RGB15(19,31,19); // VERDE CLARO:    RGB24={99,FF,99}
   SPRITE_PALETTE[24] = RGB15(31,31,19); // AMARILLO CLARO: RGB24={FF,FF,99}
} // set_main_palette()

/* 
 * Dentro de esta función hay que definir el color con el que se mostrará cada uno de los 256 
 * colores posibles en la pantalla secundaria. El 0 es transparente y los no definidos son negros.
 */

void set_secondary_palette() {
   SPRITE_PALETTE_SUB[1] = RGB15(0,31,0);   // los pixels a 1 se mostrarán verdes
   SPRITE_PALETTE_SUB[2] = RGB15(31,31,31); // los pixels a 1 se mostrarán blancos
   SPRITE_PALETTE_SUB[3] = RGB15(31,31,0);  // los pixels a 1 se mostrarán amarillos
} // set_secondary_palette()


/* 
 *Para guardar los sprites en memoria y luego poder usarlos.
 **/
void alloc_sprites_in_memory() {
  int i;
  for(i = 0; i < 16 * 16 / 2; i++){ //muestra un cuadrado en la memoria de la pantalla principal		
     gfx_crab_alien[i] 	     = crab_alien[i*2]  	  | (crab_alien[(i*2)+1]<<8);
	 gfx_squid_alien[i]  	 = squid_alien[i*2] 	  | (squid_alien[(i*2)+1]<<8);
	 gfx_octopus_alien[i]    = octopus_alien[i*2] 	  | (octopus_alien[(i*2)+1]<<8);
     gfx_laser_cannon[i] 	 = laser_cannon[i*2] 	  | (laser_cannon[(i*2)+1]<<8);	
     gfx_projectile[i]  	 = projectile[i*2] 		  | (projectile[(i*2)+1]<<8);	
	 gfx_enemy_projectile[i] = enemy_projectile[i*2]  | (enemy_projectile[(i*2)+1]<<8);	
	 gfx_explosion[i] 		 = explosion[i*2]  		  | (explosion[(i*2)+1]<<8);	

  }
} // alloc_sprites_in_memory()



/* 
 * Funciones especificas para manejar los sprites. 
 **/

void display_laser_cannon(int x, int y) {
	oamSet(&oamMain, 	//main graphics engine context
		127,     		//oam index (0 to 127)  
		x, y,    		//x and y pixel location of the sprite
		0,       		//priority, lower renders last (on top)
		0,	 			//this is the palette index if multiple palettes or the alpha value if bmp sprite	
		SpriteSize_16x16,     
		SpriteColorFormat_256Color, 
		gfx_laser_cannon,	//+16*16/2,	//pointer to the loaded graphics
		-1,             //sprite rotation data  
		false,          //double the size when rotating?
		false,			//hide the sprite?
		false, false, 	//vflip, hflip
		false			//apply mosaic
	);   
	oamUpdate(&oamMain); 
} // display_laser_cannon()

void remove_laser_cannon(int x, int y) {
	oamSet(&oamMain, 	//main graphics engine context
		127,     		//oam index (0 to 127)
		x, y,    		//x and y pixel location of the sprite
		0,       		//priority, lower renders last (on top)
		0,	 			//this is the palette index if multiple palettes or the alpha value if bmp sprite
		SpriteSize_16x16,
		SpriteColorFormat_256Color,
		gfx_laser_cannon,	//+16*16/2,	//pointer to the loaded graphics
		-1,             //sprite rotation data
		false,          //double the size when rotating?
		true,			//hide the sprite?
		false, false, 	//vflip, hflip
		false			//apply mosaic
	);
	oamUpdate(&oamMain);
} // remove_laser_cannon()

void display_crab_alien(int index, int x, int y) { 
	oamSet(&oamMain, 	//main graphics engine context
		index,  		//oam index (0 to 127)  
		x, y,    		//x and y pixel location of the sprite
		0,       		//priority, lower renders last (on top)
		0,	 			//this is the palette index if multiple palettes or the alpha value if bmp sprite	
		SpriteSize_16x16,     
		SpriteColorFormat_256Color, 
		gfx_crab_alien,		//+16*16/2, 	//pointer to the loaded graphics
		-1,             //sprite rotation data  
		false,          //double the size when rotating?
		false,			//hide the sprite?
		false, false, 	//vflip, hflip
		false			//apply mosaic
	); 
	oamUpdate(&oamMain);  
} // display_crab_alien()

void remove_crab_alien(int index, int x, int y) {
	oamSet(&oamMain, 	//main graphics engine context
		index,  		//oam index (0 to 127)  
		x, y,    		//x and y pixel location of the sprite
		0,       		//priority, lower renders last (on top)
		0,	 			//this is the palette index if multiple palettes or the alpha value if bmp sprite	
		SpriteSize_16x16,     
		SpriteColorFormat_256Color, 
		gfx_crab_alien,		//+16*16/2, 	//pointer to the loaded graphics
		-1,            	//sprite rotation data  
		false,         	//double the size when rotating?
		true,			//hide the sprite?
		false, false, 	//vflip, hflip
		false			//apply mosaic
	); 
	oamUpdate(&oamMain); 
} // remove_crab_alien()

void display_squid_alien(int index, int x, int y) { 
	oamSet(&oamMain, 	//main graphics engine context
		index,  		//oam index (0 to 127)  
		x, y,    		//x and y pixel location of the sprite
		0,       		//priority, lower renders last (on top)
		0,	 			//this is the palette index if multiple palettes or the alpha value if bmp sprite	
		SpriteSize_16x16,     
		SpriteColorFormat_256Color, 
		gfx_squid_alien,		//+16*16/2, 	//pointer to the loaded graphics
		-1,             //sprite rotation data  
		false,          //double the size when rotating?
		false,			//hide the sprite?
		false, false, 	//vflip, hflip
		false			//apply mosaic
	); 
	oamUpdate(&oamMain);  
} // display_squid_alien()

void remove_squid_alien(int index, int x, int y) {
	oamSet(&oamMain, 	//main graphics engine context
		index,  		//oam index (0 to 127)  
		x, y,    		//x and y pixel location of the sprite
		0,       		//priority, lower renders last (on top)
		0,	 			//this is the palette index if multiple palettes or the alpha value if bmp sprite	
		SpriteSize_16x16,     
		SpriteColorFormat_256Color, 
		gfx_squid_alien,		//+16*16/2, 	//pointer to the loaded graphics
		-1,            	//sprite rotation data  
		false,         	//double the size when rotating?
		true,			//hide the sprite?
		false, false, 	//vflip, hflip
		false			//apply mosaic
	); 
	oamUpdate(&oamMain); 
} // remove_squid_alien()

void display_octopus_alien(int index, int x, int y) { 
	oamSet(&oamMain, 	//main graphics engine context
		index,  		//oam index (0 to 127)  
		x, y,    		//x and y pixel location of the sprite
		0,       		//priority, lower renders last (on top)
		0,	 			//this is the palette index if multiple palettes or the alpha value if bmp sprite	
		SpriteSize_16x16,     
		SpriteColorFormat_256Color, 
		gfx_octopus_alien,		//+16*16/2, 	//pointer to the loaded graphics
		-1,             //sprite rotation data  
		false,          //double the size when rotating?
		false,			//hide the sprite?
		false, false, 	//vflip, hflip
		false			//apply mosaic
	); 
	oamUpdate(&oamMain);  
} // display_octopus_alien()

void remove_octopus_alien(int index, int x, int y) {
	oamSet(&oamMain, 	//main graphics engine context
		index,  		//oam index (0 to 127)  
		x, y,    		//x and y pixel location of the sprite
		0,       		//priority, lower renders last (on top)
		0,	 			//this is the palette index if multiple palettes or the alpha value if bmp sprite	
		SpriteSize_16x16,     
		SpriteColorFormat_256Color, 
		gfx_octopus_alien,		//+16*16/2, 	//pointer to the loaded graphics
		-1,            	//sprite rotation data  
		false,         	//double the size when rotating?
		true,			//hide the sprite?
		false, false, 	//vflip, hflip
		false			//apply mosaic
	); 
	oamUpdate(&oamMain); 
} // remove_octopus_alien()

void display_projectile(int index, int x, int y) { 
	oamSet(&oamMain, 	//main graphics engine context
		index,  		//oam index (0 to 127)  
		x, y,    		//x and y pixel location of the sprite
		0,       		//priority, lower renders last (on top)
		0,	 			//this is the palette index if multiple palettes or the alpha value if bmp sprite	
		SpriteSize_16x16,     
		SpriteColorFormat_256Color, 
		gfx_projectile,		//+16*16/2, 	//pointer to the loaded graphics
		-1,             //sprite rotation data  
		false,          //double the size when rotating?
		false,			//hide the sprite?
		false, false, 	//vflip, hflip
		false			//apply mosaic
	); 
	oamUpdate(&oamMain);  
} // display_projectile()

void remove_projectile(int index, int x, int y) {
	oamSet(&oamMain, 	//main graphics engine context
		index,  		//oam index (0 to 127)  
		x, y,    		//x and y pixel location of the sprite
		0,       		//priority, lower renders last (on top)
		0,	 			//this is the palette index if multiple palettes or the alpha value if bmp sprite	
		SpriteSize_16x16,     
		SpriteColorFormat_256Color, 
		gfx_projectile,		//+16*16/2, 	//pointer to the loaded graphics
		-1,            	//sprite rotation data  
		false,         	//double the size when rotating?
		true,			//hide the sprite?
		false, false, 	//vflip, hflip
		false			//apply mosaic
	); 
	oamUpdate(&oamMain); 
} // remove_projectile()


void display_enemy_projectile(int index, int x, int y) { 
	oamSet(&oamMain, 	//main graphics engine context
		index,  		//oam index (0 to 127)  
		x, y,    		//x and y pixel location of the sprite
		0,       		//priority, lower renders last (on top)
		0,	 			//this is the palette index if multiple palettes or the alpha value if bmp sprite	
		SpriteSize_16x16,     
		SpriteColorFormat_256Color, 
		gfx_enemy_projectile,		//+16*16/2, 	//pointer to the loaded graphics
		-1,             //sprite rotation data  
		false,          //double the size when rotating?
		false,			//hide the sprite?
		false, false, 	//vflip, hflip
		false			//apply mosaic
	); 
	oamUpdate(&oamMain);  
} // display_enemy_projectile()

void remove_enemy_projectile(int index, int x, int y) {
	oamSet(&oamMain, 	//main graphics engine context
		index,  		//oam index (0 to 127)  
		x, y,    		//x and y pixel location of the sprite
		0,       		//priority, lower renders last (on top)
		0,	 			//this is the palette index if multiple palettes or the alpha value if bmp sprite	
		SpriteSize_16x16,     
		SpriteColorFormat_256Color, 
		gfx_enemy_projectile,		//+16*16/2, 	//pointer to the loaded graphics
		-1,            	//sprite rotation data  
		false,         	//double the size when rotating?
		true,			//hide the sprite?
		false, false, 	//vflip, hflip
		false			//apply mosaic
	); 
	oamUpdate(&oamMain); 
} // remove_enemy_projectile()


void display_explosion(int index, int x, int y) { 
	oamSet(&oamMain, 	//main graphics engine context
		index,  		//oam index (0 to 127)  
		x, y,    		//x and y pixel location of the sprite
		0,       		//priority, lower renders last (on top)
		0,	 			//this is the palette index if multiple palettes or the alpha value if bmp sprite	
		SpriteSize_16x16,     
		SpriteColorFormat_256Color, 
		gfx_explosion,		//+16*16/2, 	//pointer to the loaded graphics
		-1,             //sprite rotation data  
		false,          //double the size when rotating?
		false,			//hide the sprite?
		false, false, 	//vflip, hflip
		false			//apply mosaic
	); 
	oamUpdate(&oamMain);  
} // display_explosion()


void remove_explosion(int index, int x, int y) {
	oamSet(&oamMain, 	//main graphics engine context
		index,  		//oam index (0 to 127)  
		x, y,    		//x and y pixel location of the sprite
		0,       		//priority, lower renders last (on top)
		0,	 			//this is the palette index if multiple palettes or the alpha value if bmp sprite	
		SpriteSize_16x16,     
		SpriteColorFormat_256Color, 
		gfx_explosion,		//+16*16/2, 	//pointer to the loaded graphics
		-1,            	//sprite rotation data  
		false,         	//double the size when rotating?
		true,			//hide the sprite?
		false, false, 	//vflip, hflip
		false			//apply mosaic
	); 
	oamUpdate(&oamMain); 
} // remove_explosion()
