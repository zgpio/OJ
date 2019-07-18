#include <cstdio>
#include <stdio.h>
#include <cstdlib>
#include <cmath>
#include <iostream>//其中包含了stl_algobase
#include <algorithm>
#include <cstring>
#include <set>
#include <string>
#include <list>
using namespace std;
const int LINE_LEN = 10000;
const int WORD_LEN = 100;
int main()
{
#ifndef ONLINE_JUDGE
    freopen ("input.txt", "rt", stdin);
#endif
    char line[LINE_LEN];
    char word[WORD_LEN];
    while(cin.getline(line, LINE_LEN)) {
        if(strchr(line, '#'))
            break;
        int i = 0;
        set<string> wset;
        while(sscanf(line + i, "%s", word) != EOF) {
            i += strstr(line + i, word) - (line + i) + strlen(word);
            wset.insert(word);
        }
        printf("%ld\n", wset.size());
    }
    return 0;
}
