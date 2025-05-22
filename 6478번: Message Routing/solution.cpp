#include <iostream>
#include <sstream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

namespace
{

    /* ---------- Domain types ---------- */
    struct OrName
    {
        std::string c, admd, prmd, org;
        [[nodiscard]] bool matches(const OrName &pat) const noexcept
        {
            auto ok = [](const std::string &p, const std::string &v)
            {
                return p == "*" || p == v;
            };
            return ok(pat.c, c) && ok(pat.admd, admd) &&
                   ok(pat.prmd, prmd) && ok(pat.org, org);
        }
    };

    struct Route
    {
        std::string next;
        OrName pat;
    };
    struct Mta
    {
        std::string name;
        std::vector<Route> tbl;
    };

    /* ---------- Parsing helpers (token-based) ---------- */
    [[nodiscard]] Mta readMta(std::istream &in)
    {
        std::string line;
        while (std::getline(in, line) && line.empty())
            ; // skip blank

        std::istringstream hdr(line);
        Mta mta;
        int routeCnt{};
        hdr >> mta.name >> routeCnt;

        mta.tbl.reserve(routeCnt);
        for (int i = 0; i < routeCnt; ++i)
        {
            std::getline(in, line);
            if (line.empty())
            {
                --i;
                continue;
            } // safety
            std::istringstream iss(line);
            Route r;
            iss >> r.next >> r.pat.c >> r.pat.admd >> r.pat.prmd >> r.pat.org;
            mta.tbl.push_back(std::move(r));
        }
        return mta;
    }

    [[nodiscard]] std::pair<std::string, OrName>
    readMessageLine(const std::string &line)
    {
        std::istringstream iss(line);
        std::pair<std::string, OrName> msg;
        iss >> msg.first >> msg.second.c >> msg.second.admd >> msg.second.prmd >> msg.second.org;
        return msg;
    }

    /* ---------- Simulation ---------- */
    void deliver(int idx,
                 const std::string &start,
                 const OrName &dest,
                 const std::unordered_map<std::string, Mta> &mp)
    {
        const Mta *cur = &mp.at(start);
        std::unordered_set<std::string> seen;

        while (true)
        {
            if (!seen.insert(cur->name).second)
            {
                std::cout << idx << " -- circular routing detected by "
                          << cur->name << '\n';
                return;
            }

            const Route *use = nullptr;
            for (const auto &r : cur->tbl)
                if (dest.matches(r.pat))
                {
                    use = &r;
                    break;
                }

            if (!use)
            {
                std::cout << idx << " -- unable to route at "
                          << cur->name << '\n';
                return;
            }
            if (use->next == cur->name)
            {
                std::cout << idx << " -- delivered to "
                          << cur->name << '\n';
                return;
            }
            cur = &mp.at(use->next); // hop
        }
    }

} // -- unnamed namespace

/* ================================================== */
int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int scenNo = 0;
    for (int mtaCnt; (std::cin >> mtaCnt);)
    {
        ++scenNo;
        std::string dummy;
        std::getline(std::cin, dummy); // newline

        std::unordered_map<std::string, Mta> mtaMap;
        mtaMap.reserve(mtaCnt * 2);

        for (int i = 0; i < mtaCnt; ++i)
        {
            Mta m = readMta(std::cin);
            mtaMap.emplace(m.name, std::move(m));
        }

        int msgCnt;
        std::cin >> msgCnt;
        std::getline(std::cin, dummy); // newline

        std::vector<std::pair<std::string, OrName>> msgs;
        msgs.reserve(msgCnt);
        for (int i = 0; i < msgCnt; ++i)
        {
            std::string line;
            std::getline(std::cin, line);
            msgs.push_back(readMessageLine(line));
        }

        std::cout << "Scenario # " << scenNo << '\n';
        for (int i = 0; i < msgCnt; ++i)
            deliver(i + 1, msgs[i].first, msgs[i].second, mtaMap);
        std::cout << '\n';
    }
}