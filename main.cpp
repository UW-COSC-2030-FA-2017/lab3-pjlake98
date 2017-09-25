// James Fantin
// COSC 2030
// Lab 03

#include <iostream>

using namespace std;

void shortSum(short n);
void longSum(long n);
void floatFactorial(long n);
void doubleFactorial(long n);
void strangeFloat(long n);
void strangeDouble(long n);
void puzzleFloat();
void puzzleDouble();

int main()
{
    cout << "Testing the sum with a short" << endl;
    shortSum(255);
    shortSum(256);

    cout << "\nTesting the sum with a long" << endl;
    longSum(65535);
    longSum(65536);

    cout << "\nTesting the factorial with a float" << endl;
    floatFactorial(34);
    floatFactorial(35);

    cout << "\nTesting the factorial with a double" << endl;
    doubleFactorial(170);
    doubleFactorial(171);

    cout << "\nTesting the ratio with a float" << endl;
    strangeFloat(34);
    strangeFloat(35);
    strangeFloat(36);

    cout << "\nTesting the ratio with a float" << endl;
    strangeDouble(200);
    strangeDouble(220);

    cout << "\nTesting the puzzle with a float" << endl;
    puzzleFloat();

    cout << "\nTesting the puzzle with a double" << endl;
    puzzleDouble();

    return 0;
}

void shortSum(short n)
{
    short sum = 0;
    for (int i = 1; i < n+1; i++)
    {
        sum += i;
    }
    cout << "The sum from 1 to " << n << " is " << sum << endl;
    return;
    // The overflow occurs when n = 256 as the result is -32640.
    // An overflow for this process can be detected in the sum is a negative number
    //  since that should never be the case.
}

void longSum(long n)
{
    long sum = 0;
    for (int i = 1; i < n+1; i++)
    {
        sum += i;
    }
    cout << "The sum from 1 to " << n << " is " << sum << endl;
    return;
    // The overflow occurs when n = 65536
}

void floatFactorial(long n)
{
    float product = 1;
    for (int i = 1; i < n+1; i++)
    {
        product *= i;
    }
    cout << "The factorial of " << n << " is " << product << endl;
    return;
    // The overflow occurs when n = 35
    // This could be detected because the value after the overflow is reported as inf
}

void doubleFactorial(long n)
{
    double product = 1;
    for (int i = 1; i < n+1; i++)
    {
        product *= i;
    }
    cout << "The factorial of " << n << " is " << product << endl;
    return;
    // The overflow occurs when n = 171
}

void strangeFloat(long n)
{
    float sum = 0;
    for (int i = 1; i < n+1; i++)
    {
        sum += 1.0/n;
    }
    sum -= 1.0;
    cout << "The sum of the ratios - 1 of " << n << " is " << sum << endl;
    return;
    // The expected value should be 0 if the values are exact.
    // The weird results occur because the 1/n value can not be computed exactly for
    // certain numbers because the decimals increase forever
    // The float or double will drop certain decimals which will create a rounding error
    //  so the values will not be completely accurate
}

void strangeDouble(long n)
{
    double sum = 0;
    for (int i = 1; i < n+1; i++)
    {
        sum += 1.0/n;
    }
    sum -= 1.0;
    cout << "The sum of the ratios - 1 of " << n << " is " << sum << endl;
    return;
    // The expected value should be 0 if the values are exact.
    // The weird results occur because the 1/n value can not be computed exactly for
    // certain numbers because the decimals increase forever
    // The float or double will drop certain decimals which will create a rounding error
    //  so the values will not be completely accurate
}

void puzzleFloat()
{
    for (float i = 3.4; i < 4.4; i += 0.2)
	{
		cout << "i = " << i << endl;
	}
	// The error occurs because there is some variance in floating point arithmetic
	// When .2 is added to a float, that cannot be done completely accurately
	//  so there is a bit of variance in the floating point representation
}

void puzzleDouble()
{
    for (double i = 3.4; i < 4.4; i += 0.2)
	{
		cout << "i = " << i << endl;
	}
	// The error occurs because there is some variance in floating point arithmetic
	// When .2 is added to a double, that cannot be done completely accurately
	//  so there is a bit of variance in the double representation
	// The double works while the float does not because the .2 does go into the double
	//  with a smaller variance so the value is a bit less when compared
}
