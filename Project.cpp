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

int command= m[argv[1]];

   switch(command){
   	case 1:myfile.open("task.txt", ios::app);
   	       if(myfile.is_open())
   	       {
   	       	myfile<<argv[2]<<" "<<argv[3]<<"\n";
   	       }
   	       myfile.close();
   	      
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