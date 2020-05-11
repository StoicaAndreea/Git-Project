#include "Operations.h"
#include"RepoArray.h"

// filter all the projects who have the no of branches and no of commits than a given limit
// In: an array of projects a number of commits (integer)
// Out: an array of filtered projects and their number of branches(integer), a path (String), a number of commits (integer)
void filterProjectsWithRepoArray(RepositoryArray& rep, int a, int b, Project projFilter[], int& m) {
	for (int i = 0; i < rep.getSize(); i++) {
		Project crtProject = rep.getItemFromPos(i);

		if ((crtProject.getNoOfBranches() >= a) && (crtProject.getTotalNoOfCommits() >= b)) {
			projFilter[m++] = crtProject;
		}
	}
}


// deletes all the projects who have the no of branches * no of commits =0
// In: an array of projects 
// Out: an array of filtered projects and their number of branches(integer), a path (String), a number of commits (integer)
void deleteProjectsWithCommitsAndBranchesArray(RepositoryArray& rep) {
	for (int i = 0; i < rep.getSize(); i++) {
		if (rep.getItemFromPos(i).getNoOfBranches() * rep.getItemFromPos(i).getTotalNoOfCommits() == 0)
		{
			rep.delElem(rep.getItemFromPos(i));
		}
	}
}