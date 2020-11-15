#include <iostream>
using namespace std;

struct STUDENT
{
    char surname[20];
    char initial_name, initial_patronymic;
    int group_numb;
    float grades[5];

    void create(char surn[], char name_init, char patr_init, int group, float grade[])
    {
        cout << "creating";
        for (int i = 0;i < 20;i++)
        {
            surname[i] = surn[i];
            if (surname[i] == 32)
                break;
        }

        initial_name = name_init;
        initial_patronymic = patr_init;
        group_numb = group;
        
        for (int i = 0;i < 5;i++)
        {
            grades[i] = grade[i];
        }
    }

    char* readStudent( int &answer_len)
    {
        int surn_len = 0;
        for (int i = 0;i < 20;i++)
        {
            if (surname[i] == 32 || surname[i] == NULL)
            {
                break;
            }
            surn_len++;
        }
        
        
        char* answer_full_name = new char[surn_len + 3];
        answer_len = surn_len + 3;
        for (int i = 0;i < surn_len;i++)
        {
            answer_full_name[i] = surname[i];
        }

        answer_full_name[surn_len] = 32;
        answer_full_name[surn_len + 1] = initial_name;
        answer_full_name[surn_len + 2] = initial_patronymic;

        return answer_full_name;
    }

    void update_group_grades(int new_gr, float new_grades[])
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



int main()
{
	return 0;	
}
