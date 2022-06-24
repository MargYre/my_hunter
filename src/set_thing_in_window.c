
/*
** EPITECH PROJECT, 2018
** MUL_my_hunter_2018
** File description:
** set_ghost_texture, move_rect, set_sound
*/

#include "../include/hunter.h"

void ghost_basic_animation(image_t *s_pri_tex, system_t *s_system)
{
    sfClock *clock;
    sfTime time;
    float seconds = 0.0;

    clock = sfClock_create();
    sfClock_restart(clock);
    if (s_pri_tex->rect.left >= 255)
        s_pri_tex->rect.left = 0;
    else {
        if (seconds <= 0.0) {
            while (seconds < 15.000000) {
                time = sfClock_getElapsedTime(clock);
                seconds = time.microseconds / 10000;
            }
        }
        s_pri_tex->rect.left = s_pri_tex->rect.left + 64;
    }
    sfSprite_setTextureRect(s_pri_tex->sprite_ghost, s_pri_tex->rect);
    sfClock_destroy(clock);
}

int ghost_travel(image_t *s_spri_tex, system_t *s_system)
{
    sfVector2f test;
    static int i = 10;
    int nb_random = get_random_nb(80, 334);

    s_spri_tex->pos.x = i;
    s_spri_tex->pos.y = 0;
    test = sfSprite_getPosition(s_spri_tex->sprite_ghost);
    if (test.x >= 810) {
        s_spri_tex->pos.x = -100;
        s_spri_tex->pos.y = nb_random;
        sfSprite_setPosition(s_spri_tex->sprite_ghost, s_spri_tex->pos);
        display_sprite(s_system, s_spri_tex);
        s_system->life--;
    }
    if (test.x <= -5) {
        if (i < 25)
            i = i + 2;
    }
    sfSprite_move(s_spri_tex->sprite_ghost, s_spri_tex->pos);
    return (s_system->life);
}
