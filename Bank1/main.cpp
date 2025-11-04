#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <vector>
#include "FstreamFunction.h"
#include "SetFunctions.h"
#include "Screen.h"
#include "UserInput.h"
#include "ClientFunction.h"

using namespace Damoni1337;
using namespace std;


namespace Damoni1337
{
	enum enMainMenuOption { ShowClientList = 1, AddNewClient = 2, DeleteClient = 3, UpdateClient = 4, FindClient = 5, Exit = 6 };


	void GetBackToMainMenu()
	{
		cout << "\nPress Enter to go back to the Main menu...\n";
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cin.get();
	}

	void ShowMainMenuOption()
	{
		system("cls");
		cout << "\n=============================================\n";
		cout << "               Main Menu Screen                  ";
		cout << "\n==============================================\n";
		cout << left << setw(5) << "[1]Show Client List." << endl;
		cout << left << setw(5) << "[2]Add New Client." << endl;
		cout << left << setw(5) << "[3]Delete Client." << endl;
		cout << left << setw(5) << "[4]Update Client Info." << endl;
		cout << left << setw(5) << "[5]Find Client." << endl;
		cout << left << setw(5) << "[6]Exit." << endl;
		cout << "\n==============================================\n";
	}

	enMainMenuOption ListOrder(enMainMenuOption MainMenu, string AccountNumber, vector<string>vsClient)
	{


		switch (MainMenu)
		{
		case enMainMenuOption::ShowClientList:
			system("cls");
			GetClientList();
			GetBackToMainMenu();
			break;
		case enMainMenuOption::AddNewClient:
			system("cls");
			AddNewClientScreen();
			SetAddNewClient();
			GetBackToMainMenu();
			break;
		case enMainMenuOption::DeleteClient:
			system("cls");
			DeleteClientScreen();
			SetDeleteClient();
			GetBackToMainMenu();
			break;
		case enMainMenuOption::UpdateClient:
			system("cls");
			UpdateClientInfoScreen();
			SetUpdateClient();
			GetBackToMainMenu();
			break;
		case enMainMenuOption::FindClient:
			system("cls");
			FindClientScreen();
			SetFindClient(AccountNumber);
			GetBackToMainMenu();
			break;
		case enMainMenuOption::Exit:
			system("cls");
			ExitScreen();
			system("Pause > 0");
			break;
		}

		return MainMenu;
	}




	void StartProgram()
	{
		vector<string>vsClient;
		string AccountNumber;
		enMainMenuOption MenuChoice;

		do
		{
			ShowMainMenuOption();

			short choise = ReadChoise(1, 6);
			MenuChoice = (enMainMenuOption)choise;

			ListOrder(MenuChoice, AccountNumber, vsClient);


		} while (MenuChoice != enMainMenuOption::Exit);
	}

}

int main()
{

	StartProgram();

	return 0;
}