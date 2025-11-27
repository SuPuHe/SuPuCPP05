/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omizin <omizin@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 12:17:39 by omizin            #+#    #+#             */
/*   Updated: 2025/11/27 12:34:22 by omizin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(): _name("Default"), _grade(75)
{
	std::cout<<"Default Bureaucrat constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(std::string name, int grade): _name(name), _grade(grade)
{
	std::cout<<"Bureaucrat constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(Bureaucrat const &copy): _name(copy._name), _grade(copy._grade)
{
	std::cout << "Bureaucrat copy constructor called" << std::endl;
}

Bureaucrat &Bureaucrat::operator=(Bureaucrat const &copy)
{
	std::cout << "Bureaucrat copy assigment operator called" << std::endl;
	if (this != &copy)
	{
		_name = copy._name;
		_grade = copy._grade;
	}
	return *this;
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "Bureaucrat destructor called" << std::endl;
}

std::string	Bureaucrat::getName() const { return _name; }

int			Bureaucrat::getGrade() const { return _grade; }

void		Bureaucrat::incrementGrade()
{
	if (_grade == 1)
	{
		std::cout << "Grade too hight already" << std::endl;
		return;
	}
	_grade++;
}

void		Bureaucrat::decrementGrade()
{
	if (_grade == 150)
	{
		std::cout << "Grade too low already" << std::endl;
		return;
	}
	_grade--;
}

std::ostream &operator<<(std::ostream &out, const Bureaucrat &b)
{
	out << b.getName() << ": grade - " << b.getGrade() << std::endl;
	return out;
}
