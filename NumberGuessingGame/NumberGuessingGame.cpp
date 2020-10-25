#include <iostream>
#include <string>

using namespace std;

// --- functions

void DisplayMainMenu(string Name) {

    cout << "What is your name? " << endl;

    cin >> Name;

    cout << "Welcome " << Name << endl;

    cout << "What is your gender?" << endl;
    cout << "   1) Male" << endl;
    cout << "   2) Female" << endl;
    cout << "press 1 or 2" << endl;
}

void DisplayMainPage() {

    // Display Welcome Page
    cout << "-------- Welcome to the Amazing number guessing game. --------" << endl;
    cout << "         You have 2 guesses to correctly guess the correct number between 1 and 20:" << endl;
    cout << "         1) Play now." << endl;
    cout << "         2) Quit." << endl;
    cout << "press 1 or 2 " << endl;
}


class Player {
    private:
        string nickname;
        int gender;

    public:
        void SetNickname(string n) {
            nickname = n;
        }

        string GetNickname() {
            return nickname;
        }

        void SetGender(int g) {
            gender = g;
        }

        int GetGender() {
            return gender;
        }
};



int main()
{
 
    constexpr int kPlayMenu = 1;
    constexpr int kQuit = 2;

    constexpr int kMaleGender = 1;
    constexpr int kFemaleGender = 2;

    // --- variables
    string Name;
    int GenderInput;
    Player CurrentPlayer;

    DisplayMainPage();

    int input;
    cin >> input;

    switch (input)
    {
        case kPlayMenu:
        {
            DisplayMainMenu(Name);

            //int gender;
            cin >> GenderInput;
            CurrentPlayer.SetGender(GenderInput);
            
            if (CurrentPlayer.GetGender() >= kMaleGender && CurrentPlayer.GetGender() <= kFemaleGender) {

                cout << "What is your age?" << endl;
                int age;
                cin >> age;

                

                // pick nickname for males
                if (CurrentPlayer.GetGender() == kMaleGender) {
                    if (age > 60) {

                        CurrentPlayer.SetNickname("old man");
                        //nickname = "old man";
                    }
                    else if (age < 10) {
                        //nickname = "little man";
                        CurrentPlayer.SetNickname("little man");
                    }
                    else {
                        //nickname = "buddy";
                        CurrentPlayer.SetNickname("buddy");
                    }

                }else {

                    // pick nickname for females
                    if (age > 60) {

                        //nickname = "old lady";
                        CurrentPlayer.SetNickname("old lady");
                    }
                    else if (age < 10) {
                        //nickname = "little lady";
                        CurrentPlayer.SetNickname("little lady");
                    }
                    else {
                        //nickname = "ma'am";
                        CurrentPlayer.SetNickname("ma'am");
                    }
                }

                int RandomNumber = rand() % 20 + 1;

                // --- GUESS 1
                cout << "Guess 1: " << "Alright " << CurrentPlayer.GetNickname() << " please guess a number: " << endl;
                int guess;
                cin >> guess;

                if (guess == RandomNumber) {
                    cout << "Congradulations, you guessed the correct number!!" << endl;
                }
                else if (guess > RandomNumber) {
                    cout << "Your guess is too high, please try again!" << endl;
                }
                else {
                    cout << "Your guess is too low, please try again!" << endl;
                }


                // --- GUESS 2
                cout << "Guess 1: " << "Alright " << CurrentPlayer.GetNickname() << " please guess a number: " << endl;
                cin >> guess;

                if (guess == RandomNumber) {
                    cout << "Congradulations, you guessed the correct number!!" << endl;
                }
                else if (guess > RandomNumber) {
                    cout << "Oh, I'm sorry, your guess is too high." << endl;
                }
                else {
                    cout << "Oops, too low.." << endl;
                }

                cout << "Better luck next time. Goodbye!" << endl;

            }
            else {
                cout << "Invalid gender" << endl;
            }
            break;
        }
        case kQuit:
        {
            cout << "Goodbye!" << endl;
            break;
        }
        default:
        {
            cout << "Invalid input. Goodbye!" << endl;
        }
    }
}
