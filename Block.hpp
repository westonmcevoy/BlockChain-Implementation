#pragma once
#include<iostream>
#include <vector>
#include "Transaction.hpp"

using namespace std;

class Block {
private:
    long long nonce; // An arbitrary number crucial in mining
    time_t timestamp; // Time when mined 
    string hash; // Hash of this block
    string previousHash; // Hash of previous block
    vector<Transaction> transactions; //vector of transactions 

public:
    Block(vector<Transaction> _transactions, time_t _timestamp, string _previousHash);
    void setPreviousHash(string hash);
    string calculateHash();
    void mineBlock(unsigned int nDifficulty);
    string toString();
    string getHash();
    string getPreviousHash();
    vector<Transaction> getTransactions();
};

