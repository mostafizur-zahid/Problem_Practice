#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int m;
        cin>>m;
        int array[m];
        for(int j=0;j<m;j++){
            cin>>array[j];
        }
        int max = array[0];
        for(int k=0;k<m;k++){
            if(max<array[k])
            max=array[k];
        }
        cout<<"Case "<<i+1<<": "<<max<<endl;
    }

}