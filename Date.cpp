#include "Date.h"
#include "sstream"

/// Getter
/// \return \param day
int Date::getDay() const {
    return day;
}

/// Setter
/// muda \param dia da data
void Date::setDay(int day) {
    Date::day = day;
}

/// Getter
/// \return \param year
int Date::getYear() const {
    return year;
}

/// Setter
/// \param year
/// muda \param ano da data
void Date::setYear(int year) {
    Date::year = year;
}

/// Getter
/// \return \param month
int Date::getMonth() const {
    return month;
}

/// Setter
/// \param month
/// muda \param month da data
void Date::setMonth(int month) {
    Date::month = month;
}

/// Construtor
/// \param day
/// \param month
/// \param year
/// cria um objeto da classe Date com os atributos day, month e year
Date::Date(int day,int  month,int year){
    this->day = day;
    this->month = month;
    this->year = year;
}

///
/// \param day da Data mudado
/// \param month da Data mudado
/// \param year da Data mudado
void Date::setDate(int day, int month, int year){
    this->day = day;
    this->month = month;
    this->year = year;
}

/// Operator<
/// \se os anos forem iguais e os meses forem iguais retorna day < d2.getDay()
/// \se os anos forem iguais e os meses diferentes retorna month < d2.getMonth()
/// \caso contrario retorna year < d2.getYear()
bool const Date::operator<(const Date d2) const {
    if(year == d2.getYear()){
        if(month == d2.getMonth()) return day < d2.getMonth();
        return month < d2.getMonth();
    }
    return year<d2.getYear();
}

/// Operator==
/// \retorna year == d2.getYear() && month == d2.getMonth() && day == d2.getDay()
bool const Date::operator==(const Date d2) const{
    return year == d2.getYear() && month == d2.getMonth() && day == d2.getDay();
}

/// Construtor
/// cria um objeto da classe date
/// com parâmetros default \param day = 31, \param month = 12, \param year = 3000
Date::Date() {
    this->day = 31;
    this->month = 12;
    this->year = 3000;
}
