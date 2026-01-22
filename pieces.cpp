#include <iostream>
#include <vector>
#include <cmath>
#include "pieces.h"

class exceptie1 :public exception {
    virtual const char* what() const throw()
    {
        return "en passant";
    }
};

string piece::Get_Color() { return color; }
string piece::Get_Name() { return name; }
string piece::Get_Position() { return position; }

void ch_to_int(int& x, int& y, string pos)
{
    x = int(pos[0] - 'a' + 1);
    y = int(pos[1] - '0');
}

emptyness::emptyness() {
    name = "unidentified";
    color = "no_color";
    position = "no_position";
}
bool emptyness::move(string pos, vector<piece*> piese) { return false; }

King::King(string culoare, string position) {
    color = culoare;
    if (culoare == "black")
    {
        this->position = position;
        name = "Black_King";
    }
    else
    {
        this->position = position;
        name = "White_King";
    }
}
bool King::move(string pos, vector<piece*> piese) {
    int x, y, X, Y;
    if (pos == "ghost")
    {
        position = pos;
        return true;
    }
    if (position == "ghost")
    {
        position = pos;
        return true;
    }
    ch_to_int(x, y, pos);
    ch_to_int(X, Y, Get_Position());
    if (abs(X - x) <= 1 && abs(Y - y) <= 1)
    {
        position = pos;
        return true;
    }
    return false;
}

Queen::Queen(string culoare, string position) {
    color = culoare;
    if (culoare == "black")
    {
        this->position = position;
        name = "Black_Queen";
    }
    else
    {
        this->position = position;
        name = "White_Queen";
    }
}
bool Queen::move(string pos, vector<piece*> piese) {
    int x, y, X, Y, a, b, g, h;
    if (pos == "ghost")
    {
        position = pos;
        return true;
    }
    if (position == "ghost")
    {
        position = pos;
        return true;
    }
    ch_to_int(x, y, pos);
    ch_to_int(X, Y, Get_Position());
    if (x == X)
    {
        if (y < Y)
        {
            for (int i = Y - 1; i > y; i--)
                for (auto j : piese)
                {
                    ch_to_int(a, b, j->Get_Position());
                    if (x == a && i == b)
                    {
                        cout << "Piesa " << Get_Name() << " este obstructionata de piesa " << j->Get_Name() << endl;
                        return false;
                    }
                }
        }
        else
            for (int i = Y + 1; i < y; i++)
                for (auto j : piese)
                {
                    ch_to_int(a, b, j->Get_Position());
                    if (x == a && i == b)
                    {
                        cout << "Piesa " << Get_Name() << " este obstructionata de piesa " << j->Get_Name() << endl;
                        return false;
                    }
                }
        position = pos;
        return true;
    }
    if (y == Y)
    {
        if (x < X)
        {
            for (int i = X - 1; i > x; i--)
                for (auto j : piese)
                {
                    ch_to_int(a, b, j->Get_Position());
                    if (i == a && y == b)
                    {
                        cout << "Piesa " << Get_Name() << " este obstructionata de piesa " << j->Get_Name() << endl;
                        return false;
                    }
                }
        }
        else
            for (int i = X + 1; i < x; i++)
                for (auto j : piese)
                {
                    ch_to_int(a, b, j->Get_Position());
                    if (i == a && y == b)
                    {
                        cout << "Piesa " << Get_Name() << " este obstructionata de piesa " << j->Get_Name() << endl;
                        return false;
                    }
                }
        position = pos;
        return true;
    }
    if (abs(X - x) == abs(Y - y))
    {
        if (y < Y && x>X)
        {
            g = X + 1; h = Y - 1;
            while (g<x && h>y)
            {
                for (auto j : piese)
                {
                    ch_to_int(a, b, j->Get_Position());
                    if (g == a && h == b)
                    {
                        cout << "Piesa " << Get_Name() << " este obstructionata de piesa " << j->Get_Name() << endl;
                        return false;
                    }
                }
                g++; h--;
            }
        }
        if (y > Y && x < X)
        {
            g = X - 1; h = Y + 1;
            while (g > x && h < y)
            {
                cout << "plumber" << endl;
                for (auto j : piese)
                {
                    ch_to_int(a, b, j->Get_Position());
                    if (g == a && h == b)
                    {
                        cout << "Piesa " << Get_Name() << " este obstructionata de piesa " << j->Get_Name() << endl;
                        return false;
                    }
                }
                g--; h++;
            }
        }
        if (y < Y && x < X)
        {
            g = X - 1; h = Y - 1;
            while (g > x && h > y)
            {
                for (auto j : piese)
                {
                    ch_to_int(a, b, j->Get_Position());
                    if (g == a && h == b)
                    {
                        cout << "Piesa " << Get_Name() << " este obstructionata de piesa " << j->Get_Name() << endl;
                        return false;
                    }
                }
                g--; h--;
            }
        }
        if (y > Y && x > X)
        {
            g = X + 1; h = Y + 1;
            while (g < x && h < y)
            {
                for (auto j : piese)
                {
                    ch_to_int(a, b, j->Get_Position());
                    if (g == a && h == b)
                    {
                        cout << "Piesa " << Get_Name() << " este obstructionata de piesa " << j->Get_Name() << endl;
                        return false;
                    }
                }
                g++; h++;
            }
        }
        position = pos;
        return true;
    }
    return false;
}

