#include "../includes/RobotomyRequestForm.hpp"
#include "../includes/AForm.hpp"
#include "../includes/Bureaucrat.hpp"

//	####################
//	Constructor & Destructor
RobotomyRequestForm::RobotomyRequestForm(const std::string& target) :
	AForm(target, 72, 45), _target(target)
{
	std::cout	<< "RobotomyRequestForm "
				<< CYAN << getTarget() << RESET
				<< " constructor called" << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << "RobotomyRequestForm destructor called" << std::endl;
}

//	####################
//	Getters & Setters
const std::string &RobotomyRequestForm::getTarget() const
{
	return (this->_target);
}

//	####################
//	Methodes
void RobotomyRequestForm::execute(const Bureaucrat &executor) const
{
	checkExecutability(executor);
	std::cout << "\"Makes some drilling noises\"" << std::endl;
	int v1 = rand() % 2;
	if (v1)
	{
		std::cout	<< CYAN << getTarget() << RESET
					<< " has been robotomized successfully "
					<< std::endl;
	}
	else
		std::cout << "Robotomized failed..." << std::endl;
}