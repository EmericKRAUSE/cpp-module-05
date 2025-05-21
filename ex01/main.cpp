#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
	try
	{
		Bureaucrat	b1("Bernard", 1);
		Form 		f1("Form1", 150, 150);
		Form 		f2("Form2", 10, 10);
		Form		f3("Form3", 1, 1);
		b1.signForm(f1);
		b1.signForm(f2);
		b1.signForm(f3);
		std::cout << f1 << std::endl;
		std::cout << f2 << std::endl;
		std::cout << f3 << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
	}

	std::cout << std::endl;

	try
	{
		Bureaucrat	b1("Bernard", 150);
		Form 		f1("Form1", 150, 150);
		Form 		f2("Form3", 10, 10);
		Form		f3("Form3", 1, 1);
		b1.signForm(f1);
		b1.signForm(f2);
		b1.signForm(f3);
	}
	catch(const std::exception& e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
	}

	std::cout << std::endl;

	try
	{
		Bureaucrat	b1("Bernard", 150);
		Form 		f1("Form1", 151, 150);
		Form 		f2("Form3", 10, 10);
		Form		f3("Form3", 1, 1);
		b1.signForm(f1);
		b1.signForm(f2);
		b1.signForm(f3);
	}
	catch(const std::exception& e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
	}

	std::cout << std::endl;

	try
	{
		Bureaucrat	b1("Bernard", 150);
		Form 		f1("Form1", 0, 0);
		Form 		f2("Form3", 10, 10);
		Form		f3("Form3", 1, 1);
		b1.signForm(f1);
		b1.signForm(f2);
		b1.signForm(f3);
	}
	catch(const std::exception& e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
	}
}