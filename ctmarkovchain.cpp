/*
  Copyright 2015 Carter Turnbaugh

  This file is part of Terca C++ Vector.

  Terca C++ Vector is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.

  Terca C++ Vector is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with Terca C++ Vector.  If not, see <http://www.gnu.org/licenses/>.
*/

#include "ctmarkovchain.h"
#include <iostream>
using namespace std;

markovchain::markovchain(){}
markovchain::~markovchain(){}

int markovchain::addnode(string node){
	markovnode newnode(node);
	nodes.push_back(newnode);
	return 0;
}

int markovchain::addlink(string node, string nextnode){
	int index = getindex(node);
	if(index == -1){
		return -1;
	}
	
	int nextindex = getindex(nextnode);
	if(getindex(nextnode) == -1){
		return -2;
	}
	
	nodes[index].appendnode(&nodes[nextindex]);
	
	return 0;
}

vector<string> markovchain::walk(string start, int steps){
	int startindex = getindex(start);
	vector<string> visited;
	markovnode *node = &nodes[startindex];
	
	for(int i = 0; i < steps; i++){
		node = node->getnext();
		visited.push_back(node->getname());
	}
	return visited;
}

vector<string> markovchain::walkuntil(string start, string end){
	int startindex = getindex(start);
	
	vector<string> visited;
	
	markovnode *node = &nodes[startindex];
	
	bool done = false;
	while(!done){
		node = node->getnext();
		done = node->getname() == end;
		visited.push_back(node->getname());
	}
	
	return visited;
}

markovnode* markovchain::getnode(string name){
	for(int i = 0; i < nodes.size(); i++){
		if(name == nodes[i].getname()) return &nodes[i];
	}
	
	return NULL;
}

int markovchain::getindex(string name){
	for(int i = 0; i < nodes.size(); i++){
		if(name == nodes[i].getname()) return i;
	}
	
	return -1;
}

int markovchain::test(){
	cout << "\n\n";
	for(int i = 0; i < nodes.size(); i++){
		cout << nodes[i].getname() << "\n";
	}
	
	return 0;
}
