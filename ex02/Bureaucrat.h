/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: areheman <areheman@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 17:14:11 by areheman          #+#    #+#             */
/*   Updated: 2023/01/06 15:19:14 by areheman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_H
#define BUREAUCRAT_H

#include <iostream>
#include <string>
#include <exception>
#include "AForm.h"

class AForm;

class Bureaucrat
{
	private:
			std::string const 	name;
			int					grade;
			Bureaucrat();
	public:
			Bureaucrat(std::string const name, int grade);
			Bureaucrat(const Bureaucrat& obj);
			~Bureaucrat();
			Bureaucrat& operator=(const Bureaucrat& obj);

			std::string	getName() const;
			int			getGrade()const;
			void		increaseGrade();
			void		decreaseGrade();
			void		signForm(AForm& obj);
			void		executeForm(AForm const & form);
			
	class GradeTooHighExcption:public std::exception
	{
		public:
			const char* what() const throw(){return "Grade Too High";}
	};
	class GradeTooLowExcption:public std::exception
	{
		public:
			const char* what() const throw(){return "Grade Too Low";}
	};
};

std::ostream& operator<<(std::ostream& ou, const Bureaucrat& o);

#endif