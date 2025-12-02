/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omizin <omizin@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 11:38:56 by omizin            #+#    #+#             */
/*   Updated: 2025/12/02 11:59:02 by omizin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"

RobotomyRequestForm::RobotomyRequestForm(): AForm("DefaultRobotomy", 72, 45), _target("Default")
{
	std::cout<<"Default RobotomyRequestForm constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target): AForm("RobotomyRequestForm", 72, 45), _target(target)
{
	std::cout<<"RobotomyRequestForm constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &copy): AForm(copy)
{
	std::cout << "RobotomyRequestForm copy constructor called" << std::endl;
	*this = copy;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(RobotomyRequestForm const &copy)
{
	std::cout << "RobotomyRequestForm copy assigment operator called" << std::endl;
	if (this != &copy)
		return *this;
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << "RobotomyRequestForm destructor called" << std::endl;
}

void	RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
	if (!getSigned())
		throw AForm::FormIsNotSignedException();
	if (executor.getGrade() > getGTE())
		throw AForm::GradeTooLowException();

	std::cout << "* drilling noises *" << std::endl;

	if (rand() % 2)
		std::cout << GREEN << _target << " has been robotomized successfully" << RESET << std::endl;
	else
		std::cout << RED << "Robotomy of " << _target << " has failed" << RESET << std::endl;

}
