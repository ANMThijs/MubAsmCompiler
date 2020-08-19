#pragma once
#pragma warning(disable : 4996)

#include "Line.h"
#include "Register.h"

void Compile(const char* Filename);

void DeleteComments(FILE* file);