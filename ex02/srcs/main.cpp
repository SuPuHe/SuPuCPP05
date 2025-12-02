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
	Bureaucrat a("Alice", 5);
	ShrubberyCreationForm s("home");

	a.signForm(s);
	a.executeForm(s);

	return 0;
}
