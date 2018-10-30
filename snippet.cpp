int isLeap(int Y)
{
    if ((Y % 4 == 0 && Y % 100 != 0) or (Y % 400 == 0)) return 1;
    return 0;
}
