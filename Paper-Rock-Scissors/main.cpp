#include <iostream>
using namespace std;

struct Player{
    int id{};
    string name;
    int score = 0;
    string symbol;
};

Player initiatePlayer(int _id){
    Player * player = new Player;
    player -> id = _id;

    cout << "Player " << player -> id + 1 << " type your name >> >>";
    cin >> player -> name;
    cout << "" << endl;

    return * player;
}

Player * initiatePlayers(){
    static Player players[2];
    for (int i = 0; i < 2; ++i) {
        players[i] = initiatePlayer(i);
    }
    return players;
}

int initiateRounds(){
    int rounds;
    cout << "How many rounds do you wish to play? >> >>";
    cin >> rounds;
    cout << "" << endl;

    return rounds;
}

void displayScore(Player * player){
    cout << "+-----------------------------------+" << endl;
    cout << "+------------ " << player[0].name  << " VS " << player[1].name << " ---------------+" << endl;
    cout << "+----------- " << player[0].score  << " +--+ " << player[1].score << " --------------+" << endl;
    cout << "+-----------------------------------+" << endl;
    cout << "" << endl;
}

void roll(Player * players){
    for(int i = 0; i < 2; i++){
        int check = 1;
        while (check){
            cout << players[i].name << " choose symbol >> >>";
            cin >> players[i].symbol;
            cout << "" << endl;

            if (players[i].symbol == "P" || players[i].symbol == "S" || players[i].symbol == "R"){
                check = 0;
            } else{
                cout << "Please enter a valid symbol." << endl;
                cout << "" << endl;
            }

        }
    }
}

void checkScore(Player players[], int * rounds){

    if(players[0].symbol == players[1].symbol){
        cout << "It's a tie!" << endl;
        cout << "" << endl;
    }
    else if(players[0].symbol == "P" && players[1].symbol == "R"){
        players[0].score++;
    }
    else if(players[0].symbol == "R" && players[1].symbol == "S"){
        players[0].score++;
    }
    else if(players[0].symbol == "S" && players[1].symbol == "P"){
        players[0].score++;
    }
    else{
        players[1].score++;
    }

    displayScore(players);
    --*rounds;
}

void run(){
    int replay = 1;
    int rounds;
    Player * players = initiatePlayers();

    while (replay){
        rounds = initiateRounds();

        do{
            roll(players);
            checkScore(players, &rounds);

        } while (rounds > 0);

        string answer;
        cout << "Want to play again?? >> >>";
        cin >> answer;
        cout << "" << endl;

        if (answer == "y" || answer == "Y" || answer == "yes" || answer == "Yes" || answer == "YES"){
            replay = 1;
        }else{
            replay = 0;
        }
    }


}

int main() {
    run();
}
