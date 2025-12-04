/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omizin <omizin@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 13:12:25 by omizin            #+#    #+#             */
/*   Updated: 2025/12/04 12:09:40 by omizin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"

int main()
{
	srand(time(NULL));

	std::cout << "=== Creating forms ===\n" << std::endl;

	Intern a;
	AForm* rrf_s;
	AForm* rrf_r;
	AForm* rrf_p;
	Bureaucrat hight ("Hight", 1);

	rrf_s = a.makeForm("shrubbery creation", "home");
	rrf_r = a.makeForm("robotomy Request", "Bender");
	rrf_p = a.makeForm("presidential pardon", "Bender");

	std::cout << *rrf_s << std::endl;
	std::cout << *rrf_r << std::endl;
	std::cout << *rrf_p << std::endl;

	std::cout << "\n=== Trying to execute not signed forms ===" << std::endl;
	try
	{
		hight.executeForm(*rrf_p);
	}
	catch (std::exception &e)
	{
		std::cout << "Exception caught: " << e.what() << std::endl;
	}
	try
	{
		hight.executeForm(*rrf_r);
	}
	catch (std::exception &e)
	{
		std::cout << "Exception caught: " << e.what() << std::endl;
	}

	hight.signForm(*rrf_s);
	hight.signForm(*rrf_r);
	hight.signForm(*rrf_p);


	std::cout << "\n=== Execute shrubbery form ===" << std::endl;

	hight.executeForm(*rrf_s);

	std::cout << "\n=== Execute robotomy form 10 times ===" << std::endl;

	for (int i = 0; i < 10; i++)
		hight.executeForm(*rrf_r);

	std::cout << "\n=== Execute presidential form ===" << std::endl;

	hight.executeForm(*rrf_p);

	delete rrf_s;
	delete rrf_p;
	delete rrf_r;

	return 0;
}
