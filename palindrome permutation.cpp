//logic:
//sort the string
//if even length ki string hai, to sabhi characters ka count even hi aana chaiye and no character should repeat odd no.of times.
//if odd string hai to only at most koi ek hi character aisa hona chaiye jo odd no of times repeat hora ho.

#include<iostream>
#include<algorithm>  //to use sort()
#include<cstdlib>   //to use malloc()

//isse baar baar std:: nhi likhna padta
using namespace std; 

int main()
{
	int n,i,count=0,even_count_elements=0,odd_count_elements=0; 
	 
	cout<<"\nWhat should be your string's size => ";
	cin>>n;
	
	//input string being dynamically allocated
	cout<<"\nStart filling the string => ";
	char *str=(char*)malloc(sizeof(char)*(n));
	
	for(i=0;i<n;i++)
	{
		cout<<"\nCharacter at index "<<i<<" ";
		cin>>str[i];
	}
	
	//sorting the string to get duplicate characters in the consecutive locations
	sort(str,str+n);
	
	//now iterate thorugh the sorted string again.
   for(i=0;i<n;i++)
   {	
   		count++;
   		//sabse pehle to litne odd and kitne even counts wale hai vo nikalo.Har ek individual characters ka count nikalo 
		//sabse pehle and if vo count even hai to even_count++ else odd_count++
   		if((str[i]!=str[i+1] || i+1>=n))   //i+1>=n isiliye taaki last element ko ek baar check kar sake
   		{
   			//character repeats even no. of times
   			if(count%2==0)
   			{
   				even_count_elements++;
			}
			else
			{
				odd_count_elements++;
			}
			
			//reset count
			count=0;
			
		}	
   }
	
	//if even length ki string hai, to sabhi characters ka count even hi aana chaiye and no character should repeat odd no.of times.
	if(n%2==0 && (odd_count_elements==0 && even_count_elements!=0))
	{
		cout<<"\nYes, the input string is a palindrome permutation";
	}
	//if odd string hai to only at most koi ek hi character aisa hona chaiye jo odd no of times repeat hora ho.
	else if(n%2==1 && (odd_count_elements==1 && even_count_elements!=0))
	{
		cout<<"\nYes, the input string is a palindrome permutation";
	}
	//none of the above two
	else 
	{
		cout<<"\nNo, the input string is NOT a palindrome permutation";
	}
		   

return 0;
}
