/*
            STUDENT DETAILS MANAGEMENT SYSTEM 

                            ---BY Jitender Yadav
                            
*/


#include<iostream>
#include<windows.h>
#include<conio.h>
#include<stdio.h>
#include<fstream>
#include<stdlib.h>
#include<cstdlib>
#include<string>
#include<cstdlib>
#include<regex>

using namespace std;

class Student{
    private:
        int roll_no;
        long long int contact_no;
        string name,course,address,email_id;
    
    public:
        void addNewStudent();
        void DisplayStudents();
        void updateDetails();
        void searchStudent();
        void delete_student();
};

bool Emailcheck(string email){
    const regex pattern("(\\w+)(\\.|_)?(\\w*)@(\\w+)(\\.(\\w+))+");
    return regex_match(email, pattern);
}

void Student::addNewStudent(){
    system("cls");
    fstream file;
    cout << "\n-------------------------------------------------------------------------------------------------------" << endl;
    cout << "------------------------------------- Add Student Details ---------------------------------------------" << endl;
    cout << "\t\t\tEnter Roll No.: ";
    cin >> roll_no;
    cout << "\t\t\tEnter Name: ";
    cin >> name;
    cout << "\t\t\tEnter Course: ";
    cin >> course;
email:
    cout << "\t\t\tEnter Email Id(name@gmail.com): ";
    cin >> email_id;
    if (Emailcheck(email_id))
    {
        cout << "\t\t\t Your Email-Id is Valid" << endl;
    }
    else
    {
        cout << "\t\t\t Your Email-Id is InValid" << endl;
        goto email;
    }
contact:
    cout << "\t\t\tEnter Contact No(9639xxxxxx): ";
    cin >> contact_no;
    if (contact_no < 1000000000 || contact_no > 9999999999)
    {
        cout << "\t\t\t Please Enter Only 10 Digits..." << endl;
        goto contact;
    }
    cout << "\t\t\tEnter Address: ";
    cin >> address;
    file.open("studentRecord.txt", ios::app | ios::out);
    file << " " << roll_no << "\t\t " << name << "\t\t " << course << "\t\t " << email_id << "\t\t\t " << contact_no << "\t\t\t " << address << "\n";
    file.close();
}

void Student::DisplayStudents(){
    system("cls");
    fstream file;
    int total = 0;
    cout << "\n-------------------------------------------------------------------------------------------------------" << endl;
    cout << "------------------------------------- Student Record Table --------------------------------------------" << endl;
    file.open("studentRecord.txt", ios::in);
    if (!file){
        cout << "\n\t\t\tNo Data is Present... ";
        file.close();
    }
    else{
        file >> roll_no >> name >> course >> email_id >> contact_no >> address;
        while(!file.eof()){
            
            Sleep(300);
            cout << "\n\n\t\t\tStudent No.: " << ++total << endl;
            Sleep(100);
            cout << "\t\t\tRoll No.: " << roll_no << "\n";
            Sleep(100);
            cout << "\t\t\tName: " << name << "\n";
            Sleep(100);
            cout << "\t\t\tCourse: " << course << "\n";
            Sleep(100);
            cout << "\t\t\tEmail Id: " << email_id << "\n";
            Sleep(100);
            cout << "\t\t\tContact No.: " << contact_no << "\n";
            Sleep(100);
            cout << "\t\t\tAddress: " << address << "\n";
            Sleep(100);
            file >>  roll_no >>name >> course >> email_id >> contact_no >> address;
        }
        if (total == 0)
        {

            cout << "\n\t\t\tNo Data is Present..." << endl;
        }
    }

    file.close();
}

void Student::searchStudent(){
    system("cls");
    fstream file;
    int found = 0;
    file.open("studentRecord.txt", ios::in);
    cout << "\n-------------------------------------------------------------------------------------------------------" << endl;
    cout << "------------------------------------- Student Search Data --------------------------------------------" << endl;
    if (!file)
    {
        cout << "\n\t\t\tNo Data is Present... " << endl;
    }
    else
    {
        int rollno;
        cout << "\nEnter Roll No. of Student which you want to search: ";
        cin >> rollno;
        file >> roll_no >> name >> course >> email_id >> contact_no >> address;
        while (!file.eof())
        {
            if (rollno == roll_no)
            {
                cout << "\n\n\t\t\tName: " << name << "\n";
                cout << "\t\t\tRoll No.: " << roll_no << "\n";
                cout << "\t\t\tCourse: " << course << "\n";
                cout << "\t\t\tEmail Id: " << email_id << "\n";
                cout << "\t\t\tContact No.: " << contact_no << "\n";
                cout << "\t\t\tAddress: " << address << "\n";
                found++;
            }
            file >> roll_no >> name >> course >> email_id >> contact_no >> address;
        }
        if (found == 0)
            {
                cout << "\n\t\t\t Student Roll NO. Not Found....\n";
            }
        file.close();
    }
}

