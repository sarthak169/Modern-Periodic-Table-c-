 #include<iostream.h>
 #include<stdlib.h>
 #include<stdio.h>
 #include<conio.h>
 #include<fstream.h>
 #include<process.h>
 #include<string.h>
 #include<graphics.h>
 struct question
 {
  int qid;
  char question[100];  //these are sizes for one particular question
  char answer[25];
  char option1[20];
  char option2[20];
  char option3[20];                 //struct is a datatype which allows both
  char option4[20];                 // integer and character
 } array[10];
 void  loadQues(question questionArray[]);   //formal parameter
 void displayMainMenu();
 void anonuser();
 void admin();
 void pass();
 void insertElement();
 void deleteElement();
 void searchElement();
 void editElement();
 void insertfirst();
 void insertspecpos();
 void insertend();
 void insertafter();
 void delno();
 void delname();
 void disphydro();
 void disperiodic();
 void dispfile();
 void test();
 void dispAlkane();
 void dispAlkene();
 void dispAlkyne();
 class table
{
   private:

   int atmno, atmmas;
   int grp, period, neutrons;
   char ename[20], etype[20], elccnfg[30];
   char chrge[15], esymb[5];

   public:

   //Member function to input data
   void getdata()
   {
       cout<<"\n\n Enter Element's Symbol:  ";
       gets(esymb);
       cout<<"\n\n Enter Element's Name:  ";
       gets(ename);
       cout<<"\n\n Enter Element's Type: ";
       gets(etype);
       cout<<"\n\n Enter Element's Group: ";
       cin>>grp;
       cout<<"\n\n Enter Element's Period: ";
       cin>>period;
       cout<<"\n\n Enter Element's atomic Number: ";
       cin>>atmno;
       cout<<"\n\n Enter Element's Atomic Mass: ";
       cin>>atmmas;
       cout<<"\n\n Enter Element;s Charge: ";
       gets(chrge);
    }
    //function to display element info
    void display()
    {
       cout<<"\n\n Element Symbol: ";
       puts(esymb);
       cout<<"\n\n Element's Name: ";
       puts(ename);
       cout<<"\n\n Element's Type: ";
       puts(etype);
       cout<<"\n\n Element's Group: ";
       cout<<grp;
       cout<<"\n\n Element's Period: ";
       cout<<period;
       cout<<"\n\n Element's atomic Number: ";
       cout<<atmno;
       cout<<"\n\n Element's Atomic Mass: ";
       cout<<atmmas;
       cout<<"\n\n Elemen's Charge: ";
       puts(chrge);
     }

     //function to display element's info in tabular form
     void displayd(int x)
     {
       gotoxy(1,x);
       puts(esymb);
       gotoxy(4,x);
       puts(ename);
       gotoxy(18,x);
       cout<<grp;
       gotoxy(25,x);
       cout<<atmno;
       gotoxy(36,x);
       cout<<atmmas;
       gotoxy(64,x);
       puts(chrge);
     }
     //function to return element symbol
     char* retesymb()
     {
	return esymb;
     }
     //function to return element name
     char* retename()
     {
       return ename;
     }
     //function to return element atomic num
     int retatmno()
     {
       return atmno;
     }
     // function to return element atomic mass
     int retatmmas()
     {
       return atmmas;
     }
};
table t1,t2,temp;

  void main()
  {
  clrscr();
  cout<<"\n\n\n\n\n\n\t\t\t  Modern Periodic Table\n";
  cout<<"\n\t\t\t\t&\n";
  cout<<"\n\t\t\tStructure of Hydrocarbons\n";
  gotoxy(2,20);
  cout<<"\n\nMade By:-\n";
  cout<<"\n\nSarthak(1610991774) and Samarth Dogra(1610991760)\n\n";
  getch();
  displayMainMenu();

  }
  void displayMainMenu()
  {
   clrscr();
   int choice1;
   cout<<"\n\n\n\tLogin as:";
   cout<<"\n\t\t1.Admin\n";
   cout<<"\n\t\t2.Anonymous user\n";
   cout<<"\n\t\t3.Exit\n";
   cout<<"\nEnter your choice\n";
   cin>>choice1;
   switch(choice1)
    {
     case 1:pass();break;
     case 2:anonuser();break;
     case 3:exit(0);getch();break;
     default:cout<<"Enter a valid choice";break;
    }
  }
  void pass()
  {
   clrscr();
   for(int i=2;i>=0;i--)
   {
      char *password;
      password = getpass("Enter the password:");
       if(i==0)
      {
       cout<<"\n Your access is denied...Press any key to exit the application." ;
       getch();
       exit(0);
      }
      if(strcmpi(password,"Table_21")==0)
       {
	 admin();
       }
      else
      {
	cout<<"\nTry Again!!!! You have "<<i<<" tries/try left \n";
      }
    }
  }
  void admin()
  {
    again:
    clrscr();
    int adminChoice;
    cout<<"\n\n\t\tADMIN USER MENU :";
    cout<<"\n\n\t\t1. Insert an Element";
    cout<<"\n\n\t\t2. Edit Element Details";
    cout<<"\n\n\t\t3. Delete Element";
    cout<<"\n\n\t\t4. Search Element";
    cout<<"\n\n\t\t5. Go Back";
    cout<<"\n\n\t\tEnter your choice\t";
    cin>>adminChoice;
    switch(adminChoice)
    {
      case 1 : insertElement();break;
      case 2 : editElement();break;
      case 3 : deleteElement();break;
      case 4 : searchElement();break;
      case 5 : displayMainMenu();break;
      default : cout<<"\n\n\t\tPlease enter a valid choice";goto again;break;
    }
  }
 void  insertElement()
  {
   again1:
   clrscr();
   cout<<"\n\n\n\t\tINSERT at:";
   cout<<"\n\t\t1.Beginning \n\t\t2.end \n\t\t3.after Specific Element name \n\t\t4.After specific atomic number";
   int choice;
   cin>>choice;
   switch (choice)
    {
     case 1:insertfirst();break;
     case 2:insertend();break;
     case 3:insertspecpos();break;
     case 4:insertafter();break;
     default:cout<<"Enter a valid choice";goto again1;break;
    }
   }
