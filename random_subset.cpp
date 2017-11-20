#include "testlib.h"

#include <cassert>
#include <map>
#include <vector>

// binom{[n]}{k} : O(k \log k)
template<typename Int>
std::vector<Int> random_subset(Int n, int k)
{
    assert(n >= k);
    std::set<Int> set;
    for (Int i = n - k; i < n; ++ i) {
        Int p = rnd.next(static_cast<Int>(0), i - 1);
        if (set.count(p)) {
            set.insert(i);
        } else {
            set.insert(p);
        }
    }
    std::vector<Int> result;
    for (auto elem : set) {
        result.push_back(elem);
    }
    return result;
}

int main()
{
    auto result = random_subset(1000000000LL, 10);
    for (auto elem : result) {
        printf("%lld,", elem);
    }
    puts("");
}
