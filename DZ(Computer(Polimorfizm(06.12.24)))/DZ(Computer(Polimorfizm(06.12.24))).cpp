#include <iostream>
#include <string>
using namespace std;

class PC {
protected:
    string name;
    string CPU;
    string GPU;
    string SSD;
    string RAM;
    double price;
public:
    PC(string name, string CPU, string GPU, string SSD, string RAM, double price)
        : name(name), CPU(CPU), GPU(GPU), SSD(SSD), RAM(RAM), price(price) {}

    double GetPrice() const {
        return price;
    }

    virtual void Print() const {
        cout << "��������: " << name << "\n"
            << "CPU: " << CPU << "\n"
            << "GPU: " << GPU << "\n"
            << "SSD: " << SSD << "\n"
            << "RAM: " << RAM << "\n"
            << "����: " << price << " USD\n";
    }

    virtual ~PC() {}
};

class OfficePC : public PC {
private:
    string micro; 
public:
    OfficePC(string name, string CPU, string GPU, string SSD, string RAM, double price, string micro)
        : PC(name, CPU, GPU, SSD, RAM, price), micro(micro) {}

    void Print() const override {
        cout << "���: ������� ��\n";
        PC::Print();
        cout << "��������: " << micro << "\n";
    }
};

class GamePC : public PC {
private:
    string keyboard; 
    string headphones; 

public:
    GamePC(string name, string CPU, string GPU, string SSD, string RAM, double price, string keyboard, string headphones)
        : PC(name, CPU, GPU, SSD, RAM, price), keyboard(keyboard), headphones(headphones) {}

    void Print() const override {
        cout << "���: ������� ��\n";
        PC::Print();
        cout << "������� ����������: " << keyboard << "\n"
            << "��������: " << headphones << "\n";
    }
};

class HomePC : public PC {
private:
    string webcam; 
public:
    HomePC(string name, string CPU, string GPU, string SSD, string RAM, double price, string webcam)
        : PC(name, CPU, GPU, SSD, RAM, price), webcam(webcam) {}

    void Print() const override {
        cout << "���: �������� ��\n";
        PC::Print();
        cout << "���-������: " << webcam << "\n";
    }
};

int main() {
    setlocale(0, "ru");
    OfficePC officePC("Office", "Intel i5", "Integratted", "256GB", "8GB", 500, "Logitech USB Mic");
    GamePC gamePC("Gaming", "Intel i9", "NVIDIA RTX 3080", "1TB", "32GB", 2000, "Varmillo", "Razer");
    HomePC homePC("Hom", "Intel i3", "Integrated", "512GB", "16GB", 800, "Logiech HD Webcam");

    cout << "�������� ��� �� ��� ���������:\n";
    cout << "1. ������� ��\n"
     << "2. ������� ��\n" << "3. �������� ��\n" << "��� �����: ";
    int choice;
    cin >> choice;

    if (choice == 1)
    {
        officePC.Print();
    }
    else if (choice == 2)
    {
        gamePC.Print();
    }
    else if (choice == 3)
    {
        homePC.Print();
    }
    else{
        cout << "�������� �����!\n";
    }

    return 0;
}
