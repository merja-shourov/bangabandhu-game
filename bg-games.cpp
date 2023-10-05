#include <bits/stdc++.h>
#include <windows.h>
// # include <unistd.h> // for linux
using namespace std;

// All function declearation / prototype
void login();
void registration();
void forget();
void home_page();
void select_games();

void Guess_number();
void HANGMAN();
void exit();

// This is info class
class info
{
public:
    string name;
    string pass;

    // Parameterise constructor
    info(string name, string pass)
    {
        this->name = name;
        this->pass = pass;
    }
    // This is default constructor
    info(){};
};

// MAIN FUNTION
int main()
{
    system("COLOR 6");
    home_page();
    return 0;
}

// Function: Home Page
void home_page()
{
    system("cls");
    cout << "\t ===== HOME PAGE ====== \n\n";
    cout << "\t | ENTER 1 FOR REGISTRATION     \n";
    cout << "\t | ENTER 2 FOR LOGIN         \n";
    cout << "\t | ENTER 3 IF YOU FORGOT PASSWORD\n";
    cout << "\t | PRESS 4 TO EXIT           \n\n";

    cout << "\t Enter your choice: ";
    int choice;
    cin >> choice;

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
void registration()
{
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

    cout << endl
         << endl;
    string success_messege = "\t REGISTRATION SUCCESSFULL !";
    for (char ch : success_messege)
    {
        cout << ch;
        Sleep(50);
    }
    cout << endl
         << endl;

    char y_n;
    cout << "\t DO YOU WANT TO LOGIN NOW (Y/N): ";
    cin >> y_n;
    if (y_n == 'y' || y_n == 'Y')
    {
        login();
    }
    else
    {
        home_page();
    }
}

// Function : Login Page
void login()
{
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

    while (myFile >> f_name >> f_pass >> f_id)
    {
        if (u_name == f_name && u_pass == f_pass)
        {
            copy_name = u_name;
            flag = 1;
            break;
        }
    }

    // Login success or denite
    cout << endl
         << endl;
    if (flag)
    {
        string suc = "\t >_< LOGIN SUCCESSFULL !!!";

        for (char ch : suc)
        {
            cout << ch;
            Sleep(100);
        }
        select_games();
    }
    else
    {
        string unc = "\t INVALID USERNAME AND PASSWORD";
        for (char ch : unc)
        {
            cout << ch;
            Sleep(100);
        }
    }
    cout << endl
         << endl;

    char ch;
    cout << "\t ENTER 'Y' TO GO HOME PAGE: ";
    cin >> ch;
    if (ch == 'Y' || ch == 'y')
    {
        home_page();
    }
}

// Function : Forget password
void forget()
{
    string userName, id;
    system("cls");
    cout << "\t\t | PASSWORD RECOVER |\n";
    cout << "\t\t  ------------------ \n\n";
    cout << "\t Enter your username: ";
    cin >> userName;
    cout << "\t Enter your id ( last 3 dit): ";
    cin >> id;

    ifstream myFile("info.txt");
    
    string f_username, f_id, f_pass;
    int flag = 1;
    while( myFile >> f_username >> f_pass >> f_id ){

        if( f_username == userName && f_id == id ){
            cout << endl << endl;
            cout << "\t Your name is => " << f_username << " & ";
            cout << "Your password is => " << f_pass << endl << endl;
            break;
        }else{
            flag = 0;
        }
    }

    if( flag == 0 ) cout << endl << endl <<"\t ~YOUR GIVEN INFORMATION IS WRONG\n\n";
    
    char ch;
    cout << "\t ENTER 'Y' TO GO HOME PAGE: ";
    cin >> ch;
    if (ch == 'Y' || ch == 'y')
    {
        home_page();
    }

}

// This random file for Hangman Game
string random_file()
{
    vector<string> words = {"fruit.txt", "bird.txt", "fish.txt", "animal.txt", "color.txt"};
    int randomIndex = rand() % words.size();
    string word = words[randomIndex];
    words.erase(words.begin() + randomIndex);
    return word;
}
// Hangman funciton define
void HANGMAN()
{
    // Whole display HANGMAN FUNTION Class //
    class Hangman
    {
    private:
        const string adminUsername = "sheikhsayed23@gmail.com";
        const string adminPassword = "123456789";
        vector<string> questionAnswers;

    public:
        void Game()
        {
            cout << endl
                 << endl;
            cout << "\t\t\t\t\t\t_________________________\t\t" << endl;
            cout << "\t\t\t\t\t\t|\t1)Start Game\t|\t\t" << endl;
            cout << "\t\t\t\t\t\t|                       |\t\t" << endl;
            cout << "\t\t\t\t\t\t|\t2)Admin\t\t|\t\t" << endl;
            cout << "\t\t\t\t\t\t|                       |\t\t" << endl;
            cout << "\t\t\t\t\t\t|\t3)Exit \t \t|\t\t" << endl;
            cout << "\t\t\t\t\t\t|_______________________|\t\t" << endl;

            int choice;
            cout << "\t\t\t\t=======================================================" << endl;
            cout << "\t\t\t\t=======================================================" << endl
                 << endl;
            cout << "\t\t\t\t\t\t Enter your choice : ";
            cin >> choice;

            switch (choice)
            {
            case 1:
                Start_game();
                break;
            case 2:
                Admin();
                break;
            default:
                select_games();
                break;
            }
        }
        void Start_game()
        {
            // word collector class //
            class WordBank
            {
            private:
                vector<string> words;

            public:
                WordBank(const string &bank)
                {
                    ifstream file(bank);
                    if (!file)
                    {
                        cout << "Error opening " << bank << " file\n";
                        exit(1);
                    }
                    string word;
                    while (getline(file, word))
                    {
                        words.push_back(word);
                    }
                    file.close();
                }

                string getRandomWord()
                {
                    {
                        if (words.empty())
                        {
                            cerr << "Word bank is empty." << endl;
                            exit(1);
                        }

                        int randomIndex = rand() % words.size();
                        string word = words[randomIndex];
                        words.erase(words.begin() + randomIndex);

                        return word;
                    }
                }
            };
            // Hangman game Class //
            class HGMan
            {
            private:
                string secretWord;
                string guessedWord;
                int wordsize = 0;
                int maxAttempts;
                int attemptsLeft;
                bool isGameOver;

            public:
                HGMan(const string &word, int maxAttempts = 3) : secretWord(word), maxAttempts(maxAttempts), attemptsLeft(maxAttempts), isGameOver(false)
                {
                    for (char c : secretWord)
                    {
                        if (isalpha(c))
                        {
                            guessedWord += '_';
                            wordsize++;
                        }
                        else
                        {
                            guessedWord += c;
                        }
                    }
                }

                bool isLetterInWord(char letter)
                {

                    bool found = false;
                    for (size_t i = 0; i < secretWord.length(); ++i)
                    {
                        if (secretWord[i] == letter)
                        {
                            guessedWord[i] = letter;
                            found = true;
                        }
                    }
                    return found;
                }
                bool isGameWon()
                {

                    return secretWord == guessedWord;
                }
                bool isGameLost()
                {

                    return attemptsLeft == 0;
                }
                bool isGameOverState()
                {
                    return isGameWon() || isGameLost();
                }
                void makeGuess(char letter)
                {
                    if (!isGameOverState())
                    {
                        if (!isLetterInWord(letter))
                        {
                            attemptsLeft--;
                        }

                        if (isGameWon() || isGameLost())
                        {
                            isGameOver = true;
                        }
                    }
                }
                void displayGameStatus(string word)
                {
                    string name = "|";
                    string st = "=====";
                    string handle = " /";

                    if (isGameWon())
                    {
                        name = " ";
                    }
                    else if (isGameLost())
                    {

                        st = "     ";
                        handle = " |";
                    }

                    cout << "\t\t\t\t___________________________________\t\t\n";
                    cout << "\t\t\t\t         " << name << "          |           \t\t\n";
                    cout << "\t\t\t\t         O          |           \t\t\n";
                    cout << "\t\t\t\t        / \\         |              You have " << attemptsLeft << " changes \t\t\n";
                    cout << "\t\t\t\t         |          |             /\t\t\n";
                    cout << "\t\t\t\t        / \\         |            O\t\t\n";
                    cout << "\t\t\t\t   ====" << st << "=====   |           / \\\t\t\n";
                    cout << "\t\t\t\t   |           |    |   " << handle << "       |\t\t\n";
                    cout << "\t\t\t\t   |           |    |  ====     / \\  \t\t\n";
                    cout << "\t\t\t\t=======================|==|=======================\t\t\n";
                    cout << "\t\t\t\tHint: " << word << endl;
                    cout << "\t\t\t\tWord size : " << wordsize << endl;
                    cout << "\t\t\t\tSecret Word: " << guessedWord << endl;

                    if (isGameWon())
                    {
                        cout << "Congratulations! You guessed the word!" << endl;
                    }
                    else if (isGameLost())
                    {
                        cout << "Game Over! The word was: " << secretWord << endl;
                    }
                }
                bool isGameOverNow()
                {
                    return isGameOver;
                }
            };

            // Player Input Class///
            class Player
            {
            public:
                static char getGuess()
                {
                    char guess;
                    cout << "\t\t\t\tEnter a letter guess: ";
                    cin >> guess;
                    return tolower(guess);
                }
            };
            srand(time(0));
            while (true)
            {
                vector<string> words = {"fruit", "bird", "fish", "animal", "color"};
                int randomIndex = rand() % words.size();
                string word = words[randomIndex];
                words.erase(words.begin() + randomIndex);
                if (word == "fruit")
                {
                    WordBank wordBank("fruits.txt");
                    string randomWord = wordBank.getRandomWord();
                    HGMan game(randomWord);
                    while (!game.isGameOverNow())
                    {
                        system("cls");
                        game.displayGameStatus(word);
                        char guess = Player::getGuess();
                        game.makeGuess(guess);
                    }
                    system("cls");
                    game.displayGameStatus(word);
                    cout << "Do you want to play again? (yes/no): ";
                    string playAgain;
                    cin >> playAgain;

                    if (playAgain != "yes")
                    {
                        break;
                    }
                }
                else if (word == "fish")
                {
                    WordBank wordBank("fish.txt");
                    string randomWord = wordBank.getRandomWord();
                    HGMan game(randomWord);
                    while (!game.isGameOverNow())
                    {
                        system("cls");
                        game.displayGameStatus(word);
                        char guess = Player::getGuess();
                        game.makeGuess(guess);
                    }
                    system("cls");
                    game.displayGameStatus(word);
                    cout << "Do you want to play again? (yes/no): ";
                    string playAgain;
                    cin >> playAgain;

                    if (playAgain != "yes")
                    {
                        break;
                    }
                }
                else if (word == "bird")
                {
                    WordBank wordBank("bird.txt");
                    string randomWord = wordBank.getRandomWord();
                    HGMan game(randomWord);
                    while (!game.isGameOverNow())
                    {
                        system("cls");
                        game.displayGameStatus(word);
                        char guess = Player::getGuess();
                        game.makeGuess(guess);
                    }
                    system("cls");
                    game.displayGameStatus(word);
                    cout << "Do you want to play again? (yes/no): ";
                    string playAgain;
                    cin >> playAgain;

                    if (playAgain != "yes")
                    {
                        break;
                    }
                }
                else if (word == "animal")
                {
                    WordBank wordBank("animal.txt");
                    string randomWord = wordBank.getRandomWord();
                    HGMan game(randomWord);
                    while (!game.isGameOverNow())
                    {
                        system("cls");
                        game.displayGameStatus(word);
                        char guess = Player::getGuess();
                        game.makeGuess(guess);
                    }
                    system("cls");
                    game.displayGameStatus(word);
                    cout << "Do you want to play again? (yes/no): ";
                    string playAgain;
                    cin >> playAgain;

                    if (playAgain != "yes")
                    {
                        break;
                    }
                }
                else if (word == "color")
                {
                    WordBank wordBank("color.txt");
                    string randomWord = wordBank.getRandomWord();
                    HGMan game(randomWord);
                    while (!game.isGameOverNow())
                    {
                        system("cls");
                        game.displayGameStatus(word);
                        char guess = Player::getGuess();
                        game.makeGuess(guess);
                    }
                    system("cls");
                    game.displayGameStatus(word);
                    cout << "Do you want to play again? (yes/no): ";
                    string playAgain;
                    cin >> playAgain;

                    if (playAgain != "yes")
                    {
                        break;
                    }
                }
            }
        }
        void Admin()
        {
            {
                string username;
                string password;
                cout << "\t\t\t________________________________________\t\t" << endl
                     << endl;
                cout << "\t\t\t________________________________________\t\t" << endl
                     << endl;
                cout << "\t\t\t\tEnter username\t\t" << endl;
                cout << "\t\t\t\t";
                cin >> username;
                cout << "\t\t\t\tEnter password\t\t" << endl;
                cout << "\t\t\t\t";
                cin >> password;
                cout << "\t\t\t________________________________________\t\t" << endl
                     << endl;
                cout << "\t\t\t________________________________________\t\t" << endl
                     << endl;

                if (username == adminUsername && password == adminPassword)
                {
                    string f;
                    cout << "Enter the file name with txt extension" << endl;
                    cout << "Enter file name: ";
                    cin >> f;

                    AdminPannel(f);
                }
                else
                {
                    string invalid = "Invalid username or password";
                    cout << "\t\t\t___________________________________________\t\t" << endl
                         << endl;

                    cout << "\t\t\t\t";
                    for (char c : invalid)
                    {
                        cout << c;
                        Sleep(100);
                    }
                    cout << "\t\t" << endl;
                    cout << "\t\t\t___________________________________________\t\t" << endl
                         << endl;
                }
            }
        }
        void AdminPannel(const string &file)
        {
            while (true)
            {
                string answer;
                cout << "Enter the word name: ";
                cin >> answer;

                questionAnswers.push_back(answer);

                ofstream outputFile(file, ios::app);

                if (outputFile.is_open())
                {
                    outputFile << answer << endl;
                    outputFile.close();
                    cout << "The word stored successfully." << endl;
                }
                else
                {
                    cerr << "Error: Unable to open the file for writing." << endl;
                }

                string another;
                cout << "Do you want to store another question? (yes/no): ";
                cin >> another;
                if (another != "yes")
                {
                    break;
                }
            }
        }
    };
    system("cls");
    Sleep(500);
    cout << "\n\n";
    cout << "\t\t{}\t{}    {}{}\t {}\t {}\t {}}}}}}\t{}\t{}\t {}{} \t {}\t  {}\t\n";
    Sleep(500);
    cout << "\t\t{}\t{}   {}  {}\t {}}} \t {}\t{}    {}\t{}}}  {{{}\t{}  {}\t {}}}\t  {}\t\n";
    Sleep(500);
    cout << "\t\t{}{{{}}}{}  {}{{}}{}\t {} {}}  {}\t{} \t\t{}  {}  {}     {}{{}}{}\t {}  {}}  {}\t\n";
    Sleep(500);
    cout << "\t\t{}\t{}  {}\t  {}\t {}    {{{}\t{}   {}{}\t{}\t{}     {}    {}\t {}\t{{{}\t\n";
    Sleep(500);
    cout << "\t\t{}\t{}  {}\t  {}\t {}\t {}\t {}}}}}}\t{}\t{}     {}    {}\t {}\t  {}\t\n";
    Sleep(500);
    Hangman Hangman;
    while (true)
    {
        Hangman.Game();
    }
}
// Guess_number funtion //
void Guess_number()
{
        int flag = 0;
    do{
        system("cls");
        int guess;
        cout << "\t -| NUMBER GUSSING GAME |- \n\n\n";
        cout << "\t Guess any number between 1 & 10: ";
        cin >> guess;

        int random_num = rand() % 10 + 1;
        if( guess == random_num ){
            cout << "\n\t YOU ARE IN LUCK !! YOU WON\n";

            cout << "\n\t Do you want to play again(y/n): ";
            char choice; cin >> choice;

            if( choice == 'y' || choice == 'Y' ){
                flag = 1;
            }else{
                flag = 0;
            }
        }else{
            cout << "\n\t Oops, better luck next time !! You lost\n";
            cout << "\t Winnig number was: " << random_num << endl;

            cout << "\n\n\t Do you want to play again(y/n): ";
            char choice; cin >> choice;
            if( choice == 'y' || choice == 'Y' ){
                flag = 1;
            }else{
                flag = 0;
            }
        }
    }while( flag );
}

// select games //
void select_games()
{
    system("cls");
    cout << endl
         << endl
         << endl;
    cout << "\t\t\t\t\t -| Which game you want play ? \n\n";
    cout << "\t\t\t\t\t ++ Enter 1 for play GUESS-NUMBER " << endl;
    cout << "\t\t\t\t\t ++ Enter 2 for play HANGMAN-GAME " << endl;
    cout << endl
         << "\t\t\t\t\t Enter your choice: ";
    int choice;
    cin >> choice;
    switch (choice)
    {
    case 1:
        Guess_number();
        break;
    case 2:
        HANGMAN();
    default:
        exit();
        break;
    }
}
// Function : Exit
void exit()
{
    exit(0); // return
}
