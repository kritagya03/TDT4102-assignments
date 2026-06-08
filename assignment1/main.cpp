#include "std_lib_facilities.h"

//1a)
//def isFibonacciNymber(n):
//      a=0
//      b=1
//      while (b<n):
//          temp=b
//          b+=a
//          a=temp
//      return b==n

//2a)
double maxOfTwo(double a, double b) {
    if (a>b) {
        cout << "A is greater than B" <<endl;
        return a;
    } else {
        cout << "B is greater than or equal to A";
        return b;
    }
}

//2b)
//int main(){
//    cout << "Oppgave a) " << endl;
//    cout << maxOfTwo(3,2) << endl;
//
//    return 0;
//}

//2c)
int fibonacci(int n) {
    int a=0;
    int b=1;
    cout << "Fibonacci numbers:" <<endl;

    for (int i=1; i<n+1;i+=1) {
        cout <<i <<", " <<b <<endl;
        int temp=b;
        b+=a;
        a=temp;
    }

    cout <<"----" <<endl;
    return b; 
}

//2d)
int squareNumberSum(int n) {
    int totalSum =0;
    for (int i=1;i<n+1;i+=1) {
        totalSum+=i*i;
        cout << i*i <<endl;
    }
    cout << totalSum <<endl;
    return totalSum;
}

//2e)
void triangleNumbersBelow(int n) {
    int acc=1;
    int num=2;
    cout << "Triangle numbers below "
    <<n <<":" <<endl;
    while (acc<n) {
        cout << acc <<endl;
        acc+=num;
        num+=1;
    }
}

//2f)
bool isPrime(int n) {
    for (int j=2;j<n;j+=1) {
        if (n%j==0) {
            return false;}
    }
    return true;
}

//2g)
void naivePrimeNumberSearch(int n) {
    for (int number=2; number<n; number+=1) {
        if (isPrime(number)) {
            cout << number <<" is a prime" <<endl;}
    }
}

//2h)
void inputAndPrintNameAndAge() {
    string name;
    cout << "Skriv inn et navn: ";
    cin >> name;

    string age;
    cout << "Skriv inn alderen til " <<name <<": ";
    cin >>age;

    cout<< name <<" er " <<age <<" aar gamel.";
}


int main(){
    int k;
    k+=3;
    cout << "Oppgave c) " <<k << endl;
    fibonacci(5);

    return 0;
}

//------------------------------------------------------------------------------
