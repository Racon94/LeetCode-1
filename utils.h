#pragma once

#ifndef UTILS_H
#define UTILS_H


#include <string>
#include <vector>

std::vector<std::string> split(std::string in, char p=' ');

int parseInt(std::string num);

#endif // !UTILS_H