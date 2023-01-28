/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: areheman <areheman@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 12:41:54 by areheman          #+#    #+#             */
/*   Updated: 2023/01/09 13:26:19 by areheman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.h"
#include "Intern.h"
#include "Bureaucrat.h"
#include "ShrubberyCreationForm.h"
#include "RobotomyRequestForm.h"
#include "PresidentialPardonForm.h"

int main()
{

	Intern intern;
	AForm *a;
	AForm *b;
	AForm *c;
	try
	{
		a = intern.makeForm("shrubbery creation", "home");
		b = intern.makeForm("robotomy request", "robot");
		c = intern.makeForm("presidential pardon", "criminal");
		Bureaucrat	tom("tom", 5);
		Bureaucrat	sam("sam", 46);
		
		std::cout<<"Form c  ++++++++++"<<std::endl;
		tom.signForm(*c);
		sam.executeForm(*c);
		tom.executeForm((*c));
		
		std::cout<<"Form b  ++++++++++"<<std::endl;
		sam.signForm(*b);
		sam.executeForm(*b);
		tom.executeForm((*b));

		std::cout<<"Form a  ++++++++++"<<std::endl;
		sam.signForm(*a);
		sam.executeForm(*a);		
		tom.executeForm((*a));

	}
	catch(std::exception& e)
	{
		std::cout<<e.what()<<std::endl;
	}
	if (a != NULL)
		delete	a;
	if (b != NULL)	
		delete	b;
	if (c != NULL)
		delete	c;
	return 0;
}