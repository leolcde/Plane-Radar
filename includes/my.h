/*
** EPITECH PROJECT, 2024
** my.h
** File description:
** my
*/

#ifndef MY_H_
    #define MY_H_

    #include <SFML/Graphics.h>
    #include <stdlib.h>
    #include <SFML/Window.h>
    #include <SFML/System.h>
    #include <SFML/Graphics/Rect.h>
    #include <SFML/System/Clock.h>
    #include <SFML/System/Vector2.h>
    #include <SFML/Audio.h>
    #include <math.h>
    #include <stdio.h>
    #include <stdbool.h>
    #include <time.h>
    #include <unistd.h>

    #define WINDOW_WIDTH 1920
    #define WINDOW_HEIGHT 1080



typedef struct airplane_s {
    sfVector2i start;
    sfVector2i end;
    int speed;
    int delay;
    sfTexture *texture;
    sfSprite *sprite;
    bool disp_hitbox;
    struct airplane_s *next;
} airplane_t;

typedef struct tower_s {
    sfVector2i position;
    int radius;
    sfTexture *texture;
    sfSprite *sprite;
    bool disp_hitbox;
    struct tower_s *next;
} tower_t;

typedef struct background_s {
    sfTexture *texture;
    sfSprite *sprite;
} background_t;

typedef struct timer_radar_s {
    sfText *text;
    sfFont *font;
    sfVector2f position;
} timer_radat_t;

typedef struct hitbox_s {
    int display_airplanes_hitbox;
    int display_towers_hitbox;
} hitbox_t;

typedef struct main_s {
    airplane_t *plane;
    tower_t *twr;
    background_t *bg;
    timer_radat_t *tmr;
    hitbox_t htbx;
} main_t;

int my_str_to_int(const char *str);
void parse_airplane(char **parsing_array, airplane_t **airplane_list);
void parse_tower(char **parsing_array, tower_t **tower_list);
int script_parsing(const char *script_path, airplane_t **head_a,
    tower_t **head_t);
void background(sfRenderWindow *window, background_t *bg);
void dislay_background(sfRenderWindow *window, background_t *bg);
void *init_airplane(airplane_t *plane);
void *init_tower(tower_t *tower);
void display_airplanes(sfRenderWindow *window, airplane_t *plane,
    hitbox_t *must_display);
void display_tower(sfRenderWindow *window, tower_t *tower,
    hitbox_t *must_display);
int compute_node(airplane_t *plane);
void update_airplanes(airplane_t *plane_list, float elapsed_time,
    float total_elapsed_time);
void display_timer(sfRenderWindow *window, timer_radat_t *timer,
    float seconds);
void init_timer(timer_radat_t *timer);
sfClock* create_clock(void);
void reset_clock(sfClock* clock);
float get_elapsed_time(sfClock* clock);

#endif
