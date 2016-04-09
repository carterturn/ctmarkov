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

#include "ctmarkovchain.h"

using namespace std;

int dualmarkovchain::addnode(string node){
		forward.addnode(node);
		reverse.addnode(node);

		return 0;
}

int dualmarkovchain::addforwardlink(string node, string nextnode){
		forward.addlink(node, nextnode);

		return 0;
}

int dualmarkovchain::addreverselink(string node, string nextnode){
		reverse.addlink(node, nextnode);

		return 0;
}

vector<string> dualmarkovchain::walkforward(string start, int steps){
		return forward.walk(start, steps);
}

vector<string> dualmarkovchain::walkforwarduntil(string start, string end){
		return forward.walkuntil(start, end);
}

vector<string> dualmarkovchain::walkreverse(string start, int steps){
		return reverse.walk(start, steps);
}

vector<string> dualmarkovchain::walkreverseuntil(string start, string end){
		return reverse.walkuntil(start, end);
}
