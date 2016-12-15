#include <iostream>
#include <cstdint>
#include <stdlib.h>
#include <stddef.h>
#include <cstring>

struct Stud
    {
	char name[16];
	int god;
	double ball;
	uint8_t pol : 1;
	int N_kurs;
    Stud *star;
};
bool proverka(char* name);
void print_in_hex(uint8_t byte);
void print_in_hex(const void* data, size_t size);
void print_in_binary(uint8_t byte);
void print_in_binary(const void* data, size_t size);

char convert_in_hex(std::string a) {
    if (a == "0000") return '0';
    if (a == "0001") return '1';
    if (a == "0010") return '2';
    if (a == "0011") return '3';
    if (a == "0100") return '4';
    if (a == "0101") return '5';
    if (a == "0110") return '6';
    if (a == "0111") return '7';
    if (a == "1000") return '8';
    if (a == "1001") return '9';
    if (a == "1010") return 'A';
    if (a == "1011") return 'B';
    if (a == "1100") return 'C';
    if (a == "1101") return 'D';
    if (a == "1110") return 'E';
    if (a == "1111") return 'F';
}


bool proverka(char* name){

    if (strchr(name,':')==&name[0]) {
        return true;
    } else
        for (unsigned int i=1; i<strlen(name)-1; ++i) {
            if(name[i]==':') {
                if(!isalpha(name[i-1]))
                    return true;
                else
                    return false;
                if(name[i+1]!='\\')
                    return true;
                else
                    return false;
            }
        }

        for(unsigned int i=0; i<strlen(name); ++i){
        if (name[i]=='"' || name[i]=='<' || name[i]=='>' || name[i]=='?' || name[i]=='|' || name[i]=='*' ) {
            return true;
        } else {
            return false;
        }
    }
}

void print_in_hex(uint8_t byte) {
    std::string c1,c2;
    for(int i=0; i<4; i++)
    {
      if ((byte) & (1 <<i))
        c1='1'+c1;
      else
        c1='0'+c1;
    }

    for(int i=4; i<8; i++)
    {
      if ((byte) & (1<<i))
        c2='1'+c2;
      else
        c2='0'+c2;
    }
    std::cout << convert_in_hex(c2);
    std::cout << convert_in_hex(c1);
}


void print_in_hex(const void* data, size_t size) {
    const uint8_t* data1=reinterpret_cast<const uint8_t*>(data);
    for(unsigned int i=0; i<size; ++i)
    {
        print_in_hex(data1[i]);
        std::cout << ' ';
    }
}

void print_in_binary(uint8_t byte)
{
    for(int i=0; i<8; i++) {
    if ((byte) & (128>>i))
        std::cout << '1';
    else
        std::cout << '0';
    }
}

void print_in_binary(const void* data, size_t size)
{
    const uint8_t* data1=reinterpret_cast<const uint8_t*>(data);
    for(unsigned int i=0; i<size; ++i)
    {
        print_in_binary(data1[i]);
        std::cout << ' ';
    }
}



using namespace std;

