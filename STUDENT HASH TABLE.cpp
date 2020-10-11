#include <iostream>
#include<cstdlib>
#include<string>
#include<sstream>
#include<cstring>
#include<stdio.h>
#include<fstream>
using namespace std;
struct date
{
    int dd;
     int mm;
      int yy;
 }s;
int valid(int dd,int mm,int yy)
{  int i=1;
  if(yy>1900&&yy<2019)
  {
  	if((dd>=1&&dd<=31) && (mm==1||mm==3||mm==5||mm==8||mm==7||mm==9||mm==11))
  	{return i;
	}
	  else if((dd>=1&&dd<=30)&&(mm==4||mm==6||mm==12))
	  {return i;
	  }
	  else if((mm==2)&&(yy%4==0)&&(dd>=1&&dd<=29))
	  {return i;
	  }
	  else if((mm==2)&&(dd>=1&&dd<=28))
	  {return i;
	  }
	  else
	  { i=0;
	   return i;
	  }

  }
  i=0;
  return i;
  }

class Hash
{
    private:
    static const int tablesize=10;
    struct student
    {
        int rollno;
        string name;
        string dob;
        string clss;
        int marks;
        student* next;
    };
    student* HashTable[tablesize];
    public:
    Hash()
    {
       for(int i=0;i<tablesize;i++)
       {
           HashTable[i]=new student;
           HashTable[i]->rollno=0;
           HashTable[i]->name="empty";
           HashTable[i]->dob="empty";
           HashTable[i]->clss="empty";
           HashTable[i]->marks=0;
           HashTable[i]->next=NULL;
       } 
    }
    int Hashing(string key);
    void PrintTable();
    void AddStudentEntry();
    int NumberofItemsinIndex(int index);
    void PrintItemsInIndex(int index);
    void SearchRecord(string name);
    void RemoveEntry(string name);
    void SortFields();
    friend bool IntTryParse(string inputstring,int &outputint);
};
bool IntTryParse(string inputstring,int &outputint)
{
	outputint=-1;
	int i,len;
	char c;
	for(i=0;inputstring[i]!='\0';i++){
	}
	len=i;
	for(i=0;i<len;i++){
		c=inputstring[i];
	if(!isdigit(c))
	  return false;}
	  sscanf(inputstring.c_str(),"%d",&outputint);
	  return true;
}
void Hash::AddStudentEntry()
{
    int i,temprollno,num=0,correct=1,tempmark=0;
    string name,dob,clss,rollno="",marks;
    char insert='Y';
    while(insert=='Y' || insert=='y')
    {
        while(1)
        {
            cout<<"\nEnter the Roll No. of the Student : ";
            cin>>rollno;
            if(IntTryParse(rollno,num))
            {
                break;
            }
	        cout<<"Please Enter the Valid Input\n";
	}
	stringstream convert(rollno);
	convert >>temprollno;
	char nam;
	name="";
	getline(cin,name);
	correct=1;
	while(correct)
    {
        cout<<"\nEnter the Name of the Student1 : ";
        getline(cin,name);
        for(i=0;name[i]!='\0';i++)
	    {
            nam=name[i];
	        if(isdigit(nam) || nam>=33 && nam<=45 || nam==47 || nam>=58 && nam<=64 || nam>=92 && nam<=96 || nam>=123 && nam<=126)
	        {
                correct=1;
	    	    break;
		    }
		    else
            {
			    correct=0;
		    }
	    }
        if(correct==1)
        {
     	    cout<<"\nPlease Enter the Valid Name\n";
	    } 
    }
    int period,flag=1;
    char tempdob[10];
    while(flag)
    {
        cout<<"\nEnter the D.O.B of the Student (dd/mm/yyyy): ";
        scanf("%d/%d/%d",&s.dd,&s.mm,&s.yy);
        period=valid(s.dd,s.mm,s.yy);
        if(period==0)
        {
    	    printf("                   Please Enter the Valid Date!!!");
    	    flag=1;
	    }    
	    else
        {
		    flag=0;
		    dob="";
		    if(s.mm<=9 && s.dd<9)
            {
		        sprintf(tempdob,"%d%d/%d%d/%d",0,s.dd,0,s.mm,s.yy);
	        }
	        else if(s.mm<=9)
	        {
		        sprintf(tempdob,"%d/%d%d/%d",s.dd,0,s.mm,s.yy);
	        }
	        else if(s.dd<9)
	        {
		        sprintf(tempdob,"%d%d/%d/%d",0,s.dd,s.mm,s.yy);
	        }
	        else
            {
		        sprintf(tempdob,"%d/%d/%d",s.dd,s.mm,s.yy);
	        }
		    for(i=0;i<10;i++)
		    {
			    dob=dob+tempdob[i];
		}
	}
	} 
    correct=1;
    while(correct){
    cout<<"\nEnter the Class of the Student (ss/dcs/ds): ";
    cin>>clss;
    if(clss=="ss" || clss== "Ss" || clss=="sS" || clss=="SS"){
    	correct=0;
    }
    else if(clss=="ds" || clss== "Ds" || clss=="DS" || clss=="dS")
    {
    	correct=0;
	}
	else if(clss=="dcs" || clss== "Dcs" || clss=="Dcs" || clss=="dCs" || clss=="dCS" || clss=="DCS" || clss=="DCs" || clss=="dCS" || clss=="DcS")
    {
    	correct=0;
	}
	else{
		cout<<"\nPlease Enter within the given Choice\n";
	}
}
    correct=1;
    int found=0;
    while(correct){
    cout<<"\nEnter the Marks of the Student : ";
    cin>>marks;
    i=0;
    while(1){
    if(IntTryParse(marks,tempmark)){
    	found=1;
      break;}
      else{
       found=0;
	  cout<<"\nPlease Enter the Valid Input\n";
	  break;}
       }
       if(found=1){
       stringstream convert1(marks);
       convert1>>tempmark;
       if(tempmark<0 || tempmark>100)
      {
      	cout<<"\nPlease Enter the Mark Between 0 to 100\n";
      	correct=1;
	  }
	  else{
	  	correct=0;
	  }}}
    int index=Hashing(dob);
   
    if(HashTable[index]->name=="empty")
    {
       HashTable[index]->rollno=temprollno;
       HashTable[index]->name=name;
       HashTable[index]->dob=dob;
       HashTable[index]->clss=clss;
       HashTable[index]->marks=tempmark;
    } 
    else
    {
       student* Ptr=HashTable[index];
       student* n = new student;
       n->rollno=temprollno;
       n->name=name;
       n->dob=dob;
       n->clss=clss;
       n->marks=tempmark;
       
       n->next=NULL;
       while(Ptr->next !=NULL)
       {
           Ptr=Ptr->next;

       }
       Ptr->next=n;
    }
	cout<<"Do You Want To Insert Another Record (Y/N):";
	cin>>insert;
	}
}

