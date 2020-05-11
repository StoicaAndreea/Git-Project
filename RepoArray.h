#pragma once
#include "ProjectG.h"

class RepositoryArray
{
private:
	Project elem[10];
	int size;

public:
	RepositoryArray();
	void addElem(Project);
	int findElem(Project);
	Project getItemFromPos(int);
	void delElem(Project);
	void updateElem(Project, const char*, int, int);
	Project* getAll();
	int getSize();
	~RepositoryArray();
};

