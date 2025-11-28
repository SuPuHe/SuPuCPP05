/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omizin <omizin@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 13:12:25 by omizin            #+#    #+#             */
/*   Updated: 2025/11/27 13:47:53 by omizin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"

int main()
{
	std::cout << "\n=== Creating Forms ===" << std::endl;
	try
	{
		Form f1("good", 10, 5);
		Form f2("good1", 100, 100);

		std::cout << f1 << std::endl;
		std::cout << f2 << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << "Exception caught: " << e.what() << std::endl;
	}

	std::cout << "\n=== Creating Invalid Forms ===" << std::endl;
	try
	{
		Form f("wrong", 0, 10);
	}
	catch (std::exception &e)
	{
		std::cout << "Exception caught: " << e.what() << std::endl;
	}
	try
	{
		Form f("wrong1", 10, 200);
	}
	catch (std::exception &e)
	{
		std::cout << "Exception caught: " << e.what() << std::endl;
	}

	std::cout << "\n=== Bureaucrats signing forms ===" << std::endl;

	Bureaucrat a("Alice", 5);
	Bureaucrat b("Bob", 50);
	Form hight("Hightpriority", 10, 5);
	Form low("Lowpriority", 120, 20);

	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << hight << std::endl;
	std::cout << low << std::endl;

	std::cout << "\n== Trying to sign Hightpriority ==" << std::endl;
	a.signForm(hight);
	b.signForm(hight);

	std::cout << "\n== Trying to sign Lowpriority ==" << std::endl;
	b.signForm(low);

	std::cout << "\n=== Final Form States ===" << std::endl;
	std::cout << hight << std::endl;
	std::cout << low << std::endl;

	return 0;
}
