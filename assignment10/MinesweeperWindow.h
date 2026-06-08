#pragma once
#include "AnimationWindow.h"
#include "Tile.h"
#include "widgets/TextInput.h"
#include "widgets/Button.h"
#include <string>

using namespace std;
using namespace TDT4102;

// Minesweeper GUI
class MinesweeperWindow : public AnimationWindow
{
public:
	// storrelsen til hver tile
	static constexpr int cellSize = 30;
	MinesweeperWindow(int x, int y, int width, int height, int mines, const string& title);
private:
	const int width;		// Bredde i antall tiles
	const int height;		// Hoyde i antall tiles
	const int mines;		// Antall miner
	vector<shared_ptr<Tile>> tiles; // Vektor som inneholder alle tiles

	// hoyde og bredde i piksler
	int Height() const { return height * cellSize; } 
	int Width() const { return width * cellSize; }

	// Returnerer en vektor med nabotilene rundt en tile, der hver tile representeres som et punkt
	vector<Point> adjacentPoints(Point xy) const;

	// tell miner basert paa en liste tiles
	int countMines(vector<Point> coords) const;

	// Sjekker at et punkt er paa brettet
	bool inRange(Point xy) const { return xy.x >= 0 && xy.x< Width() && xy.y >= 0 && xy.y < Height(); }

	// Returnerer en tile gitt et punkt
	shared_ptr<Tile>& at(Point xy) { return tiles[xy.x / cellSize + (xy.y / cellSize) * width]; }
	const shared_ptr<Tile>& at(Point xy) const { return tiles[xy.x / cellSize + (xy.y / cellSize) * width]; }

    //aapne og flagge rute
	void openTile(Point xy);
	void flagTile(Point xy);

	// callback funksjoner til Tile knappene
	void cb_click();

	int CountMines;

	TDT4102::TextInput GameState{{0,cellSize*height},
	static_cast<unsigned int>(30*4.35),cellSize, std::to_string(CountMines) + " Bombs left"};
	
	TDT4102::TextInput GameOver{{30*5,cellSize*height},
	static_cast<unsigned int>(30*3.5),cellSize,"You ..."};

	TDT4102::Button Restart{{30*5+30*4,cellSize*height}, 40, cellSize, "R"};
	
	void cb_restart();

	bool lost=false;
};