Bishop::Bishop(string nume, string culoare, string position) {
    color = culoare;
    if (culoare == "black")
    {
        this->position = position;
        name = nume;
    }
    else
    {
        this->position = position;
        name = nume;
    }

}
bool Bishop::move(string pos, vector<piece*> piese) {
    if (pos == "ghost")
    {
        position = pos;
        return true;
    }
    if (position == "ghost")
    {
        position = pos;
        return true;
    }
    int x, y, X, Y, a, b, g, h;
    ch_to_int(x, y, pos);
    ch_to_int(X, Y, Get_Position());
    if (abs(X - x) == abs(Y - y))
    {
        if (y < Y && x>X)
        {
            g = X + 1; h = Y - 1;
            while (g<x && h>y)
            {
                for (auto j : piese)
                {
                    ch_to_int(a, b, j->Get_Position());
                    if (g == a && h == b)
                    {
                        cout << "Piesa " << Get_Name() << " este obstructionata de piesa " << j->Get_Name() << endl;
                        return false;
                    }
                }
                g++; h--;
            }
        }
        if (y > Y && x < X)
        {
            g = X - 1; h = Y + 1;
            while (g > x && h < y)
            {
                cout << "plumber" << endl;
                for (auto j : piese)
                {
                    ch_to_int(a, b, j->Get_Position());
                    if (g == a && h == b)
                    {
                        cout << "Piesa " << Get_Name() << " este obstructionata de piesa " << j->Get_Name() << endl;
                        return false;
                    }
                }
                g--; h++;
            }
        }
        if (y < Y && x < X)
        {
            g = X - 1; h = Y - 1;
            while (g > x && h > y)
            {
                for (auto j : piese)
                {
                    ch_to_int(a, b, j->Get_Position());
                    if (g == a && h == b)
                    {
                        cout << "Piesa " << Get_Name() << " este obstructionata de piesa " << j->Get_Name() << endl;
                        return false;
                    }
                }
                g--; h--;
            }
        }
        if (y > Y && x > X)
        {
            g = X + 1; h = Y + 1;
            while (g < x && h < y)
            {
                for (auto j : piese)
                {
                    ch_to_int(a, b, j->Get_Position());
                    if (g == a && h == b)
                    {
                        cout << "Piesa " << Get_Name() << " este obstructionata de piesa " << j->Get_Name() << endl;
                        return false;
                    }
                }
                g++; h++;
            }
        }
        position = pos;
        return true;
    }
    return false;
}

Knight::Knight(string nume, string culoare, string position) {
    color = culoare;
    if (culoare == "black")
    {
        this->position = position;
        name = nume;
    }
    else
    {
        this->position = position;
        name = nume;
    }
}
bool Knight::move(string pos, vector<piece*> piese) {
    if (pos == "ghost")
    {
        position = pos;
        return true;
    }
    if (position == "ghost")
    {
        position = pos;
        return true;
    }
    int x, y, X, Y;
    ch_to_int(x, y, pos);
    ch_to_int(X, Y, Get_Position());
    if (abs(Y - y) == 2 && (abs(X - x) == 1))
    {
        position = pos;
        return true;
    }
    else
        if (abs(X - x) == 2 && abs(Y - y) == 1)
        {
            position = pos;
            return true;
        }
    return false;
}

