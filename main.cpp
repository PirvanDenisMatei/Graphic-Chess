#include <iostream>
#include <SFML/Graphics.hpp>
#include <vector>
#include "screen.h"

using namespace std;


int main()
{
	int page = 0;
	string pozitie, position1 = "amogus", position2;
	
	cout << "Este tura jucatorului alb" << endl;
	sf::Color border_color = sf::Color::Black;
	sf::RenderWindow window(sf::VideoMode(800, 800), "Chess");
	ChessGame main_screen(&window);
	while(window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		pozitie = main_screen.patrat_ales();
		if (pozitie != "sus")
		{
				if (position1 == "amogus")
				{
					switch (main_screen.get_turn())
					{
					case 0:
					{
						if (main_screen.get_table().Get_Square_Piece(pozitie)->Get_Color() == "black") {
							position1 = pozitie, cout << endl << position1 << ' ';
						}
						break;
					}
					case 1:
					{
						if (main_screen.get_table().Get_Square_Piece(pozitie)->Get_Color() == "white") {
							position1 = pozitie, cout << endl << position1 << ' ';
						}
						break;
					}
					}
				}
				else
				{
					if (pozitie != position1)
					{
						position2 = pozitie, cout << position2 << endl;
						if (main_screen.get_table().Get_Square_Piece(position1)->Get_Name() != "unidentified" && position1 != position2)
						{
							main_screen.move_piece(main_screen.get_table().Get_Square_Piece(position1), position1, position2, main_screen.get_table().Get_Square_Piece(position1)->Get_Color());
							//char* tura = main_screen.get_turn() == true ? "alb" : "negru";
							cout << "\n\nEste tura jucatorului " << (main_screen.get_turn() == true ? "alb" : "negru") << endl;
						}
						else {
							cout << "Mutare invalida" << endl;
						}
						position1 = "amogus";
					}
				}
			}
	}


	return 0;
}