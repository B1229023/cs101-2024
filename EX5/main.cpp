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
        ifstream file("main.cpp");
        string Classname[20];
        int n =0;
        int Class_num = 0;
        int m = 0;
        if(file.is_open()){
            char c;
            char s[6] = "class";
            while(file.get(c)){
                if(m == 1){
                    if (c=='{'){
                        m==0;
                    }else if (c != '"'){
                        Classname[Class_num-1]+=c;
                    }else{
                        Class_num --;
                        m=0;
                    }
                }
                if (s[n]==c){
                    n++;
                }else{
                    n=0;
                }
                if(n==4){
                    Class_num ++;
                    m=1;
                    n=0;
                }
            }
        }else {
            cout << "unable open"<<endl;
        }
        cout <<Class_num<<"class in main.cpp\n";
        for (int i =0;i<Class_num;i++){
            cout <<"clas"<<Classname[i]<<endl;
        }
    }   
};


int main(){
    ReadClass rfile;
    rfile.showClass();


    return 0;
}
