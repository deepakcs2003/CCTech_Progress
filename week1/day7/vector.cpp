#include <bits/stdc++.h>
using namespace std;

int main() {

    vector<int> v={1,2,3,4};
    v.push_back(1);
    v.insert(v.begin()+1,4);

    cout<<v[0]<<endl;
    v[0]=10;
    cout<<v[0]<<endl;
    cout << v.at(2)<<endl;
    cout<<v.size()<<endl;
    v.pop_back();
      for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;
    v.erase(v.begin()+2);
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;
    cout<<v.empty()<<endl;
    vector<vector<int>> matrix(3,vector<int>(4,4));
    for(int i=0;i<matrix.size();i++){
        for(int j=0;j<matrix[i].size();j++){
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}