#include <iostream>
#include "main.h"

std::string Rock = "Rock\n";
std::string Paper = "Paper\n";
std::string Scissors = "Scissors\n";

void PrintIntroduction()
{
    std::cout << "\nWelcome to Rock, Paper, Scissors!\n";
    std::cout << "Play against the computer and try to beat it at the classic game.\n\n";
}

void PlayerChoice()
{
    std::cout << "Please select the number for your turn and press enter:\n" << "1. " << Rock << "2. "<< Paper << "3. " << Scissors;
    std::cin >> PlayerNumber;
    switch(PlayerNumber){
        case 1:
            std::cout << "You chose: " << Rock;
            break;
        case 2:
            std::cout << "You chose: " << Paper;
            break;
        case 3:
            std::cout << "You chose: " << Scissors;
            break;
        default:
            std::cout << "Please enter a valid choice next time!\n";
            EndGame();
    }
}

void ComputerChoice()
{
    for (int i = 0; i < 1; i++)
    {
        RandomNumber = rand() % 3;
        ComputerNumber = Array[RandomNumber];
    }
    std::cout << "\n\nComputer Choice: ";
    switch(ComputerNumber){
        case 1:
            std::cout << Rock;
            break;
        case 2:
            std::cout << Paper;
            break;
        case 3:
            std::cout << Scissors;
            break;
        default:
            std::cout << "Please enter a valid choice next time!\n";
    }
}

void GetWinner()
{
    GamesPlayed++;
    if (PlayerNumber == ComputerNumber) {
        std::cout << "\nYou drew!\n\n";
        GamesDrawn++;
    }
    else if (PlayerNumber == 1 && ComputerNumber == 3)
    {
        std::cout << "\nYou win!\n\n";
        GamesWon++;
        Score++;    
    }
    else if (PlayerNumber == 3 && ComputerNumber == 2)
    {
        std::cout << "\nYou win!\n\n";
        GamesWon++;
        Score++;
    } 
    else if (PlayerNumber == 2 && ComputerNumber == 1)
    {
        std::cout << "\nYou win!\n\n";
        GamesWon++;
        Score++;
    } 
    else
    {
        std::cout << "\nYou lose! Computer wins the game.\n\n";
        GamesLost++;
        Score--;
    }
    std::cout << "Games played: " << GamesPlayed << "\n";
    std::cout << "Games won: " << GamesWon << "\n";
    std::cout << "Games drawn: " << GamesDrawn << "\n";
    std::cout << "Games lost: " << GamesLost << "\n";
    std::cout << "Score: " << Score << "\n\n";
}

void EndGame()
{
    std::cin.clear();
    std::cin.ignore();
    std::cout << "\nPlay again? Press 0 then enter to continue.\n";
    int PlayAgain;
    std::cin >> PlayAgain;

    if (PlayAgain == 0)
    {
      PlayGame();  
    }
    else
    {
        std::cout << "\nThanks for playing!\n";
    }
}

void PlayGame()
{
    PlayerChoice();
    ComputerChoice();
    GetWinner();
    EndGame();
}

int main()
{
    PrintIntroduction();
    PlayGame();
    return 0;
}