#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
using namespace std;

int main(){
    int S;
    cin >> S;
    cin.ignore(); // Ignore the newline after the number
    for(int scenario=1; scenario<=S; scenario++){
        string line;
        getline(cin, line);
        // Split the line into names
        vector<string> names;
        string name;
        for(char c : line){
            if(c == ' ') {
                if(!name.empty()){
                    names.push_back(name);
                    name = "";
                }
            }
            else{
                name += c;
            }
        }
        if(!name.empty()) names.push_back(name);
        // Set presence flags
        bool hasAnne=false, hasBob=false, hasKarin=false, hasDave=false, hasCharly=false, hasEdward=false, hasFrank=false;
        for(auto &n : names){
            if(n == "Anne") hasAnne=true;
            else if(n == "Bob") hasBob=true;
            else if(n == "Karin") hasKarin=true;
            else if(n == "Dave") hasDave=true;
            else if(n == "Charly") hasCharly=true;
            else if(n == "Edward") hasEdward=true;
            else if(n == "Frank") hasFrank=true;
        }
        // Initialize vote counts
        map<string, int> voteCount;
        voteCount["cinema"]=0;
        voteCount["cocktail bar"]=0;
        voteCount["disco"]=0;
        // Process each friend
        for(auto &n : names){
            if(n == "Anne"){
                // Rule 1
                voteCount["cinema"]++;
            }
            else if(n == "Bob"){
                // Determine possible votes
                set<string> votes;
                // Rule 2
                if(hasKarin){
                    votes.insert("disco");
                }
                // Rule 5
                if(hasDave){
                    votes.insert("cocktail bar");
                }
                // Rule 8
                if(hasEdward){
                    votes.insert("cocktail bar");
                }
                // Rule 10
                if(!hasAnne){
                    votes.insert("cocktail bar");
                }
                // Check if votes are consistent
                if(votes.size()==1){
                    voteCount[*votes.begin()]++;
                }
                // Else abstain
            }
            else if(n == "Karin"){
                // Rule 3
                if(hasCharly){
                    voteCount["disco"]++;
                }
                else if(hasAnne){
                    voteCount["cinema"]++;
                }
                else{
                    voteCount["cocktail bar"]++;
                }
            }
            else if(n == "Dave"){
                // Rule 4: never votes
                continue;
            }
            else if(n == "Charly"){
                // Rule 6
                if(hasAnne){
                    voteCount["cinema"]++;
                }
                // Else no rule
            }
            else if(n == "Edward"){
                // Rule 7
                if(hasAnne && !hasCharly){
                    voteCount["cocktail bar"]++;
                }
                else{
                    voteCount["cinema"]++;
                }
            }
            else if(n == "Frank"){
                // Rule 9
                if(!hasBob && !hasAnne){
                    voteCount["cinema"]++;
                }
                if(hasAnne){
                    voteCount["disco"]++;
                }
                // If both conditions apply and lead to different votes, abstain
                if((!hasBob && !hasAnne) && hasAnne){
                    // Votes for cinema and disco
                    // Different votes, so abstain
                    voteCount["cinema"]--;
                    voteCount["disco"]--;
                }
            }
        }
        // Determine the result
        string result;
        // Find the maximum vote
        int maxVotes = max(voteCount["cinema"], max(voteCount["cocktail bar"], voteCount["disco"]));
        // Count how many have the maxVotes
        int cnt=0;
        string place;
        for(auto &p : voteCount){
            if(p.second == maxVotes){
                cnt++;
                place = p.first;
            }
        }
        if(cnt ==1){
            result = place;
        }
        else{
            result = "stay at the Hacienda";
        }
        // Output
        cout << "Scenario #" << scenario << ":\n" << result << "\n\n";
    }
}