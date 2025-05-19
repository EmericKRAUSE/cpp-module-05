#pragma once

# include <string>
# include <stdexcept>
# include <iostream>

# define RED "\033[31m"
# define GREEN "\033[32m"
# define CYAN "\033[36m"
# define RESET "\033[0m"

class Bureaucrat
{
	private:
		const std::string	_name;
		int					_grade;

	public:
		//	####################
		//	Constructor & Destructor
		Bureaucrat(void);
		Bureaucrat(std::string name, int grade);
		Bureaucrat(const Bureaucrat& copy);
		~Bureaucrat();

		//	####################
		//	Operator Overload
		Bureaucrat& operator=(const Bureaucrat& obj);

		//	####################
		//	Getters & Setters
		std::string	getName() const;
		int			getGrade() const;
		void		setGrade(const int grade);

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

		//	####################
		//	Methodes
		void	upGrade();
		void	downGrade();
};

std::ostream& operator<<(std::ostream& r, const Bureaucrat& obj);