/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: areheman <areheman@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 10:22:32 by areheman          #+#    #+#             */
/*   Updated: 2023/01/06 12:02:52 by areheman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_H
#define FORM_H

#include <iostream>
#include <string>
#include "Bureaucrat.h"

class Bureaucrat;

class Form
{
	private:
		std::string  const name;
		bool				_signed;
		int const			grade_to_sign;
		int const			grade_to_exe;
		Form();
	public:
		Form(std::string const name, int const grade_to_sign, int const grade_to_exe);
		Form(const Form& obj);
		Form& operator=(const Form& obj);
		~Form();
		std::string getName() const;
		int			getGrade_to_sign() const;
		int			getGrade_to_exe() const;
		bool			isSigned() const;
	
		void	beSigned(const Bureaucrat& obj);

	class GradeTooHighException: public std::exception
	{
		public:
			const char* what() const throw(){return "Grade Too Heigh";}
	};

	class GradeTooLowException: public std::exception
	{
		public:
			const char* what() const throw(){return "Grade Too Low";}
	};
};

std::ostream& operator<<(std::ostream& o, const Form& obj);

#endif