#include<iostream>
using namespace std;
void print1(int n){
    for(int i=1;i<=n;i++){

     for(int j=0;j<n-i;j++){
     
        cout<<" "; 
        }
      for(char j=65;j<'A'+i;j++){
     
        cout<<j; 
        }
         for(char j=65;j<'A'+i-1;j++){
     
        cout<<j; 
        }
       
        cout<<endl;  
    }

}
int main(){
     int n;
     cout<<"Enter the number ";
     cin>>n;
   print1(n);
     
 
    return 0;
}
//     A
//    ABA
//   ABCAB
//  ABCDABC
// ABCDEABCD