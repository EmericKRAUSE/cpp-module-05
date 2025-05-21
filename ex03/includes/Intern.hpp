#pragma once

# include <string>
# include <stdexcept>
# include <iostream>

# define RED "\033[31m"
# define GREEN "\033[32m"
# define CYAN "\033[36m"
# define RESET "\033[0m"

class AForm;

class Intern
{
	private:

	public:
		//	####################
		//	Constructor & Destructor
		Intern();
		Intern(const Intern& copy);
		~Intern();

		//	####################
		//	Operator Overload
		Intern &operator=(const Intern &obj);

		//	####################
		//	Methodes
		AForm* makeForm(const std::string& formName, const std::string& formTarget) const;
};
