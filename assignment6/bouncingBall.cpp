#include "std_lib_facilities.h"
#include "AnimationWindow.h"
#include "Color.h"
#include "bouncingBall.h"

istream& operator>>(istream& is, Config& cfg){
    // int save1;
    // int save2;
    // int save3;

    // string save;
    // if (cfg.ColorUp==1){
    //     cout << "hi";
    //     getline(is, save);
    // }
    // getline(is, save);
    // string part;
    // stringstream str;
    // str << save;
    // while (getline(str, part, ',')){
    //     save1=save2;
    //     save2=save3;
    //     save3=stoi(part);
    // }

    // cfg.ColorUp=save1;
    // cfg.ColorDown=save2;
    // cfg.BallSpeed=save3;
    is >> cfg.BallSpeed >> cfg.ColorDown >> cfg.ColorUp;
    

    return is;
}

constexpr Point BOUNCE_WINDOW_TOP_LEFT{50, 50};
constexpr int BOUNCE_WINDOW_WIDTH{800}; 
constexpr int BOUNCE_WINDOW_HEIGHT{500};



void bouncingBall() {
    AnimationWindow window{BOUNCE_WINDOW_TOP_LEFT.x, BOUNCE_WINDOW_TOP_LEFT.y, 
                           BOUNCE_WINDOW_WIDTH, BOUNCE_WINDOW_HEIGHT, "Bouncing ball"};
    
    const int radius{30};
    int alpha{1};
    int velocity{2};
    Color colour_up{Color::blue};
    Color colour_down{Color::blue};
    int x{0};
    int y{360};
    int increment_x{0};
    int increment_y{0};
    int count_bounce_top{0};
    int count_bounce_bottom{0};
    int count_num_passes{0};

    // read from configuration file
    Config ballInfo;

    // initialise the run
    filesystem::path config_file{"konfigurasjon.txt"};
    Config BallInfoFast;
    Config BallInfoSlow;
    ifstream is{config_file};
    is >> BallInfoSlow >> BallInfoFast;

    string a;
    string b;

    cin >> a >> b;


    velocity=BallInfo.BallSpeed;
    Color fillcolor = aColor.at(BallInfo.ColorUp);

    while (!window.should_close()) {

        Point centre{x,y};
        window.draw_circle(centre, 30, fillcolor);

        // determine increments based on the velocity
        increment_x = velocity * cos(alpha);
        increment_y = velocity * sin(alpha);

        // movement i x-direction
        if ((increment_x + x) > window.width()) {
            // reached right side - wrap around to the leftmost
            x = 0;
            // increment counter which counts number of full left-to-right passes
            count_num_passes++;
            // alternate between slow and fast configuration every fifth pass
            if (count_num_passes % 2 == 0) {
                // change configuration
                // update both velcity and colors
                // ifstream is{config_file};
                // is >> BallInfo;
                // velocity=BallInfo.BallSpeed;
                // fillcolor= aColor.at(BallInfo.ColorUp);
                if (velocity == BallInfoFast.BallSpeed) {
                    velocity
                }
            }
        } else {
            // moving rightwards
            x += increment_x;
        }

        // movement i y-direction
        if (((count_bounce_top + count_bounce_bottom) % 2) == 0) {
            // move upwards
            y-=increment_y;
            if (y<=0){
                count_bounce_top++;
                fillcolor= aColor.at(BallInfo.ColorDown);
            }
        } else {
            // move downward
            y+=increment_y;
            if (y>window.height()){
                count_bounce_bottom++;
                fillcolor= aColor.at(BallInfo.ColorUp);
            }
        }
    
        window.next_frame();
    }
}

