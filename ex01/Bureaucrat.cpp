#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat():_name("Default") {}

Bureaucrat::Bureaucrat(const std::string name, int grade):_name(name)
{
	_grade = grade;
	if (_grade < 1)
		throw(GradeTooHighException());
	if (_grade > 150)
		throw(GradeTooLowException());
}

Bureaucrat::Bureaucrat(const Bureaucrat &other):_name(other._name)
{
	_grade = other._grade;
}

Bureaucrat::~Bureaucrat() {}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other)
{
	if (this != &other)
		_grade = other._grade;
	return (*this);
}

std::ostream& operator<<(std::ostream& out, Bureaucrat const &in)
{
	out << in.getName() << ", bureaucrat grade "<< in.getGrade();
	return (out);
}

const std::string Bureaucrat::getName() const
{
	return (_name);
}

int	Bureaucrat::getGrade() const
{
	return (_grade);
}

void Bureaucrat::increment()
{
	if (_grade - 1 < 1)
		throw(GradeTooHighException());
	_grade -= 1;
}

void Bureaucrat::decrement()
{
	if (_grade + 1 > 150)
		throw(GradeTooLowException());
	_grade += 1;
}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Error: GradeTooHighException");
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Error: GradeTooLowException");
}

void  Bureaucrat::signForm(Form &other) const
{
	if (other.isSigned())
		std::cout << *this << " signed " << other << "\n";
	else
		std::cout << *this << " couldn’t sign " << other << " because GradeTooLow \n";
}