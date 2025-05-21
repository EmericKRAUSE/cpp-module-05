#include "includes/Bureaucrat.hpp"
#include "includes/AForm.hpp"
#include "includes/ShrubberyCreationForm.hpp"
#include "includes/RobotomyRequestForm.hpp"
#include "includes/PresidentialPardonForm.hpp"
#include "includes/Intern.hpp"

int main()
{
	srand(time(NULL));
	std::cout << GREEN << "\nObject initialisation:" << RESET << std::endl;
	Bureaucrat	b1("Bernard", 1);
	Intern		intern;
	AForm*		shrubbery = intern.makeForm("shrubbery creation", "home");
	AForm*		robotomy = intern.makeForm("robotomy request", "jack");
	AForm*		presidential = intern.makeForm("presidential pardon", "luc");
	AForm*		random = intern.makeForm("random", "random");

	try
	{

		std::cout << GREEN << "\nExecution:" << RESET << std::endl;
		if (shrubbery)
			b1.executeForm(*shrubbery);
		if (robotomy)
			b1.executeForm(*robotomy);
		if (presidential)
			b1.executeForm(*presidential);
		if (random)
			b1.executeForm(*random);
	}
	catch (const std::exception &e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
	}

	std::cout << GREEN << "\nDestructor:" << RESET << std::endl;
	delete shrubbery;
	delete robotomy;
	delete presidential;
	delete random;
}