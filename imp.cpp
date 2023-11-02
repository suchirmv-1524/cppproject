#include "header.h"

Account accs[100];
int num=0;
ifstream ifile;
ofstream wfile;

Account::Account(){}

Account::Account(int flag){
    // Generating Random Account Number
    this->accno=randgen(10);
    while (findacc(this->accno)==1){
        this->accno=randgen(10);
    }
    this->debval=-1;
    this->debno=-1;
    this->balance=0;
}

long long int Account::getAccNo(){
    return this->accno;
}

long long int Account::getDebNo(){
    return this->debno;
}

void Account::filldet(void* holder, CHOICE detmap){
    // Function to fill paticular detail of account
    switch (detmap){
        case NAME:
            strcpy(this->name, ((char*) holder));
            break;
        case FNAME:
            strcpy(this->fname, ((char*) holder));
            break;
        case GENDER:
            strcpy(this->gender, ((char*) holder));
            break;
        case ADDRESS:
            strcpy(this->address, ((char*) holder));
            break;
        case MARITIAL:
            strcpy(this->maritial, ((char*) holder));
            break;
        case NATIONALITY:
            strcpy(this->nationality, ((char*) holder));
            break;
        case ACCTYPE:
            strcpy(this->acctype, ((char*) holder));
            break;
        case DOB:
            strcpy(this->dob, ((char*) holder));
            break;
        case PHNO:
            this->phno=*((long long int*) holder);
            break;
        case AADNO:
            this->aadno=*((long long int*) holder);
            break;
        case PANNO:
            this->panno=*((long long int*) holder);
            break;
        case AGE:
            this->age=*((int*) holder);
            break;
        case EMAIL:
            strcpy(this->email, ((char*) holder));
    }
}

void Account::getdet(void* holder, CHOICE detmap){
    // Function to get paticular detail of account
    switch (detmap){
        case NAME:
            strcpy(((char*) holder), this->name);
            break;
        case FNAME:
            strcpy(((char*) holder), this->fname);
            break;
        case GENDER:
            strcpy(((char*) holder), this->gender);
            break;
        case ADDRESS:
            strcpy(((char*) holder), this->address);
            break;
        case MARITIAL:
            strcpy(((char*) holder), this->maritial);
            break;
        case NATIONALITY:
            strcpy(((char*) holder), this->nationality);
            break;
        case ACCTYPE:
            strcpy(((char*) holder), this->acctype);
            break;
        case DOB:
            strcpy(((char*) holder), this->dob);
            break;
        case PHNO:
            *((long long int*) holder)=this->phno;
            break;
        case AADNO:
            *((long long int*) holder)=this->aadno;
            break;
        case PANNO:
            *((long long int*) holder)=this->panno;
            break;
        case AGE:
            *((int*) holder)=this->age;
            break;
        case EMAIL:
            strcpy(((char*) holder), this->email);
    }
}

void Account::appdebcard(){
    // Function to generate a debit card

    // Code to get current year
    time_t now=time(0);
    char* dt=ctime(&now);
    char year[4]={dt[strlen(dt)-5], dt[strlen(dt)-4], dt[strlen(dt)-3], dt[strlen(dt)-2]};
    int curyear=atoi(year);

    // Checking is any existing valid debit card is present
    if (this->debno==-1 || curyear==this->debval){
        // Generating random debit card number
        this->debno=randgen(12);
        while (finddeb(this->debno)==1){
            this->debno=randgen(12);
        }

        // Setting validity of debit card
        this->debval=curyear+4;

        // Displaying debit card details
        cout<<"Debit card generated and linked to your account successfully."<<endl;
        cout<<"Debit Card number:"<<this->debno<<endl;
        cout<<"Valid Upto:"<<this->debval;
    }
    else{
        // Displaying debit card details
        cout<<"A Valid debit card is already linked to your account..."<<endl;
        cout<<"Debit Card Number:"<<this->debno<<endl;
        cout<<"Valid Upto:"<<this->debval;
    }

    // Updating accounts.dat file
    saveaccs();
}

int Account::findacc(long long int key){
    // Function to check whether an account number generated already exists
    int count=0;
    for (int i=0; i<num; i++){
        if (key==accs[i].getAccNo())
            count++; 
    }
    if (count>1)
        return 1;
    else if (count==1)
        return 2;
    else
        return 0;
}

int Account::finddeb(long long int key){
    // Function to check whether an debit card number generated already exists
    int count=0;
    for (int i=0; i<num; i++){
        if (key==accs[i].getDebNo())
            count++; 
    }
    if (count>1)
        return 1;
    else if (count==1)
        return 2;
    else
        return 0;
}


long long int Account::chkbal(){
    // Code for check balance : Suchir
}

void Account::deposit(long long int amount){
    // Code for cash deposit : Suchir
}

void Account::withdraw(long long int amount){
    // Code for cash withdrawal : Yogesh
}

void Account::updatekyc(){
    // Code for update kyc : Yogesh
}

