/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bajeanno <bajeanno@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 16:44:18 by bajeanno          #+#    #+#             */
/*   Updated: 2024/03/13 16:48:16 by bajeanno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "Form.hpp"

class PresidentialPardonForm : public Form {
private:
	std::string	target;
	PresidentialPardonForm();
public:
	explicit PresidentialPardonForm(const std::string& target);
	void execute(const Bureaucrat& executor);
	PresidentialPardonForm &operator=(const PresidentialPardonForm& other);
};

#endif