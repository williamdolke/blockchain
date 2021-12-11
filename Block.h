#ifndef BLOCK_H
#define BLOCK_H
#include <iostream>
#include <cstdint>
#include <sstream>

using namespace std;

class Block {
    public:
        string prevHash;

        string getHash();
        void mineBlock(uint32_t difficulty);

        Block(uint32_t indexIn, const string &dataIn);
    
    private:
        uint32_t index;
        int64_t nonce;
        string data;
        string hash;
        time_t currentTime;

        string calculateHash() const;
};
#endif