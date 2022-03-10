

#include <iostream>
#include <string>
using namespace std;

double calculate(int num){
    double result = (num * (double)9/5) + 32;
    return result;
}

void run(){
    double temp;
    double calculated;
    bool retype = true;

    while (retype){
        cout << "Type the value of the temperature >> >>";
        cin >> temp;
        cout << "" << endl;

        if(temp <= -271.15){
            cout << "Invalid. Temperature below absolute zero" << endl;
            cout << "" << endl;
        }
        else{
            retype = false;
            calculated = calculate(temp);
        }
    }
    cout << calculated << " Fahrenheit"<< endl;
}


int main() {
    run();
}
