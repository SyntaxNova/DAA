#include<iostream>
using namespace std;

int main(){
    int n;                                                     //number of objects
    cout<<"Enter total number of objecs"<<" ";
    cin>>n;
    int weight[n+1];                                           //weight array                                        
    int profit[n+1];                                           //profit array
    weight[0]=0;                                               //first element as 0
    profit[0]=0;                                               //first element as 0
    cout<<"Enter weights for each object"<<" ";
    for(int i=1;i<n+1;i++){
        cin>>weight[i];
    }
    cout<<"Enter profit for each object"<<" ";
    for(int i=1;i<n+1;i++){
        cin>>profit[i];
    }
    int size;
    cout<<"Enter capacity of the sack"<<" ";
    cin>>size;
    int mat[n+1][size];                                        //create matrix
    
    //main logic
    for(int i=0;i<=n;i++){
        for(int w=0;w<=size;w++){
            if(i==0 || w==0){
                mat[i][w]=0;
            }
            else if(weight[i]<=w){
                mat[i][w]=max(profit[i]+mat[i-1][w-weight[i]],mat[i-1][w]);
            }
            else{
                mat[i][w]=mat[i-1][w];
            }
        }
    }
    cout<<mat[n][size];
}