/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omizin <omizin@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 13:12:25 by omizin            #+#    #+#             */
/*   Updated: 2025/12/03 15:02:32 by omizin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"

int main()
{
	srand(time(NULL));

	Intern a;
	AForm* rrf;
	rrf = a.makeForm("robotomy Request", "Bender");

	Bureaucrat b ("as", 1);
	b.signForm(*rrf);
	b.executeForm(*rrf);

	delete rrf;

}
