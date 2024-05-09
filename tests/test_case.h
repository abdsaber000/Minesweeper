#ifndef TEST_CASE
#define TEST_CASE
#include<string>
using namespace std;

struct TestCase{
    bool passed = false;
    string message;
    TestCase(bool passed , string message) : passed(passed) , message(message){}
};

#endif