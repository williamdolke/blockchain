#ifndef BLOCKCHAIN_H
#define BLOCKCHAIN_H
#include <cstdint>
#include <vector>
#include "Block.h"

using namespace std;

class Blockchain {
    public:
        Blockchain();

        void addBlock(Block nextBlock);

    private:
        uint32_t difficulty;
        vector<Block> chain;

        Block getLastBlock() const;
};
#endif