#pragma once

#include <string>
#include <fstream>
#include <iostream>
#include <algorithm>
#include "Book.h"

Book* parseBookFromFile(std::ifstream& file);