template <typename T>
void merge(T arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 =  r - m;
    T L[n1], R[n2];
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1+ j];
    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2)
    {
        if (L[i].rollno <= R[j].rollno)
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}

template <typename T>
void merge1(T arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 =  r - m;
    T L[n1], R[n2];
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1+ j];
    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2)
    {
        if (L[i].name <= R[j].name)
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}

template <typename T>
void merge2(T arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 =  r - m;
    T L[n1], R[n2];
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1+ j];
    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2)
    {
        if (L[i].marks <= R[j].marks)
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}

template<typename T>
void mergeSort(T arr[], int l, int r,int x)
{
    if(x==1)
    {
        if (l < r)
        {
            int m = l+(r-l)/2;
            mergeSort(arr, l, m,1);
            mergeSort(arr, m+1, r,1);
            merge(arr, l, m, r);
        }
    }
    else if(x==2)
    {
         if (l < r)
         {
   
            int m = l+(r-l)/2;
            mergeSort(arr, l, m,2);
            mergeSort(arr, m+1, r,2);
            merge1(arr, l, m, r);
         }
    }
    else if(x==3)
    {
         if (l < r)
        {
   
            int m = l+(r-l)/2;
            mergeSort(arr, l, m,3);
            mergeSort(arr, m+1, r,3);
            merge2(arr, l, m, r);
        }
    }
}

