#include "../includes/Bureaucrat.hpp"
#include "../includes/AForm.hpp"

//	####################
//	Constructor & Destructor
Bureaucrat::Bureaucrat() : _name("Default"), _grade(150)
{
	std::cout << "Default constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name)
{
	if (grade < 1)
		throw GradeTooHighException();
	if (grade > 150)
		throw GradeTooLowException();
	this->_grade = grade;
	std::cout	<< "Bureaucrat "
				<< CYAN
				<< this->getName()
				<< RESET
				<< " has been created with a grade of "
				<< CYAN
				<< this->getGrade()
				<< RESET
				<< std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat& copy) : _name(copy._name + " (copy)")
{
	std::cout << "Copy construcor called" << std::endl;
	*this = copy;
}

Bureaucrat::~Bureaucrat()
{
	std::cout	<< "Bureaucrat "
				<< CYAN
				<< this->getName()
				<< RESET
				<< " has been deleted"
				<< std::endl;
}

//	####################
//	Operator Overload
Bureaucrat& Bureaucrat::operator=(const Bureaucrat& obj)
{
	if (this != &obj)
	{
		setGrade(obj.getGrade());
	}
	return (*this);
}

std::ostream &operator<<(std::ostream &os, const Bureaucrat &obj)
{
	os	<< CYAN
		<< obj.getName()
		<< RESET
		<< ", bureaucrat grade "
		<< CYAN
		<< obj.getGrade()
		<< RESET;
	return (os);
}

//	####################
//	Getters & Setters
std::string Bureaucrat::getName() const
{
	return (this->_name);
}

int	Bureaucrat::getGrade() const
{
	return (this->_grade);
}

void Bureaucrat::setGrade(const int grade)
{
	if (grade < 1)
		throw GradeTooHighException();
	if (grade > 150)
		throw GradeTooLowException();
	this->_grade = grade;
}

//	####################
//	Exeption classes
const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return (RED "Grade too high" RESET);
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return (RED "Grade too low" RESET);
}

//	####################
//	Methodes
void Bureaucrat::upGrade()
{
	setGrade(getGrade() - 1);
}

void Bureaucrat::downGrade()
{
	setGrade(getGrade() + 1);
}

void Bureaucrat::signForm(AForm& form) const
{
	try
	{
		form.beSigned(*this);
		std::cout	<< "Bureaucrat "
					<< CYAN << getName() << RESET
					<< " signed form "
					<< CYAN << form.getName() << RESET
					<< std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout	<< "Bureaucrat "
					<< CYAN << getName() << RESET
					<< " couldn't sign form "
					<< CYAN << form.getName() << RESET
					<< " because "
					<< e.what()
					<< std::endl;
	}
}

void Bureaucrat::executeForm(AForm& form) const
{
	try
	{
		form.execute(*this);
		std::cout	<< "Bureaucrat "
					<< CYAN << getName() << RESET
					<< " executed form "
					<< CYAN << form.getName() << RESET
					<< std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout	<< "Bureaucrat "
					<< CYAN << getName() << RESET
					<< " couldn't execute form "
					<< CYAN << form.getName() << RESET
					<< " because "
					<< e.what()
					<< std::endl;
	}
}