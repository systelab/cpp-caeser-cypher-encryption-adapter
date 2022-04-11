#include "CaeserCypherEncryptionAdapter/EncryptionAdapter.h"

#include <functional>
#include <iostream>
#include <memory>


int main(int argc, char *argv[])
{
    std::unique_ptr<systelab::encryption::IEncryptionAdapter> encryptionAdapter = std::make_unique<systelab::encryption::caeser_cypher::EncryptionAdapter>();

	std::string input = "This is a super-secret";
	systelab::encryption::SecurityKey key = [](){ return std::string("MySuperKey"); };
	std::string output = encryptionAdapter->encryptString(key, input);

	std::cout << "Input: " << input << std::endl;
	std::cout << "Key: " << key() << std::endl;
	std::cout << "Output: " << output << std::endl;

    return 0;
}
