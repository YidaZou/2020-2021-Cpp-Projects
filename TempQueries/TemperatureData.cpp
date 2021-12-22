/*
 * TemperatureData.cpp
 *
 *  Created on: Jul 16, 2018
 *      Author: student
 */
#include <string>
#include <iostream>
#include "TemperatureData.h"
using namespace std;

TemperatureData::TemperatureData(): id(""), year(0), month(0), temperature(0) {} //initialize everything

TemperatureData::TemperatureData(std::string id, int year, int month, double temperature): id(id), year(year), month(month), temperature(temperature) {} //initialize everything


TemperatureData::~TemperatureData() {} // You should not need to implement this

bool TemperatureData::operator<(const TemperatureData& b) {
	// Implement this
  //cout<<"! '<' used"<<endl;
  if(id<b.id){
    return true;
  }else if(id>b.id){
    return false;
  }
  if(year<b.year){
    return true;
  }else if(year>b.year){
    return false;
  }
  if(month<b.month){
    return true;
  }else if(month>b.month){
    return false;
  }
  return true;
}
