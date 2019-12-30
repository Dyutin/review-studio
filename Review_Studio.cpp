#include<conio.h>
#include<fstream.h>
#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>

int i,Trate;
int UserRate;
char TMname[20];
void menu();
class credentials
 {
   char userId[20],adminId[20],adminPass[20],userPass[20],temp1[20],temp2[20];
   int flag;
   public:
    credentials()
    { flag=0;}
    void NewUser();
    void disp()
    {cout<<adminId;}
    void ShowUser();
    void NewAdmin();
    void ShowAdmin();
    void details();
    char* Get_adminId(){return adminId;}
    char* Get_adminPass(){return adminPass;}
    char* Get_userId(){return userId;}
    char* Get_userPass(){return userPass;}
  };

class database
 {
   private:
   int Get_Rating,castno;
   char GetGenre[20],mvname[30],mvdetail[200],cast[10][50],runtime[20],lang[20],MPAA[5],status[20];
   public:
   int AvgRating;
   void Getmv();
   void MvDisp();
   void ViewAll();
   void GetStatus();
   int RatePort()
   { return Get_Rating;}
   char* MvPort()
   {return mvname;}
  }D;


void database::Getmv()
 { clrscr();
   cout<<"\nEnter Name of the Movie: ";
   gets(mvname);
   cout<<"Enter the genre: ";
   gets(GetGenre);
   cout<<"Enter language: ";
   gets(lang);
   cout<<"Enter details of the Movie: ";
   gets(mvdetail);
   cout<<"Enter the number of cast: ";
   cin>>castno;
   cout<<"Enter cast list: " ;
   for(int j=0;j<castno;j++)
     gets(cast[j]);
   cout<<"Enter runtime: ";
   gets(runtime);
   cout<<"Enter Movie Picture Rating(MPAA): ";
   gets(MPAA);
   cout<<"Enter status: ";
   gets(status);
   AvgRating=0;
 }

void database::MvDisp()
 {cout<<"\n\t\t\tMovie Name: "<<mvname<<"\n\t\t\tGenre: "<<GetGenre;
  cout<<"\n\t\t\tLanguage: "<<lang<<"\n\t\t\tMovie details:\n\n"<<mvdetail;
  cout<<"\n\n\t\t\tCast list: ";
  for(int h=0;h<castno;h++)
    { cout<<"\n\t\t\t"<<cast[h];}
  cout<<"\n\t\t\tMovie Picture Rating(MPAA): "<<MPAA;
  cout<<"\n\t\t\tStatus: "<<status;
  cout<<"\n\t\t\tCurrent Rating: "<<AvgRating<<"/10";
 }

void database::ViewAll()
 {cout<<"\n\n\t\t\tMovie Name: "<<mvname<<"\n\t\t\tLanguage: "<<lang;
  cout<<"\n\t\t\tStatus: "<<status;
  cout<<"\n\t\t\tCurrent Rating: "<<AvgRating<<"/10";
 }

void database::GetStatus()
 { cout<<"\n\n\t\t\tEnter new Status: ";
   gets(status);
 }


class AvgRate
 { int Urate;
   char MovName[20];
   public:
    AvgRate()
    {strcpy(MovName,TMname);
     Urate=UserRate;
    }
    int RetUrate()
     {return Urate;}
    char* RetMov()
     {return MovName;}
 };

void credentials::NewAdmin()
 {
   cout<<"Enter Admin ID :";
   gets(adminId);
   while(flag==0)
    {
     cout<<"\nEnter Password :";
     gets(temp1);
     cout<<"\nConfirm Password :";
     gets(temp2);
     if(strcmp(temp1,temp2)==0)
      {
	 flag=1;
	 strcpy(adminPass,temp1);
      }
      else
	 cout<<"\n\nPassword does not match\n";
    }

 }

 void credentials::ShowAdmin()
  {
   cout<<"\nAdmin Id :"<<adminId<<"\nPassword :"<<adminPass;
  }

 void credentials::NewUser()
 {
     cout<<"Enter User ID :";
     gets(userId);
     while(flag==0)
     {
      cout<<"\nEnter Password :";
      gets(temp1);
      cout<<"\nConfirm Password :";
      gets(temp2);
      if(strcmp(temp1,temp2)==0)
	{
	 flag=1;
	 strcpy(userPass,temp1);
	}
      else
	 cout<<"\n\nPassword does not match\n";
      }

 }

 void credentials::ShowUser()
  {
    cout<<"\nUser Id :"<<userId<<"\nPassword :"<<userPass;
   }

 void Addadmin()
 {
  credentials admin;
  ofstream fout("ADMIN.DAT",ios::app|ios::binary);
  admin.NewAdmin();
  fout.write((char*)&admin,sizeof(admin));
  fout.close();
  cout<<"\n\nCongratulations! Your account has been created\n";
  admin.ShowAdmin();
 }

 void Adduser()
 {
  credentials user;
  ofstream fout("USER.DAT",ios::app|ios::binary);
  user.NewUser();
  fout.write((char*)&user,sizeof(user));
  fout.close();
  cout<<"\n\nCongratulations! Your account has been created\n";
  user.ShowUser();
 }

