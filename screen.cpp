#include <iostream>
#include <SFML/Graphics.hpp>
#include "screen.h"

ChessGame::ChessGame(sf::RenderWindow* window) {
	this->window = window;
	this->Draw_Table();
	this->Draw_Pieces();
	this->window->display();
}

ChessGame::~ChessGame() {
	this->piese_capturate.clear();
	delete this->window;
}

Table ChessGame::get_table() { return this->tabla; }
bool ChessGame::get_turn() { return this->turn; }
bool ChessGame::get_game_over() { return this->GameOver; }

string ChessGame::mouse_coordinates(int x, int y)
{
	char pos[3];
	pos[0] = 'a' + (x / 100);
	pos[1] = '8' - (y / 100);
	pos[2] = NULL;
	return pos;
}

string ChessGame::patrat_ales()
{
	int x, y;
	string pt;
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
	{
		sf::Vector2i mouse_position = sf::Mouse::getPosition(*window);
		return mouse_coordinates(mouse_position.x, mouse_position.y);
	}
	return "sus";
}

void ChessGame::Draw_Table()
{
	//setfillstyle(SOLID_FILL, COLOR(31, 13, 5));
	//floodfill(1, 1, WHITE);
	int r = 207, g = 168, b = 130;
	//setcolor(COLOR(r, g, b));

	//setfillstyle(SOLID_FILL, COLOR(r, g, b));
	sf::Color white_color(207, 168, 130);
	sf::Color black_color(31, 13, 5);
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			sf::Color square_color;
			(i % 2 == 0) ? 
				((j % 2 == 0) ? (square_color = white_color) : (square_color = black_color)) : 
				((j % 2 == 0) ? (square_color = black_color) : (square_color = white_color));

			sf::RectangleShape patrat(sf::Vector2f(100, 100));
			patrat.setFillColor(square_color);
			patrat.setPosition(sf::Vector2f(j * 100, i * 100));
			this->window->draw(patrat);
		}
	}

	/*for (int i = 1; i <= 8; i++)
	{
		char txt[2];
		txt[0] = '0' + i;
		txt[1] = NULL;
		if (i % 2 == 1)
		{
			setbkcolor(COLOR(31, 13, 5));
			setcolor(COLOR(r, g, b));
		}
		else
		{
			setbkcolor(COLOR(r, g, b));
			setcolor(COLOR(31, 13, 5));
		}
		outtextxy(5, 810 - i * 100, txt);
		txt[0] = 'a' + i - 1;
		outtextxy(i * 100 - 20, 770, txt);
	}

	setbkcolor(BLACK);*/

	//window->display();
}

void ChessGame::pos_to_int(int& x, int& y, string pos)
{
	x = int(pos[0] - 'a');
	x = x * 100 + 50;
	y = int(pos[1] - '0');
	y = 850 - y * 100;
}

void ChessGame::Draw_Pieces()
{
	//setcolor(WHITE);
	int x, y;
	for (auto i : tabla.Get_White_Pieces())
	{
		char ch[5] = "W_";
		ch[2] = i->Get_Name()[6];
		ch[3] = i->Get_Name()[7];
		ch[4] = NULL;
		pos_to_int(x, y, i->Get_Position());
		if (((x + y - 100) / 100) % 2 == 0)
		{
			setbkcolor(COLOR(31, 13, 5));
			setcolor(COLOR(207, 168, 130));
		}
		else
		{
			setbkcolor(COLOR(207, 168, 130));
			setcolor(COLOR(31, 13, 5));
		}
		outtextxy(x - textwidth(ch) / 2, y - textheight(ch) / 2, ch);
	}

	for (auto i : tabla.Get_Black_Pieces())
	{
		char ch[5] = "B_";
		ch[2] = i->Get_Name()[6];
		ch[3] = i->Get_Name()[7];
		ch[4] = NULL;
		pos_to_int(x, y, i->Get_Position());
		if (((x + y - 100) / 100) % 2 == 0)
		{
			setbkcolor(COLOR(31, 13, 5));
			setcolor(COLOR(207, 168, 130));
		}
		else
		{
			setbkcolor(COLOR(207, 168, 130));
			setcolor(COLOR(31, 13, 5));
		}
		outtextxy(x - textwidth(ch) / 2, y - textheight(ch) / 2, ch);
	}

	//window->display();
}

void ChessGame::Set_Pieces()
{
	this->tabla += new King("white", "e1");
	this->tabla += new King("black", "e8");
	this->tabla += new Queen("white", "d1");
	this->tabla += new Queen("black", "d8");
	this->tabla += new Bishop("White_Bishop_1", "white", "c1");
	this->tabla += new Bishop("White_Bishop_2", "white", "f1");
	this->tabla += new Bishop("Black_Bishop_1", "black", "c8");
	this->tabla += new Bishop("Black_Bishop_2", "black", "f8");
	this->tabla += new Knight("White_Knight_1", "white", "b1");
	this->tabla += new Knight("White_Knight_2", "white", "g1");
	this->tabla += new Knight("Black_Knight_1", "black", "b8");
	this->tabla += new Knight("Black_Knight_2", "black", "g8");
	this->tabla += new Rook("White_Rook_1", "white", "a1");
	this->tabla += new Rook("White_Rook_2", "white", "h1");
	this->tabla += new Rook("Black_Rook_1", "black", "a8");
	this->tabla += new Rook("Black_Rook_2", "black", "h8");
	for (int i = 1; i <= 8; i++)
	{
		char pos[3];
		pos[0] = 'a' + i - 1;
		pos[1] = '2';
		pos[2] = NULL;

		char name[14] = "White_Pawn_";
		name[11] = '0' + i;
		name[12] = NULL;

		this->tabla += new Pawn(name, "white", pos);
	}
	for (int i = 1; i <= 8; i++)
	{
		char pos[3];
		pos[0] = 'a' + i - 1;
		pos[1] = '7';
		pos[2] = NULL;

		char name[14] = "Black_Pawn_";
		name[11] = '0' + i;
		name[12] = NULL;
		this->tabla += new Pawn(name, "black", pos);
	}
	this->tabla += new emptyness;
}

