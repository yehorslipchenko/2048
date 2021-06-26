//
//  point.hpp
//  2048
//
//  Created by Егор Слипченко on 23.04.2021.
//

#ifndef point_hpp
#define point_hpp
#include <stdio.h>

class point{
    int x = 0;
    int y = 0;
public:
    point(int x, int y){
        this->x = x;
        this->y = y;
    }
    int GetX(){return x;}
    int GetY(){return y;}
    void SetX(int x){this->x = x;}
    void SetY(int y){this->y = y;}
};
#endif /* point_hpp */
