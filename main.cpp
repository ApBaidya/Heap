/*
Aparajita Baidya 2.20.2026
*/
#include <iostream>
#include <cstring>
#include <fstream>

using namespace std;

//definitions
void addSort();
void Add();
void fileAdd();
void Print();
void rmvSort();
void Delete();
void Reset();

//main
int main(){
  //variables
  running = 1;
  int heap[100];
  char input;//just user input
  while(running == 1){
    cout<<"welcome, what would you like to do?: "<<endl;
    cout<<"[a] add, [f] add via filename, [p] print, [d] delete a number, [r] reset, [q] quit"<<endl;
    if(input == 'a'){
      Add();
    }
    else if(input == 'f'){
      fileAdd();
    }
    else if(input == 'p'){
      Print();
    }
    else if(input == 'd'){
      Delete();
      Print();//just to check
    }
    else if(input == 'r'){
      Reset();
    }
    else if(input == 'q'){
      Reset();
      Print();//just to check
      running = 0;
    }
  }//end main loop
  cout<<"Farewell. Fare thee well."<<endl;
  return 0;
}

void addSort(){
  //check parent
  //parent = (i-1)/2
  //swap with parent if you are larger
  //recurse till root
}

void Add(){
  //keep asking them for numbers till they want to stop
  //add to bottom of tree(bottom row, rightmost empty spot)
  //sort after each add
}

void fileAdd(){
  //open a file
  //maybe put all values in a vector
  //iterate through vector and do add process
}

void Print(){
  //
}

void rmvSort(){
  //check left and right child --> who is larger
  //left = 2i + 1, right = 2i + 2
  //if root is less than one of them, swap
  //recurse until bigger than children, or at leaf
}

void Delete(){
  //output root value to console
  //remove root
  //move bottom of tree to the root
  //reduce table size
  //rm sort
}

void Reset(){
  //just...keep calling delete 
}
