#include <iostream>
  #include <fstream>
  #include <string.h>
  using namespace std;
  class Student{
    typedef struct stud{
        char name[10];
        char add[10];
        char div;
        int roll; 
    }stud;
    stud rec;
    public:
        void create();
        void display();
        int search();
        void delet();
  };

  void Student::create()
  {
    int n;
    ofstream fout;
    fout.open("stud.dat", ios::out|ios::binary);
    cout<<"Enter the no. of records to add  : ";
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cout<<"Enter roll no.: ";
        cin>>rec.roll;
        cin.ignore();
        cout<<"Enter name : ";
        cin.getline(rec.name,sizeof(rec.name));
        cout<<"Enter division :";
        cin>>rec.div;
        cin.ignore();
        cout<<"Enter address : ";
        cin.getline(rec.add,sizeof(rec.add));
        fout.write((char *)&rec,sizeof(stud));
        cin.ignore();
    }
    fout.close();
   }
   void Student::display()
  {
	ifstream fin;
	fin.open("stud.dat",ios::in|ios::binary);
	fin.seekg(0,ios::beg);
	cout<<"\nThe Content of File are:\n";
	//cout<<"\n\tRoll\tName\tDiv\tAddress";
	while(fin.read((char *)&rec,sizeof(stud)))
	  {
		if(rec.roll!=-1)
       		  cout<<"Roll no. : "<<rec.roll<<endl;
              cout<<"Name : "<<rec.name<<endl;
              cout<<"Division : "<<rec.div<<endl;
              cout<<"Address : "<<rec.add<<endl;
	  }
	fin.close();
  }
   int Student::search()
   {
        int r,i=0;
        ifstream fin;
        fin.open("stud.dat",ios::in|ios::binary);
        cout<<"Enter roll no. : ";
        cin>>r;
        while(fin.read((char*)&rec,sizeof(stud)))
        {
            if(rec.roll==r)
            {
                cout<<"RECORD FOUND !\n";
                //cout<<"\nRoll No.\tName\tAddress\tDivision\n";
                //cout<<"\n"<<rec.roll<<"\t"<<rec.name<<"\t"<<rec.add<<"\t"<<rec.div<<"\n";
                cout<<"Roll no. : "<<rec.roll<<endl;
                cout<<"Name : "<<rec.name<<endl;
                cout<<"Division : "<<rec.div<<endl;
                cout<<"Address : "<<rec.add<<endl;
                return i;
            }
        i++;
        }
        fin.close();
        return 0;
   }
   void Student::delet()
   {
        int pos;
        pos=search();
        fstream f;
        f.open("stud.dat",ios::in|ios::out|ios::binary);
        f.seekg(0,ios::beg);
        if(pos==0)
        {
            cout<<"Record not found !!!\n";
            return;
        }
        int offset=pos*(sizeof(stud));
        f.seekp(offset);
        rec.roll=-1;
        strcpy(rec.name,"NULL");
        rec.div='N';
        strcpy(rec.add,"NULL");
        f.write((char*)&rec,sizeof(stud));
        f.seekg(0);
        f.close();
        cout<<"Record Deleted !!\n";
   }
   int main()
   {
        Student s;
        int key,ch;
        do{
            cout<<"****************\n";
            cout<<"1. Insert data \n";
            cout<<"2. Display data \n";
            cout<<"3. Search data \n";
            cout<<"4. Delete data \n";
            cout<<"5. Exit \n";
            cout<<"Enter your choice : ";
            cin>>ch;
            switch(ch)
            {
                case 1:
                    s.create();
                    break;
                case 2:
                    s.display();
                    break;
                case 3:
                    key= s.search();
                    if(key==0)
                    {
                        cout<<"Record not found !\n";
                    }
                    break;
                case 4:
                    s.delet();
                    break;
                case 5: 
                    cout<<"Exiting Program !\n";
                    break;
            }
        }while(ch!=5);
    return 0;
   }
