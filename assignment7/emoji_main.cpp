#include "AnimationWindow.h"
#include "std_lib_facilities.h"
#include "Emoji.h"

// Definer størrelse på vindu og emoji
constexpr int xmax = 1000;
constexpr int ymax = 600;
constexpr int emojiRadius = 50;

int main()
{
	const Point tl{100, 100};
	const string win_label{"Emoji factory"};
	AnimationWindow win{tl.x, tl.y, xmax, ymax, win_label};

	EmptyFace face1({150,150},100,{50,20},20);
	face1.draw(win);
	
	SmilingFace face2({350,150},100,{50,20},20,225,315);
	face2.draw(win);

	SadFace face3({550,150},100,{50,20},20,45,135);
	face3.draw(win); //Hvordan kan jeg bruke SmilingFace?

	win.wait_for_close();

	return 0;
}
