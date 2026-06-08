#include "Tile.h"
#include <string>


// For aa sette Tilelabel i henhold til state
const std::map<Cell, std::string> cellToSymbol{{Cell::closed, ""},
									 			{Cell::open, ""},
									 	  		{Cell::flagged, "|>"}};

Tile::Tile(TDT4102::Point pos, int size) : 
	Button({pos.x, pos.y}, 1.5*size, size, "") {
		setButtonColor(TDT4102::Color::silver);
	}

void Tile::open()
{
	if (state==Cell::closed){
		state=Cell::open;
		setButtonColor(TDT4102::Color::white);
		if (isMine==true){
			set_label("X");
			set_label_color(TDT4102::Color::red);
		}
	}
}

void Tile::flag()
{
	if (state==Cell::closed){
		state=Cell::flagged;
		set_label("|>");
		set_label_color(TDT4102::Color::deep_pink);
	} else if (state==Cell::flagged){
		state=Cell::closed;
		set_label("");
	}
}

void Tile::setAsjMines(int n){
	set_label(std::to_string(n));
	set_label_color(minesToColor.at(n));
}