void Hash::PrintItemsInIndex(int index)
{
    student *Ptr = HashTable[index];
    if(Ptr->name=="empty")
    {
        cout<<"index = "<<index<<" is empty";

    }
    else
    {
        cout<<"index "<<index<<" contains the following item\n";
        while(Ptr!=NULL)
        {
            cout<<"-----------------------\n";
            cout<<"\nRoll No. :"<<Ptr->rollno<<endl;
            cout<<"\nName     :"<<Ptr->name<<endl;
            cout<<"\nD.O.B    :"<<Ptr->dob<<endl;
            cout<<"\nClass    :"<<Ptr->clss<<endl;
            cout<<"\nMarks    :"<<Ptr->marks<<endl;
            cout<<"-----------------------\n";
            Ptr=Ptr->next;
        }
    }
}

void Hash::SearchRecord(string name)
{
    int index=Hashing(name);
    bool foundName=false;
    int rollno;
    string dob;
    string clss;
    int marks;

    student* Ptr=HashTable[index];
    while(Ptr !=NULL)
    {
        if(Ptr->dob==name)
        {
            foundName=true;
            name=Ptr->name;
            rollno=Ptr->rollno;
            dob=Ptr->dob;
            clss=Ptr->clss;
            marks=Ptr->marks;
        }
        Ptr=Ptr->next;
    }
    if(foundName == true)
    {
        cout<<"\nName     : "<<name;
        cout<<"\nRoll No. : "<<rollno;
        cout<<"\nD.O.B    : "<<dob;
        cout<<"\nClass    : "<<clss;
        cout<<"\nMarks    : "<<marks;
        cout<<"\n\n";
    }
    else
    {
        cout<<name<<"'s info was not found in the hash table";
    }
    
}

void Hash::SortFields()
{
    fstream fp1;
    student s1[50];
    int cnt=0;
    int ch;
    for(int i=0;i<tablesize;i++)
    {
        if(HashTable[i]->rollno!=0&&HashTable[i]->name!="empty"&&HashTable[i]->dob!="empty"&&HashTable[i]->clss!="empty"&&HashTable[i]->marks!=0)
        {
    
            student *Ptr = HashTable[i];
            while(Ptr!=NULL)
            {
                        
                s1[cnt].rollno=Ptr->rollno;
                s1[cnt].name=Ptr->name;
                s1[cnt].dob=Ptr->dob;
                s1[cnt].clss=Ptr->clss;
                s1[cnt].marks=Ptr->marks;
                
                fp1.open("student.dat",ios::app);
                fp1.write((char*)&s1[cnt],sizeof(student));
                cnt++;
                fp1.close();
        
                Ptr=Ptr->next;
            }
            }
    }
    cout<<"\n1.Sort by Roll No.";
    cout<<"\n2.Sort by Name";
    cout<<"\n3.Sort by Marks";
    cout<<"\n\nEnter your choice : ";
    cin>>ch;
    switch(ch)
    {
        case 1:
        {
            mergeSort(s1,0,cnt-1,1);
            cout<<"\nRoll No.\tName\tD.O.B\tClass\tMarks"<<endl;
            for(int i=0;i<cnt;i++)
            {
                cout<<s1[i].rollno<<"\t";
                cout<<s1[i].name<<"\t";
                cout<<s1[i].dob<<"\t";
                cout<<s1[i].clss<<"\t";
                cout<<s1[i].marks<<"\t";
                cout<<"\n";
            }
        }
        break;
        
        case 2:
        {
            mergeSort(s1,0,cnt-1,2);
            cout<<"\nRoll No.\tName\tD.O.B\tClass\tMarks"<<endl;
            for(int i=0;i<cnt;i++)
            {
                cout<<s1[i].rollno<<"\t";
                cout<<s1[i].name<<"\t";
                cout<<s1[i].dob<<"\t";
                cout<<s1[i].clss<<"\t";
                cout<<s1[i].marks<<"\t";
                cout<<"\n";
            }
        }
        break;
        
        case 3:
        {
            mergeSort(s1,0,cnt-1,3);
            cout<<"\nRoll No.\tName\tD.O.B\tClass\tMarks"<<endl;
            for(int i=0;i<cnt;i++)
            {
                cout<<s1[i].rollno<<"\t";
                cout<<s1[i].name<<"\t";
                cout<<s1[i].dob<<"\t";
                cout<<s1[i].clss<<"\t";
                cout<<s1[i].marks<<"\t";
                cout<<"\n";
            }
        }
        break;
    }
}

