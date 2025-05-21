#pragma once

# include <string>
# include <stdexcept>
# include <iostream>

# define RED "\033[31m"
# define GREEN "\033[32m"
# define CYAN "\033[36m"
# define RESET "\033[0m"

class Bureaucrat;

class AForm
{
	private:
		const std::string	_name;
		bool				_isSigned;
		const int			_gradeRequiredToSign;
		const int			_gradeRequiredToExecute;
	
	public:
		//	####################
		//	Constructor & Destructor
		AForm();
		AForm(const std::string &name, const int gradeRequiredToSign, const int gradeRequiredToExecute);
		AForm(const AForm& copy);
		virtual ~AForm();

		//	####################
		//	Operator Overload
		AForm& operator=(const AForm &obj);

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
		void				checkExecutability(const Bureaucrat& executor) const;
		virtual	void		execute(const Bureaucrat& executor) const = 0;

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

		class NotSignedExeption : public std::exception
		{
			public:
				const char *what() const throw();
		};
};

std::ostream &operator<<(std::ostream &r, const AForm &obj);