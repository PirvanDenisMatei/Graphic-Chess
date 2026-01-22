#include <iostream>
#include "pieces.h"

using namespace std;

class ChessGame {
	sf::RenderWindow* window;
	Table tabla;
	vector<piece*> piese_capturate;
	bool GameOver = false;
	bool turn = 1;
public:
	ChessGame(sf::RenderWindow* window);
	~ChessGame();
	string mouse_coordinates(int x, int y);
	string patrat_ales();
	void Draw_Table();
	void pos_to_int(int& x, int& y, string pos);
	void Draw_Pieces();
	void Set_Pieces();
	void move_piece(piece* piesa, string pos_init, string pos_ult, string culoare);
	Table get_table();
	bool get_turn();
	bool get_game_over();
};
