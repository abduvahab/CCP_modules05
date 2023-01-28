/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.h                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: areheman <areheman@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 15:20:42 by areheman          #+#    #+#             */
/*   Updated: 2023/01/08 17:00:48 by areheman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_H
#define SHRUBBERYCREATIONFORM_H

#include "AForm.h"
#include <fstream>

class Bureaucrat;

class ShrubberyCreationForm :public AForm
{
	private:
			std::string target;
	public:
			ShrubberyCreationForm(std::string target);
			~ShrubberyCreationForm();
			ShrubberyCreationForm(const ShrubberyCreationForm& obj);
			ShrubberyCreationForm& operator=(const ShrubberyCreationForm& obj);
			void	execute(Bureaucrat const & executor) const;
			std::string getTarget() const;
			void		setTarget(std::string target);
};

#endif