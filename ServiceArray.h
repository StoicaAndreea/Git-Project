#pragma once
#include "RepoArray.h"
#include "ProjectG.h"
using namespace std;

class ServiceArray
{
private:
	RepositoryArray repo;
	RepositoryArray undo[100];
	int size = 0;
public:
	ServiceArray();
	ServiceArray(const RepositoryArray&);
	void setRepo(const RepositoryArray&);
	void filterProjects(int a, int b, Project projFilter[], int& m);
	void addProject(Project&);
	int delProject(Project&);
	Project* getAll();
	Project updateProject(Project, const char*, int, int);
	int findOne(Project);
	Project getItemFromPos(int);
	int getSize();
	void deleteProjectsWithCommitsAndBranchesArray();
	int undoList();
	~ServiceArray();
};


