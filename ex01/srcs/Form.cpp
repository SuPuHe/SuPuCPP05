/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omizin <omizin@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 13:47:54 by omizin            #+#    #+#             */
/*   Updated: 2025/11/27 14:40:29 by omizin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"

Form::Form(): _name("Default"), _signed(false), _grade_to_sign(75), _grade_to_execute(75)
{
	std::cout<<"Default Form constructor called" << std::endl;
}

Form::Form(std::string name, int gts, int gte): _name(name), _signed(false), _grade_to_sign(gts), _grade_to_execute(gte)
{
	std::cout<<"Form constructor called" << std::endl;
	// if (_grade < 1)
	// 	throw GradeTooHighException();
	// if (_grade > 150)
	// 	throw GradeTooLowException();
}

Form::Form(Form const &copy): _name(copy._name), _signed(copy._signed), _grade_to_sign(copy._grade_to_sign), _grade_to_execute(copy._grade_to_execute)
{
	std::cout << "Form copy constructor called" << std::endl;
}

Form &Form::operator=(Form const &copy)
{
	std::cout << "Form copy assigment operator called" << std::endl;
	if (this != &copy)
		_signed = copy._signed;
	return *this;
}

Form::~Form()
{
	std::cout << "Form destructor called" << std::endl;
}

std::string	Form::getName() const { return _name; }
bool		Form::getSigned()const { return _signed; }
int			Form::getGTS()const { return _grade_to_sign; }
int			Form::getGTE()const { return _grade_to_execute; }

std::ostream &operator<<(std::ostream &out, const Form &f)
{
	out << f.getName() << " status:\nSigned: " << f.getSigned()
	<< "\nGrade to sign: " << f.getGTS()
	<< "\nGrade to execute: " << f.getGTE() << std::endl;
	return out;
}
