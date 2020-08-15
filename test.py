# -*- coding: utf-8 -*-
import os
from pathlib import Path

project_root = Path(__file__).resolve().parents[0]


# 遍历文件夹
def walkFile(file):
    rv = []
    for root, dirs, files in os.walk(file):

        # root 表示当前正在访问的文件夹路径
        # dirs 表示该文件夹下的子目录名list
        # files 表示该文件夹下的文件list

        # 遍历文件
        for f in files:
            rv.append(os.path.join(root, f))

    return rv


def is_contain_chinese(check_str):
    """
    判断字符串中是否包含中文
    :param check_str: {str} 需要检测的字符串
    :return: {bool} 包含返回True， 不包含返回False
    """
    for ch in check_str:
        if u'\u4e00' <= ch <= u'\u9fff':
            return True
    return False


def main():
    fs = walkFile(Path(project_root, 'lc_main'))
    build = Path(project_root, 'build')
    for f in fs:
        cmd = f'cmake -S {project_root} -B {build} -DMAIN:STRING="{f}"'
        if is_contain_chinese(f):
            cmd += ' -DTARGET:STRING=test'
            exe = build.joinpath('test')
        else:
            fn = Path(f).resolve().stem
            exe = build.joinpath(fn)

        os.system(cmd)
        os.system(f'make -C {build}')
        os.system(exe)


if __name__ == '__main__':
    main()