void ChessGame::move_piece(piece* piesa, string pos_init, string pos_ult, string culoare)
{
	this->window->clear();
	if (tabla.Get_Square_Piece(pos_ult)->Get_Name() == "unidentified")
	{
		if (tabla.Get_Square_Piece(pos_init)->move(pos_ult, tabla.Get_All_Pieces()) == true)
		{
			cout << "Piesa " << tabla.Get_Square_Piece(pos_ult)->Get_Name() << " a fost mutata pe pozitia " << pos_ult << endl;
			if (turn == 0)
				turn = 1;
			else
				turn = 0;
		}
		else
			cout << "Mutare invalida" << endl;
	}
	else
		if (tabla.Get_Square_Piece(pos_ult)->Get_Color() != culoare) {
			if (tabla.Get_Square_Piece(pos_init)->return_type() != pawn) {
				if (tabla.Get_Square_Piece(pos_ult)->move("ghost", tabla.Get_All_Pieces()) == true) {
					if (tabla.Get_Square_Piece(pos_init)->move(pos_ult, tabla.Get_All_Pieces()) == false)
					{
						if (tabla.Get_Square_Piece("ghost")->move(pos_ult, tabla.Get_All_Pieces()))
							cout << "Mutare invalida" << endl;
					}
					else
					{
						cout << "Piesa " << tabla.Get_Square_Piece(pos_ult)->Get_Name() << " a fost mutata pe pozitia " << pos_ult << endl;
						piese_capturate.push_back(tabla.Get_Square_Piece("ghost"));
						tabla.destroy(tabla.Get_Square_Piece("ghost")->Get_Position());
						cout << "Piesa " << tabla.Get_Square_Piece(pos_ult)->Get_Name() << " a capturat piesa " << piese_capturate.back()->Get_Name() << endl;
						cout << endl << "Piesele capturate sunt:" << endl;
						for (auto i : piese_capturate)
							cout << i->Get_Name() << endl;
						cout << endl;
						turn = !turn;
					}
				}
				tabla.Set_En_Passant_To_False();
			}
			else {
				if (tabla.Get_Square_Piece(pos_init)->move(pos_ult, tabla.Get_All_Pieces()) == true) {
					string culoare2;
					culoare2 = culoare == "white" ? "black" : "white";
					if (tabla.Get_Square_Piece(pos_ult)->return_type() == pawn) {
						if (tabla.Get_Pawn(pos_ult, culoare2)->move("ghost", tabla.Get_All_Pieces()) == true) {
							cout << "Piesa " << tabla.Get_Square_Piece(pos_ult)->Get_Name() << " a fost mutata pe pozitia " << pos_ult << endl;
							piese_capturate.push_back(tabla.Get_Square_Piece("ghost"));
							tabla.destroy(tabla.Get_Square_Piece("ghost")->Get_Position());
							cout << "Piesa " << tabla.Get_Square_Piece(pos_ult)->Get_Name() << " a capturat piesa " << piese_capturate.back()->Get_Name() << endl;
							cout << endl << "Piesele capturate sunt:" << endl;
							for (auto i : piese_capturate)
								cout << i->Get_Name() << endl;
							cout << endl;
							if (turn == 0)
								turn = 1;
							else
								turn = 0;
						}
					}
					else {
						if (tabla.Get_Not_Pawn(pos_ult, culoare2)->move("ghost", tabla.Get_All_Pieces()) == true)
						{
							cout << "Piesa " << tabla.Get_Square_Piece(pos_ult)->Get_Name() << " a fost mutata pe pozitia " << pos_ult << endl;
							piese_capturate.push_back(tabla.Get_Square_Piece("ghost"));
							tabla.destroy(tabla.Get_Square_Piece("ghost")->Get_Position());
							cout << "Piesa " << tabla.Get_Square_Piece(pos_ult)->Get_Name() << " a capturat piesa " << piese_capturate.back()->Get_Name() << endl;
							cout << endl << "Piesele capturate sunt:" << endl;
							for (auto i : piese_capturate)
								cout << i->Get_Name() << endl;
							cout << endl;
							if (turn == 0)
								turn = 1;
							else
								turn = 0;
						}
					}
				}
				else {
					cout << "Mutare invalida" << endl;
				}
			}
		}
		else {
			if (tabla.Get_Square_Piece(pos_init)->move(pos_ult, tabla.Get_All_Pieces()) == true) {
				cout << "Nu iti poti captura propria piesa" << endl;
			}
			else {
				cout << "Mutare invalida" << endl;
			}
		}

	this->Draw_Table();
	this->Draw_Pieces();
	this->window->display();
}