/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: areheman <areheman@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 12:41:54 by areheman          #+#    #+#             */
/*   Updated: 2023/01/09 13:31:02 by areheman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.h"
#include "Bureaucrat.h"
#include "ShrubberyCreationForm.h"
#include "RobotomyRequestForm.h"
#include "PresidentialPardonForm.h"

int main()
{
	/*
	AForm *a = new 	ShrubberyCreationForm("home");
	AForm *b = new 	RobotomyRequestForm("robot");
	AForm *c = new 	PresidentialPardonForm("criminal");
	*/
	ShrubberyCreationForm	a("home");
	RobotomyRequestForm		b("robot");
	PresidentialPardonForm 	c("criminal");
	Bureaucrat	tom("tom", 5);
	Bureaucrat	sam("sam", 46);
	
	std::cout<<"Form c  ++++++++++"<<std::endl;
	tom.signForm(c);
	sam.executeForm(c);
	tom.executeForm((c));
	
	std::cout<<"Form b  ++++++++++"<<std::endl;
	sam.signForm(b);
	sam.executeForm(b);
	tom.executeForm((b));

	std::cout<<"Form a  ++++++++++"<<std::endl;
	sam.signForm(a);
	sam.executeForm(a);		
	tom.executeForm((a));

	// delete	a;
	// delete	b;
	// delete	c;
	return 0;
}