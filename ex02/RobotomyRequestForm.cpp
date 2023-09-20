#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm():Form("RobotomyRequestForm", 72, 45)
{
	std::cout << "RobotomyRequestForm Default constructor called\n";
}

RobotomyRequestForm::RobotomyRequestForm(std::string target):Form("RobotomyRequestForm", 72, 45)
{
	_target = target;
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &other)
{
	*this = other;
	std::cout << "RobotomyRequestForm Copy constructor called\n";
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << "RobotomyRequestForm Destructor called\n";
}

RobotomyRequestForm &RobotomyRequestForm::operator=(RobotomyRequestForm const &other)
{
	if (this != &other)
		_target = other._target;
	return (*this);
}

void RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
	if (executor.getGrade() > getExecGrade())
		throw(Form::GradeTooLowException());
	else 
	{
		static int i = 0;
		if (i % 2 == 0)
			std::cout << _target << " has been robotomized successfully\n";
		else
			std::cout << _target << " has been robotomized unsuccessfully\n";
		i++;
	}
}