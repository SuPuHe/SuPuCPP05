/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omizin <omizin@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 13:32:25 by omizin            #+#    #+#             */
/*   Updated: 2025/12/03 14:59:01 by omizin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"

Intern::Intern()
{
	std::cout<<"Default Intern constructor called" << std::endl;
}

Intern::Intern(Intern const &copy)
{
	std::cout << "Intern copy constructor called" << std::endl;
	*this = copy;
}

Intern &Intern::operator=(Intern const &copy)
{
	std::cout << "Intern copy assigment operator called" << std::endl;
	if (this != &copy)
		return *this;
	return *this;
}

Intern::~Intern()
{
	std::cout << "Intern destructor called" << std::endl;
}

std::string toLowerLoop(std::string str)
{
	for (char &c : str)
		c = std::tolower(static_cast<unsigned char>(c));
	return str;
}

AForm *Intern::makeForm(std::string form_name, std::string form_target)
{

	std::string nameLower = toLowerLoop(form_name);

	std::string names[3] = {
		"shrubbery creation",
		"robotomy request",
		"presidential pardon"
	};

	std::function<AForm*(std::string)> forms[3] = {
		[](std::string target) -> AForm* { return new ShrubberyCreationForm(target); },
		[](std::string target) -> AForm* { return new RobotomyRequestForm(target); },
		[](std::string target) -> AForm* { return new PresidentialPardonForm(target); }
	};

	for (int i = 0; i < 3; i++)
	{
		if (nameLower == names[i])
		{
			std::cout << GREEN << "Intern creates " << nameLower << RESET << std::endl;
			return forms[i](form_target);
		}
	}

	std::cout << RED << "Unknown form" << RESET << std::endl;
	return NULL;
}



