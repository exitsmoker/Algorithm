using namespace std;
bool check = false;

int gcd(int a, int b)
{
	int c;
	while (b != 0)
	{
		c = a % b;
		a = b;
		b = c;
	}
	if(b == 0){
		check = true;
	}
	return a;
}
long long solution(int w,int h)
{	
    int tempInt;
    long long answer;
	tempInt = gcd(w,h);
    if (check){
		answer = (w*h) - (w+h-tempInt);
	}  
	else {
		answer = (w*h) - (w+h-1);
	}  
		
	return answer;
}