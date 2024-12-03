#include <bits/stdc++.h>
using namespace std;

int result = 0;

unordered_set<int> donotSt,doSt;


//a better optimization can be using binary search here..
bool findClosest(int idx){ //if do is near true to do it.
    for(int i=idx;i>=0;i--){
        if(donotSt.find(i) != donotSt.end()) {
            // cout<<"found at "<<i<<"\n";
            return 0;
        }
        else if(doSt.find(i) != doSt.end()) return 1;
    }
    return 1; //nothing founf till 0 edge case if its just strating
}


void validate(string &str, int idx){
    int start = idx+4; //for the numbers.
    int n = str.size();
    string first = "",second="";
    bool comma=false;
    bool closeBracket=false;
    bool failed = false;
    for(int i=start;i<n;i++){
        if(str[i] == ')'){
            closeBracket = true;
            break;
        }
        //to validate for numbers open brackets and commas.
        else if(str[i] >='0' && str[i]<='9'){
            // a number.
            if(comma){
                second += str[i];
            }
            else first += str[i];
        }
        else if(str[i] == ','){
            comma = true;
        }
        else {
            //anything other than these.
            failed = true;
            break;
        }
    }
    
    if(!failed && comma && closeBracket){
        // cout<<first <<" "<<second<<"\n";
        // cout<<first.size()<<" "<<second.size()<<"\n";
        if(findClosest(idx)) result += stoi(first) * stoi(second);
        //findClosest is the validation for part-2. (100411201)
        //normal multiplication is the part-1. (174103751)
    }
}


int main() {
	// your code goes here
    string str;
    // cin>>str;
    string line;
    // cout<<"size is "<<str.size()<<"\n";
    string sub="mul("; // str is string to search, sub is the substring to search 
    string donotIdx = "don't()";
    string doIdx = "do()";
    
    while(getline(cin,line) && !line.empty()){
        str += line;
        // cout<<line<<"\n";
        // cout<<line.size()<<"\n";
    }
    
    // cout<<str.size();
    // int n = str.size();
    // cout<<str[0]<<" "<<str[n-1]<<str[n-2]<<str[n-3]<<"\n";
    
     
    size_t pos1 = str.find(donotIdx, 0);
    while(pos1 != string::npos)
    {
        donotSt.insert(pos1);
        // cout<<pos<<"\n";
        // validate(str,pos);
        pos1 = str.find(donotIdx,pos1+1);
    }
    
    size_t pos2 = str.find(doIdx, 0);
    while(pos2 != string::npos)
    {
        doSt.insert(pos2);
        // cout<<pos<<"\n";
        // validate(str,pos);
        pos2 = str.find(doIdx,pos2+1);
    }
    
    


    size_t pos = str.find(sub, 0);
    while(pos != string::npos)
    {
        // cout<<pos<<"\n";
        validate(str,pos);
        pos = str.find(sub,pos+1);
    }
   
    cout<<result<<"\n";
    
}
