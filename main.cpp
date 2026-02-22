/*
Aparajita Baidya 2.22.2026
*/
#include <iostream>
#include <cstring>
#include <fstream>
#include <string>//oh god.

using namespace std;

//definitions
void addSort(int* heap, int lastPos);
int* Add(int* heap, int &lastPos);
void fileAdd(int* heap, int &lastPos);
void Print(int* heap, int lastPos);
void rmvSort(int* heap, int pos);
void Delete(int* heap, int &lastPos);
void Reset(int* heap, int &lastPos);

//main
int main(){
  //variables
  int lastPos = 0;//where to inset number
  int running = 1;
  int* heap = new int[lastPos];
  char input;//just user input
  while(running == 1){
    cout<<"what would you like to do?: "<<endl;
    cout<<"[a] add, [f] add via filename, [p] print, [d] delete root, [r] reset, [q] quit"<<endl;
    cin >> input;
    cin.ignore(10, '\n');
    cin.clear();
    if(input == 'a'){
      heap = Add(heap, lastPos);
    }
    else if(input == 'f'){
      fileAdd(heap, lastPos);
    }
    else if(input == 'p'){
      Print(heap, lastPos);
    }
    else if(input == 'd'){
      Delete(heap, lastPos);
      Print(heap, lastPos);//just to check
    }
    else if(input == 'r'){
      Reset(heap, lastPos);
    }
    else if(input == 'q'){
      Reset(heap, lastPos);
      Print(heap, lastPos);//just to check
      running = 0;
    }
  }//end main loop
  cout<<"Farewell. Fare thee well."<<endl;
  return 0;
}

void addSort(int* heap, int lastPos){
  //end cond, nothing left to check
  cout<<"sort"<<endl;
  if(lastPos == 0){
    return;
  }
  int parentPos = ((lastPos-1)/2);
  int parent = heap[parentPos];//parent = (i-1)/2
  int current = heap[lastPos];
  if(parent<current){//swap with parent if you are larger
    heap[parentPos]=current;
    heap[lastPos]=parent;
    lastPos = parentPos;
    addSort(heap, lastPos);//recurse till root
  }
  else{//nothing to sort 
    return;
  }
}

int* Add(int* heap, int &lastPos){
  char running = 'y';
  int data;//input number
  int* tempH = new int[lastPos];
  int* tempH2 = new int[lastPos];
  for(int i = 0; i<lastPos; i++){
    tempH2[i] = heap[i];
  }
  cout<<tempH[0]<<endl;
  //keep asking them for numbers till they want to stop
  while(running == 'y'){
    cout<<"would you like to add (y/n)"<<endl;
    cin>>running;
    cin.ignore(10, '\n');
    cin.clear();
    if(running == 'y'){
      tempH = new int[lastPos + 1];
      for(int i = 0; i < lastPos; i ++){
	tempH[i] = tempH2[i];
      }
      cout<<"gimme data"<<endl;
      cin>>data;
      tempH[lastPos]=data;
      cout<<tempH[0]<<endl;
      addSort(tempH, lastPos);
      ++ lastPos;
      cout<<tempH[0];
      tempH2 = new int[lastPos];
      for(int i = 0; i<lastPos; i++){
	tempH2[i] = tempH[i];
      }
    }
  }
  delete[] tempH2;
  cout<<tempH[0];
  return tempH;
  cout<<"done adding, then."<<endl;
}

void fileAdd(int* heap, int &lastPos){
  string filePath;//(-_-)...
  int data;
  cout<<"Gimme that file path"<<endl;
  cin>>filePath;
  cin.clear();
  ifstream nums(filePath);
  if(nums.is_open()){
    //go through file and add each number...one by one...
    while(nums>>data){
    }
    cout<<"done adding, then (with the file)"<<endl;
  }
  else{
    cout<<"ooooops can't seem to open that fellow."<<endl;
  }
}

void Print(int* heap, int lastPos){
  for(int i = 0; i<lastPos; i ++){
    cout<<heap[i]<<endl;
  }
  //not really sure what to do here hahaha.
}

void rmvSort(int* heap, int pos){
  int leftPos = (2*pos)+1;
  int rightPos = (2*pos)+2;
  int current = heap[pos];
  int leftC = heap[leftPos];
  int rightC = heap[rightPos];
  //returns
  //if()
  //check left and right child --> who is larger
  //left = 2i + 1, right = 2i + 2
  //if root is less than one of them, swap
  //recurse until bigger than children, or at leaf
}

void Delete(int* heap, int &lastPos){
  //output root value to console
  int heap2[lastPos];//make a smaller array
  cout<<"root"<<heap[0];
  int root = heap[0];
  int last = heap[lastPos];
  //move bottom of tree to the root
  //reduce table size
  //rm sort
  int pos = 0;//root
  rmvSort(heap, lastPos);
}

void Reset(int* heap, int &lastPos){
  //just...keep calling delete 
}
