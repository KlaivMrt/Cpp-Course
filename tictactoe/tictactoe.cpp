//
// Created by arcmi on 3/8/2022.
//

#include <iostream>
#include <string>
using namespace std;

struct Player {
    int id{};
    string name;
    int score = 0;
};

Player generatePlayer(int _id){
    Player player;
    player.id = _id;
    cout << "Player "<< _id + 1 << " type your name >> >>";
    cin >> player.name;
    cout << "Welcome to the game "<< player.name << endl;
    cout << "" << endl;
    return player;
}

Player * generatePlayers(){
    static Player players[2];
    for (int i = 0; i < 2; i++){
        players[i] = generatePlayer(i);
    }
    return players;
}

void resetGrid(int _grid[][3]){
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            _grid[i][j] = -1;
        }
    }
}

void checkGrid(int _grid[][3], Player * currentPlayer, int * rounds, int * tieCheck){
    int id = currentPlayer->id;
    cout << *rounds << endl;
//    cout << rounds << endl;
//    cout << --*rounds << endl;

    if (_grid[0][0] == _grid[1][1] && _grid[1][1] == _grid[2][2] && _grid[0][0] == id){
        currentPlayer->score++;
        --*rounds;
        resetGrid(_grid);
    }
    else if (_grid[0][2] == _grid[1][1] && _grid[1][1] == _grid[2][0] && _grid[0][2] == id){
        currentPlayer->score++;
        --*rounds;
        resetGrid(_grid);
        return;
    }

    for (int i = 0; i < 3; ++i) {
        if (_grid[i][0] == _grid[i][1] && _grid[i][1] == _grid[i][2] && _grid[i][0] == id){
            currentPlayer->score++;
            --*rounds;
            resetGrid(_grid);
            return;
        }
    }

    for (int i = 0; i < 3; ++i) {
        if (_grid[0][i] == _grid[1][i] && _grid[1][i] == _grid[2][i] && _grid[0][i] == id){
            currentPlayer->score++;
            --*rounds;
            resetGrid(_grid);
            return;
        }
    }
    ++*tieCheck;
}

void displayGrid(int _grid[][3]){
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            cout << _grid[i][j];
        }
        cout << "" << endl;
    }
    cout << "" << endl;
}

void run(){

    int grid[3][3] {
            {-1, -1, -1},
            {-1, -1, -1},
            {-1, -1, -1}
    };

    Player * players = generatePlayers();
    Player * currentPlayer = &players[1];
    int rounds = 2;
    int tieCheck = 0;

    do{
        int row = -1;
        int column = -1;

        checkGrid(grid, currentPlayer, &rounds, &tieCheck);

        if(currentPlayer == &players[1]){
            currentPlayer = &players[0];
        }else{
            currentPlayer = &players[1];
        }


        while(row < 0 || row > 3){
            cout << currentPlayer->name << " choose your row:" << " ";
            cin >> row;
            cout << "" << endl;

            if (row < 0 || row > 3){
                cout << "Row out of range, please try again." << endl;
            }
        }

        while(column < 0 || column > 3){
            cout << currentPlayer->name << " choose you column: ";
            cin >> column;
            cout << "" << endl;


            if(column < 0 || column > 3){
                cout << "Column out of range, please try again." << endl;
            }

        }

        if(grid[row - 1][column - 1] == -1){
            grid[row - 1][column - 1] = currentPlayer->id;
        } else{
            if(currentPlayer == &players[1]){
                currentPlayer = &players[0];
            }else{
                currentPlayer = &players[1];
            }
            cout << "The position you chose is already occupied. Please, try again." << endl;
        }

        if (tieCheck == 9) {
            rounds--;
            resetGrid(grid);
        }
        displayGrid(grid);
    }while (rounds > 0);
}

int main(){
    run();
}