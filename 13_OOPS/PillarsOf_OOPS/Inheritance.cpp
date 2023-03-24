#include<iostream>
#include<cstring>
using namespace std;

class Human{
    private:
        int height;
        int weight;
        int age;

    public:
        void setHeight(int height) {
            this -> height = height;
        }

        void setWeight(int weight) {
            this -> weight = weight;
        }

        void setAge(int age) {
            this -> age = age;
        }

        int getHeight() {
            return height;
        }

        int getWeight() {
            return weight;
        }

        int getAge() {
            return age;
        }
};

class Male : public Human{
    private:
        string color;

    public:
        void setColor(string color) {
            this -> color = color;
        }

        string getColor() {
            return color;
        }

        void random() {
            cout << "Inheritance is working" << endl;
        }

        void print() {
            cout << getAge() << endl;
            cout << getHeight() << endl;
            cout << getWeight() << endl;
            cout << getColor() << endl;
        }
};

int main() {
    Male obj;
    obj.setAge(19);
    obj.setHeight(173);
    obj.setWeight(49);
    obj.setColor("black");

    obj.print();
    obj.random();
}