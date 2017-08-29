#include "include_routine.h"

SimpleTestClass::SimpleTestClass( int value ) : value( value ) {}

bool SimpleTestClass::operator<( const SimpleTestClass& rhs ) {
    return this -> value < rhs.value;
}

bool SimpleTestClass::operator>( const SimpleTestClass& rhs ) {
    return this -> value > rhs.value;
}
