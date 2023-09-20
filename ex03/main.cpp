#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "AForm.hpp"
#include "Intern.hpp"

int main()
{

	{
		Intern someRandomIntern;
		Form* rrf;
		rrf = someRandomIntern.makeForm("shrubbery creation", "TEST");
		delete rrf;
	}
	try
	{
		Bureaucrat bureaucrat("ali", 10);
		PresidentialPardonForm presidentform("President");
		RobotomyRequestForm robotomyform("Robotomy");
		ShrubberyCreationForm shrubberyform("Home");

		std::cout << "<--------- Test 1 --------->\n";
		bureaucrat.signForm(presidentform);
		bureaucrat.excuteForm(presidentform);
		shrubberyform.execute(bureaucrat);
		std::cout << "<--------- Test 2 --------->\n";
		bureaucrat.signForm(robotomyform);
		bureaucrat.excuteForm(robotomyform);
		shrubberyform.execute(bureaucrat);
		std::cout << "<--------- Test 3 --------->\n";;
		bureaucrat.signForm(shrubberyform);
		bureaucrat.excuteForm(shrubberyform);
		shrubberyform.execute(bureaucrat);
		std::cout << "<--------- ------ --------->\n";
	}
	catch (std::exception & e)
	{
		/* handle exception */
		std::cout<<e.what()<< std::endl;
	}
	return (0);
}