//
//  player.hpp
//  2048
//
//  Created by Егор Слипченко on 08.04.2021.
//

#ifndef player_hpp
#define player_hpp

#include <stdio.h>
#include <iostream>
#include <termios.h>
#include <unistd.h>
#include <vector>
#define SIZE 4
using namespace std;

class player{
    
private:
    unsigned long int score = 0;
    unsigned long int best_score = 0;
    
    int getch();
    
    void shift_up(int (*lg_field)[SIZE], bool &check);
    void shift_left(int (*lg_field)[SIZE], bool &check);
    void shift_down(int (*lg_field)[SIZE], bool &check);
    void shift_right(int (*lg_field)[SIZE], bool &check);
    void retry_step();
    
public:
    bool get_poss_step(int (*lg_field)[SIZE]);
    bool step(int (*lg_field)[SIZE]);
};

#endif /* player_hpp */
