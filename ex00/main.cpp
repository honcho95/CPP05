#include "Bureaucrat.hpp"

int main()
{
    std::cout << "<--------- Test 1 --------->\n";
	try
	{
		Bureaucrat bureaucrat1("bureaucrat1", 1);
		std::cout << bureaucrat1;
        std::cout << "Incrementing grade" << std::endl;
		bureaucrat1.upGrade();
	}
	catch (std::exception & e)
	{
		std::cout<<e.what()<< std::endl;
	}

	std::cout << "<--------- Test 2 --------->\n";
	try
	{
		Bureaucrat bureaucrat2("bureaucrat1", 150);
        std::cout << bureaucrat2;
        std::cout << "Decrementing grade" << std::endl;
		bureaucrat2.downGrade();
	}
	catch (std::exception & e)
	{
		std::cout<<e.what()<< std::endl;
	}

	std::cout << "<--------- Test 3 --------->\n";
	try
	{
		Bureaucrat bureaucrat3("bureaucrat3", 149);
        std::cout << bureaucrat3;
        std::cout << "Decrementing grade" << std::endl;
		bureaucrat3.downGrade();
		std::cout << bureaucrat3; 
	}
	catch (std::exception & e)
	{
		std::cout<<e.what()<< std::endl;
	}
}