#include<fstream>
#include <iostream>
#include <iomanip>
#include<stdlib.h>
#include<cstring>
using namespace std;
struct student {
       int id;
       char fName[15],lName[20];
};

void put(const char fileName[]){
   student s;
   fstream 
   file(fileName, ios::out|ios::app);
   cout<<"\nEnter id no:  ";  cin>>s.id;
   while (s.id != 0){
       cout<<"Enter name: ";      cin>>s.fName;
       cout<<"Enter last name: "; cin>>s.lName;
       file.write((char *)&s, sizeof(student));
       cout<<"\nEnter id no:  ";  cin>>s.id;
   }
   file.close();
   cout <<endl;
//   system("pause");
}

void displayRec(const char fileName[]){
   student s;
   bool found = false;
   fstream file(fileName,ios::in);
   if(!file){
       cout << "\nError Can not open file. . . ";
      // system("pause");
       return; //exit(1);
   }
   cout << "\nStudent No" << "  " << "First Name     " << "  " << "Last Name           " << endl;
   //file.seekg(0);
   while((file.read((char *)&s, sizeof(s)))){
      if(s.id){
         cout << setw(10) << right << s.id << "  "
              << setw(15) << left << s.fName << "  "
              << setw(20) << left << s.lName << "  "
              << endl;
         found = true;
      }
   }
   file.close();
   if (!found) cout<<"\nNo record found ... ";
   //system("pause");
}

void modify(const char fileName[]){
   student s;
   int temp;
   bool found = false;
   long location;
   char yesNo;
   fstream file(fileName,ios::in | ios:: out);
   if(!file){
       cout << "\nError Can not open file. . . ";
      // system("pause");
       return; //exit(1);
   }
   cout<<"\nenter id no: "; cin>>temp;
   cin.ignore(100,'\n');
   //file.seekg(0,ios::beg);
   while((file.read((char *)&s,sizeof(student)))){
      if(s.id != 0 && s.id == temp){
         cout<< "id no.: " << s.id << endl;
         cout<< "student name:  " << s.fName << endl;
         cout<< "last name: " << s.lName << endl <<endl;
         found = true;
         location = file.tellg();
         cout << "Do u want to chang data [Y/N]: "; cin >> yesNo;
         cin.ignore(100,'\n');
         if (yesNo == 'Y' || yesNo == 'y'){
               cout << "\nEnter id no:  ";  cin >> s.id;
               cin.ignore(100,'\n');
               cout << "Enter name: ";      cin >> s.fName;
               cin.ignore(100,'\n');
               cout << "Enter last name: "; cin >> s.lName;
               cin.ignore(100,'\n');
               file.seekp(location -  sizeof(student));
               file.write((char *)&s, sizeof(student));
               cout<<"\nRecord Updated ... ";
         }
         break;
      }
   }
   file.close();
   if (!found) cout<<"\nnot found ... ";
   //system("pause");
}

void deleteRec(const char fileName[]){
   student s;
   int temp;
   bool found = false;
   long location;
   char yesNo;
   fstream file(fileName,ios::in | ios:: out);
   if(!file){
       cout << "\nError Can not open file. . . ";
     //  system("pause");
       exit(1);
   }
   cout<<"\nenter id no: "; cin>>temp;
   file.seekg(0,ios::beg);
   while(file.read((char *)&s, sizeof(student))){
      if(s.id != 0 && s.id == temp){
         cout<<"id no.: "<<s.id<<endl;
         cout<<"student name:  "<<s.fName<<endl;
         cout<<"last name: "<<s.lName<<endl<<endl;
         found = true;
         location = file.tellg();
         cout << "Do u want delete data [Y/N]: "; cin >> yesNo;
         if (yesNo == 'Y' || yesNo == 'y') {
               //student blankRec;
               s.id = 0; strcpy(s.fName ," "); strcpy(s.lName ," ");
               file.seekp(location - sizeof(student),ios::beg);
               file.write((char *)&s, sizeof(student));
               cout<<"\nRecord deleted ... ";
               }
         break;
      }
   }
   file.close();
   if (!found) cout<<"\nnot found ... ";
   //system("pause");
}

int enterChoice(){ // enable user to input menu choice
   cout << "\n\nChoice ................" << endl
        << "1 - Display information" << endl
        << "2 - Add " << endl
        << "3 - Modify" << endl
        << "4 - Delete" << endl
        << "0 - End program " << endl;
   int menuChoice;
   cout << "\nEnter your choice: "; cin >> menuChoice;
   return menuChoice;
}
main(){
   char fileName[30];
   cout << "\nRnter file name: "; cin >> fileName;
   int choice;
   do {
       choice = enterChoice();
       switch (choice) {
          case 1: displayRec(fileName); break;
          case 2: put(fileName); break;
          case 3: modify(fileName); break;
          case 4: deleteRec(fileName); break;
          case 0: break;
          default: cout << "Enter valid choice ...\n";
       }
   } while(choice);
   cout <<endl;
   //system("pause");
}

