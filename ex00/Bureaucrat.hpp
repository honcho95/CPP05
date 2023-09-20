#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <string>
#include <iostream>

class Bureaucrat 
{
public:
    Bureaucrat(std::string const & name, int grade);
    Bureaucrat(Bureaucrat const & src);
    ~Bureaucrat();
    Bureaucrat & operator=(Bureaucrat const & other);

    std::string getName() const;
    int getGrade() const;
    void upGrade();
    void downGrade();

    class GradeTooHighException : public std::exception 
    {
        public:
            virtual const char* what() const throw() 
            {
                return "Grade too high!";
            }
    };

    class GradeTooLowException : public std::exception 
    {
        public:
            virtual const char* what() const throw() 
            {
                return "Grade too low!";
            }
    };

private:
    const std::string name;
    int grade;

    void exceptions(int grade);
};

std::ostream & operator<<(std::ostream & ost, Bureaucrat const & bureaucrat);

#endif
