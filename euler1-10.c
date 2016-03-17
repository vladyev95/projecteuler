#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

/* Problem 1 */ int multiples_five_three(void);

/* Problem 2 */ int sum_fibonaccis_4mil(void);
/* Problem 2 */ int fibonacci(int);

/* Problem 3 */ bool is_prime(long n);
/* Problem 3 */	long find_max_prime(void);
/* Problem 3 */ #define PROB_3_N 600851475143

/* Problem 4 */ bool is_palindrome(char* str, int len);
/* Problem 4 */ int find_largest_palindrome(void);
/* Problem 4 */ char* to_string(int n);
/* Problem 4 */ int int_len(int n);

/* Problem 5 */ bool divisible_upto20(int n);
/* Problem 5 */ long get_divisible_upto20(void);

/* Problem 6 */ int get_sum_of_squares(void);
/* Problem 6 */ #define SQUARE_OF_SUMS pow(100*101/2, 2)

/* Problem 7 */ int get_nth_prime(int n);

/* Problem 8 */ static const char* str_1000 = 
"73167176531330624919225119674426574742355349194934"
"96983520312774506326239578318016984801869478851843"
"85861560789112949495459501737958331952853208805511"
"12540698747158523863050715693290963295227443043557"
"66896648950445244523161731856403098711121722383113"
"62229893423380308135336276614282806444486645238749"
"30358907296290491560440772390713810515859307960866"
"70172427121883998797908792274921901699720888093776"
"65727333001053367881220235421809751254540594752243"
"52584907711670556013604839586446706324415722155397"
"53697817977846174064955149290862569321978468622482"
"83972241375657056057490261407972968652414535100474"
"82166370484403199890008895243450658541227588666881"
"16427171479924442928230863465674813919123162824586"
"17866458359124566529476545682848912883142607690042"
"24219022671055626321111109370544217506941658960408"
"07198403850962455444362981230987879927244284909188"
"84580156166097919133875499200524063689912560717606"
"05886116467109405077541002256983155200055935729725"
"71636269561882670428252483600823257530420752963450";
/* Problem 8 */ long largest_13_product(void);

/* Problem 9 */ int product_of_triples(void);

/* Problem 10 */ long sum_primes_under2mil(void);



int main(void) {
	printf("1: Sum of multiples of 3 or 5 below 1000: %d\n", 
		multiples_five_three());

	printf("2: Sum of fibonacci values not exceeding 4 mil: %d\n", 
		sum_fibonaccis_4mil());

	printf("3: Largest prime factor of %ld is %ld;\n",
		PROB_3_N, find_max_prime());

	printf("4: Largest palindrome that is product of 3 digit nums: %d\n",
		find_largest_palindrome());

	printf("5: Smallest number divisible by 1 thru 20: %ld\n", 
	get_divisible_upto20()); 

	printf("6: Sum of squares(1-100): %d\n", get_sum_of_squares());
	printf("Square of sum(1-100): %.0lf\n", SQUARE_OF_SUMS);
	printf("Difference: %.0lf", get_sum_of_squares() - SQUARE_OF_SUMS);

	printf("7: 10001st prime: %d\n", get_nth_prime(10001)); 

	printf("8: Largest product of 13 consecutive digits: %ld\n", 
		largest_13_product()); 

	printf("9: Product of pythagorean triples: %d", product_of_triples()); 

	printf("10: Sum of primes under 2 mil: %ld", sum_primes_under2mil());
}



/*****Problem 1 *****************/

int multiples_five_three(void) {
	int sum = 0;
	//Every 3rd fibonacci number is even
	for(short i=3; i<1000; i+=3) {
		if(i%3 == 0 || i%5 == 0) {
			sum += i;
		}
	}
	return sum;
}

/********************************/
 



/*****Problem 2*****************/

