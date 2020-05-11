#pragma once
#include<iostream>
#include<string>
using namespace std;

class Project {
private:
	char* gitPath;
	int noOfBranches;
	int totalNoOfCommits;
public:
	Project();
	Project(const char*, int, int);
	Project(const Project&);
	Project& operator=(const Project&);
	Project(string);//conversie
	char* getGitPath();
	int getNoOfBranches();
	int getTotalNoOfCommits();
	void setGitPath(const char*);
	void setNoOfBranches(int);
	void setTotalNoOfCommits(int);
	bool operator==(const Project&);
	bool operator<(const Project&);
	~Project();
	friend ostream& operator<<(ostream& os, Project s);
	friend istream& operator>>(istream&, Project&);
};