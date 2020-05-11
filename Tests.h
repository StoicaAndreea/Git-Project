#pragma once
#include "ServiceArray.h"
#include"RepoArray.h"
#include "Operations.h"
class Tests {
private:
	RepositoryArray repa;
	ServiceArray serv;
public:
	Tests();
	void testDomain();
	void testRepoArray();
	void testProjectsWithRepoArray();
	void testServiceArray();
	~Tests();
};
