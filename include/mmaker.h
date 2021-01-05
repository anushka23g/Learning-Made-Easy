#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cstdio>
#include "include/func.h"

using namespace std;

class item
{
    public:
        string name, desc;
        int ret;
        int y;
        item()
        {
            name = " ";
            desc = " ";
            y = 0;
            ret = 0;
        }
        item(string s1, int a, string s2)
        {
            name = s1;
            desc = s2;
            ret = a;
        }
        void display();
        void disp_selected();
};
void item::display()
{
   cout.width(y + (name.size()));
   cout<<name<<"  \n";
}

void item::disp_selected()
{
    cout.width(y+10);
    cout<<"\033[31;1;4m--> " << name <<"\033[0m     \n";

}

class menu
{
    item head;
    vector<item> entries;
    int num;
    public:
    menu()
    {
        num=0;
    };
    void add(string,int,string);
    void menu_head(string);
    int display();
    void readfromfile(string);
};


void menu::add(string s, int r = 0, string d = " ")
{
    num++;
	if(r == 0)
		r = num;
    entries.push_back(item(s, r, d));
}

void menu::menu_head(string s)
{
    head.name = s;
    return;
}

int menu::display()
{
    system("clear");
    int selected = 0, opt=66, last_x = getmax_x(), last_y = getmax_y();
    while(true)
    {
        int max_y = getmax_y(), i;
		head.y = (max_y - head.name.size())/2;
        for(item &a : entries)
        {
            a.y = (max_y - a.name.size())/2;
        }
        int max_x = getmax_x();
        if (!(max_x == last_x && max_y == last_y))
        {
            system("clear");
            last_x = max_x;
            last_y = max_y;
        }
        int x = (max_x - num)/2 - 2;
        gotoxy(0, 0);
        //printf("\033[%d;%dH", 0, 0);
        for(i =2; i<x; i++)
            cout<<endl;
        //cout.width(head.y);
        head.display();
        cout.width(head.y+2*head.name.size());
        cout << string(3*head.name.size(), '*');
        //cout << "**********";
		cout<<"\n\n";
        for(i=0;i<(int)entries.size();i++)
        {
            if ( i == selected)
                entries[i].disp_selected();
            else
                entries[i].display();
        }
        cout << "\n\n\n\n\n\n\n";
        cout << "Desription: " << entries[selected].desc;
        int previous = (opt==66)?(selected-1):(selected+1);
        if (previous < 0)
            previous = num-1;
        if(previous == num)
            previous = 0;
        int temp = (entries[previous].desc.length() - entries[selected].desc.length());
        for(int i=0;i<temp;i++)
            cout << " ";
        cout<<'\n';
        opt = getch();
        if (opt == 10)
            return entries[selected].ret;
        switch(opt)
        {
            case 66:
                selected++;
                break;
            case 65:
                selected--;
                break;
        }
        if(selected == num)
            selected = 0;
        if(selected == -1)
            selected = num -1;
    }
}

void menumaker()
{
    string objn, input;
    cout<<"Enter name of object to create: ";
    cin>> objn;
    item a;
    vector<item> m_entry;
    int num=0;
    ofstream fentry;
    fentry.open(objn);
	cout << "Enter menu heading: ";
	cin>>a.name;
	fentry<<a.name<<endl;
    while(true)
    {
        cout<<"Enter menu entry name(NIL for exiting): ";
        cin>> a.name;
        if(a.name=="NIL")
            break;
        fentry<<a.name<<' ';
        num++;
        cout<<"Enter description(NIL to skip): ";
        cin>>a.desc;
        fentry<<a.desc<<' ';
        cout<<"Enter return value(0 for default): ";
        cin>>a.ret;
        if(a.ret == 0)
            a.ret = num;
        fentry<<a.ret<<' '<<endl;
        m_entry.push_back(a);
    }
    fentry.close();
    ofstream outf;
    outf.open("temp");
        {
            outf<<objn;
            outf<<".readfromfile(\"";
            outf<<objn;
            outf<<"\");";
            outf<<"\nwhile(true)\n{\n\tint x=";
            outf<<objn;
            outf<<".display();\n\tswitch(x)\n\t{\n";
            for(int i=0;i<num;i++)
            {
                outf<<"\t\tcase ";
                outf<<m_entry[i].ret;
                outf<<":\t//menu item ";
                outf<<m_entry[i].name;
                outf<<"\n\n\t\t\tbreak;\n";
            }
            outf<<"\t\tdefault:\n\t\tbreak;\n\t}\n}";
        }

    cout<<"Please copy code from file temp and place in the appropriate place\n";
    outf.close();
}


void menu::readfromfile(string s)
{
    item temp;
    ifstream file;
    file.open(s);
	file>>temp.name;
	head.name = temp.name;
    while(file.good())
    {
        file>>temp.name;
        file>>temp.desc;
        file>>temp.ret;
		num++;
        entries.push_back(temp);
    }
    file.close();
}
