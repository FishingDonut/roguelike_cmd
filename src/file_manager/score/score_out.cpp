#include "file_manager/score/score_out.h"

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

void scoreOut(vector<string> &linhas)
{
    string linha;

    ofstream file("scores.txt", ios::trunc);

    if (!file.is_open())
    {
        return;
    }

    file.clear();
    file.seekp(0, ios::beg);

    for (string &linha : linhas)
    {
        file << linha << '\n';
    }
    return;
}