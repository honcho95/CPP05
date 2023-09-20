#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(std::string const & name, int grade) : name(name), grade(grade) 
{
    exceptions(grade);
}

Bureaucrat::Bureaucrat(Bureaucrat const & src) : name(src.name), grade(src.grade) {}

Bureaucrat::~Bureaucrat() {}

Bureaucrat & Bureaucrat::operator=(Bureaucrat const & other) 
{
    if (this != &other) 
    {
        grade = other.grade;  // name is const, so can't assign it.
    }
    return *this;
}

std::string Bureaucrat::getName() const 
{
    return name;
}

int Bureaucrat::getGrade() const 
{
    return grade;
}

void Bureaucrat::upGrade() 
{
    exceptions(grade - 1);
    grade--;
}

void Bureaucrat::downGrade() 
{
    exceptions(grade + 1);
    grade++;
}

void Bureaucrat::exceptions(int grade) 
{
    if (grade < 1) 
    {
        throw GradeTooHighException();
    } 
    else if (grade > 150) 
    {
        throw GradeTooLowException();
    }
}

std::ostream & operator<<(std::ostream & ost, Bureaucrat const & bureaucrat) 
{
    ost << bureaucrat.getName() << "'s grade is " << bureaucrat.getGrade() << std::endl;
    return ost;
}
