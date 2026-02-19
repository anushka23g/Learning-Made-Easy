#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iomanip>
#include <cmath>
#include <cstdlib>
#include <QApplication>
#include <QMainWindow>
#include <QPushButton>
#include <QLabel>
#include <QLineEdit>
#include <QSpinBox>
#include <QInputDialog>
#include <QMessageBox>
#include <QProgressBar>
#include <QTimer>
#include <QVBoxLayout>
#include <QPalette>
#include <QPixmap>
#include <QTableWidget>
#include <QHeaderView>
#include <QTableWidgetItem>
#include <QDir>
#include <QCoreApplication>

using namespace std;

class MainMenuWindow;
class MainWindow;

class MainMenuWindow : public QWidget {
  Q_OBJECT
  public:
    explicit MainMenuWindow(QWidget *parent = nullptr);
  protected:
    void resizeEvent(QResizeEvent *event) override;
};

class topic {
public:
    string name;
    int count=0;
    int priority;
    int difficulty;
    double time;
    int weightage;
    int imp;
};

class subject {
public:
string sname;
     topic c[50];
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

bool cmp(topic a, topic b) {
    double r1 = (double)a.priority / a.time;
    double r2 = (double)b.priority / b.time;
    return r1 > r2;
}

bool cmpsub(subject a,subject b) {
    return (a.credits<b.credits);
}

bool cmpDate(subject s1,subject s2) {
    return s1.time_left<s2.time_left;
}

bool cmpDiff(topic a,topic b) {
    return (a.difficulty<b.difficulty);
}

bool cmpImp(topic a,topic b) {
    return (a.imp<b.imp);
}

bool comparison(subject a, subject b) {
     return (a.imp > b.imp);
}

void printJobScheduling(subject arr[], int n) {
    sort(arr, arr+n, comparison);
    for (int i=0;i<n;i++) {
    	cout<<"\n"<<i+1<<") "<<arr[i].sname;              // updated the function and it works correctly now(  error RTE before user feedback()  )
	}
	cout<<"\n";
    int result[n];
    bool slot[n];
    for (int i=0; i<n; i++)
        slot[i] = false;
    for (int i=0; i<n; i++) {
       for (int j=min(n, arr[i].time_left)-1; j>=0; j--) {
          if (slot[j]==false) {
             result[j] = i;  // Add this job to result
             slot[j] = true; // Make this slot occupied
             break;
          }
       }
    }
    for (int i=n-1; i>=0; i--) {
          if (slot[i]) {
		      cout << arr[result[i]].sname << "\n";
          }
      }
}

double fractionalKnapsack(float W, topic arr[], int n) {
     sort(arr, arr + n, cmp);
    int curMarks = 0;  // Current weight in knapsack
    double finalvalue = 0.0; // Result (value in Knapsack)
     for (int i = 0; i < n; i++) {
         if (curMarks + arr[i].time <= W) {
            curMarks += arr[i].time;
            finalvalue += arr[i].weightage;
           if(arr[i].count==0) {
                 cout<<"\n--------------------------------"<<endl;
                 cout<<"For "<<arr[i].name<<": "<<endl;
            }
           if(arr[i].count==1) {
           float trev=arr[i].time/2;
            float tpaper=arr[i].time/4;
            float tdoubts=arr[i].time/4;
           if(trev<1) {
               trev*=60;
               tpaper*=60;
               tdoubts*=60;
           //cout<<"\n------------------------------------------------------"<<endl;
           cout<<"You can revise the topic "<<arr[i].name<< " in "<<trev<<" minutes"<<endl;
           //cout<<"\n-----------------------------------------------------------------------------------------------"<<endl;
           cout<<"Do not forget to take a look at last year questions for this topic in the next "<<tpaper<<" minutes"<<endl;
           //cout<<"\n------------------------------------------------------------------------------------"<<endl;
           cout<<"Try to clear your doubts about this topic in the next "<<tdoubts<<" minutes"<<"\n"<<endl;
           } else if((tpaper<1)&&(trev>=1)) {
               tpaper*=60;
               tdoubts*=60;
           //cout<<"\n------------------------------------------------------"<<endl;
           cout<<"You can revise the topic "<<arr[i].name<< " in "<<trev<<" hours"<<endl;
           //cout<<"\n-----------------------------------------------------------------------------------------------"<<endl;
           cout<<"Do not forget to take a look at last year questions for this topic in the next "<<tpaper<<" minutes"<<endl;
           //cout<<"\n------------------------------------------------------------------------------------"<<endl;
           cout<<"Try to clear your doubts about this topic in the next "<<tdoubts<<" minutes"<<"\n"<<endl;
           } else {
           //cout<<"\n------------------------------------------------------"<<endl;
           cout<<"You can revise the topic "<<arr[i].name<< " in "<<trev<<" hours"<<endl;
           //cout<<"\n-----------------------------------------------------------------------------------------------"<<endl;
           cout<<"Do not forget to take a look at last year questions for this topic in the next "<<tpaper<<" hours"<<endl;
           cout<<"\n------------------------------------------------------------------------------------"<<endl;
           cout<<"Try to clear your doubts about this topic in the next "<<tdoubts<<" hours"<<"\n"<<endl;
           }
         }
       } else {
            int remain = W - curMarks;
            finalvalue += arr[i].weightage * ((double) remain / arr[i].time);
            cout<<"You can only do some part of the chapter"<<endl;
            break;
        }
    if(curMarks>=W) {
      return 0.0;
    }
   }
    return finalvalue;
}

void user_feedback() {
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

MainMenuWindow::MainMenuWindow(QWidget *parent) : QWidget(parent) {
    setWindowTitle("WELCOME TO LEARNING MADE EASY");
    resize(500, 500);
    QPixmap bg("Books_HD_(8314929977).jpg");
    if (!bg.isNull()) {
        QPalette palette;
        palette.setBrush(QPalette::Window, bg.scaled(this->size(), Qt::KeepAspectRatioByExpanding));
        setAutoFillBackground(true);
        setPalette(palette);
    }
    auto *layout = new QVBoxLayout(this);
    layout->setContentsMargins(40, 40, 40, 40);
    QLabel *title = new QLabel("<h2>WELCOME TO LEARNING MADE EASY</h2>", this);
    title->setAlignment(Qt::AlignCenter);
    title->setStyleSheet("color: #3e2c27; font-weight: 900; font-size: 34px;");
    QLabel *subtitle = new QLabel("<i>MENU</i>", this);
    subtitle->setAlignment(Qt::AlignCenter);
    subtitle->setStyleSheet("color: #3e2c27; font-size: 17px; font-weight: 600; margin-bottom: 15px;");
    layout->addWidget(title, 0, Qt::AlignCenter);
    layout->addWidget(subtitle, 0, Qt::AlignCenter);
    layout->addStretch();
    QStringList options = {
        "1. Schedule a given subject in limited time",
        "2. Schedule studies for all subjects for a long period of time",
        "3. Create a mixed schedule of all subjects (if you have enough time)"
    };
    for (const auto& option : options) {
        auto *btn = new QPushButton(option, this);
        btn->setStyleSheet("font-weight:bold; font-size:15px; color:#f8e5c0; background-color:#3e2c27; border-radius:8px; padding:10px;");
        btn->setCursor(Qt::PointingHandCursor);
        layout->addWidget(btn);
        connect(btn, &QPushButton::clicked, this, [this, option, options] {
            if (option.contains("1.")) {
                bool ok;
                int n = QInputDialog::getInt(this, "Input", "Enter the no. of topics: ", 1, 1, 50, 1, &ok);
                if (!ok) return;
                vector<topic> t(2 * n);
                int total_diff = 0;
                for (int i = 0; i < n; i++) {
                    QString name = QInputDialog::getText(this, "Input", "Enter name of each topic: " + QString::number(i + 1) + "Topic: ", QLineEdit::Normal, "", &ok);
                    if (!ok) return;
                    t[i].name = name.toStdString();
                    t[i].priority = QInputDialog::getInt(this, "Input", "Enter priority of each topic i.e. expected weightage: \n'From 1-10_____1 being the easiest:' ", 5, 1, 10, 1, &ok);
                    t[i].weightage = t[i].priority;
                    t[i].difficulty = QInputDialog::getInt(this, "Input", "Enter difficulty level of each topic according to you\n'From 1-10_____1 being the easiest:' ", 5, 1, 10, 1, &ok);
                    total_diff += t[i].difficulty;
                }
                total_diff = total_diff + total_diff / 2;
                double total_time = QInputDialog::getDouble(this, "Input", "Enter total time available to study this subject in hours: ", 10.0, 1.0, 500.0, 1, &ok);
                if (!ok) return;
                int focused_time_val = QInputDialog::getInt(this, "Input", "How much you can resist yourself from using phone during exams?(1-10): ", 7, 1, 10, 1, &ok);
                if (!ok) return;
                float available_time = total_time * focused_time_val / 10.0;
                float utilised_val = (total_diff > 0) ? (available_time / total_diff) : 0;
                for (int i = 0; i < n; i++) {
                    t[i].time = utilised_val * t[i].difficulty / 10.0;
                }
                QString statsMessage = QString(
                    "<b>Optimization Summary:</b><br><br>"
                    "Total Allotted Time: <b>%1 hours</b><br>"
                    "Total Difficulty Level: <b>%2</b><br>"
                    "Time Utilization Rate: <b>%3</b>")
                    .arg(available_time, 0, 'f', 2)
                    .arg(total_diff)
                    .arg(utilised_val, 0, 'f', 4);
                QMessageBox::information(this, "Summary", statsMessage);
                QString preview = "Please check if you will be able to complete the topics in the given time:<br>";
                for (int i = 0; i < n; i++) {
                    preview += "For " + QString::fromStdString(t[i].name) + ": <b>" + QString::number(t[i].time * 10, 'f', 2) + " hours</b><br>";
                }
                QMessageBox::StandardButton reply = QMessageBox::question(this, "If you are okay click Yes else click No", preview, QMessageBox::Yes | QMessageBox::No);
                if (reply == QMessageBox::No) {
                    QMessageBox::information(this, "Manual Entry", "You can enter the time manually:");
                    for (int i = 0; i < n; i++) {
                        bool manualOk;
                        double manualTime = QInputDialog::getDouble(this, "Input", "For Topic " + QString::number(i + 1) + ":", t[i].time * 10, 0.1, 24.0, 1, &manualOk);
                        if (manualOk) t[i].time = manualTime / 10.0;
                    }
                }
                for (int i = n; i < 2 * n; i++) {
                    t[i].name = t[i - n].name + " Revision";
                    t[i].time = t[i - n].time / 2.0;
                    t[i].count = 1;
                }
                fractionalKnapsack(available_time, t.data(), 2 * n);
                QDialog *resDlg = new QDialog(this);
                resDlg->setWindowTitle("Final Schedule");
                resDlg->resize(400, 300);
                QVBoxLayout *resLayout = new QVBoxLayout(resDlg);
                QTableWidget *table = new QTableWidget(2 * n, 2, resDlg);
                table->setHorizontalHeaderLabels({"Activity", "Time (Hours)"});
                for (int i = 0; i < 2 * n; i++) {
                    table->setItem(i, 0, new QTableWidgetItem(QString::fromStdString(t[i].name)));
                    table->setItem(i, 1, new QTableWidgetItem(QString::number(t[i].time * 10, 'f', 2)));
                }
                table->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
                resLayout->addWidget(table);
                QPushButton *closeBtn = new QPushButton("Close", resDlg);
                connect(closeBtn, &QPushButton::clicked, resDlg, &QDialog::accept);
                resLayout->addWidget(closeBtn);
                resDlg->exec();
                }
              //});
         //}
         if (options.contains("2.")) {
            int n;
        cout<<  "----------------------------------";
        cout << "\nEnter Total Number of subjects: ";
        cin >> n;
        //cout<<  "----------------------------------";
        cout<<"\n"<<endl;
        subject s[n];
        cout<<  "----------------------------------------------------------"<<endl;
        cout << "Please Enter the Name and Credit points for each subject: \n"<<endl; ;
        int tcred = 0;
        for (int i = 0; i < n; i++) {
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
        for (int i = 0; i < n; i++) {
            cout << s[i].sname << ":";
            cin >> s[i].examdate;
            s[i].time_left = s[i].examdate;
            s[i].ttime = s[i].time_left * tgive;
            cout<<endl;
        }
       // int ttime = s[0].time_left * tgive;
        cout<<  "----------------------------------------------------";
        cout << "\nWhat is your preparation level rate it from 1-10? \n10 being highest and 1 being the lowest: \n"<<endl;
        for(int i=0;i<n;i++) {
            cout << "For "<< s[i].sname << ": ";
            cin >> s[i].prep;
            s[i].prepp=100*s[i].prep/10;
           // cout<<"Prep Percentage: "<<s[i].prepp<<endl;
            }
        cout<<endl;
        int timp = 0;
        cout<<  "---------------------------------------------------------------";
        cout << "\nHow much time did you took for doing that preparation(in hours)"<<endl;
        for(int i=0;i<n;i++) {
            cout << "For "<< s[i].sname << ": ";
            cin>> s[i].pptime;
        }
        for (int i = 0; i < n; i++) {
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
        for(int i=0;i<n;i++) {
            cout<<"\n\t___________________________________________________________________________________";
            cout<<"\n"<<setw(20)<<s[i].sname<<setw(15)<<s[i].credits<<setw(22)<<round(s[i].rtime)<<setw(22)<<round(s[i].atime);
            cout<<"\n\t___________________________________________________________________________________";
        }
       cout<<"\n\n";
       cout<<"------------------------------------------------------------------";
       cout<<"\nAccording to our algorithm the priority should be as follows"<<endl;
        printJobScheduling(s, n);
          } else if (options.contains("3.")) {
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
        for (int i = 0; i < n; i++) {
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
    for(int i=0;i<n;i++) {
        cout<<s[i].sname<<"\n";
        cout<<s[i].topics<<"\n";}*/
        topic it[ttopic * n];
        int y = 0;
            cout << "\n-----------------------------------------------------------------------------------------------"<<endl;
        for (int i = 0; i < n; i++) {
            cout << "Enter the name of each Topic with its importance in exam and Difficulty level according to you."<<endl;
            cout << "From 1-10_____1 being the easiest for the subject"<<endl;
            cout <<"For "<< s[i].sname << ": "<<endl;
            for (int j = 0; j < s[i].topics; j++) {
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
        if (ask == 0) {
            //sort on the basis of difficulty
            sort(it, it + (n * ttopic), cmpDiff);
            cout << "\n----------------------------------------------------"<<endl;
            cout << "Sorted by difficulty in each topic faced by you:\n";
            for (int i = (n * ttopic) - 1; i >= 0; i--) {
                cout << it[i].name << "\n";
            }
        } else if (ask == 1) {
            //sort on the basis of importance
            sort(it, it + (n * ttopic), cmpImp);
            cout << "\n----------------------------------------------------"<<endl;
            cout << "Sorted by importance of each subject in exam: ";
            for (int i = (n * ttopic) - 1; i >= 0; i--) {
                cout << it[i].name << "\n";
            }
        }
    } else {
    	cout<<"\n-----------------------------------------"<<endl;
    	cout<<"The Option Number you chose is not their"<<endl;
    	cout<<"\n-------------------------------------"<<endl;
    	cout<<"Thank You! :)"<<endl;
          }
      });
   }
}

class StartWindow : public QWidget {
    Q_OBJECT
    QProgressBar *bar = nullptr;
    QTimer *timer = nullptr;
    int progress = 0;
public:
    explicit StartWindow(QWidget *parent = nullptr) : QWidget(parent) {
        setFixedSize(400, 200);
        setWindowTitle("Start");
        auto *layout = new QVBoxLayout(this);
        QLabel *label = new QLabel("<b>Preparing your study environment...</b>");
        label->setAlignment(Qt::AlignCenter);
        bar = new QProgressBar(this);
        bar->setRange(0, 100);
        bar->setValue(0);
        QPushButton *startBtn = new QPushButton("Begin Analysis", this);
        layout->addWidget(label);
        layout->addWidget(bar);
        layout->addWidget(startBtn);
        connect(startBtn, &QPushButton::clicked, this, &StartWindow::startGeneration);
        timer = new QTimer(this);
        connect(timer, &QTimer::timeout, this, &StartWindow::updateProgress);
    }
    private slots:
      void startGeneration() {
        timer->start(30);
    }
    void updateProgress() {
        progress++;
        bar->setValue(progress);
        if (progress >= 100) {
            timer->stop();
            MainMenuWindow *mainWin = new MainMenuWindow();
            mainWin->show();
            this->close();
        }
    }
};

void MainMenuWindow::resizeEvent(QResizeEvent *event) {
  QWidget::resizeEvent(event);
}

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    QDir::setCurrent(QCoreApplication::applicationDirPath());
    StartWindow* window = new StartWindow();
    window->show();
    return app.exec();
 }

#include "test-prep.moc"

