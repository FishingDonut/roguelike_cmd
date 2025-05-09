#include "file_manager/score/score_manager.h"
#include "file_manager/score/score_out.h"
#include "file_manager/score/score_in.h"

#include <vector>
#include <ctime>
#include <random>

using namespace std;

int scoreManager()
{
    vector<string> linhas;
    time_t now = time(0);
    srand(now);
    tm data = *localtime(&now);

    long long pontos = 0 + (rand() % (6000 - 0) - 1);
    string name = "Edu";

    scoreIn(linhas, pontos, name);
    scoreOut(linhas);

    return 0;
}
