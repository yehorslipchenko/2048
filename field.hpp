#ifndef field_hpp
#define field_hpp

#include <stdio.h>
#include <iostream>
#include <ctime>
#include "player.hpp"
#include "point.hpp"
#define SIZE 4
using namespace std;

class field{
    
private:
    int getch();
    int logic_field [SIZE] [SIZE];
    int new_elem();
    void show();
    void set_af_step(int (*lg_field)[SIZE]);
    void end_game(bool &ch);
public:
    field();
    void game();
};
#endif /* field_hpp */
