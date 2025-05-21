#include "includes/Bureaucrat.hpp"
#include "includes/AForm.hpp"
#include "includes/ShrubberyCreationForm.hpp"
#include "includes/RobotomyRequestForm.hpp"
#include "includes/PresidentialPardonForm.hpp"

int main()
{
	srand(time(NULL));
	try
	{
		std::cout << GREEN << "\nObject initialisation:" << RESET << std::endl;
		Bureaucrat b1("Bernard", 1);

		ShrubberyCreationForm s1("shruberry");
		RobotomyRequestForm r1("robotomy");
		PresidentialPardonForm p1("presidential");

		ShrubberyCreationForm s2("shruberry_error");
		RobotomyRequestForm r2("robotomy_error");
		PresidentialPardonForm p2("presidential_error");

		std::cout << GREEN << "\nExecution:" << RESET << std::endl;
		b1.signForm(s1);
		b1.signForm(r1);
		b1.signForm(p1);
		b1.executeForm(s1);
		b1.executeForm(r1);
		b1.executeForm(p1);

		std::cout << GREEN << "\nError test:" << RESET << std::endl;
		b1.executeForm(s2);
		b1.executeForm(r2);
		b1.executeForm(p2);

		std::cout << std::endl;
		b1.setGrade(145);
		b1.signForm(s2);
		b1.executeForm(s2);

		std::cout << std::endl;
		b1.setGrade(72);
		b1.signForm(r2);
		b1.executeForm(r2);

		std::cout << std::endl;
		b1.setGrade(25);
		b1.signForm(p1);
		b1.executeForm(p1);

		std::cout << GREEN << "\nDestructor:" << RESET << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
	}
}