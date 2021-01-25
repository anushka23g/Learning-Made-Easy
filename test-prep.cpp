
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
     topic c[];
    int credits;
    int prep;
    int prepp;
    float stime;
    int imp;
    float profit;
    int examdate;
    int time_left;
    int topics;
    int diff;
    float ttime;
    float atime;
    double lrate;
    float pptime;
    float rtime;


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
    int k=1;
    for (int i=n-1; i>=0; i--)
	{
		if(slot[i])
		{
			cout <<k<<". ";
			cout << arr[result[i]].sname << "\n";
			k++;
		}
	}

   /* for (int i=n-1; i>=0; i++)
      {
          if (slot[i]){ cout <<i;
         cout << arr[result[i]].sname << "\n";}
      }*/
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
                 cout<<"\n--------------------------------"<<endl;
                 cout<<"For "<<arr[i].name<<": "<<endl;


            }
           if(arr[i].count==1)
            {
           float trev=arr[i].time/2;
            float tpaper=arr[i].time/4;
            float tdoubts=arr[i].time/4;
           if(trev<1)
           {
               trev*=60;
               tpaper*=60;
               tdoubts*=60;
           //cout<<"\n------------------------------------------------------"<<endl;
           cout<<"You can revise the topic "<<arr[i].name<< " in "<<trev<<" minutes"<<endl;
           //cout<<"\n-----------------------------------------------------------------------------------------------"<<endl;
           cout<<"Do not forget to take a look at last year questions for this topic in the next "<<tpaper<<" minutes"<<endl;
           //cout<<"\n------------------------------------------------------------------------------------"<<endl;
           cout<<"Try to clear your doubts about this topic in the next "<<tdoubts<<" minutes"<<"\n"<<endl;

           }

           else if((tpaper<1)&&(trev>=1))
           {
               tpaper*=60;
               tdoubts*=60;
           //cout<<"\n------------------------------------------------------"<<endl;
           cout<<"You can revise the topic "<<arr[i].name<< " in "<<trev<<" hours"<<endl;
           //cout<<"\n-----------------------------------------------------------------------------------------------"<<endl;
           cout<<"Do not forget to take a look at last year questions for this topic in the next "<<tpaper<<" minutes"<<endl;
           //cout<<"\n------------------------------------------------------------------------------------"<<endl;
           cout<<"Try to clear your doubts about this topic in the next "<<tdoubts<<" minutes"<<"\n"<<endl;
           }

            else
           {
           //cout<<"\n------------------------------------------------------"<<endl;
           cout<<"You can revise the topic "<<arr[i].name<< " in "<<trev<<" hours"<<endl;
           //cout<<"\n-----------------------------------------------------------------------------------------------"<<endl;
           cout<<"Do not forget to take a look at last year questions for this topic in the next "<<tpaper<<" hours"<<endl;
           cout<<"\n------------------------------------------------------------------------------------"<<endl;
           cout<<"Try to clear your doubts about this topic in the next "<<tdoubts<<" hours"<<"\n"<<endl;}

            }
        }

         else
        {
            int remain = W - curMarks;
            finalvalue += arr[i].weightage * ((double) remain / arr[i].time);
            cout<<"You can only do some part of the chapter"<<endl;
            break;
        }
    if(curMarks>=W){return 0.0;}
    }

     return finalvalue;
}


void user_feedback(){
    int ratings;
    cout<<"----------------------------------------------------------------------------------";
    cout<<"\nPlease give us a feedback on the basis of the preparation schedule provided to you:\nRate us out of 5 where 1 symbolises lowest"<<endl;
    cin>>ratings;
    cout<<"______________"<<endl;
    cout<<"|Thank You!:D|"<<endl;
    cout<<"**************"<<endl;
}

/*

end

COMPLETE FOR 1 SUBJECT


 */





