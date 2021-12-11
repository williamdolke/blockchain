#include "Blockchain.h"

Blockchain::Blockchain() {
    chain.emplace_back(Block(0, "Genesis Block"));
    difficulty = 6;
}

void Blockchain::addBlock(Block nextBlock) {
    nextBlock.prevHash = getLastBlock().getHash();
    nextBlock.mineBlock(difficulty);
    chain.push_back(nextBlock);
}

Block Blockchain::getLastBlock() const {
    return chain.back();
}