Rook::Rook(string nume, string culoare, string position) {
    color = culoare;
    if (culoare == "black")
    {
        this->position = position;
        name = nume;
    }
    else
    {
        this->position = position;
        name = nume;
    }
}
bool Rook::move(string pos, vector<piece*> piese) {
    if (pos == "ghost")
    {
        position = pos;
        return true;
    }
    if (position == "ghost")
    {
        position = pos;
        return true;
    }
    int x, y, X, Y, a, b;
    ch_to_int(x, y, pos);
    ch_to_int(X, Y, Get_Position());
    if (x == X)
    {
        if (y < Y)
        {
            for (int i = Y - 1; i > y; i--)
                for (auto j : piese)
                {
                    ch_to_int(a, b, j->Get_Position());
                    if (x == a && i == b)
                    {
                        cout << "Piesa " << Get_Name() << " este obstructionata de piesa " << j->Get_Name() << endl;
                        return false;
                    }
                }
        }
        else
            for (int i = Y + 1; i < y; i++)
                for (auto j : piese)
                {
                    ch_to_int(a, b, j->Get_Position());
                    if (x == a && i == b)
                    {
                        cout << "Piesa " << Get_Name() << " este obstructionata de piesa " << j->Get_Name() << endl;
                        return false;
                    }
                }
        position = pos;
        return true;
    }
    if (y == Y)
    {
        if (x < X)
        {
            for (int i = X - 1; i > x; i--)
                for (auto j : piese)
                {
                    ch_to_int(a, b, j->Get_Position());
                    if (i == a && y == b)
                    {
                        cout << "Piesa " << Get_Name() << " este obstructionata de piesa " << j->Get_Name() << endl;
                        return false;
                    }
                }
        }
        else
            for (int i = X + 1; i < x; i++)
                for (auto j : piese)
                {
                    ch_to_int(a, b, j->Get_Position());
                    if (i == a && y == b)
                    {
                        cout << "Piesa " << Get_Name() << " este obstructionata de piesa " << j->Get_Name() << endl;
                        return false;
                    }
                }
        position = pos;
        return true;
    }
    return false;
}

Pawn::Pawn(string nume, string culoare, string position) {
    color = culoare;
    if (culoare == "black")
    {
        this->position = position;
        name = nume;
    }
    else
    {
        this->position = position;
        name = nume;
    }
    has_moved = false;
    en_passant = false;
}

