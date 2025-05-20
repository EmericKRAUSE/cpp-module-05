#pragma once

# include <string>
# include <stdexcept>
# include <iostream>

# define RED "\033[31m"
# define GREEN "\033[32m"
# define CYAN "\033[36m"
# define RESET "\033[0m"

class Bureaucrat;

class Form
{
	private:
		const std::string	_name;
		bool				_isSigned;
		const int			_gradeRequiredToSign;
		const int			_gradeRequiredToExecute;
	
	public:
		//	####################
		//	Constructor & Destructor
		Form();
		Form(const std::string &name, const int gradeRequiredToSign, const int gradeRequiredToExecute);
		Form(const Form& copy);
		~Form();

		//	####################
		//	Operator Overload
		Form& operator=(const Form &obj);

		//	####################
		//	Getters & Setters
		const std::string&	getName() const;
		bool				getIsSigned() const;
		int					getGradeRequiredToSign() const;
		int					getGradeRequiredToExecute() const;
		void				setIsSigned(bool isSigned);

		//	####################
		//	Methodes
		void				beSigned(const Bureaucrat& bureaucrat);

		//	####################
		//	Exception classes
		class GradeTooHighException : public std::exception
		{
			public:
				const char *what() const throw();
		};

		class GradeTooLowException : public std::exception
		{
			public:
				const char *what() const throw();
		};
};

std::ostream &operator<<(std::ostream &r, const Form &obj);