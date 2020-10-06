# 输入规模与计算复杂度之间的对应关系(根据计算机算力具体分析)
[![Build Status](https://travis-ci.org/zgpio/OJ.svg?branch=master)](https://travis-ci.org/zgpio/OJ)
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
- HDU OJ 定义了 ONLINE_JUDGE 宏
- CMakeLists.txt
    - 设置宏 LOCAL_JUDGE, 用于区分本地和ONLINE
    - 设置 CMAKE_EXPORT_COMPILE_COMMANDS 选项, 用于导出编译命令

# Build
## Linux/Macos
```sh
cmake -DCMAKE_EXPORT_COMPILE_COMMANDS=YES -DCMAKE_BUILD_TYPE=Debug -S ~/OJ -B ~/OJ/build -DMAIN:STRING=kmp.cpp
ln -s build/compile_commands.json
```
## Windows
- [安装Target为x86_64-pc-windows-msvc的LLVM](https://marvinsblog.net/post/2019-01-08-clang-on-windows/)

```sh
# 在"x64 Native Tools Command Prompt for VS 2019"环境下
# %comspec% /k "C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\VC\Auxiliary\Build\vcvars64.bat"
# 使用"NMake Makefiles" generator可以生成compile_commands.json, 而"Visual Studio 16 2019"不能
cmake -G "NMake Makefiles"  -DCMAKE_EXPORT_COMPILE_COMMANDS=YES  -S ~/OJ -B ~/OJ/build -DMAIN:STRING=kmp.cpp
cmake --build ~/oj/build


# 默认使用"Visual Studio 16 2019" generator
cmake -DCMAKE_EXPORT_COMPILE_COMMANDS=YES -S ~/OJ -B ~/OJ/build -DMAIN:STRING=kmp.cpp
cmake --build ~/oj/build


# 使用clang编译器替代cl.exe
cmake -G "NMake Makefiles"  -DCMAKE_C_COMPILER=clang -DCMAKE_CXX_COMPILER=clang++  -DCMAKE_EXPORT_COMPILE_COMMANDS=YES  -S ~/OJ -B ~/OJ/build -DMAIN:STRING=kmp.cpp
cmake --build ~/oj/build

mklink C:\Users\zgp\oj\compile_commands.json C:\Users\zgp\oj\build\compile_commands.json
```
