#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

struct UserIdentifier
{
    int userId = 0;
};

struct Item
{
    int id = 0;
    std::string name{};
};

bool operator==(const Item &lhs, const Item &rhs)
{
    return lhs.id == rhs.id && (lhs.name == rhs.name);
}

struct Cart
{
    std::vector<Item> items{};
};

bool isLoggedIn(const UserIdentifier &user)
{
    return user.userId % 2 == 0;
}

Cart getUserCart(const UserIdentifier &user)
{
    return Cart();
}

void removeItem(Cart &cart, Item &cartItem)
{
    auto location = std::find(cart.items.begin(), cart.items.end(), cartItem);
    if (location != cart.items.end())
    {
        cart.items.erase(location);
    }

    std::cout << "Item removed!" << std::endl;
    return;
}

void addItems(Cart &cart, const std::vector<Item> &items)
{
    cart.items.insert(cart.items.end(), items.begin(), items.end());
    std::cout << "Items added" << std::endl;
}

template <typename Action, typename Parameter>
void execute_on_user_cart(UserIdentifier user, Action action, Parameter &&parameter)
{
    if (isLoggedIn(user))
    {
        Cart cart = getUserCart(user);
        action(cart, std::forward<Parameter>(parameter));
    }

    else
    {
        std::cout << "the user is no log in" << std::endl;
    }
}

int main()
{
    std::cout << "Activity 17: Ensuring Users are Logged in When Performing Actions on the Account" << std::endl;

    struct Item toothbrush
    {
        1023, "Toothbrush"
    };
    struct Item toothpaste
    {
        1024, "Toothpaste"
    };

    UserIdentifier loggedInUser{0};
    // The user is logged in, we will add the items
    std::cout << "Adding items if the user is logged in" << std::endl;
    std::vector<Item> y = std::vector<Item>({toothbrush, toothpaste});
    execute_on_user_cart(loggedInUser, addItems, std::vector<Item>({toothbrush, toothpaste}));
    // execute_on_user_cart(loggedInUser, addItems, Cart.item);

    UserIdentifier loggedOutUser{1};
    // The user is not logged in, we will not remove the item
    std::cout << "Removing item if the user is logged out" << std::endl;
    execute_on_user_cart(loggedOutUser, removeItem, toothbrush);

    return 0;
}