char find(char[],char[]);
void AdminPage(char[]);
void UserPage(void);

void credentials::details()
 {clrscr();
  char MARKER='i';
  cout<<"\n\t\t\tEnter LogIn Id :";
  gets(temp1);
  cout<<"\t\t\tEnter Password :";
  gets(temp2);
  MARKER=find(temp1,temp2);
  if(MARKER=='0')
      cout<<"\n\t\t\tLogin ID does not exist";
  if(MARKER=='y')
     AdminPage(temp1);
  else if(MARKER=='Y')
     UserPage();
 }

void AdminPage(char adminid[])
{
 cout<<"\nAdmin Logged in";
 cout<<"\n\n\nWelcome Admin "<<adminid;
 char Modname[20];
 database TEMP;
 int cH,cp,pos;
 pos=sizeof(D);
 pos=pos*(-1);
 int mflag=0,dflag=0,vflag=0;
 char ch;
 while(1)
 {clrscr();
 cout<<"\n\t\t\t***ADMIN MENU***";
 cout<<"\n\t\t\t1.Add New Movie\n\t\t\t2.Modify Movie Status\n\t\t\t3.Delete a Movie\n\t\t\t4.Display Existing Movies\n\t\t\t5.Back to Login Page";
 cout<<"\n\t\t\tEnter your choice: ";
 cin>>cH;
 switch(cH)
  {
   case 1:
     D.Getmv();
     ofstream Mout("MVDET.DAT",ios::app|ios::binary);
     Mout.write((char*)&D,sizeof(D));
     Mout.close();
     getch();
     break;
   case 2:
     cout<<"\n\t\t\tEnter movie name to modify status: ";
      gets(Modname);
      fstream X("MVDET.DAT",ios::in|ios::out|ios::binary);
      while(X.read((char*)&D,sizeof(D)))
      {
       if(strcmpi(D.MvPort(),Modname)==0)
       {mflag=1;
	D.ViewAll();
	D.GetStatus();
	X.seekp(pos,ios::cur);
	X.write((char*)&D,sizeof(D));
	cout<<"\n\n\t\t\tStatus Modified...";
	break;
       }
      }
      X.close();
      if(mflag==0)
	cout<<"\n\n\t\t\tMovie not Found\n";
      getch();
      break;
   case 3:
      ofstream temp("TEMPMV.DAT",ios::out|ios::binary);
      ifstream Delo("MVDET.DAT",ios::in|ios::binary);
      cout<<"\n\t\t\tEnter the movie name to delete: ";
      gets(Modname);
      while(Delo.read((char*)&D,sizeof(D)))
      {
       if(strcmpi(D.MvPort(),Modname)!=0)
       {
	temp.write((char*)&D,sizeof(D));
       }
       else
       {  clrscr();
	  dflag=1;
	  D.MvDisp();
	  cout<<"\n\n\t\t\tThis movie will be deleted!!.. ";
	  cout<<"\n\n\t\t\tConfirm Deletion (Y/N): ";
	  cin>>ch;
	  if(ch=='y' || ch=='Y')
	    cout<<"\n\t\t\t\t\t\t Movie Deleted....";
	  else
	    temp.write((char*)&D,sizeof(D));
       }
      }
      if(dflag==0)
      cout<<"\n\n\t\t\tMovie not Found\n";
      temp.close();
      Delo.close();
      remove("MVDET.DAT");
      rename("TEMPMV.DAT","MVDET.DAT");
      getch();
      break;
   case 4:
      ifstream fn("MVDET.DAT",ios::in|ios::binary);
      while(fn.read((char*)&D,sizeof(D)))
      { vflag=1;
	D.ViewAll();
      }
      if(vflag==0)
	cout<<"\n\n\t\t\tFile is Empty";
      fn.close();
      getch();
      break;
   case 5:
      menu();
  }
 }
}

