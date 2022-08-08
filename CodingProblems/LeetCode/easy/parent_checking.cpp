// input : string
//
// search: { 
//
// going through the string to find },
//		if found {:
//			if there's more {
//				
//			if there's more }
//				if not or found an {
//					true
//			else "reach the end"
//				true
//
//		else
//			false
//
//
// 2nd
//
// count the { 
//	i++
//
// count the }
// i--
//
// i 0 or non-0

#include <iostream>
using namespace std;

#include <string>

int main(void) {

	return 0;
}

bool parent_check(const std::string &s) {
	// ++ if found {
	// -- if found }
	int counter{0};
	
	// use iterator insted of i
	for (int i = 0; i < strlen(s); i++)
	{
		if (s[i] == '}') {
			counter--;
			if (counter < 0) {
				return false;
			}
		} else if (s[i] = '{') {
			counter++;
		}
	}

	// 0 = false then !0 is true
	return (!(counter));
}
