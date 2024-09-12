/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thlefebv <thlefebv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 13:25:43 by thlefebv          #+#    #+#             */
/*   Updated: 2024/09/10 19:32:22 by thlefebv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

// Constructors

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

// Destructor

Fixed::~Fixed()
{
	// std::cout << "Destructor called" << std::endl;
}



// Methodes

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



// Comparison operators

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

bool Fixed::operator>(const Fixed& nb)
{
	return this->_fixed > nb._fixed;
}

bool Fixed::operator<(const Fixed& nb)
{
	return this->_fixed < nb._fixed;
}

bool Fixed::operator>=(const Fixed& nb)
{
	return this->_fixed >= nb._fixed;
}

bool Fixed::operator<=(const Fixed& nb)
{
	return this->_fixed <= nb._fixed;
}

bool Fixed::operator==(const Fixed& nb)
{	
	return this->_fixed == nb._fixed;
}

bool Fixed::operator!=(const Fixed& nb)
{
	return this->_fixed != nb._fixed;
}


// Maths operators;
Fixed Fixed::operator+(const Fixed &nb)
{
	Fixed value;
	value.setRawBits(this->_fixed + nb._fixed);
	return value;
}

Fixed Fixed::operator-(const Fixed &nb)
{
	Fixed value;
	value.setRawBits(this->_fixed - nb._fixed);
	return value;
}

Fixed Fixed::operator*(const Fixed &nb)
{
	Fixed value;
	value.setRawBits(this->_fixed * nb._fixed >> _fraction);
	return value;
}

Fixed Fixed::operator/(const Fixed &nb)
{
	Fixed value;
	value.setRawBits((this->_fixed * (1 << _fraction)) / nb._fixed);
	return value;
}


//Increments operators

Fixed &Fixed::operator++()
{
	this->_fixed++;
	return *this;
}

Fixed &Fixed::operator--()
{
	this->_fixed--;
	return *this;
}

Fixed Fixed::operator++(int)
{
	Fixed tmp = *this;
	++*this;
	return tmp;
}

Fixed Fixed::operator--(int)
{
	Fixed tmp = *this;
	--*this;
	return tmp;
}


//Overloads functions

Fixed& Fixed::min(Fixed& nb1, Fixed&nb2)
{
	if (nb1 >nb2)
		return nb2;
	return nb1;
}

Fixed& Fixed::max(Fixed& nb1, Fixed&nb2)
{
	if (nb1 <nb2)
		return nb2;
	return nb1;
}

const Fixed& Fixed::min(const Fixed& nb1, const Fixed&nb2)
{
	if (nb1._fixed >nb2._fixed)
		return nb2;
	return nb1;
}

const Fixed& Fixed::max(const Fixed& nb1, const Fixed&nb2)
{
	if (nb1._fixed <nb2._fixed)
		return nb2;
	return nb1;
}