void insertafter()    //insert after atomic no.
{
     again2:
     clrscr();
     fstream file ,temp;table t3;
     t1.getdata();
     file.open("Element.dat",ios::in|ios::binary);
     temp.open("new.dat",ios::out|ios::binary);
     while(file.read((char*)&t3,sizeof(t3)))
	{
	   if(t3.retatmno()==t1.retatmno())
	    {
	      cout<<"\n element already exists \n";
	      file.close();goto again3;
	    }
	 }
     int atno;
     cout<<"\n\n\n\t\t\t ENTER THE ATOMIC NUMBER AFTER WHICH YOU WANT TO INSERT: ";
     cin>>atno;
     file.seekg(0);
     while(file.read((char*)&t2,sizeof(t2)))
     {
	    if( t2.retatmno()!=atno)
	    {
		 temp.write((char*)&t2, sizeof(t2));
	    }
	    else
	    {
		temp.write((char*)&t2,sizeof(t2));
		temp.write((char*)&t1,sizeof(t1));
	    }
      }

      temp.close();
      file.close();
      remove("Element.dat");
      rename("new.dat","Element.dat");
      again3:
      cout<<"Do you Want to continue(y/n) ?";
      char ch;
      cin>>ch;
      if((ch=='y')||(ch=='Y'))
       {
	clrscr();
	goto again2;
       }
       if((ch=='n')||(ch=='N'))
       {
	clrscr;
	admin();
       }
      else
      {
       cout<<"enter a valid choice";
       goto again3;
      }
 }

