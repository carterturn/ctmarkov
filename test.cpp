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

#include <iostream>
#include "ctmarkovchain.h"

using namespace std;

int main(int argc, char* argv[]){
	
	markovchain chain;
	
	chain.addnode("a");
	chain.addnode("b");
	chain.addnode("c");
	chain.addnode("d");
	
	chain.addlink("a", "a");
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
	vector<string> result = chain.walk("a", 5000);
	
	for(int i = 0; i < result.size(); i++){
		cout << result[i] << " ";
	}
	
	chain.test();
	
	return 0;
}
