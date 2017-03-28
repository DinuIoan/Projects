
public class CMDpwd extends ReadCommand{
	Folder folder;
	
	public CMDpwd(Folder folder)
	{
		this.folder = folder;
	}
	
	/*public String function(Folder f)
	{
		for(Repository i : f.folders)
		{
			if(i.getPath().equals(this.folder))
				return i.getPath();
		}
		for(Repository i : f.folders)
		{
			if()
			return i.getPath() + function(i);
		}
		return null;
	}*/

	@Override
	public void execute2(Folder folder) {
		String s="";
		
		
	}

	@Override
	public void execute2(File file) {
		// TODO Auto-generated method stub
		
	}
	
}
