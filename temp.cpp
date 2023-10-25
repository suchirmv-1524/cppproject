#include "header.h"

int main(){
    ofstream ifile("accounts.dat", ios::binary);
    int num=1;
    ifile.write((char*) &num, sizeof(int));

    Account acc(0);
    char c[400];
    strcpy(c, "Sohan Shanbhag");
    acc.filldet(c, NAME);
    strcpy(c, "Shreenivas Shanbhag");
    acc.filldet(c, FNAME);
    strcpy(c, "Male");
    acc.filldet(c, GENDER);
    strcpy(c, "B-405, Scintilla Apartments, 45, Industrial Area, Yelahanka New Town, Bangalore");
    acc.filldet(c, ADDRESS);
    strcpy(c, "Indian");
    acc.filldet(c, NATIONALITY);
    strcpy(c, "Unmarried");
    acc.filldet(c, MARITIAL);
    strcpy(c, "Savings");
    acc.filldet(c, ACCTYPE);
    strcpy(c, "15/02/2005");
    acc.filldet(c, DOB);

    long long int temp;
    temp=8050042295;
    acc.filldet(&temp, PHNO);
    temp=451465031639;
    acc.filldet(&temp, AADNO);
    temp=454545454545;
    acc.filldet(&temp, PANNO);

    int age=18;
    acc.filldet(&age, AGE);

    ifile.write((char*) &acc, sizeof(Account));
    ifile.close();

    cout<<acc.accno;
    return 0;
}