#include "std_lib_facilities.h"

void inputAndPrintInteger() {
    string number;
    cout << "Write a whole number ";
    cin >> number;
    cout << "You wrote " << number <<endl;
}


int inputInteger(){
    string number;
    cout <<"Write a whole number ";
    cin >> number;
    return stoi(number);
}


void inputIntegersAndPrintSum(){
    int n1=inputInteger();
    int n2=inputInteger();

    cout << "The sum: " << n1+n2 <<endl;
}


//Jeg valgte å bruke inputInteger() fordi det returnerer integer


bool isOdd(int n){
    return n % 2 == 0;
}


//------------------------------------------------------------------------------


void summation() {
    int howMuch;
    cout << "how many numbers do you want to add? ";
    cin >> howMuch;

    int sum=0;

    for (int i=0; i<howMuch; i++) {
        int number=inputInteger();
        sum+=number;
    }

    cout <<"The sum is " <<sum;
}


void summation2() {

    int number=1;
    int sum=0;
    while(number!=0) {
        int value=inputInteger();
        number=value;
        sum+=value;
    }

    cout <<"The sum of those numbers are" << sum;
}


/*for a) er det best å bruke en for-løkker fordi vi veit hvor mange ganger løkken
skal loop, men for b) er vi ikke sikker så vi bruker en while-løkke*/

double inputDouble(){
    string number;
    cout <<"Write a decimal number ";
    cin >> number;
    return stod(number);
}


void ToEU(){
    cout << "How much money do you have in NOK?" <<endl;
    double NOK=inputDouble();
    while (NOK<0) {
        cout << "How much money do you have in NOK?" <<endl;
        NOK=inputDouble();
    }

    double EU=NOK*0.088;
    cout << fixed << setprecision(2);
    cout << "You have this much money in EUR: " << EU <<endl;;
}


/*Jeg brukte inputDouble fordi vi nå jobbet med decimltall og ikke
heltall. Funksjonstypen til selve funksjonen er void fordi jeg
ikke returnerer noe*/


void Gangetabell(){
    int width;
    int hight;
    cout << "Enter width ";
    cin >> width;
    cout << "Enter hight ";
    cin >> hight;

    for (int i=0; i<hight; i+=1){
        for (int j=0; j<width; j+=1){
            cout << (i+1)*(j+1) <<setw(5);
            }
        cout <<"" <<endl;
    }
}


//------------------------------------------------------------------------------

double inTheRoot(double a, double b, double c){
    double result = pow(b,2) - 4*a*c;
    return result;
}

void printRealRoots(double a, double b, double c){
    
    if (inTheRoot(a,b,c)>0){
        double solution1=(-b+sqrt(inTheRoot(a,b,c)))/2*a;
        double solution2=(-b-sqrt(inTheRoot(a,b,c)))/2*a;

        cout<<solution1 <<" and " <<solution2;
    } else if (inTheRoot(a,b,c)==0) {
        double solution1=-b/2*a;
        
        cout << solution1;
    } else {
        cout << "There are no answers";
    }
}

void solveQuadraticEquation(double a, double b, double c){
    cout << "The solution(s) to " << a << "x**2 +"
    <<b <<"x +" <<c <<" = 0" <<" are:" <<endl;

    printRealRoots(a, b, c);
    cout << "" <<endl;
}

//1) No answers
//2) -8
//3) 11.71 and -43.71

//------------------------------------------------------------------------------

#include"AnimationWindow.h"

void Pythagoras(){
    cout << "Hello, World!" << endl;
    AnimationWindow win{50,50, 1000,900, "Pythagoras"};
    win.draw_triangle({350,250}, {350,450}, {650,450}, Color::red);
    win.draw_quad({350,250}, {350,450}, {150,450}, {150, 250}, Color::blue);
    win.draw_quad({350,450}, {650,450}, {650,650}, {350, 650}, Color::green);
    win.draw_quad({350,250}, {650,450}, {850,145}, {550, 0}, Color::yellow);

    win.wait_for_close();
}

//------------------------------------------------------------------------------

vector<int> calculateBalance(int innskudd, int rente, int aar){
    vector <int>saldoer = {};
    for (int i=0; i<aar+1; i++) {
        double saldo = innskudd*pow((1+double(rente)/100),i);

        int Hsaldo=int(saldo);

        saldoer.push_back(Hsaldo);
    }

    for (int j=0; j<saldoer.size(); j++){
        cout<< "For year " <<j <<": ";
        cout << saldoer.at(j) <<endl;
    }

    return saldoer;
}

void printBalance (vector <int>Yinfo){
    cout  <<left <<setw(10) << "AAr" <<"Saldo" << endl;
    for (int i=0; i<Yinfo.size(); i++){
        cout << left <<setw(10) <<i <<Yinfo.at(i) <<endl; 
    }
}

//Feilen kan skyldes at det ikke er mulig å visualisere vectoren i terminalen

//Feilen ligger i at funksjonen prøver å kalle en 9'ende index som ikke eksisterer 

void menu() {
	while (1) {
        cout << "" <<endl;
		cout << "Menu\n"
			<< "1.\t inputAndPrintInteger\n"
			<< "2.\t inputInteger\n"
			<< "3.\t inputIntegersAndPrintSum\n"
			<< "4.\t isOdd\n"
			<< "5.\t NOK to EURO\n"
            << "6.\t Gangetabell\n"
            << "7.\t solveQuadraticEquation\n" 
            << "8.\t Pythagoras\n"
            << "9.\t printBalance\n"
			<< "Input: ";

		int menu_choice;
		cin >> menu_choice;
		
		switch (menu_choice)
		{
		case 1:
			inputAndPrintInteger();
			break;
		case 2:
			cout<<inputInteger();
			break;
		case 3:
			inputIntegersAndPrintSum();
			break;
		case 4:
            for (int i=0; i<16; i++){
                cout << i <<" " << (isOdd(i) ? "true" : "false") <<endl;
            }
			break;
        case 5:
            ToEU();
            break;
        case 6:
            Gangetabell();
            break;
        case 7:
            double first;
            cout << "a: ";
            cin >> first;

            double second;
            cout <<"b: ";
            cin>>second;

            double third;
            cout <<"c: ";
            cin >> third;
            solveQuadraticEquation(first, second, third);
            break;
        case 8:
            Pythagoras();
            break;
        case 9:
            int inn;
            cout <<"innskudd: ";
            cin >>inn;

            int ren;
            cout<< "rente: ";
            cin >>ren;

            int aa;
            cout <<"Aar: ";
            cin >> aa;

            printBalance (calculateBalance(inn, ren, aa));
            break;
		default:
			return; // quit program
			break;
		}
	}
}


int main() {
    menu();
    std::cout << std::fixed << std::setprecision(2);
    
    cout << double(1) << " ";
    std::cout << 2.189128 << " ";
    std::cout << 2.989218 << " ";
    std::cout << 3.09301 << " ";

    std::cout.unsetf(std::ios::fixed);
    std::cout << 4.87329392;

    return 0;
}

//------------------------------------------------------------------------------
