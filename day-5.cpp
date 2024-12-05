#include <bits/stdc++.h>
using namespace std;

int main() {
	 string line;
    vector<string> set1, set2;
    vector<string>* currentSet = &set1; // Start with set1
    unordered_set<string> st;

    while (getline(cin, line)) {
        // If a blank line is encountered, switch to the second set
        if (line.empty()) {
            currentSet = &set2;
            continue;
        }

        // Add the line to the current set
        currentSet->push_back(line);
        st.insert(line);
    }

    // Output the sets to verify
    // cout << "Set 1:\n";
    // for (const string& str : set1) {
    //     // cout << str << "\n";
    // }

    // cout << "\nSet 2:\n";
    vector<vector<int>> curr;
    for (const string& str : set2) {
        // cout << str << "\n";
        int currNumber=0;
        vector<int> temp;
        for(int i=0;i<str.size();i++){
            if(str[i]!=','){
                currNumber = currNumber*10 + (str[i]-'0');
            }
            else{
                temp.push_back(currNumber);
                // cout<<currNumber<<" ";
                currNumber=0;
            }
            if(i==str.size()-1) temp.push_back(currNumber);
        }
        // cout<<"\n";
        // temp.push_back(currNumber); //for the last number
        // for(int i=0;i<temp.size();i++) cout<<temp[i]<<" ";
        // cout<<"\n";
        curr.push_back(temp);
    }
    
    int result =0;
    vector<int> wrongIdx;
    for(int k=0;k<curr.size();k++){
        bool valid=true;
        vector<int> temp = curr[k];
        int n = temp.size();
        for(int i=n-1;i>0;i--){
            for(int j=i-1;j>=0;j--){
                string check = string() + to_string(temp[i]) + "|" +  to_string(temp[j]);
                if(st.find(check) != st.end()){
                    valid = false;
                    wrongIdx.push_back(k);
                    break;
                }
            }
        }
        
        if(valid){
            // cout<<k<<"\n";
            //finding middle.
            int middle = n/2;
            result += temp[middle];
        }
    }


// cout<<"result: "<<result<<"\n";

// cout<<"wrong size "<<wrongIdx.size()<<"\n";
// for(int i=0;i<wrongIdx.size();i++) cout<<wrongIdx[i]<<" ";

unordered_set<int> wrong;
for(int i=0;i<wrongIdx.size();i++){
    if(wrong.find(wrongIdx[i]) == wrong.end()) wrong.insert(wrongIdx[i]);
}

cout<<"over\n";

//for part-2
int result_part2=0;
for(auto val: wrong){
    // if(wrongIdx[k] == wrongIdx[k-1]) break;
    vector<int> temp = curr[val];
    //wrongly mapped vector.
    int n = temp.size();
    for(int i=n-1;i>0;i--){
        for(int j=i-1;j>=0;j--){
            string check = string() + to_string(temp[i]) + "|" +  to_string(temp[j]);
            if(st.find(check) != st.end()){
                //interchange the two numbers.
                int fir = temp[i];
                temp[i] = temp[j];
                temp[j] = fir;
                // valid = false;
                // wrongIdx.push_back(k);
                // break; doing for all iterasions
            }
        }
    }
    
    
    // cout<<"at idx "<<wrongIdx[k]<<"\n";
    
    //after interhanging finding resultl
    int middle = n/2;
    cout<<"temp's value for odx is "<<temp[middle]<<"\n";
    result_part2 += temp[middle];
    // cout<<"each item changed to ";
    // for(int i=0;i<temp.size();i++){
    //     cout<<temp[i]<<" ";
    // }
    // cout<<"\n";
}

    cout<<"result part2 is "<<result_part2<<"\n";

    return 0;
}
