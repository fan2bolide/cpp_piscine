#include "Account.hpp"

Account::Account(int initial_deposit) {
	_totalAmount = initial_deposit;
	_nbDeposits = 1;
}

Account::~Account(void) {

}

int	Account::getNbAccounts()
{
	return _nbAccounts;
}

void	Account::displayAccountsInfos()
{
	return;
}

int Account::getTotalAmount() {
	return _totalAmount ;
}

int Account::getNbDeposits( void ) {
	return _totalNbDeposits;
}

int Account::getNbWithdrawals() {
	return _totalNbWithdrawals;
}

void Account::makeDeposit(int deposit) {
	_nbDeposits++;
	_amount += deposit;
	_totalAmount +=deposit;
}

bool Account::makeWithdrawal(int withdrawal) {
	return false;
}

int Account::checkAmount() const {
	return 0;
}

void Account::displayStatus(void) const {

}

void Account::_displayTimestamp(void) {

}

Account::Account(void) {

}
