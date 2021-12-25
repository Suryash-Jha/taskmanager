#include<bits/stdc++.h>
using namespace std;


int main(int argc, char** argv)
{
map<string, int> m;
m["add"]= 1;
m["ls"]=2;
m["del"]=3;
m["done"]=4;
m["help"]= 5;
m["report"]=6;

fstream myfile;
  multimap<int, string> taskXprior;
  myfile.open("file.txt", ios::in);
  if(myfile.is_open()){
    string line;
    while(getline(myfile, line)){
auto priority = stoi(line.substr(0, line.find(' ')));
 auto task= line.substr(line.find(' ')+1, line.length());
      taskXprior.insert({priority, task});
      
    }
    myfile.close();
    myfile.open("file.txt", ios::out);
    {
     for(auto it: taskXprior){
      myfile<<it.first<<" "<<it.second<<endl;
    }
    myfile.close(); 
    }
    
  }
int command= m[argv[1]];

   switch(command){
   	case 1:
         {
          auto priority = stoi(argv[2]);
          string task;
          for(int i=3; i<argc; i++)
          {
          	task+= argv[i];
          	task+=' ';
          } 
          taskXprior.insert({priority, task});
          myfile.open("file.txt", ios::out);
          if(myfile.is_open())
          {
          	for(auto it: taskXprior){
               cout<<it.first<<" "<<it.second<<endl;
          		myfile<<it.first<<" "<<it.second<<endl;
          	}
          	myfile.close();
          }
         } 

   	      
   	      break;
    case 2:
          {
            myfile.open("file.txt", ios::in);
            if(myfile.is_open()){
            	string line;
            	int count=1;
            	while(getline(myfile, line)){
            		auto priority = stoi(line.substr(0, line.find(' ')));
 					auto task= line.substr(line.find(' ')+1, line.length());
 					cout<<count<<".) "<<task<<" ["<<priority<<"]"<<endl;
 					count++;
            	}
            	myfile.close();
            }

          }
          break;
   	case 5: 
   	    cout<<"Usage :-";
		cout<<"	\n	$ ./task add 2 hello world    # Add a new item with priority 2 and text \"hello world\" to the list";
		cout<<"	\n	$ ./task ls                   # Show incomplete priority list items sorted by priority in ascending order";
		cout<<"	\n	$ ./task del INDEX            # Delete the incomplete item with the given index";
		cout<<"	\n	$ ./task done INDEX           # Mark the incomplete item with the given index as complete";
		cout<<"	\n	$ ./task help                 # Show usage";
		cout<<"	\n	$ ./task report               # Statistics";
   	      break;

   	default:
   	      cout<<"\n Wrong input";
   }



}