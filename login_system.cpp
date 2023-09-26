#include<bits/stdc++.h>
#include <windows.h>
// # include <unistd.h> // for linux
using namespace std;

// All function declearation
void login(); 
void registration(); 
void forget(); 
void home_page();
void exit();

// This is info class
class info{
    public: 
        string name;
        string pass;
    
    // Parameterise constructor
    info( string name, string pass){
        this-> name = name; this->pass = pass;
    }
    // This is default constructor
    info(){};
};

// MAIN FUNTION
int main(){

    home_page();
    return 0;
}

// Function: Home Page
void home_page(){
    system("cls");
    cout << "\t ===== HOME PAGE ====== \n\n";
    cout << "\t | ENTER 1 FOR REGISTRATION     \n";
    cout << "\t | ENTER 2 FOR LOGIN         \n";
    cout << "\t | ENTER 3 IF YOU FORGOT PASSWORD\n";
    cout << "\t | PRESS 4 TO EXIT           \n\n";

    cout << "\t Enter your choice: ";
    int choice; cin >> choice;

    switch (choice)
    {
    case 1:
        registration();
        break;
    case 2:
        login();
        break;
    case 3:
        forget();
        break;
    case 4:
        exit();
        break;
    default:
        cout << "Enter your choice between 1 ~ 4\t|" << endl;
        break;
    }
}

// Function : Registration Page
void registration(){
    system("cls");
    cout << "\t ======= REGISTRATION FORM ======= \n\n";

    string user_name, user_pass, user_id;
    cout << "\t | Enter your username: ";
    cin >> user_name;
    cout << "\t | Enter your password: ";
    cin >> user_pass;
    cout << "\t | Enter your id [Last 3 digit ]: ";
    cin >> user_id;

    // set value of an user using object
    info person(user_name, user_pass);


    // File create or open and write user information:
    ofstream myFile("info.txt", ios::app);
    // Write name and pass in file using class & object. 
    myFile << person.name << " " << person.pass << " " << user_id << endl; 
    myFile.close();
    // File Close


    cout << endl << endl;
    string success_messege = "\t REGISTRATION SUCCESSFULL !";
    for( char ch : success_messege ){
        cout << ch;
        Sleep(50);
    }
    cout << endl << endl;
    
    char y_n;
    cout << "\t DO YOU WANT TO LOGIN NOW (Y/N): ";
    cin >> y_n;
    if( y_n == 'y' || y_n == 'Y'){
        login();
    }else{
        home_page();
    }
   
}

// Function : Login Page
void login(){
    system("cls");
    string f_name, f_pass, f_id, u_name, u_pass;
    string copy_name;
    int flag = 0;
    
    cout << "\t = = = = = LOGIN PAGE = = = = = \n\n";
    cout << "\t | Enter your username: ";
    cin >> u_name;
    cout << "\t | Enter your password: ";
    cin >> u_pass;

    // read value from file
    ifstream myFile("info.txt");
    
    while ( myFile >> f_name >> f_pass >> f_id)
    {
        if( u_name == f_name && u_pass == f_pass ){
            copy_name = u_name;
            flag = 1;
            break;
        }
    }
    
    // Login success or denite
    cout << endl << endl;
    if( flag ){
        string suc = "\t >_< LOGIN SUCCESSFULL !!!";
        
        for( char ch : suc ){
            cout << ch;
            Sleep(100);
        }
        cout << endl << endl << endl << "\t -| Hello " << copy_name << ",\n" << "\t -| Which game you want play ? \n\n";
        cout << "\t ++ Enter 1 for play GUESS-NUMBER " << endl;
        cout << "\t ++ Enter 2 for play HNGMAN-GAME " << endl;
        cout << endl << "\t Enter your choice: ";
    }else{
        string unc = "\t INVALID USERNAME AND PASSWORD";
        for( char ch : unc ){
            cout << ch;
            Sleep(100);
        }
    }
    cout << endl << endl;

    char ch;
    cout << "\t ENTER 'Y' TO GO HOME PAGE: ";
    cin >> ch;
    if( ch == 'Y' || ch == 'y' ){
        home_page();
    }
}

// Function : Forget password
void forget(){
    cout << "\t ::Forget function is under construction\n\n";
} 

// Function : Exit
void exit(){
    return;
};
