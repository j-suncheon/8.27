#include <iostream>
#include <string>

using namespace std;

class CMP {
public:
	char* ps;
	char* pt;

	virtual int cmpare()
	{
		return 0;
	}
};

class Strcmp : public CMP {
public:
	Strcmp(char* s, char* t) {
		ps = s;
		pt = t;
	}
	int cmpare() {
		int i = 0;
		int len;
		int num = 0;
		len = (strlen(ps) <= strlen(pt) ? strlen(ps) : strlen(pt));

		while (i < len)
		{
			if (ps[i]>pt[i])
			{
				i = i + len;
				num = 1;
			}
			else if (ps[i]<pt[i])
			{
				i += len;
				num = -1;
			}
			else
			{
				num = 0;
				i++;
			}
		}
		return num;
	}
};

class Numcmp : public CMP {
public :
	Numcmp(char* s, char* t) {
		ps = s;
		pt = t;
	}
	int cmpare() {
		float a, b;
		a = stof(ps);
		b = stof(pt);

		if (a > b)
			return 1;
		else if (a < b)
			return -1;
		else
			return 0;
	}
};

CMP* fcmp(char*, char*);

int main()
{
	char s[80], t[80];
	int result;

	CMP* p = new CMP();
	
	cout << "첫번째 문자열 : ";
	cin >> s;
	cout << "두번째 문자열 : ";
	cin >> t;
	p = fcmp(s, t);
	result = p->cmpare();
	cout << result;
	return 0;
}

CMP* fcmp(char* ps, char* pt)
{
	char* s;
	char* t;
	s = ps;
	t = pt;

	if (*s == '-')
		s++;
	while (*s != NULL)
		if (isdigit(*s) || *s == '.')
			s++;
		else
			return new Strcmp(ps, pt);

	if (*t == '-')
		t++;
	while (*t != NULL)
		if (isdigit(*t) || *t == '.')
			t++;
		else
			return new Strcmp(ps, pt);
	return new Numcmp(ps, pt);
}