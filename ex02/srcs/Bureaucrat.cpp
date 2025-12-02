/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omizin <omizin@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 12:17:39 by omizin            #+#    #+#             */
/*   Updated: 2025/12/02 11:57:25 by omizin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"

Bureaucrat::Bureaucrat(): _name("Default"), _grade(75)
{
	std::cout<<"Default Bureaucrat constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(std::string name, int grade): _name(name), _grade(grade)
{
	std::cout<<"Bureaucrat constructor called" << std::endl;
	if (_grade < 1)
		throw GradeTooHighException();
	if (_grade > 150)
		throw GradeTooLowException();
}

Bureaucrat::Bureaucrat(Bureaucrat const &copy): _name(copy._name), _grade(copy._grade)
{
	std::cout << "Bureaucrat copy constructor called" << std::endl;
}

Bureaucrat &Bureaucrat::operator=(Bureaucrat const &copy)
{
	std::cout << "Bureaucrat copy assigment operator called" << std::endl;
	if (this != &copy)
		_grade = copy._grade;
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
	if (_grade <= 1)
		throw GradeTooHighException();
	_grade--;
}

void		Bureaucrat::decrementGrade()
{
	if (_grade >= 150)
		throw GradeTooLowException();
	_grade++;
}

void		Bureaucrat::signForm(AForm &f)
{
	try
	{
		f.beSigned(*this);
	}
	catch(const std::exception& e)
	{
		std::cout << _name << " couldn't sign " << f.getName() << " because " << e.what() << std::endl;
		return;
	}
	std::cout << GREEN << _name << " signed " << f.getName() << RESET << std::endl;
}

const char	*Bureaucrat::GradeTooHighException::what() const throw()
{
	return RED "Grade is too high" RESET;
}

const char	*Bureaucrat::GradeTooLowException::what() const throw()
{
	return RED "Grade is too low" RESET;
}

std::ostream &operator<<(std::ostream &out, const Bureaucrat &b)
{
	out << GREEN << b.getName() << ", bureaucrat grade " << b.getGrade() << RESET;
	return out;
}
