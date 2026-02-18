#include <bits/stdc++.h>
using namespace std;

class Complex{
    private:
    int real,imaginary;
    public:
    Complex(int r,int i):real(r),imaginary(i){};
    friend ostream& operator<<(ostream &out,const Complex& c){
        out<<c.real<<"+"<<c.imaginary<<"i"<<endl;
    }
};
int main() {

    Complex c(3,4);
    cout<<c;
    // text format
    // ofstream fout("data.txt");
    // int num=786;
    // char ch='a';
    // fout<<num<<" "<<ch;

    // binary format
    // ofstream fout("data.bin",ios::binary);
    // int num=789;
    // char ch='A';
    // fout.write((char*)&num,sizeof(num));
    // fout.write(&ch,sizeof(ch));


    // fstream file("data.txt",ios::in|ios::out);
    // file.seekp(0,ios::end);
    // file<<"\nnew line";
    // file.seekg(0,ios::beg);
    // string line;
    // while (getline(file,line))
    // {
    //     cout<<line<<endl;
    // }

    // file.close();

    ifstream file("data.txt");
    string s;
    getline(file,s);
    cout<<"read string :"<<s<<endl;
    file.close();

    cout << "Hello"<<endl;
    cerr << "Error!"<<endl;
    clog << "Log message"<<endl;
    return 0;
}