#pragma once
#include "ProjectG.h"
#include "RepoArray.h"

void filterProjectsWithRepoArray(RepositoryArray& repa, int a, int b, Project projFilter[], int& m);
void deleteProjectsWithCommitsAndBranchesArray(RepositoryArray& repa);
