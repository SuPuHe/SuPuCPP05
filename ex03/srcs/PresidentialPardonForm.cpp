/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omizin <omizin@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 11:59:30 by omizin            #+#    #+#             */
/*   Updated: 2025/12/02 11:59:37 by omizin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"

PresidentialPardonForm::PresidentialPardonForm(): AForm("DefaultPresidential", 25, 5), _target("Default")
{
	std::cout<<"Default PresidentialPardonForm constructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(std::string target): AForm("PresidentialPardonForm", 25, 5), _target(target)
{
	std::cout<<"PresidentialPardonForm constructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &copy): AForm(copy)
{
	std::cout << "PresidentialPardonForm copy constructor called" << std::endl;
	*this = copy;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(PresidentialPardonForm const &copy)
{
	std::cout << "PresidentialPardonForm copy assigment operator called" << std::endl;
	if (this != &copy)
		return *this;
	return *this;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << "PresidentialPardonForm destructor called" << std::endl;
}

void	PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
	if (!getSigned())
		throw AForm::FormIsNotSignedException();
	if (executor.getGrade() > getGTE())
		throw AForm::GradeTooLowException();

	std::cout << GREEN << _target << " has been pardoned by Zaphod Beeblebrox" << RESET << std::endl;

}
