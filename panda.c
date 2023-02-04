#include "panda.h"
// swap
void SWAP_DEFAULT(void *a, void *b, size_t sz) {
    void *p;
    p = malloc(sz);
    memcpy(p, a, sz);
    memcpy(a, b, sz);
    memcpy(b, p, sz);
    return;
}
// sort
bool less_then_unsigned(const void *a, const void *b, int equal,
                        const size_t sz) {
    if (!sz) return equal;
    uint8_t a_first_byte = *(uint8_t *)(a + sz - 1);
    uint8_t b_first_byte = *(uint8_t *)(b + sz - 1);
    if (a_first_byte != b_first_byte) return a_first_byte < b_first_byte;
    return less_then_unsigned(a, b, equal, sz - 1);
}
bool less_then_signed(const void *a, const void *b, int equal,
                      const size_t sz) {
    int8_t a_first_byte = *(int8_t *)(a + sz - 1);
    int8_t b_first_byte = *(int8_t *)(b + sz - 1);
    //+-
    if ((a_first_byte ^ b_first_byte) < 0) {
        if (equal) return a_first_byte <= b_first_byte;
        return a_first_byte < b_first_byte;
    }
    return less_then_unsigned(a, b, equal, sz) ^ (a_first_byte < 0);
}

bool less_then_float(const void *a, const void *b, int equal, const size_t sz) {
    float at = *(float *)a;
    float bt = *(float *)b;
    if (equal) return at <= bt;
    return at < bt;
}
bool less_then_double(const void *a, const void *b, int equal,
                      const size_t sz) {
    double at = *(double *)a;
    double bt = *(double *)b;
    if (equal) return at <= bt;
    return at < bt;
}

void SORT_DEFAULT(void *s, void *t, int sz, int equal,
                  bool (*cmp)(const void *, const void *, const int,
                              const size_t)) {
    if (t - s == 0) return;
    if (t - s == sz) return;
    size_t length = t - s;
    void *lend = s + ((length / sz) >> 1) * sz;
    SORT_DEFAULT(s, lend, sz, equal, cmp);
    SORT_DEFAULT(lend, t, sz, equal, cmp);
    void *tmp;
    tmp = malloc(length);
    size_t cntl = 0;
    size_t cntr = 0;
    size_t cnt = 0;
    while (s + cntl * sz != lend && lend + cntr * sz != t) {
        if (cmp((s + cntl * sz), (lend + cntr * sz), equal, sz)) {
            memcpy(tmp + cnt * sz, s + cntl * sz, sz);
            cntl++;
        } else {
            memcpy(tmp + cnt * sz, lend + cntr * sz, sz);
            cntr++;
        }
        cnt++;
    }
    while (s + cntl * sz != lend) {
        memcpy(tmp + cnt * sz, s + cntl * sz, sz);
        cntl++;
        cnt++;
    }
    while (lend + cntr * sz != t) {
        memcpy(tmp + cnt * sz, lend + cntr * sz, sz);
        cntr++;
        cnt++;
    }
    memcpy(s, tmp, length);
}
// lower_bound
void *LOWER_BOUND_DEFAULT(void *a, void *b, void *v, size_t sz,
                          bool (*cmp)(const void *, const void *, int equal,
                                      const size_t)) {
    if (cmp(b - sz, v, 0, sz)) return b;
    void *mid;
    void *low = a;
    void *high = b;
    while (high - low > 0) {
        mid = low + (((high - low) / sz) >> 1) * sz;
        if (cmp(mid, v, 0, sz)) {
            low = mid;
        } else {
            high = mid;
        }
    }
    return low;
}
// upper_bound
void *UPPER_BOUND_DEFAULT(void *a, void *b, void *v, size_t sz,
                          bool (*cmp)(const void *, const void *, int equal,
                                      const size_t)) {
    if (cmp(b - sz, v, 1, sz)) return b;
    void *mid;
    void *low = a;
    void *high = b;
    while (high - low > 0) {
        mid = low + (((high - low) / sz) >> 1) * sz;
        if (cmp(mid, v, 1, sz)) {
            low = mid;
        } else {
            high = mid;
        }
    }
    return low;
}
