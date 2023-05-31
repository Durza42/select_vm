#include <ncurses.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

#include "loop.h"
#include "app_data.h"
#define _DEBUG
#include "msg.h"

void loop(App_datas* datas)
{
    log_msg("begin loop\n");

    int i = 0;
    do
    {
        ++i;
        refresh();
        mvprintw(0, 50, "count:%d", i);
        events(datas, i);
        delay_output(50);
    } while(TRUE);

}

void events(App_datas* datas, int i)
{
    int ch = getch();

    switch(ch)
    {
        case ERR:
            exit(1);
       break;

        case KEY_UP:
            mvprintw(0, 0, "up\n");
//            datas -> current_field = datas -> fields[datas -> current_field].next_id[UP];
//            wmove(stdscr, datas -> fields[datas -> current_field].y, datas -> fields[datas -> current_field].x);
       break;

        case KEY_RIGHT:
            mvprintw(0, 0, "right\n");
//            datas -> current_field = datas -> fields[datas -> current_field].next_id[RIGHT];
//            wmove(stdscr, datas -> fields[datas -> current_field].y, datas -> fields[datas -> current_field].x);
       break;

        case KEY_DOWN:
            mvprintw(0, 0, "down\n");
//            datas -> current_field = datas -> fields[datas -> current_field].next_id[DOWN];
//            wmove(stdscr, datas -> fields[datas -> current_field].y, datas -> fields[datas -> current_field].x);
       break;

        case KEY_LEFT:
            mvprintw(0, 0, "left\n");
//            datas -> current_field = datas -> fields[datas -> current_field].next_id[LEFT];
//            wmove(stdscr, datas -> fields[datas -> current_field].y, datas -> fields[datas -> current_field].x);
       break;

        case 'q':
            mvprintw(0, 0, "Quit\n");
            endwin();
            exit(EXIT_SUCCESS);
       break;

        default:
       break;
    }
}


void log_msg(const char* restrict str)
{
    FILE* log = fopen("log.log", "a");
    fputs(str, log);
    fclose(log);
}
