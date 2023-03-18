#include <iostream>
#include <fstream>
#include "../code_1/Blockchain.hpp"

using namespace std;

int main(int argc, char* argv[])
{
    Blockchain buffCUoin;

    bool quit = false;
    while(!quit){
        string input;
        string senderName;
        string recipientName;
        string amount;
        string miner;
        int option = 0;

        cout << "-----Main Menu-----" << endl;
        cout << "1. Verify and Print Blockchain" << endl;
        cout << "2. Add Transaction" << endl;
        cout << "3. Mine Pending Transactions" << endl;
        cout << "4. Quit" << endl;

        getline(cin, input);
        option = stoi(input);

        switch(option){
            case 1:
                buffCUoin.isChainValid();
                buffCUoin.prettyPrint();
                break;
            case 2:
                cout << "Enter name of sender" << endl;
                getline(cin, senderName);
                cout << "Enter name of recipient" << endl;
                getline(cin, recipientName);
                cout << "Enter amount to be transferred" << endl;
                getline(cin, amount);
                cout << senderName << " paid " << recipientName << " " << amount << " BFC ... " << endl;
                buffCUoin.addTransaction(senderName, recipientName, stoi(amount));
                break;
            case 3:
                cout << "Who is mining?" << endl;
                getline(cin,miner);
                cout << miner << " is mining the block ... " << endl;
                buffCUoin.minePendingTransactions(miner);
                break;
            case 4: 
                quit = true;
                break;
        }
    }

    // PDF Test Case

    // buffCUoin.prettyPrint(); 

    // cout << "ashutosh mining first block ... " << endl;
    // buffCUoin.minePendingTransactions("ashutosh");

    // cout << "asa mining second block ... " << endl;
    // buffCUoin.minePendingTransactions("asa");

    // cout << "ashutosh paid maciej 2 BFC ... " << endl;
    // buffCUoin.addTransaction("ashutosh","maciej", 2);

    // cout << "maciej paid asa 5 BFC ... " << endl;
    // buffCUoin.addTransaction("maciej","asa", 5);

    // cout << "maciej mining third block ... " << endl;
    // buffCUoin.minePendingTransactions("maciej"); 

    // cout << "maciej paid asa 5 BFC ... " << endl;
    // buffCUoin.addTransaction("maciej","asa", 5);

    // buffCUoin.prettyPrint();


    // Main Test Case

    // cout << "ashutosh mining first block ... " << endl;
    // buffCUoin.minePendingTransactions("ashutosh");
    // buffCUoin.prettyPrint(); 
    
    // cout << "ashutosh paid maciej 1 BFC ... " << endl;
    // buffCUoin.addTransaction("ashutosh","maciej", 1);

    // cout << "ashutosh paid asa 1 BFC ... " << endl;
    // buffCUoin.addTransaction("ashutosh","asa", 1);
    // cout << "asa mining second block ... " << endl;
    // buffCUoin.minePendingTransactions("asa");
    // buffCUoin.prettyPrint(); 
    
    // cout << "asa paid ashutosh 1 BFC ... " << endl;
    // buffCUoin.addTransaction("asa","ashutosh", 1);    
    // cout << "ashutosh paid maciej 2 BFC ... " << endl;
    // buffCUoin.addTransaction("ashutosh","maciej", 2);
    
    // cout << "maciej mining third block ... " << endl;
    // buffCUoin.minePendingTransactions("maciej");
    // buffCUoin.prettyPrint(); 
    
    // cout << "ashutosh mining fourth block ... " << endl;
    // buffCUoin.minePendingTransactions("ashutosh");
    // buffCUoin.prettyPrint();
    
    return 0;
}