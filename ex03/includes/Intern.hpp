/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omizin <omizin@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 13:31:49 by omizin            #+#    #+#             */
/*   Updated: 2025/12/03 13:47:16 by omizin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "main.hpp"

class Intern
{
	public:
		Intern();
		Intern(Intern const &copy);
		Intern &operator=(Intern const &copy);
		~Intern();

		AForm	*makeForm(std::string form_name, std::string form_target);
};
