#ifndef SIMPLE_TEST_CLASS_H
#define SIMPLE_TEST_CLASS_H

class SimpleTestClass {
public:
	int value;
	SimpleTestClass( int value );
	bool operator<( const SimpleTestClass& rhs );
	bool operator>( const SimpleTestClass& rhs );
};


#endif /* end of include guard: SIMPLE_TEST_CLASS_H */