void insertfirst()      //insert at the first
{     again2:
      fstream file,temp;
      clrscr();
      t1.getdata();table t3;
      file.open("Element.dat",ios::in|ios::binary);
      temp.open("new.dat",ios::out|ios::binary);
      while(file.read((char*)&t3,sizeof(t3)))
	{
	   if(t3.retatmno()==t1.retatmno())
	    {
	      cout<<"\n element already exists \n";
	      file.close();goto again3;
	    }
	 }
      temp.write((char*)&t1, sizeof(t1));
      while(file.read((char*)&t2,sizeof(t2)))
      {
	   temp.write((char*)&t2,sizeof(t2));
      }

      temp.close();
      file.close();
       remove("Element.dat");
      rename("new.dat","element.dat");
      again3:
      cout<<"Do you Want to continue(y/n) ?";
      char ch;
      cin>>ch;
      if((ch=='y')||(ch=='Y'))
       {
	clrscr();
	goto again2;
       }
       if((ch=='n')||(ch=='N'))
       {
	clrscr;
	admin();
       }
      else
      {
       cout<<"enter a valid choice";
       goto again3;
      }

}
void insertend()          //insert at the end
{   again2:
    fstream file,temp;
    clrscr();
    t1.getdata();table t3;
     file.open("Element.dat",ios::in|ios::binary);
     temp.open("new.dat",ios::out|ios::binary);
     while(file.read((char*)&t3,sizeof(t3)))
	{
	   if(t3.retatmno()==t1.retatmno())
	    {
	      cout<<"\n element already exists \n";
	      file.close();goto again3;
	    }
	 }
     file.seekg(0);
     while( file.read((char*)&t2, sizeof(t2)))
     {
	 temp.write((char*)&t2,sizeof(t2));
     }
     temp.write((char*)&t1,sizeof(t1));

      temp.close();
      file.close();
      remove("Element.dat");
      rename("new.dat","element.dat");
      again3:
      cout<<"Do you Want to continue(y/n) ?";
      char ch;
      cin>>ch;
      if((ch=='y')||(ch=='Y'))
       {
	clrscr();
	goto again2;
       }
       if((ch=='n')||(ch=='N'))
       {
	clrscr;
	admin();
       }
      else
      {
       cout<<"enter a valid choice \n";
       goto again3;
      }

}
void insertspecpos()    //to insert afterspecific element name
{   again2:
    clrscr();
    fstream file,temp;
    t1.getdata();table t3;
       file.open("Element.dat",ios::in|ios::binary);
       temp.open("new.dat",ios::out|ios::binary);
	while(file.read((char*)&t3,sizeof(t3)))
	{
	   if(t3.retatmno()==t1.retatmno())
	    {
	      cout<<"\n element already exists \n";
	      file.close();goto again3;
	    }
	 }
       char nme[20];
       cout<<"\n\n\n\t\t\t ENTER THE ELEMENT NAME AFTER WHICH YOU WANT TO INSERT: ";
       gets(nme);
       file.seekg(0);
       while(file.read((char*)&t2,sizeof(t2)))
	{
	    if(strcmpi(t2.retename(),nme)!=0)
	    {
		 temp.write((char*)&t2, sizeof(t2));
	    }
	    else
	    {
		temp.write((char*)&t2,sizeof(t2));
		temp.write((char*)&t1,sizeof(t1));
	    }
	 }
      temp.close();
      file.close();
      remove("Element.dat");
      rename("new.dat","element.dat");

      again3:
      cout<<"Do you Want to continue(y/n) ?";
      char ch;
      cin>>ch;
      if((ch=='y')||(ch=='Y'))
       {
	clrscr();
	goto again2;
       }
       if((ch=='n')||(ch=='N'))
       {
	clrscr;
	admin();
       }
      else
      {
       cout<<"enter a valid choice";
       goto again3;
      }
}

void editElement()         //to edit
  {  again2:
    fstream file;
    clrscr();
    int ele;
    cout<<"\n\n\n\t\t ENTER ATOMIC NUMBER TO EDIT: ";
    cin>>ele;
    cout<<"\n\n ENTER RECORD:";
    t1.getdata();table t2;int count=0;
    file.open("Element.dat",ios::ate|ios::out|ios::binary);
    while(file.read((char*)&t2,sizeof(t2)))
    {
     if(t2.retatmno()==t1.retatmno())
	count++;
    }
    if(count!=0)
    {
     file.seekp((ele-1)*sizeof(t1),ios::beg);
     file.write((char*)&t1,sizeof(t1));
     file.close();
    }
    else
      cout<<"Element not found \n\n";
     again3:
      cout<<"Do you Want to continue(y/n) ?";
      char ch;
      cin>>ch;
      if((ch=='y')||(ch=='Y'))
       {
	clrscr();
	goto again2;
       }
       if((ch=='n')||(ch=='N'))
       {
	clrscr;
	admin();
       }
      else
      {
       cout<<"enter a valid choice";
       goto again3;
      }

  }
void searchElement()             //to search
  {
     again2:
     clrscr();

     fstream file;
     int choice;
     file.open("Element.dat", ios::in|ios::binary);
     cout<<"\n\n\n\t\t\t  SEARCH ACCORDING TO:\n\t\t\t\t 1. Symbol \n\t\t\t\t  2. Atomic Number";
     cout<<"\n\n\n\t\t\t   Enter Choice: ";
     cin>>choice;

     if(choice==1)
     {
	char sym[20]; char f='n'; char n2[20];
	cout<<"\n\n\n\t\t\t   Enter the Element Symbol to Search: ";
	gets(sym);
	while(file.read((char*)&t1, sizeof(t1)))
	{
	    strcpy(n2,t1.retesymb());

	    if(strcmpi(sym,n2)==0)
	    {
		  t1.display();
		  f='y';

	     }
	 }


	 if(f=='n')
	{
	  cout<<"\n\n\n\t\t\t  ELEMENT NOT FOUND!! ";
	}



      }


     if(choice==2)
     {
       char f='n';int atno;
       cout<<"\n\n\n\t\t\t  Enter the Atomic Number to be Searched: ";
       cin>>atno;

       while(file.read((char*)&t1,sizeof(t1)))
       {
	   if(t1.retatmno()==atno)
	   {
	       t1.display();
	       f='y';
	       break;
	    }
	}


	if(f=='n')
	cout<<"\n\n\n\t\t\t  ELEMENT NOT FOUND!! ";


     }

     file.close();again3:
      cout<<"Do you Want to continue(y/n) ?";
      char ch;
      cin>>ch;
      if((ch=='y')||(ch=='Y'))
       {
	clrscr();
	goto again2;
       }
       if((ch=='n')||(ch=='N'))
       {
	clrscr;
	admin();
       }
      else
      {
       cout<<"enter a valid choice";
       goto again3;
      }

  }
