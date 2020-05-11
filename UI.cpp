#include "UI.h"
#include <iostream>
using namespace std;

UI::UI(ServiceArray& service)
{
	s = service;
}
void UI::addProj() {
	Project proj;
	cout << "Give the Project:";
	cin >> proj;
	s.addProject(proj);
	cout << "the Project has been successfully added" << endl;
}


void UI::findProj() {
	Project proj;
	cout << "Give the Project:";
	cin >> proj;
	int rez = s.findOne(proj);
	if (rez>=0) cout << "The Project has been found!" << endl;
	else cout << "The Project has not been found!" << endl;
}

void UI::delProj() {
	Project proj;
	cout << "Give the Project:" << endl;;
	cin >> proj;
	int rez = s.delProject(proj);
	if (rez == 0) cout << "Projectul a fost  sters cu succes!" << endl;
	else cout << "Projectul NU a fost sters!" << endl;
}

void UI::showAll() {
	//Project* proj = serv.getAll();
	for (int i = 0; i < s.getSize(); i++)
		cout << s.getItemFromPos(i).getGitPath()<<" "<< s.getItemFromPos(i).getNoOfBranches()<<" "<< s.getItemFromPos(i).getTotalNoOfCommits()<< endl;
}

void UI::undoProj(){
	int rez = s.undoList();
	if (rez == 0) cout << "The undo was successfull!" << endl;
	else cout << "can't undo" << endl;
}
void UI::updateProj() {
	Project proj;
	cout << "Give the Project you want to update:";
	cin >> proj;
	cout << "Give the Project data:" << endl;
	char* gp = new char[10];	
	int b;
	int c;
	int rez = s.findOne(proj);
	if (rez >= 0) {
		cout << "path: ";
		cin >> gp;
		cout << "branches: ";
		cin >> b;
		cout << "commits: ";
		cin >> c;
		s.updateProject(proj, gp, b, c);
		cout << "The project has been updated!";
	}
	else { cout << "The project has not been found!"; }
}
void UI::showFilteredProjects() {
	int b;
	int c;
	cout << "Branches: ";
	cin >> b;
	cout << "Commits:";
	cin >> c;
	Project projFilter[100];
	int m=0;
	s.filterProjects(b,c,projFilter, m);
	for (int i = 0; i < m; i++)
	{
		cout << projFilter[i] << endl;
	}
}
void UI::deleteProjectsWithBC()
{
	s.deleteProjectsWithCommitsAndBranchesArray();
}

void UI::showUI()
{
	bool gata = false;
	while (!gata) {
		cout << endl;
		cout << "OPTIONS: " << endl;
		cout << "	1. Add Project " << endl;
		cout << "	2. Search Project " << endl;
		cout << "	3. Delete Project " << endl;
		cout << "	4. Update Project " << endl;
		cout << "	5. Show Projects " << endl;
		cout << "	6. DeleteProjects with branches and commits =0 " << endl;
		cout << "	7. Filter Projects after branches and commits " << endl;
		cout << "	8. UNDO" << endl;
		cout << "	0. EXIT!" << endl;
		cout << "option: (give the number):  ";
		int opt;
		cin >> opt;
		cout <<endl;
		switch (opt) {
		case 1: {addProj(); break; }
		case 2: {findProj(); break; }
		case 3: {delProj(); break; }
		case 4: {updateProj(); break; }
		case 5: {showAll(); break; }
		case 6: {deleteProjectsWithBC(); break; }
		case 7: {showFilteredProjects(); break; }
		case 8: {undoProj(); break; }
		case 0: {gata = true; cout << "BYE BYE..." << endl; }
		}
	}
}
UI::~UI()
{

}
