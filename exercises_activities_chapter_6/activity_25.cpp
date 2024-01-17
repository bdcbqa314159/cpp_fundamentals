#include <iostream>
#include <string>

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

void exampleOfUsage(const UserProfileStorage &storage)
{
    UserId u_id;
    std::cout << "About to retrieve the user profile from the storage" << nl;
    UserProfile user = storage.getUserProfile(u_id);
    return;
}

int main()
{
    std::cout << "Activity 25: Retrieving User Information" << nl;
    UserProfileCache cache;
    exampleOfUsage(cache);
    return 0;
}
