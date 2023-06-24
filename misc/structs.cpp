#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

/*
 * Technically, there is only difference between structs and classes
 * Members of class are by default private if no access modifier is defined
 * Whereas in structs, all member are by default public
 * That's all there is to it but in code both of them have a separate applications
 * If there are no major technical differences between classes and structs, they why do have them?
 * Answer is for backwards compatibility as C doesn't have classes, only structs.
 * Removing it from C++ would remove the codebase's backward compatibility with C.

 * Use Structs
 * -> When it comes to group variables
 * -> Don't use it to represent entities
 * -> When the functionality is very less (no/some simple methods)

 * Definition: Structure is a collection of variables of different data types under a single name. It is similar to a class in that, both holds a collecion of data of different data types.
 * When a structure is created, no memory is allocated. The structure definition is only the blueprint for the creating of variables. You can imagine it as a datatype.
 * Memory is allocated only when struct variable is defined
*/

struct SoftwareEngineer {
    string name;
    string skills[5];
    int yoe;

    void describeEngineer() {
        cout << this -> name << endl;
        for (string skill: this -> skills) {
            cout << skill << " ";
        } cout << endl;
        cout << this -> yoe << " years of experience";
    }
};

int main() {
    SoftwareEngineer se1;

    se1.name = "Suyash Purwar";
    se1.skills[0] = "Node.js";
    se1.skills[1] = "PostgreSQL";
    se1.skills[2] = "AWS";
    se1.skills[3] = "Docker";
    se1.skills[4] = "System Design";
    se1.yoe = 22;

    se1.describeEngineer();

	return 0;
}