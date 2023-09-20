#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP
#include "AForm.hpp"

class Form;
class RobotomyRequestForm : public Form
{
	std::string _target;

public:
	RobotomyRequestForm();
	RobotomyRequestForm(std::string target);
	RobotomyRequestForm(RobotomyRequestForm const &other);
	~RobotomyRequestForm();
	RobotomyRequestForm &operator=(RobotomyRequestForm const &other);
	void execute(Bureaucrat const &executor) const;
};

#endif