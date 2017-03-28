
public class CMDcat extends ReadCommand{
	String numeFis;
	
	public CMDcat(String s)
	{
		this.numeFis = s;
	}
	@Override
	public void execute2(Folder folder) {
		for(Repository i: Folder.folders)
		{
			if(i.getPath().equals(numeFis))
			{
				Terminal.txtArea.append(i.getContent());
			}
		}
		
	}

	@Override
	public void execute2(File file) {
		// TODO Auto-generated method stub
		
	}

}
