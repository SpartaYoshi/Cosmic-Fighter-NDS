#ifndef _sprites
#define _sprites
/********************************************************** 
 * sprites.h 
 **********************************************************/

extern u16* gfx_laser_cannon;
extern u16* gfx_crab_alien;
extern u16* gfx_octopus_alien;
extern u16* gfx_squid_alien;
extern u16* gfx_projectile;
extern u16* gfx_enemy_projectile;
extern u16* gfx_explosion;


extern void init_sprite_memory();

extern void set_main_palette();
extern void set_secondary_palette();

extern void alloc_sprites_in_memory();


extern void display_laser_cannon(int x, int y);
extern void remove_laser_cannon(int x, int y);

extern void display_crab_alien(int index, int x, int y);
extern void remove_crab_alien(int index, int x, int y);

extern void display_octopus_alien(int index, int x, int y);
extern void remove_octopus_alien(int index, int x, int y);

extern void display_squid_alien(int index, int x, int y);
extern void remove_squid_alien(int index, int x, int y);

extern void display_projectile(int index, int x, int y);
extern void remove_projectile(int index, int x, int y);

extern void display_enemy_projectile(int index, int x, int y);
extern void remove_enemy_projectile(int index, int x, int y);

extern void display_explosion(int index, int x, int y);
extern void remove_explosion(int index, int x, int y);
#endif