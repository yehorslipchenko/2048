#include "field.hpp"


int field::getch(){
    struct termios oldt,
    newt;
    int ch;
    tcgetattr( STDIN_FILENO, &oldt );
    newt = oldt;
    newt.c_lflag &= ~( ICANON | ECHO );
    tcsetattr( STDIN_FILENO, TCSANOW, &newt );
    ch = getchar();
    tcsetattr( STDIN_FILENO, TCSANOW, &oldt );
    return ch;
 }


int field::new_elem(){

    int new_number = 0;
    srand(time(0));
    
    int check = rand()%101;
        if (check <= 10) {
            new_number = 4;
        }else new_number = 2;
    
    return new_number;
}

field::field(){
    
    for (int i = 0; i<SIZE; i++) {
        for (int j = 0; j<SIZE; j++) {
            logic_field[i][j] = 0;
        }
    }
    srand(time(0));
    int pos_x = rand()%4;
    int pos_y = rand()%4;
    logic_field[pos_x][pos_y] = new_elem();
    while (true) {
        pos_x = rand()%4;
        pos_y = rand()%4;
        if (logic_field[pos_x][pos_y] == 0) {
            logic_field[pos_x][pos_y] = new_elem();
            break;
        }
    }
}


void field::show(){
    cout << "2048\n";
    cout << "\n\t\t--------------------------\n";
    for (int i = 0; i<SIZE; i++) {
        cout << "\t\t| ";
        for (int j = 0; j<SIZE; j++) {
            int element = logic_field[i][j];
            if (element == 0) {
                cout << "  " <<  " " << "  |";
            }else{
                cout << "  " <<  logic_field[i][j] << "  |";
            }
            
        }
        cout << "\n\t\t--------------------------\n";
    }
}

void field::set_af_step(int (*lg_field)[SIZE]){
    vector<point> pos_to_choose;
    for (int i = 0; i<SIZE; i++) {
        for (int j = 0; j<SIZE; j++) {
            if (lg_field[i][j] == 0) {
                point a(i,j);
                pos_to_choose.push_back(a);
            }
        }
    }
    srand(time(0));
    int index_ran_point = rand()%pos_to_choose.size();
    point a = pos_to_choose[index_ran_point];
    lg_field[a.GetX()][a.GetY()] = new_elem();
}

void field::end_game(bool &ch){
    cout << "\n\n\t\tGAME OVER\n\t if you would to try again press 1\n\n\t";
    int a = getch();
    if (a == 49) {
        ch = true;
    }else ch = false;
    
    
}

void field::game(){
    player gamer;
    bool game_ch = true;
    while (game_ch) {
        show();
        while (true){
            if (gamer.step(logic_field)) {
                break;
            }
        }
//        if(!gamer.get_poss_step(logic_field)){
//            end_game(game_ch);
//        }
        set_af_step(logic_field);
    }
}
