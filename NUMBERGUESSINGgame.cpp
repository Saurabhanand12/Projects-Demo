#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;

void number_guessing_game(){
    srand(time(0));
    int secret_number = rand() % 100 + 1 ;

    int guess =0;
    int attempts = 0;

    cout<<"WELCOME TO THE NUMBER GUESSING GAME !"<<endl;
    cout<<"USING NUMBER IN BETWEEN 1 TO 100"<<endl;

    while(guess != secret_number){
        cout<<"ENTER YOUR GUESS NUMBER : "<<" ";
        cin>>guess;
        attempts++;

        if(guess > secret_number ){
            cout<<" NUMBER IS GREATER THAN GUESS" <<endl;
            cout<<"PLEASE GUESS LOW NUMBER"<<endl;   
        }
        else if(guess < secret_number ){
            cout<<" NUMBER IS LESS THAN GUESS "<<endl;
            cout<<"PLEASE GUESS HIGH NUMBER"<<endl;
        }
    }
    cout<<"CONGRATULATIONS! YOU GUESSED THE CORRECT NUMBER IN " << attempts << " attempts." << endl;
}

int main() {
    number_guessing_game();
return 0;
}