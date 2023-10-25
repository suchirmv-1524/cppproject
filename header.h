#include <iostream>
#include <cstdlib>
#include <ctime> // for random number generation and for getting current time
#include <conio.h> // for getche function
#include <cstring> // for string functions
#include <fstream> // for File IO operations
using namespace std;

// enum for switch case
typedef enum{
    NAME, FNAME, GENDER, ADDRESS, MARITIAL, NATIONALITY, DOB, AGE, PHNO, AADNO, PANNO, ACCTYPE
}CHOICE;

// Account class declaration
class Account{
    private:
        // Declaration of variables for storing personal details
        // debval is debit card validity
        long long int balance, phno, aadno, panno;
        char name[40], fname[40], gender[7], address[1000], 
        maritial[10], nationality[40], acctype[8], dob[9];
        int age, debval;

    public:
        // declaration of constructors and functions
        long long int accno, debno;
        Account();
        Account(int flag);
        void getdet(void *holder, CHOICE detmap);
        void filldet(void *holder, CHOICE detmap);
        void appdebcard();
        long long int chkbal();
        void deposit(long long int amount);
        void withdraw(long long int amount);
        void updatekyc();
        static int findacc(long long int key);
        static int finddeb(long long int key);
};

// other function declaration
long long int randgen(int);
void printupper();
void saveaccs();
void openaccs(void) __attribute__((constructor));
void createaccount();
void printoptions();
Account* getaccount(long long int accno);
void thank();