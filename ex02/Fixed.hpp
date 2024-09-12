/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thlefebv <thlefebv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 13:26:03 by thlefebv          #+#    #+#             */
/*   Updated: 2024/09/10 19:31:58 by thlefebv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>
#include <bitset>

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

			float toFloat(void) const;
			int toInt(void) const;
			
			static			Fixed& min(Fixed& nb1, Fixed& nb2);
			static const	Fixed& min(const Fixed& nb1, const Fixed& nb2);
			static			Fixed& max(Fixed& nb1, Fixed& nb2);
			static const	Fixed& max(const Fixed& nb1, const Fixed& nb2);
	
			//Comparison operators
			bool operator>(const Fixed& nb);
			bool operator<(const Fixed& nb);
			bool operator>=(const Fixed& nb);
			bool operator<=(const Fixed& nb);
			bool operator==(const Fixed& nb);
			bool operator!=(const Fixed& nb);
			
			//Math operators
			Fixed operator+(const Fixed &nb);
			Fixed operator-(const Fixed &nb);
			Fixed operator/(const Fixed &nb);
			Fixed operator*(const Fixed &nb);
			

			//Increment operators
			Fixed &operator++(void);
			Fixed &operator--(void);
			Fixed operator--(int);
			Fixed operator++(int);

	private:
			int _fixed;
			static int const _fraction = 8;
};
	
std::ostream &operator<<(std::ostream &value, const Fixed &fixed);

#endif