/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omizin <omizin@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 12:06:55 by omizin            #+#    #+#             */
/*   Updated: 2025/11/27 14:54:30 by omizin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "main.hpp"

class Form;

class Bureaucrat
{
	private:
		const std::string	_name;
		int					_grade;
	public:
		Bureaucrat();
		Bureaucrat(std::string name, int grade);
		Bureaucrat(Bureaucrat const &copy);
		Bureaucrat &operator=(Bureaucrat const &copy);
		~Bureaucrat();

		std::string		getName()const;
		int				getGrade()const;

		void			incrementGrade();
		void			decrementGrade();

		void			signForm(Form &f);

		class GradeTooHighException : public std::exception
		{
			public:
				const char *what() const throw();
		};

		class GradeTooLowException : public std::exception
		{
			public:
				const char *what() const throw();
		};

};

std::ostream &operator<<(std::ostream &out, const Bureaucrat &b);