void deleteElement()  //to delete
{
   clrscr(); back:
   cout<<"\n\n\t\t\ Delete by:\n\t\t\t\ 1.Name \n\t\t\t 2.Atomic no.";
   int choice;
   cin>>choice;
   switch(choice)
   {

     case 1:delname();break;
     case 2:delno();break;
     default :cout<<"Enter valid choice: \n";goto back;break;
   }
 }
 void delno()       //to delete by no.
 {    again2:
      clrscr();
      fstream file,temp;
      file.open("Element.dat", ios::in|ios::binary);
      temp.open("new.dat",ios::out|ios::binary);
      int atn;
      cout<<"\n\n\n\t\t\t ENTER THE ATOMIC NUMBER TO BE DELETED: ";
      cin>>atn;
      file.seekg(0);int count=0;


      while(file.read((char*)&t2, sizeof(t2)))
      {


	    if(t2.retatmno()!=atn)
	     {
		temp.write((char*)&t2,sizeof(t2));
		count++;

	     }


       }
	file.close();
       temp.close();
       remove("Element.dat");
       rename("new.dat","Element.dat");
       if (count==0)
	cout<<"element does not exist";
	again3:
      cout<<"Do you Want to continue(y/n) ?";
      char ch;
      cin>>ch;
      if((ch=='y')||(ch=='Y'))
       {
	clrscr();
	goto again2;
       }
       if((ch=='n')||(ch=='N'))
       {
	clrscr;
	admin();
       }
      else
      {
       cout<<"enter a valid choice \n";
       goto again3;
      }
 }
 void delname()         //to delete by name
 {
	again2:
       clrscr();
       fstream file,temp;
      file.open("Element.dat", ios::in|ios::binary);
      temp.open("new.dat",ios::out|ios::binary);
      char nme[20];
      cout<<"\n\n\n\t\t\t ENTER THE ELEMENT NAME TO BE DELETED: ";
      gets(nme);
      file.seekg(0);int count=0;
      while(file.read((char*)&t2, sizeof(t2)))
      {
	    if(strcmpi(t2.retename(),nme)!=0)
	    {
		temp.write((char*)&t2,sizeof(t2));count++;
	    }

       }
       if(count==0)
	 cout<<"The element does not exist .... \n";
       file.close();
       temp.close();
       remove("Element.dat");
       rename("new.dat","Element.dat");
       again3:
       cout<<"Do you Want to continue(y/n) ? \n";
       char ch;
       cin>>ch;
       if((ch=='y')||(ch=='Y'))
	{
	 clrscr();
	 goto again2;
       }
       if((ch=='n')||(ch=='N'))
       {
	clrscr;
	admin();
       }
      else
      {
       cout<<"enter a valid choice \n";
       goto again3;
      }
 }



  void anonuser()
  {
    clrscr();
    again:
    cout<<"\n\n\t\tANONYMOUS USER MENU:";
    cout<<"\n\n\n\n\t\t 1.Modern Periodic Table";
    cout<<"\n\n\t\t 2.Hydrocarbon Structure";
    cout<<"\n\n\t\t 3.File Data";
    cout<<"\n\n\t\t 4.Search an element \n\n\t\t 5.Take the test\n\n\t\t 6.Go back \n";
    cout<<"\n\n\t\tEnter your choice:\t";
    int choice; cin>>choice;
    switch(choice)
    {
     case 1:disperiodic();break;
     case 2:disphydro();break;
     case 3:dispfile(); break;
     case 4:searchElement();break;
     case 6:displayMainMenu();break;
     case 5:test();break;
     default:cout<<"\n\n\t\tEnter a valid choice";goto again; break;
    }
  }
 void disperiodic()
 {
    clrscr();
    gotoxy(2,4);
    cout<<"H";
    gotoxy(2,6);
    cout<<"Li";
    gotoxy(2,8);
    cout<<"Na";
    gotoxy(2,10);
    cout<<"K";
    gotoxy(2,12);
    cout<<"Rb";
    gotoxy(2,14);
    cout<<"Cs";
    gotoxy(5,6);
    cout<<"Be";
    gotoxy(5,8);
    cout<<"Mg";
    gotoxy(5,10);
    cout<<"Ca";
    gotoxy(5,12);
    cout<<"Sr";
    gotoxy(5,14);
    cout<<"Ba";
    gotoxy(8,10);
    cout<<"Sc";
    gotoxy(8,12);
    cout<<"Y";
    gotoxy(8,14);
    cout<<"*";
    gotoxy(11,10);
    cout<<"Ti";
    gotoxy(11,12);
    cout<<"Zr";
    gotoxy(11,14);
    cout<<"Hf";
    gotoxy(14,10);
    cout<<"V";
    gotoxy(14,12);
    cout<<"Nb";
    gotoxy(14,14);
    cout<<"Ta";
    gotoxy(17,10);
    cout<<"Cr";
    gotoxy(17,12);
    cout<<"Mo";
    gotoxy(17,14);
    cout<<"W";
    gotoxy(20,10);
    cout<<"Mn";
    gotoxy(20,12);
    cout<<"Tc";
    gotoxy(20,14);
    cout<<"Re";
    gotoxy(23,10);
    cout<<"Fe";
    gotoxy(23,12);
    cout<<"Ru";
    gotoxy(23,14);
    cout<<"Os";
    gotoxy(26,10);
    cout<<"Co";
    gotoxy(26,12);
    cout<<"Rh";
    gotoxy(26,14);
    cout<<"Ir";
    gotoxy(29,10);
    cout<<"Ni";
    gotoxy(29,12);
    cout<<"Pd";
    gotoxy(29,14);
    cout<<"Pt";
    gotoxy(32,10);
    cout<<"Cu";
    gotoxy(32,12);
    cout<<"Ag";
    gotoxy(32,14);
    cout<<"Au";
    gotoxy(35,10);
    cout<<"Zn";
    gotoxy(35,12);
    cout<<"Cd";
    gotoxy(35,14);
    cout<<"Hg";
    gotoxy(38,6);
    cout<<"B";
    gotoxy(38,8);
    cout<<"Al";
    gotoxy(38,10);
    cout<<"Ga";
    gotoxy(38,12);
    cout<<"In";
    gotoxy(38,14);
    cout<<"TI";
    gotoxy(41,6);
    cout<<"C";
    gotoxy(41,8);
    cout<<"Si";
    gotoxy(41,10);
    cout<<"Ge";
    gotoxy(41,12);
    cout<<"Sn";
    gotoxy(41,14);
    cout<<"Pb";
    gotoxy(44,6);
    cout<<"N";
    gotoxy(44,8);
    cout<<"P";
    gotoxy(44,10);
    cout<<"As";
    gotoxy(44,12);
    cout<<"Sb";
    gotoxy(44,14);
    cout<<"Bi";
    gotoxy(47,6);
    cout<<"O";
    gotoxy(47,8);
    cout<<"S";
    gotoxy(47,10);
    cout<<"Se";
    gotoxy(47,12);
    cout<<"Te";
    gotoxy(47,14);
    cout<<"Po";
    gotoxy(50,6);
    cout<<"F";
    gotoxy(50,8);
    cout<<"Cl";
    gotoxy(50,10);
    cout<<"Br";
    gotoxy(50,12);
    cout<<"I";
    gotoxy(50,14);
    cout<<"At";
    gotoxy(53,4);
    cout<<"He";
    gotoxy(53,6);
    cout<<"Ne";
    gotoxy(53,8);
    cout<<"Ar";
    gotoxy(53,10);
    cout<<"Kr";
    gotoxy(53,12);
    cout<<"Xe";
    gotoxy(53,14);
    cout<<"Rn";
    cout<<"\n\n";

    cout<<"\n\n\n\n Press any key...";
    getch();
    anonuser();
 }
 void disphydro()
 {
    clrscr();
    again1:
    clrscr();
    int choice;
    cout<<"\n\n\n\t\tHYDROCARBON STRUCTURE:";
    cout<<"\n\n\n\t\t1.ALKANE";
    cout<<"\n\n\n\t\t2.ALKENE";
    cout<<"\n\n\n\t\t3.ALKYNE";
    cout<<"\n\n\n\t\t  ENTER CHOICE:";
    cin>>choice;
    switch(choice)//switch construct for hydrocarbon begins
    {
    case 1: dispAlkane();break;
    case 2: dispAlkene();break;
    case 3: dispAlkyne();break;
    default: cout<<"\n\n\tPlease enter a valid choice. Press any key...";getch();goto again1;break;
    }
   again2:
   cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t Do You Want to display another hydrocarbon structure(y/n):\t";
   char cnt; cin>>cnt;
   if((cnt=='y')||(cnt=='Y'))
     goto again1;
    if((cnt=='n')||(cnt=='N'))
     anonuser();
   else
   {
    cout<<"\nNot valid choice\t"<<"Press any key....";
    getch();
    goto again2;
    }
 }
 //method for displaying Alkane structure
 void dispAlkane()
 {
  again :
  clrscr();
  int numberCarbon = 0;
  cout<<"\n\n\t\tEnter the number of carbon atoms\t";
  cin>>numberCarbon;
  if(!(numberCarbon >= 0 && numberCarbon <=50))
  {
    cout<<"\n\n\tPlease enter a valid number. Press any key to continue....";
    getch();
    goto again;
  }
  else
  {
  int xCoord = 12;
  int yCoord = 10;
  gotoxy(10,10);cout<<"H";
  gotoxy(11,10);cout<<"-";
  for(int i=0; i < numberCarbon; i++, xCoord+=2){
    gotoxy(xCoord,yCoord);cout<<"C";
    gotoxy(xCoord+1,yCoord);cout<<"-";
    gotoxy(xCoord,yCoord-1);cout<<"|";
    gotoxy(xCoord,yCoord-2);cout<<"H";
    gotoxy(xCoord,yCoord+1);cout<<"|";
    gotoxy(xCoord,yCoord+2);cout<<"H";
   }
  gotoxy(xCoord,yCoord);cout<<"H";
  }
 }
 //method for displaying Alkene structure
 void dispAlkene()
 {
  again :
  clrscr();
  int numberCarbon = 0;
  int bondNumber = 0;
  cout<<"\n\n\t\tEnter the number of carbon atoms for alkene\t";
  cin>>numberCarbon;
  cout<<"\n\n\t\tEnter the number of carbon atom on which double bond is required\t";
  cin>>bondNumber;
  if(!((numberCarbon >= 0 && numberCarbon <= 50)&&(bondNumber >= 0 && bondNumber <= 50)))
  {
    cout<<"\n\n\t Please enter a valid number. Press any key to continue....";
    getch();
    goto again;
  }
  else if(bondNumber > numberCarbon)
  {
    cout<<"\n\n\t Please enter a valid bond number. Press any key to continue....";
    getch();
    goto again;
  }
  else
  {
    int xCoord = 12;
    int yCoord = 10;
    gotoxy(10,10);cout<<"H";
    gotoxy(11,10);cout<<"-";
    for(int i=1; i <= numberCarbon; i++, xCoord+=2){
       gotoxy(xCoord,yCoord);cout<<"C";
       if(i == bondNumber)
       {
	  gotoxy(xCoord+1,yCoord);cout<<"=";
       }
       else
       {
	  gotoxy(xCoord+1,yCoord);cout<<"-";
       }
       if( (i == bondNumber) || (i == bondNumber+1) )
       {
	  gotoxy(xCoord,yCoord-1);cout<<"|";
	  gotoxy(xCoord,yCoord-2);cout<<"H";
       }
       else
       {
	  gotoxy(xCoord,yCoord-1);cout<<"|";
	  gotoxy(xCoord,yCoord-2);cout<<"H";
	  gotoxy(xCoord,yCoord+1);cout<<"|";
	  gotoxy(xCoord,yCoord+2);cout<<"H";
       }
    }
    gotoxy(xCoord,yCoord);cout<<"H";
  } //else part ends
 }
 //method for displaying Alkyne structure
 void dispAlkyne()
 {
   again :
   clrscr();
   int numberCarbon = 0;
   int bondNumber = 0;
   cout<<"\n\n\t\tEnter the number of carbon atoms for alkyne\t";
   cin>>numberCarbon;
   cout<<"\n\n\t\tEnter the number of carbon atom on which triple bond is required.\t";
   cin>>bondNumber;
   if(!((numberCarbon >= 0 && numberCarbon <= 50)&&(bondNumber >= 0 && bondNumber <= 50)))
   {
     cout<<"\n\n\t\tPlease enter a valid number. press any ket to continue...";
     getch();
     goto again;
   }
    else if(bondNumber > numberCarbon)
   {
     cout<<"\n\n\t Please enter a valid bond number. Press any key to continue....";
     getch();
     goto again;
   }
   else
   {
     int xCoord = 12;
     int yCoord = 10;
     gotoxy(10,10);cout<<"H";
     gotoxy(11,10);cout<<"-";
     for(int i=1; i <= numberCarbon; i++, xCoord+=2)
     {
       gotoxy(xCoord,yCoord);cout<<"C";
       if(i == bondNumber)
       {
	 gotoxy(xCoord+1,yCoord);cout<<char(240);
       }
       else
       {
	  gotoxy(xCoord+1,yCoord);cout<<"-";
       }
      if(i == bondNumber || i == bondNumber+1)
      {
	continue;
      }
      else
      {
	gotoxy(xCoord,yCoord-1);cout<<"|";
	gotoxy(xCoord,yCoord-2);cout<<"H";
	gotoxy(xCoord,yCoord+1);cout<<"|";
	gotoxy(xCoord,yCoord+2);cout<<"H";
      }
   }
   gotoxy(xCoord,yCoord);cout<<"H";
  }
 }

 void dispfile()
 {
  clrscr();table t1;
  fstream file;
  file.open("Element.dat",ios::in|ios::binary);
   while(file.read((char*)&t1,sizeof(t1)))
     {
      t1.display();
      cout<<"\n\t\t Press any key to continue";
      getch();
      clrscr();
     }
    cout<<" \n\n\t\t press any key to go back to main menu...";
    getch();
    anonuser();
    file.close();
 }
 void test()
 {
   loadQues(array);
   again :
   clrscr();
   int i;
   int score=0;
   char string[5];
   cout<<"\t"<<"\t";cout<<"\t"<<"\t"<<	   "  Quiz Time "           <<endl<<endl<<endl;
   cout<<" 1.GO- start the quiz"; cout<<endl;
   cout<<" 2.Help         " ;     cout<<endl;
   cout<<" 3.Exit          " ;    cout<<endl;
   randomize();
    cout<< "\n\n Type 'GO' to start the quiz or 'Help' for instructions or Exit to quit the game";cout<<endl;
    gets(string);
    if(strcmpi(string,"help")==0)
    {
	cout<<" This quiz contains 10 questions"<<"\n";
	cout<<" Every question contain four options"<<"\n";
	cout<<" Select one option as an answer"<<"\n";
	cout<<" Every correct answer will be rewarded with 10 points"<<"\n";
	cout<<" For every wrong answer 5 points will be deducted "<<"\n";
    }
    else if(strcmpi(string,"exit")==0)
    {
       cout<<"\n\n\t"<<"THANKS for Playing!!BYE BYE...Press any key to continue.. ";    	 getch();
       getch();
       anonuser();
    }
    else if(strcmpi(string,"GO")==0)
     {
	clrscr();
	char name[20];
	cout<<"\tEnter Your Name:";
	cin.getline(name,20);
	loadQues(array);
	cout<<"\tSo, lets Begin the quiz with "<<name;cout<<endl;

	for(i=0;i<2;i++)
	{
	    clrscr();
	    int randId = 0 ;      // random function added
	    randId = random(10);
	    char ans[20];
	    cout<<"\n\n\tQuestion"<<i+1<<"\t";
	    cout<<(array[randId].question);cout<<endl<<endl ;
	    cout<<"\n\n\toption 1 "<<(array[randId].option1); cout<<endl;
	    cout<<"\n\n\toption 2 "<<(array[randId].option2);cout<<endl;
	    cout<<"\n\n\toption 3 "<<(array[randId].option3);cout<<endl;
	    cout<<"\n\n\toption 4 "<<(array[randId].option4);cout<<endl;
	    cout<<"\n\n\tPlease type your answer"<<endl;
	    cin.getline(ans,20);
	    if(strcmpi(ans,array[randId].answer)==0)
	    {
	       score+=10;  cout<<"wonderful ,you are correct"<<endl;
	       if(i<1)
		  cout<<"lets move on to our next question"<<endl;
	       getch();
	    }
	  else
	    {
	       score-=5;
	       cout<<"you are wrong"<<endl;
	       if(i==2)
		 cout<<"\n\n\tThe quiz ends here";
	       else
		 cout<< "dont loose hope ,lets move to our next question"<<endl;
	       getch();
	    }
	  }
	  cout<<"\n\n\tYour score is "<<score;
	  cout<<"\n\n\t Press any key to go back to main menu\t";
	  getch();
	  goto again;
	}
       else
       {
	   cout<<"dont type anything invalid!!! Press any key to go back to main menu....";
	   getch();
	   goto again;
       }

 }
 void loadQues(question questionArray[])
{
 questionArray[0].qid=1;
 strncpy(questionArray[0].question,"\n\n\tAbout how many known elements are there in the periodic table ?",100);
 strncpy(questionArray[0].answer,"118",25);
 strncpy(questionArray[0].option1,"10",25);
 strncpy(questionArray[0].option2,"50",25);
 strncpy(questionArray[0].option3,"100",25) ;
 strncpy(questionArray[0].option4,"118",25)  ;
 questionArray[1].qid=2;
 strncpy(questionArray[1].question,"\n\n\tThe elements in the periodic table are arranged by :",100);
 strncpy(questionArray[1].answer,"Atomic Number",20);
 strncpy(questionArray[1].option1,"Atomic Mass",20);
 strncpy(questionArray[1].option2,"Atomic Number",20);
 strncpy(questionArray[1].option3,"Chemical Reactivity",20) ;
 strncpy(questionArray[1].option4,"Neutron Number",20);
 questionArray[2].qid=3;
 strncpy(questionArray[2].question,"\n\n\tWhich of these things are not listed in the periodic table?",100);
 strncpy(questionArray[2].answer,"Atomic Orbital Radius",20);
 strncpy(questionArray[2].option1,"Element Name or Symbol",20);
 strncpy(questionArray[2].option2,"Atomic Mass",20);
 strncpy(questionArray[2].option3,"Atomic Number",20);
 strncpy(questionArray[2].option4,"Atomic Orbital Radius",20);
 questionArray[3].qid=4;
 strncpy(questionArray[3].question,"Which scientist came up with the concept of Periodic table ?",100);
 strncpy(questionArray[3].answer,"Dmitri Mendeleev",20);
 strncpy(questionArray[3].option1,"Jason Priestly",20);
 strncpy(questionArray[3].option2,"Dmitri Mendeleev",20);
 strncpy(questionArray[3].option3,"Antoine Lavoisier",20) ;
 strncpy(questionArray[3].option4,"Albert Einstein",20);
 questionArray[4].qid=5;
 strncpy(questionArray[4].question,"Which of these is not a family of elements ?",100);
 strncpy(questionArray[4].answer,"All are families of elements",20);
 strncpy(questionArray[4].option1,"Halogens",20);
 strncpy(questionArray[4].option2,"Lanthanoids",20);
 strncpy(questionArray[4].option3,"Noble Gases",20);
 strncpy(questionArray[4].option4,"All are families of elements",20) ;
 questionArray[5].qid=6;
 strncpy(questionArray[5].question,"What does atomic number tell about a neutral atom ?",100);
 strncpy(questionArray[5].answer,"Number of protons",20);
 strncpy(questionArray[5].option1,"Number of protons",20);
 strncpy(questionArray[5].option3,"Neutron Number",20);
 strncpy(questionArray[5].option2,"Atomic Mass Number",20) ;
 strncpy(questionArray[5].option4,"None of the above",20);
 questionArray[6].qid=7;
 strncpy(questionArray[6].question,"What is the symbol for Sodium ?",100);
 strncpy(questionArray[6].answer,"Na",20);
 strncpy(questionArray[6].option1,"Mg",20);
 strncpy(questionArray[6].option2,"Hg",20);
 strncpy(questionArray[6].option3,"Cl",20) ;
 strncpy(questionArray[6].option4,"Na",20);
 questionArray[7].qid=8;
 strncpy(questionArray[7].question,"Which of these is the symbol for Arsenic ?",100);
 strncpy(questionArray[7].answer,"As",20);
 strncpy(questionArray[7].option1,"As",20);
 strncpy(questionArray[7].option2,"Ar",20);
 strncpy(questionArray[7].option3,"O",20) ;
 strncpy(questionArray[7].option4,"Al",20);

questionArray[8].qid=9;
 strncpy(questionArray[8].question,"Which of these is the symbol for Mercury ?",100);
 strncpy(questionArray[8].answer,"Hg",20);
 strncpy(questionArray[8].option1,"Mg",20);
 strncpy(questionArray[8].option2,"C",20);
 strncpy(questionArray[8].option3,"Hg",20) ;
 strncpy(questionArray[8].option4,"Pb",20);

 questionArray[9].qid=10;
 strncpy(questionArray[9].question,"which period does sodium lie ?",100);
 strncpy(questionArray[9].answer,"3",20);
 strncpy(questionArray[9].option1,"7",20);
 strncpy(questionArray[9].option2,"3",20);
 strncpy(questionArray[9].option3,"4",20) ;
 strncpy(questionArray[9].option4,"2",20);


}