void Hash::RemoveEntry(string dob)
{
    int index=Hashing(dob);
    student* delPtr;
    student* P1;
    student* P2;

    if(HashTable[index]->dob=="empty" )
    {
        cout<<dob<<"was not found in the hashtable";
    }
    else if(HashTable[index]->dob==dob && HashTable[index]->next==NULL)
    {
        HashTable[index]->name="empty";
        HashTable[index]->rollno=0;
        HashTable[index]->clss="empty";
        HashTable[index]->marks=0;
        HashTable[index]->dob="empty";
        cout<<dob<<" was removed from Hash Table\n";
    }
    else if (HashTable[index]->dob==dob)
    {
        delPtr=HashTable[index];
        HashTable[index]=HashTable[index]->next;
        delete delPtr;
        cout<<dob<<" was removed from Hash Table\n";
    }
    else
    {
        P1=HashTable[index]->next;
        P2=HashTable[index];
        while(P1!=NULL &&P1->dob!=dob)
        {
            P2=P1;
            P1=P1->next;
        }
        if(P1==NULL)
        {
            cout<<dob<<" was not found in the Hash Table\n";
        }
        else
        {
            delPtr=P1;
            P1=P1->next;
            P2->next=P1;
            delete delPtr;
            cout<<dob<<" was removed from Hash Table\n";
        }
        
    }
}

void Hash::PrintTable()
{
    int number;
    cout<<"\nHash Table";
    cout<<"\nIndex\tRoll No.\t\tName\t\t\tD.O.B\t\tClass\t\tMarks\t\t# of items"<<endl;
    for(int i=0;i<tablesize;i++)
    {
        number=NumberofItemsinIndex(i);
        if(HashTable[i]->rollno!=0&&HashTable[i]->name!="empty"&&HashTable[i]->dob!="empty"&&HashTable[i]->clss!="empty"&&HashTable[i]->marks!=0)
            cout<<i<<"\t"<<HashTable[i]->rollno<<"\t\t\t"<<HashTable[i]->name<<"\t\t"<<HashTable[i]->dob<<"\t\t"<<HashTable[i]->clss<<"\t\t"<<HashTable[i]->marks<<"\t\t"<<number<<endl;
    }
}

int Hash::NumberofItemsinIndex(int index)
{
    int count=0;
    if(HashTable[index]->name=="empty")
    {
        return count;
    }
    else
    {
        count++;
        student* Ptr=HashTable[index];
        while(Ptr->next!=NULL)
        {
            count++;
            Ptr=Ptr->next;
        }
    }
    return count;
}

int Hash::Hashing(string key)
{
   
    int index;
    int x=(int)key[3];
    int y=(int)key[4];
    int num=(x*10)+y;
    index=num*num;
    index=index%tablesize;
    return index;
}

