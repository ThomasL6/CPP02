/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thlefebv <thlefebv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 13:25:43 by thlefebv          #+#    #+#             */
/*   Updated: 2024/09/09 16:31:57 by thlefebv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"


Fixed::Fixed(): _fixed(0)
{
	std::cout << "Default constructor called" << std::endl;
}



Fixed::Fixed(const Fixed& ptr):_fixed(ptr._fixed)
{
	std::cout << "Copy constructor called" << std::endl;
}


Fixed::Fixed(float const nb) 
{
	std::cout << "Float constructor called" << std::endl;
	this->setRawBits((int)roundf(nb * (1 << this->_fraction)));
}

Fixed::Fixed(int const nb)
{
	std::cout << "Int constructor called" << std::endl;
	setRawBits(nb << this->_fraction);
}


Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}




int Fixed::getRawBits() const
{
	return(this->_fixed);
}

void Fixed::setRawBits(int const raw)
{
	this->_fixed = raw;
}






float Fixed::toFloat( void ) const
{
	return((float)(this->getRawBits()) / (1 << _fraction));
}


int Fixed::toInt( void ) const
{
	return(getRawBits() >> _fraction);
}





std::ostream &operator<<(std::ostream& value, const Fixed& fixed)
{
	value << fixed.toFloat();
	return value;
}


Fixed &Fixed::operator=(const Fixed &overload)
{
	std::cout << "Argument operator called" << std::endl;
	this->_fixed = overload._fixed;
	return *this;	
}

