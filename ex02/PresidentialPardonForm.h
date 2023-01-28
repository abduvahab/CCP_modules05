/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.h                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: areheman <areheman@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 15:37:16 by areheman          #+#    #+#             */
/*   Updated: 2023/01/08 14:24:57 by areheman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_H
#define PRESIDENTIALPARDONFORM_H

#include "AForm.h"

class PresidentialPardonForm :public AForm
{
	private:
			std::string target;
	public:
			PresidentialPardonForm(std::string target);
			~PresidentialPardonForm();
			PresidentialPardonForm(const PresidentialPardonForm& obj);
			PresidentialPardonForm& operator=(const PresidentialPardonForm& obj);
			void	execute(Bureaucrat const & executor) const;
};

#endif