#include "Tests.h"
#include "assert.h"
#include <iostream>
#include <string.h>
using namespace std;

Tests::Tests() {

}
void Tests::testDomain() {
	Project p1("pppp", 4, 2);
	Project p2(p1);
	Project p3;
	assert(p3.getNoOfBranches() == 0);
	assert(p1 == p2);
	p2.setNoOfBranches(1);
	assert(p2.getNoOfBranches() == 1);
}

void Tests::testRepoArray() {
	Project s1("Ana", 19, 12);
	Project s2("Maria", 19, 14);
	Project s3("Ana", 20, 15);
	Project s4("Ana", 18, 10);
	RepositoryArray rep;
	rep.addElem(s1);
	rep.addElem(s2);
	rep.addElem(s3);
	rep.addElem(s4);
	assert(rep.getSize() == 4);
	assert(rep.getItemFromPos(0) == s1);
	assert(rep.findElem(s1) == 0);
	assert(rep.getAll()[0] == s1);
	assert(rep.getAll()[1] == s2);
	assert(rep.getAll()[2] == s3);
	assert(rep.getAll()[3] == s4);
	rep.updateElem(rep.getItemFromPos(0), "aaa", 1, 1);
	assert(strcmp(rep.getItemFromPos(0).getGitPath(), "aaa") == 0);
	rep.delElem(rep.getItemFromPos(0));
	assert(rep.getSize() == 3);

}
void Tests::testProjectsWithRepoArray()
{
	Project s1("Ana", 19, 12);
	Project s2("Maria", 19, 12);
	Project s3("Dana", 20, 0);
	Project s4("Oana", 18, 10);
	repa.addElem(s1);
	repa.addElem(s2);
	repa.addElem(s3);
	repa.addElem(s4);
	Project results[10];
	assert(repa.getSize() == 4);
	int n = 0;
	filterProjectsWithRepoArray(repa, 20, 0, results, n);
	assert(results[0] == s3);
	deleteProjectsWithCommitsAndBranchesArray(repa);
	assert(repa.getSize() == 3);}

void Tests::testServiceArray() {
	Project p("aaa", 12, 1);
	Project p1("Ana", 19, 12);
	Project p2("Maria", 19, 12);
	Project p3("Dana", 20, 0);
	Project p4("Oana", 18, 10);
	serv.addProject(p1);
	serv.addProject(p2);
	serv.addProject(p3);
	serv.addProject(p4);
	serv.addProject(p);
	assert(serv.getSize() == 5);
	assert(serv.getItemFromPos(0) == p1);
	assert(serv.findOne(p) == 4);
	assert(serv.getAll()[0] == p1);
	assert(serv.getAll()[1] == p2);
	assert(serv.getAll()[2] == p3);
	assert(serv.getAll()[4] == p);
	Project results[10];
	int m = 0;
	serv.filterProjects(20, 0, results, m);
	assert(results[0] == p3);
	int n = serv.delProject(p);
	assert(serv.findOne(p) == -1);
	assert(n == 0);
	serv.updateProject(p1, "aaa", 1, 1);
	assert(strcmp(serv.getItemFromPos(0).getGitPath(), "aaa") == 0);
	serv.undoList();
	assert(strcmp(serv.getItemFromPos(0).getGitPath(), "Ana") == 0);
	serv.undoList();
	assert(serv.findOne(p) == 4);
	serv.deleteProjectsWithCommitsAndBranchesArray();
	assert(serv.findOne(p3) == -1);

}

Tests::~Tests() {

}
