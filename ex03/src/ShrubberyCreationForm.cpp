#include "../includes/ShrubberyCreationForm.hpp"
#include "../includes/AForm.hpp"
#include "../includes/Bureaucrat.hpp"

//	####################
//	Constructor & Destructor
ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target) :
	AForm(target, 145, 137), _target(target)
{
	std::cout	<< "ShrubberyCreationForm "
				<< CYAN << getTarget() << RESET
				<< " constructor called" << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "ShrubberyCreationForm destructor called" << std::endl;
}

//	####################
//	Getters & Setters
const std::string &ShrubberyCreationForm::getTarget() const
{
	return (this->_target);
}

//	####################
//	Methodes
void ShrubberyCreationForm::execute(const Bureaucrat& executor) const
{
	checkExecutability(executor);
	std::ofstream outfile((getTarget() + "_shrubbery").c_str());
	if (outfile)
	{
		outfile << "       _-_ \n"
				<< "    /~~   ~~\\ \n"
				<< " /~~         ~~\\ \n"
				<< "{               } \n"
				<< " \\  _-     -_  / \n"
				<< "   ~  \\ //  ~ \n"
				<< "_- -   | | _- _ \n"
				<< "  _ -  | |   -_ \n"
				<< "      // \\ \n"
				<< std::endl;
	}
	outfile.close();
}