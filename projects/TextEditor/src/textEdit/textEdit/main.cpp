#define PDC_DLL_BUILD 1

#include "curses.h"
#include "panel.h"
#include "curspriv.h"
#include <string>
#include <algorithm>

using namespace std;

int main(int argc, char* argv[])
{
	WINDOW* main_window = nullptr;
	int num_cols = 0;
	int num_rows = 0;

	//SETUP

	//initializing our window
	main_window = initscr();

	//resize our window
	//resize_term(5000, 5000); <-- gets full screen
	getmaxyx(main_window, num_rows, num_cols);
	resize_term(num_rows - 1, num_cols - 1);
	getmaxyx(main_window, num_rows, num_cols);

	//turn keyboard echo
	noecho();

	cbreak();

	//turn on keypad input
	keypad(main_window, TRUE);

	//hide the cursor
	curs_set(FALSE);

	//MAIN PROGRAM LOGIC GOES HERE

	// ****** BORDER ******

	for (int i = 0; i < num_cols; i++)
	{
		//top row
		mvaddch(0, i, ACS_BLOCK);

		//bottom row
		mvaddch(num_rows - 1, i, ACS_BLOCK);
	}

	for (int i = 0; i < num_rows; i++)
	{
		//left column
		mvaddch(i, 0, ACS_BLOCK);

		//right column
		mvaddch(i, num_cols - 1, ACS_BLOCK);
	}

	//refresh tells curses to draw everything
	refresh();

	//******** STATUS BAR *********



	// ****** HEADER ********
/*
	//intizializing the window
	initscr();
	noecho();
	cbreak();
*/

//getting screen size for small window
	int yMax, xMax;
	getmaxyx(stdscr, yMax, xMax);

	//creating smaller window for input/menu
	WINDOW* small_window = newwin(8, xMax - 10, yMax - 10, 7);
	box(small_window, 0, 0);
	refresh();
	wrefresh(small_window);

	//using arrow keys
	keypad(small_window, true);

	string menu[2] = { "FILE", "EXIT" };
	//string menu[5] = { "FILE", "EDIT", "OPTIONS", "HELP", "EXIT" };
	int choice;
	int highlight = 0;

	while (1)
	{
		for (int i = 0; i < 2; i++)
		{
			if (i == highlight)
				wattron(small_window, A_REVERSE);
			mvwprintw(small_window, 1, i + 5, menu[i].c_str()); // change the spacing
			wattroff(small_window, A_REVERSE);
		}
		choice = wgetch(small_window);

		switch (choice)
		{
		case KEY_LEFT:
			highlight--;
			if (highlight == -1)
				highlight = 0;
			break;
		case KEY_RIGHT:
			highlight++;
			if (highlight == 2)//5
				highlight = 1;//4
			break;
		default:
			break;
		}
		if (choice == 10)
			break;
	}

	//printw("Your choice was: %s", menu[highlight].c_str());

	//END OF PROGRAM
	getch();
	endwin();
}