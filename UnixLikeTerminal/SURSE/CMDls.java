
public class CMDls extends ReadCommand{
	String s = null;
	String s1 = null;
	
	public CMDls()
	{
		
	}
	public CMDls(String s)
	{
		this.s = s;
	}
	public CMDls(String s,String s1)
	{
		this.s = s;
		this.s1 = s1;
	}

	public void execute2(Folder folder) {
		if(s == null && s1 == null)
		{
			for(Repository i: Folder.folders)
			{
				Terminal.txtArea.append(i.getPath() + "\n");
			}
		}
		else if(s != null && s1 == null)
		{
			
			if(s.equals("-r"))
			{
				for(Repository i: Folder.folders)
				{
					
				}
			}
		}
	}

	public void execute2(File file) {
		
	}
	
	
	
}
