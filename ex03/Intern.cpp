/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: areheman <areheman@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 15:36:50 by areheman          #+#    #+#             */
/*   Updated: 2023/01/09 13:14:15 by areheman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.h"

Intern::Intern()
{
	std::cout<<"Intern default constructor"<<std::endl;

}

Intern::Intern(const Intern& obj)
{
	std::cout<<"Intern copy constructor"<<std::endl;
	*this = obj;
}

Intern& Intern::operator=(const Intern& obj)
{
	std::cout<<"Intern copy assignement constructor"<<std::endl;
	if (this == &obj)
		return *this;
	*this = obj;
	return *this;
}
/*
AForm* Intern::makeForm(std::string name, std::string target) const
{
//	AForm* p;
	AForm* form[]={new ShrubberyCreationForm(target),\
			new RobotomyRequestForm(target),\
			new PresidentialPardonForm(target)};
	for (int i = 0; i< 3;i++)
	{
		if (name.compare(form[i]->getName()) == 0)
		{
			std::cout<<"Intern create "<<name<<std::endl;

			return form[i];
		//	delete form;
		//	return p;
		}
	}
	std::cout<<name<<"doesn't exit!"<<std::endl;
	return NULL;
}
*/

AForm* Intern::makeForm(std::string name, std::string target) const
{
	int i;
	AForm* p;
	std::string form[3]={"shrubbery creation","robotomy request","presidential pardon"};
	for (i = 0; i< 3;i++)
	{
		if (name.compare(form[i]) == 0)
		{
			std::cout<<"Intern create "<<name<< " form"<<std::endl;
			break;
		}
	}
	switch (i)
	{
		case 0:
				p = new ShrubberyCreationForm(target);
				break;
		case 1:
				p = new RobotomyRequestForm(target);
				break;
		case 2:
				p = new PresidentialPardonForm(target);
				break;
		case 3:
				p = NULL;
				break;
	}
	if (p == NULL)
	{
		std::cout<<name;
		throw NotExitForm();
	}
	return p;
}

Intern::~Intern()
{
	std::cout<<"Intern destructor"<<std::endl;
}