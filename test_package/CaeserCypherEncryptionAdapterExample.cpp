#include "CaeserCypherEncryptionAdapter/EncryptionAdapter.h"

#include <iostream>


int main(int argc, char *argv[])
{
    std::unique_ptr<systelab::encryption::IEncryptionAdapter> encryptionAdapter = std::make_unique<systelab::encryption::caeser_cypher::EncryptionAdapter>();

	std::string input = "This is a super-secret";
	std::string key = "MySuperKey";
	std::string output = encryptionAdapter->encryptString(input, key);

	std::cout << "Input: " << input << std::endl;
	std::cout << "Key: " << key << std::endl;
	std::cout << "Output: " << output << std::endl;

    return 0;
}
