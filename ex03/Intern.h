/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: areheman <areheman@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 15:26:49 by areheman          #+#    #+#             */
/*   Updated: 2023/01/09 13:24:48 by areheman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_H
#define INTERN_H

#include "Bureaucrat.h"
#include "ShrubberyCreationForm.h"
#include "RobotomyRequestForm.h"
#include "PresidentialPardonForm.h"

class Intern
{	
	public:
		Intern();
		Intern(const Intern& obj);
		~Intern();
		
		Intern& operator=(const Intern& obj);
		AForm* makeForm(std::string name, std::string target) const;

		class NotExitForm:public std::exception
		{
			const char* what() const throw()
			{
				return " form doesn't exit!";
			}
		};
};
#endif