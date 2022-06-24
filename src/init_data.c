/*
** EPITECH PROJECT, 2018
** MUL_my_hunter_2018
** File description:
** init_system, init_spri_text
*/

#include "../include/hunter.h"

void init_system(system_t *s_system, sound_t *s_sound)
{
    s_system->mode.width = 800;
    s_system->mode.height = 800;
    s_system->mode.bitsPerPixel = 32;
    s_system->window = sfRenderWindow_create(s_system->mode, "Window My_Hunter",
                                             sfResize | sfClose, NULL);
    s_system->event;
    s_sound->music = sfMusic_createFromFile("./music/kyary_fashion_monster.ogg");
    sfMusic_setLoop(s_sound->music, sfTrue);
    sfMusic_play(s_sound->music);
    s_system->life = 2;
}

void init_spri_text(image_t *s_pri_tex)
{
    s_pri_tex->texture_ghost = sfTexture_createFromFile("./png/ghost_sprites_sheet.png", NULL);
    s_pri_tex->texture_bg = sfTexture_createFromFile("./png/background.png", NULL);
    s_pri_tex->rect.top = 0;
    s_pri_tex->rect.left = 0;
    s_pri_tex->rect.width = 64;
    s_pri_tex->rect.height = 76;
    s_pri_tex->sprite_ghost = sfSprite_create();
    s_pri_tex->sprite_bg = sfSprite_create();
    sfSprite_setTexture(s_pri_tex->sprite_ghost, s_pri_tex->texture_ghost, sfTrue);
    sfSprite_setTexture(s_pri_tex->sprite_bg, s_pri_tex->texture_bg, sfTrue);
    s_pri_tex->pos.y = 50;
    s_pri_tex->pos.x = 0;
    sfSprite_setPosition(s_pri_tex->sprite_ghost, s_pri_tex->pos);
}
