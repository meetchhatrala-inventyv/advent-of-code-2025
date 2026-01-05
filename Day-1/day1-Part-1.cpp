// Online C++ compiler to run C++ program online
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

int main() {
    int num;
    cin>>num;
    
    // int r;
    // cin>>r;

    ifstream file("moves.txt");  

    if (!file.is_open()) {
        cout << "Error opening file!" << endl;
        return 1;
    }

    vector<string> str;   
    string temp;

    
    while (file >> temp) {
        str.push_back(temp);
    }

    file.close();
    int count=0;
    for(int i=0;i<str.size();i++)
    {
        int n = stoi(str[i].substr(1))%100;
        
        if(str[i][0]=='L')
        {
            int t=num-n;
            if(t<0)
            {
                num=100+t;
            }else
            {
                num=t;
            }
        }else if(str[i][0]=='R')
        {
            int t=num+n;
            if(t>99)
            {
                num=t-100;
            }else
            {
                num=t;
            }
        }
        
        if(num==0)
        {
            count++;
        }
    }
    
    cout<<count;

    

    return 0;
}
// L6850
// L30
// R48
// L5
// R60
// L55
// L1
// L99
// R14
// L82