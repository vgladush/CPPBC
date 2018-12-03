#include "game.h"

Game::Game()
{
	srand(time(0));
	game = 4;
	initscr();
	noecho();
	curs_set(0);
	start_color();
	mousemask(ALL_MOUSE_EVENTS | REPORT_MOUSE_POSITION, NULL);
	win = newwin(HEIGHT, WIDTH, 0, 0);
	box(win, 0, 0);
	keypad(win, true);
	nodelay(win, true);
	wrefresh(win);
}

Game::~Game() 
{
	delwin(win);
	endwin();
}

void	Game::minesweeper()
{

	if (event.x < 8 || event.x > 50 || event.y < 8 || event.y > 27)
		return ;
	int ex = (event.x - 8) / 4, ey = (event.y - 8) / 2;
	if (event.bstate == BUTTON3_CLICKED && (!vis[ey][ex] || vis[ey][ex] == 'x'))
	{
		vis[ey][ex] = (!vis[ey][ex] ? 'x' : 0);
		wattron(win, COLOR_PAIR((!vis[ey][ex] ? 9 : 11)));
		mvwaddch(win, ey * 2 + 8, ex * 4 + 9, (!vis[ey][ex] ? ' ' : 'x'));
		wattroff(win, COLOR_PAIR((!vis[ey][ex] ? 9 : 11)));
		return ;
	}
	if (event.bstate == BUTTON1_CLICKED && !vis[ey][ex])
	{
		vis[ey][ex] = gm[ey][ex];
		if (vis[ey][ex] == 42)
		{
			for (int i = 0; i < y; ++i)
			{
				for (int j = 0; j < x; ++j)
				{
					if (gm[i][j] == 42)
					{
						wattron(win, COLOR_PAIR(11));
						mvwaddch(win, i * 2 + 8, j * 4 + 9, 42);
						wattron(win, COLOR_PAIR(11));
					}
				}
			}
			game = 3;
		}
		wattron(win, COLOR_PAIR(10));
		mvwprintw(win, ey * 2 + 8, ex * 4 + 8, " %c ", vis[ey][ex]);
		mvwprintw(win, ey * 2 + 9, ex * 4 + 8, "___");
		wattroff(win, COLOR_PAIR(10));
		vic += (game == 3 ? 0 : 1);
		if (vis[ey][ex] == ' ')
		{
			event.x += 4;
			minesweeper();
			event.y += 2;
			minesweeper();
			event.y -= 4;
			minesweeper();
			event.x -= 8;
			minesweeper();
			event.y += 2;
			minesweeper();
			event.y += 2;
			minesweeper();
			event.x += 4;
			minesweeper();
			event.y -= 4;
			minesweeper();
			event.y += 2;
		}
	}
}

void	Game::displ_15()
{
	for (int i = 0, j = 5, z = 0; i < 16; ++i, z += 11)
	{
		if (!(i % 4))
		{
			j += 5;
			z = 13;
		}
	wattron(win, COLOR_PAIR(3));
		if (!pzl[i])
		{
			wattron(win, COLOR_PAIR(9));
			mvwprintw(win, j, z, "  ");
			wattroff(win, COLOR_PAIR(9));
		}
		else
			mvwprintw(win, j, z, "%d", pzl[i]);
	wattroff(win, COLOR_PAIR(3));
	}
}

void	Game::puzzle15()
{
	if (event.x < 9 || event.x > 51 || event.y < 8 || event.y > 27)
		return ;
	int a = (event.x - 9) / 11 + (event.y - 8) / 5 * 4;
	if (a > 3 && !pzl[a - 4])
		std::swap(pzl[a], pzl[a - 4]);
	else if (a < 12 && !pzl[a + 4])
		std::swap(pzl[a], pzl[a + 4]);
	else if (a % 4 && !pzl[a - 1])
		std::swap(pzl[a], pzl[a - 1]);
	else if (a % 4 != 3 && !pzl[a + 1])
		std::swap(pzl[a], pzl[a + 1]);
	displ_15();
}

void Game::run_mine()
{
	for (int i = 0; i < y; ++i)
	{
		bzero(vis[i], x + 1);
		std::fill(gm[i], gm[i] + x, ' ');
		gm[i][x] = 0;
	}
	for (int i = 0; i < BOMBS; ++i)
	{
		int a = rand() % x, b = rand() % y;
		if (gm[b][a] == 42)
			--i;
		gm[b][a] = 42;
	}
	for (int i = 0; i < y; ++i)
	{
		for (int j = 0; j < x; ++j)
		{
			int bs = 0;
			if (gm[i][j] == 42)
				continue ;
			if (i > 0)
			{
				if (gm[i - 1][j] == 42)
					++bs;
				if (j + 1 < x && gm[i - 1][j + 1] == 42)
					++bs;
				if (j > 0 && gm[i - 1][j - 1] == 42)
					++bs;
			}
			if (i + 1 < y)
			{
				if (gm[i + 1][j] == 42)
					++bs;
				if (j + 1 < x && gm[i + 1][j + 1] == 42)
					++bs;
				if (j > 0 && gm[i + 1][j - 1] == 42)
					++bs;
			}
			if (j + 1 < x && gm[i][j + 1] == 42)
				++bs;
			if (j > 0 && gm[i][j - 1] == 42)
				++bs;
			if (bs)
				gm[i][j] = 48 + bs;
		}
	}
	wattron(win, COLOR_PAIR(3));
	for (int i = 8; i < 27; ++i)
	{
		mvwprintw(win, i, 8, "   |   |   |   |   |   |   |   |   |   |   ");
		mvwprintw(win, ++i, 8, "___|___|___|___|___|___|___|___|___|___|___");
	}
	mvwprintw(win, 27, 8, "   |   |   |   |   |   |   |   |   |   |   ");
	// wrefresh(win);
	vic = 0;
	event.x = 0;
	game = 1;
}

