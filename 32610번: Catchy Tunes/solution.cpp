#include <bits/stdc++.h>
using namespace std;

struct ArtistBucket
{
    string name;
    vector<string> songs;
};

vector<string> arrange_playlist(const vector<pair<string, string>> &input)
{
    unordered_map<string, size_t> id_of;
    vector<ArtistBucket> buckets;
    buckets.reserve(input.size());

    auto get_id = [&](const string &artist) -> size_t
    {
        auto it = id_of.find(artist);
        if (it != id_of.end())
            return it->second;
        size_t new_id = buckets.size();
        id_of.emplace(artist, new_id);
        buckets.push_back({artist, {}});
        return new_id;
    };

    for (auto &[art, song] : input)
    {
        buckets[get_id(art)].songs.push_back(song);
    }

    using Node = pair<int, size_t>;

    struct Cmp
    {
        bool operator()(const Node &a, const Node &b) const
        {
            return a.first < b.first;
        }
    };

    priority_queue<Node, vector<Node>, Cmp> pq;

    for (size_t id = 0; id < buckets.size(); ++id)
    {
        pq.emplace((int)buckets[id].songs.size(), id);
    }

    vector<string> output;
    output.reserve(input.size());
    string prev_artist;

    while (!pq.empty())
    {
        auto [cnt1, id1] = pq.top();
        pq.pop();

        if (buckets[id1].songs.empty())
            continue;
        if (prev_artist.empty() || buckets[id1].name != prev_artist)
        {
            output.push_back(buckets[id1].songs.back());
            buckets[id1].songs.pop_back();
            if (--cnt1 > 0)
                pq.emplace(cnt1, id1);
            prev_artist = buckets[id1].name;
        }
        else
        {
            if (pq.empty())
                throw runtime_error("Impossible arrangement contradicts guarantee");

            auto [cnt2, id2] = pq.top();
            pq.pop();

            output.push_back(buckets[id2].songs.back());
            buckets[id2].songs.pop_back();
            if (--cnt2 > 0)
                pq.emplace(cnt2, id2);

            pq.emplace(cnt1, id1);
            prev_artist = buckets[id2].name;
        }
    }

    return output;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    if (!(cin >> n))
        return 0;
    vector<pair<string, string>> songs;
    songs.reserve(n);

    for (int i = 0; i < n; ++i)
    {
        string a, s;
        cin >> a >> s;
        songs.emplace_back(move(a), move(s));
    }

    auto shuffled = arrange_playlist(songs);
    for (auto &title : shuffled)
        cout << title << "\n";
    return 0;
}