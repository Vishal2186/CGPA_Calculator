#include<iostream>
#include<vector>
using namespace std;

class subject
{
    public:
    string subjectname;
    int credit;
    float gradepoint;

    subject(string name, int cr, float gp)
    {
        subjectname = name;
        credit = cr;
        gradepoint = gp;
    }

};

class student
{
    public :
    string name;
    vector<subject>subjects;

    student(string studentName)
    {
        name = studentName;
    }

    void addsubject(string subjectName, int credit ,float gradepoint)
    {
        subject newSubject(subjectName,credit,gradepoint);
        subjects.push_back(newSubject);
    }

    float calculatecgpa()
    {
        int totalcredit = 0;
        float weightgradepoint = 0;
        for(const subject & subject : subjects)
        {
            totalcredit += subject.credit;
            weightgradepoint += subject.credit * subject.gradepoint;
        }
        return ( totalcredit > 0 )?(weightgradepoint/totalcredit) : 0;
    }

    void displaycgpa()
    {
        cout<<"Student Name = "<<name<<endl;
        float cgpa = calculatecgpa();
        cout<<"CGPA = "<<cgpa<<endl;
    }

    // void addsubject(string subjectname, int credit, float gradepoint);
    
};


int main()
{
    string studentname;
    int num_sub;

    cout<<"Enter student name = ";
    getline(cin,studentname);

    cout<<"Enter the number of subjects = ";
    cin>>num_sub;
    student student(studentname);
    for (int i = 0; i < num_sub; i++)
    {
        string subjectname;
        int credit;
        float gradepoint;

        cout<<"Enter the subjects name = ";
        cin.ignore();
        getline(cin,subjectname);

        cout<<"Enter the credits = ";
        cin>>credit;

        cout<<"Enter the grade points = ";
        cin>>gradepoint;
        student.addsubject(subjectname , credit , gradepoint);
    }
    
    student.displaycgpa();

    return 0;
}