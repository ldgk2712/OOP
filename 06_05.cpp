#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Professor;
class Student;

class Student {
private:
    string id;
    string name;
    vector <Professor*> professors;
public:
    // getters and setters
    string getId() {
        return this->id;
    }
    void setId(string id) {
        this->id = id;
    }
    string getName() {
        return this->name;
    }
    void setName(string name) {
        this->name = name;
    }
    // constructors
    Student(string id, string name) {
        this->setId(id);
        this->setName(name);
    }
    Student(): Student("NA", "NA") {
    }
    // display information about the student
    void display(){
        cout << "Student:\n";
        cout << " - id: " << this->getId() << "\n";
        cout << " - name: " << this->getName() << "\n";
    }

    // registerThesis
    // do ham addStudent cua Professor chua khai bao truoc nen ta se khai bao sau cung
    void registerThesis(Professor *professor);

    // display professors
    void displayProfessors(); // do ham display cua Professor chua khai bao truoc nen ta se khai bao sau cung

    // destructor
    ~Student(){
        delete (this);
    }
};

class Professor {
private:
    string name;
    vector <Student*> students;
public:
    // getters and setters
    string getName() {
        return this->name;
    }
    void setName(string name) {
        this->name = name;
    }
    // constructors
    Professor(string name) {
        this->setName(name);
    }
    Professor(): Professor("NA") {
    }
    // display information about the professor
    void display(){
        cout << "Professor:\n";
        cout << " - name: " << this->getName() << "\n";
    }

    // add student
    void addStudent(Student *student){
        this->students.push_back(student);
    }

    // display students
    void displayStudents(){
        cout << "List of Students is being guided by " << this->getName() << ":\n";
        for (auto student: this->students) {
            student->display();
        }
    }

    // destructor
    ~Professor(){
        delete (this);
    }
};

// registerThesis
void Student::registerThesis(Professor *professor){
    this->professors.push_back(professor);
    professor->addStudent(this);
}

// displayProfessors
void Student::displayProfessors(){
    cout << "List of Professors is guiding " << this->getName() << ":\n";
    for (auto professor: this->professors) {
        professor->display();
    }
}

int main(){
    // Tao 3 sinh vien
    Student *s1 = new Student("001", "Gia Khanh");
    Student *s2 = new Student("002", "Nguyen Khang");
    Student *s3 = new Student("003", "Minh Khoa");
    // Tao 2 giang vien
    Professor *p1 = new Professor("Dr. Thao");
    Professor *p2 = new Professor("Dr. Binh");

    // Cho 2 sinh vien dau tien dang ki khoan luan voi 2 giang vien
    s1->registerThesis(p1);
    s1->registerThesis(p2);
    s2->registerThesis(p1);
    s2->registerThesis(p2);

    // Cho sinh vien thu 3 dang ki khoan luan voi giang vien thu 2
    s3->registerThesis(p2);

    // Hien thi thong tin cua cac sinh vien va danh sach cac giang vien dang huong dan sinh vien do.
    s1->display();
    s1->displayProfessors();
    cout << endl;

    s2->display();
    s2->displayProfessors();
    cout << endl;

    s3->display();
    s3->displayProfessors();
    cout << endl;

    // Hien thi thong tin cua cac giang vien va danh sach cac sinh vien dang duoc huong dan boi giang vien do.
    p1->display();
    p1->displayStudents();
    cout << endl;

    p2->display();
    p2->displayStudents();

    return 0;
}