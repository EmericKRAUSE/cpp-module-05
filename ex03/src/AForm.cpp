 #include "../includes/AForm.hpp"
 #include "../includes/Bureaucrat.hpp"

//	####################
//	Constructor & Destructor
AForm::AForm() :
	_name("Default"),
	_isSigned(false),
	_gradeRequiredToSign(150),
	_gradeRequiredToExecute(150)
{
	std::cout << "Default constructor called" << std::endl;
}

AForm::AForm(const std::string &name, const int gradeRequiredToSign, const int gradeRequiredToExecute) :
	_name(name),
	_isSigned(false),
	_gradeRequiredToSign(gradeRequiredToSign),
	_gradeRequiredToExecute(gradeRequiredToExecute)
{
	if (_gradeRequiredToSign < 1)
		throw (GradeTooHighException());
	if (_gradeRequiredToSign > 150)
		throw (GradeTooLowException());
	if (_gradeRequiredToExecute < 1)
		throw(GradeTooHighException());
	if (_gradeRequiredToExecute > 150)
		throw(GradeTooLowException());
	std::cout 	<< "AForm "
				<< CYAN << getName() << RESET
				<< " has been created, Signed: "
				<< CYAN << getIsSigned() << RESET
				<< ", Grade required to sign: "
				<< CYAN << getGradeRequiredToSign() << RESET
				<< ", Grade required to execute: "
				<< CYAN << getGradeRequiredToExecute() << RESET
				<< std::endl;
}

AForm::AForm(const AForm &copy) :
	_name(copy.getName() + " (copy)"),
	_gradeRequiredToSign(copy.getGradeRequiredToSign()),
	_gradeRequiredToExecute(copy.getGradeRequiredToExecute())
{
	std::cout << "Copy construcor called" << std::endl;
	*this = copy;
}

AForm::~AForm()
{
	std::cout	<< "AForm "
				<< CYAN << getName() << RESET
				<< " has been deleted."
				<< std::endl;
}

//	####################
//	Operator Overload
AForm& AForm::operator=(const AForm& obj)
{
	if (this != &obj)
	{
		setIsSigned(getIsSigned());
	}
	return (*this);
}

std::ostream &operator<<(std::ostream &os, const AForm &obj)
{
	os	<< CYAN << obj.getName() << RESET
		<< " grade to sign: "
		<< CYAN << obj.getGradeRequiredToSign() << RESET
		<< " grade to execute: "
		<< CYAN << obj.getGradeRequiredToExecute() << RESET;
	return (os);
}

//	####################
//	Getters & Setters
const std::string& AForm::getName() const
{ return (this->_name); }

bool AForm::getIsSigned() const
{ return (this->_isSigned); }

int AForm::getGradeRequiredToSign() const
{ return (this->_gradeRequiredToSign); }

int AForm::getGradeRequiredToExecute() const
{ return (this->_gradeRequiredToExecute); }

void AForm::setIsSigned(bool isSigned)
{ this->_isSigned = isSigned; }

//	####################
//	Methodes
void AForm::beSigned(const Bureaucrat& bureaucrat)
{
	if (bureaucrat.getGrade() > getGradeRequiredToSign())
		throw GradeTooLowException();
	if (getIsSigned() == false)
		setIsSigned(true);
}

void AForm::checkExecutability(const Bureaucrat& executor) const
{
	if (getIsSigned() == false)
		throw(NotSignedExeption());
	if (executor.getGrade() > getGradeRequiredToExecute())
		throw(GradeTooLowException());
}

//	####################
//	Exeption classes
const char* AForm::GradeTooHighException::what() const throw()
{
	return (RED "Grade too high" RESET);
}

const char* AForm::GradeTooLowException::what() const throw()
{
	return (RED "Grade too low" RESET);
}

const char *AForm::NotSignedExeption::what() const throw()
{
	return (RED "Form not signed" RESET);
}