int main()
{
    Hash hashobj;
    string dob,ch="";
    int ind,num=0,done=0,ch1;
    while(1)
    {system("color 76");
        cout<<"\nOperations Available";
        cout<<"\n1.New entry";
        cout<<"\n2.Print table";
        cout<<"\n3.Print Details in Specific Index";
        cout<<"\n4.Search Record";
        cout<<"\n5.Delete Record";
        cout<<"\n6.Sort Fields";
        cout<<"\n7.Exit";
        //cout<<"\n\nEnter your choice : ";
        //cin>>ch;
        
        while(!done)
	{
    cout<<"\n\nEnter your choice(only Numbers) : ";
    cin>>ch;
    if(IntTryParse(ch,num))
      break;
	  cout<<"Please Enter the Valid Input\n";
    }
    stringstream strin(ch);
    strin >> ch1;
        switch(ch1)
        {
            case 1:hashobj.AddStudentEntry();
            break;
            case 2:hashobj.PrintTable();
            break;
            case 3:
            {
                cout<<"\nEnter the Index : ";
                cin>>ind;
                hashobj.PrintItemsInIndex(ind);
            }
            break;
            case 4:
            {
                int flag=1,period;
                char tempdob[90];
                while(flag){
                cout<<"\nEnter the D.O.B of the Student (dd/mm/yyyy): ";
                scanf("%d/%d/%d",&s.dd,&s.mm,&s.yy);
                period=valid(s.dd,s.mm,s.yy);
                if(period==0)
                {
    	            printf("                   Please Enter The Valid Date!!!");
    	            flag=1;
	            }    
	            else
                {
		            flag=0;
		            dob="";
		            if(s.mm<=9 && s.dd<9){
		            sprintf(tempdob,"%d%d/%d%d/%d",0,s.dd,0,s.mm,s.yy);
	            }
	            else if(s.mm<=9)
	            {
		            sprintf(tempdob,"%d/%d%d/%d",s.dd,0,s.mm,s.yy);
	            }
	            else if(s.dd<9)
	            {
		            sprintf(tempdob,"%d%d/%d/%d",0,s.dd,s.mm,s.yy);
	            }
	            else
                {
		            sprintf(tempdob,"%d/%d/%d",s.dd,s.mm,s.yy);
	            }
		        for(int i=0;i<10;i++)
		        {
			        dob=dob+tempdob[i];
		        }
		        hashobj.SearchRecord(dob);
	        }
	    } 
        }
        break;
        case 5:
            {
                int flag=1,period;
                char tempdob[90];
                while(flag){
                cout<<"\nEnter the D.O.B of the Student (dd/mm/yyyy): ";
                scanf("%d/%d/%d",&s.dd,&s.mm,&s.yy);
                period=valid(s.dd,s.mm,s.yy);
                if(period==0)
                {
    	            printf("                   Please Enter the Valid Date!!!");
    	            flag=1;
	            }    
	            else
                {
		            flag=0;
		            dob="";
		            if(s.mm<=9 && s.dd<9)
                    {
		                sprintf(tempdob,"%d%d/%d%d/%d",0,s.dd,0,s.mm,s.yy);
	                }
	                else if(s.mm<=9)
	                {
		                sprintf(tempdob,"%d/%d%d/%d",s.dd,0,s.mm,s.yy);
	                }
	                else if(s.dd<9)
	                {
		                sprintf(tempdob,"%d%d/%d/%d",0,s.dd,s.mm,s.yy);
	                }
	                else
                    {
		                sprintf(tempdob,"%d/%d/%d",s.dd,s.mm,s.yy);
	                }
		            for(int i=0;i<10;i++)
		            {
			            dob=dob+tempdob[i];
		            }      
		            hashobj.RemoveEntry(dob);
	            }
	        } 
            }
            break;
            case 6:
            {
                hashobj.SortFields();
            }
            break;
            case 7:
        	{
        		exit(0);
			}
			default:
				cout<<"\nPlease Enter the No between 1 to 6\n\n";
        }
    }
    return 0;
}
    
    
