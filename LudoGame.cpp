#include <iostream>
#include<random> // library for rand function
using namespace std;


class ludo
{
    private:
    int countForPlayer1, countForPlayer2;
    int noOfTurnPlayer1, noOfTurnPlayer2;
    public:

    // Setting all values to zero
    ludo()
    {
        countForPlayer1 = countForPlayer2 = 0;
        noOfTurnPlayer1 = noOfTurnPlayer2 = 0;
    }

    // generating a random number between 1 to 6
    int randomFunction()
    {   
        std::random_device rd;
        std::uniform_int_distribution<int> list(1, 6);
        int r = list(rd);
        return r;
    }

    // Switching Player turn on basis of Rule and Regulation
    void switchingPlayer(bool player1, bool player2)
    {
        for (int i = 0; i < 5 ; i++)
        {
            if (player1 == true)
            {
                noOfTurnPlayer1++;
                if (randomFunction() == 6)
                {
                    player1 = true;
                    countForPlayer1++;
                    if (randomFunction() == 6 && randomFunction() == 6)
                    {
                        player1 = false;
                        countForPlayer1 += 2;
                        noOfTurnPlayer1 += 2;
                    }
                }
                else
                {
                    player2 = true;
                    player1 = false;
                }
            }
            else
            {
                noOfTurnPlayer2++;
                if (randomFunction() == 6)
                {
                    player2 = true;
                    countForPlayer2++;
                    if (randomFunction() == 6 && randomFunction() == 6)
                    {
                        player2 = false;
                        countForPlayer2 += 2;
                        noOfTurnPlayer2 += 2;
                    }
                }
                else
                {
                    player1 = true;
                    player2 = false;
                }
            }
        }
    }

    //Getters
    int getNoOfTurnP1()
    {
        return noOfTurnPlayer1;
    }

    int getNoOfTurnP2()
    {
        return noOfTurnPlayer2;
         
    }

    int noOfSixP1()
    {
        return countForPlayer1;
    }
    int noOfSixP2()
    {
        return countForPlayer2;
         
    }

    void display()
    {
        cout << "\t\t\t\t----------------------------------------------" << endl << endl;
        cout << "\t\t\t\t\t NUMBER OF TURNS OF PLAYER 1: " << getNoOfTurnP1() << endl;
        cout << "\t\t\t\t\t NUMBER OF SIXES OF PLAYER 1: " << noOfSixP1() << endl << endl;
        cout << "\t\t\t\t----------------------------------------------" << endl << endl;

        cout << "\n\n";

        cout << "\t\t\t\t----------------------------------------------" << endl << endl;
        cout << "\t\t\t\t\t NUMBER OF TURNS OF PLAYER 2: " << getNoOfTurnP2() << endl;
        cout << "\t\t\t\t\t NUMBER OF SIXES OF PLAYER 2: " << noOfSixP2() << endl << endl;
        cout << "\t\t\t\t----------------------------------------------" << endl << endl;


        cout << "\t\t\t\t    ---------------LUDO END---------------" << "\n\n";
    }


};

















int main()
{
    cout << "\t\t\t\t    ---------------LUDO START---------------" << "\n\n";

    ludo obj1;

    obj1.switchingPlayer(true,true);
    obj1.display();
    
    return 0;
}

