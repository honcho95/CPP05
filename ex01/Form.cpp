#include "Form.hpp"

Form::Form() : _name("Default"), _sign_grade(150), _exec_grade(150)
{
	_signed = false;
	std::cout << "Form Default constructor called\n";
}

Form::Form(std::string name, int sign_grade, int exec_grade):_name(name),_sign_grade(sign_grade), _exec_grade(exec_grade)
{
	
	if (_exec_grade < 1 || _sign_grade < 1)
		throw(GradeTooHighException());
	if (_exec_grade > 150 || _sign_grade > 150)
		throw(GradeTooLowException());
	_signed = false;
}

Form::Form(const Form &other) : _sign_grade(other._sign_grade), _exec_grade(other._exec_grade)
{
	*this = other;
	std::cout << "Form Copy constructor called\n";
}

Form::~Form()
{
	std::cout << "Form Destructor called\n";
}

Form &Form::operator=(const Form &other)
{
	if (this != &other)
		_signed = other._signed;
	return (*this);
}

std::ostream &operator<<(std::ostream &out, Form const &in)
{
	out << "Form: " << in.getName() << ", Signed: " << in.isSigned()
		<< ", Grade sing: " << in.getSignGrade()
		<< ", Grade exec: " << in.getExecGrade();
	return (out);
}

const std::string &Form::getName() const
{
	return (_name);
}

bool Form::isSigned() const
{
	return (_signed);
}

int Form::getSignGrade() const
{
	return (_sign_grade);
}

int Form::getExecGrade() const
{
	return (_exec_grade);
}

const char *Form::GradeTooHighException::what() const throw()
{
	return ("Error: GradeTooHighException");
}

const char *Form::GradeTooLowException::what() const throw()
{
	return ("Error: GradeTooLowException");
}

void Form::beSigned(Bureaucrat &other)
{
	if (other.getGrade() <= _sign_grade)
		_signed = true;
	else
		throw(GradeTooLowException());
}