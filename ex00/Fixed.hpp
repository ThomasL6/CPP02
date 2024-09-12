/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thlefebv <thlefebv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 13:26:03 by thlefebv          #+#    #+#             */
/*   Updated: 2024/09/09 14:26:11 by thlefebv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed
{
	public:
			Fixed();
			Fixed(const Fixed &ptr);
			~Fixed();

			//setter
			void setRawBits(int const raw);
			
			//getter
			int getRawBits(void) const;
			
			Fixed &operator = (const Fixed &overload);
			
	private:
			int _fixed;
			static int const _fraction =  8;
};


#endif