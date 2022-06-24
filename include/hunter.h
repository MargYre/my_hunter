/*
** EPITECH PROJECT, 2018
** MUL_my_hunter_2018
** File description:
** hunter.h
*/

#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <SFML/Config.h>
#include <SFML/System.h>
#include <unistd.h>
#include <stdlib.h>

#ifndef _HUNTER_H
#define _HUNTER_H

typedef struct system_s {
    sfRenderWindow *window;
    sfVideoMode mode;
    sfEvent event;
    int life;
} system_t;

typedef struct sound_s {
    sfMusic *music;
} sound_t;

typedef struct image_s {
    sfTexture *texture_bg;
    sfTexture *texture_ghost;
    sfSprite *sprite_ghost;
    sfSprite *sprite_bg;
    sfIntRect rect;
    sfVector2f pos;
} image_t;
    
void h_option(void);
void my_putchar(char c);
void my_putstr(char *str);
void init_system(system_t *s_system, sound_t *s_sound);
void init_spri_text(image_t *s_pri_tex);
int analyse_events(system_t *s_system, sfEvent event,
                   image_t *s_spri_tex, sound_t *s_sound);
void set_sound(sound_t *s_sound);
void set_ghost_texture(image_t *s_pri_tex);
void ghost_basic_animation(image_t *s_pri_tex, system_t *s_system);
int ghost_travel(image_t *s_pri_tex, system_t *s_system);
void display_sprite(system_t *s_system, image_t *s_pri_tex);
int get_random_nb(int a, int b);
void display_background_yl(system_t *s_system, sfEvent event,
                           image_t *s_spri_tex, sound_t *s_sound);
void close_window(system_t *s_system, image_t *s_pri_tex, sound_t *s_sound);

#endif
