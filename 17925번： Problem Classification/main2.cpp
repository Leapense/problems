#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std;

// The solution function reads from an input stream and writes to an output stream.
void solve(istream &in, ostream &out)
{
    ios::sync_with_stdio(false);
    in.tie(nullptr);

    int N;
    in >> N;

    // Structures to hold category details.
    vector<string> categories(N);
    vector<int> counts(N, 0);

    // Map each keyword to the list of category indices it belongs to.
    unordered_map<string, vector<int>> keywordToCategory;

    // Read each category and its associated keywords.
    for (int i = 0; i < N; i++)
    {
        string catName;
        int W;
        in >> catName >> W;
        categories[i] = catName;
        for (int j = 0; j < W; j++)
        {
            string keyword;
            in >> keyword;
            keywordToCategory[keyword].push_back(i);
        }
    }

    // Process the rest of the input (the problem statement)
    string word;
    while (in >> word)
    {
        // If the word is found in our map, update counts for all relevant categories.
        if (keywordToCategory.count(word))
        {
            for (int idx : keywordToCategory[word])
            {
                counts[idx]++;
            }
        }
    }

    // Determine the maximum count achieved.
    int maxCount = 0;
    for (int count : counts)
    {
        maxCount = max(maxCount, count);
    }

    // Gather categories with the maximum count.
    vector<string> result;
    for (int i = 0; i < N; i++)
    {
        if (counts[i] == maxCount)
        {
            result.push_back(categories[i]);
        }
    }

    // Sort the results in lexicographical order and output.
    sort(result.begin(), result.end());
    for (const string &cat : result)
    {
        out << cat << "\n";
    }
}

// Testing harness code.
int main()
{
    // Each test case is a pair of strings: {input, expected_output}.
    vector<pair<string, string>> testCases = {
        // Test Case 1: Minimum Input
        {
            R"(1
math 1 add
add
)",
            R"(math
)"},
        // Test Case 2: Sample Input 1 (from the problem statement)
        {
            R"(4
datastructure 3 query range sum
geometry 3 euclid range vertex
graph 3 query vertex hamiltonian
math 3 hamiltonian sum euclid
consider the hamiltonian graph where each vertex corresponds
to an linear equation we can solve these using the euclid
algorithm now you will receive a query corresponding to a
range of vertices your task is to compute the sum of the
minimum solution of those vertices
)",
            R"(datastructure
geometry
graph
math
)"},
        // Test Case 3: Sample Input 2 (from the problem statement)
        {
            R"(2
graph 2 vertex edge
string 2 words letters
problem classification
when reading programming problems one can often get some
hints regarding the topic of the problem by skimming the
problem statement for certain words if for example the
word vertex or edge appears the problem is almost
certainly a graph problem while the words words or
letters suggest that the problem is about strings your
task is to implement a simple program that attempts to
classify a problem according to one of n categories each
category has an associated set of words which if they
appear as words in a statement suggest the problem
belongs to this category when classifying a statement
the program should suggest those categories which have
the highest number of occurences of their associated
words in the above example we suggested that the
category graph may have the associated words vertex
and edge and the category string could have the
associated words words and letters then if there were
occurances each of the words vertex and edge the number
of matches for the category graph would be if the
statement contained occurances of words and of letters
the number of matches for the category string would be 
since there are more matches for the second category
the program should suggest it if there are multiple
categories with the same number of matches your
program should suggest all of them
input
the first line of input contains the number of categories
n the next n lines each contain a description of a
category the description starts with the name of the
category a single word then an integer w follows 
the number of words associated with this category this
is followed by those w words separated by spaces this
is followed by a number of lines describing the
statement of the problem each line contains a list of
spaceseparated words every word in the input will
consist solely of lowercase letters a z output for each
suggested category output the name of the category on a
single line in lexicographical order
)",
            R"(string
)"},
        // Test Case 4: No Keywords Found
        {
            R"(3
algebra 2 add subtract
geometry 2 point line
calculus 2 derive integrate
this statement contains none of the keywords we are looking for
and hence no category has any matching words
)",
            R"(algebra
calculus
geometry
)"},
        // Test Case 5: Mixed Frequencies with Ties
        {
            R"(3
binary 2 bit byte
decimal 2 digit number
hexadecimal 2 digit hex
bit bit byte digit hex digit digit
)",
            R"(hexadecimal
)"}};

    int testNum = 0;
    int passed = 0;
    for (const auto &[inputStr, expectedOutput] : testCases)
    {
        testNum++;
        istringstream iss(inputStr);
        ostringstream oss;
        solve(iss, oss);
        string output = oss.str();
        if (output == expectedOutput)
        {
            cout << "Test case " << testNum << " passed.\n";
            passed++;
        }
        else
        {
            cout << "Test case " << testNum << " failed.\n";
            cout << "Input:\n"
                 << inputStr << "\n";
            cout << "Expected Output:\n"
                 << expectedOutput << "\n";
            cout << "Your Output:\n"
                 << output << "\n";
        }
    }
    cout << passed << " out of " << testCases.size() << " test cases passed.\n";
    return 0;
}
