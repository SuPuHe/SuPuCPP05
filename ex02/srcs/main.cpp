/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omizin <omizin@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 13:12:25 by omizin            #+#    #+#             */
/*   Updated: 2025/12/02 13:25:39 by omizin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"

int main()
{
	srand(time(NULL));

	Bureaucrat a("Alice", 5);
	ShrubberyCreationForm s("home");
	RobotomyRequestForm form("human");

	a.signForm(s);
	a.signForm(form);
	a.executeForm(s);
	for (int i = 0; i < 10; i++)
		a.executeForm(form);

	return 0;
}
