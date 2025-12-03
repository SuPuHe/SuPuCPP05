/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omizin <omizin@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 13:12:25 by omizin            #+#    #+#             */
/*   Updated: 2025/12/03 13:43:46 by omizin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"

int main()
{
	srand(time(NULL));

	std::cout << "\n=== Creating Forms and Bureaucraft ===" << std::endl;

	ShrubberyCreationForm shrubbery("home");
	RobotomyRequestForm robotomy("human");
	PresidentialPardonForm presidential("robo");

	Bureaucrat hight("Hight-rank", 1);
	Bureaucrat mid("Mid-rank", 75);
	Bureaucrat low("Low-rank", 150);

	std::cout << shrubbery << std::endl;
	std::cout << robotomy << std::endl;
	std::cout << presidential << std::endl;

	std::cout << "\n=== Trying to execute not signed forms ===" << std::endl;
	try
	{
		hight.executeForm(presidential);
	}
	catch (std::exception &e)
	{
		std::cout << "Exception caught: " << e.what() << std::endl;
	}
	try
	{
		mid.executeForm(shrubbery);
	}
	catch (std::exception &e)
	{
		std::cout << "Exception caught: " << e.what() << std::endl;
	}
	std::cout << "\n=== Trying to execute form with wrong grade ===" << std::endl;

	hight.signForm(shrubbery);
	hight.signForm(robotomy);
	hight.signForm(presidential);

	try
	{
		low.executeForm(robotomy);
	}
	catch (std::exception &e)
	{
		std::cout << "Exception caught: " << e.what() << std::endl;
	}
	try
	{
		mid.executeForm(presidential);
	}
	catch (std::exception &e)
	{
		std::cout << "Exception caught: " << e.what() << std::endl;
	}
	std::cout << "\n=== Execute shrubbery form ===" << std::endl;

	mid.executeForm(shrubbery);

	std::cout << "\n=== Execute robotomy form 10 times ===" << std::endl;

	for (int i = 0; i < 10; i++)
		hight.executeForm(robotomy);

	std::cout << "\n=== Execute presidential form ===" << std::endl;

	hight.executeForm(presidential);

	return 0;
}
