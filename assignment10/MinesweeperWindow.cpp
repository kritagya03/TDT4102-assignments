#include "MinesweeperWindow.h"
#include <iostream>
#include <random>
#include "widgets/TextInput.h"

MinesweeperWindow::MinesweeperWindow(int x, int y, int width, int height, int mines, const string &title) : 
	// Initialiser medlemsvariabler, bruker konstruktoren til AnimationWindow-klassen
	AnimationWindow{x, y, width * cellSize, (height + 1) * cellSize, title},
	width{width}, height{height}, mines{mines}, CountMines{mines}
{
	// Legg til alle tiles i vinduet
	for (int i = 0; i < height; ++i) {
		for (int j = 0; j < width; ++j) {
			tiles.emplace_back(new Tile{ Point{j * cellSize, i * cellSize}, cellSize});
			tiles.back()->setCallback(std::bind(&MinesweeperWindow::cb_click, this));
			auto temp = tiles.back().get();
			add(*temp); 
		}
	}

	add(GameState);

	// Legg til miner paa tilfeldige posisjoner
	std::random_device rd;
	std::default_random_engine generator (rd());
	std::uniform_int_distribution<int> dist (1,tiles.size());

	int i=mines;
	while (i!=0){
		int number=dist(generator);
		if (!tiles[number]->getisMine()){
			tiles[number]->setisMine(true);
			i--;
		}
	}

	add(GameOver);
	add(Restart);
	Restart.setCallback(std::bind(&MinesweeperWindow::cb_restart,this));
}

vector<Point> MinesweeperWindow::adjacentPoints(Point xy) const {
	vector<Point> points;
	for (int di = -1; di <= 1; ++di) {
		for (int dj = -1; dj <= 1; ++dj) {
			if (di == 0 && dj == 0) {
				continue;
			}

			Point neighbour{ xy.x + di * cellSize,xy.y + dj * cellSize };
			if (inRange(neighbour)) {
				points.push_back(neighbour);
			}
		}
	}
	return points;
}

int MinesweeperWindow::countMines(vector<Point> coords) const{
	int value=0;
	for (int i=0;i<coords.size();i++){
		shared_ptr<Tile> count = at(coords[i]);
		if (count->getisMine()){
			value++;
		}
	}
	return value;
}

void MinesweeperWindow::openTile(Point xy) {
	shared_ptr<Tile> change=at(xy);
	change->open();

	vector<Point> around = adjacentPoints(xy);
	if (!change->getisMine() && countMines(around)>0 && change->getState() != Cell::flagged){
		change->setAsjMines(countMines(around));
	
	} else if (!change->getisMine() && countMines(around)==0 && change->getState() != Cell::flagged){
		for (int i=0;i<around.size();i++){
			shared_ptr<Tile> check = at(around[i]);
			if (check->getState() == Cell::closed)
				openTile(around[i]);
		}
	}

	if (change->getisMine()){
		for (int i=0;i<tiles.size();i++){
			if (tiles[i]->getisMine()){
				tiles[i]->open();
			}
		}

		GameOver.setText("You Lost!");
		lost=true;
	}

	//if the amount of closed tiles is the same as the amount of closed tiles that have
	//mines in them, then the game is finished
	
	int AmountOfClosed = 0;
	int AlsoMines=0;
	for (int i=0;i<tiles.size();i++){
		if(tiles[i]->getState()==Cell::closed && !lost){
			AmountOfClosed++;
			if (tiles[i]->getisMine()){
				AlsoMines++;
			}
		}
	}

	if (AmountOfClosed==AlsoMines && !lost){
		for (int i=0;i<tiles.size();i++){
			if (tiles[i]->getisMine()){
				tiles[i]->setState(Cell::closed);
				tiles[i]->flag();
			}
		}
		GameState.setText("0 Bombs left");
		GameOver.setText("You Win!");
		lost=true;
	}
}

void MinesweeperWindow::cb_restart(){
	for (int i=0;i<tiles.size();i++){
		tiles[i]->setisMine(false);

		tiles[i]->setState(Cell::closed);
		tiles[i]->setButtonColor(TDT4102::Color::silver);
		tiles[i]->setLabel("");
	}

	CountMines=mines;
	GameState.setText(std::to_string(CountMines) + " Bombs left");

	std::random_device rd;
	std::default_random_engine generator (rd());
	std::uniform_int_distribution<int> dist (1,tiles.size());
	
	int i=mines;
	while (i!=0){
		int number=dist(generator);
		if (!tiles[number]->getisMine()){
			tiles[number]->setisMine(true);
			i--;
		}
	}

	GameOver.setText("You ...");

	lost=false;
}

void MinesweeperWindow::flagTile(Point xy) {
	shared_ptr<Tile> change=at(xy);
	change->flag();

	if (change->getState()==Cell::flagged){
		CountMines--;
		GameState.setText(std::to_string(CountMines) + " Bombs left");
	} else {
		CountMines++;
		GameState.setText(std::to_string(CountMines) + " Bombs left");
	}
}

//Kaller openTile ved venstreklikk og flagTile ved hoyreklikk
void MinesweeperWindow::cb_click() {
	
	Point xy{this->get_mouse_coordinates()};

	if (!inRange(xy)) {
		return;
	}
	if (this->is_left_mouse_button_down() && !lost) {
		openTile(xy);
	}
	else if(this->is_right_mouse_button_down() && !lost){
		flagTile(xy);
	}
}