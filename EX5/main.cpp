#include <iostream>
#include <string>
#include <fstream>
using namespace std;

class myString{
    private:
        string m_str;
    public:
        myString(string s){
                m_str = s;
        }
};
class ReadClass{
    public:
    void showClass(){
        while(getline(in, line)){
            if (){
            
            }
        }
    }   
};


int main(){
    ifstream in;
    string line;
    in.open("main.cpp");
    if(in.fail()){
        cout << "Erroropening a file"<<endl;
        in.close();
    }
    ReadClass rfile;
    rfile.showClass();
    in.close();

    return 0;
}
