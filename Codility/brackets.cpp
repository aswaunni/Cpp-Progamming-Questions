/*
A string S consisting of N characters is considered to be properly nested if any of the following conditions is true:

S is empty;
S has the form "(U)" or "[U]" or "{U}" where U is a properly nested string;
S has the form "VW" where V and W are properly nested strings.
For example, the string "{[()()]}" is properly nested but "([)()]" is not.

Write a function:

int solution(string &S);

that, given a string S consisting of N characters, returns 1 if S is properly nested and 0 otherwise.

For example, given S = "{[()()]}", the function should return 1 and given S = "([)()]", the function should return 0, as explained above.
*/

int solution(string &S) {
	int n = S.length();
	if (n == 0)
		return 1;

	if (n%2)
		return 0;

	stack<char> q;

	auto has_pair = [&q] (char c) {
		if (q.empty() || q.top() != c)
			return false;

		q.pop();
		return true;
	};

	for (auto& c : S) {
		switch(c) {
			case '}' : {
					   if (!has_pair('{'))
						   return 0;
					   break;
				   }
			case ']' :{
					  if (!has_pair('['))
						  return 0;
					  break;
				  }
			case ')' :{
					  if (!has_pair('('))
						  return 0;
					  break;
				  }
			default :
				  q.push(c);
		}
	}

	return (q.empty() ? 1 : 0);
}
