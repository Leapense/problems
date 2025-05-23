#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    // Seed the random number generator for deterministic behavior
    srand(0);

    string jane_initial, john_initial;
    // Read initial piles until no more input
    while(getline(cin, jane_initial) && getline(cin, john_initial)){
        // Initialize 'jane' and 'john' as face-up piles
        string jane = jane_initial;
        string john = john_initial;
        int janei = 0, johni = 0;
        int turn;
        bool game_over = false;
        string winner = "";

        for(turn = 0; turn < 1000 && !game_over; turn++){
            // Check if current indices are within bounds
            if(janei >= jane.length() || johni >= john.length()){
                break;
            }

            if(jane[janei] == john[johni]){
                // Determine who calls first: 0 for Jane, 1 for John
                int caller = (rand() / 141) % 2;
                if(caller == 0){
                    // Jane calls first
                    // Print Snap! message
                    cout << "Snap! for Jane: ";
                    // Print Jane's face-up pile up to janei
                    for(int i = janei; i >=0; i--){
                        cout << jane[i];
                    }
                    cout << "\n";

                    // Insert John's pile up to johni into Jane's pile at janei +1
                    string to_insert = john.substr(0, johni +1);
                    jane.insert(janei +1, to_insert);

                    // Remove the inserted part from John's pile
                    john.erase(0, johni +1);

                    // Update janei and reset johni
                    janei += johni +2;
                    johni = 0;

                    // Print updated Jane's face-up pile up to janei -1
                    cout << "Snap! for Jane: ";
                    for(int i = janei -1; i >=0; i--){
                        cout << jane[i];
                    }
                    cout << "\n";
                }
                else{
                    // John calls first
                    // Print Snap! message
                    cout << "Snap! for John: ";
                    // Print John's face-up pile up to johni
                    for(int i = johni; i >=0; i--){
                        cout << john[i];
                    }
                    cout << "\n";

                    // Insert Jane's pile up to janei into John's pile at johni +1
                    string to_insert = jane.substr(0, janei +1);
                    john.insert(johni +1, to_insert);

                    // Remove the inserted part from Jane's pile
                    jane.erase(0, janei +1);

                    // Update johni and reset janei
                    johni += janei +2;
                    janei = 0;

                    // Print updated John's face-up pile up to johni -1
                    cout << "Snap! for John: ";
                    for(int i = johni -1; i >=0; i--){
                        cout << john[i];
                    }
                    cout << "\n";
                }
            }
            else{
                // No Snap!, move to next cards
                janei++;
                johni++;
            }

            // Reset indices if they reach the end
            if(janei >= jane.length()) janei = 0;
            if(johni >= john.length()) johni = 0;
        }

        // Determine the winner
        if(jane.empty()){
            cout << "John wins.\n";
        }
        else if(john.empty()){
            cout << "Jane wins.\n";
        }
        else{
            cout << "Keeps going and going ...\n";
        }
    }

    return 0;
}
