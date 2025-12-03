/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omizin <omizin@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 13:47:54 by omizin            #+#    #+#             */
/*   Updated: 2025/11/27 14:51:40 by omizin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"

AForm::AForm(): _name("Default"), _signed(false), _grade_to_sign(75), _grade_to_execute(75)
{
	std::cout<<"Default AForm constructor called" << std::endl;
}

AForm::AForm(std::string name, int gts, int gte): _name(name), _signed(false), _grade_to_sign(gts), _grade_to_execute(gte)
{
	std::cout<<"AForm constructor called" << std::endl;
	if (_grade_to_sign < 1 || _grade_to_execute < 1)
		throw GradeTooHighException();
	if (_grade_to_sign > 150 || _grade_to_execute > 150)
		throw GradeTooLowException();
}

AForm::AForm(AForm const &copy): _name(copy._name), _signed(copy._signed), _grade_to_sign(copy._grade_to_sign), _grade_to_execute(copy._grade_to_execute)
{
	std::cout << "AForm copy constructor called" << std::endl;
}

AForm &AForm::operator=(AForm const &copy)
{
	std::cout << "AForm copy assigment operator called" << std::endl;
	if (this != &copy)
		_signed = copy._signed;
	return *this;
}

AForm::~AForm()
{
	std::cout << "AForm destructor called" << std::endl;
}

std::string	AForm::getName() const { return _name; }
bool		AForm::getSigned()const { return _signed; }
int			AForm::getGTS()const { return _grade_to_sign; }
int			AForm::getGTE()const { return _grade_to_execute; }

void		AForm::beSigned(Bureaucrat const &b)
{
	if (b.getGrade() <= _grade_to_sign)
	{
		if (_signed){
			std::cout << RED << "This AForm already signed" << RESET << std::endl;
			return ;
		}
		_signed = true;
	}
	else
		throw GradeTooLowException();
}

const char	*AForm::GradeTooHighException::what() const throw()
{
	return RED "Grade is too high" RESET;
}

const char	*AForm::GradeTooLowException::what() const throw()
{
	return RED "Grade is too low" RESET;
}

const char *AForm::FormIsNotSignedException::what() const throw()
{
	return RED "Form is not signed" RESET;
}

std::ostream &operator<<(std::ostream &out, const AForm &f)
{
	out << MAGENTA << f.getName() << " status:\nSigned: " << f.getSigned()
	<< "\nGrade to sign: " << f.getGTS()
	<< "\nGrade to execute: " << f.getGTE() << RESET << std::endl;
	return out;
}
