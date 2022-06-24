/*
** EPITECH PROJECT, 2018
** MUL_my_hunter_2018
** File description:
** close_window
*/

#include "../include/hunter.h"

void close_window(system_t *s_system, image_t *s_pri_tex, sound_t *s_sound)
{
    sfMusic_destroy(s_sound->music);
    sfSprite_destroy(s_pri_tex->sprite_bg);
    sfSprite_destroy(s_pri_tex->sprite_ghost);
    sfTexture_destroy(s_pri_tex->texture_bg);
    sfTexture_destroy(s_pri_tex->texture_ghost);
    sfRenderWindow_destroy(s_system->window);
}
