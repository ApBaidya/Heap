/*
Aparajita Baidya 2.24.2026
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
void rmvSort(int* heap, int pos, int lastPos);
int* Delete(int* heap, int &lastPos);
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
      //cout<<"LASTPOS"<<lastPos<<endl;
      heap = Delete(heap, lastPos);
      Print(heap, lastPos);//just to check
      //cout<<"LASTPOS"<<lastPos<<endl;
    }
    else if(input == 'r'){
      Reset(heap, lastPos);
    }
    else if(input == 'q'){
      Reset(heap, lastPos);
      Print(heap, lastPos);//just to check
      delete[] heap;
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
  //cout<<tempH[0]<<endl;
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
      //cout<<tempH[0]<<endl;
      Print(tempH, lastPos);
      addSort(tempH, lastPos);
      ++ lastPos;
      //cout<<tempH[0];
      tempH2 = new int[lastPos];
      for(int i = 0; i<lastPos; i++){
	tempH2[i] = tempH[i];
      }
    }
  }
  delete[] tempH2;
  //cout<<tempH[0];
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
  cout<<"PRINING"<<endl;
  for(int i = 0; i<lastPos; i ++){
    cout<<heap[i]<<endl;
  }
  //not really sure what to do here hahaha.
}
//??????? Why is this not working
void rmvSort(int* heap, int pos, int lastPos){
  int leftPos = (2*pos)+1;//left = 2i + 1, right = 2i + 2
  int rightPos = (2*pos)+2;
  int current = heap[pos];
  cout<<current<<"left"<<heap[leftPos]<<"right"<<heap[rightPos]<<endl;
  //returns
  if(leftPos>=lastPos){
    //leaf
    cout<<"NAH"<<endl;
    return;
  }
  int leftC = heap[leftPos];
  if(rightPos>lastPos){//only look at leftmost
    if(leftC>current){
      cout<<"AAAA"<<endl;
      heap[leftPos] = current;
      heap[pos] = leftC;
      cout<<heap[pos]<<endl;
      return;//?
    }
  }
  int rightC = heap[rightPos];
  //check left and right child --> who is larger
  if(leftC>current && rightC>current){
    if(leftC>=rightC){
      heap[leftPos]=current;
      heap[pos]=leftC;
      cout<<"A"<<endl;
      cout<<"new"<<heap[pos]<<endl;
      rmvSort(heap, leftPos, lastPos);
      return;
    }
    else{
      heap[rightPos]=current;
      heap[pos]=rightC;
      cout<<"B"<<endl;
      rmvSort(heap, rightPos, lastPos);
      return;
    }
  }
  else if(leftC>current){
    heap[leftPos]=current;
    heap[pos]=leftC;
    cout<<"C"<<endl;
    rmvSort(heap, leftPos, lastPos);
    return;
  }
  else if(rightC>current){
    heap[rightPos]=current;
    heap[pos]=rightC;
    cout<<"D"<<endl;
    rmvSort(heap, rightPos, lastPos);
    return;
  }
  return;
}

int* Delete(int* heap, int &lastPos){
  //output root value to console
  if(lastPos != 0){
    int* tempH = new int[lastPos-1];//make a smaller array
    cout<<"root"<<heap[0]<<endl;
    int root = heap[0];
    int last = heap[lastPos-1];
    cout<<last<<endl;
    heap[0] = last;
    heap[lastPos-1] = root;
    -- lastPos;
    for(int i = 0;i<lastPos;i++){
      tempH[i] = heap[i];
    }
    int pos = 0;
    rmvSort(tempH, pos, lastPos);
    return tempH;
  }
  return heap;
}

void Reset(int* heap, int &lastPos){
  int oldLP = lastPos;
  for(int i = 0; i < oldLP; i ++){
  //just...keep calling delete
    heap = Delete(heap, lastPos);
  }
  Print(heap, lastPos);
}
