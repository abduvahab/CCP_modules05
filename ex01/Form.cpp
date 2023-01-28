/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: areheman <areheman@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 10:37:29 by areheman          #+#    #+#             */
/*   Updated: 2023/01/06 11:57:02 by areheman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.h"
/*
Form::Form()
{
	std::cout<<"Form default constructor"<<std::endl;
}
*/
Form::Form(std::string const name, \
		int const grade_to_sign, int const grade_to_exe)\
		:name(name), _signed(false)\
		, grade_to_sign(grade_to_sign)\
		, grade_to_exe(grade_to_exe)
{
	if (grade_to_exe < 1 || grade_to_exe < 1)
		throw Form::GradeTooHighException();
	if (grade_to_exe > 150 || grade_to_sign > 150)
		throw Form::GradeTooLowException();
	std::cout<<"Form constructor with arguments"<<std::endl;
}

Form::Form(const Form& obj)\
		:name(obj.name), _signed(obj._signed)\
		, grade_to_sign(obj.grade_to_sign)\
		, grade_to_exe(obj.grade_to_exe)
{
	std::cout<<"Form copy constructor"<<std::endl;	
}

Form& Form::operator=(const Form& obj)
{
	std::cout<<"Form copy assignement constructor"<<std::endl;	
	if (this == &obj)
		return *this;
	_signed = obj.isSigned();
	return *this;
}


Form::~Form()
{
	std::cout<<"Form destructor"<<std::endl;
}

std::string Form::getName() const
{
	return name;
}

int	Form::getGrade_to_exe() const
{
	return grade_to_exe;
}

int	Form::getGrade_to_sign() const
{
	return grade_to_sign;
}

bool	Form::isSigned() const
{
	return _signed;
}

void	Form::beSigned(const Bureaucrat& obj)
{
	if (obj.getGrade() <= grade_to_sign)
		_signed = true;
	else
		throw Form::GradeTooLowException();
}

std::ostream& operator<<(std::ostream& o, const Form& obj)
{
	o<<"Form name : "<<obj.getName()<<std::endl;
	o<<"Form is signed : "<<(obj.isSigned()?"yes":"no")<<std::endl;
	o<<"Grade requied to sign is : "<<obj.getGrade_to_sign()<<std::endl;
	o<<"Grade required to execute is : "<<obj.getGrade_to_exe()<<std::endl;
	
	return o;
}

