/*
** EPITECH PROJECT, 2018
** MUL_my_hunter_2018
** File description:
** display_sprite, display_background_yl
*/

#include "../include/hunter.h"

void display_sprite(system_t *s_system, image_t *s_pri_tex)
{
    sfRenderWindow_clear(s_system->window, sfBlack);
    sfRenderWindow_drawSprite(s_system->window, s_pri_tex->sprite_bg, NULL);
    sfRenderWindow_drawSprite(s_system->window, s_pri_tex->sprite_ghost, NULL);
    sfRenderWindow_display(s_system->window);
}

void display_background_yl(system_t *s_system, sfEvent event,
                   image_t *s_spri_tex, sound_t *s_sound)
{
    sfTexture *tex_youlose;
    sfSprite *spri_youlose;

    tex_youlose = sfTexture_createFromFile("./png/you_lose.png", NULL);
    spri_youlose = sfSprite_create();
    sfSprite_setTexture(spri_youlose, tex_youlose, sfTrue);
    sfRenderWindow_clear(s_system->window, sfBlack);
    sfRenderWindow_drawSprite(s_system->window, spri_youlose, NULL);
    sfRenderWindow_drawSprite(s_system->window, spri_youlose, NULL);
    sfRenderWindow_display(s_system->window);
    sfMusic_stop(s_sound->music);
    for (;analyse_events(s_system, event, s_spri_tex, s_sound) != -1;);
    sfSprite_destroy(spri_youlose);
    sfTexture_destroy(tex_youlose);
}
