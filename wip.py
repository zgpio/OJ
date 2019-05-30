# -*- coding: utf-8 -*-

N = 8
block = {(4, 0), (5, 0), (1, 2), (6, 4), (7, 4), (3, 6)}
entry = {(7, 3), (0, 4), (1, 7), (5, 7)}


def straight(p1, p2):
    """TODO: Docstring for straight.

    :p1: TODO
    :p2: TODO
    :returns: TODO

    """
    x1, y1 = p1
    x2, y2 = p2
    dx = x2 - x1
    dy = y2 - y1
    if x1 < x2:
        x, y = x1, y1
    else:
        x, y = x2, y2

    while(x<)
