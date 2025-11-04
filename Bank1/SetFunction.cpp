#include "SetFunctions.h"
#include "FstreamFunction.h"
#include <iostream>
#include <limits>
#include <cctype>
#include "UserInput.h"
#include "ClientFunction.h"


using namespace std;


namespace Damoni1337
{
    void SetAddNewClient()
    {
        char AddingMore = 'N';

        do
        {
            vector<stClient> vClients = LoadDatafromfile();

            string AccountNumber = ReadAccountNumber();
            AccountNumber = CheckAccountExist(vClients, AccountNumber);

            stClient Client = ReadUpdateInfos();
            Client.AccountNumber = AccountNumber;

            SaveDataToFile(Client);

            cout << "\nClient added successfully.\n";

            cout << "\nDo you want to add more clients? (Y/N): ";
            cin >> AddingMore;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

        } while (toupper(AddingMore) == 'Y');
    }

    void SetDeleteClient()
    {
        string AccountNumber = ReadAccountNumber();
        vector<string> vClients = LoadFileLines();


        for (string& sClientData : vClients)
        {
            if (sClientData.find(AccountNumber) != string::npos)
            {
                if (DeleteClientAndUpdateFile(sClientData))
                {
                    cout << "\nClient Deleted Successfully.\n";

                }
                else
                {
                    cout << "\nClient Not Deleted.\n";
                }
                break;
            }
        }
    }

    void SetUpdateClient()
    {
        string AccountNumber = ReadAccountNumber();
        vector<string> vClients = LoadFileLines();

        for (string& sClientData : vClients)
        {
            if (sClientData.find(AccountNumber) != string::npos)
            {
                if (UpdateClientAndUpdateFile(sClientData))
                {
                    cout << "\nClient Updated Successfully.\n";
                }
                else
                {
                    cout << "\nClient Not Updated.\n";
                }
                break;
            }
        }

    }

    void SetFindClient(string AccountNumber)
    {
        AccountNumber = ReadAccountNumber();
        stClient C;
        vector<stClient> vClients = LoadDatafromfile();

        if (isFindedAccount(AccountNumber, vClients, C))
        {
            PrintClientCard(C);
        }
        else
        {
            cout << "\nClient with Account Number [" << AccountNumber << "] is not found!\n";
        }
    }

}
