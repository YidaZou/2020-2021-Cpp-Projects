#include <iostream>
#include <string>
#include "Course.h"
#include "Section.h"
#include "CourseOfferings.h"

using std::cout, std::endl, std::string, std::ostream;

/* TODO: Define copy constructor here. */
CourseOfferings::CourseOfferings(const CourseOfferings& o)
	: course(o.course), year(o.year), semester(o.semester), nbSections(o.nbSections), capacity(o.capacity), sectionList() {
		delete sectionList;
		sectionList = new Section[o.nbSections];
		for(size_t i=0; i<o.nbSections; i++){
			Section* a = new Section(o.sectionList[i].getId(),o.sectionList[i].getTime(), o.sectionList[i].getLocation(), o.sectionList[i].getInstructor());
			sectionList[i] = *a;
		}
	}
/* TODO: Define copy assignment operator function here. */
CourseOfferings& CourseOfferings::operator=(const CourseOfferings& o) {
	this->course = o.course;
	this->year = o.year;
	this->semester = o.semester;
	this->nbSections = o.nbSections;
	this->capacity = o.capacity;
	if(o.sectionList!=nullptr){
		//cout<<"not empty"<<endl;
		delete[] sectionList;
		sectionList = new Section[o.nbSections];
		for(size_t i=0; i<o.nbSections; i++){
			Section* a = new Section(o.sectionList[i].getId(),o.sectionList[i].getTime(), o.sectionList[i].getLocation(), o.sectionList[i].getInstructor());
			sectionList[i] = *a;
		}
	}else{
		//cout<<"is empty"<<endl;
		delete [] sectionList;
		sectionList = new Section[0];
	}
	return *this;
}
/* TODO: Define destructor here. */
CourseOfferings::~CourseOfferings(){
	delete [] sectionList;
}
/* TODO: Declare CourseOfferings extraction overload operator function here. */
std::ostream& operator<<(std::ostream& out, const CourseOfferings& o){
	cout<<"Year: "<<o.getYear()<<" Semester: "<<o.getSemester()<<" Course id: "<<o.getCourse().getId()<<endl;
	cout<<"Course title: "<<o.getCourse().getTitle()<<endl;
	cout<<"Sections:"<<endl;
	for(size_t i=0; i<o.getNumberSections(); i++){
		cout<<o.getSectionList()[i].getId()<<" "<<o.getSectionList()[i].getTime()<<" "<<o.getSectionList()[i].getLocation()<<" "<<o.getSectionList()[i].getInstructor()<<endl;
	}
	return out;
}

CourseOfferings::CourseOfferings(Course course, unsigned int year, char semester)
	: course(course), year(year), semester(semester), nbSections(0), capacity(0), sectionList(nullptr) { }

CourseOfferings::CourseOfferings(unsigned int year, char semester, const CourseOfferings& other)
	: CourseOfferings(other) {
	this->year = year;
	this->semester = semester;
}

void CourseOfferings::addSection(const Section& section) {
	if (nbSections == capacity) {
		increaseSectionListCapacity();
	}
	sectionList[nbSections++] = section;
}

void CourseOfferings::increaseSectionListCapacity() {
	// increase capacity
	capacity = capacity == 0 ? 1 : capacity * 2;
	if (capacity == 0) {
		capacity = 1;
		sectionList = new Section[1] {}; // initialize section list
	}

	// copy old contents to new contents
	Section* newSectionList = new Section[capacity];
	for (size_t i = 0; i < nbSections; ++i) {
		newSectionList[i] = sectionList[i];
	}

	// deallocate old contents
	delete[] sectionList;

	// set old contents to new contents
	sectionList = newSectionList;
}

bool operator==(const CourseOfferings& lhs, const CourseOfferings& rhs) {
	// checking year
	if (! (lhs.getYear() == rhs.getYear()
		&& lhs.getSemester() == rhs.getSemester()
		&& lhs.getCourse().getId() == rhs.getCourse().getId()
		&& lhs.getCourse().getTitle() == rhs.getCourse().getTitle()
		&& lhs.getNumberSections() == rhs.getNumberSections()
		&& lhs.getSectionListCapacity() == rhs.getSectionListCapacity())) {
		return false;
	}

	// checking sections
	for (size_t i = 0; i < lhs.getNumberSections(); i++) {
		Section ls = lhs.getSectionList()[i];
		Section rs = rhs.getSectionList()[i];
		if (!(ls.getId() == rs.getId()
				&& ls.getTime() == rs.getTime()
				&& ls.getLocation() == rs.getLocation()
				&& ls.getInstructor() == rs.getInstructor())) {
			return false;
		}
	}
	return true;
}
