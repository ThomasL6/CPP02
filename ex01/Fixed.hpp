/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thlefebv <thlefebv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 13:26:03 by thlefebv          #+#    #+#             */
/*   Updated: 2024/09/09 16:22:55 by thlefebv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
	public:
			//Constructors
			Fixed();
			Fixed(const Fixed &ptr);
			Fixed(int const nb);
			Fixed(float const nb);
			
			~Fixed();

			//setter
			void setRawBits(int const raw);
			
			//getter
			int getRawBits(void) const;
			
			Fixed &operator=(const Fixed &overload);

			float toFloat( void ) const;
			int toInt( void ) const;
			
	private:
			int _fixed;
			static int const _fraction = 8;
};
	
std::ostream &operator<<(std::ostream &value, const Fixed &fixed);

#endif