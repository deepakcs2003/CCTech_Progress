#include <bits/stdc++.h>
using namespace std;

struct  student
{
    string name;
    int age;
    int mark;
};

int main() {

    int c=10;
    int d=30;
    // auto greet=[c,d](double a,double b)->int{
    //     return a+b+c+d;
    // };
    //   auto greet=[=](double a,double b)->int{
    //     return a+b+c+d;
    // };
    //    auto greet=[=,&d](double a,double b)->int{
    //     d++;
    //     return a+b+c+d;
    // };

     auto greet=[d](double a,double b)mutable->int{
        d++;
        return a+b+d;
    };
    cout<<greet(3,4)<<endl;

    vector<int> v={12,4,3,1,3};
    int total=0;
    for_each(v.begin(),v.end(),[&total](int x){
        total+=x;
    });
    cout<<total<<endl;

    auto comp=[](auto a,auto b){
        return a>b;
    };
    vector<int> vi = {3, 1, 5};
    vector<double> vd = {2.2, 1.1, 4.4};
    vector<string> vs = {"cat", "apple", "dog"};

    sort(vi.begin(), vi.end(), comp);
    sort(vd.begin(), vd.end(), comp);
    sort(vs.begin(), vs.end(), comp);

    for(auto x: vi) cout << x << " ";
    cout << endl;

    for(auto x: vd) cout << x << " ";
    cout << endl;

    for(auto x: vs) cout << x << " ";
    std::function<int(int)> fact;
    fact=[&](int n){
        if(n==0){
            return 1;
        }
        return n*fact(n-1);
    };
    cout << fact(5);

    auto cmp=[](student s1,student s2){
        if(s1.mark!=s2.mark){
            return s1.mark>s2.mark;
        }else{
            return s1.name<s2.name;
        }
    };
     priority_queue<student, vector<student>, decltype(cmp)> pq(cmp);
      pq.push({"Rahul", 90, 20});
    pq.push({"Amit", 95, 22});
    pq.push({"Neha", 90, 18});
    pq.push({"Sita", 95, 19});
      while (!pq.empty()) {
        student s = pq.top();
        pq.pop();
        cout << s.name << " " << s.mark << " " << s.age << endl;
    }
    return 0;
}