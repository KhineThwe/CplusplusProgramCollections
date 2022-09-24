//
// Created by Khine on 9/24/2022.
//
#include "iostream"
using namespace std;
class Student{
private:
    int rollName;
    string name;
    int mathMarks;
    int phyMarks;
    int chemMarks;
public:
    Student(int r,string n,int m,int p,int c){
        rollName = r;
        name = n;
        mathMarks = m;
        phyMarks = p;
        chemMarks = c;
    }
    int total(){
        return (mathMarks + phyMarks + chemMarks);
    }
    char grade(){
        float avg = total()/3;
        if (avg > 60)
        {
            return 'A';
        }
        else if (avg >= 40 && avg < 60)
        {
            return 'B';
        }
        else
        {
            return 'C';
        }
    }
};
int main(){
    int roll;
    string name;
    int m, p, c;
    cout << "Enter Roll number of a Student: ";
    cin >> roll;
    cout << "Enter name of the Student: ";
    cin >> name;
    cout << "Enter marks for maths, phy & chem respectively: ";
    cin >> m >> p >> c;
    Student std(roll,name,m,p,c);
    cout << "Total Marks: " << std.total() << endl;
    cout << "Grade :"<<std.grade()<<endl;
    return 0;
}
