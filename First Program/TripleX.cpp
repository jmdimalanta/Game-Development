#include <iostream>
#include <ctime>

void PrintIntroduction(int Difficulty)
{
    //Prints welcome messages to the terminal.
    std::cout << "\n\nHello 007, your mission is to hack into the enemy's headquarters, you are at level " << Difficulty;;
    std::cout << ", you must prevent them from using the nuclear codes...\nThe correct codes need to be entered to continue...\n\n";
}

bool PlayGame(int Difficulty)
{
    PrintIntroduction(Difficulty);

    //Declares the 3 number code.
    const int CodeA = rand() % Difficulty + Difficulty;
    const int CodeB = rand() % Difficulty + Difficulty;
    const int CodeC = rand() % Difficulty + Difficulty;

    const int CodeSum = CodeA + CodeB + CodeC; 
    const int CodeProduct = CodeA * CodeB * CodeC; 

    //Prints the sum and product.
    std::cout << "* There are three numbers in the code";
    std::cout << "\n* The codes add up to: " << CodeSum;
    std::cout << "\n* The codes product is: "<< CodeProduct << std::endl;

    //Stores the player's guess
    int GuessA, GuessB, GuessC;

    std::cin >> GuessA >> GuessB >> GuessC;
    
    int GuessSum = GuessA + GuessB + GuessC;
    int GuessProduct = GuessA * GuessB * GuessC;

    //Check's the player's guess.
    if (GuessSum == CodeSum && GuessProduct == CodeProduct)
    {
        std::cout << "\n*** Well done Bond! Keep going! ***\n";
        return true;
    }
    else
    {
        std::cout << "\n*** Try again Bond! ***\n";
        return false;
    }

}

int main()
{
    srand(time(NULL));
    int LevelDifficulty = 1;
    int const MaxDifficulty = 10;

    while (LevelDifficulty <= MaxDifficulty) //Loops the game until all levels are completed
    {
        bool bLevelComplete = PlayGame(LevelDifficulty);
        std::cin.clear(); // clears errors.
        std::cin.ignore();// clears buffers.

        if (bLevelComplete)
        {
            ++LevelDifficulty;
        }
        
    }
    std::cout << "\n*** Congratulations Bond, you have prevented all out nuclear war! *** \n";
    return 0;
}