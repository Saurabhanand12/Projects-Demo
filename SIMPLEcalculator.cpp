#include<iostream>
using namespace std;

int main() {
    float no1,no2;           //numbers 
    char op;                // opreator
    cout<<"Enter the values : "<<endl;
    cin>>no1>>op>>no2;                       //input

    switch(op) {
        case '+':
        cout<<no1 + no2;
        break;

        case '-':
        cout<<no1 - no2;                     //arithmetic operations
        break;

        case '*':
        cout<<no1 * no2;
        break;

        case '/':
        cout<<no1 / no2;
        break;

        default : 
        cout<<"operator is not correct"<<endl;

    }
return 0;
}