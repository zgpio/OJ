# 在竞赛中, 一般算机一秒能运行5 x 10^8次汁算, 一般输入规模
```
O(n)            n < 10^8.
O(nlogn)        n < 10^6.
O(n*sqrt(n))    n < 10^5.
O(n^2)          n < 5000.
O(n^3)          n < 300.
O(2^n)          n < 25.
O(n!)           n < 11.
```

# Tools
* https://github.com/renatoGarcia/icecream-cpp
* https://github.com/Limeoats/BigNumber
* https://www.cs.usfca.edu/~galles/visualization/AVLtree.html

# TODO
- [x] lc91
- [x] lc71
- [ ] 48. Rotate Image

# Build
```sh
cmake -DCMAKE_EXPORT_COMPILE_COMMANDS=YES -DCMAKE_BUILD_TYPE=Debug -S ~/OJ -B ~/OJ/build -DMAIN:STRING=kmp.cpp
```