int sum_fibonaccis_4mil(void) {
	int sum = 0;
	for(int i=1; ; i++) {
		int val = fibonacci(i);
		if(val > 4000000) {
			break;
		} else if(val % 2 == 0) {
			sum += val;
		}
	}
	return sum;
}
int fibonacci(int n) {
	if(n == 0 || n == 1) {
		return 1;
	} else {
	 		return fibonacci(n-1) + fibonacci(n-2);
	}
}

/*******************************/


/*****Problem 3*****************/

bool is_prime(long n) {
	if(n == 2) {
		return true;
	}
	long sqrt_n = sqrt(n);
	for(long i=2; i <= sqrt_n; i++) {
		if(n%i == 0) {
			return false;
		}
	}
	return true;
}

long find_max_prime(void) {
	long max_prime = 2;
	long sqrt_n = sqrt(PROB_3_N);
	for(long i=3; i <= sqrt_n; i += 2) {
		if(is_prime(i) && PROB_3_N % i == 0) {
			max_prime = i;
		}
	}
	return max_prime;
}

/*******************************/


/*****Problem 4*****************/
bool is_palindrome(char* str, int len) {
	int high = len - 1, low = 0;
	while(high >= low) {
		if(*(str+low) != *(str+high)) {
			free(str);
			return false;
		} else {
			low++;
			high--;
		}
	}
	free(str);
	return true;
}

char* to_string(int n) {
	int temp = n;
	int count = 0;
	while(temp != 0) {
		count++;
		temp /= 10;
	}
	char* n_str = malloc(count + 1);
	for(int i=0; i<count; i++) {
		*(n_str+i) = 48 + n % 10;
		n /= 10;
	}
	*(n_str + count) = 0;
	return n_str;
}

int int_len(int n) {
	int count = 0;
	while(n > 0) {
		count++;
		n /= 10;
	}
	return count;
}

int find_largest_palindrome(void) {
	int max = 0;
	for(short i=100; i<=999; i++) {
		for(short j=100; j<=i; j++) {
			int num = i * j;
			if(is_palindrome(to_string(num), int_len(num)) && num > max) {
				max = num;
			}
		}
	}
	return max;
}

/*******************************/


/*****Problem 5*****************/

long get_divisible_upto20(void) {
	for(int i=2520; ; i += 20) {
		if(divisible_upto20(i)) {
			return i;
		}
	}
	return 0;
}




bool divisible_upto20(int n) {
	for(int i=20; i>=11; i--) {
		if(n%i != 0) {
			return false;
		}
	} 
	return true;
}

/*******************************/


/*****Problem 6*****************/

int get_sum_of_squares(void) {
	int sum = 0;
	for(char i=1; i<=100 ; i++) {
		sum += pow(i, 2);
	}
	return sum;
}

/******************************/

/*****Problem 7*****************/

int get_nth_prime(int n) {
	if(n == 1) {
		return 2;
	} else {
		int counter = 2;
		for(int i=5; ; i += 2) {
			if(is_prime(i)) {
				counter++;
			}
			if(counter == n) {
				return i;
			}
		}
	}
	return -1;
}

/******************************/


/*****Problem 8*****************/

long largest_13_product(void) {
	long largest = 0;
	long product;
	for(short i=0; i<986; i++) {
		product = 1;
		for(short j=i; j < i+13; j++) {
			product *= (int)(*(str_1000 + j) - 48);
		}
		if(product > largest) {
			largest = product;
		}
	}
	return largest;
}

/******************************/


/*****Problem 9*****************/

int product_of_triples(void) {
	for(short a=1; a<1000; a++) {
		for(short b=a+1; b<1000; b++) {
			for(short c=b+1; c<1000; c++) {
				if(a+b+c == 1000 && pow(a,2) + pow(b, 2) == pow(c, 2)) {
					return a*b*c;
				}
			}
		}
	}
	return -1;
}

/********************************/


/*****Problem 10*****************/

long sum_primes_under2mil(void) {
	long sum = 0;
	for(int i=2; i<2000000; i++) {
		if(is_prime(i)) {
			sum += i;
		}
	}
	return sum;
}

/********************************/