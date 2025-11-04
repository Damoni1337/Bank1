#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include "SetFunctions.h"
#include "FstreamFunction.h"

using namespace std;


namespace Damoni1337
{

	const string ClientFile = "Client.txt";
	const string Separator = "#|*|#";



	vector<string>SplitString(string s1)
	{
		vector<string>vString;

		string sWord = "";

		short pos = 0;

		while ((pos = s1.find(Separator)) != string::npos)
		{
			sWord = s1.substr(0, pos);

			if (sWord != "")
			{
				vString.push_back(sWord);
			}

			s1.erase(0, pos + Separator.length());
		}

		if (s1 != "")
		{
			vString.push_back(s1);
		}

		return vString;
	}

	stClient ConvertLineToData(string s1)
	{
		vector<string>vString = SplitString(s1);

		stClient Client;

		Client.AccountNumber = vString[0];
		Client.PinCode = vString[1];
		Client.Name = vString[2];
		Client.Phone = vString[3];
		Client.AccountBalance = stod(vString[4]);

		return Client;
	}

	string ConvertDataToLine(stClient Client)
	{
		string s2 = "";

		s2 += Client.AccountNumber + Separator;
		s2 += Client.PinCode + Separator;
		s2 += Client.Name + Separator;
		s2 += Client.Phone + Separator;
		s2 += to_string(Client.AccountBalance);

		return s2;
	}

	void SaveDataToFile(stClient Client)
	{
		fstream MyFile;

		MyFile.open(ClientFile, ios::app);

		if (MyFile.is_open())
		{
			string Line = "";
			Line = ConvertDataToLine(Client);
			MyFile << Line << endl;
		}

		MyFile.close();
	}

	void SaveVectorToFile(vector <string> vFileContent)
	{
		fstream MyFile;

		MyFile.open(ClientFile, ios::out);

		if (MyFile.is_open())
		{
			for (string Line : vFileContent)
			{
				if (Line != "")
				{
					MyFile << Line << endl;
				}
			}
			MyFile.close();
		}
	}

	vector<string> LoadFileLines()
	{
		vector<string> vLines;
		fstream MyFile(ClientFile, ios::in);
		if (MyFile.is_open())
		{
			string Line;
			while (getline(MyFile, Line))
			{
				if (!Line.empty())
					vLines.push_back(Line);
			}
			MyFile.close();
		}
		return vLines;
	}

	vector<stClient> LoadDatafromfile()
	{
		vector<stClient>vClient;
		fstream MyFile;


		MyFile.open(ClientFile, ios::in);
		if (MyFile.is_open())
		{
			string line = "";
			stClient Client;
			while (getline(MyFile, line))
			{
				Client = ConvertLineToData(line);
				vClient.push_back(Client);
			}
			MyFile.close();
		}
		return vClient;
	}



	vector<string>ClientWithOutDeleted(string& Data)
	{
		fstream MyFile;
		vector<string>vString;

		MyFile.open(ClientFile, ios::in);

		if (MyFile.is_open())
		{
			string Line;

			while (getline(MyFile, Line))
			{
				if (Line != Data && Line != "")
				{
					vString.push_back(Line);
				}
			}

			MyFile.close();
		}

		return vString;
	}

	vector<string>ClientWithOutUpdated(string& Data)
	{
		fstream MyFile;
		vector<string>vString;

		MyFile.open(ClientFile, ios::in);

		if (MyFile.is_open())
		{
			string Line;

			while (getline(MyFile, Line))
			{
				if (Line != Data && Line != "")
				{
					vString.push_back(Line);
				}
			}

			MyFile.close();
		}

		return vString;
	}
}
