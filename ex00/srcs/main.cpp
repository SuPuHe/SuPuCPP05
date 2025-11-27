/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omizin <omizin@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 13:12:25 by omizin            #+#    #+#             */
/*   Updated: 2025/11/27 13:26:31 by omizin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{
	std::cout << "=== Creating valid bureaucrats ===" << std::endl;
	try
	{
		Bureaucrat a("BureaucratA", 10);
		Bureaucrat b("BureaucratB", 1);
		Bureaucrat c("BureaucratC", 150);

		std::cout << a << std::endl;
		std::cout << b << std::endl;
		std::cout << c << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << "Exception caught: " << e.what() << std::endl;
	}

	std::cout << std::endl << "=== Creating bureaucrats with invalid grade ===" << std::endl;
	try
	{
		Bureaucrat wrong1("BureaucratHight", 0);
	}
	catch (std::exception& e)
	{
		std::cout << "Exception caught: " << e.what() << std::endl;
	}
	try
	{
		Bureaucrat wrong2("BureaucratLow", 200);
	}
	catch (std::exception& e)
	{
		std::cout << "Exception caught: " << e.what() << std::endl;
	}

	std::cout << std::endl << "=== Testing increment and decrement ===" << std::endl;
	try
	{
		Bureaucrat s("SuPuHe", 5);
		std::cout << s << std::endl;

		s.incrementGrade();
		std::cout << s << std::endl;

		s.decrementGrade();
		std::cout << s << std::endl;

		Bureaucrat j("John", 1);
		std::cout << j << std::endl;

		j.incrementGrade();
		std::cout << j << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << "Exception caught: " << e.what() << std::endl;
	}
	try
	{
		Bureaucrat g("Geece", 150);
		std::cout << g << std::endl;

		g.decrementGrade();
		std::cout << g << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << "Exception caught: " << e.what() << std::endl;
	}

	return 0;
}
