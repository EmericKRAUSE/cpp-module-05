#include "../includes/PresidentialPardonForm.hpp"
#include "../includes/AForm.hpp"
#include "../includes/Bureaucrat.hpp"

//	####################
//	Constructor & Destructor
PresidentialPardonForm::PresidentialPardonForm(const std::string& target) :
	AForm(target, 25, 5), _target(target)
{
	std::cout	<< "PresidentialPardonForm "
				<< CYAN << getTarget() << RESET
				<< " constructor called" << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << "PresidentialPardonForm destructor called" << std::endl;
}

//	####################
//	Getters & Setters
const std::string &PresidentialPardonForm::getTarget() const
{
	return (this->_target);
}

//	####################
//	Methodes
void PresidentialPardonForm::execute(const Bureaucrat &executor) const
{
	checkExecutability(executor);
	std::cout	<< CYAN << getTarget() << RESET
				<< " has been pardoned by Zaphod Beeblebrox."
				<< std::endl;
}