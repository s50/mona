#include <string>
#include <fstream>
#include "QuoteFilterTest.h"

CPPUNIT_TEST_SUITE_REGISTRATION(QuoteFilterTest);

using namespace std;
using namespace util;
using namespace monash;

void QuoteFilterTest::setUp()
{
}

void QuoteFilterTest::tearDown()
{
}

void QuoteFilterTest::testFilter()
{
    char buf[1024];
    YAML yaml;
    loadYAML("test_cpp/quote_filter.yml", yaml);

    if (yaml.size() == 0)
    {
        fprintf(stderr, "bad yaml!\n");
    }
    for (int i = 0; i < yaml.size(); i++)
    {
        strings* s = yaml[i];
        if (s->size() != 2)
        {
            fprintf(stderr, "bad yaml!\n");
        }

        String before  = s->at(0).c_str();
        String after   = s->at(1).c_str();
        QuoteFilter f;
        String ret = f.filter(before);
        sprintf(buf, "[result]\n%s unmatch\n [expected]\n%s\n", ret.data(), after.data());
        CPPUNIT_ASSERT_MESSAGE(buf, ret == after);
    }
}
