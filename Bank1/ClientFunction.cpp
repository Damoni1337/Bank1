#include <iostream>
#include <string>
#include <vector>
#include "ClientFunction.h"
#include "FstreamFunction.h"
#include <iomanip>
#include "UserInput.h"

using namespace std;


namespace Damoni1337
{
	void PrintClientCard(stClient Client)
	{
		cout << "\n\nThe following are the client details :\n\n";

		cout << "Account Number: " << Client.AccountNumber << endl;
		cout << "PIN Code: " << Client.PinCode << endl;
		cout << "Name: " << Client.Name << endl;
		cout << "Phone: " << Client.Phone << endl;
		cout << "Account Balance: " << Client.AccountBalance << endl;

	}

	bool isAccountNumberTrue(stClient& C, string AccountNumber)
	{
		return (AccountNumber == C.AccountNumber) == true;
	}

	bool IsAccountExist(const string& AccountNumber, const vector<stClient>& vClients)
	{
		for (const stClient& C : vClients)
		{
			if (C.AccountNumber == AccountNumber)
				return true;
		}
		return false;
	}



	bool DeleteClientAndUpdateFile(string& Data)
	{
		stClient Client;
		Client = ConvertLineToData(Data);
		PrintClientCard(Client);

		char sure;
		cout << "\nAre you sure you want to Delete this Client ? (Y/N) : ";
		cin >> sure;

		if (toupper(sure) == 'Y')
		{
			vector<string>vString = ClientWithOutDeleted(Data);
			SaveVectorToFile(vString);
			return true;
		}

		return false;
	}

	bool UpdateClientAndUpdateFile(string& Data)
	{
		stClient OriginalClient = ConvertLineToData(Data);
		PrintClientCard(OriginalClient);

		char sure;
		cout << "\nAre you sure you want to Update this Client ? (Y/N) : ";
		cin >> sure;
		cin.ignore(numeric_limits<streamsize>::max(), '\n');

		if (toupper(sure) == 'Y')
		{
			stClient UpdatedClient = ReadUpdateInfos();
			UpdatedClient.AccountNumber = OriginalClient.AccountNumber;


			vector<string> vLines = LoadFileLines();

			for (string& line : vLines)
			{
				stClient Temp = ConvertLineToData(line);
				if (Temp.AccountNumber == OriginalClient.AccountNumber)
				{
					line = ConvertDataToLine(UpdatedClient);
					break;
				}
			}


			SaveVectorToFile(vLines);

			return true;
		}

		return false;
	}



	bool isFindedAccount(string Acc, vector<stClient>vClient, stClient& Results)
	{
		for (stClient& C : vClient)
		{
			if (C.AccountNumber == Acc)
			{
				Results = C;
				return true;
			}
		}

		return false;
	}

	vector<stClient>GetClientList()
	{
		vector<stClient>vstClient = LoadDatafromfile();

		cout << "\n         Client List (" << vstClient.size() << ") Client(s).           \n";
		cout << "-------------------------------------------------------------------------------------------------------------\n";
		cout << left <<setw(15) << "| AccountNumber"
			<< left << setw(10) << "| Pin Code"
			<< left << setw(20) << "| Client Name"
			<< left << setw(15) << "| Phone"
			<< left << setw(10) << "| Balance" << endl;
		cout << "-------------------------------------------------------------------------------------------------------------\n";
		for (stClient& C : vstClient)
		{
			cout << left << "|" << setw(14) << C.AccountNumber
				<< left << "|" << setw(9) << C.PinCode
				<< left << "|" << setw(19) << C.Name
				<< left << "|" << setw(14) << C.Phone
				<< left << "|" << setw(9) << C.AccountBalance
				<< endl;
		}

		return vstClient;

	}

	string CheckAccountExist(const vector<stClient>& vClients, string AccountNumber)
	{
		while (IsAccountExist(AccountNumber, vClients))
		{
			cout << "Account Number [" << AccountNumber << "] already exists, Enter another Number: ";
			getline(cin, AccountNumber);	
		}

		return AccountNumber;
	}
}