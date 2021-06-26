//
//  player.cpp
//  2048
//
//  Created by Егор Слипченко on 08.04.2021.
//

#include "player.hpp"

int player::getch(){
    struct termios oldt,
    newt;
    int ch;
    tcgetattr( STDIN_FILENO, &oldt );
    newt = oldt;
    newt.c_lflag &= ~( ICANON | ECHO );
    tcsetattr( STDIN_FILENO, TCSANOW, &newt );
    ch = getchar();
    cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
    tcsetattr( STDIN_FILENO, TCSANOW, &oldt );
    return ch;
 }

void player::retry_step(){
    cout << "\n\t\t You must use only WASD key!\n\t\t";
}

void player::shift_up(int (*lg_field)[SIZE], bool &check){
    
    for (int col = 0; col<SIZE; col++) {
    
        for (int j = 0; j<SIZE; j++) {
            for (int e = 0; e<SIZE-1; e++) {
                if (lg_field[e][col] == 0) {
                    lg_field[e][col] = lg_field[e+1][col];
                    lg_field[e+1][col] = 0;
                }
            }
        }
        
        
        for (int i = 0; i<SIZE-1; i++) {
            if (lg_field[i][col] == lg_field[i+1][col]){
                lg_field[i][col] *= 2;
                lg_field[i+1][col] = 0;
                check = true;
            }
        }
        
        for (int j = 0; j<SIZE; j++) {
            for (int e = 0; e<SIZE-1; e++) {
                if (lg_field[e][col] == 0) {
                    lg_field[e][col] = lg_field[e+1][col];
                    lg_field[e+1][col] = 0;
                }
            }
        }
    }
}

void player::shift_left(int (*lg_field)[SIZE], bool &check){
    
    for (int row = 0; row<SIZE; row++) {
        
        for (int i = 0; i<SIZE; i++) {
            for (int col = 0; col<SIZE-1; col++) {
                if (lg_field[row][col] == 0) {
                    lg_field[row][col] = lg_field[row][col+1];
                    lg_field[row][col+1] = 0;
                }
            }
        }
        
        for (int i = 0; i<SIZE-1; i++) {
            if (lg_field[row][i] == lg_field[row][i+1]) {
                lg_field[row][i] *=2;
                lg_field[row][i+1] = 0;
                check = true;
            }
        }
        
        for (int i = 0; i<SIZE; i++) {
            for (int col = 0; col<SIZE-1; col++) {
                if (lg_field[row][col] == 0) {
                    lg_field[row][col] = lg_field[row][col+1];
                    lg_field[row][col+1] = 0;
                }
            }
        }
        
    }
    
}

void player::shift_down(int (*lg_field)[SIZE], bool &check){
    for (int col = 0; col<SIZE; col++) {
        
        for (int i = 0; i<SIZE; i++) {
            for (int j = SIZE-1; j>0; j--) {
                if (lg_field[j][col] == 0) {
                    lg_field[j][col] = lg_field[j-1][col];
                    lg_field[j-1][col] = 0;
                }
            }
        }
        
        for (int i = SIZE-1; i>0; i--) {
            if (lg_field[i][col] == lg_field[i-1][col]){
                lg_field[i][col] *= 2;
                lg_field[i-1][col] = 0;
                check = true;
            }
        }
        
        for (int i = 0; i<SIZE; i++) {
            for (int j = SIZE-1; j>0; j--) {
                if (lg_field[j][col] == 0) {
                    lg_field[j][col] = lg_field[j-1][col];
                    lg_field[j-1][col] = 0;
                }
            }
        }
        
    }
}

void player::shift_right(int (*lg_field)[SIZE], bool &check){
    
    for (int row = 0; row<SIZE; row++) {
        
        for (int i = 0; i<SIZE; i++) {
            for (int j = SIZE-1; j>0; j--) {
                if (lg_field[row][j] == 0) {
                    lg_field[row][j] = lg_field[row][j-1];
                    lg_field[row][j-1] = 0;
                }
            }
        }
        
        for (int i = SIZE-1; i>0; i--) {
            if (lg_field[row][i] == lg_field[row][i-1]){
                lg_field[row][i] *= 2;
                lg_field[row][i-1] = 0;
                check = true;
            }
        }
        
        for (int i = 0; i<SIZE; i++) {
            for (int j = SIZE-1; j>0; j--) {
                if (lg_field[row][j] == 0) {
                    lg_field[row][j] = lg_field[row][j-1];
                    lg_field[row][j-1] = 0;
                }
            }
        }
        
    }
}

bool player::get_poss_step(int (*lg_field)[SIZE]){
    bool _pos_step = false;
    int range = 2;
    int start_pos = 0;
    vector<int> first_row, second_row, first_col, second_col;
    for (int i = 0; i<SIZE-1; i++) {
        
        for (int a = start_pos; a<range; a++) {
            for (int b = 0; b<SIZE; b++) {
                if (a == start_pos) {
                    first_row.push_back(lg_field[a][b]);
                }else{
                    second_row.push_back(lg_field[a][b]);
                }
            }
        }
        
        for (int c = 0; c<SIZE; c++) {
            if (first_row[c] == second_row[c]) {
                _pos_step = true;
            }
        }
        if(_pos_step) break;
        start_pos++;
    }
    
    start_pos = 0;
    
    for (int i = 0; i<SIZE-1; i++) {
        
        for (int a = start_pos; a<range; a++) {
            for (int b = 0; b<SIZE; b++) {
                if (a==start_pos) {
                    first_col.push_back(lg_field[b][a]);
                }else{
                    second_col.push_back(lg_field[b][a]);
                }
            }
        }
        
        for (int k = 0; k<SIZE; k++) {
            if (first_col[k] == second_col[k]) {
                _pos_step = true;
            }
        }
        if(_pos_step) break;
        start_pos++;
    }
    
    return _pos_step;
}
bool player::step(int (*lg_field)[SIZE]){
    
    int set_key = getch();
    bool check_step = false;
    
    switch (set_key) {
        case 119:
            shift_up(lg_field, check_step);
            break;
        case 97:
            shift_left(lg_field,check_step);
            break;
        case 115:
            shift_down(lg_field,check_step);
            break;
        case 100:
            shift_right(lg_field,check_step);
            break;

        default:
            retry_step();
            check_step = false;
            break;
    }

        return check_step;

    
}
