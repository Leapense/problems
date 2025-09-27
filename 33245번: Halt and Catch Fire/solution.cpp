#include <bits/stdc++.h>
using namespace std;

enum class Op { MOV, ADD, SUB, JEQ, HCF };

struct Arg {
    bool isVar{};
    string name;
    long long imm;
};

struct Inst {
    Op op;
    Arg a, b;
    string hcf_a, hcf_b;
};

static long long val(const Arg& x, unordered_map<string, long long>& V) {
    return x.isVar ? V[x.name] : x.imm;
}

static Arg parseArg(const string& s) {
    Arg r{};
    if (!s.empty() && s[0] == '$') {
        r.isVar = true;
        r.name = s.substr(1);
    } else {
        r.isVar = false;
        r.imm = stoll(s);
    }

    return r;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    if (!(cin >> n)) return 0;
    
    vector<Inst> P(n);
    for (int i = 0; i < n; ++i) {
        string op, sa, sb;
        cin >> op >> sa >> sb;
        if (op == "mov") P[i].op = Op::MOV;
        else if (op == "add") P[i].op = Op::ADD;
        else if (op == "sub") P[i].op = Op::SUB;
        else if (op == "jeq") P[i].op = Op::JEQ;
        else P[i].op = Op::HCF;

        P[i].a = parseArg(sa);
        P[i].b = parseArg(sb);
        if (P[i].op == Op::HCF) {
            P[i].hcf_a = sa;
            P[i].hcf_b = sb;
        }
    }

    unordered_map<string, long long> V;
    V["acc"] = 0;
    V["cmp"] = 0;
    V["out"] = 0;
    V["pc"] = 0;

    while (true) {
        long long pc = V["pc"];
        if (pc < 0 || pc >= n) {
            cout << V["out"] << '\n';
            return 0;
        }

        V["pc"] = pc;

        const Inst& ins = P[(size_t)pc];
        switch (ins.op) {
            case Op::HCF: {
                cout << "hcf " << ins.hcf_a << ' ' << ins.hcf_b << "\n";
                cout << V["acc"] << "\n" << V["cmp"] << "\n" << V["out"] << "\n";
                return 0;
            }
            case Op::MOV: {
                long long vv = val(ins.a, V);
                string dst = ins.b.name;
                V[dst] = vv;
                if (dst != "pc") V["pc"] = pc + 1;
                break;
            }
            case Op::ADD: {
                V["acc"] = val(ins.a, V) + val(ins.b, V);
                V["pc"] = pc + 1;
                break;
            }
            case Op::SUB: {
                V["acc"] = val(ins.a, V) - val(ins.b, V);
                V["pc"] = pc + 1;
                break;
            }
            case Op::JEQ: {
                if (val(ins.a, V) == V["cmp"]) V["pc"] = val(ins.b, V);
                else V["pc"] = pc + 1;
                break;
            }
        }
    }
}