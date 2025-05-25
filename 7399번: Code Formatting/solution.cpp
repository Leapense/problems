#include <cctype>
#include <iostream>
#include <iterator>
#include <string>
#include <string_view>
#include <vector>

namespace
{

    auto tokenize(const std::string &src) -> std::vector<std::string>
    {
        std::vector<std::string> tokens;
        const std::size_t n = src.size();

        for (std::size_t i = 0; i < n;)
        {
            const char ch = src[i];

            if (std::isspace(static_cast<unsigned char>(ch)) != 0)
            {
                ++i;
                continue;
            }

            if (std::isalnum(static_cast<unsigned char>(ch)) != 0)
            {
                std::size_t j = i;
                while (j < n && std::isalnum(static_cast<unsigned char>(src[j])) != 0)
                {
                    ++j;
                }

                tokens.emplace_back(src.substr(i, j - i));
                i = j;
                continue;
            }

            tokens.emplace_back(src.substr(i, 1));
            ++i;
        }

        return tokens;
    }

    void flushLine(std::string &lineBuf, int indent, std::vector<std::string> &lines)
    {
        if (lineBuf.empty())
        {
            return;
        }

        lines.emplace_back(std::string(static_cast<std::size_t>(indent) * 4U, ' ') + lineBuf);
        lineBuf.clear();
    }

}

auto main() -> int
{
    const std::string input((std::istreambuf_iterator<char>(std::cin)), std::istreambuf_iterator<char>());

    const std::vector<std::string> tokens = tokenize(input);

    std::vector<std::string> lines;
    std::string lineBuf;

    int indent = 0;
    for (std::size_t idx = 0; idx < tokens.size(); ++idx)
    {
        const std::string_view tok = tokens[idx];

        switch (tok.front())
        {
        case '{':
            if (!lineBuf.empty())
            {
                lineBuf.push_back(' ');
            }
            lineBuf.push_back('{');
            flushLine(lineBuf, indent, lines);
            ++indent;
            break;

        case '}':
            flushLine(lineBuf, indent, lines);
            --indent;
            lineBuf.push_back('}');
            break;

        case ';':
            lineBuf.push_back(';');
            flushLine(lineBuf, indent, lines);
            break;

        case ',':
            lineBuf.push_back(',');
            lineBuf.push_back(' ');
            break;

        default: // identifier, '(', ')'
            lineBuf.append(tok);
            break;
        }
    }

    flushLine(lineBuf, indent, lines);

    for (std::size_t i = 0; i < lines.size(); ++i)
    {
        std::cout << lines[i];
        if (i + 1 < lines.size())
        {
            std::cout << "\n";
        }
    }

    return 0;
}