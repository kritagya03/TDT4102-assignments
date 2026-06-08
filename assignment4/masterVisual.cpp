#include "masterVisual.h"
#include "Mastermind.h"
#include "utilities.h"

void playMastermindVisual(){
	constexpr int size=4;
    constexpr int letters=6;
    string code;
    string guess="    ";
	char startLetter = 'A';
    
    int lives=6;
    int gameOver=0;
    while (gameOver==0){
        code=randomizeString(size, 'A'+(letters-1),'A');
        cout << code << endl;
		MastermindWindow mwin{900, 20, winW, winH, size, "Mastermind"};
        while (checkCharactersAndPosition(code,guess) != 4 && lives!=0) {
            cout << "You have " << lives << " lives left\n";
            guess=mwin.getInput(size, 'A'+(letters-1), 'A');
			addGuess(mwin,code,startLetter);

            cout << "You have " << checkCharactersAndPosition(code, guess)
            << " letters in the correct position\n";
            cout << "You guessed " << checkCharacters(code, guess) 
            << " letters correctly\n";
            lives-=1;
            }

    string answer;
    if (checkCharactersAndPosition(code,guess) == 4){
        cout << "Congratulations! Would you like to play again?(Y/N) ";
        cin >> answer;
        } else {
        cout << "You lost :(. Would you like to play again?(Y/N) ";
        cin >> answer;
        }

    if (answer=="N"){
        gameOver=1;
    } else {
        guess="    ";
        lives=10;
    }
    }
}

void addGuess(MastermindWindow &mwin, const string code, const char startLetter)
{
	Guess g{code,startLetter};
	mwin.guesses.push_back(g);
	//cout << mwin.guesses.at(0).startLetter;

}

void addFeedback(MastermindWindow &mwin, const int correctPosition, const int correctCharacter)
{
	// implementer addFeedback
}

void MastermindWindow::drawCodeHider()
{
	if (code_hidden) {
		draw_rectangle(Point{padX, 3 * padY}, winW - size * padX, padY, Color::black);
	}
}

MastermindWindow::MastermindWindow(int x, int y, int w, int h, int size, const string &title) 
: AnimationWindow(x, y, w, h, title),
guessBtn{{upperLeftCornerBtn.x, upperLeftCornerBtn.y}, btnW, btnH, "Add"},
guess{{upperLeftCornerInBox.x, upperLeftCornerInBox.y}, inBoxW, inBoxH, ""},
size(size)
{
	add(guess);
	add(guessBtn);
	guessBtn.setCallback(std::bind(&MastermindWindow::cb_guess, this));
};

void MastermindWindow::drawGuessesAndFeedbacks()
{
	std::map<int, Color> colorConverter{
		{1, Color::red},
		{2, Color::green},
		{3, Color::yellow},
		{4, Color::blue},
		{5, Color::blue_violet},
		{6, Color::dark_cyan}};

	for (int guessIndex = 0; guessIndex < static_cast<int>(guesses.size()); guessIndex++)
	{     //Hvordan skal jeg iterer

		// Implementer funksjonalitet slik at det vises fargede rektangler i grafikkvinduet
		// Tegn gjettet som ligger på plassen guessIndex i vektoren guesses.
		for (int i = 0; i < size; i++)
		{
			// Tegn rektangler ved bruk av draw_rectangle(). Bruk: colorConverter.at() for å få riktig farge

		}
	}

	for (int feedbackIndex = 0; feedbackIndex < static_cast<int>(feedbacks.size()); feedbackIndex++)
	{
		// Implementer feedback

		for (int i = 0; i < size; i++)
		{
			// Tegn sirkler ved hjelp av draw_circle().

		}
	}
}

string MastermindWindow::wait_for_guess()
{

	while (!button_pressed && !should_close())
	{
		drawGuessesAndFeedbacks();
		// Burde tegnes sist siden den skal ligge på toppen
		drawCodeHider();

		next_frame();
	}
	button_pressed = false;

	string newGuess = guess.getText();
	guess.setText("");

	return newGuess;
}

string MastermindWindow::getInput(unsigned int n, char lower, char upper)
{
	bool validInput = false;
	string guess;
	while (!validInput && !should_close())
	{
		guess.clear();
		string input = wait_for_guess();
		if (input.size() == n)
		{
			for (unsigned int i = 0; i < n; i++)
			{
				char ch = input.at(i);
				if (isalpha(ch) && toupper(ch) <= upper && lower <= toupper(ch))
				{
					guess += toupper(ch);
				}
				else
					break;
			}
		}
		if (guess.size() == n)
		{
			validInput = true;
		}
		else
		{
			cout << "Invalid input guess again" << endl;
		}
	}
	return guess;
}

void MastermindWindow::setCodeHidden(bool hidden) {
	code_hidden = hidden;
}
