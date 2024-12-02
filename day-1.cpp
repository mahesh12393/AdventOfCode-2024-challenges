#include <bits/stdc++.h>
using namespace std;

int main() {
    string line;
    int num1, num2;
    vector<int> first,second;
    int sz =0 ;

    cout << "Enter two numbers: ";
    while(getline(cin,line) && !line.empty()){
        sz++;
    stringstream ss(line);
    ss >> num1 >> num2;
    first.push_back(num1);
    second.push_back(num2);
}

// for validation
cout<<sz<<"\n";

cout<<"vec size "<<first.size()<<"\n";

int output = 0;
sort(first.begin(),first.end());
sort(second.begin(),second.end());
for(int i=0;i<first.size();i++){
    output += abs(first[i] - second[i]);
}

unordered_map<int,int> mp;
for(int i=0;i<second.size();i++){
    mp[second[i]]++;
}

long long result = 0;

for(int i=0;i<first.size();i++){
    int val = 0;
    if(mp.find(first[i]) != mp.end()) val = mp[first[i]];
    result += (long long)(first[i] * val);
}

cout<<result;
    return 0;
}