void	Game::run_15()
{
	for (int i = 0; i < 15; ++i)
		pzl[i] = i + 1;
	for (int i = 0; i < 15; ++i)
		std::swap(pzl[i], pzl[(rand() % 15)]);
	pzl[15] = 0;
	wattron(win, COLOR_PAIR(3));
	for (int i = 8; i < 27; ++i)
	{
		mvwprintw(win, i, 9, "          |          |          |          ");
		mvwprintw(win, ++i, 9, "          |          |          |          ");
		mvwprintw(win, ++i, 9, "          |          |          |          ");
		mvwprintw(win, ++i, 9, "          |          |          |          ");
		mvwprintw(win, ++i, 9, "__________|__________|__________|__________");
	}
	mvwprintw(win, 27, 9, "          |          |          |          ");
	displ_15();
	wattroff(win, COLOR_PAIR(3));
	event.x = 0;
	game = 2;
}

void	Game::choicegame()
{
	if (game)
	{
		wattron(win, COLOR_PAIR(6));
		for (int i = 6; i < HEIGHT - 2; ++i)
		{
			for (int j = 8; j < WIDTH - 8; ++j)
				mvwaddch(win, i, j, ' ');
		}
		wattron(win, COLOR_PAIR(6));
		wattron(win, COLOR_PAIR(7));
		mvwprintw(win, 9, 14, "                               ");
		mvwprintw(win, 10, 14, "                               ");
		mvwprintw(win, 11, 14, "          Minesweeper          ");
		mvwprintw(win, 12, 14, "                               ");
		mvwprintw(win, 13, 14, "                               ");
		wattroff(win, COLOR_PAIR(7));

		wattron(win, COLOR_PAIR(8));
		mvwprintw(win, 19, 14, "                               ");
		mvwprintw(win, 20, 14, "                               ");
		mvwprintw(win, 21, 14, "           15 puzzle           ");
		mvwprintw(win, 22, 14, "                               ");
		mvwprintw(win, 23, 14, "                               ");
		wattroff(win, COLOR_PAIR(8));
		// wrefresh(win);
	}
	game = 0;
}

void	Game::play()
{
	// COLOR_BLACK = 0, COLOR_RED = 1, COLOR_GREEN = 2, COLOR_YELLOW = 3
	// COLOR_BLUE = 4, COLOR_MAGENTA = 5, COLOR_CYAN = 6, COLOR_WHITE = 7

	init_pair(1, 4, 2);
	init_pair(2, 1, 3);
	init_pair(3, 0, 7);
	init_pair(4, 1, 0);
	init_pair(5, 2, 0);
	init_pair(6, 0, 0);
	init_pair(7, 7, 6);
	init_pair(8, 0, 5);
	init_pair(9, 7, 7);
	init_pair(10, 0, 6);
	init_pair(11, 1, 7);

	wattron(win, COLOR_PAIR(1));
	mvwprintw(win, 2, 9, "                ");
	mvwprintw(win, 3, 9, "    NEW GAME    ");
	mvwprintw(win, 4, 9, "                ");
	wattroff(win, COLOR_PAIR(1));

	wattron(win, COLOR_PAIR(2));
	mvwprintw(win, 2, 35, "                ");
	mvwprintw(win, 3, 35, "      EXIT      ");
	mvwprintw(win, 4, 35, "                ");
	wattroff(win, COLOR_PAIR(2));
	choicegame();

	while (1)
	{
		int key = std::tolower(wgetch(win));
		if (key == 27 || key == 'q')
			break ;
		if (getmouse(&event) == OK) {
			if (event.y > 1 && event.y < 5)
			{
				if (event.x > 8 && event.x < 25)
					choicegame();
				else if (event.x > 34 && event.x < 51)
					break ;
			}
			if (!game && event.x > 13 && event.x < 45)
			{
				if (event.y > 8 && event.y < 14)
					run_mine();
				else if (event.y > 18 && event.y < 24)
					run_15();
			}
			if (game == 1)
			{
				minesweeper();
				if (vic == 110 - BOMBS)
					game = 4;
			}
			if (game == 2)
			{
				puzzle15();
				for (int i = 0; i < 15; ++i)
				{
					if (i == 13 && pzl[i] == 15)
						game = 3;
					if (pzl[i] != i + 1)
						break ;
					if (i == 14)
						game = 4;
				}
			}
			if (game == 3 || game == 4)
			{
				wattron(win, COLOR_PAIR((game == 3 ? 4 : 5)));
				mvwprintw(win, 6, 22, (game == 3 ? "Y O U    L O S E" : "Y O U    W O N !"));
				wattroff(win, COLOR_PAIR((game == 3 ? 4 : 5)));
				game = 5;
			}
		}
	}
}
