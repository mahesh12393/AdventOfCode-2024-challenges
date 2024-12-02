#include <bits/stdc++.h>
using namespace std;

int checkSafe(vector<int> &curr){
        int n = curr.size();
        // cout<<"inside hgere "<<n<<"\n";
        // for(int i=0;i<n;i++) cout<<curr[i]<<" ";
        // cout<<"\n";
        bool increasing=false;
        if(curr[0] < curr[1]) increasing = true;
        for(int i=1;i<n-1;i++){
            //first rule of increasing and decreasing.
            if(increasing){
                if(curr[i] >= curr[i+1]){
                    //fails the condition.
                    return false;
                }
            }
            else {
                if(curr[i] <= curr[i+1]){
                //fails the condition.
                    return false;
                }
            }
        }
        // cout<<"httung ruke 2"<<"\n";
        //rule 2 validation.
        for(int i=0;i<n-1;i++){
            int adjDiff = abs(curr[i] - curr[i+1]);
            if(adjDiff < 1 || adjDiff >3) return false;
        }
        
        // cout<<"yoyo"<< curr[0] <<" "<<n<<"\n";
        return true;
}


int main() {
    string line;
    int safeCount = 0;
    int sz=0;
    while(getline(cin,line) && !line.empty()){
        stringstream ss(line);
        vector<int> curr;
        int num;
        while(ss>>num){
            curr.push_back(num);
        }
        
        if(checkSafe(curr)) safeCount ++;
        else{
            //for part2.
            int n = curr.size();
            for(int i=0;i<n;i++){
                vector<int> reducedCurr = curr;
                reducedCurr.erase(reducedCurr.begin() + i);
                if(checkSafe(reducedCurr)){
                    safeCount++;
                    break; //no need to check other iterasions
                }
            }
        }
    }
    cout << safeCount << endl;
    return 0;
}