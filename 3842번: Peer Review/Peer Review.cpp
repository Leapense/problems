#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    while(true){
        int K, N;
        cin >> K >> N;
        if(K == 0 && N == 0){
            break;
        }
        
        // Use 1-based indexing
        vector<string> authors_institution(N+1);
        // To store reviewers for each paper
        vector<vector<int>> reviewers_of_paper(N+1, vector<int>());
        
        for(int i=1; i<=N; i++){
            string institution;
            cin >> institution;
            authors_institution[i] = institution;
            for(int j=0; j<K; j++){
                int p;
                cin >> p;
                if(p >=1 && p <= N){
                    reviewers_of_paper[p].push_back(i);
                }
                // If p is out of range, it's unclear from the problem statement.
                // Assuming p is always valid as per problem constraints.
            }
        }
        
        int problems = 0;
        for(int p=1; p<=N; p++){
            bool violation = false;
            // 1. Check number of reviewers
            if((int)reviewers_of_paper[p].size() != K){
                violation = true;
            }
            
            // 2. Check if any reviewer is from the same institution
            if(!violation){
                string paper_institution = authors_institution[p];
                for(auto &rev: reviewers_of_paper[p]){
                    if(authors_institution[rev] == paper_institution){
                        violation = true;
                        break;
                    }
                }
            }
            
            // 3. Check for duplicate reviewers
            if(!violation){
                // Since K is small (<=5), we can use a set
                unordered_set<int> unique_reviewers;
                bool duplicate = false;
                for(auto &rev: reviewers_of_paper[p]){
                    if(unique_reviewers.find(rev) != unique_reviewers.end()){
                        duplicate = true;
                        break;
                    }
                    unique_reviewers.insert(rev);
                }
                if(duplicate){
                    violation = true;
                }
            }
            
            if(violation){
                problems++;
            }
        }
        
        if(problems == 0){
            cout << "NO PROBLEMS FOUND\n";
        }
        else if(problems == 1){
            cout << "1 PROBLEM FOUND\n";
        }
        else{
            cout << problems << " PROBLEMS FOUND\n";
        }
    }
}