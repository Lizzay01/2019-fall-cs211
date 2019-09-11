#define PDC_DLL_BUILD 1

#include "curses.h"
#include "panel.h"
#include "curspriv.h"
#include <string>
<<<<<<< HEAD
#include <algorithm>
=======

using namespace std;
>>>>>>> d1b777fbbd63a38b5f22e92e4b639bc253e5a08c

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

<<<<<<< HEAD
	//******** STATUS BAR *********



	// ****** HEADER ********
/*
	//intizializing the window
	initscr();
	noecho();
	cbreak();
*/

//getting screen size for small window
=======

	// ****** HEADER ********
/*
	//intizializing the window
	initscr();
	noecho();
	cbreak();
*/

	//getting screen size for small window
>>>>>>> d1b777fbbd63a38b5f22e92e4b639bc253e5a08c
	int yMax, xMax;
	getmaxyx(stdscr, yMax, xMax);

	//creating smaller window for input/menu
<<<<<<< HEAD
	WINDOW* small_window = newwin(8, xMax - 10, yMax - 10, 7);
=======
	WINDOW* small_window = newwin(8, xMax - 12, yMax - 20, 7);
>>>>>>> d1b777fbbd63a38b5f22e92e4b639bc253e5a08c
	box(small_window, 0, 0);
	refresh();
	wrefresh(small_window);

	//using arrow keys
	keypad(small_window, true);

<<<<<<< HEAD
	string menu[2] = { "FILE", "EXIT" };
	//string menu[5] = { "FILE", "EDIT", "OPTIONS", "HELP", "EXIT" };
=======
	string menu[5] = { "FILE", "EDIT", "OPTIONS", "HELP", "EXIT" };
>>>>>>> d1b777fbbd63a38b5f22e92e4b639bc253e5a08c
	int choice;
	int highlight = 0;

	while (1)
	{
<<<<<<< HEAD
		for (int i = 0; i < 2; i++)
		{
			if (i == highlight)
				wattron(small_window, A_REVERSE);
			mvwprintw(small_window, 1, i + 5, menu[i].c_str()); // change the spacing
=======
		for (int i = 0; i < 5; i++)
		{
			if (i == highlight)
				wattron(small_window, A_REVERSE);
			mvwprintw(small_window, i + 1, 1, menu[i].c_str());
>>>>>>> d1b777fbbd63a38b5f22e92e4b639bc253e5a08c
			wattroff(small_window, A_REVERSE);
		}
		choice = wgetch(small_window);

		switch (choice)
		{
<<<<<<< HEAD
		case KEY_LEFT:
=======
		case KEY_UP:
>>>>>>> d1b777fbbd63a38b5f22e92e4b639bc253e5a08c
			highlight--;
			if (highlight == -1)
				highlight = 0;
			break;
<<<<<<< HEAD
		case KEY_RIGHT:
			highlight++;
			if (highlight == 2)//5
				highlight = 1;//4
=======
		case KEY_DOWN:
			highlight++;
			if (highlight == 5)
				highlight = 4;
>>>>>>> d1b777fbbd63a38b5f22e92e4b639bc253e5a08c
			break;
		default:
			break;
		}
		if (choice == 10)
			break;
	}

<<<<<<< HEAD
	//printw("Your choice was: %s", menu[highlight].c_str());
=======
	printw("Your choice was: %s", menu[highlight].c_str());
>>>>>>> d1b777fbbd63a38b5f22e92e4b639bc253e5a08c

	//END OF PROGRAM
	getch();
	endwin();
}