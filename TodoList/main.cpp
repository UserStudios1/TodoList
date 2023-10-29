#include <iostream>
#include <string>
#include <list>

class TodoItem {
private:
    int id;
    std::string description;
    bool completed;
public:
    TodoItem() : id(0), description(""), completed(false) {}
    ~TodoItem() = default;

    bool create(std::string new_description) {
        // generates random in between 1 and 100
        id = rand() % 100 + 1;
        description = new_description;
        return true;
    }

    int getId() {
        return id;
    }
    std::string getDescription() {
        return description;
    }
    bool isCompleted() {
        return completed;
    }
    void setCompleted(bool value) {
        completed = value;
    }
};

int main()
{
    char input_option;
    int input_id;
    std::string input_description;
    std::string version = "v0.2.0";
    std::list<TodoItem> todoItems;
    std::list<TodoItem>::iterator i;

    // generate new seed for the rand() call in create(std::string new_description)
    srand(time(NULL));

    todoItems.clear();

    //TodoItem test;
    //test.create("Test Item");
    //todoItems.push_back(test);

    while (true) {
        system("cls");
        std::cout << "Todo List Maker by UserStudios1 - " << version << std::endl;
        std::cout << "\n" << "\n";

        for (i = todoItems.begin(); i != todoItems.end(); i++) {

            // checks if the todo is completed
            std::string completed = i->isCompleted() ? "Completed" : "Uncompleted";

            // print information
            std::cout << i->getId() << " | " << i->getDescription() << " | " << completed << "\n" << std::endl;
        }
        if (todoItems.empty()) {
            std::cout << "Add a new Todo to your List!\n" << std::endl;
        }

        std::cout << "[A]dd a new Todo to your List" << std::endl;
        std::cout << "[C]ompleted a Todo" << std::endl;
        std::cout << "[Q]uit" << std::endl;

        std::cout << "Option: ";
        std::cin >> input_option;

        if (input_option == 'q' || input_option == 'Q') {
            std::cout << "Quiting..." << std::endl;
            break;
        }
        else if (input_option == 'c' || input_option == 'C') {
            std::cout << "Enter the id of the Todo that you want to mark as Completed/Uncompleted: ";
            std::cin >> input_id;

            for (i = todoItems.begin(); i != todoItems.end(); i++) {
                if (input_id == i->getId() && !i->isCompleted()) {
                    i->setCompleted(true);
                    break;
                }
                else if (input_id == i->getId() && i->isCompleted()) {
                    i->setCompleted(false);
                    break;
                }
            }
        }
        else if (input_option == 'a' || input_option == 'A') {
            std::cout << "Add a new description: ";
            std::cin.clear();
            std::cin.ignore();
            std::getline(std::cin, input_description);

            TodoItem newItem;
            newItem.create(input_description);
            todoItems.push_back(newItem);
        }
    }

    return 0;
}