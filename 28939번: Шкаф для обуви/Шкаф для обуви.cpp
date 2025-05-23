#include <iostream>
#include <vector>

using namespace std;

int main()
{
    
    int n;
    cin >> n;
    
    int k, m1, m2;
    cin >> k >> m1 >> m2;

    int invalid_shoes_count = 0;

    for (int i = 0; i < n; ++i) {
        
        int h_i, k_i;
        cin >> h_i >> k_i;

        vector<int> sizes(k_i);

        for (int j = 0; j < k_i; ++j) {

            cin >> sizes[j];
        
        }

        for (int size : sizes) {
        
            double min_height = static_cast<double>(size) * m2;
            double max_height = static_cast<double>(size) * m1;
        
            if (!(min_height / k <= h_i && h_i <= max_height)) {
                
                invalid_shoes_count++;

            }

        }

    }

    cout << invalid_shoes_count << endl;

    return 0;

}