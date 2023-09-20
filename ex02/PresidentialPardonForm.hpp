#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP
#include "AForm.hpp"

class Form;
class PresidentialPardonForm : public Form
{
	std::string _target;
public:
	PresidentialPardonForm();
	PresidentialPardonForm(std::string target);
	PresidentialPardonForm(PresidentialPardonForm const &other);
	~PresidentialPardonForm();
	PresidentialPardonForm &operator=(PresidentialPardonForm const &other);
	void execute(Bureaucrat const &executor) const;
};

#endif