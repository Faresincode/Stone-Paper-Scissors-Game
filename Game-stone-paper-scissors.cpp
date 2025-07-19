//Game stone paper scissors

#include<iostream>
#include<string>
#include<cstdlib>
using namespace std;


enum enGameChoice { Stone = 1,Paper=2, Scossors = 3 };
enum enWinner { Player1 = 1, Computer = 2, Drow = 3 };

struct stRoundInfo
{
	short RoundNumber = 0;
	enGameChoice Player1Choice;
	enGameChoice ComputerChoice;
	enWinner Winner;
	string WinnerName;



};
struct stGameResults
{
	short GameRounds = 0;
	short Player1WinTimes = 0;
	short Computer2WinTimes = 0;
	short DrawTimes = 0;
	enWinner GameWinner;
	string WinnerName = "";

};

int RandomNumber(int From, int To)
{

	int RandNum = rand() % (To - From + 1) + From;
	return RandNum;

}
short ReadHowManyRounds()
{

	short GameRounds;
	do
	{

		cout << "enter Game round from 1 to 10 ";
		cin >> GameRounds;


	} while (GameRounds < 1 || GameRounds > 10);
	return GameRounds;



}

string WinnerName(enWinner Winner)
{

	string arrWinnerName[3] = { "Player1","Computer","No Winner" };
	return arrWinnerName[Winner - 1];

}
string ChoiceName(enGameChoice Choice)
{
	string arrGameChoice[3] = { "Stone","Paper","Scissors" };
	return arrGameChoice[Choice - 1];
}
string Tabs(short NumberOfTabs)
{

	string t = "";

	for (int i = 1; i < NumberOfTabs; i++)
	{

		t = t + "\t";
		cout << t;

	}

	return t;


}
string BackslashN(short NumberOfBackSlashN)
{

	string N= "";
	for (int i = 0; i < NumberOfBackSlashN; i++)
	{
		N = N + "\n";
		cout << N;


	}
	return N;


}


enWinner WhoWinTheRound(stRoundInfo RoundInfo)
{

	if (RoundInfo.Player1Choice == RoundInfo.ComputerChoice)
		return enWinner::Drow;

	switch (RoundInfo.Player1Choice)
	{

	case enGameChoice::Stone:
		if (RoundInfo.ComputerChoice == enGameChoice::Paper)
		{
			return enWinner::Computer;

		}
		break;



	case enGameChoice::Paper:
		if (RoundInfo.ComputerChoice == enGameChoice::Scossors)
		{

			return enWinner::Computer;
		}
		break;


	case enGameChoice::Scossors:
		if (RoundInfo.ComputerChoice == enGameChoice::Stone)
		{
			return enWinner::Computer;

		}
		break;


	}


	//if you reache at this place it means the winner is the player1
	return enWinner::Player1;


}
enWinner WhoWinTheGame(short Player1WinTimes, short ComputerWinTimes)
{

	if (Player1WinTimes > ComputerWinTimes)
		return enWinner::Player1;
	else if (ComputerWinTimes > Player1WinTimes)
		return enWinner::Computer;
	else
		return enWinner::Drow;


}

enGameChoice ReadPlayerChoice()
{
	short Choice=1;
	do
	{
		cout << "\nenter your choice :  [1]:Paper, [2]:Stone, [3]:Scissors : ";
		cin >> Choice;



	} while (Choice < 1 || Choice>3);

	return (enGameChoice) Choice;


}
enGameChoice GetComputerChoice()
{

	return (enGameChoice)RandomNumber(1, 3);

}

void SetWinnerScreenColor(enWinner Winner)
{

	switch (Winner)
	{
	case enWinner::Player1:
		system("color 2F");//turn the screnn color to the green
		break;
	case enWinner::Computer:
		system("color 4F");//turn the screen color to the red
		break;
	case enWinner::Drow:
		system("color 6F");//turn the screen color to yellow
		break;
	}


}
void PrintRoundResult(stRoundInfo RoundInfo)
{

	cout << "\n________________Round [" << RoundInfo.RoundNumber << "] ______________\n\n";
	cout << "Player 1 Choice : " << ChoiceName(RoundInfo.Player1Choice) << endl;
	cout << "Computer Choice : " << ChoiceName(RoundInfo.ComputerChoice) << endl;
	cout << "Round Winner : [" << RoundInfo.WinnerName << "]\n";
	cout << "____________________________________\n" << endl;
	SetWinnerScreenColor(RoundInfo.Winner);



}

