#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdint.h>
#include <inttypes.h>

#define MAXN 1000
#define NAME_LEN 24
#define TOK_LEN 64

typedef enum {OP_MOV, OP_ADD, OP_SUB, OP_JEQ, OP_HCF} Op;

typedef struct {
    bool is_var;
    char var[NAME_LEN];
    int64_t imm;
} Arg;

typedef struct {
    Op op;
    Arg a, b;
    char hcf_a[TOK_LEN], hcf_b[TOK_LEN];
} Inst;

typedef struct {
    char name[NAME_LEN];
    int64_t val;
} Var;

static Inst prog[MAXN];
static int n;

static Var vars[4096];
static int vcnt = 0;

static int find_var_idx(const char* name) {
    for (int i = 0; i < vcnt; ++i) if (strcmp(vars[i].name, name) == 0) return i;
    return -1;
}

static int ensure_var_idx(const char* name) {
    int k = find_var_idx(name);
    if (k >= 0) return k;
    strcpy(vars[vcnt].name, name);
    vars[vcnt].val = 0;
    return vcnt++;
}

static int64_t get_var_val(const char* name) {
    int k = find_var_idx(name);
    if (k < 0) return 0;
    return vars[k].val;
}

static void set_var_val(const char* name, int64_t v) {
    int k = ensure_var_idx(name);
    vars[k].val = v;
}

static int64_t get_arg_val(const Arg* a) {
    if (a->is_var) return get_var_val(a->var);
    return a->imm;
}

static bool parse_arg(const char* tok, Arg* out) {
    if (tok[0] == '$') {
        out->is_var = true;
        strncpy(out->var, tok + 1, NAME_LEN - 1);
        out->var[NAME_LEN - 1] = '\0';
    } else {
        out->is_var = false;
        long long x = 0;
        sscanf(tok, "%lld", &x);
        out->imm = (int64_t)x;
    }

    return true;
}

int main(void) {
    if (scanf("%d", &n) != 1) return 0;
    for (int i = 0; i < n; ++i) {
        char op[8], sa[TOK_LEN], sb[TOK_LEN];
        if (scanf("%7s %63s %63s", op, sa, sb) != 3) return 0;
        if (strcmp(op, "mov") == 0) prog[i].op = OP_MOV;
        else if (strcmp(op, "add") == 0) prog[i].op = OP_ADD;
        else if (strcmp(op, "sub") == 0) prog[i].op = OP_SUB;
        else if (strcmp(op, "jeq") == 0) prog[i].op = OP_JEQ;
        else prog[i].op = OP_HCF;

        parse_arg(sa, &prog[i].a);
        parse_arg(sb, &prog[i].b);

        if (prog[i].op == OP_HCF) {
            strncpy(prog[i].hcf_a, sa, TOK_LEN - 1);
            prog[i].hcf_a[TOK_LEN - 1] = '\0';
            strncpy(prog[i].hcf_b, sb, TOK_LEN - 1);
            prog[i].hcf_b[TOK_LEN - 1] = '\0';
        }
    }

    set_var_val("acc", 0);
    set_var_val("cmp", 0);
    set_var_val("out", 0);
    set_var_val("pc", 0);

    while (1) {
        int64_t pc = get_var_val("pc");
        if (pc < 0 || pc >= n) {
            printf("%" PRId64 "\n", get_var_val("out"));
            return 0;
        }

        set_var_val("pc", pc);

        Inst *ins = &prog[pc];

        if (ins->op == OP_HCF) {
            printf("hcf %s %s\n", ins->hcf_a, ins->hcf_b);
            printf("%" PRId64 "\n", get_var_val("acc"));
            printf("%" PRId64 "\n", get_var_val("cmp"));
            printf("%" PRId64 "\n", get_var_val("out"));
            return 0;
        }
        else if (ins->op == OP_MOV) {
            int64_t v = get_arg_val(&ins->a);
            const char* dst = ins->b.var;
            set_var_val(dst, v);
            if (strcmp(dst, "pc") == 0) {

            } else {
                set_var_val("pc", pc + 1);
            }
        }
        else if (ins->op == OP_ADD) {
            int64_t v = get_arg_val(&ins->a) + get_arg_val(&ins->b);
            set_var_val("acc", v);
            set_var_val("pc", pc + 1);
        }
        else if (ins->op == OP_SUB) {
            int64_t v = get_arg_val(&ins->a) - get_arg_val(&ins->b);
            set_var_val("acc", v);
            set_var_val("pc", pc + 1);
        }
        else if (ins->op == OP_JEQ) {
            int64_t lhs = get_arg_val(&ins->a);
            int64_t cmp = get_var_val("cmp");
            if (lhs == cmp) {
                int64_t target = get_arg_val(&ins->b);
                set_var_val("pc", target);
            } else {
                set_var_val("pc", pc + 1);
            }
        }
    }

    return 0;
}