bool Pawn::move(string pos, vector<piece*> piese) {
    if (pos == "ghost")
    {
        position = pos;
        return true;
    }
    if (position == "ghost")
    {
        position = pos;
        return true;
    }
    int x, y, X, Y, a, b;
    exceptie1 e_p;
    ch_to_int(x, y, pos);
    ch_to_int(X, Y, Get_Position());
    if (color == "black")
    {
        if (has_moved == false)
        {
            if (y == Y - 2 && x == X)
            {
                for (auto i : piese)
                {
                    ch_to_int(a, b, i->Get_Position());
                    if (a == X && b == Y - 1 || a == X && b == Y - 2)
                    {
                        cout << "Piesa " << Get_Name() << " este obstructionata de piesa " << i->Get_Name() << endl;
                        return false;
                    }
                }
                en_passant = true;
                has_moved = true;
                position = pos;
                return true;
            }
        }
        if (y == Y - 1 && x == X)
        {
            for (auto i : piese)
            {
                ch_to_int(a, b, i->Get_Position());
                if (a == x && b == y)
                {
                    cout << "Piesa " << Get_Name() << " este obstructionata de piesa " << i->Get_Name() << endl;
                    return false;
                }
            }
            has_moved = true;
            en_passant = false;
            position = pos;
            return true;
        }
        else
            if (y == Y - 1)
            {
                if (x == X - 1)
                {
                    for (auto i : piese)
                    {
                        ch_to_int(a, b, i->Get_Position());
                        if (a == x && b == y)
                        {
                            has_moved = true;
                            en_passant = false;
                            position = pos;
                            return true;
                        }
                        else
                            if (a == x && b == 4)
                                if (i->return_type() == pawn && i->Get_EnPassant() == true)
                                {
                                    cout << "En Passant!\n";
                                    position = pos;
                                    return true;
                                }
                        //throw e_p;
                    }
                    return false;
                }
                if (x == X + 1)
                {
                    for (auto i : piese)
                    {
                        ch_to_int(a, b, i->Get_Position());
                        if (a == x && b == y)
                        {
                            has_moved = true;
                            en_passant = false;
                            position = pos;
                            return true;
                        }
                        else
                            if (a == x && b == 4)
                                if (i->return_type() == pawn && i->Get_EnPassant() == true)
                                {
                                    cout << "En Passant!\n";
                                    position = pos;
                                    return true;
                                }
                    }
                    return false;
                }
            }
    }
    else
        if (color == "white")
        {
            if (has_moved == false)
            {
                if (y == Y + 2 && x == X)
                {
                    for (auto i : piese)
                    {
                        ch_to_int(a, b, i->Get_Position());
                        if (a == X && b == Y + 1 || a == X && b == Y + 2)
                        {
                            cout << "Piesa " << Get_Name() << " este obstructionata de piesa " << i->Get_Name() << endl;
                            return false;
                        }
                    }
                    has_moved = true;
                    en_passant = true;
                    position = pos;
                    return true;
                }
            }
            if (y == Y + 1 && x == X)
            {
                for (auto i : piese)
                {
                    ch_to_int(a, b, i->Get_Position());
                    if (a == x && b == y)
                    {
                        cout << "Piesa " << Get_Name() << " este obstructionata de piesa " << i->Get_Name() << endl;
                        return false;
                    }
                    else
                        if (a == x && b == 5)
                            if (i->return_type() == pawn && i->Get_EnPassant() == true)
                            {
                                cout << "En Passant!\n";
                                position = pos;
                                return true;
                            }
                }
                has_moved = true;
                en_passant = false;
                position = pos;
                return true;
            }
            else
                if (y == Y + 1)
                {
                    if (x == X - 1)
                    {
                        for (auto i : piese)
                        {
                            ch_to_int(a, b, i->Get_Position());
                            if (a == x && b == y)
                            {
                                position = pos;
                                en_passant = false;
                                has_moved = true;
                                return true;
                            }
                            else
                                if (a == x && b == 5)
                                    if (i->return_type() == pawn && i->Get_EnPassant() == true)
                                    {
                                        cout << "En Passant!\n";
                                        position = pos;
                                        return true;
                                    }
                        }
                        return false;
                    }
                    if (x == X + 1)
                    {
                        for (auto i : piese)
                        {
                            ch_to_int(a, b, i->Get_Position());
                            if (a == x && b == y)
                            {
                                position = pos;
                                en_passant = false;
                                has_moved = true;
                                return true;
                            }
                            if (a == x && b == 5)
                                if (i->return_type() == pawn && i->Get_EnPassant() == true)
                                {
                                    cout << "En Passant!\n";
                                    position = pos;
                                    return true;
                                }
                        }
                        return false;
                    }
                }
        }
    return false;
}

Table::~Table() {
    this->table.clear();
}

void Table::operator+=(piece* piesa)
{
    table.push_back(piesa);
}

vector<piece*> Table::Get_Black_Pieces()
{
    vector<piece*> b;
    for (auto i : table)
        if (i->Get_Color() == "black")
            b.push_back(i);
    return b;
}

vector<piece*> Table::Get_White_Pieces()
{
    vector<piece*> w;
    for (auto i : table)
        if (i->Get_Color() == "white")
            w.push_back(i);
    return w;
}

vector<piece*> Table::Get_All_Pieces()
{
    vector<piece*> a;
    for (auto i : table)
        a.push_back(i);
    return a;
}

piece* Table::Get_Square_Piece(string pos)
{
    for (auto i : table)
    {
        if (i->Get_Position() == pos)
            return i;
        if (i->Get_Name() == "unidentified")
            return i;
    }
}

void Table::destroy(string pos)
{
    int k = 0;
    for (auto i : table)
    {
        if (i->Get_Position() == pos)
            table.erase(table.begin() + k);
        k++;
    }
}

piece* Table::Get_Pawn(string pos, string culoare)
{
    for (auto i : table)
    {
        if (i->return_type() == pawn && i->Get_Color() == culoare)
            if (i->Get_Position() == pos)
                return i;
    }
}

piece* Table::Get_Not_Pawn(string pos, string culoare)
{
    for (auto i : table)
    {
        if (i->return_type() != pawn && i->Get_Color() == culoare)
            if (i->Get_Position() == pos)
                return i;
    }
}

void Table::Set_En_Passant_To_False()
{
    for (auto i : table)
    {
        if (i->return_type() == pawn)
            i->False_EnPassant();
    }
}