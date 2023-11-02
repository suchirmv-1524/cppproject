#include "header.h"
using namespace std;

int main(){
    atexit(saveaccs);
    int choice;
    srand(time(NULL));

    printupper();
    cout<<"Press 1 to Create New Account"<<endl<<endl<<endl<<
    "Press 2 to Access your account"<<endl<<endl<<endl<<"Press 0 to exit"
    <<endl<<endl<<endl<<"Input:";
    choice=getche()-'0';

    if (choice==0){
        thank();
    }
    else if (choice==1){
        int temp;
        do{
            createaccount();
            cout<<endl<<endl<<"Press 1 to create another account or 0 to Main Menu....";
            temp=getche()-'0';
        }
        while (temp);
        main();
    }
    else if (choice==2){
        int temp;
        printoptions();
        cout<<endl<<endl<<"Press 1 to go to main menu or 0 to exit..."<<endl;
        int choice;
        choice=getche()-'0';
        if (choice)
            main();
        else
            thank();
    }
    else{
        cout<<"Invalid option try again!";
        main();
    }

    return 0;
}