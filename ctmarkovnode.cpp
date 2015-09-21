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

#include <cstdlib>
#include <ctime>
#include "ctmarkovnode.h"

using namespace std;

markovnode::markovnode(string name){
	id = name;
	srand(time(NULL));
}
markovnode::~markovnode(){}

//Returns 1 if node probabilty increased, 2 if node added
int markovnode::appendnode(markovnode *node){
	
	for(int i = 0; i < nextnodes.size(); i++){
		if(nextnodes[i].node->getname() == node->getname()){
			nextnodes[i].prob++;
			return 1;
		}
	}
	
	nextnode newnode;
	
	newnode.node = node;
	newnode.prob = 1;
	
	nextnodes.push_back(newnode);
	
	return 2;
}

markovnode *markovnode::getnext(){
	vector<int> nodes;
	
	for(int i = 0; i < nextnodes.size(); i++){
		for(int j = 0; j < nextnodes[i].prob; j++){
			nodes.push_back(i);
		}
	}
		
	if(nodes.size() > 0 && nextnodes.size() > 0) return nextnodes[nodes[rand()%nodes.size()]].node;
	else{
		cout << "No nodes or no next nodes\n";
		return this;
	}
}

markovnode *markovnode::getbest(){
	int bestprobid = 0;
	int bestprob = nextnodes[bestprobid].prob;
	
	for(int i = 0; i < nextnodes.size(); i++){
		if(nextnodes[i].prob > bestprob){
			bestprob = nextnodes[i].prob;
			bestprobid = i;
		}
	}
	
	return nextnodes[bestprobid].node;
}

string markovnode::getname(){
	return id;
}
