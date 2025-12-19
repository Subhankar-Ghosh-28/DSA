#include<iostream>
// #include<bits/stdc++.h>
#include<list>

using namespace std;

int main(){
  list<int> ls={1,2 ,1,3};
  ls.push_front(6);
  for(auto it : ls){
    cout<<it<<" ";
  }
   return 0;
}