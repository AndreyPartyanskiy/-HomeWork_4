// Homework_4.1.cpp 

#include <iostream>
#include <fstream>
#include <windows.h>
#include <string>

class Address
{
    std::string city;
    std::string street;
    int house;
    int appart;

public:

    

    Address() {};

    Address(std::string city, std::string street, int house, int appart)
    {
        this->city = city;
        this->street = street;
        this->house =house;
        this->appart = appart;
    };

    std::string get_new_string() 
    {
        return (city+ ", " + street+ ", " + std::to_string(house)+ ", " + std::to_string(appart));
    };
};

int main()
{
    system("chcp 1251");
    system("cls");
    int size,h,a;
    std::string c, s;
    

    std::ifstream in ("in.txt");
    std::ofstream out ("out.txt");


    if (in.is_open())
    {
        in >> size;
    }
    else
    {
        std::cout << "File not open" << std::endl;
        return (0);
    }
    Address* addr = new Address[size]{};
    for (int i = 0; i < size; i++)
    {
        in >> c;
        in >> s;
        in >> h;
        in >> a;   
        Address ad(c,s,h,a);
        addr[i] = ad;
    }
   
    
    in.close();

    out << size << "\n";
    for (int i=0;i<size;i++) 
    {
        out << addr[size-i-1].get_new_string() << std::endl;
    };
    out.close();
    delete []addr;
}

