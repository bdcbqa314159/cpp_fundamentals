#include <iostream>
#include <string>
#include <memory>

const char nl = '\n';

struct UserProfile
{
};
struct UserId
{
};

class UserProfileStorage
{
public:
    virtual UserProfile getUserProfile(const UserId &id) const = 0;
    virtual ~UserProfileStorage() = default;

protected:
    UserProfileStorage() = default;
    UserProfileStorage(const UserProfileStorage &) = default;
    UserProfileStorage &operator=(const UserProfileStorage &) = default;
};

class UserProfileCache : public UserProfileStorage
{

    UserProfile getUserProfile(const UserId &id) const override
    {
        std::cout << "Getting the user profile from the cache: " << nl;
        return UserProfile();
    }
};

// void exampleOfUsage(const UserProfileStorage &storage)
// {
//     UserId u_id;
//     std::cout << "About to retrieve the user profile from the storage" << nl;
//     UserProfile user = storage.getUserProfile(u_id);
//     return;
// }

class UserProfileStorageFactory
{
public:
    std::unique_ptr<UserProfileStorage> create() const
    {
        return std::make_unique<UserProfileCache>();
    }
};

void getUserProfile(const UserProfileStorageFactory &factory)
{
    std::unique_ptr<UserProfileStorage> storage = factory.create();
    UserId u_id;

    std::cout << "Retrieving user profile from the factory generated storage" << nl;
    storage->getUserProfile(u_id);
}

int main()
{
    std::cout << "Activity 26: Creating a Factory for UserProfileStorage" << nl;
    UserProfileStorageFactory factory;
    getUserProfile(factory);
    return 0;
}
