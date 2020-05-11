#pragma once
#include "ServiceArray.h"
class UI {
private:
	ServiceArray s;
public:
	UI(ServiceArray&s);
	void addProj();
	void findProj();
	void showUI();
	void delProj();
	void showAll();
	void undoProj();
	void updateProj();
	void showFilteredProjects();
	void deleteProjectsWithBC();
	~UI();
};