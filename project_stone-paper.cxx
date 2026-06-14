//Project_1/2
#include <iostream>
#include <cstdlib>
using namespace std;
int RandomNumber(int From, int To)
{
    int randNum = rand() % (To - From + 1) + From;
    return randNum;
}

enum enGameChoice
{

    Stone = 1,
    Paper = 2,
    Scissors = 3
};
enum enWinner
{
    Player1 = 1,
    Computer = 2,
    Draw = 3
};
struct stRoundInfo
{
    short RoundNumber = 0;
    enGameChoice Player1Choice;
    enGameChoice ComputerChoice;
    enWinner Winner;
    string WinnerName = " ";
};
struct stGameResults
{
    short GameRounds = 0;
    short Player1WinTimes = 0;
    short ComputerWinTimes = 0;
    short DrawTimes = 0;
    enWinner GameWinner;
    string WinnerName = " ";
};
//1

//1

//1
string ChoiceName(enGameChoice Choice)
{
    string arrGameChoices[3] = {
        "Stone ", "Paper ", "Scissors"};
    return arrGameChoices[Choice - 1];
}
string WinnerName(enWinner Winner)
{
    string arrWinnerName[3] = {
        "Player1", "Computer", "No Winner "};
    return arrWinnerName[Winner - 1];
}
enWinner WhoWonTheRound(stRoundInfo RoundInfo)
{
    if (RoundInfo.Player1Choice == RoundInfo.ComputerChoice)
    {
        return enWinner::Draw;
    }
    switch (RoundInfo.Player1Choice)
    {
    case enGameChoice::Stone:
        if (RoundInfo.ComputerChoice == enGameChoice::Paper)
        {
            return enWinner::Computer;
        }
        break;
    case enGameChoice::Paper:
        if (RoundInfo.ComputerChoice == enGameChoice::Scissors)
        {
            return enWinner::Computer;
        }
        break;
    case enGameChoice::Scissors:
        if (RoundInfo.ComputerChoice == enGameChoice::Stone)
        {
            return enWinner::Computer;
        }
        break;
    }
    return enWinner::Player1;
}

//2
short ReadHowManyRounds()
{
    short GameRounds = 1;
    do
    {
        cout << "How Many Rounds 1 to 10 ? \n";
        cin >> GameRounds;

    } while (GameRounds < 1 || GameRounds > 10);
    return GameRounds;
}
enGameChoice ReadPlayer1Choice()
{
    short Choice = 1;
    do
    {
        cout << "\n Your choice:  [1]:Stone - [2]:Paper [3]:Scissors : ";
        cin >> Choice;

    } while (Choice < 1 || Choice > 3);

    return (enGameChoice)Choice;
}

enGameChoice GetComputerChoice()
{
    return (enGameChoice)RandomNumber(1, 3);
}

void PrintRoundResults(stRoundInfo RoundInfo)
{
    cout << "\n______________Round [ " << RoundInfo.RoundNumber << "]__________\n\n";
    cout << "Player1 Choice : " << ChoiceName(RoundInfo.Player1Choice) << endl;
    cout << "Computer  Choice : " << ChoiceName(RoundInfo.ComputerChoice) << endl;
    cout << "Round   Winner  : " << RoundInfo.WinnerName << "] \n";
    cout << "_____________________________\n"
         << endl;
}
void ClearScreen()
{
    system("clear");
}
enWinner WhoWonTheGame(short Player1WinTimes, short ComputerWinTimes)
{
    if (Player1WinTimes > ComputerWinTimes)
        return enWinner::Player1;
    else if (ComputerWinTimes > Player1WinTimes)
        return enWinner::Computer;
    else
        return enWinner::Draw;
}
stGameResults FillGameResults(int GameRounds, short Player1WinTimes, short ComputerWinTimes, short DrawTimes)
{
    stGameResults GameResults;
    GameResults.GameRounds = GameRounds;
    GameResults.Player1WinTimes = Player1WinTimes;
    GameResults.ComputerWinTimes = ComputerWinTimes;

    GameResults.DrawTimes = DrawTimes;
    GameResults.GameWinner = WhoWonTheGame(Player1WinTimes, ComputerWinTimes);;
        GameResults.WinnerName = WinnerName(GameResults.GameWinner);


    return GameResults;
}
stGameResults PlayGame(short HowManyRounds)
{
    stRoundInfo RoundInfo;
    short Player1WinTimes = 0, Computer1WinTimes = 0, DrawTimes = 0;
    for (short GameRound = 1; GameRound <= HowManyRounds; GameRound++)

    {
        cout << "\n Round [" << GameRound << "] begins : \n";
        RoundInfo.RoundNumber = GameRound;
        RoundInfo.Player1Choice = ReadPlayer1Choice();
        RoundInfo.ComputerChoice = GetComputerChoice();
        RoundInfo.Winner = WhoWonTheRound(RoundInfo);
        RoundInfo.WinnerName = WinnerName(RoundInfo.Winner);
        if (RoundInfo.Winner == enWinner::Player1)
            Player1WinTimes++;
        else if (RoundInfo.Winner == enWinner::Computer)
            Computer1WinTimes++;

        else
            DrawTimes++;
        PrintRoundResults(RoundInfo);
    }
    return {HowManyRounds, Player1WinTimes, Computer1WinTimes, DrawTimes, WhoWonTheGame(Player1WinTimes, Computer1WinTimes), WinnerName(WhoWonTheGame(Player1WinTimes, Computer1WinTimes))};
}
string Tabs(int NumberOfTabs)
{
    string t =" ";
    for(int i=1;i<NumberOfTabs;i++)
    {

       t=t+"\t";
       cout<<t;
    }
    return t;
}
void ShowGameOverScreen()
{

    cout<<Tabs(2)<<"--------------------------\n \n";
    cout<<Tabs(2)<<"         +++ Game Over +++++ \n \n";

    cout<<Tabs(2)<<"----------------------------\n \n";
}
void SetWinnerScreenColor(enWinner Winner)
{

    switch(Winner)
    {
        case enWinner::Player1:
        system("color 2f");
        break;
        case enWinner::Computer:
        system("color 4f");
        cout<<"\a";
        break;
        default:
        system("color 6f");
    }

}
void ShowFinalGameRrsults(stGameResults GameResults)
{
    cout<<Tabs(2)<<"---------Game Result -----------\n\n";
    cout<<Tabs(2)<<"Game Rounds           :  " <<GameResults.GameRounds <<endl;
    cout<<Tabs(2)<<"Player1 Win Times     :  " <<GameResults.Player1WinTimes<<endl;
    cout<<Tabs(2)<<"Computer Win Times    :  " <<GameResults.ComputerWinTimes<<endl;

  cout<<Tabs(2)<<"Draw Times            :  " <<GameResults.DrawTimes <<endl;
    cout<<Tabs(2)<<"----------------------------\n \n";
    SetWinnerScreenColor(GameResults.GameWinner);
}
void ResetScreen()
{
    system("cls");
    system("color 0F");
}
void StartGame()
{
    char PlayAgain = 'Y';
    do
    {
        ResetScreen();
        stGameResults GameResults = PlayGame(ReadHowManyRounds());
        ShowGameOverScreen();
        ShowFinalGameRrsults(GameResults);
        cout << endl
            << Tabs(2)<< "Do you want to play again  ? Y/N";
        cin >> PlayAgain;

    } while (PlayAgain == 'Y' || PlayAgain == 'y');
}
int main(int argc, char *argv[])
{
    srand((unsigned)time(NULL));

    StartGame();
    return 0;
}