#include "stdafx.h"
#include "CaeserCypherEncryptionAdapter/EncryptionAdapter.h"


using namespace testing;

namespace systelab { namespace encryption { namespace caeser_cypher { namespace unit_test {

	namespace {
		struct EncryptionAdapterTestData
		{
			std::string key;
			std::string decryptedString;
			std::string encryptedString;
		};
		
		std::vector<EncryptionAdapterTestData> testData = {
			{ "Key", "StringToEncrypt", "VwulqjWrHqfu|sw" }
		};
	}

	class EncryptionAdapterTest : public testing::TestWithParam<EncryptionAdapterTestData>
	{
	public:
		void SetUp()
		{
			m_encryptionAdapter = std::make_unique<EncryptionAdapter>();
		}

	protected:
		std::unique_ptr<IEncryptionAdapter> m_encryptionAdapter;
	};


	TEST_P(EncryptionAdapterTest, testEncryptStringReturnsExpectedValue)
	{
		ASSERT_EQ(GetParam().encryptedString, m_encryptionAdapter->encryptString(GetParam().key, GetParam().decryptedString));
	}

	TEST_P(EncryptionAdapterTest, testDecryptStringReturnsExpectedValue)
	{
		ASSERT_EQ(GetParam().decryptedString, m_encryptionAdapter->decryptString(GetParam().key, GetParam().encryptedString));
	}

	INSTANTIATE_TEST_CASE_P(Test, EncryptionAdapterTest, testing::ValuesIn(testData));
	
}}}}