int main() {


    uint8_t a,b,ab;
    char m;

    cout << "Введите данные:" << endl;
    cout << "Первый операнд:"<< endl;
    cin >>a ;

    cout << "Второй операнд:" << endl;
    cin >> b;

    bool g=true;

	while (g) {
		cout << "\r\nВведите оператор ^, |, &:"<< endl;
		cin >>m;
		switch (m){
		case '&': ab=a&b;g=false;break;
		case '|': ab=a|b;g=false;break;
		case '^':ab=a^b;g=false;break;
		default:{cout << "Неверный оператор!";}
		}
	}

    cout << "hex:" << endl;
    print_in_hex(&a,sizeof(a));
    cout<<" "<<m<<" ";
    print_in_hex(&b,sizeof(b));
    cout<<" = ";
    print_in_hex(&ab,sizeof(ab));
    cout<<"\n";

    cout << "\nbin:" << endl;
    print_in_binary(&a,sizeof(a));
    cout <<" "<<m<<" ";
    print_in_binary(&b,sizeof(b));
    cout<<" = ";
    print_in_binary(&ab,sizeof(ab));
    cout<<"\n";



    //Пункт 3.2
    Stud stud[4]={
        {"Женя", 2014, 5, 0, 2, nullptr},
        {"Саня", 2014, 4, 1, 2, &stud[0]},
        {"Вера",2014, 5, 0, 2, &stud[0]},
        {"Влад",2014, 4, 1, 2, &stud[0]}
    };

    //Пункт 3.3
        //Пункт 3.3.1
    cout << "Адрес массива структур: " << &stud << " Размер массива структур: " << sizeof(stud) << endl;
        //Пункт 3.3.2
    for(int i=0; i<4; ++i) {
        cout << endl << "Адресс stud["<<i<<"]: " <<&stud[i];
        cout << endl << "Размер stud["<<i<<"]: " <<sizeof(stud[i]);
    }
        //Пункт 3.3.3

        cout << endl << "Студент № " << 2;
        cout << endl << " ";
        cout << endl << "\t" << "Имя: " << stud[1].name << endl;
        cout <<"\t\t -Адрес: " << &stud[1].name << endl;
        cout <<"\t\t -Смещение: " << offsetof(struct Stud, name) << endl;
        cout <<"\t\t -Размер: " << sizeof(stud[1].name) << endl;
        cout <<"\t\t -bin: ";
        print_in_binary(&stud[1].name, sizeof(stud[1].name));
        cout <<"\n\t\t -hex: ";
        print_in_hex(&stud[1].name, sizeof(stud[1].name));

        cout << endl << "\t" << "Год поступления: " << stud[1].god << endl;
        cout <<"\t\t -Адрес: " << &stud[1].god << endl;
        cout <<"\t\t -Смещение: " << offsetof(struct Stud, god) << endl;
        cout <<"\t\t -Размер: " << sizeof(stud[1].god) << endl;
        cout <<"\t\t -bin: ";
        print_in_binary(&stud[1].god, sizeof(stud[1].god));
        cout <<"\n\t\t hex: ";
        print_in_hex(&stud[1].god, sizeof(stud[1].god));

        cout << endl << "\t" << "Средний балл: " << stud[1].ball << endl;
        cout <<"\t\t -Адрес: " << &stud[1].ball << endl;
        cout <<"\t\t -Смещение: " << offsetof(struct Stud, ball) << endl;
        cout <<"\t\t -Размер: " << sizeof(stud[1].ball) << endl;
        cout <<"\t\t -bin: ";
        print_in_binary(&stud[1].ball, sizeof(stud[1].ball));
        cout <<"\n\t\t -hex: ";
        print_in_hex(&stud[1].ball, sizeof(stud[1].ball));

        cout << endl << "\t" << "Пройдено курсов: " << stud[1].N_kurs << endl;
        cout <<"\t\t -Адрес: " << &stud[1].N_kurs << endl;
        cout <<"\t\t -Смещение: " << offsetof(struct Stud, N_kurs) << endl;
        cout <<"\t\t -Размер: " << sizeof(stud[1].N_kurs) << endl;
        cout <<"\t\t -bin: ";
        print_in_binary(&stud[1].N_kurs, sizeof(stud[1].N_kurs));
        cout <<"\n\t\t -hex: ";
        print_in_hex(&stud[1].N_kurs, sizeof(stud[1].N_kurs));

        cout << endl << "\t" << "Староста: " << stud[1].star->name << endl;
        cout <<"\t\t -Адрес: " << &stud[1].star << endl;
        cout <<"\t\t -Смещение: " << offsetof(struct Stud, star) << endl;
        cout <<"\t\t -Размер: " << sizeof(stud[1].star) << endl;
        cout <<"\t\t -bin: ";
        print_in_binary(&stud[1].star, sizeof(stud[1].star));
        cout <<"\n\t\t -hex: ";
        print_in_hex(&stud[1].star, sizeof(stud[1].star));
        cout << endl;

        //Пункт 3.3.4

        for(int i=0; i<4; ++i)
        {
            print_in_hex(&stud[i].name, sizeof(stud[i]));
        }



    cout << "\t\t Задание 4" << endl;
    cout << "\t\t " << endl;

    //Пункт 4.1, 4.2
    char naz[30]="";
    bool oshib = true;

    while (oshib)
    {
        cout <<"Введите название файла (.txt)\n";
        cin >>naz;
        oshib = proverka(naz);
        cout <<endl;
    }

    //Пункт 4.3
    FILE * ptrFile = fopen(naz, "a+");
    fseek(ptrFile,0,SEEK_END);
    int size = ftell(ptrFile);
    cout <<"Размер файла: "<<size<<endl;
    fseek(ptrFile,0,SEEK_SET);
    char *mass = new char[ size +1 ];
    memset(mass, 0, size +1);
    size_t result = fread(mass, sizeof(char), size, ptrFile);
    if (result != ftell(ptrFile))
    {
        fputs("Ошибка чтения", ptrFile);
        exit (1);
    }
    cout <<endl<<"Содержимое файла:"<<endl;
    puts(mass);

    //Пункт 4.4
    cout <<endl <<"Найти строку:  ";
    char str[20];
    cin >> str;
    //Пункт 4.5
    char *cp = (char *) mass;
    char *s1, *s2;
    while(*cp)
    {
        s1 = cp;
        s2 = (char *) str;
        while ( *s1 && *s2 && !(*s1-*s2) )
                s1++, s2++;
            if (!*s2)
                cout<<"Положение строки: "<<(cp-mass+1)<<"\n";
        cp++;
    }
    //Пункт 4.6
    int * pos=new int [20];
    int number=0;
    pos[0]=-1;
    for(int i=0; i<size; ++i)
            if(mass[i] == '.' || mass[i] == '?' || mass[i] == '!')
            {
                ++number;
                pos[number]=i;
            }
    cout <<"\nНомер предложения: "<<number<<endl;
    char ** proparray=new char*[number];
        for(int i=0; i<number; ++i)
        {
            fseek(ptrFile, pos[i]+1,SEEK_SET);
            char * mass1 = new char[pos[i+1]];
            fread(mass1,sizeof(char),pos[i+1],ptrFile);
            char * mass2 = new char[pos[i+1]];
            proparray[i]= strncpy(mass2, mass1, (pos[i+1]-pos[i])*sizeof(char));
            delete [] mass1;
        }
        fclose (ptrFile);
        cout<<endl;
        for(int i=0; i<number; ++i)
           cout<<i+1<<" предложение ("<<strlen(proparray[i])<<") : "<<proparray[i]<<"\n";
    //Пункт 4.7
    char * c;
    for (int i = 0; i < number - 1; i++)
    {
        for (int j = 0; j < number - i - 1; j++)
        {
            if (strlen(proparray[j]) > strlen(proparray[j+1]))
            {
                c=proparray[j];
                proparray[j]=proparray[j+1];
                proparray[j+1]=c;
            }
        }
    }
    cout<<"\n\nПосле сортировки:\n";
    for(int i=0; i<number; ++i)
           cout<<i+1<<" предложение ("<<strlen(proparray[i])<<") : "<<proparray[i]<<"\n";
    //Пункт 4.8

    char naz2[30]="";
    oshib = true;

    while (oshib)
    {
        cout <<"Введите название файла (.txt)\n";
        cin >>naz2;
        oshib = proverka(naz2);
        cout <<endl;
    }
    FILE * ptrFile2 = fopen(naz2, "a+");
    fseek(ptrFile2,0,SEEK_SET);
    for(int i=0; i<number; ++i)
        fputs(proparray[i], ptrFile2);
        fclose (ptrFile2);

    //Пункт 4.9
    for(int i=0; i<number; ++i)
    {
       delete[] proparray[i];
    }
    delete [] mass, pos, cp, proparray;
    delete s1, s2, c;
    return 0;
}
