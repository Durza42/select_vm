#include "app_data.h"
#include "fields.h"
#include <ncurses.h>

/**
 * @brief what is done when key_up is pressed
 * @details goes to field registered as at the up of the current one
 */
void up(App_datas* datas)
{
    if(datas -> fields[datas -> current_field].next_id[UP] == -1)
        return;

    datas -> current_field = datas -> fields[datas -> current_field].next_id[UP];

    wmove(stdscr, datas -> fields[datas -> current_field].y, datas -> fields[datas -> current_field].x);
}

/**
 * @brief what is done when key_right is pressed
 * @details goes to field registered as at the right of the current one
 */
void right(App_datas* datas)
{
    if(datas -> fields[datas -> current_field].next_id[RIGHT] == -1)
        return;

    datas -> current_field = datas -> fields[datas -> current_field].next_id[RIGHT];
    wmove(stdscr, datas -> fields[datas -> current_field].y, datas -> fields[datas -> current_field].x);
}

/**
 * @brief what is done when key_down is pressed
 * @details goes to field registered as at the down of the current one
 */
void down(App_datas* datas)
{
    if(datas -> fields[datas -> current_field].next_id[DOWN] == -1)
        return;

    datas -> current_field = datas -> fields[datas -> current_field].next_id[DOWN];
    wmove(stdscr, datas -> fields[datas -> current_field].y, datas -> fields[datas -> current_field].x);
}

/**
 * @brief what is done when key_left is pressed
 * @details goes to field registered as at the left of the current one
 */
void left(App_datas* datas)
{
    if(datas -> fields[datas -> current_field].next_id[LEFT] == -1)
        return;

    datas -> current_field = datas -> fields[datas -> current_field].next_id[LEFT];
    wmove(stdscr, datas -> fields[datas -> current_field].y, datas -> fields[datas -> current_field].x);
}

