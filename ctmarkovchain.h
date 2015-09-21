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

#pragma once
#include <vector>
#include "ctmarkovnode.h"

class markovchain {
public:
	markovchain();
	~markovchain();
	
	int addnode(std::string node);
	int addlink(std::string node, std::string nextnode);
	
	std::vector<std::string> walk(std::string start, int steps);
	std::vector<std::string> walkuntil(std::string start, std::string end);
	int test(); // deprecated, use only for debugging
	
	markovnode* getnode(std::string nodename);
	
private:
	std::vector<markovnode> nodes;
	
	int getindex(std::string nodename);
};