long long int randgen(int nodigits){
    //Function that generates random numbers by generating random digits
    long long int temp=0;
    int digit=0;
    for (int i=0; i<nodigits; i++){
        temp*=10;
        digit=rand()%10;
        temp+=(digit)?digit:1;
    }
    return temp;
}

void printupper(){
    // Function to print upper portion
    system("cls");
    cout<<"----------------------------------------Welcome to My Bank\
------------------------------------"<<endl<<endl;
}

void openaccs(){
    // Function to read accounts stored in accounts.dat before executing main
    // num  is number of accounts
    // accs is a global array consisting of all account objects
    ifile.open("accounts.dat", ios::binary);
    if (ifile){
        ifile.read((char*) &num, sizeof(int));
        ifile.read((char*) &accs[0], sizeof(Account)*num);
    }
    ifile.close();
}

void saveaccs(){
    // Function to store accounts in accounts.dat
    // num  is number of accounts
    // accs is a global array consisting of all account objects
    wfile.open("accounts.dat", ios::binary);
    if (wfile && num){
        wfile.write((const char*) &num, sizeof(int));
        wfile.write((const char*) &accs[0], sizeof(Account)*num);
    }
    wfile.close();
}

void createaccount(){
    // Function to create a new account
    printupper();
    cout<<endl<<"Option 1:Create new account..."<<endl<<endl;
    string det[13]={"Name", "Father\'s Name", "Gender", "Address", "Maritial status", 
    "Nationality", "Date of birth", "Age", "Phone Number", "Aadhar Number", "PAN Number", 
    "Account Type", "email"};
    Account tempacc;

    // Storing user details
    for (int i=0; i<12; i++){
        cout<<"Enter your "<<det[i]<<":";
        if (i==NAME || i==FNAME || i==ADDRESS || i==MARITIAL || i==NATIONALITY 
        || i==DOB || i==GENDER || i==ACCTYPE || i==EMAIL){
            string temp;
            getline(cin>>ws, temp);
            char temps[400];
            strcpy(temps, temp.c_str());
            tempacc.filldet(&temp, (CHOICE) i);
        }
        else if (i==PHNO || i==AADNO || i==PANNO){
            long long int temp;
            cin>>temp;
            tempacc.filldet(&temp, (CHOICE) i);
        }
        else if (i==AGE){
            int temp;
            cin>>temp;
            tempacc.filldet(&temp, (CHOICE) i);
        }
        cout<<endl;
    }

    // Adding new account to the array
    accs[num++]=tempacc;

    // Displaying account number to user and updating accounts.dat file
    cout<<endl<<endl;
    cout<<"Congratulations! Your account has been created successfully.";
    cout<<"Your account number is "<<tempacc.getAccNo()<<endl;
    saveaccs();
}

void printoptions(){
    // Function to show various banking options
    long long int tempaccno;
    printupper();

    cout<<endl<<"Option 2:Banking options..."<<endl<<endl;
    cout<<"Enter your account number:\n";
    cin>>tempaccno;

    // Checking if account is valid
    if (Account::findacc(tempaccno)==2){
        cout<<"Inside if";
        Account* acc=getaccount(tempaccno);
        printupper();
        cout<<endl<<endl<<"Valid Account Number.";
        char name[40];
        acc->getdet(name, NAME);
        cout<<endl<<endl<<"Account Number:"<<tempaccno;
        cout<<endl<<"Account Holder Name:"<<name;

        // Showing options to user
        cout<<endl<<endl<<"Press"<<endl<<"1 for cash deposit"<<
        endl<<"2 for cash withdrawal"<<endl<<"3 for applying new debit card"<<
        endl<<"4 for checking balance"<<endl<<"5 for updating kyc."<<endl<<
        "6 for transfering funds"<<endl<<"0 to exit"<<endl<<endl<<"Input:";

        int choice;
        choice=getche()-'0';

        switch (choice){
            case 0:{
                thank();
                break;
            }
            case 1:{
                /*Code for cash deposit : Suchir*/
            }
            case 2:{
                /*Code for cash withdrawal : Yogesh*/
            }
            case 3:{
                printupper();
                cout<<endl<<endl<<"Option 3: Issual of new debit card..."<<endl<<endl;
                acc->appdebcard();
            }
            case 4:{
                /*Code for checking balance : Suchir*/
            }
            case 5:{
                /*Code for updating kyc : Yogesh*/
            }
            case 6:{
                /*Code for tranfering fund : Suchir*/
            }
        }
    }
    else{
        cout<<"Invalid account number.\nTry Again!";
        printoptions();
    }
}

Account* getaccount(long long int accno){
    // Function to get account object for a particular account number
    int i;
    for (i=0; i<num; i++){
        if (accs[i].getAccNo()==accno){
            break;
        }
    }
    return &accs[i];
}

void thank(){
    // Function to thank at the end of program
    system("cls");
    cout<<"Thank You for banking with Us.\nHave a great day!";
    cout<<endl<<endl;
}