#include "testlib.h"
#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <algorithm>

// A helper function to generate a random identifier.
// An identifier consists of letters, digits, and underscores, but cannot start with a digit.
std::string gen_ident(int max_len) {
    int len = rnd.next(1, max_len);
    std::string s;
    // The first character cannot be a digit.
    s += rnd.next("[a-zA-Z_]");
    // Subsequent characters can be alphanumeric or underscore.
    for (int i = 1; i < len; ++i) {
        s += rnd.next("[a-zA-Z0-9_]");
    }
    return s;
}

// Represents a fact or a query for easier handling.
struct Fact {
    std::string name;
    std::vector<std::string> args;

    // Overload the << operator for easy printing in the required format.
    friend std::ostream& operator<<(std::ostream& os, const Fact& f) {
        os << f.name << "(";
        for (size_t i = 0; i < f.args.size(); ++i) {
            os << f.args[i] << (i == f.args.size() - 1 ? "" : ",");
        }
        os << ")";
        return os;
    }
};

int main(int argc, char* argv[]) {
    // Initialize the testlib generator.
    registerGen(argc, argv, 1);

    // --- Read Parameters from Command Line ---
    // These parameters control the size and complexity of the generated test case.
    int num_facts = opt<int>("nfacts", 100);
    int num_queries = opt<int>("nqueries", 50);
    int num_fact_names = opt<int>("nnames", 10);
    int num_constants = opt<int>("nconsts", 20);
    int max_arity = opt<int>("maxarity", 5);
    int max_len = opt<int>("maxlen", 8);

    // --- Generate Pools of Reusable Components ---
    std::vector<std::string> fact_names;
    for (int i = 0; i < num_fact_names; ++i) {
        fact_names.push_back(gen_ident(max_len));
    }

    std::vector<std::string> constants;
    for (int i = 0; i < num_constants; ++i) {
        constants.push_back(gen_ident(max_len));
    }
    
    // Generate a set of "signatures" (name, arity) to structure the facts.
    std::map<std::string, std::set<int>> signatures;
    for(const auto& name : fact_names) {
        int num_arities_for_name = rnd.next(1, 2);
        for(int i = 0; i < num_arities_for_name; ++i) {
            signatures[name].insert(rnd.next(1, max_arity));
        }
    }

    // --- Generate and Print Facts ---
    std::vector<Fact> facts;
    for (int i = 0; i < num_facts; ++i) {
        // Pick a random name and one of its valid arities.
        auto it = signatures.begin();
        std::advance(it, rnd.next(signatures.size()));
        std::string name = it->first;
        int arity = *it->second.begin();
        
        Fact f;
        f.name = name;
        for (int j = 0; j < arity; ++j) {
            f.args.push_back(constants[rnd.next(constants.size())]);
        }
        facts.push_back(f);
    }
    
    // Print the generated facts, with a random number of facts per line.
    for (size_t i = 0; i < facts.size(); ) {
        int count_on_line = rnd.next(1, 4);
        for(int j = 0; j < count_on_line && i < facts.size(); ++j, ++i) {
            std::cout << facts[i] << (j == count_on_line - 1 || i == facts.size() ? "" : " ");
        }
        std::cout << std::endl;
    }

    // A blank line separates the facts from the queries.
    std::cout << std::endl;

    // --- Generate and Print Queries ---
    std::vector<std::string> var_names;
    for(char c = 'A'; c <= 'Z'; ++c) {
        var_names.push_back(std::string("_") + c);
    }

    for (int i = 0; i < num_queries; ++i) {
        int query_type = rnd.next(100);
        Fact q;

        // 70% chance to generate a query that is likely to match something.
        if (query_type < 70 && !facts.empty()) {
            const auto& base_fact = facts[rnd.next(facts.size())];
            q.name = base_fact.name;
            
            std::map<std::string, std::string> const_to_var;
            int var_idx = 0;

            for (const auto& arg : base_fact.args) {
                int arg_type = rnd.next(100);
                if (arg_type < 40) { // 40% chance to keep the original constant.
                    q.args.push_back(arg);
                } else if (arg_type < 70) { // 30% chance to use a wildcard '_'.
                    q.args.push_back("_");
                } else { // 30% chance to use a named variable like '_X'.
                    if (const_to_var.find(arg) == const_to_var.end()) {
                        const_to_var[arg] = var_names[var_idx++ % var_names.size()];
                    }
                    q.args.push_back(const_to_var[arg]);
                }
            }
        // 20% chance to generate a query that is unlikely to match.
        } else if (query_type < 90 && !signatures.empty()) {
            int mismatch_type = rnd.next(1, 3);
            if (mismatch_type == 1) { // Mismatch by name.
                 q.name = "non_existent_" + gen_ident(5);
                 q.args.assign(rnd.next(1, max_arity), constants[0]);
            } else { // Mismatch by arity.
                 auto it = signatures.begin();
                 std::advance(it, rnd.next(signatures.size()));
                 q.name = it->first;
                 int wrong_arity;
                 do {
                     wrong_arity = rnd.next(1, max_arity + 3);
                 } while (it->second.count(wrong_arity)); // Ensure arity is actually wrong.
                 q.args.assign(wrong_arity, constants[0]);
            }
        // 10% chance for a completely random query.
        } else {
            auto it = signatures.begin();
            std::advance(it, rnd.next(signatures.size()));
            q.name = it->first;
            int arity = *it->second.begin();

            for (int j = 0; j < arity; ++j) {
                int arg_type = rnd.next(1, 3);
                if (arg_type == 1) { // Constant
                     q.args.push_back(constants[rnd.next(constants.size())]);
                } else if (arg_type == 2) { // Wildcard
                    q.args.push_back("_");
                } else { // Named variable
                    q.args.push_back(var_names[rnd.next(var_names.size())]);
                }
            }
        }
        
        std::cout << q << std::endl;
    }

    return 0;
}