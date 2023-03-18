#include<iostream>
#include <sstream>

#include "Transaction.hpp"
#include "Block.hpp"
#include "Blockchain.hpp"
#include<vector>

using namespace std;

Blockchain::Blockchain() {
    Transaction genesis("BFC","BFC",0);
    pending.push_back(genesis);

    Block gBlock(pending, time(nullptr), "In the beginning..");
    chain.push_back(gBlock);

    Transaction freeMoney("BFC","make money by mining",0);
    pending.push_back(freeMoney);

    difficulty = 4;
    miningReward = 10;
}

Block Blockchain::getLatestBlock() { 
    return chain.back();
}

void Blockchain::addTransaction(string src, string dst, int coins) {
    if(isChainValid()){
        int balance = getBalanceOfAddress(src);
        if(balance >= coins){           
            Transaction add(src, dst, coins);
            pending.push_back(add);
            cout << endl;
        }
        else{
            cout << "Error: " << src << " doesn't have adequate funds." << endl << endl;
        }

    }   
}

bool Blockchain::isChainValid() { 
    
    // cout << chain[0].hash << endl;
    // cout << chain[1].previousHash << endl;

    for(int i = 1; i < chain.size(); i++){
        stringstream diff;
        if(chain[i-1].getHash() != chain[i].getPreviousHash()){
            cout << "Hashes not equal" << endl;
            return false;
        }
        for(int j = 0; j < difficulty; j++){
            diff << "0";
        }
        if(diff.str() != chain[i].getHash().substr(0, difficulty)){
            cout << "Hash invalid" << endl;
            return false;
        }
    }
    return true;
}

bool Blockchain::minePendingTransactions(string minerAddress) {
    Block add(pending, time(NULL), chain.back().getHash());
    add.mineBlock(difficulty);
    pending.clear();
    chain.push_back(add);
    Transaction add1("BFC", minerAddress, miningReward);
    pending.push_back(add1);
    return true;
}

int Blockchain::getBalanceOfAddress(string address) {
    int balance = 0;
    for(int i = 0; i < chain.size(); i++){
        for(int j = 0; j < chain[i].getTransactions().size(); j++){
            if(chain[i].getTransactions()[j].getSender() == address){
                balance -= chain[i].getTransactions()[j].getAmount();
            }
            if(chain[i].getTransactions()[j].getReceiver() == address){
                balance += chain[i].getTransactions()[j].getAmount();

            }
        }
    }
    return balance;
}

void Blockchain::prettyPrint() {
    for(int i = 0; i < chain.size(); i++){
        cout << "Block " << i+1 << " " << "Transactions: " << endl;
        for(int j = 0; j < chain[i].getTransactions().size(); j++){
            cout << chain[i].getTransactions()[j].toString() << endl;
        }
    }
    cout << endl;
}
        