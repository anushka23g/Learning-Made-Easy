/*This file contains all the functions used by the program*/
#include <bits/stdc++.h>
#include "include/classes.h"

using namespace std;

void printJobScheduling(subject arr[], int n);

double fractionalKnapsack(int W, topic arr[], int n);

bool cmp(topic a, topic b)
{
    double r1 = (double)a.priority / a.time;
    double r2 = (double)b.priority / b.time;
    return r1 > r2;
}

bool cmpsub(subject a, subject b)
{
    return (a.credits < b.credits);
}
bool cmpDate(subject s1, subject s2)
{
    return s1.time_left < s2.time_left;
}

bool cmpDiff(topic a, topic b)
{
    return (a.difficulty < b.difficulty);
}
bool cmpImp(topic a, topic b)
{
    return (a.imp < b.imp);
}

bool comparison(subject a, subject b)
{
    return (a.imp > b.imp);
}

void user_feedback()
{
    int ratings;
    cout << "Please give us a feedback on the basis of the preparation schedule provided to you:\nRate us out of 5 where 1 symbolises lowest\n";
    cout << "Enter the rating: ";
    cin >> ratings;
    cout << "Thank you,:)";
}
/*
void printJobScheduling(subject arr[], int n)
{
    sort(arr, arr+n, comparison);
    int result[n];
    bool slot[n];
    for (int i=0; i<n; i++)
        slot[i] = false;
    for (int i=0; i<n; i++)
    {
       for (int j=min(n, arr[i].time_left)-1; j>=0; j--)
       {
          if (slot[j]==false)
          {
             result[j] = i;  // Add this job to result
             slot[j] = true; // Make this slot occupied
             break;
          }
       }
    }
    for (int i=0; i<n; i++)
       if (slot[i])
         cout << arr[result[i]].sname << " ";
}
*/

void printJobScheduling(subject arr[], int n)
{

    sort(arr, arr + n, comparison);

    int result[n];
    bool slot[n];

    for (int i = 0; i < n; i++)
        slot[i] = false;

    for (int i = 0; i < n; i++)
    {

        for (int j = min(n, arr[i].time_left) - 1; j >= 0; j--)
        {

            if (slot[j] == false)
            {
                result[j] = i;  // Add this job to result
                slot[j] = true; // Make this slot occupied
                break;
            }
        }
    }

    for (int i = n - 1; i >= 0; i++)
    {
        if (slot[i])
        {
            cout << i;
            cout << arr[result[i]].sname << "\n";
        }
    }
}

double fractionalKnapsack(float W, topic arr[], int n)
{
    sort(arr, arr + n, cmp);

    int curMarks = 0;        // Current weight in knapsack
    double finalvalue = 0.0; // Result (value in Knapsack)

    for (int i = 0; i < n; i++)
    {
        if (curMarks + arr[i].time <= W)
        {
            curMarks += arr[i].time;
            finalvalue += arr[i].weightage;
            if (arr[i].count == 0)
            {
                cout << arr[i].name;
            }
            if (arr[i].count == 1)
            {
                float trev = arr[i].time / 2;
                float tpaper = arr[i].time / 4;
                float tdoubts = arr[i].time / 4;

                cout << "You can revise the topic" << arr[i].name << "in " << trev << " hours"
                     << "\n";

                cout << "Do not forget to take a look at last year questions for this topic in the next" << tpaper << " hours"
                     << "\n";

                cout << "Try to clear your doubts about this topic in next" << tdoubts << " hours"
                     << "\n";
                cout << "\n";
            }
        }

        else
        {
            int remain = W - curMarks;
            finalvalue += arr[i].weightage * ((double)remain / arr[i].time);
            cout << "You can only do some part of the chapter";
            break;
        }
        if (curMarks >= W)
        {
            return 0.0;
        }
    }

    return finalvalue;
}
