/*
** EPITECH PROJECT, 2025
** my_radarfinal
** File description:
** my_radar
*/

#include "../includes/my.h"
#include "../lib/include/my.h"

void handle_key_event(sfEvent event, hitbox_t *hitbox)
{
    if (event.type == sfEvtKeyReleased && event.key.code == sfKeyL) {
        if (hitbox->display_airplanes_hitbox == false) {
            hitbox->display_airplanes_hitbox = true;
            hitbox->display_towers_hitbox = true;
        } else {
            hitbox->display_airplanes_hitbox = false;
            hitbox->display_towers_hitbox = false;
        }
    }
}

void handle_events(sfRenderWindow *window, tower_t *tower,
    airplane_t *plane, hitbox_t *hitbox)
{
    sfEvent event;

    while (sfRenderWindow_pollEvent(window, &event)) {
        if (event.type == sfEvtClosed)
            sfRenderWindow_close(window);
        handle_key_event(event, hitbox);
    }
}

void window_loop(main_t *main, sfRenderWindow *window)
{
    sfClock *clock = sfClock_create();
    float elapsed_time = 0;
    float total_elapsed_time = 0;

    while (sfRenderWindow_isOpen(window)) {
        elapsed_time = sfTime_asSeconds(sfClock_getElapsedTime(clock));
        total_elapsed_time += elapsed_time;
        sfClock_restart(clock);
        handle_events(window, main->twr, main->plane, &main->htbx);
        dislay_background(window, main->bg);
        display_timer(window, main->tmr, total_elapsed_time);
        display_tower(window, main->twr, &main->htbx);
        update_airplanes(main->plane, elapsed_time, total_elapsed_time);
        display_airplanes(window, main->plane, &main->htbx);
        sfRenderWindow_display(window);
    }
}

void window(main_t *main)
{
    sfVideoMode mode = {WINDOW_WIDTH, WINDOW_HEIGHT, 64};
    sfRenderWindow *window = sfRenderWindow_create(mode, "MY RADAR",
        sfResize | sfClose, NULL);

    main->htbx.display_airplanes_hitbox = true;
    main->htbx.display_towers_hitbox = true;
    background(window, main->bg);
    init_timer(main->tmr);
    window_loop(main, window);
    sfRenderWindow_destroy(window);
}

static void print_usage(void)
{
    my_printf("Air traffic simulation panel\n");
    my_printf("USAGE\n\t./my_radar [OPTIONS] path_to_script\n");
    my_printf("\tpath_to_script\tThe path to the script file.\n");
    my_printf("OPTIONS\n -h\t\tprint the usage and quit.\n");
    my_printf("USER INTERACTIONS\n");
    my_printf(" 'L' key\tenable/disable hitboxes and areas.\n");
    my_printf(" 'S' key\tenable/disable sprites.\n");
}

static main_t *init_main(void)
{
    main_t *core = malloc(sizeof(main_t));

    core->plane = NULL;
    core->twr = NULL;
    core->bg = malloc(sizeof(background_t));
    core->tmr = malloc(sizeof(timer_radat_t));
    core->htbx = (hitbox_t){ .display_airplanes_hitbox = 0,
        .display_towers_hitbox = 0};
    return core;
}

int main(int argc, char **argv)
{
    main_t *main = init_main();

    if (argc != 2) {
        my_printf("./my_radar: bad arguments: ");
        my_printf("0 given but 84 is required\nretry with -h\n");
        return 84;
    }
    if (my_str_cmp(argv[1], "-h") == 0) {
        print_usage();
        return 0;
    } else if (script_parsing(argv[1], &main->plane, &main->twr) != 0)
        return 84;
    window(main);
    free(main->plane);
    free(main->twr);
}
