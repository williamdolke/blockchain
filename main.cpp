#include "Blockchain.h"

int main() {
    Blockchain bChain = Blockchain();

    cout << "Mining block 1..." << endl;
    bChain.addBlock(Block(1, " Transaction 1 data "));

    cout << "Mining block 2..." << endl;
    bChain.addBlock(Block(2, " Transaction 2 data "));

    cout << "Mining block 3..." << endl;
    bChain.addBlock(Block(3, " Transaction 3 data "));

    return 0;
}