#include <string>
#include <iostream>
class Human{
    private:
        std::string name;
        int age;
    public:
        const std::string &getName() const {
            return(name);
        }
        int getAge() const {
            return (age);
        }
        //Default Construtor
        Human() : name("Default Name"), age(0){
            std::cout << "Human Default Construtor Called!" << std::endl;
        }

        //Parameterid Construtor
        Human(const std::string &name, int age) : name(name), age(age){
            std::cout << "Human Parameterized Construtor Called" << std::endl;
        }
        //Copy Contructor
        Human(const Human &other) : name(other.name), age(other.age) {
            std::cout << "Human copy Construtoor Called" << std::endl;
        }

        Human &operator = (const Human &other)
        {
            if (this != &other)
            {
                name = other.name;
                age = other.age
            }
            std::cout << "Human Assignment Operator Called" << std::endl;
            return (*this); //Required for chaining
        };

        //Destrutor
        ~Human(){
            std::cout << "Human Destructor Called" << std::endl;
            delete name; //Clean up
        }
}

int main(void)
{
    //Default Contrutor
    Human h1;

    std::cout << h1.getName() << std::endl;
    std::cout << h1.getAge() << std::endl;

    //Parameterized Construtor

    Human h2("Gilson", 23)
    std::cout << h1.getName() << std::endl;
    std::cout << h1.getAge() << std::endl;

    //Copy Construtor initializes a new object as a copy of an existing objecy. 
    //This is useful when passing an object by value or when we need to duplicate an object 
    
    Human h3(h2);
    std::cout << h2.getName() << std::endl;
    std::cout << h2.getAge() << std::endl;

    //The assignment Operator assings the value of one object to other already existing object
    //to onother already-existing object. Here we need handle deep copying and self-assignment.

    Human h4("Gilson Bravo", 24);

    h2=h1;
    std::cout << h4.getName() << std::endl;
    std::cout << h4.getAge() << std::endl;

    return (0);
}