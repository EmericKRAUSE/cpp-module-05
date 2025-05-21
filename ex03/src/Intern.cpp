#include "../includes/Intern.hpp"
#include "../includes/ShrubberyCreationForm.hpp"
#include "../includes/RobotomyRequestForm.hpp"
#include "../includes/PresidentialPardonForm.hpp"

//	####################
//	Constructor & Destructor
Intern::Intern()
{
	std::cout << "Intern constructor called" << std::endl;
}

Intern::Intern(const Intern &copy)
{
	(void)copy;
}

Intern::~Intern()
{
	std::cout << "Intern destructor called" << std::endl;
}

//	####################
//	Operator Overload
Intern& Intern::operator=(const Intern &obj)
{
	(void)obj;
	return (*this);
}

//	####################
//	Methodes
AForm* Intern::makeForm(const std::string &formName, const std::string &formTarget) const
{
	std::string formList[] = {"shrubbery creation", "robotomy request", "presidential pardon"};
	int i = 0;
	while (i < 3 && formName != formList[i])
		i++;
	switch (i)
	{
		case 0:
			std::cout	<< "Intern creates "
						<< formName << std::endl;
			return (new ShrubberyCreationForm(formTarget));
		case 1:
			std::cout << "Intern creates "
					  << formName << std::endl;
			return (new RobotomyRequestForm(formTarget));
		case 2:
			std::cout << "Intern creates "
					  << formName << std::endl;
			return (new PresidentialPardonForm(formTarget));
		default:
			std::cout	<< "Form "
						<< formName 
						<<	" does not exit" << std::endl;
			return NULL;
	}
}