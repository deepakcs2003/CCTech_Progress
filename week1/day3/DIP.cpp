#include <bits/stdc++.h>
using namespace std;


class IVersionControl{
    public:
    virtual void commit(const string& message)=0;
    virtual void push()=0;
    virtual void pull()=0;
};
class GitVersionControl:public IVersionControl{
    public:
    void commit(const string& message) override{
        cout<<"Commit in git"<<message<<endl;
    }
      
    void push() override {
        cout << "Pushing to Git repository" << endl;
    }
    
    void pull() override {
        cout << "Pulling from Git repository" << endl;
    }

};
class DevlopmentItems{
    private:
    IVersionControl* versionControl;
    public:
      DevlopmentItems(IVersionControl* vc) : versionControl(vc) {}
    
    void makeCommit(const string& message) {
        versionControl->commit(message);
    }
    
    void performPush() {
        versionControl->push();
    }
    
    void performPull() {
        versionControl->pull();
    }
};
int main() {

    GitVersionControl git;
    DevlopmentItems team(&git);  // Inject dependency
    
    team.makeCommit("Initial commit");
    team.performPush();
    

    return 0;
}