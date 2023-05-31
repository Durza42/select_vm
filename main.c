#if 1

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

    log_msg("print_base.\n");
}

/**
 * @brief initialize all the datas of the application
 * 
 * @param datas a pointer to the datas stored by the application. Thoses datas will be initialised
 */
void init_datas(App_datas* datas)
{
    log_msg("init_datas.\n");

    datas -> nb_vms = 0;

    /// TODO: remove hardcode; use: environment variables? specific file?
    add_VM(datas, "arch linux\0");
    add_VM(datas, "Microsoft Windows\0");

    log_msg("VMs:\n");
    for(int i = 0 ; i < datas -> nb_vms ; ++i)
    {
        log_msg("-> ");
        log_msg(datas -> VMs[i].name);
        log_msg("\n");
    }

    datas -> nb_fields = 0;

    add_field(datas, MSG_first_name_VM_y(stdscr),     MSG_name_VM_x(stdscr) - 2, (int[4]){-1, -1,  1, -1});
    add_field(datas, MSG_first_name_VM_y(stdscr) + 2, MSG_name_VM_x(stdscr) - 2, (int[4]){ 0, -1,  2, -1});
    add_field(datas, MSG_add_VM_y(stdscr),            MSG_add_VM_y(stdscr),      (int[4]){ 1, -1, -1, -1});

    datas -> current_field = 0;

    log_msg("end init_datas.\n");

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
//    cbreak();

    log_msg("init.\n");

    init_datas(datas);

    print_base(*datas);

    log_msg("end init.\n");
}

int main()
{
    log_msg("main.\n");

    App_datas datas;
    init(&datas);

    loop(&datas);

	return 0;
}

#endif
#if 0

#include <ncurses.h>


WINDOW *create_newwin(int height, int width, int starty, int startx);
void destroy_win(WINDOW *local_win);

int main(int argc, char *argv[])
{	
    WINDOW *my_win;
    int startx, starty, width, height;
    int ch;
    initscr();			/* Start curses mode 		*/
    raw();			/* Line buffering disabled, Pass on
				 * everty thing to me 		*/
    noecho();

    keypad(stdscr, TRUE);		/* I need that nifty F2 	*/
    height = 3;
    width = 10;
    starty = (LINES - height) / 2;	/* Calculating for a center placement */
    startx = (COLS - width) / 2;	/* of the window		*/
    printw("Press F2 to exit");
    refresh();
     
    my_win = create_newwin(height, width, starty, startx);

    int i = 0;
    while((ch = getch()) != KEY_F(2))
    {
        i++;
	switch(ch)
	{
	    case KEY_LEFT: 				
		destroy_win(my_win);				
		my_win = create_newwin(height, width, starty,--startx);	
		break;
	
	    case KEY_RIGHT:
		destroy_win(my_win);
		my_win = create_newwin(height, width, starty,++startx);
		break;

	    case KEY_UP:
		destroy_win(my_win);
		my_win = create_newwin(height, width, --starty,startx);
		break;

	    case KEY_DOWN:
		destroy_win(my_win);
		my_win = create_newwin(height, width, ++starty,startx);
		break;	
	}
    mvprintw(0, 30, " test, %d", i);
    }
    endwin();			/* End curses mode		  */
    return 0;
}

WINDOW *create_newwin(int height, int width, int starty, int startx)
{	
    WINDOW *local_win;
    local_win = newwin(height, width, starty, startx);
    box(local_win, 0 , 0);		/* 0, 0 gives default characters 
					   for the vertical and horizontal
					    lines			*/
    wrefresh(local_win);		/* Show that box 		*/
    return local_win;
}

void destroy_win(WINDOW *local_win)
{
    	/* box(local_win, ' ', ' '); : This won't produce the desired
  	 * result of erasing the window. It will leave it's four corners 
	 * and so an ugly remnant of window.  */
    
    wborder(local_win, ' ', ' ', ' ',' ',' ',' ',' ',' ');

	/* The parameters taken are 
	 * 1. win: the window on which to operate
	 * 2. ls: character to be used for the left side of the window 
	 * 3. rs: character to be used for the right side of the window 
	 * 4. ts: character to be used for the top side of the window 
	 * 5. bs: character to be used for the bottom side of the window 
 	 * 6. tl: character to be used for the top left corner of the window 
	 * 7. tr: character to be used for the top right corner of the window 
	 * 8. bl: character to be used for the bottom left corner of the window 
	 * 9. br: character to be used for the bottom right corner of the window */
    
    wrefresh(local_win);
    delwin(local_win);
}
#endif
