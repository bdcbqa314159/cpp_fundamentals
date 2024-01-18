#include <iostream>
#include <string>
#include <future>

const char nl = '\n';

struct DataBaseConnection
{
};

void updateOrderList(DataBaseConnection &db)
{
    std::cout << "Updating order list" << nl;
}

void scheduleOrderProcessing(DataBaseConnection &db)
{
    std::cout << "Schedule order processing" << nl;
}

void updateWithConnection(std::shared_ptr<DataBaseConnection> connection)
{
    updateOrderList(*connection);
}

void scheduleWithConnection(std::shared_ptr<DataBaseConnection> connection)
{
    scheduleOrderProcessing(*connection);
}

int main()
{
    std::cout << "Activity 27: Using a Database Connection for Multiple Operations" << nl;

    std::shared_ptr<DataBaseConnection> connection = std::make_shared<DataBaseConnection>();
    std::cout << "Updating order and scheduling order processing in parallel" << std::endl;
    auto updateResult = std::async(std::launch::async, updateWithConnection, connection);
    auto scheduleResult = std::async(std::launch::async, scheduleWithConnection, connection);

    updateResult.wait();
    scheduleResult.wait();

    return 0;
}
