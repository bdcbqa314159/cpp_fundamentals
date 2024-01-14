#include <iostream>
#include <string>
#include <stack>
#include <vector>

const char nl = '\n';

struct RegistrationForm
{
    std::string userName{};

    RegistrationForm(std::string &name) : userName(name) {}
};

void processRegistration(RegistrationForm form)
{
    std::cout << "Processing form for user: " << form.userName << nl;
}

void storeRegistrationForm(std::stack<RegistrationForm> &stack,
                           RegistrationForm form)
{
    processRegistration(form);
    stack.push(form);
    return;
}

void endOfDayRegistrationProcessing(std::stack<RegistrationForm> &stack)
{
    while (!stack.empty())
    {
        RegistrationForm out = stack.top();
        processRegistration(out);
        stack.pop();
    }
    return;
}

int main()
{
    std::stack<RegistrationForm> data{};

    std::vector<std::string> names = {"Alice", "Bob", "Charlie"};

    std::cout << "==== storing ====" << nl;
    for (auto name : names)
        storeRegistrationForm(data, name);

    std::cout << "==== closing end ====" << nl;
    endOfDayRegistrationProcessing(data);

    return 0;
}
