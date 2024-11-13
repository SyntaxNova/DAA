#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

struct Item{
    int profit;
    int weight;
    double profitByweight;
};
bool comparator(const Item& a,const Item& b){
    return a.profitByweight > b.profitByweight;
}
double fractionalKnap(vector<Item>& items,int size){
    sort(items.begin(),items.end(),comparator);
    double final_profit=0;
    int weight=0;
    for(const auto& item:items){
        if(weight+item.weight <= size){
            final_profit+=item.profit;
            weight+=item.weight;
        }
        else{
            double remain=size-item.weight;
            final_profit+=item.profitByweight*remain;
            break;
        }
    }
    return final_profit;

}

int main(){
    int n;
    cout<<"Enter the number of objects"<<" ";
    cin>>n;
    cout<<"Enter size of the sack"<<" ";
    int size;
    cin>>size;
    vector<Item>items(n);
    cout<<"Enter Profit"<<" "<<"Weight"<<endl;
    for(int i=0;i<n;i++){
        cin>>items[i].profit>>items[i].weight;
        items[i].profitByweight=double(items[i].profit)/items[i].weight;
    }
    double max_profit=fractionalKnap(items,size);
    cout<<max_profit;

}