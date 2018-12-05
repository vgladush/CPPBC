#ifndef GAME_HPP
#define GAME_HPP

#define WIDTH 60
#define HEIGHT 30
#define MAP_SZ 10
#define BOMBS 15

#include <ncurses.h>
/* to work with the library on the linux platform (ubuntu 16.04), you need to install it:
sudo apt-get install libncurses5-dev libncursesw5-dev
*/

class Game
{

public:

	Game();
	~Game();
	void	run_15(void);
	void	run_mine(void);
	void	play();
	void	displ_15();
	void	choicegame();
	void	minesweeper();
	void	puzzle15();

private:

	WINDOW *win;
	MEVENT event;
	int		game;
	int		vic;
	int		x = 11;
	int		y = 10;
	char	pzl[16];
	char	gm[MAP_SZ][MAP_SZ + 3];
	char	vis[MAP_SZ][MAP_SZ + 3];

};

#endif
