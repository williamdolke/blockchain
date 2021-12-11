#include "Block.h"
#include "sha256.h"
#include <ctime>

Block::Block(uint32_t indexIn, const string &dataIn) : index(indexIn), data(dataIn) {
    nonce = 0;
    currentTime = time(nullptr);
    hash = calculateHash();
}

string Block::getHash() {
    return hash;
}

void Block::mineBlock(uint32_t difficulty) {
    char cstr[difficulty+1];
    for (uint32_t i=0; i<difficulty ; i++) {
        cstr[i] = '0';
    }

    cstr[difficulty] = '\0'; // String terminator character

    string str(cstr); // Convert character array to std::string

    do {
        nonce++;
        hash = calculateHash();
    } while (hash.substr(0, difficulty) != str);

    cout << "Block mined:" << hash << endl;
    cout << "Nonce: " << nonce << endl;
}

string Block::calculateHash() const {
    stringstream ss;
    ss << index << prevHash << currentTime << data << nonce;

    return sha256(ss.str());
}