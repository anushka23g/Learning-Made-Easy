/*This header file contains the classes of all the objects used. */
#include <bits/stdc++.h>

using namespace std;

class topic
{
public:
    string name;
    int count = 0;
    int priority;
    int difficulty;
    double time;
    int weightage;
    int imp;
};

class subject
{
public:
    string sname;
    topic c[];
    int credits;
    int prep;
    double stime;
    int imp;
    float profit;
    int examdate;
    int time_left;
    int topics;
    int diff;
};