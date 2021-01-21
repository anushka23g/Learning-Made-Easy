#include <bits/stdc++.h>

using namespace std;


class topic
{
public:
    string name;
    int count=0;
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
     topic c[20];
    int credits;
    int prep;
    float stime;
    int imp;
    float profit;
    int examdate;
    int exam_month;
    int time_left;
    int topics;
    int diff;
	int s[100];
};
void printJobScheduling(subject arr[], int n);

double fractionalKnapsack(int W, topic arr[], int n);

bool cmp(topic a, topic b)
{
    double r1 = (double)a.priority / a.time;
    double r2 = (double)b.priority / b.time;
    return r1 > r2;
}

bool cmpsub(subject a,subject b)
{
    return (a.credits<b.credits);

}
bool cmpDate(subject s1,subject s2)
{
    return s1.time_left<s2.time_left;

}


bool cmpDiff(topic a,topic b)
{
    return (a.difficulty<b.difficulty);

}
bool cmpImp(topic a,topic b)
{
    return (a.imp<b.imp);

}



bool comparison(subject a, subject b)
{
     return (a.imp > b.imp);
}



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


    for (int i=n-1; i>=0; i--)
      {
          if (slot[i])
		  {
		      cout << arr[result[i]].sname << "\n";
          }
      }
}



double fractionalKnapsack(float W, topic arr[], int n)
{
     sort(arr, arr + n, cmp);


    int curMarks = 0;  // Current weight in knapsack
    double finalvalue = 0.0; // Result (value in Knapsack)

     for (int i = 0; i < n; i++)
    {
         if (curMarks + arr[i].time <= W)
        {
            curMarks += arr[i].time;
            finalvalue += arr[i].weightage;
           if(arr[i].count==0)
            {
                 cout<<arr[i].name;


            }
           if(arr[i].count==1)
            {
            float trev=arr[i].time/2;
           float tpaper=arr[i].time/4;
           float tdoubts=arr[i].time/4;

           cout<<"You can revise the topic"<<arr[i].name<< "in "<<trev<<" hours"<<"\n";

           cout<<"Do not forget to take a look at last year questions for this topic in the next"<<tpaper<<" hours"<<"\n";

           cout<<"try to clear your doubts about this topic in next"<<tdoubts<<" hours"<<"\n";cout<<"\n";

            }
        }

         else
        {
            int remain = W - curMarks;
            finalvalue += arr[i].weightage * ((double) remain / arr[i].time);
            cout<<"You can only do some part of the chapter";
            break;
        }
    if(curMarks>=W){return 0.0;}
    }

     return finalvalue;
}



void user_feedback(){
    int ratings;
    cout<<"Please give us a feedback on the basis of the preparation schedule provided to you:\nRate us out of 5 where 1 symbolises lowest\n";
    cin>>ratings;
    cout<<"Thank you,:)";
}


/*
end
COMPLETE FOR 1 SUBJECT
 */