stGameResults FillGameResults(short GameRounds, short Player1WinTimes, short ComputerWinTimes, short DrawTimes)
{

	stGameResults GameResults;

	GameResults.GameRounds = GameRounds;
	GameResults.Player1WinTimes = Player1WinTimes;
	GameResults.Computer2WinTimes = ComputerWinTimes;
	GameResults.DrawTimes = DrawTimes;
	GameResults.GameWinner = WhoWinTheGame(Player1WinTimes, ComputerWinTimes);
	GameResults.WinnerName = WinnerName(GameResults.GameWinner);
	return GameResults;

}
stGameResults PlayGame(short HowManyRounds)
{

	stRoundInfo RoundInfo;

	short Player1WinTimes = 0, ComputerWinTimes = 0, DrawTimes = 0;

	for (short GameRound = 1; GameRound <= HowManyRounds; GameRound++)
	{

		cout << "\nRound [" << GameRound << "] begins:\n";
		RoundInfo.RoundNumber = GameRound;
		RoundInfo.Player1Choice = ReadPlayerChoice();
		RoundInfo.ComputerChoice = GetComputerChoice();
		RoundInfo.Winner = WhoWinTheRound(RoundInfo);
		RoundInfo.WinnerName = WinnerName(RoundInfo.Winner);

		//increase win /Draw Counters

		if (RoundInfo.Winner == enWinner::Player1)
			Player1WinTimes++;
		else if (RoundInfo.Winner == enWinner::Computer)
			ComputerWinTimes++;
		else
			DrawTimes++;

		PrintRoundResult(RoundInfo);
	}
	return FillGameResults(HowManyRounds, Player1WinTimes, ComputerWinTimes, DrawTimes);



}


void ShowGameOverScreen()
{


	cout <<Tabs(2)<< "_______________________________________________________"<<BackslashN(1);
	cout <<Tabs(2)<< "                + + + G a m e O v e r + + +"<< BackslashN(1);
	cout <<Tabs(2)<< "_______________________________________________________"<< BackslashN(1);


}
void PrintGameResults()
{

	cout <<Tabs(2)<< "________________________________________________________"<< BackslashN(1);
	cout <<Tabs(2)<< "                   +++ Game Result +++ "<< BackslashN(1);
	cout <<Tabs(2)<< "--------------------------------------------------------"<< BackslashN(2);

}
void ResetScreen()
{

	system("cls");
	system("color 0F");

}
void ShowFinalGameResults(stGameResults GameResults)
{


	cout << Tabs(2) << "_____________________[ Game Results ]__________________\n\n";
	cout << Tabs(2) << "Game Rounds         : " << GameResults.GameRounds << endl;
	cout << Tabs(2) << "Player1 won times   : " << GameResults.Player1WinTimes << endl;
	cout << Tabs(2) << "Computer won times  : " << GameResults.Computer2WinTimes << endl;
	cout << Tabs(2) << "Drow Times          : " << GameResults.DrawTimes << endl;
	cout << Tabs(2) << "Final Winner        : " << GameResults.WinnerName << endl;
	cout << Tabs(2) << "_________________________________________________________\n";

	SetWinnerScreenColor(GameResults.GameWinner);
}
void StartGame()
{
	char PlayAgain = 'y';

	do
	{
		ResetScreen();
		stGameResults GameResults = PlayGame(ReadHowManyRounds());
		ShowGameOverScreen();
		ShowFinalGameResults(GameResults);
		cout << endl << Tabs(3) << "Do you want to play again? Y/N? ";
		cin >> PlayAgain;

	} while (PlayAgain == 'Y' || PlayAgain == 'y');





}

int main()
{

	srand((unsigned)time(NULL));
	StartGame();


	return 0;
}