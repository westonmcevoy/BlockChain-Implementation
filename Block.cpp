#include<iostream>
#include <sstream>


#include "Transaction.hpp"
#include "Block.hpp"
#include "sha256.hpp"

using namespace std;

Block::Block(vector<Transaction> _transactions, time_t _timestamp, string _previousHash) {
    nonce = -1;
    transactions = _transactions;
    previousHash = _previousHash;
    timestamp = _timestamp;
    hash = calculateHash();
}

void Block::setPreviousHash(string _previousHash) {
    // TODO
}

string Block::calculateHash() {
    return sha256(toString());   
}

void Block::mineBlock(unsigned int difficulty) {
    string currentHash;
    stringstream ss;
    for(int j = 0; j < difficulty; j++){
        ss << "0";
    }
    do{
        nonce += 1000000;
        currentHash = calculateHash();
    }while(currentHash.substr(0, difficulty) != ss.str());
    hash = currentHash;
}

string Block::toString() {
    stringstream ss;
    ss << nonce << timestamp << previousHash;
    for(int i = 0; i < transactions.size(); i++){
        ss << transactions[i].toString();
    }
    return ss.str();
}

string Block::getHash(){
    return hash;
}

string Block::getPreviousHash(){
    return previousHash;
}

vector<Transaction> Block::getTransactions(){
    return transactions;
}