#include "file_manager/score/score_manager.h"
#include "file_manager/score/score_out.h"
#include "file_manager/score/score_in.h"

#include <vector>

int scoreManager(long long pontos, std::string name)
{
    std::vector<std::string> linhas;

    scoreIn(linhas, pontos, name);
    scoreOut(linhas);

    return 0;
}
