/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: areheman <areheman@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 15:34:42 by areheman          #+#    #+#             */
/*   Updated: 2023/01/08 17:01:12 by areheman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_H
#define ROBOTOMYREQUESTFORM_H

#include "AForm.h"

class RobotomyRequestForm :public AForm
{
	private:
			std::string target;
	public:
			RobotomyRequestForm(std::string target);
			~RobotomyRequestForm();
			RobotomyRequestForm(const RobotomyRequestForm& obj);
			RobotomyRequestForm& operator=(const RobotomyRequestForm& obj);
			void	execute(Bureaucrat const & executor) const;
			std::string getTarget() const;
			void		setTarget(std::string target);
};

#endif