int main()
{
    int option;
    cout <<"                  ___________________________________________________________________________"<<endl;
    cout <<"                  |                               WELCOME TO                                |"<<endl;
    cout <<"                  |                                                                         |"<<endl;
    cout <<"                  |                           LEARNING MADE EASY                            |"<<endl;
    cout <<"                  |                                                                         |"<<endl;
    cout <<"                  |                                  MENU                                   |"<<endl;
    cout <<"                  |                                                                         |"<<endl;
    cout <<"                  | 1 to schedule a given subject in limited time                           |"<<endl;
    cout <<"                  | 2 to schedule studies for all subjects for a long period of time        |"<<endl;
    cout <<"                  | 3 for mixed schedule of all subjects(if you have enough time)           |"<<endl;
    cout <<"                  |                                                                         |"<<endl;
    cout <<"                  |                                                                         |"<<endl;
    cout <<"                  |_________________________________________________________________________|"<<endl;
    cout << "\nEnter your required option: ";
    cin >> option;
    if (option == 1)

    {
        int n;
        cout << "---------------------------"<<endl;
        cout << "Enter the no. of topics: ";
        cin >> n;

        int total_diff = 0; // sp

        topic t[2 * n];
        cout << "----------------------------"<<endl;
        cout << "Enter name of each topic: "<<endl;

        for (int i = 0; i < n; i++)
        {
            cout<< "Topic "<<i+1<<": ";
            cin >> t[i].name;
        }
        cout << "----------------------------------------------------------";
        cout << "\nEnter priority of each topic i.e. expected weightage: "<<endl;
        cout << "'From 1-10_____1 being the easiest:' "<<endl;


        for (int i = 0; i < n; i++)
        {

            cout <<"For " <<t[i].name << " : ";
            cin >> t[i].priority;
            t[i].weightage = t[i].priority;
            t[i].count = 0;
        }
        cout << "-------------------------------------------------------"<<endl;
        cout << "Enter difficulty level of each topic according to you"<<endl;
        cout << "'From 1-10_____1 being the easiest:' "<<endl;

        for (int i = 0; i < n; i++)
        {
            cout <<"For " <<t[i].name << " : ";
            cin >> t[i].difficulty;
            total_diff = total_diff + t[i].difficulty;
        }

        total_diff = total_diff + total_diff / 2;
         cout<<endl;
        int total_time;   // tt
        int focused_time; // eff
        cout << "--------------------------------------------------------------"<<endl;
        cout << "\nEnter total time available to study this subject in hours: ";
        cin >> total_time;
        cout << "\n-----------------------------------------------------------------------"<<endl;
        cout << "How much you can resist yourself from using phone during exams?(1-10): ";
        cin >> focused_time;
        cout<<"\n";
        float available_time = total_time * focused_time / 10; //at
        cout << "---------------------------"<<endl;
        cout << "Total Allotted time: " << available_time << "\n";
        cout << "\nDifficulty Level: " << total_diff << "\n";
        float utilised_val = available_time / total_diff; //ut
        cout << "\nTime Utilization rate: " << utilised_val << "\n";

        for (int i = 0; i < n; i++)
        {
            t[i].time = utilised_val * t[i].difficulty / 10;
            //cout << t[i].name << " " << t[i].time * 10 << "\n";
        }

        int checksub;
       // cout << "The time is: ";
        cout << "\n-------------------------------------------------------------------------------";
        cout << "\nPlease check if you will be able to complete the topics in the given time: "<<endl;
        for (int i = 0; i < n; i++)
        {
            cout <<"For " <<t[i].name << ": " << t[i].time*10 <<" hours" <<"\n";
        }
        cout<<"\n--------------------------------------";
        cout<<"\nIf you are okay press 1 else press 0"<<endl;
        cout<<"Enter your choice: ";
        cin >> checksub;

        if (checksub == 0)
        {
            cout <<"\n----------------------------------"<<endl;
            cout << "You can enter the time manually: ";
            for (int i = 0; i < n; i++)
            {
                cout<<"For Topic "<<i+1<<": ";
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

       // cout << prepared; *No NEED*
       // return 0; *This Statement Stops the calling the feedback function*
    }

    else if (option == 2)

    {
        int n;
        cout<<  "----------------------------------";
        cout << "\nEnter Total Number of subjects: ";
        cin >> n;
        //cout<<  "----------------------------------";
        cout<<"\n"<<endl;
        subject s[n];
        int tcred = 0;
        cout<<  "----------------------------------------------------------"<<endl;
        cout << "Please Enter the Name and Credit points for each subject: \n"<<endl; ;
        for (int i = 0; i < n; i++)
        {
            cout<<"\nEnter the NAME for subject number- "<<i+1<<": ";
            cin >> s[i].sname ;
            cout<<"\nEnter the CREDIT POINTS for subject number- "<<i+1<<": ";
            cin >> s[i].credits;
            tcred += s[i].credits;
        }
        cout<<" \n"<<endl;

        //int date;

        //cout << "Enter today's date(Format: dd): ";
        //cin >> date;

        int tgive;
        cout<<  "--------------------------------------------------------------";
        cout << "\nHow much time can you give each day to studies(in hours): ";
        cin >> tgive;
        cout<<  "--------------------------------------------------------------";
        cout << "\nEnter number of days you can give for the following exams\n"<<endl;

        for (int i = 0; i < n; i++)
        {
            cout << s[i].sname << ":";
            cin >> s[i].examdate;
            s[i].time_left = s[i].examdate;
            s[i].ttime = s[i].time_left * tgive;
            cout<<endl;
        }

       // int ttime = s[0].time_left * tgive;
        cout<<  "----------------------------------------------------";
        cout << "\nWhat is your preparation level rate it from 1-10? \n10 being highest and 1 being the lowest: \n"<<endl;
        for(int i=0;i<n;i++)
        {
            cout << "For "<< s[i].sname << ": ";
            cin >> s[i].prep;
            s[i].prepp=100*s[i].prep/10;
           // cout<<"Prep Percentage: "<<s[i].prepp<<endl;
            }
        cout<<endl;
        cout<<  "---------------------------------------------------------------";
        cout << "\nHow much time did you took for doing that preparation(in hours)"<<endl;
        for(int i=0;i<n;i++)
        {
            cout << "For "<< s[i].sname << ": ";
            cin>> s[i].pptime;
        }
        int timp = 0;

        for (int i = 0; i < n; i++)
        {

            s[i].lrate=s[i].pptime/s[i].prepp ;
            //cout<<"Learning Rate= "<<s[i].lrate<<endl;
            s[i].imp = s[i].credits / ((s[i].prep) * (s[i].time_left));
            s[i].profit = s[i].credits / s[i].prep;
            timp += s[i].imp;
            s[i].rtime = (100-s[i].prepp)*s[i].lrate;;
            s[i].stime = s[i].credits * s[i].ttime/ s[i].prep;

            s[i].rtime = s[i].rtime + (s[i].stime/2);

                s[i].atime=s[i].ttime;


            cout<<endl;

           // cout<<"Subject Name: "<<s[i].sname<<"Subject Credit: "<<s[i].credits<<" "<<s[i].profit<<"Required Time "<<s[i].stime<<" "<<s[i].prep<<" "<<s[i].time_left<<endl;
        }
        //cout << "Complete the subjects in the following sequence to maximize your percentage: \n ";
        cout<<"\n\t--------------------------- Displaying Schedule Details ---------------------------\n"<<" ";
        cout<<"\n\t___________________________________________________________________________________"<<endl;
        cout<<setw(20)<<"Subject Name"<<setw(20)<<"Subject Credit"<<setw(25)<<"Required Time(hrs)"<<setw(25)<<"Available Time(hrs)";
        cout<<"\n\t-----------------------------------------------------------------------------------";
        for(int i=0;i<n;i++)
        {

            cout<<"\n\t___________________________________________________________________________________";
            cout<<"\n"<<setw(20)<<s[i].sname<<setw(15)<<s[i].credits<<setw(22)<<round(s[i].rtime)<<setw(22)<<round(s[i].atime);
            cout<<"\n\t___________________________________________________________________________________";
        }
       cout<<"\n\n";
       cout<<"------------------------------------------------------------------";
       cout<<"\nAccording to our algorithm the priority should be as follows"<<endl;
        printJobScheduling(s, n);
    }

    //mixed scheduling of all subjects

    else if (option == 3)
    {

        int ask;

        //do all difficult chapters together
        int n;
        cout << "\n---------------------------"<<endl;
        cout << "Enter total no. subjects: ";
        cin >> n;

        subject s[n];

        int ttopic = 0;
        cout << "\n-------------------------------------------------------------------------------"<<endl;
        cout << "Enter name of each Subject, their Credits & Number of Topics in each Subject: ";

        for (int i = 0; i < n; i++)
        {
            cout<<"\n---------------";
            cout<<"\nNumber: "<<i+1<<endl;
            cout<<"Subject Name: ";
            cin >> s[i].sname;
            cout<<"Subject Credit: ";
            cin>> s[i].credits;
            cout<<"Number of Topics in it: ";
            cin>> s[i].topics;
            cout<<endl;
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
            cout << "\n-----------------------------------------------------------------------------------------------"<<endl;
        for (int i = 0; i < n; i++)
        {

            cout << "Enter the name of each Topic with its importance in exam and Difficulty level according to you."<<endl;
            cout << "From 1-10_____1 being the easiest for the subject"<<endl;

            cout <<"For "<< s[i].sname << ": "<<endl;

            for (int j = 0; j < s[i].topics; j++)
            {
                cout<<"\n-------------------"<<endl;
                cout<<"Topic Number: "<<j+1<<endl;
                cout<<"Topic Name: ";
                cin >> it[y].name;
                cout<<"Topic Weightage: ";
                cin >> it[y].weightage;
                cout<<"Topic difficulty: ";
                cin >> it[y].difficulty;
                cout<<endl;

                it[y].imp = it[y].weightage * s[i].credits * it[y].difficulty;

                y++;
            }
        }

        cout << "\n----------------------------------------------------------------------------------------"<<endl;
        cout << "Do you want to do major chapters first ( press 1 ) or the most difficult ones (press 0)? ";
        cin >> ask;

        if (ask == 0)
        {

            //sort on the basis of difficulty
            sort(it, it + (n * ttopic), cmpDiff);
            cout << "\n----------------------------------------------------"<<endl;
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
            cout << "\n----------------------------------------------------"<<endl;
            cout << "Sorted by importance of each subject in exam: ";

            for (int i = (n * ttopic) - 1; i >= 0; i--)
            {

                cout << it[i].name << "\n";
            }
        }
    }
    else
    {
    	cout<<"\n-----------------------------------------"<<endl;
    	cout<<"The Option Number you chose is not their"<<endl;
    	cout<<"\n-------------------------------------"<<endl;
    	cout<<"Thank You! :)"<<endl;
    	return 0;
	}
    user_feedback();
    return 0;
}
=======
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

  
    for (int i=0;i<n;i++) {
    	cout<<"\n"<<i+1<<") "<<arr[i].sname;              // updated the function and it works correctly now(  error RTE before user feedback()  )
	}
	cout<<"\n";

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
                 cout<<arr[i].name<<" ";


            }
            cout<<"\n";
           if(arr[i].count==1)
            {
            float trev=arr[i].time/2;
           float tpaper=arr[i].time/4;
           float tdoubts=arr[i].time/4;

           cout<<"You can revise the topic  "	<<arr[i].name<< " in "<<trev<<" hours"<<"\n";

           cout<<"Do not forget to take a look at last year questions for this topic in the next "<<tpaper<<" hours"<<"\n";

           cout<<"Try to clear your doubts about this topic in next "<<tdoubts<<" hours"<<"\n";cout<<"\n";
           cout<<"--------------------------------------------------------\n";

            }
        }

         else
        {
            int remain = W - curMarks;
            finalvalue += arr[i].weightage * ((double) remain / arr[i].time);
            cout<<"You can only do some part of the chapter ";
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
        cout<<"--------------------------------------------------------\n";
        int total_diff = 0; // sp

        topic t[2 * n];

        cout << "Enter name of each topic: \n";

        for (int i = 0; i < n; i++)
        {
        	cout<<i+1<<") ";
            cin >> t[i].name;
        }

        cout << "--------------------------------------------------------\nEnter priority of each topic i.e. expected weightage: \n";

        for (int i = 0; i < n; i++)
        {

            cout << t[i].name << " : ";
            cin >> t[i].priority;
            t[i].weightage = t[i].priority;
            t[i].count = 0;
        }

        cout << "--------------------------------------------------------\n";
		cout<<"Enter difficulty level of each topic based on your own understanding from(1-10) 1 being the easiest: \n";

        for (int i = 0; i < n; i++)
        {
            cout << t[i].name << " : ";
            cin >> t[i].difficulty;
            total_diff = total_diff + t[i].difficulty;
        }

        total_diff = total_diff + total_diff / 2;

        float total_time;   // tt
        float focused_time; // eff
        cout << "--------------------------------------------------------\nEnter total time available to study this subject in hours: ";
        cin >> total_time;

        cout << "--------------------------------------------------------\nHow much you can resist yourself from using phone during exams?(1-10): ";
        cin >> focused_time;
        
        cout<<"\n--------------------------------------------------------\n";
        
        float available_time = total_time * focused_time / 10; //at
        cout << "Allotted time: " << available_time << "\n";
        cout << "Difficulty Level: " << total_diff << "\n";
        float utilised_val = available_time / total_diff; //ut
        cout << "Utilization Time: " << utilised_val << "\n";
        
        cout<<"--------------------------------------------------------\n";
        
        for (int i = 0; i < n; i++)
        {
            t[i].time = utilised_val * t[i].difficulty / 10;
            cout << t[i].name << " ---> " << t[i].time * 10 << "\n";
        }
        
        cout<<"--------------------------------------------------------\n";
        
        int checksub;
        cout << "The time is: \n";
        
        for (int i = 0; i < n; i++)
        {
            cout << t[i].name << " ---> " << t[i].time << "\n";
        }
        
        cout<<"\n--------------------------------------------------------\n";
        
        cout << "Please check if you will be able to complete the topics in the given time \nIf okay press 1 else press 0: ";
        cin >> checksub;
        
        cout<<"\n--------------------------------------------------------\n";
        
        if (checksub == 0)
        {
            cout << "You can enter the time manually: \n";
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

        cout << prepared<<"\n--------------------------------------------------------\n";
        //return 0;
    }

    else if (option == 0)

    {
        int n;

        cout << "Enter total no. subjects: ";
        cin >> n;

        subject s[n];
        int tcred = 0;

        cout << "Enter name and credits for each subject: \nPrint the name and the credits separating with a space \n";
        cout<<"--------------------------------------------------------\n";
        for (int i = 0; i < n; i++)
        {
        	cout<< i+1<<")  ";
            cin >> s[i].sname >> s[i].credits;
            tcred += s[i].credits;
        }
        int date;

        cout << "--------------------------------------------------------\nEnter today's date (Format: dd): ";
        cin >> date;
		int month;

		cout<<"Enter the month (Format: mm): ";
		cin>>month;

        int tgive;
        cout << "--------------------------------------------------------\nHow much time can you give each day to studies(in hours): ";
        cin >> tgive;

        cout << "--------------------------------------------------------\nEnter the date and month for the following exams:  \n\n";

        for (int i = 0; i < n; i++)
        {
            //cout << s[i].sname << ":\nenter date: \n";
            cout<< "Date of the exam for subject "<<s[i].sname<<":  ";
            cin >> s[i].examdate;
//		    cout << "\nenter month: ";
            cout<< "Month of the exam for subject "<<s[i].sname<<":  ";
            cin>>s[i].exam_month;


            if(s[i].exam_month==month){//calculating the time left if the exam is on the same month as the date
            	s[i].time_left=s[i].examdate-date+1;
            	//cout<<"time left:"<<" "<<s[i].time_left<<" days"<<endl;
			}

			else if(s[i].exam_month>month){//calculating the time left if the exam is scheduled in later months
            	if(s[i].examdate>date){
            		int month_value=s[i].exam_month-month;
            		s[i].time_left = month_value*(30+abs(s[i].examdate - date + 1));
            		
        		}
        		else{
        			s[i].time_left=30-date+s[i].examdate+1;
        			//cout<<"time left: "<<s[i].time_left<<" days"<<endl;
        		}
        	}
        }
        cout<<"--------------------------------------------------------\n";
        for (int i=0 ; i<n ; i++ ) 
        {
        cout<<"time left for "<<s[i].sname<<" subject : "<<s[i].time_left<<" days"<<endl;	
		}
		cout<<"--------------------------------------------------------\n";
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
        cout << "Complete the subjects in the following sequence to maximize your percentage:\n--------------------------------------------------------\n";

        printJobScheduling(s, n);
        cout<<"--------------------------------------------------------\n";
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
        cout << "--------------------------------------------------------\nEnter name of the subject,credits and no. of topics in each subject: \n";

        for (int i = 0; i < n; i++)
        {
        	cout<<i+1<<") ";
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

            cout << "Enter name of each topic with its  weightage in exam and difficulty level for you \n(from 1-10  1 being the easiest) for the subject\n\n ";

            cout << s[i].sname << ": \n";

            for (int j = 0; j < s[i].topics; j++)
            {
            	cout<<"Topic "<<j+1<<") ";
                cin >> it[y].name >> it[y].weightage >> it[y].difficulty;

                it[y].imp = it[y].weightage * s[i].credits * it[y].difficulty;

                y++;
            }
            cout<<"\n--------------------------------------------------------\n";
        }
        
        
        
        cout << "Do you want to do major chapters first ( press 1 ) or the most difficult ones (press 0)? ";
        cin >> ask;
        cout<<"--------------------------------------------------------\n";
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
        cout<<"--------------------------------------------------------\n";
    }
    user_feedback();
    return 0;
}

