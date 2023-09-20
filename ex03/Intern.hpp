#ifndef INTERN_HPP
# define INTERN_HPP
# include "AForm.hpp"

class Intern{
    
public:
    Intern();
    Intern(const Intern &other);
    ~Intern();
    Intern &operator=(const Intern &other);
    Form *makeForm(std::string name, std::string target);
};

#endif