
#include "CourseOfferings.cpp"
int main(){
  Course c("CSCE197", "Introduction to Quidditch");
  CourseOfferings object (c, 2020, 'A');
  Section s1("201", "n/a", "web-based", "Harry Potter");
  Section s2("202", "n/a", "web-based", "Luna Lovegood");
  object.addSection(s1);
  object.addSection(s2);
  CourseOfferings other;
  Section s3("203", "n/a", "web-based", "Hermione Granger");
  other.addSection(s3);
  object = other;

  cout<<(object.getYear() == other.getYear())<<endl;
  cout<<(object.getSemester() == other.getSemester())<<endl;
  cout<<(object.getSectionListCapacity() == other.getSectionListCapacity())<<endl;
  cout<<(object.getNumberSections() == other.getNumberSections())<<endl;
  cout<<(object == other)<<endl; // now check everything
  cout<<(object.getSectionList() == other.getSectionList())<<endl;
  cout<<(object.getNumberSections() == 1)<<endl;
}
