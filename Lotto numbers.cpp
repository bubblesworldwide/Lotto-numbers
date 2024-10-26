// Lotto numbers.cpp : This file contains the 'main' function. Program execution begins and ends there.
//


#include <iostream>
#include <conio.h>
#include <string>
#include <ctime>
#include <cstdlib>

using namespace std;

//Generates lotto numbers and the user has to guess the first 5 then the bonus ball

//declaration of constants
const int SIZE = 5;
int main()
{
    //declaration of variables
    int value[SIZE];
    int generatedValue[SIZE];
    char choice = ' ';
    bool cond = false;
    string name = " ";
    int count;
    int bonusBall = 0;
    int genBonus = 0;
    //srand function
    srand(time(NULL));

    //introduction to do while loop
    do
    {
        //update condition for new round
        cond = false;


        //allow user to enter values
        cout << "Enter your name : ";
        getline(cin, name);

        //render new line
        cout << endl;

        //introduce user to the game
        cout << "Hi " << name << " Welcome to South African Lotto numbers.\n";
        cout << "All the best\n";

        //first stage of the game
        cout << "Guess the generated number " << name << endl;
        cout << "Ranges between 0 and 45\n";

        //introduction to for loop
        for (int k = 0; k < SIZE; k++)
        {
            cout << "Enter your lucky guess number["<<k+1<<"] : ";
            cin >> value[k];
            //render new line
            cout << endl;
        }
        cout << "Enter your bonus number : ";
        cin >> bonusBall;
        //render new line
        cout << endl;
        //check if value is greater than minimum
        bool validInput = bonusBall > 0 && bonusBall <= 10;
        //introduction to for loop
        for (int i = 0; i < SIZE && validInput; i++) 
        {
            if (value[i] > 0 || value[i] < 45) 
            {
                validInput = true;
            }
        }
        //introduction to if statement
        if (validInput)
        {
            //initialize count for each new game
            count = 0;

            //introduction to for loop
            for (int j = 0; j < SIZE; j++)
            {
                //generate the values
                generatedValue[j] = 0 + rand() % (45 - 0 + 1);
            }
            //generate bonus ball
            genBonus = 1 + rand() % (10 - 1 + 1);

            //introduction to while loop
            while (count)
            {
                //introduction to nested for loop
                for (int p = 0; p < SIZE; p++)
                {
                    for (int n = 0; n < SIZE; n++)
                    {
                        //introduction to if else statement
                        if (value[p] == generatedValue[n])
                        {
                            count++;
                        }
                    }

                }
                if (bonusBall == genBonus)
                {
                    count++;
                }
                //reset count
                count = 0;
            }

            //display
            cout << "The lotto numbers for this week are : \n";

            //introduction to for loop
            for (int o = 0; o < SIZE; o++)
            {
                cout << generatedValue[o] << "\t";
            }
            //render new line
            cout << endl;
            cout << "And the bonus ball is : " << genBonus << endl;
            
            //introduction to if else statement
            if (count == 0)
            {
                if (bonusBall == genBonus)
                {
                    cout << name << " You go home R10. Better luck next time\n";
                }
                else
                {
                    cout << name << " You go home with zero winnings. Better luck next time\n";
                }

            }
            else if (count == 1)
            {
                if (bonusBall == genBonus)
                {
                    cout << name << " you got " << count << " lotto number correctly. Big ups for the win\n";
                    cout << name << " you go home with R100. Congratulations !!!!!!!!!!!!!!!\n";
                }
                else
                {
                    cout << name << " you got " << count << " lotto number correctly. Big ups for the win\n";
                    cout << name << " you go home with R15. Congratulations !!!!!!!!!!!!!!!\n";
                }
            }
            else if (count == 2)
            {

                if (bonusBall == genBonus)
                {
                    cout << name << " you got " << count << " lotto number correctly. Big ups for the win\n";
                    cout << name << " you go home with R280. Congratulations !!!!!!!!!!!!!!!\n;";
                }
                else
                {
                    cout << name << " you got " << count << " lotto number correctly. Big ups for the win\n";
                    cout << name << " you go home with R80. Congratulations !!!!!!!!!!!!!!!\n;";
                }
            }
            else if (count == 3)
            {
                if (bonusBall == genBonus)
                {
                    cout << name << " you got " << count << " lotto number correctly. Big ups for the win\n";
                    cout << name << " you go home with R790. Congratulations !!!!!!!!!!!!!!!\n";
                }
                else
                {
                    cout << name << " you got " << count << " lotto number correctly. Big ups for the win\n";
                    cout << name << " you go home with R200. Congratulations !!!!!!!!!!!!!!!\n";
                }
            }
            else 
            {
                if (bonusBall == genBonus)
                {
                    cout << name << " you got " << count << " lotto number correctly. correctly therefor you go home with R100 milion.\n";
                    cout << name << "Congratulations !!!!!!!!!!!!!!!\n";
                }
                else
                {
                    cout << name << " you got " << count << " lotto number correctly. Big ups for the win\n";
                    cout << name << " you go home with R580000. Congratulations !!!!!!!!!!!!!!!\n";
                }
            }
        }
        else
        {
            //display
            cout << "Value is less than minimum or greater than maximum.\n";
            //break;
        }


        //ask user if they would like to try again
        //introduction to if statement
        cout << "Would you like to give it another try ? \n";
        cout << "Y - Yes and N- No\n";
        cin >> choice;

        //introduction to if statement
        if (toupper(choice) == 'Y')
        {
            //update condition
            cond = true;
        }
    } while (cond == true);
    //display
    cout << "Thank you " << name << " for playing Lotto. Best of luck\n";


    _getch();
    return 0;
}