int main()
{
    int option;
    cout << "------------MENU------------\n";
    cout << "\nEnter the number as follows:\n";
    cout << "0 to schedule studies for all subjects for a long period of time\n1 to schedule a given subject in limited time\n2 for mixed schedule of all subjects(if you have enough time)";
    cout << "\n----  ";
    cin >> option;
    if (option == 1)

    {
        int n;
        cout << "Enter the no. of topics: ";
        cin >> n;

        int total_diff = 0; // sp

        topic t[2 * n];

        cout << "Enter name of each topic: ";

        for (int i = 0; i < n; i++)
        {
            cin >> t[i].name;
        }

        cout << "Enter priority of each topic i.e. expected weightage: ";

        for (int i = 0; i < n; i++)
        {

            cout << t[i].name << " : ";
            cin >> t[i].priority;
            t[i].weightage = t[i].priority;
            t[i].count = 0;
        }

        cout << "Enter difficulty level of each topic based on your own understanding from(1-10) 1 being the easiest: ";

        for (int i = 0; i < n; i++)
        {
            cout << t[i].name << " : ";
            cin >> t[i].difficulty;
            total_diff = total_diff + t[i].difficulty;
        }

        total_diff = total_diff + total_diff / 2;

        float total_time;   // tt
        float focused_time; // eff
        cout << "Enter total time available to study this subject in hours: ";
        cin >> total_time;

        cout << "How much you can resist yourself from using phone during exams?(1-10): ";
        cin >> focused_time;

        float available_time = total_time * focused_time / 10; //at
        cout << "Allotted time: " << available_time << "\n";
        cout << "Difficulty Level: " << total_diff << "\n";
        float utilised_val = available_time / total_diff; //ut
        cout << "Utilization Time: " << utilised_val << "\n";

        for (int i = 0; i < n; i++)
        {
            t[i].time = utilised_val * t[i].difficulty / 10;
            cout << t[i].name << " " << t[i].time * 10 << "\n";
        }

        int checksub;
        cout << "The time is: ";
        cout << "Please check if you will be able to complete the topics in the given time \nIf okay press 1 else press 0: ";
        for (int i = 0; i < n; i++)
        {
            cout << t[i].name << " " << t[i].time << "\n";
        }

        cin >> checksub;

        if (checksub == 0)
        {
            cout << "You can enter the time manually: ";
            for (int i = 0; i < n; i++)
            {
                cin >> t[i].time;
            }
        }

        for (int i = n; i < 2 * n; i++)
        {
            t[i].name = t[i - n].name;
            t[i].priority = t[i - n].priority / 2;
            t[i].weightage = 0;
            t[i].difficulty = t[i - n].difficulty / 2;
            t[i].time = t[i - n].time / 2.0;
            t[i].count = 1;
        }

        //                (value,weight)----(priority,time)

        //                 capacity-tt

        //revision of each subject has a priority and time half of the subject

        double prepared = fractionalKnapsack(available_time, t, 2 * n);

        cout << prepared;
        return 0;
    }

    else if (option == 0)

    {
        int n;

        cout << "Enter total no. subjects: ";
        cin >> n;

        subject s[n];
        int tcred = 0;

        cout << "Enter name and credits for each subject: ";
        for (int i = 0; i < n; i++)
        {

            cin >> s[i].sname >> s[i].credits;
            tcred += s[i].credits;
        }
        int date;

        cout << "Enter today's date (Format: dd): ";
        cin >> date;
		int month;

		cout<<"Enter the month (Format: mm): ";
		cin>>month;

        int tgive;

        cout << "How much time can you give each day to studies(in hours): ";
        cin >> tgive;

        cout << "Enter the date and month for the following exams:  \n";

        for (int i = 0; i < n; i++)
        {
            cout << s[i].sname << ":\nenter date: ";

            cin >> s[i].examdate;
		    cout << "enter month: ";
            cin>>s[i].exam_month;


            if(s[i].exam_month==month){//calculating the time left if the exam is on the same month as the date
            	s[i].time_left=s[i].examdate-date+1;
            	cout<<"time left:"<<" "<<s[i].time_left<<" days"<<endl;
			}

			else if(s[i].exam_month>month){//calculating the time left if the exam is scheduled in later months
            	if(s[i].examdate>date){
            		int month_value=s[i].exam_month-month;
            		s[i].time_left = month_value*(30+abs(s[i].examdate - date + 1));
            		cout<<"time left: "<<s[i].time_left<<" days"<<endl;
        		}
        		else{
        			s[i].time_left=30-date+s[i].examdate+1;
        			cout<<"time left: "<<s[i].time_left<<" days"<<endl;
        		}
        	}
        }

        int ttime = s[0].time_left * tgive;
        cout << "How much previous preparation do you have on a scale of 1 to 10? \n10 being highest and 1 being the lowest: \n";

        int timp = 0;

        for (int i = 0; i < n; i++)
        {
            cout << s[i].sname << ": ";
            cin >> s[i].prep;
            s[i].imp = s[i].credits*ttime / ((s[i].prep) * (s[i].time_left)); // calculating importance of each subject
            s[i].profit = s[i].credits / s[i].prep;
            timp += s[i].imp;

            s[i].stime = s[i].credits * ttime / s[i].prep;

            //cout<<s[i].sname<<" "<<s[i].credits<<" "<<s[i].profit<<" "<<s[i].stime<<" "<<s[i].prep<<" "<<s[i].time_left<<endl;
        }
        cout << "Complete the subjects in the following sequence to maximize your percentage:\n";

        printJobScheduling(s, n);
    }

    //mixed scheduling of all subjects

    else if (option == 2)
    {

        int ask;

        //do all difficult chapters together
        int n;

        cout << "Enter total no. subjects: ";
        cin >> n;

        subject s[n];

        int ttopic = 0;
        cout << "Enter name of the subject,credits and no. of topics in each subject: ";

        for (int i = 0; i < n; i++)
        {

            cin >> s[i].sname >> s[i].credits >> s[i].topics;
            ttopic += s[i].topics;
        }
        cout << "\n";

        sort(s, s + n, cmpsub);

        //cout<<"sorted on basis of course credits";

        //cout<<"ttopic is"<<ttopic;
        /*
    for(int i=0;i<n;i++)
    {
        cout<<s[i].sname<<"\n";
        cout<<s[i].topics<<"\n";}*/

        topic it[ttopic * n];
        int y = 0;

        for (int i = 0; i < n; i++)
        {

            cout << "Enter name of each topic with its  weightage in exam and difficulty level for you (from 1-10 \n 1 being the easiest) for the subject\n ";

            cout << s[i].sname << ": ";

            for (int j = 0; j < s[i].topics; j++)
            {
                cin >> it[y].name >> it[y].weightage >> it[y].difficulty;

                it[y].imp = it[y].weightage * s[i].credits * it[y].difficulty;

                y++;
            }
        }

        cout << "Do you want to do major chapters first ( press 1 ) or the most difficult ones (press 0)? ";
        cin >> ask;

        if (ask == 0)
        {

            //sort on the basis of difficulty
            sort(it, it + (n * ttopic), cmpDiff);
            cout << "Sorted by difficulty in each topic faced by you:\n";

            for (int i = (n * ttopic) - 1; i >= 0; i--)
            {

                cout << it[i].name << "\n";
            }
        }
        else if (ask == 1)
        {
            //sort on the basis of importance

            sort(it, it + (n * ttopic), cmpImp);

            cout << "Sorted by importance of each subject in exam:\n";

            for (int i = (n * ttopic) - 1; i >= 0; i--)
            {

                cout << it[i].name << "\n";
            }
        }
    }
    user_feedback();
    return 0;
}
