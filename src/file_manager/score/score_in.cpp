#include "file_manager/score/score_in.h"
#include "core/is_numeric.h"

#include <iostream>
#include <fstream>
#include <vector>
#include <ctime>
#include <cctype>
#include <random>
#include <string>

using namespace std;

void scoreIn(vector<string> &linhas, int pontos, string newName)
{
    string linha, oldName;

    ifstream fileR("pontos.txt");

    if (!fileR.is_open())
    {
        return;
    }

    int countLine = -1;

    while (getline(fileR, linha))
    {
        countLine++;
        if (!isNumeric(linha) || linha.empty())
        {
            linhas.push_back(linha);
            continue;
        }

        try
        {
            if (stoll(linha) < pontos)
            {
                linhas.push_back(to_string(pontos));
                pontos = stoll(linha);
                oldName = linhas[countLine - 1];
                linhas[countLine - 1] = newName;
                newName = oldName;
                continue;
            }
            linhas.push_back(linha);
        }
        catch (invalid_argument &e)
        {
            cerr << "Erro ao converter: " << linha << endl;
        }
    }
}