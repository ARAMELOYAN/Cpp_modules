#include <iostream>
#include "Account.hpp"

int		Account::_nbAccounts = 0;
int		Account::_totalAmount = 0;
int		Account::_totalNbDeposits = 0;
int		Account::_totalNbWithdrawals = 0;

void	Account::_displayTimestamp( void )
{
	std::time_t ttime = std::time(0);

	std::tm *local_time = std::localtime(&ttime);
	std::cout << "["<< 1900 + local_time->tm_year;
	if (local_time->tm_mon < 9)
		std::cout<< "0";
	std::cout << 1 + local_time->tm_mon;
	if (local_time->tm_mday <= 9)
		std::cout<< "0";
	std::cout << local_time->tm_mday
    << "_";
	if (local_time->tm_hour <= 9)
		std::cout<< "0";
	std::cout << local_time->tm_hour;
	if (local_time->tm_min <= 9)
		std::cout<< "0";
    std::cout << local_time->tm_min;
	if (local_time->tm_sec <= 9)
		std::cout<< "0";
    std::cout << local_time->tm_sec
	<< "] ";
}

Account::Account(int initial_deposit)
{
	_displayTimestamp();
	_accountIndex = _nbAccounts;
	_amount = initial_deposit;
	_nbDeposits = 0;
	_nbWithdrawals = 0;
	_nbAccounts++;
	_totalAmount += _amount;
	std::cout << "index:" << _accountIndex
			<< ";amount:" << _amount
			<< ";created\n";
}

Account::~Account()
{
	_displayTimestamp();
	_nbAccounts--;
	_totalAmount -= _amount;
	std::cout << "index:" << _accountIndex
			<< ";amount:" << _amount
			<< ";closed\n";
}

void	Account::makeDeposit( int deposit )
{
	_displayTimestamp();
	if (deposit > 0)
	{
		_nbDeposits++;
		_totalAmount += deposit;
		std::cout << "index:" << _accountIndex
				<< ";p_amount:" << _amount
				<< ";deposit:" << deposit
				<< ";amount:" << _amount + deposit
				<< ";nb_deposits:" << _nbDeposits
				<< std::endl;
		_amount += deposit;
		_totalNbDeposits++;
	}
	else
	{
		std::cout << "index:" << _accountIndex
				<< ";p_amount:" << _amount
				<< ";deposit:refused\n";
	}
}

bool	Account::makeWithdrawal( int withdrawal )
{
	_displayTimestamp();
	if (withdrawal > 0 && withdrawal <= _amount)
	{
		_nbWithdrawals++;
		_totalAmount -= _nbWithdrawals;
		std::cout << "index:" << _accountIndex
				<< ";p_amount:" << _amount
				<< ";withdrawal:" << withdrawal
				<< ";amount:" << _amount - withdrawal
				<< ";nb_withdrawals:" << _nbWithdrawals
				<< std::endl;
		_amount -= withdrawal;
		_totalNbWithdrawals++;
		return true;
	}
	else
	{
		std::cout << "index:" << _accountIndex
				<< ";p_amount:" << _amount
				<< ";withdrawal:refused\n";
	}
		return false;
}

int	Account::checkAmount( void ) const
{
	return _amount;
}

void Account::displayStatus( void ) const
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex
		<< ";amount:" << _amount
		<< ";deposits:" << _nbDeposits
		<< ";withdeawals:" << _nbWithdrawals
		<< std::endl;

}

int Account::getNbAccounts( void )
{
	return _nbAccounts;
}

int Account::getTotalAmount( void )
{
	return _totalAmount;
}

int Account::getNbDeposits( void )
{
	return _totalNbDeposits;
}

int Account::getNbWithdrawals( void )
{
	return _totalNbWithdrawals;
}
 
void Account::displayAccountsInfos( void )
{
	_displayTimestamp();
	std::cout << "accounts:" << getNbAccounts()
		<< ";total:" << getTotalAmount()
		<< ";deposits:" << getNbDeposits()
		<< ";withdeawals:" << getNbWithdrawals()
		<< std::endl;
}
