/*
** EPITECH PROJECT, 2018
** MUL_my_hunter_2018
** File description:
** main, game_loop, analyse_events, check_click_to_ghost, kill_ghost
*/

#include "../include/hunter.h"

int kill_ghost(image_t *s_spri_tex, system_t *s_system)
{
    sfClock *clock;
    sfTime time;
    float seconds = 0.0;

    s_spri_tex->rect.left = 384;
    sfSprite_setTextureRect(s_spri_tex->sprite_ghost, s_spri_tex->rect);
    display_sprite(s_system, s_spri_tex);
    clock = sfClock_create();
    if (seconds <= 0.0) {
        while (seconds < 30.000000) {
            time = sfClock_getElapsedTime(clock);
            seconds = time.microseconds / 10000;
        }
    }
    s_spri_tex->pos.y = get_random_nb(100, 700);
    s_spri_tex->pos.x = -150;
    sfSprite_setPosition(s_spri_tex->sprite_ghost, s_spri_tex->pos);
    display_sprite(s_system, s_spri_tex);
    return (0);
}

int check_click_to_ghost(int x, int y, image_t *s_spri_tex, system_t *s_system)
{
    s_spri_tex->pos = sfSprite_getPosition(s_spri_tex->sprite_ghost);
    if (x >= s_spri_tex->pos.x + 20 && x <= s_spri_tex->pos.x + 60
        && y >= s_spri_tex->pos.y && y <= s_spri_tex->pos.y + 76) {
        if (s_system->life == 0)
            return (-1);
        else
            kill_ghost(s_spri_tex, s_system);
    }
    return (0);
}

int analyse_events(system_t *s_system, sfEvent event,
                   image_t *s_spri_tex, sound_t *s_sound)
{
    sfMouseButtonEvent click;

    while (sfRenderWindow_pollEvent(s_system->window, &event)) {
        if (event.type == sfEvtClosed) {
            close_window(s_system, s_spri_tex, s_sound);
            return(-1);
        }
        else if (event.type == sfEvtMouseButtonPressed) {
            click.x = sfMouse_getPositionRenderWindow(s_system->window).x;
            click.y = sfMouse_getPositionRenderWindow(s_system->window).y;
        }
        if (check_click_to_ghost(click.x, click.y, s_spri_tex, s_system) == -1)
            return (-1);
    }
    return(0);
}

int game_loop(void)
{
    system_t s_system;
    sfEvent event;
    image_t s_pri_tex;
    sound_t s_sound;

    init_system(&s_system, &s_sound);
    init_spri_text(&s_pri_tex);
    if (!s_system.window)
        return (84);
    while (sfRenderWindow_isOpen(s_system.window)) {
        if (analyse_events(&s_system, event, &s_pri_tex, &s_sound) == -1)
            return(0);
        ghost_basic_animation(&s_pri_tex, &s_system);
        if (ghost_travel(&s_pri_tex, &s_system) <= -1) {
            display_background_yl(&s_system, event, &s_pri_tex, &s_sound);
            return (0);
        }
        display_sprite(&s_system, &s_pri_tex);
    }
    return (0);
}

int main(int ac, char **av)
{
    if (ac == 2 && av[1][0] != '-' && av[1][1] != 'h'){
        write(2, "syntax error: wrong argument(s)\n", 32);
        return (84);
    }
    if (ac == 2 && av[1][0] == '-' && av[1][1] == 'h') {
        h_option();
        return (0);
    }
    return(game_loop());
}
