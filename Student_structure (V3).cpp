#include <iostream>
#include<cstring>
using namespace std;

struct STUDENT
{
    char surname[20];
    char initial_name, initial_patronymic;
    int group_numb;
    float grades[5];

    void create(char surn[], char name_init, char patr_init, int group, float grade[])
    {
        
        for (int i = 0;i < strlen(surn);i++)
        {
            surname[i] = surn[i];
        }

        for (int i = strlen(surn);i < strlen(surname);i++)
        {
            surname[i] = NULL;
        }
        
        

        initial_name = name_init;
        initial_patronymic = patr_init;
        group_numb = group;
        
        for (int i = 0;i < 5;i++)
        {
            grades[i] = grade[i];
        }
    }

    char* readStudent()
    {
        int surn_len = strlen(surname);
        
        
        
        char* answer_full_name = new char[surn_len + 3];
        for (int i = surn_len + 3;i < strlen(answer_full_name);i++)
        {
            answer_full_name[i] = NULL;
        }
        
        for (int i = 0;i < surn_len;i++)
        {
            answer_full_name[i] = surname[i];
        }

        answer_full_name[surn_len] = 32;
        answer_full_name[surn_len + 1] = initial_name;
        answer_full_name[surn_len + 2] = initial_patronymic;

        return answer_full_name;
    }

    void update_group_and_grades(int new_gr, float new_grades[])
    {
        group_numb = new_gr;
        
        for (int i = 0;i < 5;i++)
        {
            grades[i] = new_grades[i];
        }
    }

    void to_annul()
    {
        for (int i = 0;i < 20;i++)
        {
            surname[i] = NULL;
        }
        initial_name = NULL;
        initial_patronymic = NULL;
        group_numb = NULL;
        for (int i = 0;i < 5;i++)
        {
            grades[i] = NULL;
        }
    }
};

void alph_sort(STUDENT st_arr[], int numb_of_st)
{
    for (int i = 0;i < numb_of_st - 1;i++)
    {
        for (int j = i; j < numb_of_st;j++)
        {
            if (strcmp(st_arr[i].surname, st_arr[j].surname) > 0)
            {
                swap(st_arr[i], st_arr[j]);
            }
        }
    }
}

int main()
{
    
    int numb_of_students;
    cout << "enter the number of the students: ";
    cin >> numb_of_students;
    cout << endl;
    STUDENT* the_students = new STUDENT[numb_of_students];
    
    for (int i = 0;i < numb_of_students;i++)
    {
        cout << "THE STUDENT n." << i + 1 << ":" << endl;

        char temp_surname[20];
        cout << "enter the student's surname: " << endl;
        cin >> temp_surname;
        //cin.getline(temp_surname, 20);
        

        char name_letter_temp;
        cout << "enter the first letter of the student's name: " << endl;
        cin >> name_letter_temp;

        char patronymic_lett_temp;
        cout << "enter the first letter of the student's patronumic: " << endl;
        cin >> patronymic_lett_temp;

        int temp_group;
        cout << "enter the student's group number: " << endl;
        cin >> temp_group;

        float temp_grades[5];
        cout << "enter the academic success of the student by 5 grades: " << endl;
        for (int l = 0;l < 5;l++)
        {
            cin >> temp_grades[l];
        }
        the_students[i].create(temp_surname, name_letter_temp, patronymic_lett_temp, temp_group, temp_grades);

        cout << "----------------------------" << endl;;
    }

    alph_sort(the_students, numb_of_students);
    
    
    for (int i = 0;i < numb_of_students;i++)
    {
        
        char* the_full_name = the_students[i].readStudent();

        for (int l = 0;l < strlen(the_full_name);l++)
        {
            cout << the_full_name[l];
        }
        cout << endl;
    }
    
    
    return 0;
}
