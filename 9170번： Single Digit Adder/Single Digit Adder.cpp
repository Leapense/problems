/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 9170                              :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: cjhool <boj.kr/u/cjhool>                    +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/9170                           #+#        #+#      #+#    */
/*   Solved: 2025/02/27 22:15:40 by cjhool        ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#include <iostream>
#include <string>

using namespace std;
string s;
int pos = 0;

int parse_expr();

int parse_term()
{
    int result = 0;
    if (s[pos] == '(')
    {
        pos++;
        if (s[pos] == '+' || s[pos] == '-')
        {
            char op = s[pos++];
            int t = parse_term();
            result = (op == '-') ? -t : t;
        }
        else
        {
            result = parse_expr();
        }

        pos++;
    }
    else
    {
        result = s[pos++] - '0';
    }

    return result;
}

int parse_expr()
{
    int value = parse_term();
    while (pos < s.size() && (s[pos] == '+' || s[pos] == '-'))
    {
        char op = s[pos++];
        int termVal = parse_term();
        if (op == '+')
            value += termVal;
        else
            value -= termVal;
    }

    return value;
}

int main()
{
    while (getline(cin, s))
    {
        pos = 0;
        cout << parse_expr() << "\n";
    }

    return 0;
}