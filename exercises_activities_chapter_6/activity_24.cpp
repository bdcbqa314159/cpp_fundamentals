#include <iostream>
#include <string>

const char nl = '\n';

class Department
{
public:
    Department() {}
    Department(int expectedEarning, int effectiveEarning) : d_expectedEarning(expectedEarning), d_effectiveEarning(effectiveEarning) {}

    bool hasReachedTarget() const { return d_effectiveEarning >= d_effectiveEarning; }

    int expectedEarning() const { return d_expectedEarning; }
    int effectiveEarning() const { return d_effectiveEarning; }

private:
    int d_expectedEarning{}, d_effectiveEarning{};
};

class Employee
{
public:
    virtual int getBaseSalary() const { return 100; }

    virtual int getBonus(const Department &dep) const
    {
        return dep.hasReachedTarget() * (0.1 * getBaseSalary());
    }

    int getTotalCompensation(const Department &dep)
    {
        return getBaseSalary() + getBonus(dep);
    }
};

class Manager : public Employee
{
public:
    int getBaseSalary() const override
    {
        return 150;
    }

    int getBonus(const Department &dep) const
    {
        if (dep.hasReachedTarget())
        {
            int additionalDepartmentEarnings = dep.effectiveEarning() - dep.expectedEarning();
            return static_cast<int>(0.2 * getBaseSalary() + 0.01 * additionalDepartmentEarnings);
        }
        return 0;
    }
};

int main()
{
    std::cout << "Activity 24: Calculating Employee Salaries" << nl;
    Employee e;
    Manager m;

    Department dep(1000, 1100);
    Employee employee;
    Manager manager;
    std::cout << "Employee: " << employee.getTotalCompensation(dep) << ". Manager: " << manager.getTotalCompensation(dep) << nl;
    return 0;
}
