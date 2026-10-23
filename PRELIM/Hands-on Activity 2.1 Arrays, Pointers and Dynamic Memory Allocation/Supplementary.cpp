    #include <iostream>
    #include <string>
    #include <iomanip>

    //Base Class
    class GroceryItem {
    protected :
        char* name;
        double price;
        int quantity;
        std::string category;

    public:

        //Constructor
        GroceryItem(const char* item_name = "", double item_price = 0.0, int item_qty = 0, std::string item_cat = "General") 
            : price(item_price), quantity(item_qty), category(item_cat) {

            int len = 0;
            while (item_name[len] != '\0') len++;

            name = new char[len + 1];
            for (int i = 0; i <= len; i++) {
                name[i] = item_name[i];
            }
        }
        
        //Destructor
        virtual ~GroceryItem() {
            delete[] name;
        }

        //Copy Constructor
        GroceryItem(const GroceryItem& other)
            : price(other.price), quantity(other.quantity), category(other.category) {

                int len = 0;
                while (other.name[len] != '\0') len++;

                name = new char[len + 1];
                for (int i = 0; i <= len; i++) {
                    name[i] = other.name[i];
                }
            }
        
            //Copy Assignment Operator
            GroceryItem& operator=(const GroceryItem& other) {
                if (this != &other) {
                    delete[] name;

                    price = other.price;
                    quantity = other.quantity;
                    category = other.category;

                    int len = 0;
                    while (other.name[len] != '\0') len++;

                    name = new char[len + 1];
                    for (int i = 0; i <= len; i++) {
                        name[i] = other.name[i];
                    }
                }
                return *this;
            }

            //Function to calculate individual item total sum
            double calculateSum() const {
                return price * quantity;
        }

        //Displays the function to print the details
        virtual void display() const {
            std::cout << std::left << std::setw(12) << name
                    <<std::setw(12) << category
                    <<"PHP" << std::setw(8) << price
                    <<std::setw(6) << ("x" + std::to_string(quantity))
                    <<"PHP" << calculateSum() << std::endl;
        }

        const char* getName() const {return name;}
    };

    class Fruit : public GroceryItem {
    public:
    Fruit(const char* name = "", double price = 0.0, int quantity =0)
        : GroceryItem(name, price, quantity, "Fruit") {}

    };

    class Vegetable : public GroceryItem {
        public:
            Vegetable(const char* name = "", double price = 0.0, int quantity = 0)
                : GroceryItem(name, price, quantity, "Vegetable") {}
        
    };

    double TotalSum(GroceryItem* list[], int size) {
        double total = 0.0;
        for (int i = 0; i < size; ++i) {
            if (list[i] != nullptr) {
                total += list[i]->calculateSum();
            }
        }
        return total;
    }

    int main() {
        const int ITEM_COUNT = 4;

        GroceryItem* GroceryList[ITEM_COUNT];

        GroceryList[0] = new Fruit("Apple", 10.0, 7);
        GroceryList[1] = new Fruit("Banana", 10.0, 8);
        GroceryList[2] = new Vegetable("Broccoli", 60.0, 12);
        GroceryList[3] = new Vegetable("Lettuce", 50.0, 10);


        //Displays the initial Grocery List
        std::cout << "Jenna's Grocery List is:" << std::endl;
        std::cout << std::left << std:: setw(12) <<"Item name"
                << std::setw(12) << "Category"
                << std::setw(12) << "Price"
                << std::setw(6) << "Qty"
                << "Total" << std::endl;

        
        for (int i = 0; i < ITEM_COUNT; ++i) {
            if (GroceryList[i] != nullptr) {
                GroceryList[i]->display();
            }
        }

        
        std::cout << "Total Cost For All Items is: " << TotalSum(GroceryList, ITEM_COUNT) << "\n\n";

        //Deletes Lettuce and de-allocates the dynamic memory
        std::cout << "Removing Lettuce form the List" << std:: endl;
        for (int i = 0; i < ITEM_COUNT; ++i) {
            if (GroceryList[i] != nullptr && std::string(GroceryList[i]->getName()) == "Lettuce") {
                delete GroceryList[i];
                GroceryList[i] = nullptr;
                std::cout << "Lettuce has been successfully removed from the List\n\n";
                break;
            }
        }

        //Displays the updated list and recalculates the total price
        std::cout << "The New Total Costs for All Items is:" << TotalSum(GroceryList, ITEM_COUNT) << std::endl;

        for (int i = 0; i < ITEM_COUNT; ++i) {
            delete GroceryList[i];
            GroceryList[i] = nullptr;
        }

        return 0;
    }
