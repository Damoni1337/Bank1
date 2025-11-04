#pragma once
#include <iostream>
#include <vector>
#include <string>
#include "Const&Struct.h"

using namespace std;

namespace Damoni1337
{
	void PrintClientCard(stClient Client);

	bool isAccountNumberTrue(stClient& C, string AccountNumber);

	bool IsAccountExist(const string& AccountNumber, const vector<stClient>& vClients);


	bool DeleteClientAndUpdateFile(string& Data);

	bool UpdateClientAndUpdateFile(string& Data);


	bool isFindedAccount(string Acc, vector<stClient>vClient, stClient& Results);

	vector<stClient>GetClientList();

	string CheckAccountExist(const vector<stClient>& vClients, string AccountNumber);
}
