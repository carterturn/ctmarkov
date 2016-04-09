/*
  Copyright 2015 Carter Turnbaugh

  This file is part of Terca C++ Markov.

  Terca C++ Markov is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.

  Terca C++ Markov is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with Terca C++ Markov.  If not, see <http://www.gnu.org/licenses/>.
*/

#include <iostream>
#include "ctmarkovchain.h"

using namespace std;

int main(int argc, char* argv[]){
	
	markovchain chain;
	
	chain.addnode("a");
	chain.addnode("b");
	chain.addnode("c");
	chain.addnode("d");
	
	chain.addlink("a", "b");
	chain.addlink("a", "c");
	chain.addlink("b", "b");
	chain.addlink("b", "b");
	chain.addlink("b", "c");
	chain.addlink("c", "d");
	chain.addlink("c", "d");
	chain.addlink("c", "a");
	chain.addlink("d", "d");
	chain.addlink("d", "d");
	chain.addlink("d", "a");
	vector<string> result = chain.walk("a", 5);
	
	for(int i = 0; i < result.size(); i++){
		cout << result[i] << " ";
	}

	cout << "\n";
	dualmarkovchain dualchain;

	dualchain.addnode("a");
	dualchain.addnode("b");
	dualchain.addnode("c");
	dualchain.addnode("d");

	dualchain.addforwardlink("a", "b");
	dualchain.addforwardlink("a", "b");
	dualchain.addforwardlink("a", "b");
	dualchain.addforwardlink("a", "b");
	dualchain.addforwardlink("a", "b");
	dualchain.addforwardlink("a", "b");
	dualchain.addforwardlink("a", "b");
	dualchain.addforwardlink("a", "c");
	dualchain.addforwardlink("b", "c");
	dualchain.addforwardlink("b", "c");
	dualchain.addforwardlink("c", "c");
	
	dualchain.addreverselink("c", "a");
	dualchain.addreverselink("c", "a");
	dualchain.addreverselink("c", "b");
	dualchain.addreverselink("c", "b");
	dualchain.addreverselink("b", "a");
	dualchain.addreverselink("a", "c");

	vector<string> forwardresult = dualchain.walkforward("a", 4);
	vector<string> reverseresult = dualchain.walkreverse("a", 4);
	
	result = reverseresult;
	for(int i = 0; i < result.size(); i++){
		cout << result[i] << " ";
	}
	cout << "a ";

	result = forwardresult;
	for(int i = 0; i < result.size(); i++){
		cout << result[i] << " ";
	}
	cout << "\n";
	
	return 0;
}
