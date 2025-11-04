#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "Const&Struct.h"

using namespace std;

namespace Damoni1337
{



	vector<string>SplitString(string s1);
	stClient ConvertLineToData(string s1);
	string ConvertDataToLine(stClient Client);
	void SaveDataToFile(stClient Client);
	void SaveVectorToFile(vector <string> vFileContent);
	vector<string> LoadFileLines();
	vector<stClient> LoadDatafromfile();

	vector<string>ClientWithOutDeleted(string& Data);
	vector<string>ClientWithOutUpdated(string& Data);

}