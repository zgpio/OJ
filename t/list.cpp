#include "lc/list.h"

int main(int argc, char *argv[])
{
    ListNode *l = buildList(std::vector<int> {5, 4, 3, 2, 1, 0, -1});
    printL(l);
    return 0;
}
