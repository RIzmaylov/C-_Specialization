#include <iostream>

using namespace std;

struct Specialization {
    explicit Specialization(string some_string) : spec(some_string) {}
    string spec;
};

struct Course {
    explicit Course(string some_string) : spec(some_string) {}
    string spec;
};

struct Week {
    explicit Week(string some_string) : spec(some_string) {}
    string spec;
};

struct LectureTitle {
    LectureTitle(Specialization spec_, Course course_, Week week_) : specialization(spec_.spec), course(course_.spec), week(week_.spec) {}
    string specialization;
    string course;
    string week;
};

int main()
{
//    LectureTitle title(
//        Specialization("C++"),
//        Course("White belt"),
//        Week("4th")
//    );
//    LectureTitle title("C++", "White belt", "4th");
//    LectureTitle title(string("C++"), string("White belt"), string("4th"));
//    LectureTitle title = {"C++", "White belt", "4th"};
//    LectureTitle title = {{"C++"}, {"White belt"}, {"4th"}};
//    LectureTitle title(
//    Course("White belt"),
//    Specialization("C++"),
//    Week("4th")
//);
//LectureTitle title(
//    Specialization("C++"),
//    Week("4th"),
//    Course("White belt")
//);
    return 0;
}
