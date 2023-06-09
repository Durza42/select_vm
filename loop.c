#include <ncurses.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

#include "loop.h"
#include "app_data.h"
#include "events.h"
#define _DEBUG
#include "msg.h"

void loop(App_datas* datas)
{
    do
    {
        refresh();
        events(datas);
        delay_output(50);
    } while(TRUE);
}

void events(App_datas* datas)
{
    int ch = getch();

    switch(ch)
    {
        case ERR:
            exit(1);
       break;

        case KEY_UP:
            up(datas);
       break;

        case KEY_RIGHT:
            right(datas);
       break;

        case KEY_DOWN:
            down(datas);
       break;

        case KEY_LEFT:
            left(datas);
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
    fprintf(log, str);
    fclose(log);
}
