#include <iostream>
#include "RepoArray.h"
#include"ServiceArray.h"
#include "UI.h"
#include "Tests.h"
using namespace std;


int main() {
	cout << "start" << endl;
	Tests tes;
	tes.testDomain();
	tes.testRepoArray();
	tes.testProjectsWithRepoArray();
	tes.testServiceArray();
	cout << "succes" << endl;
	RepositoryArray repo;
	Project p1("aaa", 1, 1);
	Project p2("bbb", 2, 2);
	Project p3("ccc", 3, 0);
	Project p4("ddd", 2, 2);
	repo.addElem(p1);
	repo.addElem(p2);
	repo.addElem(p3);
	repo.addElem(p4);
	ServiceArray serv(repo);
	UI ui(serv);
	ui.showUI();
	return 0;
}