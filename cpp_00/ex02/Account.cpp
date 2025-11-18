/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvoronts <vvoronts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 14:19:48 by vvoronts          #+#    #+#             */
/*   Updated: 2025/09/04 17:02:20 by vvoronts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <ctime>
#include <iostream>

int	Account::_nbAccounts = 0; // number of accounts
int	Account::_totalAmount = 0; // 
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

// Public

// getters
int	Account::getNbAccounts(void) {
	return _nbAccounts;
}

int	Account::getTotalAmount(void) {
	return _totalAmount;
}

int	Account::getNbDeposits(void) {
	return _totalNbDeposits; 
}

int	Account::getNbWithdrawals(void) {
	return _totalNbWithdrawals;
}

void Account::displayAccountsInfos(void)
{
	_displayTimestamp();
	std::cout << " accounts:" << getNbAccounts() << ";";
	std::cout << " total:" << getTotalAmount() << ";";
	std::cout << " deposits:" << getNbDeposits() << ";";
	std::cout << " withdrawals:" << getNbWithdrawals() << std::endl;
}

Account::Account(int initial_deposit)
{
	this->_accountIndex = _nbAccounts;
    this->_amount = initial_deposit;
    this->_nbDeposits = 0;
    this->_nbWithdrawals = 0;

    _nbAccounts++;
    _totalAmount += initial_deposit;

    _displayTimestamp();
    std::cout << "index:" << this->_accountIndex
              << ";amount:" << this->_amount
              << ";created" << std::endl;
}

Account::~Account(void) 
{
	_displayTimestamp();
    std::cout << "index:" << this->_accountIndex
              << ";amount:" << this->_amount
              << ";closed" << std::endl;

}

void Account::_displayTimestamp(void)
{
	std::time_t now = std::time(NULL);
	char mbstr[100];
	std::strftime(mbstr, sizeof(mbstr), "[%Y%m%d_%H%M%S]", std::localtime(&now));
	std::cout << mbstr;
}

// Make a deposit
void Account::makeDeposit(int deposit) {
    _displayTimestamp();
    std::cout << "index:" << this->_accountIndex
              << ";p_amount:" << this->_amount
              << ";deposit:" << deposit;

    this->_amount += deposit;
    this->_nbDeposits++;
    _totalAmount += deposit;
    _totalNbDeposits++;

    std::cout << ";amount:" << this->_amount
              << ";nb_deposits:" << this->_nbDeposits << std::endl;
}

// Make a withdrawal
bool Account::makeWithdrawal(int withdrawal) {
    _displayTimestamp();
    std::cout << "index:" << this->_accountIndex
              << ";p_amount:" << this->_amount
              << ";withdrawal:";

    if (this->_amount < withdrawal) {
        std::cout << "refused" << std::endl;
        return false;
    }

    this->_amount -= withdrawal;
    this->_nbWithdrawals++;
    _totalAmount -= withdrawal;
    _totalNbWithdrawals++;

    std::cout << withdrawal
              << ";amount:" << this->_amount
              << ";nb_withdrawals:" << this->_nbWithdrawals << std::endl;
    return true;
}

int Account::checkAmount(void) const {
    return this->_amount;
}

void Account::displayStatus(void) const {
    _displayTimestamp();
    std::cout << "index:" << this->_accountIndex
              << ";amount:" << this->_amount
              << ";deposits:" << this->_nbDeposits
              << ";withdrawals:" << this->_nbWithdrawals << std::endl;
}
