#include <iostream>
#include <vector>
#include <unordered_map>
#include <cctype>
#include <iomanip>

[[nodiscard]] bool saver() {
    if (std::cin.eof()) {
        std::cerr << "[!]DANGER. Closing Program For Safety.\n";
        return false;
    }

    if (std::cin.fail()) {
        std::cin.clear();
    }

    return true;
}

void capitalizeFirst(std::string& text) {
    if (!(text.empty())) {
        text[0] = std::toupper(
            static_cast<unsigned char>(text[0])
        );
    } else {
        std::cout << "Empty.\n";
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::vector<std::string> cart;
    std::string user;
    std::string fix;
    double totalPrice;
    std::unordered_map<std::string, double> cafeMenu = {
        {"Cappucino", 23.12},
        {"Mochaccino", 22.21},
        {"Dalgona", 20.46},
        {"Matcha", 20.20},
        {"Americano", 19.87},
        {"Chocollate", 21.77},
        {"Pancake", 23.21},
        {"Pizza", 24.21}
    };

    std::cout << "=============== LAKE TAHOE CAFE MENU =============== \n";

    for (auto const& item : cafeMenu) {
        std::cout 
            << std::left
            << std::setw(15)
            << item.first
            << " Price: &"
            << std::setprecision(2)
            << std::fixed
            << item.second
            << "\n";
    }

    std::cout << "====================================================\n";

    while (true) {
        std::cout << "Order Or Exit: " << std::flush;
        if (!(getline(std::cin, user))) {
            if (!(saver())) return 1;
            std::cerr << "Input Invalid. Please Order Or Exit.\n";
            continue;
        }
        capitalizeFirst(user);

        if (user == "Exit") {
            break;
        }

        if (user.empty()) {
            std::cout << "Input Cannot Empty.\n";
            continue;
        }

        auto it = cafeMenu.find(user);
        if (it != cafeMenu.end()) {
            cart.push_back(user);
            totalPrice += it->second;
            std::cout 
                << user
                << "\nAdded To Cart\n";
        } else {
            std::cout << "Menu  Not Available\n";
        }
    }

    std::cout << "=============== LAKE TAHOE CAFE CART ===============\n";
    if (!(cart.empty())) {
        for (auto const& bill : cart) {
            std::cout 
                << "Your Order: "
                << std::left
                << std::setw(15)
                << bill 
                << " Price: $"
                << std::setprecision(2)
                << std::fixed
                << cafeMenu.at(bill)
                << "\n";
        }
        std::cout << "\n";
        std::cout << "Total Price: $" << totalPrice << "\n";
        std::cout << "====================================================\n";
    } else {
        std::cout << "Cart Is Empty.\n";
    }

    std::cout << "Thankyou For Be Lake Tahoe Cafe Customer\nHave A Good Day\n";
    return 0;
}