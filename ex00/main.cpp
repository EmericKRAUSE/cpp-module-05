#include "Bureaucrat.hpp"

int main()
{
	try
	{
		Bureaucrat b1("jean", 1);
		std::cout << b1 << std::endl;
		Bureaucrat b2("Bernard", 0);
	}
	catch(const Bureaucrat::GradeTooHighException& e)
	{
		std::cerr << e.what() << std::endl;
	}
	catch(const Bureaucrat::GradeTooLowException& e)
	{
		std::cerr << e.what() << std::endl;
	}

	try
	{
		Bureaucrat b1("jean", 48);
		std::cout << b1 << std::endl;
		Bureaucrat b2("Bernard", 151);
	}
	catch (const Bureaucrat::GradeTooHighException &e)
	{
		std::cerr << e.what() << std::endl;
	}
	catch (const Bureaucrat::GradeTooLowException &e)
	{
		std::cerr << e.what() << std::endl;
	}

	try
	{
		Bureaucrat b1("jean", 1);
		std::cout << b1 << std::endl;
		Bureaucrat b2(b1);
		std::cout << b2 << std::endl;
	}
	catch (const Bureaucrat::GradeTooHighException &e)
	{
		std::cerr << e.what() << std::endl;
	}
	catch (const Bureaucrat::GradeTooLowException &e)
	{
		std::cerr << e.what() << std::endl;
	}
}