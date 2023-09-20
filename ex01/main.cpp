#include "Bureaucrat.hpp"

int main()
{
	try
	{
		/* do some stuff with bureaucrats */
		Bureaucrat bureaucrat1("bureaucrat1", 1);
		bureaucrat1.increment();
	}
	catch (std::exception & e)
	{
		/* handle exception */
		std::cout<<e.what()<< std::endl;
	}

	std::cout << "<--------- Test 2 --------->\n";
	try
	{
		/* do some stuff with bureaucrats */
		Bureaucrat bureaucrat2("bureaucrat1", 90);
		bureaucrat2.decrement();
		Form form1("form1",100,100);
		form1.beSigned(bureaucrat2);
		std::cout << form1 << "\n";
		bureaucrat2.signForm(form1);
	}
	catch (std::exception & e)
	{
		/* handle exception */
		std::cout<<e.what()<< std::endl;
	}

	std::cout << "<--------- Test 3 --------->\n";
	try
	{
		/* do some stuff with bureaucrats */
		Bureaucrat bureaucrat3("bureaucrat3", 149);
		bureaucrat3.decrement();
		std::cout << bureaucrat3.getGrade() << "\n";
		Form form2("form1",100,100);
		form2.beSigned(bureaucrat3);
		std::cout << form2 << "\n";
		bureaucrat3.signForm(form2);
	}
	catch (std::exception & e)
	{
		/* handle exception */
		std::cout<<e.what()<< std::endl;
	}

	
}