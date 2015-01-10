#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;
struct TeacherData{
	char name[10];
	struct linker *linkerpt;
	struct TeacherData *next;
};
struct ClassData{
	char name[10];
	struct ClassData *next;
	struct CourseData *course;
};
struct CourseData{
	char name[20];
	char score;
	char hours;
	struct TeacherData *teacherpt;
	struct ClassData *classpt;
	struct CourseData *next;
};
struct linker{
	struct CourseData *course;
	struct linker *next;
};
struct TeacherData *teacherhead = NULL;
struct ClassData *classhead = NULL;
struct CourseData *coursehead = NULL;
struct TeacherData *teacherprevious;
struct ClassData *classprevious;
struct CourseData *courseprevious;
struct linker *linkerprevious;
int main(){
	ifstream in("data.txt");
	char tenchar[10];
	char twentychar[20];
	int course;
	in >> tenchar;
	while (strcmp(tenchar,"end")){
		TeacherData *teachercurrent = new TeacherData;
		strcpy(teachercurrent->name, tenchar);
		teachercurrent->next = NULL;
		teachercurrent->linkerpt = NULL;
		if (teacherhead == NULL)
			teacherhead = teachercurrent;
		else
			teacherprevious->next = teachercurrent;
		teacherprevious = teachercurrent;
		in >> tenchar;
	}
	in >> tenchar;
	while (strcmp(tenchar, "end")){
		ClassData *classcurrent = new ClassData;
		strcpy(classcurrent->name, tenchar);
		classcurrent->next = NULL;
		if (classhead == NULL)
			classhead = classcurrent;
		else
			classprevious->next = classcurrent;
		classprevious = classcurrent;
		in >> tenchar;
	}
	TeacherData *teachercurrent = new TeacherData;
	ClassData *classcurrent = new ClassData;
	int teacherid, classid, i;
	in >> twentychar;
	while (strcmp(twentychar, "end")){
		CourseData *coursecurrent = new CourseData;
		strcpy(coursecurrent->name, twentychar);
		in >> coursecurrent->score;
		in >> coursecurrent->hours;
		in >> teacherid;
		teachercurrent = teacherhead;
		for (i = 0; i < teacherid-1; i++)
			teachercurrent = teachercurrent->next;
		coursecurrent->teacherpt = teachercurrent;
		linker *linkercurrent = new linker;
		if (teachercurrent->linkerpt == NULL){
			teachercurrent->linkerpt = linkercurrent;
			linkercurrent->course = coursecurrent;
			linkercurrent->next = NULL;
		}
		else{

			linkercurrent = teachercurrent->linkerpt;
			while (linkercurrent!= NULL){
				linkerprevious = linkercurrent;
				linkercurrent = linkercurrent->next;
			}
			linker *linkercurrent = new linker;
			linkercurrent->course = coursecurrent;
			linkercurrent->next = NULL;
			linkerprevious->next = linkercurrent;
			
		}
		in >> classid;
		classcurrent = classhead;
		for (i = 0; i < classid-1; i++)
			classcurrent = classcurrent->next;
		coursecurrent->classpt = classcurrent;
		classcurrent->course = coursecurrent;
		coursecurrent->next = NULL;
		if (coursehead == NULL)
			coursehead = coursecurrent;
		else
			courseprevious->next = coursecurrent;
		courseprevious = coursecurrent;
		in >> twentychar;
	}
	teachercurrent = teacherhead;
	classcurrent = classhead;
	CourseData *coursecurrent = coursehead;
	cout << setw(21) << "Course name" << setw(6) << "hours" << setw(6) << "score" << setw(13) << "Teacher name" << setw(11) << "Class name" << endl;
	while (teachercurrent != NULL){
		while (teachercurrent->linkerpt!=NULL){
			cout << setw(21) << teachercurrent->linkerpt->course->name << setw(6) << teachercurrent->linkerpt->course->hours << setw(6) << teachercurrent->linkerpt->course->score << setw(13) << teachercurrent->name << setw(11) << teachercurrent->linkerpt->course->classpt->name << endl;
			teachercurrent->linkerpt = teachercurrent->linkerpt->next;
		}
		teachercurrent = teachercurrent->next;
	}
	system("pause");
}