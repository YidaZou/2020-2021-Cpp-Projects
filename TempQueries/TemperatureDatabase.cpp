#include "TemperatureDatabase.h"

#include <fstream>
#include <sstream>
using namespace std;

// Default constructor/destructor. Modify them if you need to.
TemperatureDatabase::TemperatureDatabase(): records() {}
TemperatureDatabase::~TemperatureDatabase() {}

void TemperatureDatabase::loadData(const string& filename) {
	// Implement this function for part 1
	ifstream ifs (filename);
  if (!ifs.is_open()) {
    cout<<"Error: Unable to open "<< filename;
  }
  string line;
  string id;
	int year, month;
	double temp;
  while(!ifs.eof()){
		getline(ifs,line);
		//cout<<"##!loop check! "<<line<<endl;
    if(line==""){
      break;
    }
		istringstream data(line);
		/*
		while(data.size()!=4){
			cout<<"Error: Other invalid input"
			getline(ifs,line);
	    if(line==""){
	      break;
	    }
			istringstream data(line);
		}
		if(line==""){
			break;
		}
		*/
    data>>id>>year>>month>>temp;
		if(year>2021 || year<1800){
			cout<<"Error: Invalid year "<<year<<endl;
		}else if(month>12 || month<1){
			cout<<"Error: Invalid month "<<month<<endl;
		}else if(temp>50 || temp<-50){
			cout<<"Error: Invalid temperature "<<temp<<endl;
		}else{
			//cout<<"!!!inserting"<<endl;
			records.insert(id,year,month,temp);
		}
  }
}

// Do not modify
void TemperatureDatabase::outputData(const string& filename) {
	ofstream dataout("sorted." + filename);

	if (!dataout.is_open()) {
		cout << "Error: Unable to open " << filename << endl;
		exit(1);
	}
	dataout << records.print();
}

void TemperatureDatabase::performQuery(const string& filename) {
	// Implement this function for part 2
	ifstream ifs (filename);
  if (!ifs.is_open()) {
    cout<<"Error: Unable to open "<< filename;
  }
  string line, id1, type;
	int year1, year2;
	double avg, mode;
	double sum=0;
	int count=0;
	ostringstream avgStream;
	string avgOut;
	Node* m = nullptr;

	ofstream dataout("result.dat");
	if (!dataout.is_open()) {
		cout << "Error: Unable to open " << filename << endl;
		exit(1);
	}

  while(!ifs.eof()){
		m = records.getHead();
		count=0;
		sum=0;
		getline(ifs,line);
    if(line==""){
      break;
    }
		istringstream data(line);
		data>>id1>>type>>year1>>year2;
		if(year2<year1){
			cout<<"Error: Invalid range "<<year1<<"-"<<year2<<endl;
		}else if(type!="AVG" && type!="MODE"){
			cout<<"Error: Unsupported query "<<type<<endl;
		}else{
			while(m!=nullptr && !(m->data.id==id1 && m->data.year==year1)){
				m=m->next;
			}
			if(type=="AVG"){
				while(m!=nullptr && (m->data.year==year2 || m->data.year==year1)){
					count++;
					sum+=m->data.temperature;
					m=m->next;
				}
				avg = sum/count;
				//cout<<sum<<" "<<count<<" "<<avg<<endl;
				avgStream.str("");
				avgStream<<noshowpoint<<(avg);
				avgOut = avgStream.str();
				if(avgOut=="-nan"){
					avgOut="unknown";
				}
				dataout<<id1<<" "<<to_string(year1)<<" "<<to_string(year2)<<" "<<type<<" "<<avgOut<<endl;
			}else if(type=="MODE"){

			}
		}
  }
	//  Leave it blank for part 1
}