void UserPage()
{clrscr();
 char Smv[20],Rchoice;
 database Q;
 int pos=sizeof(Q);
 pos=pos* (-1);
 int flag=0;
 cout<<"\n\n\t\t\t\t\t\t\tUser Logged in....";
 cout<<"\n\n\t\t\tEnter the movie to Search: ";
 gets(Smv);
 fstream MvIn("MVDET.DAT",ios::in|ios::out|ios::binary);
 while(MvIn.read((char*)&Q,sizeof(Q)))
 {if(strcmpi(Smv,Q.MvPort())==0)
   { Q.MvDisp();
     strcpy(TMname,Q.MvPort());
     flag=1;
     break;
   }
 }
 if(flag==0)
  {cout<<"\n\n\t\t\tMovie not Found";
   getch();
   return;
  }
 getch();
 cout<<"\n\n\t\t\t\t\tDo you want to rate the movie(Y/N)";
 cin>>Rchoice;
 if(Rchoice=='Y'|| Rchoice=='y')
  { clrscr();
    cout<<"\n\n\n\t\t\t\t\t\tMovie: "<<TMname;
    cout<<"\n\t\t\t\t\t\tRating: "<<Q.AvgRating<<"/10";
    cout<<"\n\n\t\t\tRate this Movie out of 10 :";
    cin>>UserRate;
    cout<<"\n\t\t\tYour rating is : "<<UserRate<<"/10";
    AvgRate A;
    getch();
    int n=0;
    fstream f("RATE.DAT",ios::app|ios::binary);
    f.write((char*)&A,sizeof(A));
    f.close();
    UserRate=0;
    ifstream O("RATE.DAT",ios::in|ios::binary);
    while(O.read((char*)&A,sizeof(A)))
     {
      if(strcmp(A.RetMov(),TMname)==0)
      {
	UserRate+=A.RetUrate();
	n++;
       }
     }
     O.close();
     UserRate/=n;
     Q.AvgRating=UserRate;
     MvIn.seekp(pos,ios::cur);
     MvIn.write((char*)&Q,sizeof(Q));
     MvIn.seekp(pos,ios::cur);
     MvIn.read((char*)&Q,sizeof(Q));
     Q.MvDisp();
   }
 MvIn.close();
}

char find(char tempx[20],char tempy[20])
 { credentials d;
   char marker='0';
   ifstream fin("ADMIN.DAT",ios::in|ios::binary);
   while(fin.read((char*)&d,sizeof(d)))
    {
     if(strcmp(d.Get_adminId(),tempx)==0)
      {
       if(strcmp(d.Get_adminPass(),tempy)==0)
	 marker='y';
       else
	 { marker='n';
	   cout<<"\nIncorrect Password";
	   getch();
	 }fin.close();
       return marker;
      }
    }
   if(marker=='0')
   {
    ifstream Fin("USER.DAT",ios::in|ios::binary);
    while(Fin.read((char*)&d,sizeof(d)))
    { if(strcmp(d.Get_userId(),tempx)==0)
       {
	if(strcmp(d.Get_userPass(),tempy)==0)
	 {marker='Y';}
	else
	 {marker='N';
	  cout<<"\nIncorrect Password";
	  getch();
	  }Fin.close();
	return marker;
       }
    }
   }
 return marker;
}

void menu()
{int i;
 credentials Main;
 char ch1,ch2,ch3;
 while(1)
 { clrscr();
   cout<<"\n\t\t\t1.Sign up\n\t\t\t2.Log in\n\t\t\t3.Exit\n";
   cout<<"\n\n\t\t\tEnter your choice :";
   cin>>ch1;
   switch(ch1)
   {case '1':
      cout<<"\n\n\t\t\ta. Create Admin Account\n\t\t\tb. Create User Account\n\t\t\tc. Exit";
      cout<<"\n\n\t\t\tEnter your choice :";
      cin>>ch2;
      if(ch2=='a')
	Addadmin();
      else if(ch2=='b')
	Adduser();
      else
	cout<<"\nInvalid choice";
      getch();
      break;
    case '2':
      Main.details();
      getch();
      break;
    case '3':
      exit(0);
      break;
    default:
      cout<<"\nInvalid Choice";
      getch();
  }
 }
// getch();
}


void main()
{ menu();
}
