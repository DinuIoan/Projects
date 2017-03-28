
public class CMDcd extends WriteCommand{
	String s;
	
	public CMDcd(String s)
	{
		this.s = s;
	}

	@Override
	public void execute2(Folder folder) {
		if(s.equals(".."))
		{
			
		}
		
	}

	@Override
	public void execute2(File file) {
		// TODO Auto-generated method stub
		
	}
	

}
