#include "EncryptionAdapter.h"


namespace systelab { namespace encryption { namespace caeser_cypher {

	EncryptionAdapter::EncryptionAdapter() = default;
	EncryptionAdapter::~EncryptionAdapter() = default;

	std::string EncryptionAdapter::encryptString(const std::string& key, const std::string& input) const
	{
		std::string output;
		
		unsigned int keyLength = key.size();
		unsigned int inputLength = input.size();
		for (unsigned int i = 0; i < inputLength; i++)
		{
			output += input[i] + keyLength;
		}
		
		return output;
	}

	std::string EncryptionAdapter::decryptString(const std::string& key, const std::string& input) const
	{
		std::string output;
		
		unsigned int keyLength = key.size();
		unsigned int inputLength = input.size();
		for (unsigned int i = 0; i < inputLength; i++)
		{
			output += input[i] - keyLength;
		}
		
		return output;
	}

}}}
