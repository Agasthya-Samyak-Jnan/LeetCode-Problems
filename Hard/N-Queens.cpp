#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/n-queens/
// Difficulty : Hard


/* THE N-QUEENS PROBLEM USING  ! ! !  B A C K T R A C K I N G  ! ! ! */
class Solution {
    public:
    vector<vector<string>> ans;
    vector<int> col,dia,a_dia;
    int n;

    void mark_and_place (vector<string>& temp, int i, int j) {
        col[j] = 1;
        dia[i+j] = 1;
        a_dia[i-j+(n-1)] = 1;
        temp[i][j] = 'Q';
    }
    
    void unmark_and_remove (vector<string>& temp, int i, int j) {
        col[j] = 0;
        dia[i+j] = 0;
        a_dia[i-j+(n-1)] = 0;
        temp[i][j] = '.';
    }

    void solve (vector<string>& temp, int i) {

        if (i==n) { 
            ans.push_back(temp);
            return; 
        }

        for (int j=0;j<n;j++) {
            if (col[j] == 0 && dia[i+j] == 0 && a_dia[i-j+(n-1)] == 0) {
                mark_and_place(temp,i,j);
                solve(temp,i+1);
                unmark_and_remove(temp,i,j);
            }
        }

    }

    vector<vector<string>> n_queens(int n) {

        this->n = n;
        col = vector<int>(n,0);
        a_dia = dia = vector<int>(2*n-1,0);
        vector<string> temp (n,string(n,'.'));

        solve(temp,0);

        return ans;
    }

};

int main () {
    
    int n;
    cin>>n;
    Solution* a = new Solution ();

    vector<vector<string>> ans = a->n_queens(n);

    for (auto i : ans) {
        for (auto j : i) {
            cout<<j<<"\n";
        }
        cout<<"\n";
    }

    return 0;
}