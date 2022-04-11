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
			{
				"Key",
				"StringToEncrypt",
				"VwulqjWrHqfu|sw"
			},
			{
				"SuperSecretKey",
				"Lorem ipsum dolor sit amet, consectetur adipiscing elit. Pellentesque sed "
				"fermentum est. Vestibulum vulputate sodales sodales.",
				"Z}\x80s{.w~\x81\x83{.r}z}\x80.\x81w\x82.o{s\x82:.q}|\x81sq\x82s\x82\x83\x80.orw~w\x81qw|u.szw\x82<.^sz"
				"zs|\x82s\x81\x7F\x83s.\x81sr.ts\x80{s|\x82\x83{.s\x81\x82<.ds\x81\x82wp\x83z\x83{.\x84\x83z~\x83\x82"
				"o\x82s.\x81}rozs\x81.\x81}rozs\x81<"
			},
			{
				"aPmw6Uee{6hMg%:$",
				"{ \"name\": \"John\", \"age\": 30, \"car\": null }",
				"\x8B" "02~q}u2J02Z\x7Fx~2<02qwu2J0C@<02sq\x82" "2J0~\x85||0\x8D"
			},
			{
				"qXazxNRz{T,~s&wG5hST8x9",
				"<note><to>Tove</to><from>Jani</from><heading>Reminder</heading><body>Don't forget me this weekend!</body></note>",
				"S\x85\x86\x8B|US\x8B\x86Uk\x86\x8D|SF\x8B\x86US}\x89\x86\x84Uax\x85\x80SF}\x89\x86\x84US\x7F|x{"
				"\x80\x85~Ui|\x84\x80\x85{|\x89SF\x7F|x{\x80\x85~USy\x86{\x90U[\x86\x85>\x8B"
				"7}\x86\x89~|\x8B" "7\x84|7\x8B\x7F\x80\x8A" "7\x8E||\x82|\x85{8SFy\x86{\x90USF\x85\x86\x8B|U"
			},
			{
				"P:JXy{?wsAjh.^s^&)BXkpEsuty_TBJ9GzH5gytHd",
				"Vader: Obiwan never told you what happened to your father."
				"Luke: He told me enough; he told me you killed him!"
				"Vader: No. I am your father.",
				"\x7F\x8A\x8D\x8E\x9B" "cIx\x8B\x92\xA0\x8A\x97I\x97\x8E\x9F\x8E\x9BI\x9D"
				"\x98\x95\x8DI\xA2\x98\x9EI\xA0\x91\x8A\x9DI\x91\x8A\x99\x99\x8E\x97\x8E\x8DI"
				"\x9D\x98I\xA2\x98\x9E\x9BI\x8F\x8A\x9D\x91\x8E\x9BWu\x9E\x94\x8E"
				"cIq\x8EI\x9D\x98\x95\x8DI\x96\x8EI\x8E\x97\x98\x9E\x90\x91"
				"dI\x91\x8EI\x9D\x98\x95\x8DI\x96\x8EI\xA2\x98\x9EI\x94\x92\x95\x95\x8E\x8DI"
				"\x91\x92\x96J\x7F\x8A\x8D\x8E\x9B"
				"cIw\x98WIrI\x8A\x96I\xA2\x98\x9E\x9BI\x8F\x8A\x9D\x91\x8E\x9BW"
			}
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
		systelab::encryption::SecurityKey securityKey = []() { return GetParam().key; };
		ASSERT_EQ(GetParam().encryptedString, m_encryptionAdapter->encryptString(securityKey, GetParam().decryptedString));
	}

	TEST_P(EncryptionAdapterTest, testDecryptStringReturnsExpectedValue)
	{
		systelab::encryption::SecurityKey securityKey = []() { return GetParam().key; };
		ASSERT_EQ(GetParam().decryptedString, m_encryptionAdapter->decryptString(securityKey, GetParam().encryptedString));
	}

	INSTANTIATE_TEST_CASE_P(Test, EncryptionAdapterTest, testing::ValuesIn(testData));
	
}}}}
