#include <bits/stdc++.h>
using namespace std;

int result_count = 0;
void count_occurences(vector<vector<char>> &vec,int i, int j, int row, int col, string word,int idx,int dirX,int dirY) {
        if(i<0 || i>=row || j>=col || j<0 || word[idx]!=vec[i][j]) return;
        
        if(idx == word.size()-1){
            result_count++;
            return;
        }
        count_occurences(vec,i+dirX,j+dirY,row,col,word,idx+1,dirX,dirY);
}


bool checkIfMas(vector<vector<char>> &vec, int i, int j, int row, int col) {
    // Validate that the current cell is not on the boundary or corners
    if (i - 1 < 0 || i + 1 >= row || j - 1 < 0 || j + 1 >= col) {
        return false;
    }

    //got to know No need got validate + only need to validate x mfff smth
    string adj_plus = std::string() +  vec[i-1][j-1] + vec[i][j] + vec[i+1][j+1] + vec[i-1][j+1] + vec[i][j] + vec[i+1][j-1];
    
    if(adj_plus=="MASMAS" || adj_plus=="SAMSAM" || adj_plus=="SAMMAS" || adj_plus=="MASSAM") return true;
    // If none of the conditions match, return false
    return false;
}


int main() {
	// your code goes here
    string str;
    // cin>>str;
    string line;
    vector<vector<char>> vec(150,vector<char>(150));

    int row = 0;
    while(getline(cin,line) && !line.empty()){
        str += line;
        for(int i=0;i<line.size();i++){
            char ch = line[i];
            vec[row][i] = ch;
        }
        row++;
    }
    
    string curr="";
    int row_sz = vec.size();
    int col_sz = vec[0].size();
    
    int dx[] = {1,0,1,-1,-1,0,1,-1};
    int dy[] = {0,1,1,-1,0,-1,-1,1};
    
    //searching for XMAS .
    string word="XMAS";
    for(int i=0;i<row_sz;i++){
        for(int j=0;j<col_sz;j++){
            for(int k=0;k<8;k++){
                count_occurences(vec,i,j,row_sz,col_sz,word,0,dx[k],dy[k]);
            }
        }
    }
    
    
    int mascount=0;
    //for part-2;
    for(int i=0;i<row_sz;i++){
        for(int j=0;j<col_sz;j++){
            if(vec[i][j] == 'A'){
                if(checkIfMas(vec,i,j,row_sz,col_sz)) mascount++;
            }
        }
    }
    
    //part-1
    cout<<"result_count"<< result_count<<"\n";
    
    //part-2
    cout<<"mas count is "<<mascount<<"\n";
    
    
}

