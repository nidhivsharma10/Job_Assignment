#include<iostream>
#include<stdlib.h>
using namespace std;

int main(){
    int cost = 0,minVal,minIndex=-1,val,N;  
    cout<<"Enter the no. of workers/Jobs: "<<endl;
    cin>>N; 
	bool assigned[N]={false};
	int costMatrix[N][N];
	
    //taking random input
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            val=rand()%100+1;
            costMatrix[i][j]=val; 
        }
    }
    
   //printing the matrix 
   cout<<"   ";
   for(int k=0;k<N;k++)
        cout<<"J"<<k<<" ";
    cout<<endl;
    for(int i=0;i<N;i++){
        cout<<"W"<<i+1<<" ";
        for(int j=0;j<N;j++){
            cout<<costMatrix[i][j]<<" "; 
        }
        cout<<endl;
    }
    //calculating the minimum cost job for each worker
    for(int i=0;i<N;i++){
        minVal=9999;
        for(int j=0;j<N;j++){
            if(!assigned[j] && costMatrix[i][j]<minVal){
               minVal = costMatrix[i][j];
               minIndex=j;
            }
        }
        cost+=minVal;
        assigned[minIndex]=true;
        cout<<"Worker "<<i+1<<"  is assigned to job No: J"<<minIndex<<endl;
    }
    cout<<"Total cost of path is :  "<<cost<<endl;
  return 0;  
}
