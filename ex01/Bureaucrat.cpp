/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: areheman <areheman@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 10:51:56 by areheman          #+#    #+#             */
/*   Updated: 2023/01/06 16:03:55 by areheman         ###   ########.fr       */
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
		throw GradeTooLowExcption();
	if (grade < 1)
		throw GradeTooHighExcption();
	std::cout<<"Bureaucrat constructor with arguments"<<std::endl;
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
		throw Bureaucrat::GradeTooHighExcption();
}

void Bureaucrat::decreaseGrade()
{
	if (grade < 150)
		grade++;
	else 
		throw Bureaucrat::GradeTooLowExcption();
}

std::ostream& operator<<(std::ostream& ou, const Bureaucrat& o)
{
	ou<<o.getName()<<", bureacrat grade "<<o.getGrade()<<".";
	return (ou);
}

void	Bureaucrat::signForm(Form& obj)
{

	try
	{
		obj.beSigned(*this);
		std::cout<<name<<" signed ";
		std::cout<<obj.getName()<<std::endl;	
	}
	catch(const std::exception& e)
	{
		std::cout<<name<<" could't sign ";
		std::cout<<obj.getName();
		std::cout<<" beacause the "<<e.what()<<std::endl;
	}
	

	/*
	if (grade <= obj.getGrade_to_sign())
	{
		obj.beSigned((*this));
		std::cout<<name<<" signed ";
		std::cout<<obj.getName()<<std::endl;
	}
	else
	{
		std::cout<<name<<" could't sign ";
		std::cout<<obj.getName();
		std::cout<<" beacause his grade is low"<<std::endl;
	}
	*/	
}



