 #include "Form.hpp"
 #include "Bureaucrat.hpp"

//	####################
//	Constructor & Destructor
Form::Form() :
	_name("Default"),
	_isSigned(false),
	_gradeRequiredToSign(150),
	_gradeRequiredToExecute(150)
{
	std::cout << "Default constructor called" << std::endl;
}

Form::Form(const std::string &name, const int gradeRequiredToSign, const int gradeRequiredToExecute) :
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
	std::cout 	<< "Form "
				<< CYAN << getName() << RESET
				<< " has been created, Signed: "
				<< CYAN << getIsSigned() << RESET
				<< ", Grade required to sign: "
				<< CYAN << getGradeRequiredToSign() << RESET
				<< ", Grade required to execute: "
				<< CYAN << getGradeRequiredToExecute() << RESET
				<< std::endl;
}

Form::Form(const Form &copy) :
	_name(copy.getName() + " (copy)"),
	_gradeRequiredToSign(copy.getGradeRequiredToSign()),
	_gradeRequiredToExecute(copy.getGradeRequiredToExecute())
{
	std::cout << "Copy construcor called" << std::endl;
	*this = copy;
}

Form::~Form()
{
	std::cout	<< "Form "
				<< CYAN << getName() << RESET
				<< " has been deleted."
				<< std::endl;
}

//	####################
//	Operator Overload
Form& Form::operator=(const Form& obj)
{
	if (this != &obj)
	{
		setIsSigned(getIsSigned());
	}
	return (*this);
}

std::ostream &operator<<(std::ostream &os, const Form &obj)
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
const std::string& Form::getName() const
{ return (this->_name); }

bool Form::getIsSigned() const
{ return (this->_isSigned); }

int Form::getGradeRequiredToSign() const
{ return (this->_gradeRequiredToSign); }

int Form::getGradeRequiredToExecute() const
{ return (this->_gradeRequiredToExecute); }

void Form::setIsSigned(bool isSigned)
{ this->_isSigned = isSigned; }

//	####################
//	Methodes
void Form::beSigned(const Bureaucrat& bureaucrat)
{
	if (bureaucrat.getGrade() > getGradeRequiredToSign())
		throw GradeTooLowException();
	if (getIsSigned() == false)
		setIsSigned(true);
}

//	####################
//	Exeption classes
const char *Form::GradeTooHighException::what() const throw()
{
	return (RED "Grade too high" RESET);
}

const char *Form::GradeTooLowException::what() const throw()
{
	return (RED "Grade too low" RESET);
}