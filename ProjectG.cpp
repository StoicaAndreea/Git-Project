#include "ProjectG.h"
#include <string.h>
#include <sstream>
using namespace std;

Project::Project() {
	this->gitPath = NULL;
	this->noOfBranches = 0;
	this->totalNoOfCommits = 0;
}

Project::Project(const char* gitPath, int noOfBranches, int totalNoOfCommits) {
	
	if (gitPath) {
		this->gitPath = new char[strlen(gitPath) + 1];
		strcpy_s(this->gitPath, strlen(gitPath) + 1, gitPath);
	}
	this->noOfBranches = noOfBranches;
	this->totalNoOfCommits = totalNoOfCommits;
}

Project::Project(const Project& p) {
	if (p.gitPath) {
		this->gitPath = new char[strlen(p.gitPath) + 1];
		strcpy_s(this->gitPath, strlen(p.gitPath) + 1, p.gitPath);
	}
	this->noOfBranches = p.noOfBranches;
	this->totalNoOfCommits = p.totalNoOfCommits;
}

Project::Project(string linie) {
	std::istringstream iss(linie);
	string tok1, tok2, tok3;
	iss >> tok1 >> tok2 >> tok3;
	gitPath = new char[tok1.length() + 1];
	strcpy_s(gitPath, tok1.length() + 1, tok1.c_str());
	noOfBranches = stoi(tok2);
	totalNoOfCommits = stoi(tok3);

}

char* Project::getGitPath() {
	return this->gitPath;
}

int Project::getNoOfBranches() {
	return this->noOfBranches;
}

int Project::getTotalNoOfCommits() {
	return this->totalNoOfCommits;
}

void Project::setGitPath(const char* gitPath) {
	if (this->gitPath) delete[]this->gitPath;
	this->gitPath = new char[strlen(gitPath) + 1];
	strcpy_s(this->gitPath, strlen(gitPath) + 1, gitPath);
}

void Project::setNoOfBranches(int noOfBranches) {
	this->noOfBranches = noOfBranches;
}

void Project::setTotalNoOfCommits(int totalNoOfCommits) {
	this->totalNoOfCommits = totalNoOfCommits;
}

Project::~Project() {
	if (gitPath) delete[] gitPath;
	this->gitPath = NULL;
	this->noOfBranches = -1;
	this->totalNoOfCommits = -1;
}

Project& Project::operator=(const Project& p) {
	if (this == &p) return *this; //in case of self assignment
	if (p.gitPath) {
		if (this->gitPath)delete[] this->gitPath;
		this->gitPath = new char[strlen(p.gitPath) + 1];
		strcpy_s(this->gitPath, strlen(p.gitPath) + 1, p.gitPath);
	}
	this->noOfBranches = p.noOfBranches;
	this->totalNoOfCommits = p.totalNoOfCommits;
	return*this;

}

bool Project::operator == (const Project& p) {
	if(this->gitPath and p.gitPath)
	return(strcmp(this->gitPath, p.gitPath) == 0) and (this->noOfBranches == p.noOfBranches) and (this->totalNoOfCommits == p.totalNoOfCommits);
}

bool Project::operator < (const Project& p) {
	return(strcmp(this->gitPath, p.gitPath) < 0);
}


ostream& operator<<(ostream& os, Project p) {
	os << p.gitPath << " " << p.noOfBranches << " " << p.totalNoOfCommits << endl;
	return os;
}
istream& operator>>(istream& is, Project& p) {
	cout << "Give the gitPath:  ";
	char* gitPath = new char[10];
	is >> gitPath;
	cout << "Give the no of branches:  ";
	int b;
	cin >> b;
	cout << "Give the total no of commits:  ";
	int c;
	cin >> c;
	p.setGitPath(gitPath);
	p.setNoOfBranches(b);
	p.setTotalNoOfCommits(c);
	delete[] gitPath;
	return is;
}