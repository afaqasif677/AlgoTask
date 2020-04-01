import java.util.Vector;

public class testing {
	
	int max(int a,int b)
	{
		if (a>b)
			return a;
		else 
			return b;
	}

	class Node{
		char a;
		int b;
		}
		void shifts(String pattern,Vector<Node> table )
		{
		int length=pattern.length();
		for(int i=0;i<length;i++)
		{
		char a=pattern.charAt(i);
		int val=max(1,length-i-1);
		Node obj=new Node();
		obj.a=a;
		obj.b=val;
		table.add(obj);
		}
		}

		boolean match(char a,Vector<Node> table,int index)
		{
			boolean check=false;
			for (int i=0;i<table.size();i++)
			{
				if(a==table.get(i).a)
				{
					check=true;
					index=i;
					break;
				}
			}
			return check;
		}
		
		void algo(Vector<Node> table,String text,String pattern)
		{
		int skips;
		for(int i=0;i<text.length()-pattern.length();i+=skips)
			{
			skips=0;
			for(int j=pattern.length()-1;j>=0;j--)
				{
			if(pattern.charAt(j)!=text.charAt(i+j))
					{
				int index=0;
				if(match(text.charAt(i+j),table,index))
				{
					skips= table.get(index).b;
					break;
				} 
			else
				{
				skips=pattern.length();
				break;
					}
				}
			}
			if(skips==0)
				{
				System.out.println("Match found at index "+i+" of text ");
				break;
				}
		}
		
		}

	
	public static void main(String[] args) {
		// TODO Auto-generated method stub

		Vector<Node> tab=new Vector<Node>();
		testing obj=new testing();
		String text="This is coding";
		String pat="cod";
		obj.shifts(pat, tab);
	//	for(int i=0;i<tab.size();i++)
		//	System.out.println("Char : "+tab.get(i).a+ "\n Int : "+tab.get(i).b);
		obj.algo(tab, text, pat);
	}

}