void Student::updateDetails(){
    system("cls");
    fstream file, file1;
    int rollno;
    int found = 0;
    cout << "\n-------------------------------------------------------------------------------------------------------" << endl;
    cout << "------------------------------------- Student Modify Details ------------------------------------------" << endl;
    file.open("studentRecord.txt", ios::in);
    if (!file)
    {
        cout << "\n\t\t\tNo Data is Present..";
        file.close();
    }
    else
    {
        cout << "\nEnter Roll No. of Student which you want to Modify: ";
        cin >> rollno;
        file1.open("record.txt", ios::app | ios::out);
        file >>  roll_no >> name >> course >> email_id >> contact_no >> address;
        while (!file.eof()){
            if (rollno != roll_no)
                file1 << " " << roll_no << " " << name << " " << course << " " << email_id << " " << contact_no << " " << address << "\n";
            else{
                cout << "\t\t\tEnter Roll No.: ";
                cin >> roll_no;
                cout << "\n\t\t\tEnter Name: ";
                cin >> name;
                cout << "\t\t\tEnter Course: ";
                cin >> course;
            email:
                cout << "\t\t\tEnter Email Id(name@gmail.com): ";
                cin >> email_id;
                if (Emailcheck(email_id)){
                    cout << "\t\t\t Your Email-Id is Valid" << endl;
                }
                else{
                    cout << "\t\t\t Your Email-Id is InValid" << endl;
                    goto email;
                }
            contact:
                cout << "\t\t\tEnter Contact No(9639xxxxxx): ";
                cin >> contact_no;
                if (contact_no < 1000000000 || contact_no > 9999999999){
                    cout << "\t\t\t Please Enter Only 10 Digits..." << endl;
                    goto contact;
                }
                cout << "\t\t\tEnter Address: ";
                cin >> address;
                file1 << " " << roll_no << " " << name << " " << course << " " << email_id << " " << contact_no << " " << address << "\n";
                found++;
            }
            file >> roll_no >> name >> course >> email_id >> contact_no >> address;
        }
        if (found == 0){
            cout << "\n\n\t\t\t Student Roll No. Not Found...."<<endl;
        }
        file1.close();
        file.close();
        remove("studentRecord.txt");
        rename("record.txt", "studentRecord.txt");
    }
}

void Student::delete_student() // ddeleted data of student
{
    system("cls");
    fstream file, file1;
    int found = 0;
    int roll;
    cout << "\n-------------------------------------------------------------------------------------------------------" << endl;
    cout << "------------------------------------- Delete Student Details ------------------------------------------" << endl;
    file.open("studentRecord.txt", ios::in);
    if (!file)
    {
        cout << "\n\t\t\tNo Data is Present.."<<endl;
        file.close();
    }
    else
    {
        cout << "\n\t\tEnter Roll No. of Student which you want Delete Data: ";
        cin >> roll;
        file1.open("record.txt", ios::app | ios::out);
        file >> roll_no >> name >> course >> email_id >> contact_no >> address;
        while (!file.eof())
        {
            if (roll != roll_no)
            {
                file1 << " " << roll_no << " " << name << " " << course << " " << email_id << " " << contact_no << " " << address << "\n";
            }
            else
            {
                found++;
                cout << "\n\t\t\tSuccessfully Delete Data"<<endl;
            }
            file >> roll_no >> name >> course >> email_id >> contact_no >> address;
        }
        if (found == 0)
        {
            cout << "\n\t\t\t Student Roll NO. Not Found...."<<endl;
        }
        file1.close();
        file.close();
        remove("studentRecord.txt");
        rename("record.txt", "studentRecord.txt");
    }
}

void intro(){
    system("cls");
    system("color f4");
    cout << "\n\n\n";
    Sleep(300);
    cout << "\t\t\t\t *     *  **** *      ****  ***   * * *   ****   " << endl;
    Sleep(300);
    cout << "\t\t\t\t *     * *     *     *     *   * *  *  * *        "<< endl;
    Sleep(300);
    cout << "\t\t\t\t *  *  * ***** *     *     *   * *  *  * *****    " << endl;
    Sleep(300);
    cout << "\t\t\t\t *  *  * *     *     *     *   * *     * *         " << endl;
    Sleep(300);
    cout << "\t\t\t\t  * * *   **** *****  ****  ***  *     *  ****     " << endl;
    Sleep(300);
    cout<<endl;
    cout<<"\t\t\t\t============================================="<<endl;
    Sleep(500);
    cout<<"\t\t\t\t\tTHIS IS STUDENT MANEGEMENT SYSTEM"<<endl;
    Sleep(500);
    cout<<"\t\t\t\t============================================="<<endl;
    Sleep(500);
    cout<<"\t\t\t\tpress any key to continue...";
    cin.ignore();
    cin.get();
}

int main(){
    Student students;
    intro();

    char choice;
    do{
        system("cls");
        system("color f3");
        cout<<"\n\n";
        Sleep(300);
        cout<<"\t====================STUDENT DETIALS MANEGEMENT SYSTEM===================="<<endl;
        cout<<endl;

        int option;
        Sleep(200);
        cout<<"\t\t\t\t 1. Add New Student "<<endl;
        Sleep(200);
        cout<<"\t\t\t\t 2. Display All Students "<<endl;
        Sleep(200);
        cout<<"\t\t\t\t 3. Search Student "<<endl;
        Sleep(200);
        cout<<"\t\t\t\t 4. Update Student Details "<<endl;
        Sleep(200);
        cout<<"\t\t\t\t 5. Delete Student "<<endl;
        Sleep(200);
        cout<<"\t\t\t\t 6. Exit "<<endl;
        Sleep(200);
        cout<<"\t\t\t\t Enter your choice : ";
        cin>>option;
        switch(option){
            //for adding new studnets.
            case 1:
                students.addNewStudent();
                break;

            //Displaying all students...
            case 2:
                students.DisplayStudents();
                break;

             //for searching a student..
            case 3:
                students.searchStudent();
                break;

            //for modifying/update details of students 
            case 4:
            students.updateDetails();
            break;
            
            //for deleting the details of the students
            case 5:
            	students.delete_student();
				break;
				          
			// to exit the program  
            case 6:
                exit(1);
                
            default:
            	cout<<"\t\t\t\tInvalid Option..."<<endl;
            	break;
        }

        cout<<"\t\t\t\tDo you Want to continue? [Yes/No] : ";
        cin>>choice;
    }while (choice=='y' || choice=='Y');
    
    
    return 0;
}
