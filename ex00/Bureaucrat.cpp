/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: areheman <areheman@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 10:51:56 by areheman          #+#    #+#             */
/*   Updated: 2023/01/06 10:21:28 by areheman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.h"

Bureaucrat::Bureaucrat()
{
	std::cout<<"Bureaucrat default constructor"<<std::endl;

}

Bureaucrat::Bureaucrat(std::string name, int grade):name(name), grade(grade)
{
	if (grade > 150)
		throw GradeTooLowExecption();
	if (grade < 1)
		throw GradeTooHighExecption();
	std::cout<<"Bureaucrat default constructor"<<std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat& obj):name(obj.getName()),grade(obj.grade)
{
	std::cout<<"Bureaucrat copy constructor"<<std::endl;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& obj)
{
	std::cout<<"Bureaucrat copy constructor"<<std::endl;
	if (this == &obj)
		return (*this);
	grade = obj.getGrade();
	return (*this);
}

Bureaucrat::~Bureaucrat()
{
	std::cout<<"Bureaucrat desstructor"<<std::endl;
}

std::string Bureaucrat::getName() const
{
	return (name);
}

int Bureaucrat::getGrade() const
{
	return (grade);
}

void Bureaucrat::increaseGrade()
{
	if (grade > 1)
		grade--;
	else 
		throw Bureaucrat::GradeTooHighExecption();
}

void Bureaucrat::decreaseGrade()
{
	if (grade < 150)
		grade++;
	else 
		throw Bureaucrat::GradeTooLowExecption();
}
/*
std::string Bureaucrat::GradeTooHighExecption() const
{
	return ("GradeTooHighExecption");
}

std::string Bureaucrat::GradeTooLowExecption() const
{
	return ("GradeTooLowExecption");
}
*/
std::ostream& operator<<(std::ostream& ou, const Bureaucrat& o)
{
	ou<<o.getName()<<", bureacrat grade "<<o.getGrade()<<".";
	return (ou);
}



