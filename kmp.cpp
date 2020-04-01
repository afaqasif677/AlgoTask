public class testing {

	int hash(int x,int y)
	{
	while (x>y)
	x=x%y;
	return x;
	}

	void algo(String text, String pattern,int mod)
	{
	int n=text.length();
	int m=pattern.length();
	int check;
	check=Integer.parseInt(pattern);
	check=hash(check,mod);
	for(int i=0;i<n;i++){
	String num="";
	int number;
	for(int j=0;j<m && i+j<n;j++)
	num+=text.charAt(i+j);
	number=Integer.parseInt(num);
	if(check==hash(number,mod))
	{
	double val=Integer.parseInt(pattern);
	val=val/number;
	if(val==1)
System.out.println("Match at index : "+i);
	}
	}
	}
	

	
	
	public static void main(String[] args) {
		// TODO Auto-generated method stub

		testing obj=new testing();
		String te="3141592653589793";
		String pat="26";
		int m=11;
		obj.algo(te,pat,m);
	}

}

