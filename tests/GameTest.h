#ifndef GAME_TEST
#define GAME_TEST
#include <vector>
#include <iostream>
#include "test_case.h"
using namespace std;
class GameTest
{
    vector<TestCase *> tests;
    string test_name;
    string get_status_message(TestCase * test_case){
        return (test_case->passed ? "Ok" : "Failed: " + test_case->message);
    }
public:
    GameTest(string test_name){
        this->test_name = test_name;
    }

    void add_test(TestCase *test_case)
    {
        tests.push_back(test_case);
    }
    void run(){
        cout << test_name << " started.\n";
        for(int test_case = 0; test_case < tests.size(); test_case++){
            cout << "[Test " << test_case + 1 << "] " 
                << get_status_message(tests[test_case]) << "\n";
        }

        cout << test_name << " ended.\n";
    }
};

#endif