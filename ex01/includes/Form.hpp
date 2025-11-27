/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omizin <omizin@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 13:47:33 by omizin            #+#    #+#             */
/*   Updated: 2025/11/27 14:51:50 by omizin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "main.hpp"

class Form
{
	private:
		const std::string				_name;
		bool							_signed;
		const int						_grade_to_sign;
		const int						_grade_to_execute;
	public:
		Form();
		Form(std::string name, int gts, int gte);
		Form(Form const &copy);
		Form &operator=(Form const &copy);
		~Form();

		std::string	getName()const;
		bool		getSigned()const;
		int			getGTS()const;
		int			getGTE()const;

		void		beSigned(Bureaucrat const &b);

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

std::ostream &operator<<(std::ostream &out, const Form &f);
