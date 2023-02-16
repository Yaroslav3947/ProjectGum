#pragma once

#include <Kohut.hpp>

#include <string.h>

void showOptions();
int getOption();
void isNormalTemperature(double &temperature);
void isNormalYearOfBirth(int &yearOfBirth);
void isNormalHemoglobin(double &hemoglobin);
void sortByGender(std::vector<Patient> &patients, int size);