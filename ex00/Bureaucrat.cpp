#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(std::string name, int grade)
{
	if (grade < 1)
		throw std::runtime_error("Grade trop haut!");
	if (grade > 150)
		throw std::runtime_error("Grade trop bas!");
	this->_grade = grade;
	this->_name = name;
	std::cout	<< "Bureaucrat "
				<< CYAN
				<< this->_name
				<< RESET
				<< " has been created with a grade of "
				<< CYAN
				<< this->_grade
				<< RESET
				<< std::endl;
}

Bureaucrat::~Bureaucrat()
{
	std::cout	<< "Bureaucrat "
				<< CYAN
				<< this->_name
				<< RESET
				<< " has been deleted"
				<< std::endl;
}