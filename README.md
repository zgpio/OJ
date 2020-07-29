# 输入规模与计算复杂度之间的对应关系(根据计算机算力具体分析)
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

# NOTE
- CMakeLists.txt
    - 设置宏 LOCAL_JUDGE, 用于区分本地和ONLINE
    - 设置 CMAKE_EXPORT_COMPILE_COMMANDS 选项, 用于导出编译命令

# Build
```sh
cmake -DCMAKE_EXPORT_COMPILE_COMMANDS=YES -DCMAKE_BUILD_TYPE=Debug -S ~/OJ -B ~/OJ/build -DMAIN:STRING=kmp.cpp
ln -s build/compile_commands.json
```
