#include <ncurses.h>
#include <stdbool.h>
#include "loop.h"
#include "app_data.h"
#define _DEBUG
#include "msg.h"

void loop(App_datas* datas)
{
    int i = 0;
    do
    {
        ++i;
        refresh();
        mvprintw(0, 50, "r;%d", i);
        events(datas, i);
        delay_output(50);
    } while(TRUE);
}

void events(App_datas* datas, int i)
{
//    mvprintw(DEBUG_MSG_y(stdscr), DEBUG_MSG_x(stdscr), "DEBUG MSG");
//    printw("events");

    int ch = getch();
    mvprintw(0, 40, "%d\n", ch);

//    mvprintw(DEBUG_MSG_y(stdscr), DEBUG_MSG_x(stdscr) + 15, "DEBUG MSG 1");

    switch(ch)
    {
        case ERR:
            mvprintw(DEBUG_MSG_y(stdscr), DEBUG_MSG_x(stdscr), "error.");
            return;
       break;

        case KEY_UP:
            mvprintw(0, 0, "up\n");
            datas -> current_field = datas -> fields[datas -> current_field].next_id[UP];
            wmove(stdscr, datas -> fields[datas -> current_field].y, datas -> fields[datas -> current_field].x);
       break;

        case KEY_RIGHT:
            mvprintw(0, 0, "right\n");
            datas -> current_field = datas -> fields[datas -> current_field].next_id[RIGHT];
            wmove(stdscr, datas -> fields[datas -> current_field].y, datas -> fields[datas -> current_field].x);
       break;

        case KEY_DOWN:
            mvprintw(0, 0, "down\n");
            datas -> current_field = datas -> fields[datas -> current_field].next_id[DOWN];
            wmove(stdscr, datas -> fields[datas -> current_field].y, datas -> fields[datas -> current_field].x);
       break;

        case KEY_LEFT:
            mvprintw(0, 0, "left\n");
            datas -> current_field = datas -> fields[datas -> current_field].next_id[LEFT];
            wmove(stdscr, datas -> fields[datas -> current_field].y, datas -> fields[datas -> current_field].x);
       break;

        case 'q':
            mvprintw(0, 0, "Quit\n");
            endwin();
            exit(EXIT_SUCCESS);
       break;

        default:
            mvprintw(0, 0, "no key pressed;%d;%d", ch, i);
       break;
    }

//    mvprintw(DEBUG_MSG_y(stdscr), DEBUG_MSG_x(stdscr) + 30, "DEBUG MSG 2");
}
