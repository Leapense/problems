#include <gtest/gtest.h>
#include <bits/stdc++.h>

using namespace std;

struct ArtistBucket
{
    string name;          // artist name
    vector<string> songs; // all remaining songs (we pop_back when using one)
};

// -------------- core algorithm ------------------------------
vector<string>
arrange_playlist(const vector<pair<string, string>> &input)
{
    // Step 1.  Collect songs per artist
    unordered_map<string, size_t> id_of; // artist -> index in buckets
    vector<ArtistBucket> buckets;        // indexed by id
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
        buckets[get_id(art)].songs.push_back(song);

    // Step 2.  Build max-heap (remaining_count, artist_id)
    using Node = pair<int, size_t>; // (-remaining, id) for max-heap
    struct Cmp
    {
        bool operator()(const Node &a, const Node &b) const
        {
            return a.first < b.first; // greater remaining first (note: positive counts)
        }
    };
    priority_queue<Node, vector<Node>, Cmp> pq;

    for (size_t id = 0; id < buckets.size(); ++id)
        pq.emplace((int)buckets[id].songs.size(), id);

    // Step 3.  Greedy placement
    vector<string> output;
    output.reserve(input.size());
    string prev_artist; // empty means "no previous"

    while (!pq.empty())
    {
        auto [cnt1, id1] = pq.top();
        pq.pop();

        if (buckets[id1].songs.empty())
            continue; // should never happen

        if (prev_artist.empty() || buckets[id1].name != prev_artist)
        {
            // we can use this artist
            output.push_back(buckets[id1].songs.back());
            buckets[id1].songs.pop_back();
            if (--cnt1 > 0)
                pq.emplace(cnt1, id1);
            prev_artist = buckets[id1].name;
        }
        else
        {
            // need second best
            if (pq.empty())
                throw runtime_error("Impossible arrangement contradicts guarantee");

            auto [cnt2, id2] = pq.top();
            pq.pop();

            output.push_back(buckets[id2].songs.back());
            buckets[id2].songs.pop_back();
            if (--cnt2 > 0)
                pq.emplace(cnt2, id2);

            // push first artist back unchanged
            pq.emplace(cnt1, id1);

            prev_artist = buckets[id2].name;
        }
    }
    return output; // size == input.size()
}

static bool valid_playlist(const vector<pair<string, string>> &in, const vector<string> &out)
{
    if (in.size() != out.size())
        return false;

    unordered_map<string, string> title2artist;
    for (auto &p : in)
        title2artist[p.second] = p.first;

    vector<int> seen(out.size(), 0);
    unordered_set<string> used;

    string prev;

    for (auto &title : out)
    {
        if (!title2artist.count(title))
            return false;
        if (!used.insert(title).second)
            return false;

        string curArtist = title2artist[title];
        if (!prev.empty() && curArtist == prev)
            return false;
        prev = curArtist;
    }
    return true;
}

TEST(CatchyTunes, Sample1)
{
    vector<pair<string, string>> in = {
        {"greenbiscuits", "hard2catch"},
        {"greenbiscuits", "born2run"},
        {"thebakers", "baking1000breads"},
        {"2fast2fail", "flyinghigh"},
        {"rock2thetop", "goingout"}};

    auto out = arrange_playlist(in);
    ASSERT_TRUE(valid_playlist(in, out));
}

TEST(CatchyTunes, Sample2)
{
    vector<pair<string, string>> in = {
        {"a", "a1"}, {"a", "a2"}, {"a", "a3"}, {"a", "a4"}, {"a", "a5"}, {"b", "b1"}, {"c", "c1"}, {"d", "d1"}, {"e", "e1"}, {"f", "f1"}};

    auto out = arrange_playlist(in);
    ASSERT_TRUE(valid_playlist(in, out));
}

TEST(CatchyTunes, Randomised)
{
    std::mt19937 rng(42);
    const int N = 5000;
    vector<pair<string, string>> in;
    in.reserve(N);

    for (int i = 0; i < N / 2; ++i)
    {
        string artist = "u" + to_string(i);
        string song = "su" + to_string(i);
        in.emplace_back(artist, song);
    }

    for (int i = 0; i < N / 2; ++i)
    {
        string song = "star" + to_string(i);
        in.emplace_back("star", song);
    }

    shuffle(in.begin(), in.end(), rng);

    auto out = arrange_playlist(in);
    ASSERT_TRUE(valid_playlist(in, out));
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}