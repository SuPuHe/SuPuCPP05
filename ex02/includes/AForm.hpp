/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omizin <omizin@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 13:47:33 by omizin            #+#    #+#             */
/*   Updated: 2025/12/02 11:36:57 by omizin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "main.hpp"

class AForm
{
	private:
		const std::string				_name;
		bool							_signed;
		const int						_grade_to_sign;
		const int						_grade_to_execute;
	public:
		AForm();
		AForm(std::string name, int gts, int gte);
		AForm(AForm const &copy);
		AForm &operator=(AForm const &copy);
		~AForm();

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

std::ostream &operator<<(std::ostream &out, const AForm &f);
