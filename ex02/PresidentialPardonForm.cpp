#include "PresidentialPardonForm.hpp"


PresidentialPardonForm::PresidentialPardonForm():Form("PresidentialPardonForm", 25, 5)
{
	std::cout << "PresidentialPardonForm Default constructor called\n";
}

PresidentialPardonForm::PresidentialPardonForm(std::string target):Form("PresidentialPardonForm", 25, 5)
{
	_target = target;
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &other):Form("PresidentialPardonForm", 25, 5)
{
	*this = other;
	std::cout << "PresidentialPardonForm Copy constructor called\n";
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << "Presidential PardonForm Destructor called\n";
}

PresidentialPardonForm &PresidentialPardonForm::operator=(PresidentialPardonForm const &other)
{
	if (this != &other)
		_target = other._target;
	return (*this);
}

void PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
	if (executor.getGrade() > getExecGrade())
		throw(Form::GradeTooLowException());
	else
		std::cout << _target << " has been pardoned by Zafod Beeblebrox\n";
}