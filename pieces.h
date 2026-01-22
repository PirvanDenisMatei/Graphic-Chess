#include <iostream>
#include <SFML/Graphics.hpp>
#include <vector>
using namespace std;

enum piece_type {
    queen, king, bishop, knight, rook, pawn, nothing
};

class piece {
protected:
    string color, name, position;
    sf::Texture piece_texture;
    sf::Sprite piece_sprite;
public:
    piece() {}
    string Get_Name();
    string Get_Color();
    string Get_Position();
    sf::Sprite Get_Sprite();
    void Remove_Sprite();
    virtual bool move(string pos, vector<piece*> piese) = 0;
    virtual piece_type return_type() = 0;
    virtual void False_EnPassant() = 0;
    virtual bool Get_EnPassant() = 0;
};

class Table {
    vector<piece*> table;
public:
    ~Table();
    vector<piece*> Get_White_Pieces();
    vector<piece*> Get_Black_Pieces();
    vector<piece*> Get_All_Pieces();
    piece* Get_Pawn(string pos, string culoare);
    piece* Get_Not_Pawn(string pos, string culoare);
    piece* Get_Square_Piece(string pos);
    void Set_En_Passant_To_False();
    void destroy(string pos);
    void operator+=(piece* piesa);
};

class emptyness : public piece {
public:
    emptyness();
    bool move(string pos, vector<piece*> piese) override;
    piece_type return_type() override {
        return nothing;
    }
    void False_EnPassant() {}
    bool Get_EnPassant() { return 0; }
};

class King : public piece {
public:
    King(string culoare, string position);
    bool move(string pos, vector<piece*> piese) override;
    piece_type return_type() override {
        return king;
    }
    void False_EnPassant() {}
    bool Get_EnPassant() { return 0; }
};

class Queen :public piece {
public:
    Queen(string culoare, string position);
    bool move(string pos, vector<piece*> piese) override;
    piece_type return_type() override {
        return queen;
    }
    void False_EnPassant() {}
    bool Get_EnPassant() { return 0; }
};

class Bishop :public piece {
public:
    Bishop(string nume, string culoare, string position);
    bool move(string pos, vector<piece*> piese) override;
    piece_type return_type() override {
        return bishop;
    }
    void False_EnPassant() {}
    bool Get_EnPassant() { return 0; }
};

class Knight :public piece {
public:
    Knight(string name, string culoare, string position);
    bool move(string pos, vector<piece*> piese) override;
    piece_type return_type() override {
        return knight;
    }
    void False_EnPassant() {}
    bool Get_EnPassant() { return 0; }
};

class Rook :public piece {
public:
    Rook(string name, string culoare, string position);
    bool move(string pos, vector<piece*> piese) override;
    piece_type return_type() override {
        return rook;
    }
    void False_EnPassant() {}
    bool Get_EnPassant() { return 0; }
};

class Pawn :public piece {
    bool has_moved, en_passant;
public:
    Pawn(string name, string culoare, string position);
    bool move(string pos, vector<piece*> piese) override;
    piece_type return_type() override {
        return pawn;
    }
    void False_EnPassant() { en_passant = 0; }
    bool Get_EnPassant() { return en_passant; }
};
