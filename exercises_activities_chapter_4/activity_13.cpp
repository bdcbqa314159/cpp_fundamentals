#include <iostream>
#include <array>

class UserAccount
{
public:
    static std::array<char, 100> serialize(const UserAccount &account)
    {
        std::cout << "the user account has been serialized" << std::endl;
        return {};
    }

    static UserAccount deserialize(const std::array<char, 100> &blob)
    {
        std::cout << "the user account has been deserialized" << std::endl;
        return {};
    }
};

class TcpConnection
{
public:
    std::array<char, 100> readNext() const
    {
        std::cout << "the data has been read" << std::endl;
        return {};
    }

    void writeNext(const std::array<char, 100> &blob)
    {
        std::cout << "the data has been written" << std::endl;
        return;
    }
};

template <typename Object, typename Connection>
Object readObjectFromConnection(const Connection &connection)
{
    std::array<char, 100> data = connection.readNext();
    return Object::deserialize(data);
}

template <typename Object, typename Connection>
void writeObjectToConnection(const Object &object, Connection &connection)
{
    std::array<char, 100> data = Object::serialize(object);
    connection.writeNext(data);
}

int main()
{
    std::cout << "Activity 13: Reading Objects from a Connection" << std::endl;

    std::cout << "serialize first account" << std::endl;
    UserAccount firstAccount;
    TcpConnection tcp_connection;

    writeObjectToConnection<UserAccount, TcpConnection>(firstAccount, tcp_connection);
    UserAccount user_transmitted = readObjectFromConnection<UserAccount, TcpConnection>(tcp_connection);

    return 0;
}
