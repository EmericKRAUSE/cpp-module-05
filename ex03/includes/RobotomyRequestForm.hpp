#pragma once

# include "AForm.hpp"

# include <string>
# include <stdexcept>
# include <iostream>
# include <cstdlib>

# define RED "\033[31m"
# define GREEN "\033[32m"
# define CYAN "\033[36m"
# define RESET "\033[0m"

class RobotomyRequestForm : public AForm
{
	private:
		const std::string _target;

	public:
		//	####################
		//	Constructor & Destructor
		RobotomyRequestForm(const std::string& target);
		~RobotomyRequestForm();

		//	####################
		//	Getters & Setters
		const std::string& getTarget() const;

		//	####################
		//	Methodes
		void execute(const Bureaucrat &executor) const;
};