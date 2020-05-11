#include "RepoArray.h"

RepositoryArray::RepositoryArray() { size = 0; }

void RepositoryArray::addElem(Project s) {
	elem[size++] = s;
}

int RepositoryArray::findElem(Project s) {
	int i = 0;

	while (i < size) {
		if (elem[i] == s) return i;
		i++;
	}
	return -1;
}

void RepositoryArray::delElem(Project s) {
	int i = findElem(s);
	if (i != -1)
	{
		elem[i] = elem[size - 1];
		size--;
	}
}

void RepositoryArray::updateElem(Project p, const char* gp, int b, int c) {
	int i = findElem(p);
	if (i != -1)
	{
		elem[i].setGitPath(gp);
		elem[i].setNoOfBranches(b);
		elem[i].setTotalNoOfCommits(c);
	}

}

Project* RepositoryArray::getAll() {
	return elem;
}
int RepositoryArray::getSize() {
	return size;
}
RepositoryArray::~RepositoryArray() {
}

Project RepositoryArray::getItemFromPos(int i) {
	return elem[i];
}
