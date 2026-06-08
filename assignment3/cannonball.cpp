#include "cannonball.h"
#include "utilities.h"
#include "std_lib_facilities.h"


double acclY(){
    return -9.81;
};

double velY(double initVelocity, double time){
    return initVelocity + acclY()*time; 
};

double PosX(double initPositionX, double initVelocityX, double time){
    return initPositionX +
    initVelocityX*time;
}

double PosY(double initPositionY, double initVelocityY, double time){
    return initPositionY+
    initVelocityY*time+
    (acclY()*pow(time,2))/2;
}

void printTime(double time){
    cout << "sekunder: " << time <<"\n";
    cout << "minutter " << time/60<<"\n";
    cout << "timer " << (time/60)/60 <<"\n";
}

double flightTime(double initVelocityY){
    return (-2*initVelocityY)/acclY();
}



//Posisjon = StartPosisjonX/Y + StartFartX/Y · Tid +(AkselerasjonX/Y · Tid**2/2)

// Ber brukeren om en vinkel i grader
double getUserInputTheta(){
    double result;
    cout << "what angle? ";
    cin >> result;
    return result;
}

//Ber brukeren om en startfart
double getUserInputInitVelocity(){
    double result;
    cout <<"What speed? ";
    cin >>result;
    return result;
}

// Konverterer fra grader til radianer
double degToRad(double deg){
    return deg*M_PI/180;
}

// Returnerer henholdsvis farten i x-, og y-retning, gitt en vinkel
// theta i grader og en startfart initVelocity.
double getVelocityX(double theta, double initVelocity){
    return initVelocity*cos(degToRad(theta));
}

double getVelocityY(double theta, double initVelocity){
    return initVelocity*sin(degToRad(theta));
}
// Dekomponerer farten gitt av initVelocity, i x- og y-komponentene
// gitt vinkelen theta. Det første elementet i vectoren skal være
//x-komponenten, og det andre elementet skal være y-komponenten.
// "Vector" i funksjonsnavnet er vektor-begrepet i geometri
vector<double> getVelocityVector(double theta, double initVelocity){
    vector<double>v={};
    v.push_back(getVelocityX(theta,initVelocity));
    v.push_back(getVelocityY(theta,initVelocity));
    return v;
}

void printVector(vector<double> v){
    for (int i=0;i<v.size();i++){
        cout << v.at(i) <<endl;
    }
}

double getDistanceTraveled(double velocityX, double velocityY){
   return PosX(0,velocityX, flightTime(velocityY));
}

double targetPractice(double distanceToTarget, 
double velocityX, double velocityY){
    return distanceToTarget-getDistanceTraveled(velocityX,velocityY);
}

//----------------------------------------------------------------------------//

void playTargetPractice(){
    int target=randomWithLimits(100, 1000);
    cout << "Your target is " <<target <<"m away\n";
    for (int i=0; i<10;i++) {
        cout << "You have " <<10-i <<" attempts left \n";
        cout << "Which angle do you wish to shoot the ball at? \n";
        double angle;
        cin>> angle;
        cout << "At what speed do you wish to shoot the ball at?(m/s) \n";
        double speed;
        cin>> speed;

        vector<double> Ball0=getVelocityVector(angle, speed);
        double speedX=Ball0.at(0);
        double speedY=Ball0.at(1);

        if (abs(targetPractice(target,speedX,speedY))<1.5){
            cout <<"Congratulations you hit the target!";
            break;
        }

        if (targetPractice(target, speedX, speedY)>0){
            cout<< "You shot " << targetPractice(target, speedX, speedY)
        << "m too close from the target \n";} 
        else{
            cout <<"You shot " << targetPractice(target, speedX, speedY)*(-1)
        << "m too far away from the target \n";}

        double airTime=flightTime(speedY);
        cout<< "the ball was in the air for "<<airTime <<"s \n";
    }
}