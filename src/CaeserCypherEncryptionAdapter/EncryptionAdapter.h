#pragma once

#include "EncryptionAdapterInterface/IEncryptionAdapter.h"


namespace systelab { namespace encryption { namespace caeser_cypher {

	class EncryptionAdapter : public IEncryptionAdapter
	{
	public:
		EncryptionAdapter();
		virtual ~EncryptionAdapter();

		std::string encryptString(const SecurityKey& key, const std::string& input) const override;
		std::string decryptString(const SecurityKey& key, const std::string& input) const override;
	};

}}}
