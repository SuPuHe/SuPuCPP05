/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omizin <omizin@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 11:38:13 by omizin            #+#    #+#             */
/*   Updated: 2025/12/03 13:31:10 by omizin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(): AForm("DefaultShrubbery", 145, 137), _target("Default")
{
	std::cout<<"Default ShrubberyCreationForm constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target): AForm("ShrubberyCreationForm", 145, 137), _target(target)
{
	std::cout<<"ShrubberyCreationForm constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &copy): AForm(copy)
{
	std::cout << "ShrubberyCreationForm copy constructor called" << std::endl;
	*this = copy;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(ShrubberyCreationForm const &copy)
{
	std::cout << "ShrubberyCreationForm copy assigment operator called" << std::endl;
	if (this != &copy)
		return *this;
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "ShrubberyCreationForm destructor called" << std::endl;
}

void	ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
	if (!getSigned())
		throw AForm::FormIsNotSignedException();
	if (executor.getGrade() > getGTE())
		throw AForm::GradeTooLowException();

	std::ofstream file(_target + "_shrubbery");
	if (!file)
	{
		std::cout << RED << "Error creating file" << RESET << std::endl;
		return ;
	}
	file <<
		"                                                 \n"
		"                       O                         \n"
		"                      ***                        \n"
		"                     **O**                       \n"
		"                    *******                      \n"
		"                   *********                     \n"
		"                  ***********                    \n"
		"                   ******o**                     \n"
		"                  ***********                    \n"
		"                 ****o********                   \n"
		"                ***************                  \n"
		"               ****o***o********                 \n"
		"              *******************                \n"
		"            ***********************              \n"
		"               *****O***********                 \n"
		"              **********o********                \n"
		"             ****************o****               \n"
		"            **O********************              \n"
		"           ***********o********O****             \n"
		"         *****************************           \n"
		"             *********************               \n"
		"            ***o*******************              \n"
		"           ***********o*******o*****             \n"
		"          ***************************            \n"
		"         ***********************O*****           \n"
		"        ***O***************************          \n"
		"      ***********************************        \n"
		"           *************************             \n"
		"          *******o********o**********            \n"
		"         *****************************           \n"
		"        **************o****************          \n"
		"       *************************O*******         \n"
		"      *****O*****************************        \n"
		"    **************o************************      \n"
		"          ***************************            \n"
		"         *************o***************           \n"
		"        ***********o*******************          \n"
		"       **************************O******         \n"
		"      ***o******************O************        \n"
		"    ***o***********o****************o******      \n"
		"                      ###                        \n"
		"                      ###                        \n"
		"                      ###                        \n"
		"                  ###########                    \n"
		"                  ###########                    \n";
	file.close();

}
