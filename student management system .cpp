#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
using namespace std;

class Student
{
private:
    string rollNumber;
    string fullName;
    string address;
    string dateOfBirth;
    string mobileNumber;
    string dateOfAdmission;
    string course;
    string emailId;

public:
    void setRollNumber(string roll)
    {
        rollNumber = roll;
    }
    void setFullName(string name)
    {
        fullName = name;
    }
    void setAddress(string addr)
    {
        address = addr;
    }
    void setDateOfBirth(string dob)
    {
        dateOfBirth = dob;
    }
    void setMobileNumber(string mobile)
    {
        mobileNumber = mobile;
    }
    void setDateOfAdmission(string admission)
    {
        dateOfAdmission = admission;
    }
    void setCourse(string crs)
    {
        course = crs;
    }
    void setEmailId(string email)
    {
        emailId = email;
    }

    string getRollNumber()
    {
        return rollNumber;
    }
    string getFullName()
    {
        return fullName;
    }
    string getAddress()
    {
        return address;
    }
    string getDateOfBirth()
    {
        return dateOfBirth;
    }
    string getMobileNumber()
    {
        return mobileNumber;
    }
    string getDateOfAdmission()
    {
        return dateOfAdmission;
    }
    string getCourse()
    {
        return course;
    }
    string getEmailId()
    {
        return emailId;
    }
};

vector<Student> student_list;

void enter()
{
    Student student;

    cout << "\n\t** Enter Student Details **" << endl;

    string roll, name, addr, dob, mobile, admission, crs, email;

    cout << "\n\tEnter Roll Number: ";
    cin >> roll;
    student.setRollNumber(roll);

    cout << "\tEnter Full Name: ";
    cin.ignore();
    getline(cin, name);
    student.setFullName(name);

    cout << "\tEnter Address: ";
    getline(cin, addr);
    student.setAddress(addr);

    cout << "\tEnter Date of Birth (DD-MM-YYYY): ";
    getline(cin, dob);
    student.setDateOfBirth(dob);

    cout << "\tEnter Mobile Number: ";
    getline(cin, mobile);
    student.setMobileNumber(mobile);

    cout << "\tEnter Date of Admission (DD-MM-YYYY): ";
    getline(cin, admission);
    student.setDateOfAdmission(admission);

    cout << "\tEnter Course: ";
    getline(cin, crs);
    student.setCourse(crs);

    cout << "\tEnter Email: ";
    getline(cin, email);
    student.setEmailId(email);

    student_list.push_back(student);

    cout << "\n\tStudent details added successfully!" << endl;
}

void show()
{
    if (student_list.empty())
    {
        cout << "\n\tNo student details found." << endl;
        return;
    }

    cout << "\n\t** ALL STUDENT DETAILS **" << endl << endl;

    cout << "==============================================================================================================================" << endl;
    cout << "|\tRoll Number\t|\t\tFull Name\t|\t\tAddress\t|\tDate of Birth\t|\tMobile Number|" << endl;
    cout << "==============================================================================================================================" << endl;

    for (auto person : student_list)
    {
        cout << "|\t" << setw(10) << person.getRollNumber() << "\t|\t" << setw(20) << person.getFullName() << "\t|\t" << setw(15) << person.getAddress() << "\t|\t" << setw(15) << person.getDateOfBirth() << "\t|\t" << setw(13) << person.getMobileNumber() << "|" << endl;
    }

    cout << "==============================================================================================================================" << endl << endl;
}

void search(string roll)
{
    bool found = false;
    for (auto person : student_list)
    {
        if (person.getRollNumber() == roll)
        {
            found = true;

            cout << "\n\t** STUDENT DETAILS **" << endl << endl;
            cout << left;
            cout << setw(25) << "\tRoll Number: " << person.getRollNumber() << endl;
            cout << setw(25) << "\tFull Name: " << person.getFullName() << endl;
            cout << setw(25) << "\tAddress: " << person.getAddress() << endl;
            cout << setw(25) << "\tDate of Birth: " << person.getDateOfBirth() << endl;
            cout << setw(25) << "\tMobile Number: " << person.getMobileNumber() << endl;
            cout << setw(25) << "\tDate of Admission: " << person.getDateOfAdmission() << endl;
            cout << setw(25) << "\tCourse: " << person.getCourse() << endl;
            cout << setw(25) << "\tEmail: " << person.getEmailId() << endl;

            break;
        }
    }

    if (!found)
    {
        cout << "Student with roll number " << roll << " not found." << endl;
    }
}

int main()
{
    int choice;
    string roll;

    while (true)
    {
        cout << "\n\t\t** STUDENT MANAGEMENT SYSTEM **" << endl;
        cout << "\n\t\t1. Enter student details";
        cout << "\n\t\t2. Show all student details";
        cout << "\n\t\t3. Search for a student";
        cout << "\n\t\t4. Exit";
        cout << "\n\n\t\tEnter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            enter();
            break;

        case 2:
            show();
            break;

        case 3:
            cout << "\n\tEnter the roll number to search: ";
            cin >> roll;
            search(roll);
            break;

        case 4:
            cout << "\n\tThank you for using the student management system. Goodbye!";
            exit(0);

        default:
            cout << "\n\tInvalid choice. Please enter a valid option.";
        }
    }

    return 0;
}
