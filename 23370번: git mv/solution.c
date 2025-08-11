#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ARROW " => "
#define LBRACE "{"
#define RBRACE "}"

static char **split_path(const char *path, size_t *count) {
    size_t len = strlen(path);
    size_t pieces = 1;
    for (size_t i = 0; i < len; ++i) {
        if (path[i] == '/') {
            ++pieces;
        }
    }
    char **out = (char **)malloc(pieces * sizeof(char *));
    size_t start = 0, idx = 0;
    for (size_t i = 0; i <= len; ++i) {
        if (path[i] == '/' || path[i] == '\0') {
            size_t seg_len = i - start;
            char *seg = (char *)malloc(seg_len + 1);
            memcpy(seg, path + start, seg_len);
            seg[seg_len] = '\0';
            out[idx++] = seg;
            start = i + 1;
        }
    }
    *count = pieces;
    return out;
}

static char *join_range(char **parts, size_t begin, size_t end, int leading_slash, int trailing_slash) {
    if (begin >= end) {
        char *empty = (char *)malloc(1);
        empty[0] = '\0';
        return empty;
    }

    size_t total = leading_slash + trailing_slash;
    for (size_t i = begin; i < end; ++i) {
        total += strlen(parts[i]);
        if (i + 1 < end) {
            ++total;
        }
    }

    char *res = (char *)malloc(total + 1);
    size_t pos = 0;
    if (leading_slash) {
        res[pos++] = '/';
    }

    for (size_t i = begin; i < end; ++i) {
        size_t seg_len = strlen(parts[i]);
        memcpy(res + pos, parts[i], seg_len);
        pos += seg_len;
        if (i + 1 < end) {
            res[pos++] = '/';
        }
    }
    if (trailing_slash) {
        res[pos++] = '/';
    }
    res[pos] = '\0';
    return res;
}

int main(void) {
    char *src = NULL;
    char *dst = NULL;
    size_t n = 0;
    getline(&src, &n, stdin);
    src[strcspn(src, "\n")] = '\0';
    getline(&dst, &n, stdin);
    dst[strcspn(dst, "\n")] = '\0';

    size_t src_cnt, dst_cnt;
    char **src_parts = split_path(src, &src_cnt);
    char **dst_parts = split_path(dst, &dst_cnt);

    size_t p = 0;
    while (p < src_cnt && p < dst_cnt && strcmp(src_parts[p], dst_parts[p]) == 0) {
        ++p;
    }

    size_t q = 0;
    while (q < src_cnt - p && q < dst_cnt - p && strcmp(src_parts[src_cnt - 1 - q], dst_parts[dst_cnt - 1 - q]) == 0) {
        ++q;
    }

    char *A = join_range(src_parts, 0, p, 0, p > 0);
    char *B = join_range(src_parts, p, src_cnt - q, 0, 0);
    char *C = join_range(dst_parts, p, dst_cnt - q, 0, 0);
    char *D = join_range(src_parts, src_cnt - q, src_cnt, q > 0, 0);

    size_t final_len = strlen(A) + strlen(B) + strlen(C) + strlen(D) + strlen(LBRACE) + strlen(ARROW) + strlen(RBRACE);
    char *out = (char*)malloc(final_len + 1);
    sprintf(out, "%s%s%s%s%s%s", A, LBRACE, B, ARROW, C, RBRACE);
    strcat(out, D);
    puts(out);

    free(out);
    free(A);
    free(B);
    free(C);
    free(D);
    for (size_t i = 0; i < src_cnt; ++i) free(src_parts[i]);
    for (size_t i = 0; i < dst_cnt; ++i) free(dst_parts[i]);
    free(src_parts);
    free(dst_parts);
    free(src);
    free(dst);
    return 0;
}