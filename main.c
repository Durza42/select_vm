#define _DEBUG

#include <ncurses.h>
#include <string.h>
#include "msg.h"
#include "loop.h"
#include "app_data.h"

/**
 * @brief print the base text of the app : structure, borders, ...
 * 
 * @param datas all the datas to print in the window
 */
void print_base(const App_datas datas)
{
    attron(A_BOLD);
        mvprintw(MSG_list_VM_y(stdscr), MSG_list_VM_x(stdscr), MSG_list_VM);
        mvprintw(MSG_add_VM_y(stdscr),  MSG_add_VM_x(stdscr),  MSG_add_VM);
    attroff(A_BOLD);

    attron(A_ITALIC);
        for(size_t i = 0 ; i < datas.nb_vms ; ++i)
            mvprintw(MSG_first_name_VM_y(stdscr) + 2 * i, MSG_name_VM_x(stdscr), datas.VMs[i].name);
    attroff(A_ITALIC);

    wmove(stdscr, datas.fields[datas.current_field].y, datas.fields[datas.current_field].x);
}

/**
 * @brief initialize all the datas of the application
 * 
 * @param datas a pointer to the datas stored by the application. Thoses datas will be initialised
 */
void init_datas(App_datas* datas)
{
    datas -> nb_vms = 0;

    /// TODO: remove hardcode; use: environment variables? specific file?
    add_VM(datas, "arch linux\0");
    add_VM(datas, "Microsoft Windows\0");
    add_VM(datas, "Mac OS X\0");
    add_VM(datas, "Ununtu\0");

    for(int i = 0 ; i < datas -> nb_vms ; ++i)
    {
        log_msg("-> ");
        log_msg(datas -> VMs[i].name);
        log_msg("\n");
    }
 
    datas -> nb_fields = 0;

    for(int i = 0 ; i < datas -> nb_vms ; ++i)
    {
        add_field(
            datas,
            MSG_first_name_VM_y(stdscr) + 2 * i, // y
            MSG_name_VM_x(stdscr) - 2, // x
            (int[4]){ -1+i, -1, 1+i, -1 } // { up, right, down, left }
        );
    }
 
    add_field(
        datas,
        MSG_add_VM_y(stdscr),
        MSG_add_VM_x(stdscr),
        (int[4]){ 2, -1, -1, -1});

    datas -> current_field = 0;
}

/**
 * @brief initialisation of the program
 * 
 * @param datas a pointer to every information stored by the program
 */
void init(App_datas* datas)
{
    initscr();

    raw();
    noecho();
    keypad(stdscr, TRUE);

    init_datas(datas);

    print_base(*datas);
}

int main()
{
    App_datas datas;
    init(&datas);

    loop(&datas);

	return 0;
}
