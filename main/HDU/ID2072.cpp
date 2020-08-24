#include <bits/stdc++.h>
using namespace std;
const int LINE_LEN = 10000;
const int WORD_LEN = 100;
int main()
{
#ifdef LOCAL_JUDGE
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
